// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/Succubus.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "PaperFlipbookComponent.h"
#include "Components/CapsuleComponent.h"
#include "Utilities/MathLibraries.h"
#include "Pawns/ViewPlayer.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/BoxComponent.h"
#include "Subsystems/AttackSchedulerSubsystem.h"

ASuccubus::ASuccubus()
{
    AttackHitThresholds = { 0.2f };

    if (UCharacterMovementComponent* Move = GetCharacterMovement())
    {
        Move->GravityScale = 0.f;
        Move->SetMovementMode(MOVE_Flying);
        Move->MaxFlySpeed = MoveSpeed;
    }
}

void ASuccubus::Init(const TArray<FVector>& InPoints)
{
    ControlPoints = InPoints;
    BaseControlPoints = InPoints;

    if (GetTarget())
    {
        InitialDistToEnd = FMath::Abs(ControlPoints[0].X - GetTarget()->GetActorLocation().X);
        InitialDistToEnd = FMath::Max(InitialDistToEnd, 1.f); // 0 방지
    }

    if (ControlPoints.Num() <= 2) return;

    //const int32 DropCount = FMath::RandRange(0, ControlPoints.Num() - 10);
    //ControlPoints.RemoveAt(0, DropCount, false);

    SetActorLocation(ControlPoints[0]);

    // 플레이어 참조/초기 위치
    PlayerRef = UGameplayStatics::GetPlayerPawn(this, 0);
    if (PlayerRef.IsValid())
    {
        PlayerStartLoc = PlayerRef->GetActorLocation();
    }

    // 최종점 캐싱
    CachedEndBase = ControlPoints.Last();
    LastAppliedDisplacement = FVector::ZeroVector;

    // 진행도/LUT 초기화
    Traveled = 0.f;
    CurrentSpeed = 0.f;
    ArcLUT.Reset();
    BuildArcLUT(); // 초기 곡선

    SetCurrentState(ESuccubusState::Stop);
}

void ASuccubus::BeginPlay()
{
    Super::BeginPlay();

    if (UCharacterMovementComponent* Move = GetCharacterMovement())
    {
        Move->GravityScale = 0.f;
        Move->bOrientRotationToMovement = false;
    }
    bUseControllerRotationYaw = false;
}

void ASuccubus::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    switch (CurrentState)
    {
    case ESuccubusState::Move:
        OnMove(DeltaSeconds);
        break;
    case ESuccubusState::Attack:
        OnAttack(DeltaSeconds);
        break;
    case ESuccubusState::Stop:
        OnStop(DeltaSeconds);
        break;
    case ESuccubusState::Die:
        OnDie(DeltaSeconds);
        break;
    default:
        break;
    }
}

bool ASuccubus::IsTargetInAttackRange() const
{
    if (GetTarget())
    {
        return FMath::Abs(GetActorLocation().X - GetTarget()->GetActorLocation().X) < AttackRange;
    }
    return false;
}

