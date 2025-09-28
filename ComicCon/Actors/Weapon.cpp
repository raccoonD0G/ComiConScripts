// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Weapon.h"
#include "Actors/MirroredPlayer.h"

AWeapon::AWeapon()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	RootComponent = SceneComponent;

	WeaponMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	WeaponMeshComponent->SetupAttachment(RootComponent);
}

void AWeapon::SetOwningPlayer(AMirroredPlayer* InMirroredPlayer)
{
    OwningPlayer = InMirroredPlayer;
}

void AWeapon::BeginPlay()
{
	Super::BeginPlay();

	check(OwningPlayer);
}


