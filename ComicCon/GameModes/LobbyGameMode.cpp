// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModes/LobbyGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "SaveGames/ScoreSaveGame.h"

void ALobbyGameMode::BeginPlay()
{
	Super::BeginPlay();

	Init();
}

void ALobbyGameMode::Init()
{
	// 저장 객체 로드 또는 생성
	UScoreSaveGame* SaveObj = nullptr;
	if (UGameplayStatics::DoesSaveGameExist(SaveSlotName, UserIndex))
	{
		SaveObj = Cast<UScoreSaveGame>(UGameplayStatics::LoadGameFromSlot(SaveSlotName, UserIndex));
	}
	if (!SaveObj)
	{
		SaveObj = Cast<UScoreSaveGame>(UGameplayStatics::CreateSaveGameObject(UScoreSaveGame::StaticClass()));
	}

	if(!SaveObj) return;

	SaveObj->CurrentHunterCount ++;

	if (SaveObj->ScoreHistory.IsEmpty())
	{
		SaveObj->ScoreHistory.Add({5000, 1000});
		SaveObj->ScoreHistory.Add({4000, 1001});
		SaveObj->ScoreHistory.Add({3000, 1002});
		SaveObj->ScoreHistory.Add({2000, 1003});
		SaveObj->ScoreHistory.Add({1000, 1004});	
	}
	
	// 너무 커지는 걸 방지하고 싶다면 (예: 1000개 유지)
	const int32 MaxKeep = 1000;
	
	if (SaveObj->ScoreHistory.Num() > MaxKeep)
	{
		const int32 ToRemove = SaveObj->ScoreHistory.Num() - MaxKeep;
		SaveObj->ScoreHistory.RemoveAt(0, ToRemove, /*bAllowShrinking=*/false);
	}

	UGameplayStatics::SaveGameToSlot(SaveObj, SaveSlotName, UserIndex);
}
