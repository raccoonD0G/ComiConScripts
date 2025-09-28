// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/ClampVolumeInterface.h"
#include "Webcam.generated.h"

UCLASS()
class COMICCON_API AWebcam : public AActor, public IClampVolumeInterface
{
	GENERATED_BODY()

public:
	AWebcam();

	virtual class UBoxComponent* GetClampVolume() const override;

private:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (AllowPrivateAccess = true))
	TObjectPtr<USceneComponent> SceneComponent = nullptr;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (AllowPrivateAccess = true))
	TObjectPtr<class UBoxComponent> ClampVolume = nullptr;
};
