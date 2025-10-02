// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawner.generated.h"


UCLASS()
class COMICCON_API AEnemySpawner : public AActor
{
	GENERATED_BODY()

public:
	AEnemySpawner();

protected:
        virtual void BeginPlay() override;
        virtual void Tick(float DeltaTime) override;

public:
        UFUNCTION(BlueprintCallable)
        void Start();

	UFUNCTION(BlueprintCallable)
	void Stop();

protected:
        void ScheduleNextSpawn();
        void SpawnOnce();
        void InitializeRandomStream();

        // ====== 스폰 포인트/설정 (기존) ======
        UFUNCTION(BlueprintNativeEvent)
        FTransform GetSpawnTransform();
        virtual FTransform GetSpawnTransform_Implementation();

	UFUNCTION(BlueprintNativeEvent)
	void ConfigureSpawnedEnemy(AEnemyBase* NewEnemy);
	virtual void ConfigureSpawnedEnemy_Implementation(AEnemyBase* NewEnemy);

	// ====== 동시 스폰 제한 기능 ======
protected:
	/** 동시에 살아있을 수 있는 최대 수 (부모 공통) */
	UPROPERTY(EditAnywhere, Category = "Spawn|Limit")
	int32 MaxConcurrentSpawned = 3;

	/** 내가 스폰했고 아직 살아있는 적들 */
	UPROPERTY()
	TArray<TWeakObjectPtr<AEnemyBase>> AliveSpawned;

	/** 죽은 포인터 정리 */
	void PruneDead();

	/** 현재 살아있는 수 */
	int32 GetAliveCount();

	/** 더 스폰해도 되는가 */
	bool CanSpawnMore();

	/** 유효한 새 스폰 등록(파괴시 자동 제거) */
	void RegisterAlive(AEnemyBase* NewEnemy);

	/** 액터 파괴 콜백 */
	UFUNCTION()
	void OnSpawnedEnemyDestroyed(AActor* DestroyedActor);

protected:
	// ====== 기존 멤버들 ======
	UPROPERTY(EditAnywhere, Category = "Spawn|Loop")
	bool bAutoStart = true;

	UPROPERTY(EditAnywhere, Category = "Spawn|Loop")
	float InitialDelay = 0.f;

	UPROPERTY(EditAnywhere, Category = "Spawn|Loop")
	float SpawnInterval = 2.f;

	UPROPERTY(EditAnywhere, Category = "Spawn|Loop")
	float SpawnIntervalJitter = 0.0f;

	UPROPERTY(EditAnywhere, Category = "Spawn|Class")
	TSubclassOf<AEnemyBase> EnemyClass;

	UPROPERTY(EditAnywhere, Category = "Spawn|Random")
	bool bUseDeterministicSeed = false;

	UPROPERTY(EditAnywhere, Category = "Spawn|Random")
	int32 RandomSeed = 12345;

	// 예시용 RNG
	FRandomStream Rng;

        UPROPERTY()
        bool bRunning = false;

        uint8 bRandomStreamInitialized : 1 = false;

        FTimerHandle SpawnLoopTimerHandle;

// Box Section
protected:
	UPROPERTY(VisibleAnywhere, Category = "Succubus|Spawn")
	TObjectPtr<class UBoxComponent> SpawnBoxComponent;
};
