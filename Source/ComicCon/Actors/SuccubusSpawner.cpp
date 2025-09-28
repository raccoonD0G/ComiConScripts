// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/SuccubusSpawner.h"
#include "Characters/Succubus.h"
#include "Kismet/GameplayStatics.h"
#include "Components/BoxComponent.h"

ASuccubusSpawner::ASuccubusSpawner()
{
    // 필요시 SpawnBoxComponent 생성/세팅이 여기 있을 수 있음
}

FTransform ASuccubusSpawner::GetSpawnTransform_Implementation()
{
    // 1) 컨트롤 포인트 구성
    BuildControlPointsRandom();

    // 2) 첫 포인트에서 스폰
    if (LatestControlPoints.Num() > 0)
    {
        const FVector SpawnLoc = LatestControlPoints[0];

        return FTransform(SpawnLoc);
    }

    // 폴백
    return Super::GetSpawnTransform_Implementation();
}

void ASuccubusSpawner::ConfigureSpawnedEnemy_Implementation(AEnemyBase* NewEnemy)
{
    Super::ConfigureSpawnedEnemy_Implementation(NewEnemy);
    if (!NewEnemy) return;

    if (ASuccubus* Succubus = Cast<ASuccubus>(NewEnemy))
    {
        // 3) Init 으로 컨트롤 포인트 전달
        Succubus->Init(LatestControlPoints);
    }
}

FVector ASuccubusSpawner::RandomPointInBoxWorld() const
{
    check(SpawnBoxComponent);

    const FTransform& Xf = SpawnBoxComponent->GetComponentTransform();
    const FVector Ext = SpawnBoxComponent->GetScaledBoxExtent(); // 월드 스케일 반영된 half-size

    const FVector Local(
        FMath::FRandRange(-Ext.X, Ext.X),
        FMath::FRandRange(-Ext.Y, Ext.Y),
        FMath::FRandRange(-Ext.Z, Ext.Z)
    );
    // Ext에 스케일을 포함했으니, 변환에서는 스케일을 다시 적용하지 않음
    return Xf.TransformPositionNoScale(Local);
}

void ASuccubusSpawner::BuildControlPointsRandom()
{
    LatestControlPoints.Reset();

    if (!SpawnBoxComponent)
        return;

    SetStartPoint();
    SetMiddlePoint();
    SetEndPoint();
    SortPoints();
}

void ASuccubusSpawner::SetStartPoint()
{
    // 박스 중심/반경
    const FVector BoxCenter = SpawnBoxComponent->GetComponentLocation();
    const FVector Ext = SpawnBoxComponent->GetUnscaledBoxExtent();

    // 플레이어 (최종 목적지 X를 정할 때 활용)
    const APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);

    // 1) 시작점: 박스 끝 중앙
    const FVector Start = FVector(BoxCenter.X + Ext.X, BoxCenter.Y, BoxCenter.Z);
    LatestControlPoints.Add(Start);

}

void ASuccubusSpawner::SetMiddlePoint()
{
    // 2) 중간 포인트들: 박스 내부 랜덤
    const int32 MidCount = FMath::Max(0, NumMidPoints);
    LatestControlPoints.Reserve(LatestControlPoints.Num() + MidCount + 1);

    for (int32 i = 0; i < MidCount; ++i)
    {
        LatestControlPoints.Add(RandomPointInBoxWorld());
    }
}

void ASuccubusSpawner::SetEndPoint()
{
    // 3) Viewport Top Edge 기반 End 계산
    APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
    const FVector BoxCenter = SpawnBoxComponent->GetComponentLocation();
    const FVector Ext = SpawnBoxComponent->GetScaledBoxExtent();

    // 1) EndX: 플레이어 X (없으면 시작점 X)
    float EndX = 0.0f;
    if (APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0))
    {
        EndX = PlayerPawn->GetActorLocation().X;
    }

    FVector End = FVector::ZeroVector;

    if (PC)
    {
        // 2) 화면 상단 에지의 두 점(좌/우)을 스크린→월드로 변환
        int32 ViewW = 0, ViewH = 0;
        PC->GetViewportSize(ViewW, ViewH);
        const float TopY = 8.f; // 화면 가장자리를 피하는 여유 px

        FVector O0, D0, O1, D1;
        PC->DeprojectScreenPositionToWorld(0.f, TopY, O0, D0);   // 좌상단
        PC->DeprojectScreenPositionToWorld((float)ViewW, TopY, O1, D1);  // 우상단

        // 3) 두 레이를 X=EndX 평면과 교차
        auto HitXPlane = [&](const FVector& O, const FVector& D)->FVector
            {
                if (FMath::Abs(D.X) < KINDA_SMALL_NUMBER)
                {
                    // 직교(정확히 평행)일 때는 O를 해당 X로 이동
                    FVector P = O; P.X = EndX;
                    return P;
                }
                const float t = (EndX - O.X) / D.X;
                return O + D * t;
            };

        const FVector TopL = HitXPlane(O0, D0);
        const FVector TopR = HitXPlane(O1, D1);

        // 4) 화면 상단 에지(TopL→TopR)에서 무작위 한 점 선택 (뷰폭 따라 Y/Z 자동 결정)
        const float U = FMath::FRand();
        FVector P = FMath::Lerp(TopL, TopR, U);

        // (선택) 스폰 박스 Y 범위로 클램프하고 싶다면:
        const float MinY = BoxCenter.Y - Ext.Y;
        const float MaxY = BoxCenter.Y + Ext.Y;
        P.Y = FMath::Clamp(P.Y, MinY, MaxY);

        // (선택) 필요하면 Z에 약간 여유 추가
        // P.Z += 0.f;

        End = P;
    }
    else
    {
        // 폴백: 기존 "박스 상단 랜덤" 로직
        const float EndY = FMath::FRandRange(BoxCenter.Y - Ext.Y, BoxCenter.Y + Ext.Y);
        const float EndZ = BoxCenter.Z + Ext.Z;
        End = FVector(EndX, EndY, EndZ);
    }

    LatestControlPoints.Add(End);
}

void ASuccubusSpawner::SortPoints()
{
    // X 방향으로 정렬(시작/끝 제외 중간만)
    if (bSortMidPointsByX && LatestControlPoints.Num() >= 3)
    {
        // [1 .. Last-1] 중간 포인트만 End.X 에 가까운 순서로 정렬 → 완만한 흐름
        TArray<FVector> Middle;
        Middle.Append(LatestControlPoints.GetData() + 1, LatestControlPoints.Num() - 2);
        Middle.StableSort([&](const FVector& A, const FVector& B) {
            return A.X > B.X; // 단순 오름차순(원하면 End.X 근접도 기반 정렬도 가능)
            });

        // 재조립
        TArray<FVector> Rebuild;
        Rebuild.Add(LatestControlPoints[0]);
        Rebuild.Append(Middle);
        Rebuild.Add(LatestControlPoints.Last());
        LatestControlPoints = MoveTemp(Rebuild);
    }
}
