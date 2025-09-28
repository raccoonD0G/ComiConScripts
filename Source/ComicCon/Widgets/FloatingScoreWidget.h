// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/ComponentWidget.h"
#include "Interfaces/ScoreDisplayInterface.h"
#include "FloatingScoreWidget.generated.h"

/**
 * 
 */
UCLASS()
class COMICCON_API UFloatingScoreWidget : public UComponentWidget, public IScoreDisplayInterface
{
	GENERATED_BODY()

public:
	// 인터페이스 함수들 오버라이드
	virtual void SetImageAndColor_Implementation(UTexture2D* InTexture, const FLinearColor& InTint) override;
	virtual void UpdateOpacity_Implementation(float InOpacity01) override;

protected:
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget), BlueprintReadOnly)
	class UImage* ScoreImage = nullptr;

	UPROPERTY(EditAnywhere, Category = "FloatingScore")
	FName ScoreImageName = TEXT("ScoreImage");
};
