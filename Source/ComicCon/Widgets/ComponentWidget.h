// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Engine/TextureRenderTarget2D.h"
#include "ComponentWidget.generated.h"

/**
 * 
 */
UCLASS()
class COMICCON_API UComponentWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void Init();

protected:
	virtual void NativeConstruct() override;

public:
	FORCEINLINE AActor* GetOwningActor() const { return OwningActor; }
	FORCEINLINE void SetOwningActor(AActor* InActor) { OwningActor = InActor; }

	// ===== Render-to-Texture API =====
	/** RT�� ����/�ʱ�ȭ (�ʿ� �� �ٽ� ����). */
	UFUNCTION(BlueprintCallable, Category = "RenderToTexture")
	void InitWidgetRenderTarget(int32 Width = 1024, int32 Height = 512,
		bool bInUseGammaSpace = true, TEnumAsByte<ETextureRenderTargetFormat> InFormat = RTF_RGBA8);

	/** �ܺ� RT�� �����ؼ� ���⿡ �׸����� ����. */
	UFUNCTION(BlueprintCallable, Category = "RenderToTexture")
	void SetWidgetRenderTarget(UTextureRenderTarget2D* InRT);

	/** ���� ������ RT�� ��� �׸���(�� ������ ����). */
	UFUNCTION(BlueprintCallable, Category = "RenderToTexture")
	void DrawWidgetToRenderTarget();

	/** �ڵ� ���� On/Off �� �ֱ�(��). 0�̸� �� ƽ. */
	UFUNCTION(BlueprintCallable, Category = "RenderToTexture")
	void SetAutoRedraw(bool bEnable, float InIntervalSeconds = 0.f);

	/** ���� RT �������� (��Ƽ���� �Ķ���ͷ� �Ⱦ� ���). */
	UFUNCTION(BlueprintCallable, Category = "RenderToTexture")
	UTextureRenderTarget2D* GetWidgetRenderTarget() const { return WidgetRenderTarget; }

protected:
	virtual void NativeDestruct() override;

private:
	UPROPERTY()
	TObjectPtr<AActor> OwningActor = nullptr;

	// ===== ���� ���� =====
	UPROPERTY(Transient)
	TObjectPtr<UTextureRenderTarget2D> WidgetRenderTarget = nullptr;

	UPROPERTY(EditAnywhere, Category = "RenderToTexture")
	FIntPoint DesiredRTSize = FIntPoint(1024, 512);

	UPROPERTY(EditAnywhere, Category = "RenderToTexture")
	bool bUseGammaSpace = true;

	UPROPERTY(EditAnywhere, Category = "RenderToTexture")
	TEnumAsByte<ETextureRenderTargetFormat> RTFormat = RTF_RGBA8;

	/** �ڵ� ���� ���� */
	UPROPERTY(EditAnywhere, Category = "RenderToTexture")
	bool bAutoRedraw = false;

	UPROPERTY(EditAnywhere, Category = "RenderToTexture", meta = (EditCondition = "bAutoRedraw"))
	float RedrawIntervalSeconds = 0.f; // 0 = �� ƽ

	float RedrawAccum = 0.f;

	/** Slate ������ RT�� �׸��� ������ */
	TSharedPtr<class FWidgetRenderer> WidgetRenderer;

private:
	/** �ڵ� ����: Tick ��� ���� Ÿ�̸� ��� */
	FTimerHandle AutoRedrawTimer;

	/** ���� ������ �ߺ� �׸��� ���� */
	uint64 LastDrawFrame = MAX_uint64;
};
