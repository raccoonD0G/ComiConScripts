// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "BattleGameState.generated.h"

// 카운트다운 시작 알림 (한 번)
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCountdownStarted);
// 남은 시간 알려주기 (매 틱)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCountdownSec, int32, RemainingSeconds);
// 카운트다운 끝 알림 (한 번)
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCountdownFinished);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnScoreChanged, int32, NewScore);
/**
 * 
 */
UCLASS()
class COMICCON_API ABattleGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	ABattleGameState();

protected:
        virtual void BeginPlay() override;

public:
        UFUNCTION(BlueprintCallable, Category = "Timer")
        void StartCountdown();

        /** 카운트다운 시작 시 1회 브로드캐스트 */
        UPROPERTY(BlueprintAssignable, Category = "Timer")
        FOnCountdownStarted OnCountdownStarted;

	/** 1초마다 남은 시간 브로드캐스트 */
	UPROPERTY(BlueprintAssignable, Category = "Timer")
	FOnCountdownSec OnCountdownSec;

	/** 카운트다운 종료 시 1회 브로드캐스트 */
	UPROPERTY(BlueprintAssignable, Category = "Timer")
	FOnCountdownFinished OnCountdownFinished;

public:
	FORCEINLINE int32 GetMaxSeconds() const { return MaxSeconds; }
	FORCEINLINE int32 GetRemainingSeconds() const { return RemainingSeconds; }

protected:

	/** 남은 시간(초). UI에서 바인딩해서 쓰기 좋게 공개 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Timer")
	int32 MaxSeconds = 60;

        /** 남은 시간(초). UI에서 바인딩해서 쓰기 좋게 공개 */
        UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Timer")
        int32 RemainingSeconds = 60;

        UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Timer")
        bool bAutoStartCountdown = true;

        /** 1초마다 호출되는 콜백 */
        UFUNCTION()
        void HandleCountdownTick();

private:
        FTimerHandle CountdownTimerHandle;
        uint8 bCountdownActive : 1 = false;

// Score Section

public:
	void AddScore(int32 InScore);

	UFUNCTION(BlueprintCallable)
	FORCEINLINE int32 GetScore() const { return Score; }

	FOnScoreChanged OnScoreChanged;

private:
	UPROPERTY(VisibleAnywhere)
	int32 Score = 0;
};