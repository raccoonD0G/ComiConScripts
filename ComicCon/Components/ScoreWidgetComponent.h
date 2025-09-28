// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "ScoreWidgetComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class COMICCON_API UScoreWidgetComponent : public USceneComponent
{
	GENERATED_BODY()

public:
	UScoreWidgetComponent();

	UFUNCTION(BlueprintCallable, Category = "Score")
	void ShowFloatingImage(UTexture2D* Texture, FLinearColor Color = FLinearColor::White, float OverrideLifeTime = -1.f, float OverrideRiseSpeed = -1.f);

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	/** 스폰할 액터 클래스(에디터에서 지정) */
	UPROPERTY(EditAnywhere, Category = "Score|Class")
	TSubclassOf<class AFloatingWorldWidgetActor> FloatingWidgetActorClass;

	/** 기본 지속 시간(초) */
	UPROPERTY(EditAnywhere, Category = "Score|Defaults")
	float DefaultLifeTime = 1.2f;

	/** 기본 상승 속도(Z, uu/s) */
	UPROPERTY(EditAnywhere, Category = "Score|Defaults")
	float DefaultRiseSpeed = 120.f;
};
