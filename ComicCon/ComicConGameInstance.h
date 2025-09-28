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
public:
    virtual void Init() override;
    virtual void OnStart() override; // ù �� �ε� �� ȣ��

private:
    void StartBGM();

    UPROPERTY()
    UAudioComponent* PersistentAudio = nullptr;

    UPROPERTY(EditDefaultsOnly)
    USoundBase* BGM = nullptr;
};
