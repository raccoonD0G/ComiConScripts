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
}

UBoxComponent* AWebcamReceiver::GetClampVolume() const
{
	return ClampVolume;
}