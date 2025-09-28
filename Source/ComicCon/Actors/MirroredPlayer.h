// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MirroredPlayer.generated.h"

UENUM(BlueprintType)
enum class EWeaponState
{
	Sword,
	Amulet
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCurrentWeaponChanged, EWeaponState, NewWeapon);

UCLASS()
class COMICCON_API AMirroredPlayer : public AActor
{
	GENERATED_BODY()
	
public:
	AMirroredPlayer();
	virtual void Tick(float DeltaSeconds) override;

public:
	FORCEINLINE class UPoseUdpReceiverComponent* GetPoseReceiver() { return PoseReceiver; }
	FORCEINLINE class USingleSwingClassifierComponent* GetLeftSingleSwingClassifierComponent() { return LeftSingleSwingClassifierComponent; }
	FORCEINLINE class USingleSwingClassifierComponent* GetRightSingleSwingClassifierComponent() { return RightSingleSwingClassifierComponent; }

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USceneComponent> SceneComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UPoseUdpReceiverComponent> PoseReceiver;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class USingleSwingClassifierComponent> LeftSingleSwingClassifierComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class USingleSwingClassifierComponent> RightSingleSwingClassifierComponent;
};
