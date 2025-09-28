// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PoseClassifierComponent.h"
#include "HandPoseClassifierComponent.generated.h"

UENUM(BlueprintType)
enum class EHandSide : uint8
{
    Right  UMETA(DisplayName = "Right"),
    Left   UMETA(DisplayName = "Left"),
};

USTRUCT(BlueprintType)
struct FHandSample
{
    GENERATED_BODY()

    double    T = 0.0;
    FVector2D L = FVector2D::ZeroVector;
    FVector2D R = FVector2D::ZeroVector;
    FVector2D C = FVector2D::ZeroVector;
    float     ShoulderW = 0.f;
};

USTRUCT(BlueprintType)
struct FHandMetrics
{
    GENERATED_BODY()

    double Peak = 0.0;
    double Avg = 0.0;
};

/**
 * 
 */
UCLASS()
class COMICCON_API UHandPoseClassifierComponent : public UPoseClassifierComponent
{
	GENERATED_BODY()

// Hand Section
public:
    FORCEINLINE EHandSide GetCurrentHandSide() const { return CurrentHandSide; }
    FORCEINLINE void SetCurrentHandSide(EHandSide NewHand) { CurrentHandSide = NewHand; }

protected:
    /// <brief>Hands ��Ͽ��� Ư�� ���/�տ� �ش��ϴ� �� �߽� ��ǥ�� ã��, ���� �� �ո� ��ó �ĺ��� �����Ͽ� ���� ����� ���� �����մϴ�.</brief>
    /// <param name="Hands">������ �� ���� ����Ʈ.</param>
    /// <param name="PersonId">��� ��� ID.</param>
    /// <param name="Which">�� ����(0=Left, 1=Right, 2=Unknown ���).</param>
    /// <param name="FallbackNearTo">���� �� ������ ��꿡 ����� ������(���� �ո� ��ǥ).</param>
    /// <param name="OutCenter">���õ� ���� �߽� ��ǥ(���� �� ����).</param>
    /// <return>��ȿ�� ���� ã���� true, �ƴϸ� false.</return>
    /// <details>
    /// ���� ��Ģ(��ȿ ��ǥ�� ���):
    /// 1) PersonId & Which ���� ��ġ �׸��� �켱 ����.
    /// 2) ������ ���� PersonId ������ FallbackNearTo�� ���� ����� ���� ����(Which ����/Unknown ���).
    /// 3) �׷��� ������ ��ü Hands �� FallbackNearTo�� ���� ����� ���� ����.
    /// � �ܰ迡���� �ĺ��� ������ false�� ��ȯ�մϴ�.
    /// �Ÿ� ����� 2D ��Ŭ���� �Ÿ��̸�, ��ǥ�� ����(NaN/Inf �ƴ�)�� ��츸 ����˴ϴ�.
    /// </details>
    bool FindHandFor(const TArray<FHandPose>& Hands, uint16 PersonId, uint8 Which, const FVector2f& FallbackNearTo, FVector2D& OutCenter) const;

    /// <brief>���� �ð迭���� ���� ��(��/��)�� ����ȭ �ӵ� ��Ʈ��(�ִ�/���)�� ����մϴ�.</brief>
    /// <param name="U">������/�������� ���� �ð迭 ����(�ð� ��������).</param>
    /// <param name="MeanSW">����ȭ �и�� ����� ��� �����(>0 ����).</param>
    /// <param name="bLeft">true=�޼� ����, false=������ ����.</param>
    /// <return>FHandMetrics { Peak, Avg }.</return>
    /// <details>
    /// v_i = |p_i - p_{i-1}| / KFixedDt / MeanSW �� �� ������ �ӵ��� ����ϰ�,
    /// �� �� �ִ�(Peak)�� �ð� ���(Avg)�� ��ȯ�մϴ�. Open/Close ����Ʈ�� ������� �ʽ��ϴ�.
    /// �Է��� KFixedDt �������� ���ĵǾ� �ִٰ� �����մϴ�.
    /// </details>
    // FHandMetrics CalcMetrics(const TArray<FHandSample>& U, double MeanSW, bool bLeft) const;

    /// <brief>���õ� ��(������/�޼�)�� i��° �ո� ��ǥ�� ��ȯ�մϴ�.</brief>
    /// <param name="U">���� �ð迭 ����.</param>
    /// <param name="bRight">true=������, false=�޼�.</param>
    /// <param name="i">�ε���(0 �� i &lt; U.Num()).</param>
    /// <return>U[i].R �Ǵ� U[i].L.</return>
    /// <details>ȣ�� ������ ��ȿ �ε����� �����ؾ� �մϴ�.</details>
    FORCEINLINE FVector2D WristAt(const TArray<FHandSample>& U, int i) const{ return GetCurrentHandSide() == EHandSide::Right ? U[i].R : U[i].L; }

    /// <brief>L/R/C ��ǥ�� ���������̵����(EMA)�� ���÷��̽��� �����մϴ�.</brief>
    /// <param name="U">���� �ð迭 ����(�ð� ��������). L/R/C�� �� �Լ� ������ ���ŵ˴ϴ�.</param>
    /// <return>����.</return>
    /// <details>
    /// ���� ������ Alpha=1.0�� ȿ���� ������ �����Ǿ� �ֽ��ϴ�. �������� �ʿ��ϸ� Alpha�� ���߼���(��: 0.2~0.5).
    /// ShoulderW���� EMA�� �������� �ʽ��ϴ�.
    /// </details>
    void ApplyEMA(TArray<FHandSample>& U) const; // ����=1.0 (���� �ڵ� ����)

    /// <brief>���� ���� ������ KFixedHz(��: 30Hz) ���� �ð迭�� ���� �����մϴ�.</brief>
    /// <param name="In">���� ����(�ð� ��������, 2�� �̻�).</param>
    /// <return>���(KFixedDt)�� �� ���� �迭.</return>
    /// <details>
    /// ��� �ð� t = t0 + i*KFixedDt. �� ����(T, L, R, C, ShoulderW)�� j,k ������ ���̿��� ���� �����մϴ�.
    /// ū �ҿ��� ���������� ������ ������ �� �����Ƿ� ���� �ƿ����̾� ���Ÿ� �����մϴ�.
    /// </details>
    TArray<FHandSample> ResampleUniform(const TArray<FHandSample>& In) const;

    /// <brief>U[Ui].T�� ���� ����� ���� ������ �ð� �ε����� ��ȯ�մϴ�.</brief>
    /// <param name="SnapTimes">���� ������ �ð�(��) �迭, ��������.</param>
    /// <param name="U">���� �ð迭 ���� �迭(��������).</param>
    /// <param name="Ui">������ U�� �ε���(0 �� Ui &lt; U.Num()).</param>
    /// <param name="Cursor">���� ���� Ŀ��(����). ���� ȣ�� �� �����Ͽ� ���� �ð����� ó��.</param>
    /// <return>�ֱ��� �������� �ε���.</return>
    /// <details>
    /// �� ������ ������� SnapTimes[Cursor] �� t &lt; SnapTimes[Cursor+1]�� �����,
    /// ���� �ĺ� �� t�� �� ����� ���� �����մϴ�. ��迡���� �ڵ����� 0 �Ǵ� ������ �ε����� Ŭ�����˴ϴ�.
    /// </details>
    int MapUToSnapIndex(const TArray<double>& SnapTimes, const TArray<FHandSample>& U, int Ui, int& Cursor) const;

private:
    // ��� ���� �������
    UPROPERTY(EditAnywhere, Category = "Pose")
    EHandSide CurrentHandSide = EHandSide::Right;
};
