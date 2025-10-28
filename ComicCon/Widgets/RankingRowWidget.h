// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RankingRowWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStartAnimationFinished);

/**
 * 
 */
UCLASS()
class COMICCON_API URankingRowWidget : public UUserWidget
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable)
    void SetData(int32 Rank, int32 HunterNum, int32 Score);

    /** 애니메이션 완료 시 델리게이트 */
    UPROPERTY(BlueprintAssignable, Category = "Event")
    FOnStartAnimationFinished StartAnimationFinished;

    UFUNCTION()
    static FString GetEnglishOrdinalSuffix(int32 Rank);

    UFUNCTION()
    static FText MakeOrdinalText(int32 Rank);
    
    UFUNCTION()
    void ChangeScore();

    UFUNCTION()
    void FillImage();

    UFUNCTION()
    void ChangeWidget(int32 score, int32 hunterNum);

protected:
    UPROPERTY(meta = (BindWidget))
    class UTextBlock* RankText;

    UPROPERTY(meta = (BindWidget))
    class UTextBlock* ScoreText;

    UPROPERTY(meta = (BindWidget))
    class UTextBlock* Text_HunterNum;
    
    UPROPERTY(meta = (BindWidget))
    class UImage* Image_Effect;
    
    UPROPERTY(meta = (BindWidgetAnim), Transient)
    UWidgetAnimation* ShowAnimation;
    
    UPROPERTY(meta = (BindWidgetAnim), Transient)
    UWidgetAnimation* ChangeAnimation;

    virtual void NativeConstruct() override;

    virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

    virtual void NativeDestruct() override;

    UPROPERTY()
    bool bCheckChange = false;

    UPROPERTY()
    float delta = 0.f;

    /** 애니메이션 완료 시 호출될 함수 */
    UFUNCTION()
    void HandleAnimationFinished();

private:
    FTimerHandle TimerHandle1;

    FTimerHandle TimerHandle2;

    UPROPERTY()
    int32 CScore = 0;
    
    UPROPERTY()
    int32 HNum = 0;

// Sound Section
private:
    UPROPERTY(EditDefaultsOnly, Category = "Audio")
    TObjectPtr<USoundBase> ImpactSoundAsset = nullptr;

    UFUNCTION()
    void PlayImpactSound();
};
