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

    // 2) 스케일 함수로 길이 스케일 계산
    const float LengthScale = UMathLibraries::SuperlinearScale(InLength, L0, 1.3f, 0.7f);

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

    // 3) HalfExtent 계산 시 길이에 스케일 적용
    const FVector HalfExtent(
        PlaneHalfThickness,                         // X: 두께 Half
        FMath::Max(1.f, (InLength * 0.5f) * LengthScale / 10.0f), // Y: 진행방향 HalfLength (스케일 적용됨)
        FMath::Max(1.f, InWidth * 0.5f)             // Z: 폭 Half
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
                PlaneBox->SetCollisionProfileName(TEXT("NoCollison"));
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

    // FX도 동일한 LengthScale 전달
    SpawnOrUpdateFX(InCenter, FRotator(90, 90, 0), InLength * LengthScale, InWidth);
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

    const float NormLength = InLength / 100.0f;
    const float NormWidth = InWidth / 100.0f;

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