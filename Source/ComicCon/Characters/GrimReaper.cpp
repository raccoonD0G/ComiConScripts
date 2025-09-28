// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/GrimReaper.h"
#include "PaperFlipbook.h"
#include "PaperFlipbookComponent.h"
#include "NiagaraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

AGrimReaper::AGrimReaper()
{
	AttackHitThresholds = { 0.34f, 0.46f, 0.5, 0.59f };
}

void AGrimReaper::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	SetCurrentState(EGrimReaperState::Spawn);
}

void AGrimReaper::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	switch (CurrentState)
	{
	case EGrimReaperState::Spawn:
		OnSpawn(DeltaSeconds);
		break;
	case EGrimReaperState::Idle:
		OnIdle(DeltaSeconds);
		break;
	case EGrimReaperState::Attack:
		OnAttack(DeltaSeconds);
		break;
	case EGrimReaperState::Die:
		OnDie(DeltaSeconds);
		break;
	default:
		break;
	}
}

void AGrimReaper::SetCurrentState(EGrimReaperState NewState)
{
	switch (NewState)
	{
	case EGrimReaperState::Spawn:
        SetOpacity(0.0f);
        TargetOpacity = 1.0f;
		if (SpawnFlipbook)
		{
			GetSprite()->SetFlipbook(SpawnFlipbook);
			GetSprite()->OnFinishedPlaying.Clear();
			GetSprite()->SetLooping(false);
			GetSprite()->PlayFromStart();
			GetSprite()->OnFinishedPlaying.AddDynamic(this, &AGrimReaper::EndSpawn);
		}
		break;

	case EGrimReaperState::Idle:
		ScheduleIdleToAttack();
		if (IdleFlipbook)
		{
			GetSprite()->SetFlipbook(IdleFlipbook);
			GetSprite()->OnFinishedPlaying.Clear();
			GetSprite()->SetLooping(true);
			GetSprite()->PlayFromStart();
		}
		break;

	case EGrimReaperState::Attack:
		StartAttack();
		GetWorldTimerManager().SetTimer(AttackStartHandle, this, &AGrimReaper::PlayAttackStartSound, 1.6, false);
		if (AttackFlipbook)
		{
			GetSprite()->SetFlipbook(AttackFlipbook);
			GetSprite()->OnFinishedPlaying.Clear();
			GetSprite()->SetLooping(false);
			GetSprite()->PlayFromStart();
			GetSprite()->OnFinishedPlaying.AddDynamic(this, &AGrimReaper::EndAttack);
		}
		break;

	case EGrimReaperState::Die:
		if (CurrentState == EGrimReaperState::Attack)
		{
			bIsAttacking = false;
		}
		PlayDieSound();
		GetCharacterMovement()->StopMovementImmediately();
        HitBox->SetCollisionProfileName(TEXT("NoCollision"));
        TargetOpacity = 0.0f;
		if (DieFlipbook)
		{
			GetSprite()->SetFlipbook(DieFlipbook);
			GetSprite()->OnFinishedPlaying.Clear();
			GetSprite()->SetLooping(false);
			GetSprite()->PlayFromStart();
			GetSprite()->OnFinishedPlaying.AddDynamic(this, &AGrimReaper::EndDie);
		}
		break;

	default:
		break;
	}

	CurrentState = NewState;
}

void AGrimReaper::OnSpawn(float DeltaSeconds)
{
    UpdateOpacity(DeltaSeconds, 10.0f);
}

void AGrimReaper::OnIdle(float DeltaSeconds)
{
	// TODO: 대기 로직(순찰, 시선처리 등)
}

void AGrimReaper::OnAttack(float DeltaSeconds)
{
	;
}

void AGrimReaper::OnDie(float DeltaSeconds)
{
    UpdateOpacity(DeltaSeconds, 0.1f);
}

void AGrimReaper::EndSpawn()
{
	SetCurrentState(EGrimReaperState::Idle);
}

void AGrimReaper::EndAttack()
{
	Super::EndAttack();
	SetCurrentState(EGrimReaperState::Idle);
}

void AGrimReaper::EndDie()
{
	Super::EndDie();
	Destroy();
}

void AGrimReaper::ScheduleIdleToAttack()
{
	const float MinD = FMath::Max(0.01f, IdleToAttackDelayRange.X);
	const float MaxD = FMath::Max(MinD, IdleToAttackDelayRange.Y);
	const float Delay = FMath::FRandRange(MinD, MaxD);

	GetWorldTimerManager().SetTimer(
		IdleToAttackTimerHandle,
		this, &AGrimReaper::OnIdleToAttackTimerExpired,
		Delay, false
	);
}

void AGrimReaper::OnIdleToAttackTimerExpired()
{
	// 여전히 Idle이면 Attack으로 전이
	if (CurrentState == EGrimReaperState::Idle)
	{
		SetCurrentState(EGrimReaperState::Attack);
	}
}

void AGrimReaper::PlayAttackStartSound()
{
	PlayRandomSoundOverlap(StartAttackSounds);
}

void AGrimReaper::PlaySpawnSound()
{
	PlayRandomSoundOverlap(SpawnSounds);
}

void AGrimReaper::StartDie()
{
    Super::StartDie();
    SetCurrentState(EGrimReaperState::Die);
}
