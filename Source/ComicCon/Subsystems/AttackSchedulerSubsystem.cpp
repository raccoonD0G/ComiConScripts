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

	// Active 정리
	for (int32 i = Active.Num() - 1; i >= 0; --i)
	{
		if (!Active[i].Who.IsValid())
			Active.RemoveAtSwap(i);
	}

	// Pending 만료/무효 정리
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

	// 1) 현재까지 스케줄된 "가장 마지막 시작시각"을 계산
	float LastScheduled = LastAttackStartTime;           // 실제 시작한 마지막 시각
	for (const FPending& P : Pending)                    // 이미 예약된 시작시각도 고려!
		LastScheduled = FMath::Max(LastScheduled, P.StartTime);

	// 2) 동시공격 상한 고려: Active가 이미 한도면, 다음 슬롯은 LastScheduled 이후로만 가능
	const bool bCapacityFull = (Active.Num() >= MaxConcurrentAttacks);

	// 3) 최소 간격을 모두에게 적용 (Pending 포함한 직렬화)
	const float Earliest = FMath::Max3(Now, PreferredStart, LastScheduled + MinStartSpacing);

	Out.bGranted = true;
	Out.TicketId = NextTicketId++;
	Out.StartTime = bCapacityFull ? Earliest : FMath::Max(Earliest, Now);

	// 예약 레코드
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

	// Pending 에서 TicketId를 찾아 Active 로 승격
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
	// 이미 Active면 End 처리
	for (int32 i = Active.Num() - 1; i >= 0; --i)
	{
		if (Active[i].TicketId == TicketId)
		{
			Active.RemoveAtSwap(i);
			return;
		}
	}
}
