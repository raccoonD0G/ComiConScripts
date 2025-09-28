// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Webcam.h"
#include "Components/BoxComponent.h"

AWebcam::AWebcam()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	RootComponent = SceneComponent;

	ClampVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("ClampVolume"));
	ClampVolume->SetupAttachment(RootComponent);
	ClampVolume->SetBoxExtent(FVector(92.0f, 100.0f, 540.0f));
	ClampVolume->SetCollisionProfileName(TEXT("NoCollision"));

}

UBoxComponent* AWebcam::GetClampVolume() const
{
	return ClampVolume;
}

