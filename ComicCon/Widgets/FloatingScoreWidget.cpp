// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/FloatingScoreWidget.h"
#include "Components/Image.h"

void UFloatingScoreWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UFloatingScoreWidget::SetImageAndColor_Implementation(UTexture2D* InTexture, const FLinearColor& InTint)
{
	if (ScoreImage && InTexture)
	{
		FSlateBrush Brush;
		Brush.SetResourceObject(InTexture);
		Brush.ImageSize = FVector2D(InTexture->GetSizeX(), InTexture->GetSizeY());

		ScoreImage->SetBrush(Brush);
		ScoreImage->SetColorAndOpacity(InTint);
		ScoreImage->SetRenderOpacity(1.f);
	}
}

void UFloatingScoreWidget::UpdateOpacity_Implementation(float InOpacity01)
{
	if (ScoreImage)
	{
		FLinearColor C = ScoreImage->GetColorAndOpacity();
		C.A = FMath::Clamp(InOpacity01, 0.f, 1.f);
		ScoreImage->SetColorAndOpacity(C);
	}
}
