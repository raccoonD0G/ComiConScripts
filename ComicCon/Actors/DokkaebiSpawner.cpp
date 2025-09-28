// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/DokkaebiSpawner.h"
#include "Components/BoxComponent.h"

ADokkaebiSpawner::ADokkaebiSpawner()
{
}

FTransform ADokkaebiSpawner::GetSpawnTransform_Implementation()
{
	// 기본 트랜스폼은 액터 것 유지, 위치만 교체
	FTransform Xf = GetActorTransform();
	Xf.SetLocation(ComputeSpawnLocationSameXZ_RandY());
	return Xf;
}

FVector ADokkaebiSpawner::ComputeSpawnLocationSameXZ_RandY() const
{
    const UBoxComponent* Box = SpawnBoxComponent;
    if (!Box)
    {
        return GetActorLocation();
    }

    // 박스의 로컬 Half-Extent (스케일 미적용)
    const FVector ExtUS = Box->GetUnscaledBoxExtent();

    // 로컬 Y를 -Ext.Y ~ +Ext.Y에서 랜덤
    const float RandLocalY = FMath::FRandRange(-ExtUS.Y, ExtUS.Y);

    // “가장 낮은 Z” = -Ext.Z, “가장 큰 X” = +Ext.X, Y만 랜덤
    const FVector LocalOnBottomMaxX(+ExtUS.X, RandLocalY, -ExtUS.Z);

    // 박스 컴포넌트의 트랜스폼(회전/스케일/위치 포함)으로 월드 변환
    const FTransform BoxXf = Box->GetComponentTransform();
    const FVector SpawnW = BoxXf.TransformPosition(LocalOnBottomMaxX);
    return SpawnW;
}
