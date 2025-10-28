// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModes/BattleGameMode.h"
#include "Subsystems/RecordingSubsystem.h"
#include "Engine/GameInstance.h"
#include "GameStates/BattleGameState.h"
#include "HUDs/ResultHUD.h"
#include "Utils.h"
#include "Kismet/GameplayStatics.h"
#include "Async/Async.h"
#include "SaveGames/BoothSave.h"

#include "HUDs/BattleHUD.h"
#include "Misc/DateTime.h"

#include "Blueprint/UserWidget.h"     // UUserWidget, CreateWidget
#include "Components/PanelWidget.h"   // UPanelWidget
#include "Components/ContentWidget.h" // UContentWidget
#include "Components/CanvasPanelSlot.h" // UCanvasPanelSlot
#include "Pawns/ViewPlayer.h"
#include "Widgets/GameCompleteWidget.h"       // UGameCompleteWidget
#include "Widgets/BattleWidget.h"

#include "SaveGames/GameSaveConstants.h"

void ABattleGameMode::BeginPlay()
{
    Super::BeginPlay();

    RecordBattleEntry();
    StartMatch();
    Init();
}

void ABattleGameMode::Init()
{
    if (ABattleGameState* BattleGameState = GetGameState<ABattleGameState>())
    {
        BattleGameState->OnBattleTimerFinished.AddDynamic(this, &ABattleGameMode::EndMatch);
    }
    else
    {
        GetWorldTimerManager().SetTimer(InitRetryTimer, this, &ABattleGameMode::StartMatch, 0.1f, false);
    }
}

void ABattleGameMode::StartMatch()
{
    if (UGameInstance* GI = GetGameInstance())
    {
        if (auto* Rec = GI->GetSubsystem<URecordingSubsystem>())
        {
            Rec->StartRecording();
        }
    }
}

void ABattleGameMode::EndMatch()
{
    SaveScore();

    FString VideoPath;

    APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
    if (!PC || !PC->IsLocalController()) return;

    ABattleHUD* HUD = Cast<ABattleHUD>(PC->GetHUD());
    if (!HUD) return;

    UBattleWidget* BW = Cast<UBattleWidget>(HUD->GetLevelWidget());
    if (!BW) return;

    // 플레이어 생사 판별
    APawn* Pawn = UGameplayStatics::GetPlayerPawn(this, 0);
    AViewPlayer* VP = Cast<AViewPlayer>(Pawn);
    const bool bDead = (VP && VP->GetCurrentHealth() <= 0);

    UUserWidget* Result = nullptr;

    if (bDead)
    {
        if (!GameOverWidgetInstance && ensure(GameLoseWidgetClass))
            GameOverWidgetInstance = CreateWidget<UGameCompleteWidget>(PC, GameLoseWidgetClass);

        Result = GameOverWidgetInstance;
        if (auto* GW = Cast<UGameCompleteWidget>(Result))
        {
            GW->StartImpact(0.55f);   // 사망 연출
        }
    }
    else
    {
        if (!GameCompleteWidget && ensure(GameWinWidgetClass))
            GameCompleteWidget = CreateWidget<UGameCompleteWidget>(PC, GameWinWidgetClass);

        Result = GameCompleteWidget;
        if (auto* CW = Cast<UGameCompleteWidget>(Result))
        {
            CW->StartImpact(0.60f);   // 승리 연출
        }
    }

    if (!Result) return;

    // BattleWidget 루트에 꽉 차게 붙이기
    if (UWidget* Root = BW->GetRootWidget())
    {
        if (UPanelWidget* Panel = Cast<UPanelWidget>(Root))
        {
            Panel->ClearChildren();
            Panel->AddChild(Result);
        }
        else if (UContentWidget* Content = Cast<UContentWidget>(Root))
        {
            Content->SetContent(Result);
        }
    }

    // 전체 화면 슬롯 보정
    if (UCanvasPanelSlot* S = Cast<UCanvasPanelSlot>(Result->Slot))
    {
        S->SetAnchors(FAnchors(0, 0, 1, 1));
        S->SetOffsets(FMargin(0));
        S->SetZOrder(999);
    }

    Result->SetVisibility(ESlateVisibility::Visible);
    if (!BW->IsInViewport()) BW->AddToViewport(999);

    // 2초 뒤 ResultMap 전환
    if (UWorld* World = GetWorld())
    {
        FTimerManager& TimerManager = World->GetTimerManager();

        // 이전 구현에서는 EndMatch 가 여러 번 호출될 때마다 새로운 타이머를 만들고, 람다 캡쳐에
        // 살아있지 않은 this 를 그대로 넘겨 ResultMap 으로 전환하는 동안 파괴된 GameMode 를
        // 역참조하여 충돌이 발생했다. 타이머 핸들을 멤버로 유지하고 약한 포인터로 self 를 캡쳐해
        // 중복 무장과 파괴된 객체 접근을 모두 막는다.
        if (!TimerManager.IsTimerActive(ResultLevelTimerHandle))
        {
            TWeakObjectPtr<ABattleGameMode> WeakThis = this;
            TimerManager.SetTimer(
                ResultLevelTimerHandle,
                FTimerDelegate::CreateLambda([WeakThis]()
                    {
                        if (!WeakThis.IsValid())
                        {
                            return;
                        }

                        if (UWorld* LocalWorld = WeakThis->GetWorld())
                        {
                            UGameplayStatics::OpenLevel(LocalWorld, FName(TEXT("ResultMap")));
                        }
                    }),
                4.0f,
                false
            );
        }
    }

    if (UGameInstance* GI = GetGameInstance())
    {
        if (auto* Rec = GI->GetSubsystem<URecordingSubsystem>())
        {
            Rec->StopRecording();
            VideoPath = Rec->GetLastOutputPath();
        }
    }
}

