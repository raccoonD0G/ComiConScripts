// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDs/LobbyHUD.h"
#include "Blueprint/UserWidget.h"


void ALobbyHUD::BeginPlay()
{
	Super::BeginPlay();

    APlayerController* PC = PlayerOwner;
    if (!PC) return;

    FInputModeGameAndUI InputMode;
    InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
    InputMode.SetHideCursorDuringCapture(true);

    if (GetLevelWidget())
    {
        InputMode.SetWidgetToFocus(GetLevelWidget()->TakeWidget());
    }

    PC->SetInputMode(InputMode);
    EnableInput(PC);
    PC->bShowMouseCursor = true;
}
