#include "Actors/WebcamReceiver.h"

#include "Components/ActorComponent.h"
#include "Components/BoxComponent.h"
#include "Components/PrimitiveComponent.h"

AWebcamReceiver::AWebcamReceiver()
{
        PrimaryActorTick.bCanEverTick = false;

        ClampVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("ClampVolume"));
        ClampVolume->SetupAttachment(RootComponent);
        ClampVolume->SetCollisionProfileName(TEXT("NoCollision"));
}

UBoxComponent* AWebcamReceiver::GetClampVolume() const
{
        return ClampVolume;
}

void AWebcamReceiver::OnConstruction(const FTransform& Transform)
{
        Super::OnConstruction(Transform);
        UpdateClampVolumeBounds();
}

void AWebcamReceiver::PostInitializeComponents()
{
        Super::PostInitializeComponents();
        UpdateClampVolumeBounds();
}

void AWebcamReceiver::UpdateClampVolumeBounds()
{
        if (!ClampVolume)
        {
                return;
        }

        const FTransform WorldToActor = GetActorTransform().Inverse();
        FBox CombinedBounds(EForceInit::ForceInit);

        TInlineComponentArray<UPrimitiveComponent*> PrimitiveComponents(this);
        for (UPrimitiveComponent* Primitive : PrimitiveComponents)
        {
                if (!Primitive || Primitive == ClampVolume || !Primitive->IsRegistered())
                {
                        continue;
                }

                const FBoxSphereBounds WorldBounds = Primitive->CalcBounds(Primitive->GetComponentTransform());
                const FBoxSphereBounds ActorBounds = WorldBounds.TransformBy(WorldToActor);
                const FBox BoundsBox = ActorBounds.GetBox();

                if (BoundsBox.IsValid)
                {
                        CombinedBounds += BoundsBox;
                }
        }

        if (CombinedBounds.IsValid)
        {
                ClampVolume->SetRelativeLocation(CombinedBounds.GetCenter());
                ClampVolume->SetBoxExtent(CombinedBounds.GetExtent());
        }
}
