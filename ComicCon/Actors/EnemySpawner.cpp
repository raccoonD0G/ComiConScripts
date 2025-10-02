#include "Actors/EnemySpawner.h"
#include "TimerManager.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Characters/EnemyBase.h"
#include <Components/BoxComponent.h>

AEnemySpawner::AEnemySpawner()
{
	PrimaryActorTick.bCanEverTick = true;

	SpawnBoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	RootComponent = SpawnBoxComponent;
	SpawnBoxComponent->SetCollisionProfileName(TEXT("NoCollision"));
}

void AEnemySpawner::BeginPlay()
{
    Super::BeginPlay();

    if (bAutoStart)
    {
            Start();
    }
}

void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// ====== 동시 스폰 제한 유틸 ======
void AEnemySpawner::PruneDead()
{
	for (int32 i = AliveSpawned.Num() - 1; i >= 0; --i)
	{
		if (!AliveSpawned[i].IsValid())
		{
			AliveSpawned.RemoveAtSwap(i);
		}
	}
}

int32 AEnemySpawner::GetAliveCount()
{
	PruneDead();
	return AliveSpawned.Num();
}

bool AEnemySpawner::CanSpawnMore()
{
	return GetAliveCount() < MaxConcurrentSpawned;
}

void AEnemySpawner::RegisterAlive(AEnemyBase* NewEnemy)
{
	if (!NewEnemy) return;
	PruneDead();
	AliveSpawned.Add(NewEnemy);
	NewEnemy->OnDestroyed.AddDynamic(this, &AEnemySpawner::OnSpawnedEnemyDestroyed);
}

void AEnemySpawner::OnSpawnedEnemyDestroyed(AActor* DestroyedActor)
{
	for (int32 i = AliveSpawned.Num() - 1; i >= 0; --i)
	{
		if (!AliveSpawned[i].IsValid() || AliveSpawned[i].Get() == DestroyedActor)
		{
			AliveSpawned.RemoveAtSwap(i);
		}
	}
}

// ====== 기존 루프 ======
void AEnemySpawner::Start()
{
        InitializeRandomStream();

        if (bRunning) return;
        bRunning = true;

        if (InitialDelay < KINDA_SMALL_NUMBER)
        {
		ScheduleNextSpawn();
	}
	else
	{
		GetWorld()->GetTimerManager().SetTimer(
			SpawnLoopTimerHandle, this, &AEnemySpawner::ScheduleNextSpawn, InitialDelay, false);
	}
}

void AEnemySpawner::InitializeRandomStream()
{
        if (bRandomStreamInitialized)
        {
                return;
        }

        if (bUseDeterministicSeed)
        {
                Rng.Initialize(RandomSeed);
        }
        else
        {
                Rng.GenerateNewSeed();
        }

        bRandomStreamInitialized = true;
}

void AEnemySpawner::Stop()
{
	if (!bRunning) return;
	bRunning = false;

	if (UWorld* World = GetWorld())
	{
		World->GetTimerManager().ClearTimer(SpawnLoopTimerHandle);
	}
}

void AEnemySpawner::ScheduleNextSpawn()
{
	if (!bRunning) return;

	if (UWorld* World = GetWorld())
	{
		const float J = SpawnIntervalJitter;
		const float Noise = (J > 0.f) ? Rng.FRandRange(-J, +J) : 0.f;

		// 경과 시간
		const float Elapsed = World->GetTimeSeconds();

		// 배율: 0초 → 1.0, 90초 → 0.5 (선형)
		float Multiplier = 1.0f;
		if (Elapsed < 90.f)
		{
			Multiplier = FMath::Lerp(1.0f, 0.5f, Elapsed / 90.f);
		}
		else
		{
			Multiplier = 0.5f; // 90초 이후는 2배 빨라진 상태 유지
		}

		// 다음 딜레이
		const float NextDelay = FMath::Max(
			0.05f,
			(SpawnInterval * Multiplier) + Noise
		);

		World->GetTimerManager().SetTimer(
			SpawnLoopTimerHandle, this, &AEnemySpawner::SpawnOnce, NextDelay, false);
	}
}

void AEnemySpawner::SpawnOnce()
{
	if (!bRunning)
	{
		return;
	}

	// ★★★ 동시 제한 체크: 넘치면 이번 턴은 건너뛰고 다음 스케줄로
	if (!CanSpawnMore())
	{
		ScheduleNextSpawn();
		return;
	}

	if (!EnemyClass)
	{
		ScheduleNextSpawn();
		return;
	}

	UWorld* World = GetWorld();
	if (!World)
	{
		ScheduleNextSpawn();
		return;
	}

	const FTransform SpawnXform = GetSpawnTransform();

	// 지연 스폰
	AEnemyBase* NewEnemy = World->SpawnActorDeferred<AEnemyBase>(EnemyClass, SpawnXform, this, nullptr, ESpawnActorCollisionHandlingMethod::AlwaysSpawn);

	if (NewEnemy)
	{
		// 사용자 커스터마이즈
		ConfigureSpawnedEnemy(NewEnemy);

		// 스폰 완료
		NewEnemy->FinishSpawning(SpawnXform);

		// FinishSpawning 이후 실제로 살아있는지 확인 후 등록
		if (IsValid(NewEnemy) && !NewEnemy->IsPendingKill())
		{
			RegisterAlive(NewEnemy);
		}
	}

	// 다음 스폰 예약
	ScheduleNextSpawn();
}

// ====== 기본 구현(변경 없음) ======
FTransform AEnemySpawner::GetSpawnTransform_Implementation()
{
	return GetActorTransform();
}

void AEnemySpawner::ConfigureSpawnedEnemy_Implementation(AEnemyBase* NewEnemy)
{
	// 기본은 아무것도 안 함. (파생 클래스에서 세팅)
}
