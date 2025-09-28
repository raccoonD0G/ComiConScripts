// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/Weapon.h"
#include "Amulet.generated.h"

/**
 * 
 */
UCLASS()
class COMICCON_API AAmulet : public AWeapon
{
	GENERATED_BODY()

public:
	AAmulet();
    void SetOwingSingleSwingClassifierComponent(class USingleSwingClassifierComponent* InSingleSwingClassifierComponent);

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
    TObjectPtr<class USingleSwingClassifierComponent> SingleSwingClassifierComponent;

// Follow Pose Section
private:
	// ---- ���ε� ----
    UFUNCTION()
    void OnPoseInput(const FVector2f& Pelvis2D, const TArray<FPersonPose>& Poses, float PixelToUU, const FTransform& OwnerXform);

    // ---- ���� ó�� ----
    void SetAmuletPose(const FVector& CenterWorld);

    // ���� ���� ���� ���� ���: �����ϸ� OutPoint ��ȯ
    bool TryComputeExtendedPoint(const FVector2f& Pelvis2D, const FPersonPose& Pose, const FTransform& OwnerXform, bool bRightHand, FVector& OutPoint, float* OutScore = nullptr) const;

    // Ʃ��: ���� ������ �� %�� �ո� �ٱ�����
    UPROPERTY(EditAnywhere, Category = "Amulet|Pose")
    float ExtendRatio = 0.15f;

// Attack Section
private:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
    TSubclassOf<class AAmuletAttack> AmuletAttackClass;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
    uint8 bDoDebug : 1 = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
    float SingleSwingDamageAmount = 2.f;

    UPROPERTY(EditAnywhere)
    float AttackLifeSeconds = 1.f;

    UFUNCTION()
    void HandleSingleSwingDetected(TArray<FTimedPoseSnapshot> Snaps, TArray<int32> PersonIdxOf, EHandSide InHandSide, int32 EnterIdx, int32 ExitIdx);

};
