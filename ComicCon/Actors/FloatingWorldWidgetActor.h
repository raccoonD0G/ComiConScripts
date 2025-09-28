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

	/** ������Ʈ/�������� ȣ��: ���� ���� */
	void InitFloatingImage(UTexture2D* InTexture, const FLinearColor& InTint, float InLifeTime, float InRiseSpeed);

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Widget")
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Widget")
	class UWidgetComponent* WidgetComp;

	// �Ķ����
	FText InitialText;
	FLinearColor InitialColor = FLinearColor::White;

	float LifeTime = 1.2f;     // �� ���ӽð�(��)
	float RiseSpeed = 120.f;   // �ʴ� Z �̵���

	float Elapsed = 0.f;
	bool bInitialized = false;

	/** ������ �������̽��� ������ ĳ�� */
	UPROPERTY()
	UObject* CachedUserWidgetObj = nullptr;

	/** ���� �(�����̸� nullptr). ������ 0~1 �Է�, 1~0 ������� ��� */
	UPROPERTY(EditAnywhere, Category = "Widget|Anim")
	UCurveFloat* FadeCurve = nullptr;

	UPROPERTY()
	TObjectPtr<UTexture2D> CachedTexture;
};
