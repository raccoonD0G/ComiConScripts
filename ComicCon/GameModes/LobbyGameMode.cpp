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

	UGameplayStatics::SaveGameToSlot(SaveObj, GameSave::BoothSessionSlot, 0);
}
