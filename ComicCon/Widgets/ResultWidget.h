// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SaveGames/ScoreSaveGame.h"
#include "ResultWidget.generated.h"

/**
 * 
 */
UCLASS()
class COMICCON_API UResultWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

	virtual void NativeDestruct() override;

public:
	UPROPERTY(meta = (BindWidget))
	class UVerticalBox* ListBox;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Text_MyScore;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Text_HunterCount;
	
	// 행으로 쓸 위젯 클래스 (BP에서 지정)
	UPROPERTY(EditDefaultsOnly, Category = "Ranking")
	TSubclassOf<class URankingRowWidget> RowWidgetClass;

	// 슬롯/유저 인덱스 (고정이면 constexpr/const로 빼도 됨)
	UPROPERTY(EditDefaultsOnly, Category = "Ranking")
	FString SaveSlotName = TEXT("BattleSave");

	UPROPERTY(EditDefaultsOnly, Category = "Ranking")
	int32 UserIndex = 0;

	UPROPERTY(meta = (BindWidgetAnim), Transient)
	UWidgetAnimation* MyScoreAnimation;
	
private:
	void Populate();

	void RankChange();

	UFUNCTION()
	void SpawnNextRow(); // 타이머 콜백

	void ListBoxCheck(int32 Check);

	UPROPERTY()
	TArray<FScoreEntry> PendingScores;
	
	int32 CurrentIndex = 0;
	int32 TargetCount = 0;

	FTimerHandle DelayHandle;

	UPROPERTY()
	URankingRowWidget* ChangeRow;

// Background Section
private:
	/** BP에서 설정해두는 MediaPlayer (WBP 변수 Outro와 매칭) */
	UPROPERTY(EditAnywhere)
	TObjectPtr<class UMediaPlayer> Outro = nullptr;

	/** 열어줄 MediaSource (고정 자산 경로를 기본값으로 넣어둠) */
	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<class UMediaSource> OutroSource = TSoftObjectPtr<UMediaSource>(FSoftObjectPath(TEXT("/Game/Assets/Widget/Media/FMS_Outro.FMS_Outro")));

	FTimerHandle OutroOpenTimerHandle;

	UFUNCTION()
	void OpenOutroAfterDelay();
};
