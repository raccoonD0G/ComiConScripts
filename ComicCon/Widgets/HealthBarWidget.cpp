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

    // OwningActor�� ���� ���� ������ ���� ��η� OwningPlayerPawn�� �õ�
    APaperCharacter* PaperCharacter = Cast<APaperCharacter>(GetOwningActor());

    float NewOpacity = 1.0f;

    if (PaperCharacter)
    {
        if (UPaperFlipbookComponent* Sprite = PaperCharacter->GetSprite())
        {
            // ��������Ʈ�� ��Ȱ��ȭ�� ������ ����
            if (!Sprite->IsVisible())
            {
                NewOpacity = 0.0f;
            }
            else
            {
                // ��������Ʈ ������ Alpha�� ���� RenderOpacity�� ���
                const FLinearColor Tint = Sprite->GetSpriteColor(); // (PaperFlipbookComponent API)
                NewOpacity = FMath::Clamp(Tint.A, 0.0f, 1.0f);
            }
        }
    }

    // ���� ��ü ���� ����
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