// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DebugWidget.generated.h"

/**
 * 
 */
UCLASS()
class COMICCON_API UDebugWidget : public UUserWidget
{
	GENERATED_BODY()
	

private:
	UPROPERTY(meta = (BindWidget))
	class UEditableTextBox* ScoreInputTextBox = nullptr;

	UPROPERTY(meta = (BindWidget))
	class UButton* TestResultButton = nullptr;
};
