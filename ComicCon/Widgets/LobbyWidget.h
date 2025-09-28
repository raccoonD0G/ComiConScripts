// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LobbyWidget.generated.h"

/**
 * 
 */
UCLASS()
class COMICCON_API ULobbyWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	
private:
	UFUNCTION(BlueprintCallable)
	void SetWindowed(int32 Width, int32 Height);

	UFUNCTION(BlueprintCallable)
	void SetFullscreen(bool bTrueFullscreen);

};
