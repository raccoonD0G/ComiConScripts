// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ScoreDisplayInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UScoreDisplayInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class COMICCON_API IScoreDisplayInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	/** ���� ���� 1ȸ: ����/���� ���� */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Score")
	void SetImageAndColor(UTexture2D* InTexture, const FLinearColor& InTint);

	/** �� ������: ���̵�(0~1) ����. 1=���� ������, 0=���� ���� */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Score")
	void UpdateOpacity(float InOpacity01);
};
