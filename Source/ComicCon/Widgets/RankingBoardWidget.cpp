// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/RankingBoardWidget.h"
#include "Components/VerticalBox.h"
#include "Kismet/GameplayStatics.h"
#include "SaveGames/ScoreSaveGame.h"
#include "RankingRowWidget.h"
#include "Chaos/Math/Poisson.h"
#include "Components/VerticalBoxSlot.h"

void URankingBoardWidget::NativeConstruct()
{
    Super::NativeConstruct();
    
    Populate();
}

void URankingBoardWidget::Populate()
{
    if (!ListBox || !RowWidgetClass) return;

    UScoreSaveGame* SaveObj = nullptr;
    if (UGameplayStatics::DoesSaveGameExist(SaveSlotName, UserIndex))
    {
        SaveObj = Cast<UScoreSaveGame>(UGameplayStatics::LoadGameFromSlot(SaveSlotName, UserIndex));
    }
    if (!SaveObj) return;

    // 점수 정렬
    //PendingScores = SaveObj->ScoreHistory;
    //PendingScores.Sort([](int32 A, int32 B) { return A > B; });

    PendingScores = {10000, 1000, 100, 10, 1};

    TargetCount = 5;
    CurrentIndex = 0;

    SpawnNextRow();
}

void URankingBoardWidget::SpawnNextRow()
{
    if (CurrentIndex >= TargetCount) return;

    if (!ListBox || !RowWidgetClass) return;

    URankingRowWidget* Row = CreateWidget<URankingRowWidget>(GetWorld(), RowWidgetClass);
    if (!Row) return;

    const int32 Rank = CurrentIndex + 1;
    const int32 Score = PendingScores[CurrentIndex];

    UVerticalBoxSlot* Listslot= Cast<UVerticalBoxSlot>(ListBox->Slot);
    if(Listslot)
    {
        Listslot->SetSize(ESlateSizeRule::Fill);

        if(Rank < 3)
        {
            Listslot->SetPadding(FMargin(30.f, 0.f, 0.f, 0.f));
        }
        else if(Rank < 5)
        {
            Listslot->SetPadding(FMargin(25.f, 0.f, 0.f, 0.f));
        }
    }
        
    //Row->SetData(Rank, Score);
    ListBox->AddChild(Row);

    // 애니메이션이 끝나면 다음 Row 추가
    //Row->OnRowAnimationFinished.AddDynamic(this, &URankingBoardWidget::SpawnNextRow);

    ++CurrentIndex;
}
