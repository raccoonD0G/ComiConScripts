// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/EnemySpawner.h"
#include "SuccubusSpawner.generated.h"

/**
 * 
 */
UCLASS()
class COMICCON_API ASuccubusSpawner : public AEnemySpawner
{
    GENERATED_BODY()

public:
    ASuccubusSpawner();

protected:
    virtual FTransform GetSpawnTransform_Implementation() override;
    virtual void ConfigureSpawnedEnemy_Implementation(AEnemyBase* NewEnemy) override;

private:
    FVector RandomPointInBoxWorld() const;

    void BuildControlPointsRandom();

    UPROPERTY(EditAnywhere, Category = "Succubus|Path")
    int32 NumMidPoints = 5;   // 박스 내부 중간 컨트롤 포인트 개수

    // (선택) 경로가 너무 들쭉날쭉하면 X 방향으로 정렬해서 완만하게
    UPROPERTY(EditAnywhere, Category = "Succubus|Path")
    uint8 bSortMidPointsByX : 1 = true;

    // 최신 컨트롤 포인트를 담아 Succubus.Init 에 넘김
    TArray<FVector> LatestControlPoints;

private:
    void SetStartPoint();
    void SetMiddlePoint();
    void SetEndPoint();
    void SortPoints();
};