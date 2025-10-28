// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDs/LevelHUD.h"
#include "Widgets/BattleWidget.h"
#include "Blueprint/UserWidget.h"

void ALevelHUD::BeginPlay()
{
    Super::BeginPlay();
    EnsureLevelWidgetCreated();
}

void ALevelHUD::EnsureLevelWidgetCreated()
{
    if (!LevelWidgetInstance && ensure(LevelWidgetClass))
    {
        LevelWidgetInstance = CreateWidget<UUserWidget>(GetWorld(), LevelWidgetClass);
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

UUserWidget* ALevelHUD::GetLevelWidget()
{
    if (!LevelWidgetInstance)
    {
        EnsureLevelWidgetCreated();
    }
    return LevelWidgetInstance;
}