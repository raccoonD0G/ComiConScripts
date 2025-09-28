// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/EnemySpawner.h"
#include "DokkaebiSpawner.generated.h"

/**
 * 
 */
UCLASS()
class COMICCON_API ADokkaebiSpawner : public AEnemySpawner
{
	GENERATED_BODY()
	
public:
	ADokkaebiSpawner();

protected:
	virtual FTransform GetSpawnTransform_Implementation() override;

private:
	/** 박스 내부에서 X/Z는 Far 기준, Y는 랜덤으로 만들고 월드로 변환 */
	FVector ComputeSpawnLocationSameXZ_RandY() const;
};
