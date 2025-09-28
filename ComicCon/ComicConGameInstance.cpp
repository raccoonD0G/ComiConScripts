// Fill out your copyright notice in the Description page of Project Settings.


#include "ComicConGameInstance.h"
#include "Engine/GameEngine.h"
#include "GameFramework/GameUserSettings.h"
#include "Kismet/GameplayStatics.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundBase.h"

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
}

void UComicConGameInstance::OnStart()
{
    Super::OnStart();
    StartBGM();
}

void UComicConGameInstance::StartBGM()
{
    if (!BGM) return;

    UWorld* World = GetWorld();
    if (!World) return;

    // CreateSound2D(WorldContext, Sound, Vol, Pitch, StartTime, Concurrency, bPersistAcrossLevelTransition, bAutoDestroy)
    PersistentAudio = UGameplayStatics::CreateSound2D(
        World, BGM, 1.f, 1.f, 0.f, nullptr,
        /*bPersistAcrossLevelTransition=*/true,
        /*bAutoDestroy=*/false
    );

    if (PersistentAudio)
    {
        PersistentAudio->bIsUISound = true;        // 2D BGM면 공간화 끄기
        PersistentAudio->bAllowSpatialization = false;
        PersistentAudio->Play();
    }
}
