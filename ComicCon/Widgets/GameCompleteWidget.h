// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameCompleteWidget.generated.h"

/**
 * 
 */
UCLASS()
class COMICCON_API UGameCompleteWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UGameCompleteWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}

	/** 이펙트 시작 (Duration<=0면 DefaultDuration 사용) */
	UFUNCTION(BlueprintCallable, Category = "Impact")
	void StartImpact(float InDuration = 0.f);

	/** 현재 재생 중인지 */
	UFUNCTION(BlueprintCallable, Category = "Impact")
	bool IsImpactPlaying() const { return bImpactPlaying; }

protected:
	// UUserWidget 수명주기
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	/** 팝 이펙트를 적용할 대상 이미지 (위젯 BP에서 바인딩) */
	UPROPERTY(meta = (BindWidget))
	class UImage* TextImage = nullptr;

	// ===================== 튜닝 파라미터 =====================

	/** 위젯이 생성될 때 자동으로 팡 이펙트를 재생할지 여부 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Impact|Tuning")
	bool bAutoPlayOnConstruct = true;

	/** 시작 스케일 (작게 시작) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Impact|Tuning")
	float StartScale = 0.2f;

	/** 오버슈트 스케일 (살짝 더 커졌다가) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Impact|Tuning")
	float OvershootScale = 1.12f;

	/** 최종 스케일 (안정 스케일) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Impact|Tuning")
	float EndScale = 1.0f;

	/** 총 재생 시간(초) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Impact|Tuning")
	float DefaultDuration = 0.60f;

	/** 팝(빠른 확대) 구간 비율 [0~1] */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Impact|Tuning", meta = (ClampMin = "0.1", ClampMax = "0.9"))
	float PopPhase = 0.35f;

	/** 오버슈트→안정화 구간 비율 [PopPhase~1] */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Impact|Tuning", meta = (ClampMin = "0.1", ClampMax = "0.9"))
	float SettlePhase = 0.65f;

	/** 초반 투명도 페이드인 구간 비율 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Impact|Tuning", meta = (ClampMin = "0.05", ClampMax = "0.6"))
	float FadeInPhase = 0.30f;

private:
	// ===================== 상태 =====================
	bool  bImpactPlaying = false;
	float Duration = 0.f;
	float Elapsed = 0.f;

	// ===================== 유틸 =====================
	static float SmoothStep(float A, float B, float X);
	static float EaseOutBack(float T, float Overshoot = 1.70158f);
	void ApplyTransform(float Scale, float Opacity);
};
