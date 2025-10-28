// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "NormalCam.generated.h"

/**
 * 
 */
UCLASS()
class COMICCON_API ANormalCam : public ACameraActor
{
	GENERATED_BODY()
	
public:
	ANormalCam();

protected:
	virtual void BeginPlay() override;
};
