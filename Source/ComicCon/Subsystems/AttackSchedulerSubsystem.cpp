// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/AttackSchedulerSubsystem.h"
#include "Characters/Succubus.h"
#include "Engine/World.h"
#include "TimerManager.h"

float UAttackSchedulerSubsystem::GetTime(const UWorld* W) const
{
	return W ? W->GetTimeSeconds() : 0.f;
}

void UAttackSchedulerSubsystem::GC(const UWorld* W)
{
	const float Now = GetTime(W);

	// Active ����
	for (int32 i = Active.Num() - 1; i >= 0; --i)
	{
		if (!Active[i].Who.IsValid())
			Active.RemoveAtSwap(i);
	}

	// Pending ����/��ȿ ����
	for (int32 i = Pending.Num() - 1; i >= 0; --i)
	{
		if (!Pending[i].Who.IsValid() || Pending[i].ExpireAt < Now)
			Pending.RemoveAtSwap(i);
	}
}

FAttackReservation UAttackSchedulerSubsystem::TryReserve(ASuccubus* Who, float PreferredStart)
{
	FAttackReservation Out;
	if (!Who || !GetWorld()) return Out;
	GC(GetWorld());

	const float Now = GetTime(GetWorld());

	// 1) ������� �����ٵ� "���� ������ ���۽ð�"�� ���
	float LastScheduled = LastAttackStartTime;           // ���� ������ ������ �ð�
	for (const FPending& P : Pending)                    // �̹� ����� ���۽ð��� ���!
		LastScheduled = FMath::Max(LastScheduled, P.StartTime);

	// 2) ���ð��� ���� ���: Active�� �̹� �ѵ���, ���� ������ LastScheduled ���ķθ� ����
	const bool bCapacityFull = (Active.Num() >= MaxConcurrentAttacks);

	// 3) �ּ� ������ ��ο��� ���� (Pending ������ ����ȭ)
	const float Earliest = FMath::Max3(Now, PreferredStart, LastScheduled + MinStartSpacing);

	Out.bGranted = true;
	Out.TicketId = NextTicketId++;
	Out.StartTime = bCapacityFull ? Earliest : FMath::Max(Earliest, Now);

	// ���� ���ڵ�
	FPending Q;
	Q.Who = Who;
	Q.TicketId = Out.TicketId;
	Q.StartTime = Out.StartTime;
	Q.ExpireAt = Out.StartTime + ReservationTTL;
	Pending.Add(Q);

	return Out;
}

void UAttackSchedulerSubsystem::NotifyAttackStarted(int32 TicketId, ASuccubus* Who)
{
	if (!GetWorld()) return;
	GC(GetWorld());

	// Pending ���� TicketId�� ã�� Active �� �°�
	for (int32 i = 0; i < Pending.Num(); ++i)
	{
		if (Pending[i].TicketId == TicketId)
		{
			FActive A;
			A.TicketId = TicketId;
			A.Who = Who;
			Active.Add(A);

			LastAttackStartTime = GetTime(GetWorld());
			Pending.RemoveAtSwap(i);
			return;
		}
	}
}

void UAttackSchedulerSubsystem::NotifyAttackEnded(int32 TicketId, ASuccubus* Who)
{
	for (int32 i = Active.Num() - 1; i >= 0; --i)
	{
		if (Active[i].TicketId == TicketId)
		{
			Active.RemoveAtSwap(i);
			break;
		}
	}
	GC(GetWorld());
}

void UAttackSchedulerSubsystem::CancelReservation(int32 TicketId)
{
	for (int32 i = Pending.Num() - 1; i >= 0; --i)
	{
		if (Pending[i].TicketId == TicketId)
		{
			Pending.RemoveAtSwap(i);
			return;
		}
	}
	// �̹� Active�� End ó��
	for (int32 i = Active.Num() - 1; i >= 0; --i)
	{
		if (Active[i].TicketId == TicketId)
		{
			Active.RemoveAtSwap(i);
			return;
		}
	}
}
