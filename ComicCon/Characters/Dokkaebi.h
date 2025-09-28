// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/EnemyBase.h"
#include "Dokkaebi.generated.h"

UENUM(BlueprintType)
enum class EDokkaebiState
{
	Idle,
    ReadyJump,
	Jump,
    Land,
	Attack,
    Die
};

/**
 * 
 */
UCLASS()
class COMICCON_API ADokkaebi : public AEnemyBase
{
	GENERATED_BODY()

public:
    ADokkaebi();

protected:
    virtual void PostInitializeComponents() override;
	virtual void BeginPlay() override;
    virtual void Tick(float DeltaSeconds) override;
	virtual void Landed(const FHitResult& Hit) override;
    virtual void StartDie() override;

    virtual bool IsTargetInAttackRange() const override;
private:
	void OnIdle();
	void OnJump();
    void OnReadyJump();
    void OnLand();
	void OnAttack();
    void OnDie();

private:
    UPROPERTY(VisibleAnywhere)
	EDokkaebiState CurrentState;

    void SetCurrentState(EDokkaebiState NewCurrentState);

    void ScheduleNextJump();

    void TryStartJump();

    void ForwardJump();

    UFUNCTION()
    void EndReadyJump();

    UFUNCTION()
    void EndLand();

    virtual void EndAttack() override;

    virtual void EndDie() override;

protected:
    UPROPERTY(EditAnywhere, Category = "Dokkaebi|Movement")
    float JumpForwardPower = 1200.0f; // 전방 XY 속도(점프 시 부여)

    UPROPERTY(EditAnywhere, Category = "Dokkaebi|Movement")
    float JumpUpPower = 1200.0f;

    UPROPERTY(EditAnywhere, Category = "Dokkaebi|AI")
    FVector2D IdleJumpIntervalRange = FVector2D(0.25f, 0.75f); // 초 단위 [min, max]

    UPROPERTY(EditAnywhere, Category = "Dokkaebi|Flipbook")
    class UPaperFlipbook* IdleFlipbook = nullptr;

    UPROPERTY(EditAnywhere, Category = "Dokkaebi|Flipbook")
    class UPaperFlipbook* ReadyJumpFlipbook = nullptr;

    UPROPERTY(EditAnywhere, Category = "Dokkaebi|Flipbook")
    class UPaperFlipbook* JumpFlipbook = nullptr;

    UPROPERTY(EditAnywhere, Category = "Dokkaebi|Flipbook")
    class UPaperFlipbook* LandFlipbook = nullptr;

    UPROPERTY(EditAnywhere, Category = "Dokkaebi|Flipbook")
    class UPaperFlipbook* DieFlipbook = nullptr;

private:
    FTimerHandle IdleJumpTimerHandle;

    FTimerHandle JumpHandle;

// Sound Section
private:
    void PlaySpawnSound();

    UPROPERTY(EditAnywhere, Category = "Audio")
    TArray<TObjectPtr<class USoundBase>> SpawnSounds;

    void PlayLandSound();

    UPROPERTY(EditAnywhere, Category = "Audio")
    TArray<TObjectPtr<class USoundBase>> LandSounds;

    FTimerHandle LandHandle;
};
