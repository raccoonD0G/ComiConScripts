// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "BattleGameState.generated.h"

UENUM(BlueprintType)
enum class EGamePlayState : uint8
{
	BeforeBattle,
	OnBattle,
	AfterBattle
};

// ----- State Enter Delegates -----
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnBeforeBattleStateEntered);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnBattleStateEntered);

// ----- Battle (in-game) Timer Delegates -----
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnBattleTimerStarted);                             // 한 번
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBattleTimerSec, int32, RemainingSecs);  // 매초
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnBattleTimerFinished);                            // 한 번

// ----- Score -----
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnScoreChanged, int32, NewScore);

/**
 * GameState: Pre-battle 3s → On-battle 60s
 */
UCLASS()
class COMICCON_API ABattleGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	ABattleGameState();

protected:
	virtual void PostInitializeComponents() override;
	virtual void BeginPlay() override;

	// ---------- State Section ----------
private:
	UPROPERTY(VisibleAnywhere, Category = "State")
	EGamePlayState CurrentState = EGamePlayState::BeforeBattle;

public:
	UFUNCTION(BlueprintPure, Category = "State")
	FORCEINLINE EGamePlayState GetCurrentState() const { return CurrentState; }

	void SetCurrentState(EGamePlayState NewState);

public:
	UPROPERTY(BlueprintAssignable, Category = "State")
	FOnBeforeBattleStateEntered OnBeforeBattleStateEntered;

	UPROPERTY(BlueprintAssignable, Category = "State")
	FOnBattleStateEntered OnBattleStateEntered;

	// ---------- BeforeBattle Section (3s ready timer) ----------
private:
	FTimerHandle BeforeBattleTimerHandle;
	void StartBattle();

	// ---------- OnBattle Section (match timer) ----------
public:
	/** 실전 타이머 시작 (예: 60초) */
	UFUNCTION(BlueprintCallable, Category = "BattleTimer")
	void StartBattleTimer();

	/** 실전 타이머 델리게이트들 */
	UPROPERTY(BlueprintAssignable, Category = "BattleTimer")
	FOnBattleTimerStarted OnBattleTimerStarted;

	UPROPERTY(BlueprintAssignable, Category = "BattleTimer")
	FOnBattleTimerSec OnBattleTimerSec;

	UPROPERTY(BlueprintAssignable, Category = "BattleTimer")
	FOnBattleTimerFinished OnBattleTimerFinished;

public:
	UFUNCTION(BlueprintPure, Category = "BattleTimer")
	FORCEINLINE int32 GetBattleMaxSeconds() const { return BattleMaxSeconds; }

	UFUNCTION(BlueprintPure, Category = "BattleTimer")
	FORCEINLINE int32 GetBattleRemainingSeconds() const { return BattleRemainingSeconds; }

protected:
	/** 실전 타이머 총 길이(초) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "BattleTimer")
	int32 BattleMaxSeconds = 60;

	/** 실전 타이머 남은 시간(초) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BattleTimer")
	int32 BattleRemainingSeconds = 60;

	/** 매 1초 콜백 */
	UFUNCTION()
	void HandleBattleTimerTick();

private:
	FTimerHandle BattleTimerHandle;
	uint8 bBattleTimerActive : 1 = false;

	// ---------- Score Section ----------
public:
	UFUNCTION(BlueprintCallable, Category = "Score")
	void AddScore(int32 InScore);

	UFUNCTION(BlueprintPure, Category = "Score")
	FORCEINLINE int32 GetScore() const { return Score; }

	UPROPERTY(BlueprintAssignable, Category = "Score")
	FOnScoreChanged OnScoreChanged;

private:
	UPROPERTY(VisibleAnywhere, Category = "Score")
	int32 Score = 0;
};
