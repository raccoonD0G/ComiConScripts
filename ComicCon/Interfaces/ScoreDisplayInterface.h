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
	/** 스폰 직후 1회: 점수/색상 세팅 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Score")
	void SetImageAndColor(UTexture2D* InTexture, const FLinearColor& InTint);

	/** 매 프레임: 페이드(0~1) 전달. 1=완전 불투명, 0=완전 투명 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Score")
	void UpdateOpacity(float InOpacity01);
};
