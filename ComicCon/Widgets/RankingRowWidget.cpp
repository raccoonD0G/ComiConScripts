// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/RankingRowWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"

void URankingRowWidget::NativeConstruct()
{
    Super::NativeConstruct();

    // 애니메이션 끝났을 때 델리게이트 호출
    if (ShowAnimation)
    {
        FWidgetAnimationDynamicEvent EndEvent;
        EndEvent.BindUFunction(this, FName("HandleAnimationFinished"));
        BindToAnimationFinished(ShowAnimation, EndEvent);
    }
}

void URankingRowWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
    Super::NativeTick(MyGeometry, InDeltaTime);

    if(bCheckChange)
    {
        FillImage();
    }
}

void URankingRowWidget::NativeDestruct()
{
    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(TimerHandle1);

        World->GetTimerManager().ClearTimer(TimerHandle2);
    }
    
    Super::NativeDestruct();
}

void URankingRowWidget::HandleAnimationFinished()
{
    StartAnimationFinished.Broadcast();
}

void URankingRowWidget::SetData(int32 Rank, int32 HunterNum, int32 Score)
{
    if (RankText) { RankText->SetText(MakeOrdinalText(Rank)); }
    if (Text_HunterNum) { Text_HunterNum->SetText(FText::FromString(FString::FromInt(HunterNum))); }
    if (ScoreText) { ScoreText->SetText(FText::AsNumber(Score)); }

    if(Rank == 1)
    {
        RankText->SetColorAndOpacity(FSlateColor(FLinearColor(0.98f, 0.68f, 0.05f, 1.0f)));
    }
    else if(Rank == 2)
    {
        RankText->SetColorAndOpacity(FSlateColor(FLinearColor(0.68f, 0.68f, 0.68f, 1.0f)));
    }
    else if(Rank == 3)
    {
        RankText->SetColorAndOpacity(FSlateColor(FLinearColor(0.66f, 0.12f, 0.01f, 1.0f)));
    }
    
    if(Rank < 4)
    {
        const float SetF = Rank * 0.05;
        const FVector2d ScaleSet = {1.1 - SetF, 1.1 - SetF};
        SetRenderScale(ScaleSet);
    }
    else
    {
        const FVector2d ScaleSet = {0.85f, 0.85f};
        SetRenderScale(ScaleSet);
    }
    
    if (ShowAnimation)
    {
        PlayAnimation(ShowAnimation);
    }
    else
    {
        // 애니메이션 없으면 즉시 다음으로 넘어감
        StartAnimationFinished.Broadcast();
    }
}

FString URankingRowWidget::GetEnglishOrdinalSuffix(int32 Rank)
{
    const int32 Mod100 = Rank % 100;
    
    if (Mod100 >= 11 && Mod100 <= 13)
    {
        return TEXT("th");
    }

    switch (Rank % 10)
    {
        case 1:  return TEXT("st");
        case 2:  return TEXT("nd");
        case 3:  return TEXT("rd");
        default: return TEXT("th");
    }
}

FText URankingRowWidget::MakeOrdinalText(int32 Rank)
{
    const FString Suffix = GetEnglishOrdinalSuffix(Rank);
    return FText::Format(
        NSLOCTEXT("Ranking", "RankOrdinalFmt", "{0}{1}"),
        FText::AsNumber(Rank),
        FText::FromString(Suffix)
    );
}

void URankingRowWidget::ChangeScore()
{
    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(TimerHandle2);
        
        World->GetTimerManager().SetTimer(
            TimerHandle2,
            FTimerDelegate::CreateWeakLambda(this, [this]()
            {
                UE_LOG(LogTemp, Log, TEXT("ResultWidget 타이머 Tick 실행"));
                
                bCheckChange = true;
            }),
            1.0f,   
            false    
        );
    }
}

void URankingRowWidget::FillImage()
{
    delta += 0.01f;
    
    if(delta <= 1.0f)
    {
        FVector2d scale = {delta, 1.f};
        Image_Effect->SetRenderScale(scale);
       
        if(delta >= 0.9f)
        {
            FVector2d shear = {0.f, 0.f};
            Image_Effect->SetRenderShear(shear);
        }
    }
    else
    {
        bCheckChange = false;
        
        delta = 0.f;
    }
}

void URankingRowWidget::ChangeWidget(int32 score, int32 hunterNum)
{
    CScore = score;
    HNum = hunterNum;
    
    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(TimerHandle1);
        
        World->GetTimerManager().SetTimer(
            TimerHandle1,
            FTimerDelegate::CreateWeakLambda(this, [this]()
            {
                if(ChangeAnimation)
                {
                    PlayAnimation(ChangeAnimation);
                }

                ChangeScore();

                if (ScoreText) { ScoreText->SetText(FText::AsNumber(CScore)); }
                if (Text_HunterNum) { Text_HunterNum->SetText(FText::FromString(FString::FromInt(HNum))); }

                PlayImpactSound();
            }),
            1.0f,   
            false    
        );
    }
}

void URankingRowWidget::PlayImpactSound()
{
    if (!ImpactSoundAsset)
    {
        UE_LOG(LogTemp, Warning, TEXT("ImpactSoundAsset is null in %s"), *GetName());
        return;
    }

    UGameplayStatics::PlaySound2D(
        this,             // WorldContextObject
        ImpactSoundAsset,  // Sound
        1.0f,             // VolumeMultiplier
        1.0f,             // PitchMultiplier
        0.0f,             // StartTime
        nullptr,          // ConcurrencySettings
        nullptr,          // OwningActor
        true              // bIsUISound
    );
}