void ASuccubus::SetCurrentState(ESuccubusState NewState)
{

    switch (NewState)
    {
    case ESuccubusState::Move:

        if (GetCharacterMovement())
        {
            // 입력 가속을 끊고 브레이킹만으로 감속
            GetCharacterMovement()->MaxAcceleration = 2048.f;           // 프로젝트 기본값에 맞게
            GetCharacterMovement()->BrakingDecelerationFlying = 0.f;    // Move 중엔 브레이킹 약하게/0
            GetCharacterMovement()->bUseSeparateBrakingFriction = false;
            GetCharacterMovement()->BrakingFriction = 0.f;
        }

        ScheduleNextStop();
        HitBox->SetCollisionProfileName(TEXT("NoCollision"));
        TargetOpacity = MoveOpacity;

        if (MoveFlipbook && !GetSprite()->IsPlaying())
        {
            GetSprite()->SetFlipbook(MoveFlipbook);
            GetSprite()->SetLooping(true);
            GetSprite()->PlayFromStart();
        }
        break;

    case ESuccubusState::Stop:
        PlayStopSound();

        if (GetCharacterMovement())
        {
            // 입력 가속을 끊고 브레이킹만으로 감속
            GetCharacterMovement()->MaxAcceleration = 0.f;

            GetCharacterMovement()->BrakingDecelerationFlying = 3000.f; // 1500~4000 사이로 취향 조절
            GetCharacterMovement()->bUseSeparateBrakingFriction = true;
            GetCharacterMovement()->BrakingFriction = 2.0f;             // 마찰
            GetCharacterMovement()->BrakingFrictionFactor = 1.0f;
        }

        ScheduleNextMoveOrAttack();
        HitBox->SetCollisionProfileName(TEXT("GetDamageBox"));
        TargetOpacity = StopOpacity;

        if (StopFlipbook && !GetSprite()->IsPlaying())
        {
            GetSprite()->SetFlipbook(StopFlipbook);
            GetSprite()->SetLooping(true);
            GetSprite()->PlayFromStart();
        }

        break;

    case ESuccubusState::Attack:

        StartAttack();

        GetWorldTimerManager().ClearTimer(MoveTimerHandle);
        GetWorldTimerManager().ClearTimer(StopTimerHandle);

        HitBox->SetCollisionProfileName(TEXT("NoCollision"));
        TargetOpacity = AttackOpacity;

        if (UCharacterMovementComponent* Move = GetCharacterMovement())
        {
            Move->StopMovementImmediately();
        }

        if (AttackFlipbook)
        {
            GetSprite()->OnFinishedPlaying.Clear();
            GetSprite()->SetFlipbook(AttackFlipbook);
            GetSprite()->SetLooping(false);
            GetSprite()->PlayFromStart();
            GetSprite()->OnFinishedPlaying.AddDynamic(this, &ASuccubus::EndAttack);
        }

        if (AViewPlayer* ViewPlayer = Cast<AViewPlayer>(GetTarget()))
        {
            if (USpringArmComponent* Arm = ViewPlayer->GetSpringArmComponent())
            {
                const FVector EndLoc = Arm->GetSocketLocation(USpringArmComponent::SocketName);

                const FVector TeleportLoc = EndLoc + FVector(100.f, 0.f, -250.f);

                SetActorLocation(TeleportLoc, false, nullptr, ETeleportType::TeleportPhysics);
            }
        }

        break;

    case ESuccubusState::Die:
        PlayDieSound();
        GetCharacterMovement()->StopMovementImmediately();

        GetWorldTimerManager().ClearTimer(MoveTimerHandle);
        GetWorldTimerManager().ClearTimer(StopTimerHandle);

        HitBox->SetCollisionProfileName(TEXT("NoCollision"));

        SetOpacity(1.0f);
        TargetOpacity = 0.0f;

        if (UCharacterMovementComponent* Move = GetCharacterMovement())
        {
            Move->StopMovementImmediately();
        }

        if (DieFlipbook)
        {
            GetSprite()->OnFinishedPlaying.Clear();
            GetSprite()->SetFlipbook(DieFlipbook);
            GetSprite()->SetLooping(false);
            GetSprite()->PlayFromStart();
            GetSprite()->OnFinishedPlaying.AddDynamic(this, &ASuccubus::EndDie);
        }
        break;
    }

    CurrentState = NewState;
}

