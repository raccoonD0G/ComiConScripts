// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ComicConGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class COMICCON_API UComicConGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
protected:
	virtual void Init() override;

public:
	UPROPERTY()
	UAudioComponent* PersistentAudio;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
	USoundBase* BGM;
};
