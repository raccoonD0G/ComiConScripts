// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/MirroredPlayer.h"
#include "Components/PoseUdpReceiverComponent.h"
#include "Components/SingleSwingClassifierComponent.h"

AMirroredPlayer::AMirroredPlayer()
{
	PrimaryActorTick.bCanEverTick = true;
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	RootComponent = SceneComponent;

	PoseReceiver = CreateDefaultSubobject<UPoseUdpReceiverComponent>(TEXT("PoseReceiver"));

	LeftSingleSwingClassifierComponent = CreateDefaultSubobject<USingleSwingClassifierComponent>(TEXT("LeftSingleSwingClassifierComponent"));
	LeftSingleSwingClassifierComponent->SetCurrentHandSide(EHandSide::Left);

	RightSingleSwingClassifierComponent = CreateDefaultSubobject<USingleSwingClassifierComponent>(TEXT("RightSingleSwingClassifierComponent"));
	RightSingleSwingClassifierComponent->SetCurrentHandSide(EHandSide::Right);
}

void AMirroredPlayer::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
}