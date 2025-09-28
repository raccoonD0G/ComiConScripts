// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MathLibraries.generated.h"

/**
 * 
 */
UCLASS()
class COMICCON_API UMathLibraries : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public :
	static bool IsFinite2D(const FVector2f& V);

	static uint64 LocalNowMs();

	static float SuperlinearScale(float L, float L0, float alpha, float blend);

	// 베지어 계산 유틸
	static FVector BezierPoint(const TArray<FVector>& P, float T);
};
