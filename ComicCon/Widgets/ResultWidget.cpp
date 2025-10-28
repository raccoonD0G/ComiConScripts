// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/ResultWidget.h"
#include "Components/VerticalBox.h"
#include "Kismet/GameplayStatics.h"
#include "SaveGames/ScoreSaveGame.h"
#include "RankingRowWidget.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBoxSlot.h"
#include "MediaPlayer.h"
#include "MediaSource.h"
#include "Engine/World.h"
#include "TimerManager.h"

void UResultWidget::NativeConstruct()
{
	Super::NativeConstruct();

	Populate();
}

void UResultWidget::NativeDestruct()
{
	Super::NativeDestruct();
}

void UResultWidget::Populate()
{
	PendingScores.Reset();
	
	if (!ListBox || !RowWidgetClass) return;

	UScoreSaveGame* SaveObj = nullptr;
	
	if (UGameplayStatics::DoesSaveGameExist(SaveSlotName, UserIndex))
	{
		SaveObj = Cast<UScoreSaveGame>(UGameplayStatics::LoadGameFromSlot(SaveSlotName, UserIndex));
	}
	if (!SaveObj)
	{
		SaveObj = Cast<UScoreSaveGame>(UGameplayStatics::CreateSaveGameObject(UScoreSaveGame::StaticClass()));
	}
	
	if (!SaveObj) return;

	PendingScores = SaveObj->ScoreHistory;
	
	Text_MyScore->SetText(FText::AsNumber(SaveObj->LastScore));

	Text_HunterCount->SetText(FText::FromString(FString::FromInt(SaveObj->CurrentHunterCount)));

	UE_LOG(LogTemp, Warning, TEXT("pending num is : %d"), PendingScores.Num());

	if(PendingScores.Num() < 5)
	{
		TargetCount = PendingScores.Num();
	}
	else
	{
		TargetCount = 5;
	}
	
	CurrentIndex = 0;

	SpawnNextRow();
}

void UResultWidget::RankChange()
{
	UScoreSaveGame* SaveObj = nullptr;
	
	if (UGameplayStatics::DoesSaveGameExist(SaveSlotName, UserIndex))
	{
		SaveObj = Cast<UScoreSaveGame>(UGameplayStatics::LoadGameFromSlot(SaveSlotName, UserIndex));
	}
	
	if (!SaveObj) return;
	
	const int32 HunterNum = SaveObj->CurrentHunterCount;
	const int32 Score = SaveObj->LastScore;

	// 추가하고 재정렬
	PendingScores.Add({Score, HunterNum});
	
	PendingScores.Sort([](const FScoreEntry& A, const FScoreEntry& B) { return A.Score > B.Score; });

	SaveObj->ScoreHistory = PendingScores;

	UGameplayStatics::SaveGameToSlot(SaveObj, SaveSlotName, UserIndex);
	
	if(MyScoreAnimation)
	{
		PlayAnimation(MyScoreAnimation);
	}
	
	for(int i = 0; i < TargetCount; i++)
	{
		if(PendingScores[i].HunterCount == HunterNum)
		{
			ListBoxCheck(i);

			return;
		}
	}	
}

void UResultWidget::SpawnNextRow()
{
	if (CurrentIndex >= TargetCount)
	{
		RankChange();
		
		return;
	}
	
	if (!ListBox || !RowWidgetClass) return;

	URankingRowWidget* Row = CreateWidget<URankingRowWidget>(GetWorld(), RowWidgetClass);
	
	if (!Row) return;

	const int32 Rank = CurrentIndex + 1;
	const int32 Score = PendingScores[CurrentIndex].Score;
	const int32 HunterNum = PendingScores[CurrentIndex].HunterCount;
     
	Row->SetData(Rank, HunterNum, Score);
	
	UVerticalBoxSlot* Listslot= Cast<UVerticalBoxSlot>(ListBox->AddChild(Row));
	if(Listslot)
	{
		Listslot->SetHorizontalAlignment(HAlign_Center);
		Listslot->SetVerticalAlignment(VAlign_Center);
		
		if(Rank == 2)
		{
			Listslot->SetPadding(FMargin(0.f, 20.f, 0.f, 0.f));
		}
		else if(Rank == 3)
		{
			Listslot->SetPadding(FMargin(0.f, 22.f, 0.f, 0.f));
		}
		else if(Rank >= 4)
		{
			Listslot->SetPadding(FMargin(0.f, 20.f, 0.f, 0.f));
		}
	}
	
	// 애니메이션이 끝나면 다음 Row 추가
	Row->StartAnimationFinished.AddDynamic(this, &UResultWidget::SpawnNextRow);

	++CurrentIndex;
}

void UResultWidget::ListBoxCheck(int32 Check)
{
	ChangeRow = Cast<URankingRowWidget>(ListBox->GetChildAt(Check));

	ChangeRow->ChangeWidget(PendingScores[Check].Score, PendingScores[Check].HunterCount);
}

void UResultWidget::OpenOutroAfterDelay()
{
	if (!Outro)
	{
		UE_LOG(LogTemp, Warning, TEXT("UResultWidget::OpenOutroAfterDelay: Outro MediaPlayer is null"));
		return;
	}

	// 에셋이 이미 로드되어 있지 않다면 동기 로드
	UMediaSource* Source = OutroSource.LoadSynchronous();
	if (!Source)
	{
		UE_LOG(LogTemp, Warning, TEXT("UResultWidget::OpenOutroAfterDelay: OutroSource is null or failed to load"));
		return;
	}

	const bool bOpened = Outro->OpenSource(Source);
	UE_LOG(LogTemp, Log, TEXT("UResultWidget: Outro->OpenSource(%s) -> %s"), *Source->GetName(), bOpened ? TEXT("Success") : TEXT("Fail"));
}