// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Dokkaebi.h"
#include "PaperFlipbookComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "TimerManager.h"
#include "Components/BoxComponent.h"

ADokkaebi::ADokkaebi()
{
    PrimaryActorTick.bCanEverTick = true;

    // 낙하/점프 기본값이 과하면 여기서 조정 가능
    if (UCharacterMovementComponent* Move = GetCharacterMovement())
    {
        Move->GravityScale = 1.0f;
        Move->JumpZVelocity = 420.f;    // Jump()가 사용하는 수직 속도
        Move->AirControl = 0.15f;       // 공중 제어
        Move->bOrientRotationToMovement = true;
        Move->RotationRate = FRotator(0, 540.f, 0);
        Move->SetMovementMode(MOVE_Walking);

    }

    AttackHitThresholds = { 0.16 };
}

void ADokkaebi::PostInitializeComponents()
{
    Super::PostInitializeComponents();

    SetCurrentState(EDokkaebiState::Idle);
}

void ADokkaebi::BeginPlay()
{
    Super::BeginPlay();
    PlaySpawnSound();
}

void ADokkaebi::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    switch (CurrentState)
    {
    case EDokkaebiState::Idle:
        OnIdle();
        break;
    case EDokkaebiState::Jump:
        OnJump();
        break;
    case EDokkaebiState::ReadyJump:
        OnReadyJump();
        break;
    case EDokkaebiState::Land:
        OnLand();
        break;
    case EDokkaebiState::Attack:
        OnAttack();
        break;
    case EDokkaebiState::Die:
        OnDie();
        break;
    default:
        break;
    }
}

void ADokkaebi::SetCurrentState(EDokkaebiState NewCurrentState)
{
    // 상태 진입 시 Flipbook 교체
    switch (NewCurrentState)
    {
    case EDokkaebiState::Idle:
        if (IdleFlipbook)
        {
            GetSprite()->SetFlipbook(IdleFlipbook);
            GetSprite()->OnFinishedPlaying.Clear();   // Idle은 루프이므로 델리게이트X
            GetSprite()->SetLooping(true);
            GetSprite()->PlayFromStart();
        }

        ScheduleNextJump();
        break;

    case EDokkaebiState::ReadyJump:
        if (ReadyJumpFlipbook)
        {
            GetSprite()->SetFlipbook(ReadyJumpFlipbook);
            GetSprite()->OnFinishedPlaying.Clear();
            GetSprite()->SetLooping(false);
            GetSprite()->PlayFromStart();

            GetSprite()->OnFinishedPlaying.AddDynamic(this, &ADokkaebi::EndReadyJump);
        }
        break;
    case EDokkaebiState::Jump:
        GetWorldTimerManager().SetTimer(JumpHandle, this, &ADokkaebi::ForwardJump, 0.6f, false);
        if (JumpFlipbook)
        {
            GetSprite()->SetFlipbook(JumpFlipbook);
            GetSprite()->OnFinishedPlaying.Clear();
            GetSprite()->SetLooping(false);
            GetSprite()->PlayFromStart();
        }
        break;

    case EDokkaebiState::Land:
        GetWorldTimerManager().SetTimer(LandHandle, this, &ADokkaebi::PlayLandSound, 0.23, false);
        if (LandFlipbook)
        {
            GetSprite()->SetFlipbook(LandFlipbook);
            GetSprite()->OnFinishedPlaying.Clear();
            GetSprite()->SetLooping(false);
            GetSprite()->PlayFromStart();

            GetSprite()->OnFinishedPlaying.AddDynamic(this, &ADokkaebi::EndLand);
        }
        break;

    case EDokkaebiState::Attack:
        StartAttack();
        HitBox->SetCollisionProfileName(TEXT("NoCollision"));
        if (AttackFlipbook)
        {
            GetSprite()->SetFlipbook(AttackFlipbook);
            GetSprite()->OnFinishedPlaying.Clear();
            GetSprite()->SetLooping(false);
            GetSprite()->PlayFromStart();
            GetSprite()->OnFinishedPlaying.AddDynamic(this, &ADokkaebi::EndAttack);
        }
        // 공격 중에는 점프 타이머를 멈춤(유지하고 싶으면 이 줄 제거)
        GetWorldTimerManager().ClearTimer(IdleJumpTimerHandle);
        break;

    case EDokkaebiState::Die:
        PlayDieSound();
        GetCharacterMovement()->StopMovementImmediately();
        GetWorldTimerManager().ClearTimer(JumpHandle);
        GetWorldTimerManager().ClearTimer(LandHandle);
        HitBox->SetCollisionProfileName(TEXT("NoCollision"));

        if (DieFlipbook)
        {
            GetSprite()->SetFlipbook(DieFlipbook);
            GetSprite()->OnFinishedPlaying.Clear();
            GetSprite()->SetLooping(false);
            GetSprite()->PlayFromStart();
            GetSprite()->OnFinishedPlaying.AddDynamic(this, &ADokkaebi::EndDie);
        }
        break;

    default:
        break;
    }

    CurrentState = NewCurrentState;
}


