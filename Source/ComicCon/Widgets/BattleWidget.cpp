// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/BattleWidget.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "GameStates/BattleGameState.h"
#include "Kismet/GameplayStatics.h"
#include "Pawns/ViewPlayer.h"
#include "SaveGames/ScoreSaveGame.h"

void UBattleWidget::NativeConstruct()
{
    Super::NativeConstruct();

    ABattleGameState* BattleGameState = GetWorld()->GetGameState<ABattleGameState>();
    if (BattleGameState)
    {
        BattleGameState->OnScoreChanged.AddDynamic(this, &UBattleWidget::SetScoreText);
        BattleGameState->OnCountdownSec.AddDynamic(this, &UBattleWidget::SetTimerText);
    }

    APawn* Pawn = UGameplayStatics::GetPlayerPawn(this, 0);
    if (AViewPlayer* ViewPlayer = Cast<AViewPlayer>(Pawn))
    {
        ViewPlayer->OnPlayerHealthChanged.AddDynamic(this, &UBattleWidget::OnPlayerHealthChanged);
        OnPlayerHealthChanged(ViewPlayer->GetMaxHealth(), ViewPlayer->GetCurrentHealth());
    }

    // === �ְ� ���� �ε� & ǥ�� ===
    CachedHighScore = 0;
    if (UGameplayStatics::DoesSaveGameExist(SaveSlotName, UserIndex))
    {
        if (UScoreSaveGame* SaveObj = Cast<UScoreSaveGame>(UGameplayStatics::LoadGameFromSlot(SaveSlotName, UserIndex)))
        {
            for (const FScoreEntry& Entry : SaveObj->ScoreHistory)
            {
                CachedHighScore = FMath::Max(CachedHighScore, Entry.Score);
            }

            FString HunterCount = FString::FromInt(SaveObj->CurrentHunterCount);

            Text_HounterCount->SetText(FText::FromString(HunterCount));
        }
    }
    SetHighScoreText(CachedHighScore);
}

void UBattleWidget::SetScoreText(int32 Count)
{
    if (MyScoreText)
    {
        MyScoreText->SetText(FText::AsNumber(Count));
    }

    if (Count > CachedHighScore)
    {
        CachedHighScore = Count;
        SetHighScoreText(CachedHighScore);
    }
}

void UBattleWidget::SetHighScoreText(int32 Count)
{
    if (HighScoreText)
    {
        HighScoreText->SetText(FText::AsNumber(Count));
    }
}

void UBattleWidget::OnPlayerHealthChanged(int32 MaxHealth, int32 CurrentHealth)
{
    SetHealthPercent((float)CurrentHealth / (float)MaxHealth);
}

void UBattleWidget::SetHealthPercent(float Percent)
{
    if (HealthProgressBar)
    {
        HealthProgressBar->SetPercent(FMath::Clamp(Percent, 0.0f, 1.0f));
    }
}

void UBattleWidget::SetTimerText(int32 InSecond)
{
    if (TimerText)
    {
        // int32 Min = InSecond / 60;
        // int32 Sec = InSecond % 60;
        //
        // FString MinStr;
        // FString SecStr;
        //
        // if (Min < 10)
        // {
        //     MinStr.Append(TEXT("0"));
        // }
        //
        // if (Sec < 10)
        // {
        //     SecStr.Append(TEXT("0"));
        // }
        //
        // MinStr.Append(FString::FromInt(Min));
        // SecStr.Append(FString::FromInt(Sec));
        //
        // FString TimeRemaining = MinStr + TEXT(":") + SecStr;
        TimerText->SetText(FText::AsNumber(InSecond));
    }
}
