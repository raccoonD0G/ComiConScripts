// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/EnemyBase.h"
#include "GrimReaper.generated.h"

UENUM(BlueprintType)
enum class EGrimReaperState
{
	Spawn,
	Idle,
	Attack,
	Die
};

/**
 * 
 */
UCLASS()
class COMICCON_API AGrimReaper : public AEnemyBase
{
	GENERATED_BODY()

public:
	AGrimReaper();

	// 상태 전환(전이 로직은 추후 추가)
	void SetCurrentState(EGrimReaperState NewState);

	// AActor
	virtual void Tick(float DeltaSeconds) override;
	virtual void PostInitializeComponents() override;
	virtual void StartDie() override;
	virtual void EndDie() override;

protected:
	// 상태별 틱 처리(필요 로직은 추후 추가)
	void OnSpawn(float DeltaSeconds);
	void OnIdle(float DeltaSeconds);
	void OnAttack(float DeltaSeconds);
	void OnDie(float DeltaSeconds);

	UFUNCTION()
	void EndSpawn();

	virtual void EndAttack() override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Flipbooks")
	class UPaperFlipbook* SpawnFlipbook = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Flipbooks")
	class UPaperFlipbook* IdleFlipbook = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Flipbooks")
	class UPaperFlipbook* DieFlipbook = nullptr;

private:
	UPROPERTY(VisibleAnywhere, Category = "State")
	EGrimReaperState CurrentState = EGrimReaperState::Spawn;

// Attack Section
private:
	UPROPERTY(EditAnywhere, Category = "State|Timing")
	FVector2D IdleToAttackDelayRange = FVector2D(2.f, 4.f);

	FTimerHandle IdleToAttackTimerHandle;

	void ScheduleIdleToAttack();
	void OnIdleToAttackTimerExpired();

// Sound Section
private:
	void PlayAttackStartSound();

	UPROPERTY(EditAnywhere, Category = "Audio")
	TArray<TObjectPtr<class USoundBase>> StartAttackSounds;

	FTimerHandle AttackStartHandle;

	void PlaySpawnSound();

	UPROPERTY(EditAnywhere, Category = "Audio")
	TArray<TObjectPtr<class USoundBase>> SpawnSounds;
};
