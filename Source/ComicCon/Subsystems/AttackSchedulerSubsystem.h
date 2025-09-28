// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AttackSchedulerSubsystem.generated.h"

USTRUCT()
struct FAttackReservation
{
	GENERATED_BODY()

	UPROPERTY()
	bool bGranted = false;

	UPROPERTY()
	float StartTime = 0.f;   // ����� ���� ���� ���ӽð�(��)

	UPROPERTY()
	int32 TicketId = INDEX_NONE;
};

/**
 * 
 */
UCLASS()
class COMICCON_API UAttackSchedulerSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	// ���� ��
	UPROPERTY(EditAnywhere, Category = "Scheduler")
	int32 MaxConcurrentAttacks = 1;           // ���ÿ� ������ �� �ִ� ��ť���� ��
	UPROPERTY(EditAnywhere, Category = "Scheduler")
	float MinStartSpacing = 4.0f;             // '���� ����' �� �ּ� ����(��)
	UPROPERTY(EditAnywhere, Category = "Scheduler")
	float ReservationTTL = 10.0f;              // ���� �� ���۱��� ��� �ִ� ����(��) (����� ��ȿ)

	// ���� �õ�: ��ȣ�ð�(PreferredStart)�� �������� ���۽ð��� ����
	FAttackReservation TryReserve(class ASuccubus* Who, float PreferredStart);

	// Attack ���� ���� ����/���� ���� (���ð���/���� ������ ���� �ʿ�)
	void NotifyAttackStarted(int32 TicketId, class ASuccubus* Who);
	void NotifyAttackEnded(int32 TicketId, class ASuccubus* Who);

	// ���� ���(���, ���� ��)
	void CancelReservation(int32 TicketId);

private:
	struct FActive
	{
		TWeakObjectPtr<class ASuccubus> Who;
		int32 TicketId = INDEX_NONE;
	};
	struct FPending
	{
		TWeakObjectPtr<class ASuccubus> Who;
		int32 TicketId = INDEX_NONE;
		float StartTime = 0.f;
		float ExpireAt = 0.f; // ���ӽð�: ���� ����
	};

	int32 NextTicketId = 1;
	TArray<FActive> Active;     // ���� Attack ��
	TArray<FPending> Pending;   // Attack ���� ���(����)

	float GetTime(const UWorld* W) const;

	// ��ȿ�� ����(����� ����, null ��)
	void GC(const UWorld* W);
	// ���� '���� ����' �ð��� �����Ͽ� MinStartSpacing ����
	float LastAttackStartTime = -FLT_MAX;
	
};
