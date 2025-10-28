// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BattleWidget.generated.h"


/**
 * 
 */
UCLASS()
class COMICCON_API UBattleWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
    virtual void NativeConstruct() override;

private:
    UPROPERTY(meta = (BindWidget))
    class UTextBlock* MyScoreText;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* HighScoreText;

    UPROPERTY(meta = (BindWidget))
    class UProgressBar* HealthProgressBar;

    UPROPERTY(meta = (BindWidget))
    class UTextBlock* TimerText;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Text_HounterCount;

    UFUNCTION(BlueprintCallable, Category = "BattleWidget")
    void SetScoreText(int32 Count);

    UFUNCTION(BlueprintCallable, Category = "BattleWidget")
    void SetHighScoreText(int32 Count);

    UFUNCTION()
    void OnPlayerHealthChanged(int32 MaxHealth, int32 CurrentHealth);

    UFUNCTION(BlueprintCallable, Category = "BattleWidget")
    void SetHealthPercent(float Percent);

    UFUNCTION(BlueprintCallable, Category = "BattleWidget")
    void SetTimerText(int32 InSecond);

    UPROPERTY(VisibleAnywhere, Category = "Score")
    int32 CachedHighScore = 0;

// Aniamtion Section
private:
    UPROPERTY(meta = (BindWidgetAnim), Transient)
    class UWidgetAnimation* StartAnimation;

    UFUNCTION()
    void PlayStartAnimation();
};
