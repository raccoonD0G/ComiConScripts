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
	float StartTime = 0.f;   // 예약된 공격 시작 게임시간(초)

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
	// 설정 값
	UPROPERTY(EditAnywhere, Category = "Scheduler")
	int32 MaxConcurrentAttacks = 1;           // 동시에 공격할 수 있는 서큐버스 수
	UPROPERTY(EditAnywhere, Category = "Scheduler")
	float MinStartSpacing = 4.0f;             // '공격 시작' 간 최소 간격(초)
	UPROPERTY(EditAnywhere, Category = "Scheduler")
	float ReservationTTL = 10.0f;              // 예약 후 시작까지 허용 최대 지연(초) (만료시 무효)

	// 예약 시도: 선호시각(PreferredStart)을 기준으로 시작시각을 배정
	FAttackReservation TryReserve(class ASuccubus* Who, float PreferredStart);

	// Attack 상태 실제 시작/종료 통지 (동시공격/간격 관리를 위해 필요)
	void NotifyAttackStarted(int32 TicketId, class ASuccubus* Who);
	void NotifyAttackEnded(int32 TicketId, class ASuccubus* Who);

	// 강제 취소(사망, 디스폰 등)
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
		float ExpireAt = 0.f; // 게임시간: 예약 만료
	};

	int32 NextTicketId = 1;
	TArray<FActive> Active;     // 현재 Attack 중
	TArray<FPending> Pending;   // Attack 시작 대기(예약)

	float GetTime(const UWorld* W) const;

	// 유효성 정리(만료된 예약, null 등)
	void GC(const UWorld* W);
	// 직전 '공격 시작' 시각을 추적하여 MinStartSpacing 강제
	float LastAttackStartTime = -FLT_MAX;
	
};
