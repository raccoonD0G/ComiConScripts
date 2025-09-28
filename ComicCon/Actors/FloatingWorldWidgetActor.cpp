// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/FloatingWorldWidgetActor.h"
#include "Components/WidgetComponent.h"
#include "Blueprint/UserWidget.h"
#include "Interfaces/ScoreDisplayInterface.h"

AFloatingWorldWidgetActor::AFloatingWorldWidgetActor()
{
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SetRootComponent(Root);

	WidgetComp = CreateDefaultSubobject<UWidgetComponent>(TEXT("WidgetComp"));
	WidgetComp->SetupAttachment(Root);

	WidgetComp->SetWidgetSpace(EWidgetSpace::Screen);
	// WidgetComp->SetDrawAtDesiredSize(true);
	// WidgetComp->SetTwoSided(true);
	// WidgetComp->SetPivot(FVector2D(0.5f, 0.5f));  // 중앙 정렬
	// WidgetComp->SetBlendMode(EWidgetBlendMode::Transparent);
	// WidgetComp->SetTickWhenOffscreen(true);
	// WidgetComp->SetReceiveHardwareInput(false);
}

void AFloatingWorldWidgetActor::InitFloatingImage(UTexture2D* InTexture, const FLinearColor& InTint, float InLifeTime, float InRiseSpeed)
{
	CachedTexture = InTexture;
	InitialColor = InTint;
	LifeTime = (InLifeTime > 0.f) ? InLifeTime : 1.2f;
	RiseSpeed = (InRiseSpeed > 0.f) ? InRiseSpeed : 120.f;

	// 위젯 오브젝트 확보
	if (UUserWidget* UW = Cast<UUserWidget>(WidgetComp->GetUserWidgetObject()))
	{
		CachedUserWidgetObj = UW;

		if (UW->GetClass()->ImplementsInterface(UScoreDisplayInterface::StaticClass()))
		{
			IScoreDisplayInterface::Execute_SetImageAndColor(UW, CachedTexture, InitialColor);
			IScoreDisplayInterface::Execute_UpdateOpacity(UW, 1.f);
		}
		else
		{
			// 인터페이스가 없으면 최소한 전체 불투명으로 시작
			UW->SetRenderOpacity(1.f);
		}
	}

	bInitialized = true;
}

void AFloatingWorldWidgetActor::BeginPlay()
{
	Super::BeginPlay();
}

void AFloatingWorldWidgetActor::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (!bInitialized) return;

	Elapsed += DeltaSeconds;

	// 위로 서서히 상승
	AddActorWorldOffset(FVector(0.f, 0.f, RiseSpeed * DeltaSeconds));

	// 1 -> 0으로 줄어드는 알파 계산
	float T = FMath::Clamp(Elapsed / FMath::Max(LifeTime, KINDA_SMALL_NUMBER), 0.f, 1.f);
	float Opacity = 1.f - T;
	if (FadeCurve)
	{
		// 커브가 0~1 입력일 때, 반환값을 (보통 1->0 형태)로 쓰도록 설계했다고 가정
		Opacity = FMath::Clamp(FadeCurve->GetFloatValue(T), 0.f, 1.f);
	}

	// 위젯에 반영
	if (UUserWidget* UW = Cast<UUserWidget>(CachedUserWidgetObj))
	{
		if (UW->GetClass()->ImplementsInterface(UScoreDisplayInterface::StaticClass()))
		{
			IScoreDisplayInterface::Execute_UpdateOpacity(UW, Opacity);
		}
		else
		{
			UW->SetRenderOpacity(Opacity);
		}
	}

	// 종료
	if (Elapsed >= LifeTime)
	{
		Destroy();
	}
}
