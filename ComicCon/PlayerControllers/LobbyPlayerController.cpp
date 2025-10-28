// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerControllers/LobbyPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "InputAction.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/GameUserSettings.h"
#include "Widgets/LobbyWidget.h"
#include "Kismet/GameplayStatics.h"
#include "HUDs/LevelHUD.h"


void ALobbyPlayerController::BeginPlay()
{
	Super::BeginPlay();

    if (ULocalPlayer* LP = GetLocalPlayer())
    {
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LP))
        {
            Subsystem->AddMappingContext(IMC_LobbyHUD, /*Priority*/ 0);
        }
    }

    if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(InputComponent))
    {
        EIC->BindAction(IA_Enter, ETriggerEvent::Started, this, &ALobbyPlayerController::OnEnterPressed);
        EIC->BindAction(IA_One, ETriggerEvent::Started, this, &ALobbyPlayerController::OnOnePressed);
        EIC->BindAction(IA_Two, ETriggerEvent::Started, this, &ALobbyPlayerController::OnTwoPressed);
        EIC->BindAction(IA_Three, ETriggerEvent::Started, this, &ALobbyPlayerController::OnThreePressed);
    }
}

void ALobbyPlayerController::OnEnterPressed()
{
    UGameplayStatics::OpenLevel(this, FName(TEXT("BattleMap")));
}

void ALobbyPlayerController::OnOnePressed()
{
	SetFullscreen(false);
}

void ALobbyPlayerController::OnTwoPressed()
{
	SetWindowed(450, 800);
}

void ALobbyPlayerController::OnThreePressed()
{
    OpenSetting();
}

void ALobbyPlayerController::SetWindowed(int32 Width, int32 Height)
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

void ALobbyPlayerController::SetFullscreen(bool bTrueFullscreen)
{
    if (!GEngine) return;
    if (UGameUserSettings* GS = GEngine->GetGameUserSettings())
    {
        GS->SetFullscreenMode(bTrueFullscreen ? EWindowMode::Fullscreen : EWindowMode::WindowedFullscreen);
        GS->ApplySettings(false);
        GS->SaveSettings();
    }
}

void ALobbyPlayerController::OpenSetting()
{
    ALevelHUD* LevelHUD = Cast<ALevelHUD>(GetHUD());

    if (!ensureMsgf(LevelHUD != nullptr, TEXT("LevelHUD is null in %s"), *GetName()))
    {
        return;
	}

    ULobbyWidget* LobbyWidget = Cast<ULobbyWidget>(LevelHUD->GetLevelWidget());

    if (ensureMsgf(LobbyWidget != nullptr, TEXT("LobbyWidget is null in %s"), *GetName()))
    {
		return;
    }
    
	LobbyWidget->OpenSetting();
}