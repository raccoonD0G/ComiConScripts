// Fill out your copyright notice in the Description page of Project Settings.


#include "ComicConGameInstance.h"
#include "Engine/GameEngine.h"
#include "GameFramework/GameUserSettings.h"
#include "Kismet/GameplayStatics.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundBase.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/GameStateBase.h"
#include "GameModes/BattleGameMode.h"
#include "GameStates/BattleGameState.h"

void UComicConGameInstance::Init()
{
    Super::Init();

    if (GEngine)
    {
        if (UGameUserSettings* GS = GEngine->GetGameUserSettings())
        {
            GS->SetFullscreenMode(EWindowMode::Windowed);
            GS->SetScreenResolution(FIntPoint(450, 800));
            GS->ApplySettings(false);
            GS->SaveSettings();
        }
    }

    PostLoadHandle = FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(this, &UComicConGameInstance::HandlePostLoadMap);
}

void UComicConGameInstance::OnStart()
{
    Super::OnStart();
    StartBGM();
}

void UComicConGameInstance::Shutdown()
{
    if (PostLoadHandle.IsValid())
    {
        FCoreUObjectDelegates::PostLoadMapWithWorld.Remove(PostLoadHandle);
        PostLoadHandle.Reset();
    }
    Super::Shutdown();
}

void UComicConGameInstance::StartBGM()
{
    if (!BGM) return;

    UWorld* World = GetWorld();
    if (!World) return;

    PersistentAudio = UGameplayStatics::CreateSound2D(World, BGM, 1.f, 1.f, 0.f, nullptr, true, false);

    if (PersistentAudio)
    {
        PersistentAudio->bIsUISound = true;        // 2D BGM면 공간화 끄기
        PersistentAudio->bAllowSpatialization = false;
        PersistentAudio->Play();
    }
}

void UComicConGameInstance::HandlePostLoadMap(UWorld* NewWorld)
{
    if (!IsValid(NewWorld)) return;

    // 1) 점수 적용
    if (PendingDesiredScore != INDEX_NONE)
    {
        if (ABattleGameState* BGS = NewWorld->GetGameState<ABattleGameState>())
        {
            const int32 Delta = PendingDesiredScore - BGS->GetScore();
            if (Delta != 0) { BGS->AddScore(Delta); }
        }
        PendingDesiredScore = INDEX_NONE;
    }

    // 2) EndMatch 실행
    if (bEndMatchOnPostLoad)
    {
        if (ABattleGameMode* GM = NewWorld->GetAuthGameMode<ABattleGameMode>())
        {
            GM->EndMatch();
        }
        bEndMatchOnPostLoad = false;
    }
}