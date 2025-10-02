// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/EnemyBase.h"
#include "PaperFlipbookComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameStates/BattleGameState.h"
#include "Components/ActorWidgetComponent.h"
#include "Pawns/ViewPlayer.h"
#include "Materials/MaterialRenderProxy.h"
#include "Components/ScoreWidgetComponent.h"
#include "Components/BoxComponent.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundBase.h"
#include "GameStates/BattleGameState.h"

AEnemyBase::AEnemyBase()
{
	PrimaryActorTick.bCanEverTick = true;
	bUseControllerRotationYaw = false;

	HitBox = CreateDefaultSubobject<UBoxComponent>(TEXT("HitBox"));
	HitBox->SetupAttachment(RootComponent);
	HitBox->SetCollisionProfileName(TEXT("GetDamageBox"));

	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	HealthBarWidgetComponent = CreateDefaultSubobject<UActorWidgetComponent>(TEXT("HealthWidgetComponent"));
	HealthBarWidgetComponent->SetupAttachment(RootComponent);

	ScoreWidgetComponent = CreateDefaultSubobject<UScoreWidgetComponent>(TEXT("ScoreWidgetComponent"));
	ScoreWidgetComponent->SetupAttachment(RootComponent);
	ScoreWidgetComponent->SetRelativeLocation(FVector(-10.0f, 0, 0));
}

void AEnemyBase::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	if (GetTarget())
	{
		InitialDistToEnd = FMath::Abs(GetActorLocation().X - GetTarget()->GetActorLocation().X);
		InitialDistToEnd = FMath::Max(InitialDistToEnd, 1.f); // 0 방지
	}
	
	SetActorScale3D(FVector(StartScale));

	if (GetSprite())
	{
		BaseSpriteRelativeLocation = GetSprite()->GetRelativeLocation();
	}
	CurrentOffset = FVector::ZeroVector;
	PickNewTarget();

	if (GetSprite())
	{
		// 이미 적용된 MID가 있으면 재사용, 없으면 여기서만 1회 생성
		UMaterialInterface* Current = GetSprite()->GetMaterial(0);
		SpriteMID = Cast<UMaterialInstanceDynamic>(Current);
		if (!SpriteMID)
		{
			// 권장: 컴포넌트의 헬퍼를 사용해 DMI 생성/적용을 한 번에
			SpriteMID = GetSprite()->CreateDynamicMaterialInstance(0, Current);
		}
		if (SpriteMID)
		{
			SpriteMID->SetScalarParameterValue(TEXT("BrightnessParam"), 1.0f);
		}
	}

	
}

void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();

	ABattleGameState* BattleGameState = GetWorld()->GetGameState<ABattleGameState>();
	if (BattleGameState)
	{
		const float MaxSec = BattleGameState->GetBattleMaxSeconds();
		const float RemSec = BattleGameState->GetBattleRemainingSeconds();

		if (MaxSec > KINDA_SMALL_NUMBER)
		{
			// 진행도: 0.0 (시작) ~ 1.0 (끝)
			const float Progress = FMath::Clamp((MaxSec - RemSec) / MaxSec, 0.f, 1.f);

			// 0.5 ~ 1.5 사이 선형 보간
			float Scale = (Progress < 0.5f)
				? FMath::Lerp(0.5f, 1.5f, Progress / 0.5f)  // 0~0.5 사이에서 0.5~1.5
				: 1.5f;

			MaxHealth = MaxHealth * Scale;
		}
	}

	StartPos = GetActorLocation();

	CurrentHealth = MaxHealth;
	OnHealthChanged.Broadcast(MaxHealth, CurrentHealth);
}

void AEnemyBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	SpriteMID = nullptr;

	Super::EndPlay(EndPlayReason);

#if WITH_EDITOR
	if (EndPlayReason == EEndPlayReason::EndPlayInEditor)
	{
		FUniformExpressionCacheAsyncUpdateScope AsyncUpdateScope;
	}
#endif
}

void AEnemyBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (bIsSwaying)
	{
		// 위치 오프셋 보간(스프라이트 상대좌표만)
		CurrentOffset = FMath::VInterpTo(CurrentOffset, TargetOffset, DeltaSeconds, LerpSpeed);
		ApplySwayToSprite();

		// 타깃 재설정 타이밍
		TimeToNextTarget -= DeltaSeconds;
		if (TimeToNextTarget <= 0.f && FVector::Dist(CurrentOffset, TargetOffset) < 1.f)
		{
			PickNewTarget();
		}

		if (bIsApplyBrightness)
		{
			UpdateBrightness();
		}
	}
	
	const float DistToPlayer = FMath::Abs(GetActorLocation().X - GetTarget()->GetActorLocation().X);

	UpdateScaleByCloseness(DistToPlayer);

	if (bHitShakeActive)
	{
		if (GetSprite())
		{
			HitShakeElapsed += DeltaSeconds;

			const float w = 2.f * PI * HitShakeFrequencyHz;

			// XY를 서로 다른 위상/주파수로 살짝 흔들기
			const float ox = FMath::Sin(w * HitShakeElapsed * 1.0f + 0.7f) * (HitShakeLocAmpUU * 0.5f);
			const float oy = FMath::Sin(w * HitShakeElapsed * 1.7f + 1.1f) * (HitShakeLocAmpUU);

			// 2D 게임이면 Roll(Z축)만 살짝 기울여주면 ‘덜덜’ 느낌이 좋음
			const float roll = FMath::Sin(w * HitShakeElapsed * 2.3f) * HitShakeRotAmpDeg;

			GetSprite()->SetRelativeLocation(SavedSpriteRelLoc + FVector(ox, oy, 0.f));
			GetSprite()->SetRelativeRotation((SavedSpriteRelRot + FRotator(0.f, 0.f, roll)));
		}
	}

	if (bIsAttacking)
	{
		ProcessAttackMidHits(AttackFlipbook);
	}
}

void AEnemyBase::SetOpacity(float Opacity)
{
	UWorld* W = GetWorld();
	if (!W || W->bIsTearingDown) return;

	// 가능한 경우 스프라이트 구성 요소에 불투명도를 설정합니다.
	if (UPaperFlipbookComponent* SpriteComp = GetSprite())
	{
		FLinearColor Color = SpriteComp->GetSpriteColor();
		Color.A = Opacity;
		SpriteComp->SetSpriteColor(Color);
	}
}

float AEnemyBase::GetOpacity() const
{
	const UWorld* W = GetWorld();
	if (!W || W->bIsTearingDown)
	{
		return 1.f;
	}

	if (const UPaperFlipbookComponent* SpriteComp = GetSprite())
	{
		return SpriteComp->GetSpriteColor().A;
	}

	return 1.f;
}


void AEnemyBase::UpdateScaleByCloseness(float CurrentDist)
{
	if (InitialDistToEnd <= KINDA_SMALL_NUMBER) return;

	const float Closeness = 1.f - FMath::Clamp(CurrentDist / InitialDistToEnd, 0.f, 1.f);
	const float S = FMath::Lerp(StartScale, 1.0f, Closeness) * CustomScale;
	SetActorScale3D(FVector(S));
}

void AEnemyBase::ApplySwayToSprite()
{
	if (GetSprite())
	{
		GetSprite()->SetRelativeLocation(BaseSpriteRelativeLocation + CurrentOffset);
	}
}

void AEnemyBase::PickNewTarget()
{
	const float A = SwayAmplitude;

	// 평면 선택: Paper2D라면 보통 X(가로)-Z(세로)를 많이 씀. (Y는 깊이)
	float RandX = FMath::RandRange(-A, A);
	float RandY = FMath::RandRange(-A, A);
	float RandZ = FMath::RandRange(-A, A * 0.5f);

	TargetOffset = bUseYZPlane
		? FVector(RandX, RandY, 0.f)  // XY로만 흔들기
		: FVector(0, RandY, RandZ); // YZ로만 흔들기(기본)

	// 다음 목표까지의 대기 시간(자연스러운 숨 고르기)
	TimeToNextTarget = FMath::RandRange(1.2f, 2.8f);
}

void AEnemyBase::StartSway()
{
	bIsSwaying = true;
	PickNewTarget();
}

void AEnemyBase::StopSway()
{
	bIsSwaying = false;

	// 스프라이트를 원래 자리로 복귀
	CurrentOffset = FVector::ZeroVector;
	TargetOffset = FVector::ZeroVector;
	ApplySwayToSprite();
}

