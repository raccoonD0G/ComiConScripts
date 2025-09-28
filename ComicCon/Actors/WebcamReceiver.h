#pragma once

#include "CoreMinimal.h"
#include "Actors/NDIReceiveActor.h"
#include "Interfaces/ClampVolumeInterface.h"
#include "WebcamReceiver.generated.h"

UCLASS()
class COMICCON_API AWebcamReceiver : public ANDIReceiveActor, public IClampVolumeInterface
{
        GENERATED_BODY()

public:
        AWebcamReceiver();

        virtual void OnConstruction(const FTransform& Transform) override;
        virtual void PostInitializeComponents() override;

        virtual class UBoxComponent* GetClampVolume() const override;

	void UpdateClampVolume(const FIntPoint& FrameSize);

private:
	// Baseline extent captured from the component defaults.
	FVector DefaultClampExtent = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, Category = "Clamp")
	FIntPoint ReferenceFrameSize = FIntPoint(1080, 1920);

private:
        void UpdateClampVolumeBounds();

        UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (AllowPrivateAccess = true))
        TObjectPtr<class UBoxComponent> ClampVolume = nullptr;
};
