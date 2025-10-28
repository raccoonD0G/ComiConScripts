// Fill out your copyright notice in the Description page of Project Settings.


// BattleGameState.cpp

#include "GameStates/BattleGameState.h"
#include "TimerManager.h"
#include "Engine/World.h"
#include "GameModes/BattleGameMode.h"

ABattleGameState::ABattleGameState()
{
}

void ABattleGameState::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	SetCurrentState(EGamePlayState::BeforeBattle);
}

void ABattleGameState::BeginPlay()
{
	Super::BeginPlay();
}

void ABattleGameState::HandleBattleTimerTick()
{
	if (!bBattleTimerActive)
	{
		return; // 안전장치
	}

	// 1) 남은 시간 감소
	if (BattleRemainingSeconds > 0)
	{
		--BattleRemainingSeconds;
	}

	// 2) 감소 직후 브로드캐스트 (0도 전달)
	OnBattleTimerSec.Broadcast(BattleRemainingSeconds);

	// 3) 0 이하가 되면 종료 처리
	if (BattleRemainingSeconds <= 0)
	{
		bBattleTimerActive = false;

		if (UWorld* World = GetWorld())
		{
			World->GetTimerManager().ClearTimer(BattleTimerHandle);
			OnBattleTimerFinished.Broadcast();
			SetCurrentState(EGamePlayState::AfterBattle);
		}
	}
}

void ABattleGameState::SetCurrentState(EGamePlayState NewState)
{
	switch (NewState)
	{
	case EGamePlayState::BeforeBattle:
		OnBeforeBattleStateEntered.Broadcast();
		if (UWorld* World = GetWorld())
		{
			// 시작 전 3초 타이머 (Ready)
			World->GetTimerManager().SetTimer(
				BeforeBattleTimerHandle, this, &ABattleGameState::StartBattle, 3.0f, false);
		}
		break;

	case EGamePlayState::OnBattle:
		StartBattleTimer();
		OnBattleStateEntered.Broadcast();
		break;

	case EGamePlayState::AfterBattle:
		ABattleGameMode* BattleGameMode = Cast<ABattleGameMode>(GetWorld()->GetAuthGameMode());
		BattleGameMode->EndMatch();
		break;
	}

	CurrentState = NewState;
}

void ABattleGameState::StartBattle()
{
	SetCurrentState(EGamePlayState::OnBattle);
}

void ABattleGameState::StartBattleTimer()
{
	// 이미 돌고 있다면 정리
	if (bBattleTimerActive)
	{
		if (UWorld* World = GetWorld())
		{
			World->GetTimerManager().ClearTimer(BattleTimerHandle);
		}
	}

	bBattleTimerActive = true;
	BattleRemainingSeconds = BattleMaxSeconds;

	if (UWorld* World = GetWorld())
	{
		World->GetTimerManager().SetTimer(
			BattleTimerHandle, this, &ABattleGameState::HandleBattleTimerTick, 1.0f, true);
	}

	OnBattleTimerStarted.Broadcast();
	OnBattleTimerSec.Broadcast(BattleRemainingSeconds);
}

void ABattleGameState::AddScore(int32 InScore)
{
	Score += InScore;
	OnScoreChanged.Broadcast(Score);
}