void ABattleGameMode::SaveScore()
{
    int32 Score = 0;
    if (ABattleGameState* BGS = GetGameState<ABattleGameState>())
    {
        Score = BGS->GetScore();
    }

    // 저장 객체 로드 또는 생성
    UBoothSave* SaveObj = nullptr;
    const bool bHasExistingSave = UGameplayStatics::DoesSaveGameExist(GameSave::BoothSessionSlot, 0);
    if (bHasExistingSave)
    {
        SaveObj = Cast<UBoothSave>(UGameplayStatics::LoadGameFromSlot(GameSave::BoothSessionSlot, 0));
    }

    if (!SaveObj)
    {
        SaveObj = Cast<UBoothSave>(UGameplayStatics::CreateSaveGameObject(UBoothSave::StaticClass()));
    }

    if(!SaveObj) return;

    // 점수 갱신 로직
    SaveObj->LastScore = Score;
    SaveObj->BestScore = FMath::Max(SaveObj->BestScore, Score);

    // 현재 점수를 기록하고 랭킹 순서에 맞게 정렬
    const FScoreEntry NewEntry{Score, SaveObj->CurrentHunterCount};
    SaveObj->ScoreHistory.Add(NewEntry);
    SaveObj->ScoreHistory.Sort([](const FScoreEntry& A, const FScoreEntry& B)
    {
        return A.Score > B.Score;
    });

    UGameplayStatics::SaveGameToSlot(SaveObj, GameSave::BoothSessionSlot, 0);
}

void ABattleGameMode::RecordBattleEntry()
{
    UBoothSave* SaveObj = nullptr;
    if (UGameplayStatics::DoesSaveGameExist(GameSave::BoothSessionSlot, 0))
    {
        SaveObj = Cast<UBoothSave>(UGameplayStatics::LoadGameFromSlot(GameSave::BoothSessionSlot, 0));
    }

    if (!SaveObj)
    {
        SaveObj = Cast<UBoothSave>(UGameplayStatics::CreateSaveGameObject(UBoothSave::StaticClass()));
    }

    if (!SaveObj) return;

    SaveObj->TotalBattleCount++;

    const FDateTime Now = FDateTime::Now();
    const FString Timestamp = Now.ToString(TEXT("%Y-%m-%d %H:%M"));
    SaveObj->BattleTimestamps.Add(Timestamp);

    UGameplayStatics::SaveGameToSlot(SaveObj, GameSave::BoothSessionSlot, 0);
}
