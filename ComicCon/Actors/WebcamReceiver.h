// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/NDIReceiveActor.h"
#include "Interfaces/ClampVolumeInterface.h"
#include "WebcamReceiver.generated.h"

/**
 * 
 */
UCLASS()
class COMICCON_API AWebcamReceiver : public ANDIReceiveActor, public IClampVolumeInterface
{
	GENERATED_BODY()

public:
	AWebcamReceiver();

	virtual class UBoxComponent* GetClampVolume() const override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (AllowPrivateAccess = true))
	TObjectPtr<class UBoxComponent> ClampVolume = nullptr;
	
};
