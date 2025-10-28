// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/NormalCam.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"

ANormalCam::ANormalCam()
{
}

void ANormalCam::BeginPlay()
{
	Super::BeginPlay();
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0))
	{
		PC->SetViewTargetWithBlend(this, /*BlendTime=*/0.f, VTBlend_Linear, /*BlendExp=*/0.f, /*bLockOutgoing=*/false);
	}
}