void ASuccubus::OnMove(float DeltaSeconds)
{
    // 0) 공격 범위면 Stop
    if (IsTargetInAttackRange())
    {
        SetCurrentState(ESuccubusState::Stop);
        return;
    }

    // 1) 경로 갱신 & 준비
    const float OldTotalLen = TotalLen;
    UpdateDynamicEndIfNeeded();

    if (ArcLUT.Num() == 0)
    {
        BuildArcLUT();
        Traveled = 0.f;
    }
    else if (!FMath::IsNearlyEqual(OldTotalLen, TotalLen, 1e-3f))
    {
        // (선택) 경로 바뀌면 현재 위치로 재동기화 - 유지
        if (ArcLUT.Num() > 0)
        {
            const FVector X = GetActorLocation();
            float bestS = 0.f, bestD2 = TNumericLimits<float>::Max();
            for (int32 i = 0; i < ArcLUT.Num(); ++i)
            {
                const FVector Pi = UMathLibraries::BezierPoint(ControlPoints, ArcLUT[i].T);
                const float d2 = FVector::DistSquared(Pi, X);
                if (d2 < bestD2) { bestD2 = d2; bestS = ArcLUT[i].S; }
            }
            Traveled = FMath::Clamp(bestS, 0.f, TotalLen);
        }
    }

    if (TotalLen <= KINDA_SMALL_NUMBER)
    {
        OnMovingDone();
        return;
    }

    // 2) '등속' : 바로 MaxFlySpeed 사용 (보간 제거)
    const float V = (GetCharacterMovement() ? GetCharacterMovement()->MaxFlySpeed : MoveSpeed);
    const float StepDist = FMath::Clamp(V * DeltaSeconds, 0.f, TotalLen - Traveled);
    if (StepDist <= KINDA_SMALL_NUMBER)
    {
        OnMovingDone();
        return;
    }

    // 3) 끝점 근처 안전 종료
    constexpr float FinishEps = 1.0f;
    if (TotalLen - Traveled <= FinishEps)
    {
        const FVector EndPos = UMathLibraries::BezierPoint(ControlPoints, 1.f);
        if (UCharacterMovementComponent* Move = GetCharacterMovement())
        {
            Move->StopMovementImmediately();
            FHitResult Hit;
            const FVector Delta = EndPos - GetActorLocation();
            Move->SafeMoveUpdatedComponent(Delta, GetActorRotation(), /*bSweep=*/true, Hit);
            if (Hit.IsValidBlockingHit())
            {
                const FVector Remainder = Delta * (1.f - Hit.Time);
                const FVector SlideDelta = FVector::VectorPlaneProject(Remainder, Hit.Normal);
                if (!SlideDelta.IsNearlyZero())
                {
                    FHitResult Hit2;
                    Move->SafeMoveUpdatedComponent(SlideDelta, GetActorRotation(), true, Hit2);
                }
            }
        }
        else
        {
            SetActorLocation(EndPos, false, nullptr, ETeleportType::None);
        }

        Traveled = TotalLen;     // 진행도도 종점으로
        // CurrentSpeed = 0.f;        // 더 이상 사용 안 함 (보간 제거)
        UpdateOpacity(DeltaSeconds, 10.0f);
        OnMovingDone();
        return;
    }

    // 4) 목표 지점(호 길이 기반 등속)
    const float sNext = Traveled + StepDist;
    const float tNext = FindTForDistance(sNext);
    const FVector Pnext = UMathLibraries::BezierPoint(ControlPoints, tNext);

    // 5) 실제 이동 (충돌 스윕). '속도 스케일' 같은 건 제거!
    if (UCharacterMovementComponent* Move = GetCharacterMovement())
    {
        const FVector DesiredDelta = Pnext - GetActorLocation();

        // 코너/연속 충돌 완화: 2~3회 시도
        FVector Delta = DesiredDelta;
        for (int32 Iter = 0; Iter < 3 && !Delta.IsNearlyZero(1e-3f); ++Iter)
        {
            FHitResult Hit;
            Move->SafeMoveUpdatedComponent(Delta, GetActorRotation(), /*bSweep=*/true, Hit);

            if (!Hit.IsValidBlockingHit())
            {
                break;
            }

            if (Hit.bStartPenetrating)
            {
                const FVector Depush = Hit.Normal * (Hit.PenetrationDepth + 0.1f);
                FHitResult Tmp;
                Move->SafeMoveUpdatedComponent(Depush, GetActorRotation(), /*bSweep=*/false, Tmp);
                break;
            }

            const FVector Remainder = Delta * (1.f - Hit.Time);
            const FVector SlideDelta = FVector::VectorPlaneProject(Remainder, Hit.Normal);
            Delta = SlideDelta;
        }
    }
    else
    {
        SetActorLocation(Pnext, /*bSweep=*/false, nullptr, ETeleportType::None);
    }

    // 6) '진행도'는 의도대로 등속으로 전진 (ActualMoved 사용 X)
    Traveled = FMath::Clamp(sNext, 0.f, TotalLen);

    // (선택) 보이는 효과만 업데이트
    UpdateOpacity(DeltaSeconds, 10.0f);
}

