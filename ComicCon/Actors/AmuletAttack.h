﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AmuletAttack.generated.h"

UCLASS()
class COMICCON_API AAmuletAttack : public AActor
{
    GENERATED_BODY()

public:
    AAmuletAttack();

    void InitializeAttack(const FVector& InCenter, const FRotator& InRotation, float InLength, float InWidth);

    void SpawnOrUpdateFX(const FVector& Center, const FRotator& Rotation, float InLength, float InWidth);

private:
    // 최소 전체 스윙 길이(cm) — 이 값보다 작으면 이 값으로 보정됩니다.
    UPROPERTY(EditAnywhere, Category = "Attack|Config")
    float MinAttackLength = 150.0f;

    // 최소 FX 전체 길이(cm) — FX 스케일 계산에 사용됩니다.
    // 보통 MinAttackLength와 같게 두면 직관적입니다.
    UPROPERTY(EditAnywhere, Category = "Attack|Config")
    float MinFXLength = 150.0f;

//Damage Section
private:
    UFUNCTION()
    void OnPlaneBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    UPROPERTY(EditAnywhere, Category = "Attack|Damage")
    float SingleSwingDamageAmount = 25.f;

    UPROPERTY(EditAnywhere, Category = "Attack|Damage")
    TSubclassOf<UDamageType> DamageTypeClass;

    // 한 번만 주기 위한 가드
    UPROPERTY(Transient)
    TSet<TWeakObjectPtr<AActor>> DamagedActors;

    UPROPERTY(VisibleAnywhere)
    class UBoxComponent* PlaneBox;

    UPROPERTY(EditAnywhere)
    float PlaneHalfThickness = 20.f; // OverlapPlaneOnce와 동일 의미의 두께 HalfExtent

    UPROPERTY(VisibleAnywhere)
    FVector2D PlaneHalfSize = FVector2D(50.f, 20.f); // X=HalfLen(진행), Y=HalfWidth(폭)

    float LifeSeconds = 1.0f;

    FVector AttackCenter;
    FRotator AttackRotation;
    float PlaneLength;
    float PlaneWidth;

    uint8 bDoDebug : 1 = false;

// Effects Section
private:
    UPROPERTY(EditDefaultsOnly, Category = "FX")
    class UNiagaraSystem* SwingPlaneFX;

    UPROPERTY(Transient)
    class UNiagaraComponent* SpawnedFX;

    // ScaleMultiplier 파라미터 이름
    FName ScaleMultiplierParamName = TEXT("User.ScaleMultiplier");

// Sound Section
private:
    UPROPERTY(VisibleAnywhere)
    TObjectPtr<UAudioComponent> AudioComponent;

    UPROPERTY(EditAnywhere)
    TArray<TObjectPtr<USoundBase>> ShortSounds;

    UPROPERTY(EditAnywhere)
    TArray<TObjectPtr<USoundBase>> LongSounds;

};
