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
	/** �ڽ� ���ο��� X/Z�� Far ����, Y�� �������� ����� ����� ��ȯ */
	FVector ComputeSpawnLocationSameXZ_RandY() const;
};
