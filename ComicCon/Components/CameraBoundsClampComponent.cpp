// Fill out your copyright notice in the Description page of Project Settings.

#include "CameraBoundsClampComponent.h"
#include "Components/BoxComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

UCameraBoundsClampComponent::UCameraBoundsClampComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UCameraBoundsClampComponent::BeginPlay()
{
    Super::BeginPlay();
}

void UCameraBoundsClampComponent::Init(UBoxComponent* InBoundsBox, USpringArmComponent* InSpringArm)
{
    BoundsBox = InBoundsBox;
    SpringArm = InSpringArm;

    ResolveCameraComponent();
}

void UCameraBoundsClampComponent::TickComponent(float DeltaTime, ELevelTick TickType,
    FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    ClampNow();
}

void UCameraBoundsClampComponent::ClampNow()
{
    if (!BoundsBox || !SpringArm) return;

    // 스프링암의 시작점(피벗 위치, 즉 카메라 소켓 위치 아님!)
    const FVector PivotWorld = SpringArm->GetComponentLocation();

    // 박스 로컬 공간으로 변환
    const FTransform BoxXf = BoundsBox->GetComponentTransform();
    const FVector PivotLocal = BoxXf.InverseTransformPosition(PivotWorld);

    // 박스 로컬 extents
    const FVector Extent = BoundsBox->GetUnscaledBoxExtent();

    // 좌우 시야를 고려한 보정 폭 계산
    float LocalHorizontalMargin = 0.0f;
    if (UCameraComponent* CameraComponent = ResolveCameraComponent())
    {
        const FVector CameraWorld = SpringArm->GetSocketLocation(USpringArmComponent::SocketName);
        const float DistanceToPivot = FVector::Dist(CameraWorld, PivotWorld);

        if (CameraComponent->ProjectionMode == ECameraProjectionMode::Orthographic)
        {
            LocalHorizontalMargin = CameraComponent->OrthoWidth * 0.5f;
        }
        else
        {
            const float HalfFovRad = FMath::DegreesToRadians(CameraComponent->FieldOfView * 0.5f);
            float HalfHorizontalFov = HalfFovRad;

            if (CameraComponent->AspectRatio > KINDA_SMALL_NUMBER)
            {
                const float Adjusted = FMath::Atan(FMath::Tan(HalfFovRad) * CameraComponent->AspectRatio);
                HalfHorizontalFov = FMath::Max(HalfHorizontalFov, Adjusted);
            }

            LocalHorizontalMargin = FMath::Tan(HalfHorizontalFov) * DistanceToPivot;
        }

        if (LocalHorizontalMargin > KINDA_SMALL_NUMBER)
        {
            const float ScaleY = FMath::Max(FMath::Abs(BoundsBox->GetComponentScale().Y), KINDA_SMALL_NUMBER);
            LocalHorizontalMargin /= ScaleY;
        }
        else
        {
            LocalHorizontalMargin = 0.0f;
        }
    }

    // 클램프
    FVector ClampedLocal = PivotLocal;
    ClampedLocal.X = FMath::Clamp(ClampedLocal.X, -Extent.X, Extent.X);
    ClampedLocal.Z = FMath::Clamp(ClampedLocal.Z, -Extent.Z, Extent.Z);

    if (LocalHorizontalMargin > KINDA_SMALL_NUMBER)
    {
        const float AllowedHalfWidth = Extent.Y - LocalHorizontalMargin;
        if (AllowedHalfWidth <= 0.0f)
        {
            ClampedLocal.Y = 0.0f;
        }
        else
        {
            ClampedLocal.Y = FMath::Clamp(ClampedLocal.Y, -AllowedHalfWidth, AllowedHalfWidth);
        }
    }
    else
    {
        ClampedLocal.Y = FMath::Clamp(ClampedLocal.Y, -Extent.Y, Extent.Y);
    }

    // 다시 월드 위치로 변환
    const FVector ClampedWorld = BoxXf.TransformPosition(ClampedLocal);

    // 차이를 스프링암 부모 기준으로 보정
    USceneComponent* Parent = SpringArm->GetAttachParent();
    if (Parent)
    {
        const FVector Local = Parent->GetComponentTransform().InverseTransformPosition(ClampedWorld);
        SpringArm->SetRelativeLocation(Local);
    }
    else
    {
        SpringArm->SetWorldLocation(ClampedWorld);
    }
}

UCameraComponent* UCameraBoundsClampComponent::ResolveCameraComponent()
{
    if (CachedCameraComponent.IsValid())
    {
        return CachedCameraComponent.Get();
    }

    if (!SpringArm)
    {
        return nullptr;
    }

    TArray<USceneComponent*> Children;
    SpringArm->GetChildrenComponents(true, Children);

    for (USceneComponent* Child : Children)
    {
        if (UCameraComponent* CameraComponent = Cast<UCameraComponent>(Child))
        {
            CachedCameraComponent = CameraComponent;
            return CameraComponent;
        }
    }

    return nullptr;
}
