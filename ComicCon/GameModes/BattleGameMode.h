// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BattleGameMode.generated.h"

/**
 * 
 */
UCLASS()
class COMICCON_API ABattleGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	UFUNCTION()
	void StartMatch();

	UFUNCTION()
	void EndMatch();
	
protected:
	virtual void BeginPlay() override;

private:
        FTimerHandle InitRetryTimer;
        FTimerHandle ResultLevelTimerHandle;

	UFUNCTION()
	void Init();

// Score Section
private:

    static constexpr const TCHAR* SaveSlotName = TEXT("BattleSave");
    static constexpr int32 UserIndex = 0;

    void RecordBattleEntry();
    void SaveScore();

// Widget Section
private:
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class UUserWidget> GameLoseWidgetClass;

	UPROPERTY()
	class UGameCompleteWidget* GameOverWidgetInstance = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class UUserWidget> GameWinWidgetClass;

	UPROPERTY()
	class UGameCompleteWidget* GameCompleteWidget = nullptr;

	uint8 bShowVideoQR : 1 = false;
};
