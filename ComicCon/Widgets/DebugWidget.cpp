// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/DebugWidget.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "GameModes/BattleGameMode.h"
#include "GameStates/BattleGameState.h"
#include "Kismet/GameplayStatics.h"
#include "Containers/StringConv.h"
#include "ComicConGameInstance.h"

void UDebugWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (TestResultButton)
    {
        TestResultButton->OnClicked.AddDynamic(this, &UDebugWidget::HandleTestResultButtonClicked);
    }
}

// UDebugWidget.cpp
void UDebugWidget::HandleTestResultButtonClicked()
{
    const int32 DesiredScore = GetDesiredScore();

    if (UWorld* World = GetWorld())
    {
        if (UComicConGameInstance* GI = World->GetGameInstance<UComicConGameInstance>())
        {
            GI->PendingDesiredScore = DesiredScore;
            GI->bEndMatchOnPostLoad = true;   // �� �� �ε� �� EndMatch ȣ��
        }

        // �� �̻� ������ ��������Ʈ ���ε����� ���� (�ı��Ǳ� ����)
        UGameplayStatics::OpenLevel(this, FName(TEXT("BattleMap")));
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

