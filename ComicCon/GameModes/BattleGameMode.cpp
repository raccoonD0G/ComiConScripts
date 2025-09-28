// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModes/BattleGameMode.h"
#include "Subsystems/RecordingSubsystem.h"
#include "Engine/GameInstance.h"
#include "GameStates/BattleGameState.h"
#include "HUDs/ResultHUD.h"
#include "Utils.h"
#include "Kismet/GameplayStatics.h"
#include "Async/Async.h"
#include "SaveGames/ScoreSaveGame.h"
#include <HUDs/BattleHUD.h>

#include "Blueprint/UserWidget.h"     // UUserWidget, CreateWidget
#include "Components/PanelWidget.h"   // UPanelWidget
#include "Components/ContentWidget.h" // UContentWidget
#include "Components/CanvasPanelSlot.h" // UCanvasPanelSlot
#include <Pawns/ViewPlayer.h>
#include "Widgets/GameCompleteWidget.h"       // UGameCompleteWidget
#include "Widgets/BattleWidget.h"

void ABattleGameMode::BeginPlay()
{
    Super::BeginPlay();
    
    StartMatch();
	Init();
}

void ABattleGameMode::Init()
{
    if (ABattleGameState* BattleGameState = GetGameState<ABattleGameState>())
    {
		BattleGameState->OnCountdownFinished.AddDynamic(this, &ABattleGameMode::EndMatch);
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

    UBattleWidget* BW = HUD->GetLevelWidget();
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
    FTimerHandle TimerHandle_OpenLevel;
    GetWorld()->GetTimerManager().SetTimer(
        TimerHandle_OpenLevel,
        FTimerDelegate::CreateLambda([this]()
            {
                UGameplayStatics::OpenLevel(this, FName(TEXT("ResultMap")));
            }),
        2.0f,
        false
    );

    if (UGameInstance* GI = GetGameInstance())
    {
        if (auto* Rec = GI->GetSubsystem<URecordingSubsystem>())
        {
            Rec->StopRecording();
            VideoPath = Rec->GetLastOutputPath();

            if (!VideoPath.IsEmpty() && bShowVideoQR)
            {
                TWeakObjectPtr<UGameInstance> WeakGI = GI;
                TWeakObjectPtr<URecordingSubsystem> WeakRec = Rec;

                // 권장: 서브시스템의 함수를 사용 (수명 안전)
                QR::UploadFileToServer(
                    VideoPath,
                    TEXT("http://ec2-54-180-121-4.ap-northeast-2.compute.amazonaws.com:3000"),
                    [WeakGI, WeakRec](bool bOk, FString QrUrl)
                    {
                        if (!bOk || QrUrl.IsEmpty() || !WeakRec.IsValid()) return;
                        
                        QR::FetchQrTexture(QrUrl, [WeakGI](bool bOk2, UTexture2D* QrTex)
                            {
                                if (!bOk2 || !QrTex || !WeakGI.IsValid()) return;

                                // 게임 스레드에서 UI 접근
                                AsyncTask(ENamedThreads::GameThread, [WeakGI, QrTex]()
                                    {
                                        if (!WeakGI.IsValid()) return;
                                        if (UWorld* World = WeakGI->GetWorld())
                                        {
                                            if (APlayerController* PC = UGameplayStatics::GetPlayerController(World, 0))
                                            {
                                                if (AResultHUD* ResultHUD = PC->GetHUD<AResultHUD>())
                                                {
                                                    ResultHUD->SetQrTexture(QrTex);
                                                }
                                            }
                                        }
                                    });
                            });
                    }
                );
            }
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
    UScoreSaveGame* SaveObj = nullptr;
    if (UGameplayStatics::DoesSaveGameExist(SaveSlotName, UserIndex))
    {
        SaveObj = Cast<UScoreSaveGame>(UGameplayStatics::LoadGameFromSlot(SaveSlotName, UserIndex));
    }

    if(!SaveObj) return;
    
    // 점수 갱신 로직
    SaveObj->LastScore = Score;
    SaveObj->BestScore = FMath::Max(SaveObj->BestScore, Score);
    
    UGameplayStatics::SaveGameToSlot(SaveObj, SaveSlotName, UserIndex);
}
