// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/ScoreWidgetComponent.h"
#include "Actors/FloatingWorldWidgetActor.h"
#include "Kismet/GameplayStatics.h"

UScoreWidgetComponent::UScoreWidgetComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UScoreWidgetComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UScoreWidgetComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UScoreWidgetComponent::ShowFloatingImage(UTexture2D* Texture, FLinearColor Color, float OverrideLifeTime, float OverrideRiseSpeed)
{
    if (!GetWorld() || !FloatingWidgetActorClass) return;

    float LifeTime = (OverrideLifeTime > 0.f) ? OverrideLifeTime : DefaultLifeTime;
    float RiseSpeed = (OverrideRiseSpeed > 0.f) ? OverrideRiseSpeed : DefaultRiseSpeed;

    FActorSpawnParameters Params;
    Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
    Params.Owner = GetOwner();

    AFloatingWorldWidgetActor* Actor = GetWorld()->SpawnActor<AFloatingWorldWidgetActor>(
        FloatingWidgetActorClass,
        GetComponentTransform(),
        Params
    );

    if (Actor)
    {
        Actor->InitFloatingImage(Texture, Color, LifeTime, RiseSpeed);
    }
}