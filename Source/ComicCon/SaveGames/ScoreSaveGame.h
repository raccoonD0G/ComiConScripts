// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "ScoreSaveGame.generated.h"

USTRUCT(BlueprintType)
struct FScoreEntry
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Score = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 HunterCount = 0;
};

/**
 * 
 */
UCLASS()
class COMICCON_API UScoreSaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:
    UPROPERTY(BlueprintReadWrite)
    int32 LastScore = 0;

    UPROPERTY(BlueprintReadWrite)
    int32 BestScore = 0;

	UPROPERTY(BlueprintReadWrite)
	TArray<FScoreEntry> ScoreHistory;

	UPROPERTY(BlueprintReadWrite)
	int32 CurrentHunterCount = 1004;
};
