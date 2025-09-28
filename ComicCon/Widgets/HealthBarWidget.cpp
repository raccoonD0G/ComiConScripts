// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/HealthBarWidget.h"
#include "Components/ProgressBar.h"
#include "Characters/EnemyBase.h"
#include "PaperCharacter.h"
#include "PaperFlipbookComponent.h"

void UHealthBarWidget::Init()
{
	Super::Init();

	AEnemyBase* EnemyBase = Cast<AEnemyBase>(GetOwningActor());
	if (EnemyBase)
	{
		EnemyBase->OnHealthChanged.AddDynamic(this, &UHealthBarWidget::OnHealthChanged);
		OnHealthChanged(EnemyBase->GetMaxHealth(), EnemyBase->GetCurrentHealth());
	}
}

void UHealthBarWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
    Super::NativeTick(MyGeometry, InDeltaTime);

    // OwningActor가 없을 수도 있으니 보조 경로로 OwningPlayerPawn도 시도
    APaperCharacter* PaperCharacter = Cast<APaperCharacter>(GetOwningActor());

    float NewOpacity = 1.0f;

    if (PaperCharacter)
    {
        if (UPaperFlipbookComponent* Sprite = PaperCharacter->GetSprite())
        {
            // 스프라이트가 비활성화면 위젯도 숨김
            if (!Sprite->IsVisible())
            {
                NewOpacity = 0.0f;
            }
            else
            {
                // 스프라이트 색상의 Alpha를 위젯 RenderOpacity로 사용
                const FLinearColor Tint = Sprite->GetSpriteColor(); // (PaperFlipbookComponent API)
                NewOpacity = FMath::Clamp(Tint.A, 0.0f, 1.0f);
            }
        }
    }

    // 위젯 전체 투명도 적용
    SetRenderOpacity(NewOpacity);
}


void UHealthBarWidget::OnHealthChanged(int32 MaxHealth, int32 CurrentHealth)
{
	SetHealthPercent((float)CurrentHealth / (float)MaxHealth);
}

void UHealthBarWidget::SetHealthPercent(float Percent)
{
	if (HealthBar)
	{
		HealthBar->SetPercent(FMath::Clamp(Percent, 0.0f, 1.0f));
	}
}