float AEnemyBase::TakeDamage(float DamageAmount, const FDamageEvent& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	if (bHitFlashActive || bHitShakeActive) return 0.0f;

	const float SuperDealt = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	// 기존 히트 플래시
	StartHitFlash();

	// 스프라이트 흔들림 추가
	StartHitShake();

	// 체력 처리
	CurrentHealth = FMath::Clamp(CurrentHealth - 1, 0, MaxHealth);
	if (CurrentHealth <= 0) { StartDie(); }
	OnHealthChanged.Broadcast(MaxHealth, CurrentHealth);

	ScoreWidgetComponent->ShowFloatingImage(ScoreTexture, FLinearColor::White);

	ABattleGameState* BattleGameState = GetWorld()->GetGameState<ABattleGameState>();
	if (BattleGameState)
	{
		BattleGameState->AddScore(Score);
	}

	return FMath::Max(SuperDealt, 1.f);
}


void AEnemyBase::StartDie()
{
	;
}

void AEnemyBase::EndDie()
{
	HitBox->SetCollisionProfileName(TEXT("NoCollision"));

	// 이펙트 재생
	if (DeathEffect)
	{
		const FVector  Loc = GetActorLocation();
		const FRotator Rot = GetActorRotation();
		const FVector  Scale(1.f);

		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), DeathEffect, Loc, Rot, Scale, true);
	}
}

AActor* AEnemyBase::GetTarget() const
{
	return UGameplayStatics::GetPlayerPawn(this, 0);
}

void AEnemyBase::DoDamage()
{
	PlayAttackSound();
	DoDamageToTarget(GetTarget());
}

void AEnemyBase::DoDamageToTarget(AActor* TargetActor)
{
	AViewPlayer* ViewPlayer = Cast<AViewPlayer>(TargetActor);

	if (ViewPlayer)
	{
		ViewPlayer->GetAttacked(AttackPower);
	}
}

void AEnemyBase::SetBrightness(float Brightness)
{
	if (SpriteMID)
	{
		// 머티리얼 파라미터에 직접 Brightness 값 전달
		SpriteMID->SetScalarParameterValue(TEXT("BrightnessParam"), Brightness);
	}
}

void AEnemyBase::UpdateBrightness()
{
	if (!GetTarget()) return;

	const FVector PlayerPos = GetTarget()->GetActorLocation();

	// 0.0 ~ 1.0 사이 기본 비율
	float Ratio = 1.0f - (FMath::Abs(GetActorLocation().X - PlayerPos.X) / FMath::Max(FMath::Abs(StartPos.X - PlayerPos.X), KINDA_SMALL_NUMBER));
	Ratio = FMath::Clamp(Ratio, 0.0f, 1.0f);

	// 감마 보정
	float Brightness = FMath::Pow(Ratio, 1.5f);

	Brightness = FMath::Lerp(StartBrightness, 1.0f, Brightness);

	// 추가 배율
	Brightness *= BrightnessMul;

	// 최소값 보정
	Brightness = FMath::Max(Brightness, 0.1f);

	SetBrightness(Brightness);
}


void AEnemyBase::UpdateOpacity(float DeltaSeconds, float OpacityInterpRate)
{
	float NewCurrentOpacity = FMath::FInterpTo(GetSprite()->GetSpriteColor().A, TargetOpacity, DeltaSeconds, OpacityInterpRate);
	NewCurrentOpacity = FMath::Clamp(NewCurrentOpacity, 0.f, 1.f);
	SetOpacity(NewCurrentOpacity);
}

bool AEnemyBase::IsTargetInAttackRange() const
{
	const FVector A = GetActorLocation();
	const FVector B = GetTarget()->GetActorLocation();

	float Dist2D = FVector::Dist2D(A, B);
	return (Dist2D <= AttackRange);
}

void AEnemyBase::StartHitFlash()
{
	if (GetSprite())
	{
		// 처음 켤 때 원래 색 저장
		if (!bHitFlashActive)
		{
			SavedSpriteColor = GetSprite()->GetSpriteColor();
		}
		bHitFlashActive = true;

		// 빨갛게
		GetSprite()->SetSpriteColor(HitFlashColor);

		// 0.5초 타이머 재시작(연속 피격에도 0.5초 유지)
		GetWorldTimerManager().ClearTimer(HitFlashTimerHandle);
		GetWorldTimerManager().SetTimer(
			HitFlashTimerHandle, this, &AEnemyBase::EndHitFlash, HitFlashDuration, false
		);
	}
}

