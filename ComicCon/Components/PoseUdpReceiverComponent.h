// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Global/UdpStruct.h"
#include "PoseUdpReceiverComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnPoseBufferChanged, const FVector2f&, Anchor2D, const TArray<FPersonPose>&, Poses, float, PixelToUU, const FTransform&, OwnerXform);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnHandBufferChanged, const FVector2f&, Anchor2D, const TArray<FHandPose>&, Hands, float, PixelToUU, const FTransform&, OwnerXform);

// 포맷 버전
enum : uint8 { POSE_VERSION_V1 = 1, POSE_VERSION_V2 = 2 };

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COMICCON_API UPoseUdpReceiverComponent : public UActorComponent
{
	GENERATED_BODY()

public:
    UPoseUdpReceiverComponent();

public:
    virtual void BeginPlay() override;
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
        const TArray<FPersonPose>& GetLatestPoses() const { return LatestPoses; }
    const TArray<FHandPose>& GetLatestHands() const { return LatestHands; }
        FORCEINLINE float GetPixelToUU() const { return PixelToUU; }
        FORCEINLINE float GetDepthOffsetX() const { return DepthOffsetX; }
    FORCEINLINE bool GetInvertImageYToUp() const { return bInvertImageYToUp; }
    uint64 GetLatestTimestamp() const { return LatestTimestamp; }
    bool GetShoulderMidWorld(FVector& OutMidWorld) const;
    FVector SampleToWorld(const FVector2f& P2D) const;
    FVector MakeLocalFrom2D(const FVector2f& P, const FVector2f& Origin2D) const;

    UFUNCTION(BlueprintCallable, Category = "Pose")
    void SetFrameSize(FIntPoint InFrameSize);

    UFUNCTION(BlueprintPure, Category = "Pose")
    FIntPoint GetFrameSize() const { return FrameSize; }

private:
    FSocket* Socket = nullptr;
    TArray<uint8> RecvBuffer;

    TArray<FPersonPose> LatestPoses;
    TArray<FHandPose> LatestHands;

    uint64 LatestTimestamp = 0;

    UPROPERTY(EditAnywhere)
    float PixelToUU = 1.0f; // 픽셀→언리얼 유닛 스케일
    float DepthOffsetX = 0.f; // 액터 로컬 X(전방)으로 살짝 띄우기

    UPROPERTY(EditAnywhere, Category = "Pose", meta = (ClampMin = "1", UIMin = "1"))
    FIntPoint FrameSize = FIntPoint(1080, 1920);

    // 시각화 파라미터
    const float LineThickness = 2.f;
    const float PointRadius = 5.0f;
    const FColor LineColor = FColor::Yellow;
    const FColor PointColor = FColor::White;
    FVector2f FrameOrigin2D = FVector2f::ZeroVector;

    UPROPERTY(EditAnywhere, Category = "Pose")
    uint8 bInvertImageYToUp : 1 = true;

    bool InitSocket(int32 Port = 7777);
    void CloseSocket();
    void RefreshFrameOrigin();
    bool ReceiveOnce(TArray<FPersonPose>& OutPoses, TArray<FHandPose>& OutHands, uint64& OutTsMs);

// Weapon Section
public:
    FOnPoseBufferChanged OnPoseBufferChanged;

    FOnHandBufferChanged OnHandBufferChanged;

// Debug Section
public:
    UPROPERTY(EditAnywhere, Category = "Debug")
	uint8 bDrawDebug : 1 = false;

};
