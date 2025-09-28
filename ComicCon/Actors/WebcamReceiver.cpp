// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/WebcamReceiver.h"
#include "Components/BoxComponent.h"

AWebcamReceiver::AWebcamReceiver()
{
        PrimaryActorTick.bCanEverTick = false;

        ClampVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("ClampVolume"));
        ClampVolume->SetupAttachment(RootComponent);
        ClampVolume->SetBoxExtent(FVector(92.0f, 100.0f, 540.0f));
        ClampVolume->SetCollisionProfileName(TEXT("NoCollision"));

        DefaultClampExtent = ClampVolume->GetUnscaledBoxExtent();
}

UBoxComponent* AWebcamReceiver::GetClampVolume() const
{
        return ClampVolume;
}

void AWebcamReceiver::UpdateClampVolume(const FIntPoint& FrameSize)
{
        if (!ClampVolume)
        {
                return;
        }

        if (DefaultClampExtent.IsNearlyZero())
        {
                DefaultClampExtent = ClampVolume->GetUnscaledBoxExtent();
        }

        const int32 SafeWidth = FMath::Max(FrameSize.X, 1);
        const int32 SafeHeight = FMath::Max(FrameSize.Y, 1);
        const int32 RefWidth = FMath::Max(ReferenceFrameSize.X, 1);
        const int32 RefHeight = FMath::Max(ReferenceFrameSize.Y, 1);

        FVector NewExtent = DefaultClampExtent;

        // Maintain aspect by scaling horizontal extent with incoming frame width
        // and vertical extent with incoming frame height, using the reference
        // frame as the baseline that was authored in the editor.
        const float WidthScale = (static_cast<float>(SafeWidth) / static_cast<float>(RefWidth)) *
                (static_cast<float>(RefHeight) / static_cast<float>(SafeHeight));
        const float HeightScale = static_cast<float>(SafeHeight) / static_cast<float>(RefHeight);

        NewExtent.Y = DefaultClampExtent.Y * WidthScale;
        NewExtent.Z = DefaultClampExtent.Z * HeightScale;

        ClampVolume->SetBoxExtent(NewExtent);
}
