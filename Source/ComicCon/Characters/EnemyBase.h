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
	// ��������Ʈ ���� ��� ��ġ
	FVector BaseSpriteRelativeLocation = FVector::ZeroVector;

	// ����/Ÿ�� ������(��� ��ġ ������)
	FVector CurrentOffset = FVector::ZeroVector;
	FVector TargetOffset = FVector::ZeroVector;

	// �Ķ����
	UPROPERTY(EditAnywhere, Category = "Sway")
	float SwayAmplitude = 20.f;      // ��鸲 ����(��ũ)

	UPROPERTY(EditAnywhere, Category = "Sway", meta = (ClampMin = "0.01", ClampMax = "5.0"))
	float LerpSpeed = 0.6f;          // ��ǥ���� �ε巴�� �̵� �ӵ�

	// 2D ���� ��鿡 ���� ��� ���� ���� (��: XZ��, XY�� ��)
	UPROPERTY(EditAnywhere, Category = "Sway")
	bool bUseYZPlane = false;        // true�� XY�� ����, false�� XZ�� ���

	// ����
	bool bIsSwaying = true;
	float TimeToNextTarget = 0.f;

	// ����
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

	// �� Ÿ�̹��� �̹� �ߵ��Ǿ����� ����
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
	float AttackRange = 600.f; // �÷��̾�� �� �Ÿ� ���ϸ� Attack���� ����

// Hit Section
private:
	// Hit flash ����
	UPROPERTY(EditAnywhere, Category = "HitFlash")
	float HitFlashDuration = 0.5f;

	UPROPERTY(EditAnywhere, Category = "HitFlash")
	FLinearColor HitFlashColor = FLinearColor(1.f, 0.1f, 0.1f, 1.f); // ��¦ ���� ����

private:
	FTimerHandle HitFlashTimerHandle;
	FLinearColor SavedSpriteColor;
	uint8 bHitFlashActive : 1 = false;

	void StartHitFlash();
	void EndHitFlash();

	// ==== Hit Shake ====
	UPROPERTY(EditAnywhere, Category = "HitShake")
	float HitShakeDuration = 0.5f;            // ��鸮�� �� �ð�(��)

	UPROPERTY(EditAnywhere, Category = "HitShake")
	float HitShakeLocAmpUU = 2.0f;            // ��ġ ����(�𸮾� ����) - XY ������ ũ��

	UPROPERTY(EditAnywhere, Category = "HitShake")
	float HitShakeRotAmpDeg = 2.0f;           // ȸ�� ����(��) - Z(Roll)�� ��¦

	UPROPERTY(EditAnywhere, Category = "HitShake", meta = (ClampMin = "0.1"))
	float HitShakeFrequencyHz = 25.0f;        // ���� �ӵ�(Hz)

	// ���� ����
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

