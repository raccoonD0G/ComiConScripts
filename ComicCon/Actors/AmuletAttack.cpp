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
    // 1) ���� ���� ���
    constexpr float L0 = 10.0f;

    // 2) ������ �Լ��� ���� ������ ���
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

    // 3) HalfExtent ��� �� ���̿� ������ ����
    const FVector HalfExtent(
        PlaneHalfThickness,                         // X: �β� Half
        FMath::Max(1.f, (InLength * 0.5f) * LengthScale / 10.0f), // Y: ������� HalfLength (������ �����)
        FMath::Max(1.f, InWidth * 0.5f)             // Z: �� Half
    );

    FRotator CorrectedRotation = InRotation;
    CorrectedRotation.Add(90.f, 0.f, 90.f);
    SetActorLocation(InCenter);
    SetActorRotation(CorrectedRotation);

    // �ڽ� ũ�� ����
    PlaneBox->SetBoxExtent(HalfExtent, false);
    PlaneBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    PlaneBox->SetGenerateOverlapEvents(true);

    // -X �� ��ġ ����
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

    // ����� �ڽ�
    if (bDoDebug)
    {
        const FQuat Q = CorrectedRotation.Quaternion();
        const FVector CenterFromStartFace = InCenter + Q.GetAxisX() * HalfExtent.X;
        DrawDebugBox(GetWorld(), CenterFromStartFace, HalfExtent, Q, FColor::Cyan, false, 1.0f, 0, 2.f);
    }

    // FX�� ������ LengthScale ����
    SpawnOrUpdateFX(InCenter, FRotator(90, 90, 0), InLength * LengthScale, InWidth);
}


void AAmuletAttack::SpawnOrUpdateFX(const FVector& Center, const FRotator& Rotation, float InLength, float InWidth)
{
    if (!SwingPlaneFX)
    {
        UE_LOG(LogTemp, Warning, TEXT("SwingPlaneFX is null in AAmuletAttack"));
        return;
    }

    // ���� FX �ִٸ� ����
    if (SpawnedFX && !SpawnedFX->IsPendingKill())
    {
        SpawnedFX->DestroyComponent();
        SpawnedFX = nullptr;
    }

    // ����
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

    // ���� ���Ϳ� �ߺ� ������ ���� (���ϸ� ����)
    if (DamagedActors.Contains(OtherActor)) return;

    // �ν�Ƽ������ ��Ʈ�ѷ�(������)�� ������ ����
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