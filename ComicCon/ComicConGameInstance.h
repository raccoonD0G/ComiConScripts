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
    virtual void OnStart() override;
    virtual void Shutdown() override;

private:
    void StartBGM();

    UPROPERTY()
    UAudioComponent* PersistentAudio = nullptr;

    UPROPERTY(EditDefaultsOnly)
    USoundBase* BGM = nullptr;

// Debug Section
public:
    // 위젯에서 세팅
    int32 PendingDesiredScore = INDEX_NONE;
    bool bEndMatchOnPostLoad = false;

private:
    FDelegateHandle PostLoadHandle;
    void HandlePostLoadMap(UWorld* NewWorld);
};