void AEnemyBase::EndHitFlash()
{
	bHitFlashActive = false;
	if (GetSprite())
	{
		GetSprite()->SetSpriteColor(SavedSpriteColor);
	}
}

void AEnemyBase::StartHitShake()
{
	if (GetSprite())
	{
		if (!bHitShakeActive)
		{
			// 처음 시작할 때 기준 상대 트랜스폼 저장
			SavedSpriteRelLoc = GetSprite()->GetRelativeLocation();
			SavedSpriteRelRot = GetSprite()->GetRelativeRotation();
		}

		bHitShakeActive = true;
		HitShakeElapsed = 0.f;

		// 연속 피격 시에도 종료시점 연장
		GetWorldTimerManager().ClearTimer(HitShakeTimerHandle);
		GetWorldTimerManager().SetTimer(
			HitShakeTimerHandle,
			this, &AEnemyBase::EndHitShake,
			HitShakeDuration, false
		);
	}
}

void AEnemyBase::EndHitShake()
{
	bHitShakeActive = false;

	if (GetSprite())
	{
		// 원래 위치/회전 복구
		GetSprite()->SetRelativeLocation(SavedSpriteRelLoc);
		GetSprite()->SetRelativeRotation(SavedSpriteRelRot);
	}
}

void AEnemyBase::PlayRandomSoundOverlap(const TArray<USoundBase*>& InArray, float Pitch)
{
	if (InArray.IsEmpty()) return;

	USoundBase* Sound = InArray[FMath::RandRange(0, InArray.Num() - 1)];
	if (!Sound) return;

	// Root에 붙여서 자동 파괴(사운드 끝나면 사라짐)
	UGameplayStatics::SpawnSoundAttached(
		Sound,
		GetRootComponent(),
		NAME_None,
		FVector::ZeroVector,
		EAttachLocation::KeepRelativeOffset,
		/*bStopWhenAttachedToDestroyed*/ true,
		/*VolumeMultiplier*/ 1.0f,
		/*PitchMultiplier*/ Pitch,
		/*StartTime*/ 0.f
		// Attenuation/Concurrency 필요하면 뒤에 파라미터로 넘기기
	);
}

void AEnemyBase::PlayAttackSound()
{
	PlayRandomSoundOverlap(AttackSounds);
}

void AEnemyBase::PlayDieSound()
{
	PlayRandomSoundOverlap(DieSounds);
}

void AEnemyBase::StartAttack()
{
	if (bAttackHitFired.Num() != AttackHitThresholds.Num())
	{
		bAttackHitFired.SetNum(AttackHitThresholds.Num());
		
	}
	for (bool& b : bAttackHitFired) b = false;
	bIsAttacking = true;
}

void AEnemyBase::ProcessAttackMidHits(class UPaperFlipbook* Flipbook)
{
	if (!GetSprite() || !Flipbook) return;

	// Flipbook 길이(PlayRate 반영된 컴포넌트 길이를 쓰면 더 안전)
	const float Len = GetSprite()->GetFlipbookLength(); // 컴포넌트 API (PlayRate 반영)
	if (Len <= KINDA_SMALL_NUMBER) return;

	const float Pos = GetSprite()->GetPlaybackPosition(); // 0~Len
	const float T = FMath::Clamp(Pos / Len, 0.f, 1.f);    // 0~1 정규화

	for (int32 i = 0; i < AttackHitThresholds.Num(); ++i)
	{
		if (!bAttackHitFired[i] && T >= AttackHitThresholds[i])
		{
			bAttackHitFired[i] = true;

			DoDamage();
		}
	}
}

void AEnemyBase::EndAttack()
{
	ResetAttackHitFlags();
	bIsAttacking = false;
}

void AEnemyBase::ResetAttackHitFlags()
{
	if (bAttackHitFired.Num() > 0)
	{
		for (bool& b : bAttackHitFired) b = false;
	}
}