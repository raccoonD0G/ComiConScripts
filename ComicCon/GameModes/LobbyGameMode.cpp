// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModes/LobbyGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "SaveGames/BoothSave.h"
#include "SaveGames/GameSaveConstants.h"

void ALobbyGameMode::BeginPlay()
{
	Super::BeginPlay();

	Init();
}

void ALobbyGameMode::Init()
{
	// 저장 객체 로드 또는 생성
	UBoothSave* SaveObj = nullptr;
	if (UGameplayStatics::DoesSaveGameExist(GameSave::BoothSessionSlot, 0))
	{
		SaveObj = Cast<UBoothSave>(UGameplayStatics::LoadGameFromSlot(GameSave::BoothSessionSlot, 0));
	}
	if (!SaveObj)
	{
		SaveObj = Cast<UBoothSave>(UGameplayStatics::CreateSaveGameObject(UBoothSave::StaticClass()));
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

	UGameplayStatics::SaveGameToSlot(SaveObj, GameSave::BoothSessionSlot, 0);
}
