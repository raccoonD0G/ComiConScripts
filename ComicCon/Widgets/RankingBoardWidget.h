// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RankingBoardWidget.generated.h"

/**
 * 
 */
UCLASS()
class COMICCON_API URankingBoardWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual void NativeConstruct() override;

protected:
    // UMG에 배치한 VerticalBox (이름: ListBox)
    UPROPERTY(meta = (BindWidget))
    class UVerticalBox* ListBox;

    // 행으로 쓸 위젯 클래스 (BP에서 지정)
    UPROPERTY(EditDefaultsOnly, Category = "Ranking")
    TSubclassOf<class URankingRowWidget> RowWidgetClass;

private:
    void Populate();

    UFUNCTION()
    void SpawnNextRow(); // 타이머 콜백

    TArray<int32> PendingScores;
    int32 CurrentIndex = 0;
    int32 TargetCount = 0;
};
