// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "ViewPlayer.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPlayerHealthChanged, int32, MaxHealth, int32, CurrentHealth);

UCLASS()
class COMICCON_API AViewPlayer : public APawn
{
	GENERATED_BODY()

public:
	AViewPlayer();

protected:
	virtual void PostInitializeComponents() override;
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaSeconds) override;

// Scale Section
private:
    UPROPERTY(EditAnywhere, Category = "View|Scale", meta = (ClampMin = "0.01", UIMin = "0.1", UIMax = "5.0"))
    float ViewScale = 1.0f;

    UPROPERTY(EditAnywhere, Category = "View|Media", meta = (ClampMin = "1", UIMin = "1"))
    FIntPoint VideoFrameSize = FIntPoint(1080, 1920);

// Component Section
public:
    FORCEINLINE class USpringArmComponent* GetSpringArmComponent() const { return SpringArmComponent; }

private:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Follow", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class USceneComponent> SceneComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Follow", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class USpringArmComponent> SpringArmComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Follow", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UCameraBoundsClampComponent> CameraBoundsClampComponent;

// Spawn Actor Section
private:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Follow", meta = (AllowPrivateAccess = "ture"))
    TObjectPtr<class AMirroredPlayer> MirroredPlayer;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Follow", meta = (AllowPrivateAccess = "ture"))
    TSubclassOf<class AMirroredPlayer> MirroredPlayerClass;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Follow", meta = (AllowPrivateAccess = "ture"))
    TObjectPtr<class AAmulet> AmuletLeft;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Follow", meta = (AllowPrivateAccess = "ture"))
    TObjectPtr<class AAmulet> AmuletRight;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Follow", meta = (AllowPrivateAccess = "ture"))
    TSubclassOf<class AAmulet> AmuletClass;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Follow", meta = (AllowPrivateAccess = "ture"), meta = (MustImplement = "ClampVolumeInterface"))
    TSubclassOf<class AActor> WebcamReceiverClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Follow", meta = (AllowPrivateAccess = "ture"))
	TObjectPtr<class AActor> WebcamReceiver;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Follow", meta = (AllowPrivateAccess = "ture"))
    float FollowLagSpeed = 12.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Follow", meta = (AllowPrivateAccess = "ture"))
    FVector FollowWorldOffset = FVector::ZeroVector;

// Health Section
public:
    FOnPlayerHealthChanged OnPlayerHealthChanged;

    void GetAttacked(int32 InAttackPower);

    int32 GetMaxHealth() const { return MaxHealth; }
    int32 GetCurrentHealth() const { return CurrentHealth; }

private:
    UPROPERTY(EditAnywhere)
    int32 MaxHealth = 5;

    UPROPERTY(VisibleAnywhere)
    int32 CurrentHealth = 0;

// Niagara Section
private:
    UPROPERTY(EditAnywhere)
    TObjectPtr<class UNiagaraSystem> DamagedEffect;

    UPROPERTY(EditAnywhere)
    float NiagaraXOffset = 50.0f;

    void ShowDamagedEffect();

// Camera Shake Section
private:

    UPROPERTY(EditAnywhere, Category = "Camera")
    TSubclassOf<class UCameraShakeBase> HitShakeClass; // BP_HitShake Ҵ

    void PlayHitShake();
};
