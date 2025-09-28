// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/ComponentWidget.h"
#include "HealthBarWidget.generated.h"

/**
 * 
 */
UCLASS()
class COMICCON_API UHealthBarWidget : public UComponentWidget
{
	GENERATED_BODY()

public:
	virtual void Init() override;

protected:
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

private:
	UPROPERTY(meta = (BindWidget))
	class UProgressBar* HealthBar;

	UFUNCTION()
	void OnHealthChanged(int32 MaxHealth, int32 CurrentHealth);

	void SetHealthPercent(float Percent);
};
