// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloatingWorldWidgetActor.generated.h"

UCLASS()
class COMICCON_API AFloatingWorldWidgetActor : public AActor
{
	GENERATED_BODY()

public:
	AFloatingWorldWidgetActor();

	/** 컴포넌트/스폰러가 호출: 내용 세팅 */
	void InitFloatingImage(UTexture2D* InTexture, const FLinearColor& InTint, float InLifeTime, float InRiseSpeed);

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Widget")
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Widget")
	class UWidgetComponent* WidgetComp;

	// 파라미터
	FText InitialText;
	FLinearColor InitialColor = FLinearColor::White;

	float LifeTime = 1.2f;     // 총 지속시간(초)
	float RiseSpeed = 120.f;   // 초당 Z 이동량

	float Elapsed = 0.f;
	bool bInitialized = false;

	/** 위젯에 인터페이스가 있으면 캐싱 */
	UPROPERTY()
	UObject* CachedUserWidgetObj = nullptr;

	/** 알파 곡선(선형이면 nullptr). 있으면 0~1 입력, 1~0 출력으로 사용 */
	UPROPERTY(EditAnywhere, Category = "Widget|Anim")
	UCurveFloat* FadeCurve = nullptr;

	UPROPERTY()
	TObjectPtr<UTexture2D> CachedTexture;
};
