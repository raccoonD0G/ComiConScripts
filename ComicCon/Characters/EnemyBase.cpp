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
		InitialDistToEnd = FMath::Max(InitialDistToEnd, 1.f); // 0 ����
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
		// �̹� ����� MID�� ������ ����, ������ ���⼭�� 1ȸ ����
		UMaterialInterface* Current = GetSprite()->GetMaterial(0);
		SpriteMID = Cast<UMaterialInstanceDynamic>(Current);
		if (!SpriteMID)
		{
			// ����: ������Ʈ�� ���۸� ����� DMI ����/������ �� ����
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
			// ���൵: 0.0 (����) ~ 1.0 (��)
			const float Progress = FMath::Clamp((MaxSec - RemSec) / MaxSec, 0.f, 1.f);

			// 0.5 ~ 1.5 ���� ���� ����
			float Scale = (Progress < 0.5f)
				? FMath::Lerp(0.5f, 1.5f, Progress / 0.5f)  // 0~0.5 ���̿��� 0.5~1.5
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
		// ��ġ ������ ����(��������Ʈ �����ǥ��)
		CurrentOffset = FMath::VInterpTo(CurrentOffset, TargetOffset, DeltaSeconds, LerpSpeed);
		ApplySwayToSprite();

		// Ÿ�� �缳�� Ÿ�̹�
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

			// XY�� ���� �ٸ� ����/���ļ��� ��¦ ����
			const float ox = FMath::Sin(w * HitShakeElapsed * 1.0f + 0.7f) * (HitShakeLocAmpUU * 0.5f);
			const float oy = FMath::Sin(w * HitShakeElapsed * 1.7f + 1.1f) * (HitShakeLocAmpUU);

			// 2D �����̸� Roll(Z��)�� ��¦ ��￩�ָ� �������� ������ ����
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

	// ������ ��� ��������Ʈ ���� ��ҿ� �������� �����մϴ�.
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

	// ��� ����: Paper2D��� ���� X(����)-Z(����)�� ���� ��. (Y�� ����)
	float RandX = FMath::RandRange(-A, A);
	float RandY = FMath::RandRange(-A, A);
	float RandZ = FMath::RandRange(-A, A * 0.5f);

	TargetOffset = bUseYZPlane
		? FVector(RandX, RandY, 0.f)  // XY�θ� ����
		: FVector(0, RandY, RandZ); // YZ�θ� ����(�⺻)

	// ���� ��ǥ������ ��� �ð�(�ڿ������� �� ����)
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

	// ��������Ʈ�� ���� �ڸ��� ����
	CurrentOffset = FVector::ZeroVector;
	TargetOffset = FVector::ZeroVector;
	ApplySwayToSprite();
}

float AEnemyBase::TakeDamage(float DamageAmount, const FDamageEvent& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	if (bHitFlashActive || bHitShakeActive) return 0.0f;

	const float SuperDealt = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	// ���� ��Ʈ �÷���
	StartHitFlash();

	// ��������Ʈ ��鸲 �߰�
	StartHitShake();

	// ü�� ó��
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

	// ����Ʈ ���
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
		// ��Ƽ���� �Ķ���Ϳ� ���� Brightness �� ����
		SpriteMID->SetScalarParameterValue(TEXT("BrightnessParam"), Brightness);
	}
}

void AEnemyBase::UpdateBrightness()
{
	if (!GetTarget()) return;

	const FVector PlayerPos = GetTarget()->GetActorLocation();

	// 0.0 ~ 1.0 ���� �⺻ ����
	float Ratio = 1.0f - (FMath::Abs(GetActorLocation().X - PlayerPos.X) / FMath::Max(FMath::Abs(StartPos.X - PlayerPos.X), KINDA_SMALL_NUMBER));
	Ratio = FMath::Clamp(Ratio, 0.0f, 1.0f);

	// ���� ����
	float Brightness = FMath::Pow(Ratio, 1.5f);

	Brightness = FMath::Lerp(StartBrightness, 1.0f, Brightness);

	// �߰� ����
	Brightness *= BrightnessMul;

	// �ּҰ� ����
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
		// ó�� �� �� ���� �� ����
		if (!bHitFlashActive)
		{
			SavedSpriteColor = GetSprite()->GetSpriteColor();
		}
		bHitFlashActive = true;

		// ������
		GetSprite()->SetSpriteColor(HitFlashColor);

		// 0.5�� Ÿ�̸� �����(���� �ǰݿ��� 0.5�� ����)
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
			// ó�� ������ �� ���� ��� Ʈ������ ����
			SavedSpriteRelLoc = GetSprite()->GetRelativeLocation();
			SavedSpriteRelRot = GetSprite()->GetRelativeRotation();
		}

		bHitShakeActive = true;
		HitShakeElapsed = 0.f;

		// ���� �ǰ� �ÿ��� ������� ����
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
		// ���� ��ġ/ȸ�� ����
		GetSprite()->SetRelativeLocation(SavedSpriteRelLoc);
		GetSprite()->SetRelativeRotation(SavedSpriteRelRot);
	}
}

void AEnemyBase::PlayRandomSoundOverlap(const TArray<USoundBase*>& InArray, float Pitch)
{
	if (InArray.IsEmpty()) return;

	USoundBase* Sound = InArray[FMath::RandRange(0, InArray.Num() - 1)];
	if (!Sound) return;

	// Root�� �ٿ��� �ڵ� �ı�(���� ������ �����)
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
		// Attenuation/Concurrency �ʿ��ϸ� �ڿ� �Ķ���ͷ� �ѱ��
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

	// Flipbook ����(PlayRate �ݿ��� ������Ʈ ���̸� ���� �� ����)
	const float Len = GetSprite()->GetFlipbookLength(); // ������Ʈ API (PlayRate �ݿ�)
	if (Len <= KINDA_SMALL_NUMBER) return;

	const float Pos = GetSprite()->GetPlaybackPosition(); // 0~Len
	const float T = FMath::Clamp(Pos / Len, 0.f, 1.f);    // 0~1 ����ȭ

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