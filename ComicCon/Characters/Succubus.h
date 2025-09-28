// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/EnemyBase.h"
#include "Succubus.generated.h"

UENUM()
enum class ESuccubusState
{
    Move,
    Stop,
    Attack,
    Die,
};

struct FLUTEntry
{
    float T;
    float S;
};

/**
 * 
 */
UCLASS()
class COMICCON_API ASuccubus : public AEnemyBase
{
    GENERATED_BODY()

public:
	ASuccubus();
    void Init(const TArray<FVector>& InPoints);

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaSeconds) override;
    virtual bool IsTargetInAttackRange() const override;

// State Section
public:
    FORCEINLINE ESuccubusState GetCurrentState() const { return CurrentState; }

private:
	UPROPERTY(VisibleInstanceOnly)
	ESuccubusState CurrentState;

	void SetCurrentState(ESuccubusState NewState);

    void OnMove(float DeltaSeconds);
	void OnStop(float DeltaSeconds);
	void OnAttack(float DeltaSeconds);
	void OnDie(float DeltaSeconds);

// Move Section
private:
    UFUNCTION()
    void OnMovingDone();

    UPROPERTY(VisibleAnywhere)
    TArray<FVector> ControlPoints;

    // 이동
    UPROPERTY(EditAnywhere, Category = "Succubus|Move")
    float MoveSpeed = 300.0f;    // uu/s

    UPROPERTY(EditAnywhere, Category = "Visual|Opacity")
    float MoveOpacity = 0.0f;   // Move일 때 거의 투명

    UPROPERTY(EditAnywhere, Category = "Visual|Opacity")
    float StopOpacity = 0.8f;    // Stop일 때 완전 불투명

    UPROPERTY(EditAnywhere, Category = "Visual|Opacity")
    float AttackOpacity = 0.95f;

    // 이동 보간/길이 LUT
    UPROPERTY(EditAnywhere, Category = "Succubus|Move")
    float SpeedInterpRate = 3.0f;      // 가속/감속 반응 속도(값↑ 더 빠르게 목표속도에 수렴)

    UPROPERTY(EditAnywhere, Category = "Visibility|Speed")
    float TransparentSpeedScale = 0.25f; // 완전 투명일 때 최소 속도 배율

    UPROPERTY(EditAnywhere, Category = "Succubus|Move")
    float LUTStepT = 0.01f;            // 0~1 구간 샘플 간격(작을수록 정밀)

    float CurrentSpeed = 0.f;          // 현재 uu/s
    float Traveled = 0.f;              // 누적 이동 거리(uu)
    float TotalLen = 0.f;              // 곡선 총 길이(uu)

    TArray<FLUTEntry> ArcLUT;

    void   BuildArcLUT();              // ArcLUT, TotalLen 구성
    float  FindTForDistance(float S) const; // s(거리) → t(파라미터) 역탐색
    void ResyncTraveledFromActorPos();

// Animation Section
private:
	UPROPERTY(EditAnywhere, Category = "Animation")
	TObjectPtr<class UPaperFlipbook> MoveFlipbook = nullptr;

    UPROPERTY(EditAnywhere, Category = "Animation")
	TObjectPtr<class UPaperFlipbook> StopFlipbook = nullptr;

    UPROPERTY(EditAnywhere, Category = "Animation")
    TObjectPtr<class UPaperFlipbook> ReadyAttackFlipbook = nullptr;

	UPROPERTY(EditAnywhere, Category = "Animation")
	TObjectPtr<class UPaperFlipbook> DieFlipbook = nullptr;

// Battle Section
protected:
    virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	virtual void StartDie() override;
    virtual void EndDie() override;

	virtual void EndAttack() override;
// Timer Section
private:
    FTimerHandle MoveTimerHandle;
    FTimerHandle StopTimerHandle;

    // 전이 스케줄링
    void ScheduleNextStop();  // Move 상태일 때 Stop 으로 넘어가도록 예약
    void ScheduleNextMoveOrAttack();  // Stop 상태일 때 Move 로 넘어가도록 예약

    void DoStop();
    void DoMove();
    void DoAttack();

    // 전환 시간 범위
    UPROPERTY(EditAnywhere, Category = "Succubus|Timing")
    FVector2D MoveDurationRange = FVector2D(0.5f, 1.5f);

    UPROPERTY(EditAnywhere, Category = "Succubus|Timing")
    FVector2D StopDurationRange = FVector2D(0.3f, 1.0f);

// Player Section
private:
    // 동적 최종점 추적용 캐시
    TArray<FVector> BaseControlPoints;      // Init 시 원본(마지막점 포함)
    FVector         CachedEndBase = FVector::ZeroVector;   // Init 당시 마지막 점
    TWeakObjectPtr<APawn> PlayerRef;        // 플레이어 참조
    FVector         PlayerStartLoc = FVector::ZeroVector;  // Init 당시 플레이어 위치
    FVector         LastAppliedDisplacement = FVector::ZeroVector;

    UPROPERTY(EditAnywhere, Category = "Succubus|Move")
    float EndUpdateThreshold = 5.f;         // 최종점 갱신 임계치(uu)

    // 재빌드 시 진행도 보존용
    float CachedTOnRebuild = 0.f;

    void UpdateDynamicEndIfNeeded();

// Sound Section
private:
    void PlayStopSound();

    UPROPERTY(EditAnywhere, Category = "Audio")
    TArray<TObjectPtr<class USoundBase>> StopSounds;

// Attack Scheduling Section
private:
    FTimerHandle AttackStartTimer;
    int32 AttackTicketId = INDEX_NONE;
    bool   bHasAttackReservation = false;
    bool bAttackStartSignaled = false;

    // 공격 예약/취소 유틸
    void TryScheduleAttack();     // Stop 상태에서 호출: 사거리면 공격 예약 시도
    void OnReservedAttackTimeReached(); // 예약된 시각 도달 -> 실제 Attack 진입
    void CancelAttackReservation();
};
