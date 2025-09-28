// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDs/BattleHUD.h"
#include "Widgets/BattleWidget.h"
#include "Blueprint/UserWidget.h"

void ABattleHUD::BeginPlay()
{
    Super::BeginPlay();
    EnsureLevelWidgetCreated();
}

void ABattleHUD::EnsureLevelWidgetCreated()
{
    if (!LevelWidgetInstance && ensure(LevelWidgetClass))
    {
        LevelWidgetInstance = CreateWidget<UBattleWidget>(GetWorld(), LevelWidgetClass);
        if (ensure(LevelWidgetInstance))
        {
            // 이미 뷰포트에 없다면 추가
            if (!LevelWidgetInstance->IsInViewport())
            {
                LevelWidgetInstance->AddToViewport(LevelWidgetZOrder);
            }
            LevelWidgetInstance->SetVisibility(ESlateVisibility::Visible);
        }
    }
}

UBattleWidget* ABattleHUD::GetLevelWidget()
{
    if (!LevelWidgetInstance)
    {
        EnsureLevelWidgetCreated();
    }
    return LevelWidgetInstance;
}