void ASuccubus::OnStop(float DeltaSeconds)
{
    if (IsTargetInAttackRange())
    {
        TryScheduleAttack();
    }
    UpdateOpacity(DeltaSeconds, 10.0f);
}

void ASuccubus::OnAttack(float DeltaSeconds)
{
    UpdateOpacity(DeltaSeconds, 10.0f);
}

void ASuccubus::OnDie(float DeltaSeconds)
{
    UpdateOpacity(DeltaSeconds, 0.3f);
}

void ASuccubus::OnMovingDone()
{
    SetCurrentState(ESuccubusState::Stop);
}

void ASuccubus::BuildArcLUT()
{
    ArcLUT.Reset();
    TotalLen = 0.f;

    if (ControlPoints.Num() < 2)
        return;

    const float Step = FMath::Clamp(LUTStepT, 0.001f, 0.1f);
    FVector prev = UMathLibraries::BezierPoint(ControlPoints, 0.f);
    ArcLUT.Add({ 0.f, 0.f });

    float s = 0.f;
    for (float t = Step; t < 1.f; t += Step)
    {
        const FVector pos = UMathLibraries::BezierPoint(ControlPoints, t);
        s += FVector::Dist(prev, pos);
        ArcLUT.Add({ t, s });
        prev = pos;
    }

    // 마지막 샘플(정확히 t=1)
    {
        const FVector pos1 = UMathLibraries::BezierPoint(ControlPoints, 1.f);
        s += FVector::Dist(prev, pos1);
        ArcLUT.Add({ 1.f, s });
    }

    TotalLen = s;
}

float ASuccubus::FindTForDistance(float S) const
{
    if (ArcLUT.Num() == 0) return 0.f;
    if (S <= 0.f) return 0.f;
    if (S >= ArcLUT.Last().S) return 1.f;

    // 이분 탐색
    int32 L = 0, R = ArcLUT.Num() - 1;
    while (L + 1 < R)
    {
        const int32 M = (L + R) / 2;
        (ArcLUT[M].S < S) ? L = M : R = M;
    }

    // L..R 사이 선형보간으로 t 근사
    const float s0 = ArcLUT[L].S, s1 = ArcLUT[R].S;
    const float t0 = ArcLUT[L].T, t1 = ArcLUT[R].T;
    const float a = (s1 > s0) ? (S - s0) / (s1 - s0) : 0.f;
    return FMath::Lerp(t0, t1, a);
}

// (옵션) 경로가 바뀐 직후, 현재 액터 위치를 곡선 상 s로 재동기화하는 헬퍼
void ASuccubus::ResyncTraveledFromActorPos()
{
    if (ArcLUT.Num() == 0) return;

    const FVector X = GetActorLocation();
    float bestS = 0.f;
    float bestD2 = TNumericLimits<float>::Max();

    // 간단한 샘플 기반 투영 (ArcLUT의 t들을 사용)
    for (int32 i = 0; i < ArcLUT.Num(); ++i)
    {
        const float ti = ArcLUT[i].T;
        const FVector Pi = UMathLibraries::BezierPoint(ControlPoints, ti);
        const float d2 = FVector::DistSquared(Pi, X);
        if (d2 < bestD2) { bestD2 = d2; bestS = ArcLUT[i].S; }
    }
    Traveled = FMath::Clamp(bestS, 0.f, TotalLen);
}

