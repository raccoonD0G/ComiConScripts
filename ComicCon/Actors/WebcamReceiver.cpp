// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/WebcamReceiver.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"          // GEngine
#include "Engine/World.h"           // GetWorld()
#include "Misc/OutputDeviceNull.h"  // �α׿�
#include "Materials/MaterialInstanceDynamic.h"
#include "Materials/MaterialInstance.h"
#include "Materials/MaterialInterface.h"
#include "SaveGames/BoothSave.h"
#include "SaveGames/GameSaveConstants.h"

AWebcamReceiver::AWebcamReceiver()
{
	PrimaryActorTick.bCanEverTick = false;

	ClampVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("ClampVolume"));
	ClampVolume->SetupAttachment(RootComponent);
	ClampVolume->SetBoxExtent(FVector(92.0f, 100.0f, 540.0f));
	ClampVolume->SetCollisionProfileName(TEXT("NoCollision"));

	// �׻� �ð�ȭ �ǵ��� ����
	// ClampVolume->SetHiddenInGame(false);     // ���� �߿��� ���̰�
	// ClampVolume->ShapeColor = FColor::Green; // ������ �信�� ���̾������� ����
}

UBoxComponent* AWebcamReceiver::GetClampVolume() const
{
	return ClampVolume;
}

void AWebcamReceiver::BeginPlay()
{
    Super::BeginPlay();

    if (!IsValid(VideoMeshComponent))
    {
        UE_LOG(LogTemp, Error, TEXT("[WebcamReceiver] VideoMeshComponent is null"));
        return;
    }

    const int32 MatIndex = 0;

    // 1) ���� ���Կ� �����ִ� ��Ƽ���󿡼� MID�� '�������ų�' ������ '�����'
    VideoMaterialInstance = Cast<UMaterialInstanceDynamic>(VideoMeshComponent->GetMaterial(MatIndex));
    if (!IsValid(VideoMaterialInstance))
    {
        if (!IsValid(VideoMaterial))
        {
            UE_LOG(LogTemp, Error, TEXT("[WebcamReceiver] No MID on mesh and VideoMaterial(base) is null"));
            return;
        }
        VideoMaterialInstance =
            VideoMeshComponent->CreateAndSetMaterialInstanceDynamicFromMaterial(MatIndex, VideoMaterial);
        UE_LOG(LogTemp, Log, TEXT("[WebcamReceiver] Created new MID and set on slot %d"), MatIndex);
    }
    else
    {
        UE_LOG(LogTemp, Log, TEXT("[WebcamReceiver] Reusing existing MID from slot %d"), MatIndex);
    }

    // 2) NDI ���/���ĸ� ���̰� �ϴ� ���(��Ƽ���� ���� �����ϴ� �̸��� �״�� ���)
    VideoMaterialInstance->SetScalarParameterValue(TEXT("Enable Video Texture"), 1.0f);
    VideoMaterialInstance->SetScalarParameterValue(TEXT("Enable Video Alpha"), 1.0f);
    // �ʿ� �� ���� �̸����� ����
    VideoMaterialInstance->SetScalarParameterValue(TEXT("Alpha Preview"), 0.0f);

    // 3) ���̺� �ε�
    UBoothSave* LoadedSave = nullptr;
    if (UGameplayStatics::DoesSaveGameExist(GameSave::BoothSessionSlot, 0))
    {
        LoadedSave = Cast<UBoothSave>(UGameplayStatics::LoadGameFromSlot(GameSave::BoothSessionSlot, 0));
    }
    if (!LoadedSave)
    {
        UE_LOG(LogTemp, Warning, TEXT("[WebcamReceiver] Failed to load BattleSave; using defaults"));
        return; // ����Ʈ�� �����Ϸ��� ���⼭ return ������.
    }

    // 4) �Ķ���� ���� (�α׿��� Ȯ�ε� ��Ȯ�� �̸� ���)
    VideoMaterialInstance->SetVectorParameterValue(TEXT("Key Color"), LoadedSave->SetKeyColor);
    VideoMaterialInstance->SetScalarParameterValue(TEXT("LumaMask"), LoadedSave->LumaMask);
    VideoMaterialInstance->SetScalarParameterValue(TEXT("Alpha Min"), LoadedSave->AlphaMin);
    VideoMaterialInstance->SetScalarParameterValue(TEXT("Alpha Divisor"), LoadedSave->AlphaDivisor);
    VideoMaterialInstance->SetScalarParameterValue(TEXT("IntensityFloor"), LoadedSave->IntensityFloor);

    VideoMaterialInstance->SetScalarParameterValue(TEXT("Brightness"), LoadedSave->Brightness);
    VideoMaterialInstance->SetScalarParameterValue(TEXT("Contrast"), LoadedSave->Contrast);
    VideoMaterialInstance->SetScalarParameterValue(TEXT("Saturation"), LoadedSave->Saturation);
    VideoMaterialInstance->SetScalarParameterValue(TEXT("Hue Shift"), LoadedSave->HueShift);

    // 5) ����� ���
    const FString Msg = FString::Printf(
        TEXT("[WebcamReceiver] Applied | Key=(%.3f,%.3f,%.3f,%.3f) LumaMask=%.3f AlphaMin=%.3f AlphaDiv=%.3f IntFloor=%.3f"),
        LoadedSave->SetKeyColor.R, LoadedSave->SetKeyColor.G, LoadedSave->SetKeyColor.B, LoadedSave->SetKeyColor.A,
        LoadedSave->LumaMask, LoadedSave->AlphaMin, LoadedSave->AlphaDivisor, LoadedSave->IntensityFloor
    );
    UE_LOG(LogTemp, Log, TEXT("%s"), *Msg);
    if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Yellow, Msg);
}
