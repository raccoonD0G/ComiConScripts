// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/ViewPlayer.h"
#include "Actors/MirroredPlayer.h"
#include "Components/SingleSwingClassifierComponent.h"
#include "Actors/Amulet.h"
#include "MediaPlate.h"
#include "Actors/WebcamReceiver.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CameraBoundsClampComponent.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundBase.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "GameModes/BattleGameMode.h"

AViewPlayer::AViewPlayer()
{
    PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	RootComponent = SceneComponent;

	CameraBoundsClampComponent = CreateDefaultSubobject<UCameraBoundsClampComponent>(TEXT("CameraBoundsClampComponent"));

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(RootComponent);
}

void AViewPlayer::PostInitializeComponents()
{
    Super::PostInitializeComponents();

    CurrentHealth = MaxHealth;
    OnPlayerHealthChanged.Broadcast(MaxHealth, CurrentHealth);

}

void AViewPlayer::BeginPlay()
{
    Super::BeginPlay();

    FActorSpawnParameters Params;
    Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

    check(MirroredPlayerClass);
    check(AmuletClass);
    check(WebcamReceiverClass);

    // --- MirroredPlayer 스폰 (스케일 적용) ---
    {
        const FVector MirroredScale(ViewScale);
        FTransform MirroredPlayerTF = FTransform(FRotator(), FVector(0, 0, -100), MirroredScale);
        MirroredPlayer = GetWorld()->SpawnActor<AMirroredPlayer>(MirroredPlayerClass, MirroredPlayerTF, Params);
    }

    // --- WebcamReceiver 스폰 (기본값 * ViewScale) ---
    {
        const FRotator WebcamRot(0.0f, 0.0f, 0.0f);
        const FVector WebcamLoc(0, 0, -100);

        const FVector WebcamBaseScale(10.8f * 0.5625f, 19.2f, 1.0f);
        const FVector WebcamScale = WebcamBaseScale * ViewScale;

        FTransform WebcamReceiverTF(WebcamRot, WebcamLoc, WebcamScale);
        WebcamReceiver = GetWorld()->SpawnActorDeferred<AActor>(WebcamReceiverClass, WebcamReceiverTF);

        IClampVolumeInterface* ClampVolumeInterface = Cast<IClampVolumeInterface>(WebcamReceiver);
        check(ClampVolumeInterface);

        CameraBoundsClampComponent->Init(ClampVolumeInterface->GetClampVolume(), SpringArmComponent);

        WebcamReceiver->FinishSpawning(WebcamReceiverTF);
        WebcamReceiver->SetActorTransform(WebcamReceiverTF, false, nullptr, ETeleportType::ResetPhysics);
    }

    // --- 부적(Amulet)은 기존 그대로 ---
    {
        FTransform AmuletTF;
        AmuletLeft = GetWorld()->SpawnActorDeferred<AAmulet>(AmuletClass, AmuletTF);
        AmuletLeft->SetOwningPlayer(MirroredPlayer);
        AmuletLeft->SetOwingSingleSwingClassifierComponent(MirroredPlayer->GetLeftSingleSwingClassifierComponent());
        AmuletLeft->FinishSpawning(AmuletTF);

        AmuletRight = GetWorld()->SpawnActorDeferred<AAmulet>(AmuletClass, AmuletTF);
        AmuletRight->SetOwningPlayer(MirroredPlayer);
        AmuletRight->SetOwingSingleSwingClassifierComponent(MirroredPlayer->GetRightSingleSwingClassifierComponent());
        AmuletRight->FinishSpawning(AmuletTF);
    }
}

void AViewPlayer::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
    if (!MirroredPlayer) return;

    UPoseUdpReceiverComponent* Receiver = MirroredPlayer->GetPoseReceiver();

    if (!Receiver) return;

    FVector ShoulderMid;
    if (!Receiver->GetShoulderMidWorld(ShoulderMid)) return;

    const FVector TargetLoc = ShoulderMid + FollowWorldOffset;

    if (FollowLagSpeed <= KINDA_SMALL_NUMBER)
    {
        SetActorLocation(TargetLoc);
    }
    else
    {
        SetActorLocation(FMath::VInterpTo(GetActorLocation(), TargetLoc, DeltaSeconds, FollowLagSpeed));
    }
}

void AViewPlayer::GetAttacked(int32 InAttackPower)
{
    ABattleGameMode* BattleGameMode = Cast<ABattleGameMode>(GetWorld()->GetAuthGameMode());

    if (BattleGameMode && BattleGameMode->ShouldBlockDamage())
    {
        return;
    }

    if (CurrentHealth <= 0) return;

    CurrentHealth = FMath::Clamp(CurrentHealth - InAttackPower, 0, MaxHealth);

    ShowDamagedEffect();

    PlayHitShake();

    OnPlayerHealthChanged.Broadcast(MaxHealth, CurrentHealth);
    
    if (CurrentHealth == 0)
    {
        if (BattleGameMode)
        {
            BattleGameMode->EndMatch();
        }
    }
}

void AViewPlayer::ShowDamagedEffect()
{
    if (!DamagedEffect) return;

    const FVector Offset(NiagaraXOffset, 0.f, 0.f);

    // 매번 새 컴포넌트 생성 (자동 파괴)
    UNiagaraComponent* Comp = UNiagaraFunctionLibrary::SpawnSystemAttached(
        DamagedEffect,
        SpringArmComponent,
        NAME_None,
        Offset,
        FRotator(0, 90, 0),
        EAttachLocation::KeepRelativeOffset,
        /*bAutoDestroy=*/ true
    );

    if (Comp)
    {
        Comp->SetUsingAbsoluteRotation(false);
        Comp->SetTranslucentSortPriority(1000);
        Comp->Activate(true);
    }
}

void AViewPlayer::PlayHitShake()
{
    if (APlayerController* PC = Cast<APlayerController>(GetController()))
    {
        if (PC->PlayerCameraManager && HitShakeClass)
        {
            PC->PlayerCameraManager->StartCameraShake(HitShakeClass, 1.0f);
        }
    }
}