float ASuccubus::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
    if (GetOpacity() < StopOpacity * 0.7)
    {
        return 0.0f;
    }
    return Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
}

void ASuccubus::StartDie()
{
    CancelAttackReservation();
    Super::StartDie();
    SetCurrentState(ESuccubusState::Die);
}

void ASuccubus::EndAttack()
{
    Super::EndAttack();
    DoDamageToTarget(GetTarget());

    if (bHasAttackReservation)
    {
        if (UAttackSchedulerSubsystem* S = GetWorld()->GetSubsystem<UAttackSchedulerSubsystem>())
        {
            S->NotifyAttackEnded(AttackTicketId, this);
        }
    }
    bHasAttackReservation = false;
    bAttackStartSignaled = false;   // ★ 초기화
    AttackTicketId = INDEX_NONE;

    ScheduleNextMoveOrAttack();

    Destroy(); // ← 한 번 물고 사라지는 디자인이면 유지, 아니면 제거
}

void ASuccubus::EndDie()
{
    if (bHasAttackReservation)
    {
        if (UAttackSchedulerSubsystem* S = GetWorld()->GetSubsystem<UAttackSchedulerSubsystem>())
        {
            S->NotifyAttackEnded(AttackTicketId, this);
        }
        bHasAttackReservation = false;
        AttackTicketId = INDEX_NONE;
    }
    Super::EndDie();
    Destroy();
}

void ASuccubus::ScheduleNextStop()
{
    const float MinT = FMath::Max(0.1f, MoveDurationRange.X);
    const float MaxT = FMath::Max(MinT, MoveDurationRange.Y);
    const float Interval = FMath::FRandRange(MinT, MaxT);

    GetWorldTimerManager().ClearTimer(MoveTimerHandle);
    GetWorldTimerManager().SetTimer(MoveTimerHandle, this, &ASuccubus::DoStop, Interval, false);
}

void ASuccubus::ScheduleNextMoveOrAttack()
{
    if (CurrentState == ESuccubusState::Stop)
    {
        if (IsTargetInAttackRange())
        {
            // 즉시 예약 시도 (성공하면 AttackStartTimer가 잡힘)
            TryScheduleAttack();

            // 만약 동시공격 제한으로 인해 시작시각이 멀리 밀리면,
            // Stop을 유지하면서도 Move로 가고 싶으면,
            // 여기서 일정 시간 후 DoMove()를 예약하는 보조 로직을 추가할 수 있음.
            return;
        }
    }

    const float MinT = FMath::Max(0.1f, StopDurationRange.X);
    const float MaxT = FMath::Max(MinT, StopDurationRange.Y);
    const float Interval = FMath::FRandRange(MinT, MaxT);

    GetWorldTimerManager().ClearTimer(StopTimerHandle);
    if (IsTargetInAttackRange())
    {
        GetWorldTimerManager().SetTimer(StopTimerHandle, this, &ASuccubus::DoAttack, Interval, false);
    }
    else
    {
        GetWorldTimerManager().SetTimer(StopTimerHandle, this, &ASuccubus::DoMove, Interval, false);
    }
    
}

void ASuccubus::DoStop()
{
    SetCurrentState(ESuccubusState::Stop);
}

void ASuccubus::DoMove()
{
    SetCurrentState(ESuccubusState::Move);
}

void ASuccubus::DoAttack()
{
    // 스케줄러가 Start 신호를 준 이후 + 여전히 Stop 상태 + 사거리여야 공격
    if (bHasAttackReservation && bAttackStartSignaled
        && CurrentState == ESuccubusState::Stop
        && IsTargetInAttackRange())
    {
        SetCurrentState(ESuccubusState::Attack);
        return;
    }

    // 아직 내 차례가 아니면(또는 범위/상태 불일치) 공격 안 함 → 기존 루프로 복귀
    ScheduleNextMoveOrAttack();
}


