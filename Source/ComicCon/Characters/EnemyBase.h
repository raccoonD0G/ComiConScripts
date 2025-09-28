// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "EnemyBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHealthChanged, int32, MaxHealth, int32, CurrentHealth);
/**
 * 
 */
UCLASS()
class COMICCON_API AEnemyBase : public APaperCharacter
{
	GENERATED_BODY()

public:
	AEnemyBase();

protected:
	virtual void PostInitializeComponents() override;
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	virtual void Tick(float DeltaTime) override;

//Utils Section
protected:
	float InitialDistToEnd = 0.f;

// Opacity Section
protected:
	float TargetOpacity = 1.0f;
	void SetOpacity(float Opacity);
	float GetOpacity() const;
	void UpdateOpacity(float DeltaSeconds, float OpacityInterpRate);

// Scale Section
protected:
	void UpdateScaleByCloseness(float CurrentDist);

private:
	UPROPERTY(EditAnywhere)
	float StartScale = 0.1f;

	UPROPERTY(EditAnywhere)
	float CustomScale = 1.0f;

// Sway Section
protected:
	UFUNCTION(BlueprintCallable, Category = "Sway")
	void StartSway();

	UFUNCTION(BlueprintCallable, Category = "Sway")
	void StopSway();

private:
	// 스프라이트 기준 상대 위치
	FVector BaseSpriteRelativeLocation = FVector::ZeroVector;

	// 현재/타깃 오프셋(상대 위치 보간용)
	FVector CurrentOffset = FVector::ZeroVector;
	FVector TargetOffset = FVector::ZeroVector;

	// 파라미터
	UPROPERTY(EditAnywhere, Category = "Sway")
	float SwayAmplitude = 20.f;      // 흔들림 범위(피크)

	UPROPERTY(EditAnywhere, Category = "Sway", meta = (ClampMin = "0.01", ClampMax = "5.0"))
	float LerpSpeed = 0.6f;          // 목표까지 부드럽게 이동 속도

	// 2D 게임 평면에 맞춰 흔들 방향 선택 (예: XZ만, XY만 등)
	UPROPERTY(EditAnywhere, Category = "Sway")
	bool bUseYZPlane = false;        // true면 XY로 흔들고, false면 XZ로 흔듦

	// 상태
	bool bIsSwaying = true;
	float TimeToNextTarget = 0.f;

	// 내부
	void PickNewTarget();
	void ApplySwayToSprite();

// Damage Section
public:
	FOnHealthChanged OnHealthChanged;

	int32 GetMaxHealth() const { return MaxHealth; }
	int32 GetCurrentHealth() const { return CurrentHealth; }

protected:
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health")
	int32 MaxHealth = 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Health")
	int32 CurrentHealth = 1;

	FTimerHandle DestroyTimerHandle;

private:
	float DestroyTime = 2.5f;

	UPROPERTY(EditDefaultsOnly, Category = "Health")
	TObjectPtr<UParticleSystem> DeathEffect;

// Score Section
private:

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class UScoreWidgetComponent> ScoreWidgetComponent;

	UPROPERTY(EditAnywhere)
	int32 Score = 1;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UTexture2D> ScoreTexture;

// HealtBar Section
private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class UActorWidgetComponent> HealthBarWidgetComponent;

// Attact Section
public:
	FORCEINLINE int32 GetAttackPower() const { return AttackPower; }

protected:
	AActor* GetTarget() const;

	UFUNCTION()
	void DoDamage();

	UFUNCTION()
	void DoDamageToTarget(AActor* TargetActor);

	void StartAttack();
	void ProcessAttackMidHits(class UPaperFlipbook* Flipbook);

	UFUNCTION()
	virtual void EndAttack();

	UPROPERTY(EditAnywhere, Category = "Attack")
	TArray<float> AttackHitThresholds;

	// 각 타이밍이 이미 발동되었는지 추적
	UPROPERTY(VisibleAnywhere, Category = "Attack")
	TArray<bool> bAttackHitFired;

	UPROPERTY(EditAnywhere, Category = "Flipbooks")
	class UPaperFlipbook* AttackFlipbook = nullptr;

	uint8 bIsAttacking : 1 = false;

private:
	UPROPERTY(EditAnywhere)
	int32 AttackPower = 1;

// Brightness Section
protected:
	UPROPERTY(EditAnywhere)
	float StartBrightness = 0.0f;

	void SetBrightness(float Brightness);
	void UpdateBrightness();
	FVector StartPos = FVector::ZeroVector;

	UPROPERTY(EditAnywhere)
	float BrightnessMul = 1.0f;

	UPROPERTY(EditAnywhere)
	uint8 bIsApplyBrightness : 1 = true;

private:
	UPROPERTY()
	UMaterialInstanceDynamic* SpriteMID = nullptr;

// Collision Section
protected:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class UBoxComponent> HitBox;

// Detect Section
protected:
	virtual bool IsTargetInAttackRange() const;

	UPROPERTY(EditAnywhere, Category = "Dokkaebi|AI")
	float AttackRange = 600.f; // 플레이어와 이 거리 이하면 Attack으로 전이

// Hit Section
private:
	// Hit flash 설정
	UPROPERTY(EditAnywhere, Category = "HitFlash")
	float HitFlashDuration = 0.5f;

	UPROPERTY(EditAnywhere, Category = "HitFlash")
	FLinearColor HitFlashColor = FLinearColor(1.f, 0.1f, 0.1f, 1.f); // 살짝 밝은 레드

private:
	FTimerHandle HitFlashTimerHandle;
	FLinearColor SavedSpriteColor;
	uint8 bHitFlashActive : 1 = false;

	void StartHitFlash();
	void EndHitFlash();

	// ==== Hit Shake ====
	UPROPERTY(EditAnywhere, Category = "HitShake")
	float HitShakeDuration = 0.5f;            // 흔들리는 총 시간(초)

	UPROPERTY(EditAnywhere, Category = "HitShake")
	float HitShakeLocAmpUU = 2.0f;            // 위치 진폭(언리얼 유닛) - XY 오프셋 크기

	UPROPERTY(EditAnywhere, Category = "HitShake")
	float HitShakeRotAmpDeg = 2.0f;           // 회전 진폭(도) - Z(Roll)만 살짝

	UPROPERTY(EditAnywhere, Category = "HitShake", meta = (ClampMin = "0.1"))
	float HitShakeFrequencyHz = 25.0f;        // 떨림 속도(Hz)

	// 내부 상태
	FTimerHandle HitShakeTimerHandle;
	uint8 bHitShakeActive : 1 = false;
	float HitShakeElapsed = 0.f;
	FVector  SavedSpriteRelLoc;
	FRotator SavedSpriteRelRot;

	void StartHitShake();
	void EndHitShake();

// Sound Section
protected:
	void PlayRandomSoundOverlap(const TArray<USoundBase*>& InArray, float Pitch = 1.0f);
	void PlayAttackSound();
	void PlayDieSound();

private:
	UPROPERTY(EditAnywhere, Category = "Audio")
	TArray<TObjectPtr<class USoundBase>> AttackSounds;

	UPROPERTY(EditAnywhere, Category = "Audio")
	TArray<TObjectPtr<class USoundBase>> DieSounds;

	void ResetAttackHitFlags();

// Dead Section
protected:
	virtual void StartDie();

	UFUNCTION(BlueprintCallable, Category = "Health")
	virtual void EndDie();
};

