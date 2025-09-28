// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/LobbyWidget.h"
#include "GameFramework/GameUserSettings.h"

void ULobbyWidget::NativeConstruct()
{
    Super::NativeConstruct();
}

void ULobbyWidget::SetWindowed(int32 Width, int32 Height)
{
    if (!GEngine) return;
    if (UGameUserSettings* GS = GEngine->GetGameUserSettings())
    {
        GS->SetFullscreenMode(EWindowMode::Windowed);
        GS->SetScreenResolution(FIntPoint(Width, Height));
        GS->ApplySettings(false);
        GS->SaveSettings();
    }
}

void ULobbyWidget::SetFullscreen(bool bTrueFullscreen)
{
    if (!GEngine) return;
    if (UGameUserSettings* GS = GEngine->GetGameUserSettings())
    {
        GS->SetFullscreenMode(bTrueFullscreen ? EWindowMode::Fullscreen : EWindowMode::WindowedFullscreen);
        GS->ApplySettings(false);
        GS->SaveSettings();
    }
}