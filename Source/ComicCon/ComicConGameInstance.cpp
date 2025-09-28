// Fill out your copyright notice in the Description page of Project Settings.


#include "ComicConGameInstance.h"
#include "Engine/GameEngine.h"
#include "GameFramework/GameUserSettings.h"
#include "Kismet/GameplayStatics.h"
#include "Components/AudioComponent.h"

void UComicConGameInstance::Init()
{
    Super::Init();
    if (!GEngine) return;
    if (UGameUserSettings* GS = GEngine->GetGameUserSettings())
    {
        GS->SetFullscreenMode(EWindowMode::Windowed);
        GS->SetScreenResolution(FIntPoint(450, 800));
        GS->ApplySettings(false);
        GS->SaveSettings();
    }

    if (BGM)
    {
        PersistentAudio = UGameplayStatics::CreateSound2D(this, BGM, 1.0f, 1.0f, 0.0f, nullptr, true);
        PersistentAudio->Play();
    }
}