void ADokkaebi::OnIdle()
{
    if (IsTargetInAttackRange())
    {
        if (CurrentState != EDokkaebiState::Attack)
        {
            SetCurrentState(EDokkaebiState::Attack);
            GetWorldTimerManager().ClearTimer(IdleJumpTimerHandle);
        }
    }
}

void ADokkaebi::OnJump()
{
}

void ADokkaebi::OnReadyJump()
{
}

void ADokkaebi::OnLand()
{
}

void ADokkaebi::OnAttack()
{
}

void ADokkaebi::OnDie()
{
}

void ADokkaebi::ScheduleNextJump()
{
    const float MinI = FMath::Max(0.1f, IdleJumpIntervalRange.X);
    const float MaxI = FMath::Max(MinI, IdleJumpIntervalRange.Y);
    const float Interval = FMath::FRandRange(MinI, MaxI);

    GetWorldTimerManager().ClearTimer(IdleJumpTimerHandle);
    GetWorldTimerManager().SetTimer(IdleJumpTimerHandle, this, &ADokkaebi::TryStartJump, Interval, false);
}

void ADokkaebi::TryStartJump()
{
    if (CurrentState != EDokkaebiState::Idle) return;

    SetCurrentState(EDokkaebiState::ReadyJump);  
}

void ADokkaebi::ForwardJump()
{
    const FVector Forward2D = GetActorForwardVector().GetSafeNormal2D();
    const FVector XYOnly = FVector(-Forward2D.X * JumpForwardPower, Forward2D.Y * JumpForwardPower, JumpUpPower);

    LaunchCharacter(XYOnly, true, true);
}

void ADokkaebi::Landed(const FHitResult& Hit)
{
    Super::Landed(Hit);

    // 점프 상태였다면 착지 시 Idle 복귀 및 다시 점프 예약
    if (CurrentState == EDokkaebiState::Jump)
    {
        SetCurrentState(EDokkaebiState::Land);
    }
}

void ADokkaebi::EndReadyJump()
{
    if (GetSprite())
    {
        GetSprite()->OnFinishedPlaying.Clear();
    }
    SetCurrentState(EDokkaebiState::Jump);
}

void ADokkaebi::EndLand()
{
    if (GetSprite())
    {
        GetSprite()->OnFinishedPlaying.Clear();
    }
    SetCurrentState(EDokkaebiState::Idle);
}

void ADokkaebi::StartDie()
{
    Super::StartDie();
    SetCurrentState(EDokkaebiState::Die);
}

bool ADokkaebi::IsTargetInAttackRange() const
{
    const float A = GetActorLocation().X;
    const float B = GetTarget()->GetActorLocation().X;

    float Dist2D = FMath::Abs(A - B);
    return (Dist2D <= AttackRange);
}

void ADokkaebi::EndAttack()
{
    Super::EndAttack();
    DoDamage();
    Destroy();
}

void ADokkaebi::EndDie()
{
    Super::EndDie();
    Destroy();
}

void ADokkaebi::PlaySpawnSound()
{
    PlayRandomSoundOverlap(SpawnSounds);
}

void ADokkaebi::PlayLandSound()
{
    PlayRandomSoundOverlap(LandSounds);
}
