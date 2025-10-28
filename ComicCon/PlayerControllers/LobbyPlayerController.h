// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "LobbyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class COMICCON_API ALobbyPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* IA_Enter = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* IA_One = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* IA_Two = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* IA_Three = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputMappingContext* IMC_LobbyHUD = nullptr;

private:
	void OnEnterPressed();
	void OnOnePressed();
	void OnTwoPressed();
	void OnThreePressed();

	void SetWindowed(int32 Width, int32 Height);

	void SetFullscreen(bool bTrueFullscreen);

	void OpenSetting();
};
