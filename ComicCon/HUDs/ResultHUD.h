// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HUDs/LevelHUD.h"
#include "ResultHUD.generated.h"

/**
 * 
 */
UCLASS()
class COMICCON_API AResultHUD : public ALevelHUD
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;
};
