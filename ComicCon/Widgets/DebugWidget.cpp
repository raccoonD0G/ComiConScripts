// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/DebugWidget.h"

#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "GameModes/BattleGameMode.h"
#include "GameStates/BattleGameState.h"
#include "Kismet/GameplayStatics.h"

#include "Containers/StringConv.h"

void UDebugWidget::NativeConstruct()
{
        Super::NativeConstruct();

        if (TestResultButton)
        {
                TestResultButton->OnClicked.AddDynamic(this, &UDebugWidget::HandleTestResultButtonClicked);
        }
}

void UDebugWidget::HandleTestResultButtonClicked()
{
        const int32 DesiredScore = GetDesiredScore();

        if (UWorld* World = GetWorld())
        {
                if (ABattleGameState* BattleGameState = World->GetGameState<ABattleGameState>())
                {
                        const int32 CurrentScore = BattleGameState->GetScore();
                        const int32 DeltaScore = DesiredScore - CurrentScore;

                        if (DeltaScore != 0)
                        {
                                BattleGameState->AddScore(DeltaScore);
                        }
                }

                if (ABattleGameMode* BattleGameMode = World->GetAuthGameMode<ABattleGameMode>())
                {
                        BattleGameMode->EndMatch();
                }
                else
                {
                        UGameplayStatics::OpenLevel(World, FName(TEXT("ResultMap")));
                }
        }
}

int32 UDebugWidget::GetDesiredScore() const
{
        if (!ScoreInputTextBox)
        {
                return 0;
        }

        const FString InputString = ScoreInputTextBox->GetText().ToString();

        int32 ParsedScore = 0;
        if (!InputString.IsEmpty())
        {
                LexTryParseString<int32>(ParsedScore, *InputString);
        }

        return ParsedScore;
}