void ASuccubus::UpdateDynamicEndIfNeeded()
{
    if (!PlayerRef.IsValid() || BaseControlPoints.Num() < 2)
        return;

    const FVector currPlayerLoc = PlayerRef->GetActorLocation();
    const FVector disp = currPlayerLoc - PlayerStartLoc;

    // 변화가 작으면 스킵(성능)
    if (FVector::DistSquared(LastAppliedDisplacement, disp) < FMath::Square(EndUpdateThreshold))
        return;

    // 진행도 보존: 기존 t를 계산
    float oldT = 0.f;
    if (TotalLen > KINDA_SMALL_NUMBER)
    {
        oldT = FindTForDistance(Traveled);
    }

    // 새 최종점 = 초기 최종점 + 플레이어 변위
    TArray<FVector> NewCP = BaseControlPoints;
    NewCP.Last() = CachedEndBase + disp;

    // 실제 변경 없으면 스킵
    if (ControlPoints.Num() == NewCP.Num() && ControlPoints.Last().Equals(NewCP.Last(), 0.1f))
    {
        LastAppliedDisplacement = disp;
        return;
    }

    // 컨트롤 포인트 교체 및 LUT 재생성
    ControlPoints = MoveTemp(NewCP);
    BuildArcLUT();

    // 새 곡선에서 진행도 보존
    CachedTOnRebuild = FMath::Clamp(oldT, 0.f, 1.f);
    Traveled = CachedTOnRebuild * TotalLen;

    LastAppliedDisplacement = disp;
}

void ASuccubus::PlayStopSound()
{
    PlayRandomSoundOverlap(StopSounds);
}

void ASuccubus::TryScheduleAttack()
{
    if (CurrentState != ESuccubusState::Stop) return;
    if (bHasAttackReservation) return;

    if (UAttackSchedulerSubsystem* S = GetWorld()->GetSubsystem<UAttackSchedulerSubsystem>())
    {
        const float Now = GetWorld()->GetTimeSeconds();
        // 살짝 난수 지터를 넣어서 "예약 선호시각"이 모두 동일하지 않게
        const float Jitter = FMath::FRandRange(0.0f, 0.25f);
        const float PreferredStart = Now + Jitter;

        const FAttackReservation R = S->TryReserve(this, PreferredStart);
        if (R.bGranted)
        {
            bHasAttackReservation = true;
            AttackTicketId = R.TicketId;

            const float Delay = FMath::Max(0.f, R.StartTime - Now);
            GetWorldTimerManager().SetTimer(
                AttackStartTimer,
                this,
                &ASuccubus::OnReservedAttackTimeReached,
                Delay,
                false
            );
        }
    }
}

void ASuccubus::OnReservedAttackTimeReached()
{
    if (!bHasAttackReservation) return;

    // (선택) Stop 중 공격만 허용하고 싶다면 가드 추가
    if (CurrentState != ESuccubusState::Stop)
    {
        CancelAttackReservation();
        ScheduleNextMoveOrAttack();
        return;
    }

    if (!IsTargetInAttackRange())
    {
        CancelAttackReservation();
        ScheduleNextMoveOrAttack();
        return;
    }

    if (UAttackSchedulerSubsystem* S = GetWorld()->GetSubsystem<UAttackSchedulerSubsystem>())
    {
        S->NotifyAttackStarted(AttackTicketId, this);
    }

    bAttackStartSignaled = true;  // ★ 내 차례 도착!
    DoAttack();                   // 이제 Attack으로 진입 시도
}

void ASuccubus::CancelAttackReservation()
{
    if (!bHasAttackReservation) return;

    GetWorldTimerManager().ClearTimer(AttackStartTimer);

    if (UAttackSchedulerSubsystem* S = GetWorld()->GetSubsystem<UAttackSchedulerSubsystem>())
    {
        S->CancelReservation(AttackTicketId);
    }
    bHasAttackReservation = false;
    bAttackStartSignaled = false;  // ★ 초기화
    AttackTicketId = INDEX_NONE;
}