// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "BattleHUD.generated.h"

/**
 * 
 */
UCLASS()
class COMICCON_API ABattleHUD : public AHUD
{
    GENERATED_BODY()

public:
    // ����(����) UI ��Ʈ ������ ��ȯ. ������ �����ؼ� ����Ʈ�� �߰�.
    UFUNCTION(BlueprintCallable, Category = "UI")
    class UBattleWidget* GetLevelWidget();

protected:
    virtual void BeginPlay() override;

    // �����Ϳ��� ����: UBattleWidget �������Ʈ Ŭ����
    UPROPERTY(EditDefaultsOnly, Category = "UI")
    TSubclassOf<class UUserWidget> LevelWidgetClass;

    // ���� �ν��Ͻ�(������ HUD�� ����)
    UPROPERTY(Transient)
    class UBattleWidget* LevelWidgetInstance = nullptr;

    // ����Ʈ ZOrder (�ʿ��ϸ� ����)
    UPROPERTY(EditDefaultsOnly, Category = "UI")
    int32 LevelWidgetZOrder = 0;

private:
    void EnsureLevelWidgetCreated();
	
};
