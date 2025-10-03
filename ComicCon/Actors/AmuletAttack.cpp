// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/AmuletAttack.h"
#include "Components/BoxComponent.h"
#include "DrawDebugHelpers.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Utilities/MathLibraries.h"
#include "Components/AudioComponent.h"

AAmuletAttack::AAmuletAttack()
{
    PrimaryActorTick.bCanEverTick = false;

    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

    PlaneBox = CreateDefaultSubobject<UBoxComponent>(TEXT("PlaneBox"));
    PlaneBox->SetupAttachment(RootComponent);
    PlaneBox->SetCollisionProfileName(TEXT("DoDamageBox"));

    PlaneBox->OnComponentBeginOverlap.AddDynamic(this, &AAmuletAttack::OnPlaneBoxBeginOverlap);

    AudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioComponent"));
    AudioComponent->SetupAttachment(RootComponent);
}

void AAmuletAttack::InitializeAttack(const FVector& InCenter, const FRotator& InRotation, float InLength, float InWidth)
{
    // 1) 기준 길이 잡기
    constexpr float L0 = 10.0f;

    // --- 0) 최소 길이 보정: InLength이 너무 짧으면 최소값으로 보정
    const float EffectiveLength = FMath::Max(InLength, MinAttackLength);

    // 2) 스케일 함수로 길이 스케일 계산 (보정된 길이로 계산하여
    //    짧은 스윙도 스케일 보장이 되도록 함)
    const float LengthScale = UMathLibraries::SuperlinearScale(EffectiveLength, L0, 1.3f, 0.7f);

    if (LengthScale > 5.0f)
    {
        if (LongSounds.Num() > 0)
        {
            AudioComponent->SetSound(LongSounds[FMath::RandRange(0, LongSounds.Num() - 1)]);
            AudioComponent->Play();
        }
    }
    else
    {
        if (ShortSounds.Num() > 0)
        {
            AudioComponent->SetSound(ShortSounds[FMath::RandRange(0, ShortSounds.Num() - 1)]);
            AudioComponent->Play();
        }
    }

    // 3) HalfExtent 계산 시 길이에 스케일 및 최소값 적용
    //    기존 로직은 (InLength * 0.5f) * LengthScale / 10.0f 인데,
    //    우리는 EffectiveLength(보정된 전체 길이)를 사용합니다.
    const float YHalf = FMath::Max(1.f, (EffectiveLength * 0.5f) * LengthScale / 10.0f);

    const FVector HalfExtent(
        PlaneHalfThickness, // X: 두께 Half
        YHalf,              // Y: 진행방향 HalfLength (스케일 + 최소값 적용됨)
        FMath::Max(1.f, InWidth * 0.5f) // Z: 폭 Half
    );

    FRotator CorrectedRotation = InRotation;
    CorrectedRotation.Add(90.f, 0.f, 90.f);
    SetActorLocation(InCenter);
    SetActorRotation(CorrectedRotation);

    // 박스 크기 세팅
    PlaneBox->SetBoxExtent(HalfExtent, false);
    PlaneBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    PlaneBox->SetGenerateOverlapEvents(true);

    // -X 면 위치 보정
    PlaneBox->SetRelativeLocation(FVector(+HalfExtent.X, 0, 0));
    PlaneBox->SetRelativeRotation(FRotator::ZeroRotator);

    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().SetTimerForNextTick(FTimerDelegate::CreateWeakLambda(this, [this]()
            {
                if (!IsValid(PlaneBox)) return;
                // 주의: collision profile 이름을 실제 프로젝트에 맞게 확인하세요.
                PlaneBox->SetCollisionProfileName(TEXT("NoCollision"));
            })
        );
    }

    // 디버그 박스
    if (bDoDebug)
    {
        const FQuat Q = CorrectedRotation.Quaternion();
        const FVector CenterFromStartFace = InCenter + Q.GetAxisX() * HalfExtent.X;
        DrawDebugBox(GetWorld(), CenterFromStartFace, HalfExtent, Q, FColor::Cyan, false, 1.0f, 0, 2.f);
    }

    // FX도 동일한 EffectiveLength과 LengthScale을 전달 (최소 FX 길이 보장)
    const float EffectiveFXLength = FMath::Max(EffectiveLength, MinFXLength);
    SpawnOrUpdateFX(InCenter, FRotator(90, 90, 0), EffectiveFXLength * LengthScale, InWidth);
}

void AAmuletAttack::SpawnOrUpdateFX(const FVector& Center, const FRotator& Rotation, float InLength, float InWidth)
{
    if (!SwingPlaneFX)
    {
        UE_LOG(LogTemp, Warning, TEXT("SwingPlaneFX is null in AAmuletAttack"));
        return;
    }

    // 기존 FX 있다면 제거
    if (SpawnedFX && !SpawnedFX->IsPendingKill())
    {
        SpawnedFX->DestroyComponent();
        SpawnedFX = nullptr;
    }

    // 스폰
    SpawnedFX = UNiagaraFunctionLibrary::SpawnSystemAttached(
        SwingPlaneFX,
        RootComponent,
        NAME_None,
        FVector::ZeroVector,
        Rotation,
        EAttachLocation::KeepRelativeOffset,
        true,
        true
    );

    if (!SpawnedFX)
    {
        UE_LOG(LogTemp, Warning, TEXT("Failed to spawn FX in AAmuletAttack"));
        return;
    }

    // InLength은 이미 InitializeAttack에서 보정 및 스케일 적용된 값(전체 길이 기준)
    // FX에서 사용하는 정규화 길이도 최소값 보장이 되도록 MinFXLength을 보장했다면
    // 여기서는 단순히 cm->m(또는 100으로 나누는 기존 방식을 따라) 변환.
    const float NormLength = FMath::Max(InLength, MinFXLength) / 100.0f;
    const float NormWidth = FMath::Max(InWidth, 1.0f) / 100.0f;

    // 기존에는 Vec2(1.0f, NormLength) 를 썼는데,
    // 필요한 경우 X/Y에 모두 스케일을 넣을 수 있으니 예시로 Y에 길이를 넣음.
    SpawnedFX->SetVariableVec2(ScaleMultiplierParamName, FVector2D(1.0f, NormLength));
}

void AAmuletAttack::OnPlaneBoxBeginOverlap(
    UPrimitiveComponent* OverlappedComponent,
    AActor* OtherActor,
    UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex,
    bool bFromSweep,
    const FHitResult& SweepResult)
{
    if (!OtherActor || OtherActor == this) return;

    // 같은 액터에 중복 데미지 방지 (원하면 제거)
    if (DamagedActors.Contains(OtherActor)) return;

    // 인스티게이터 컨트롤러(가해자)를 적절히 결정
    AController* InstigatorController =
        GetInstigatorController() ? GetInstigatorController()
        : (GetOwner() ? GetOwner()->GetInstigatorController() : nullptr);

    UGameplayStatics::ApplyDamage(
        OtherActor,
        SingleSwingDamageAmount,
        InstigatorController,
        this,
        DamageTypeClass ? *DamageTypeClass : UDamageType::StaticClass() 
    );

    DamagedActors.Add(OtherActor);
}