// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/LobbyWidget.h"
#include "Components/EditableTextBox.h"
#include "Components/Image.h"
#include "GameFramework/GameUserSettings.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetRenderingLibrary.h"
#include "SaveGames/ScoreSaveGame.h"

void ULobbyWidget::OnValueCommittedLumaMask(const FText& Text, ETextCommit::Type CommitMethod)
{
    const FString StringVal = Text.ToString();
    const float IntVal = FCString::Atof(*StringVal);

    UE_LOG(LogTemp, Log, TEXT("Entered Number: %f"), IntVal);

    ChangeLumaMask(IntVal);
}

void ULobbyWidget::OnValueCommittedAlphaMin(const FText& Text, ETextCommit::Type CommitMethod)
{
    const FString StringVal = Text.ToString();
    const float IntVal = FCString::Atof(*StringVal);

    UE_LOG(LogTemp, Log, TEXT("Entered Number: %f"), IntVal);

    ChangeAlphaMin(IntVal);
}

void ULobbyWidget::OnValueCommittedAlphaDivisor(const FText& Text, ETextCommit::Type CommitMethod)
{
    const FString StringVal = Text.ToString();
    const float IntVal = FCString::Atof(*StringVal);

    UE_LOG(LogTemp, Log, TEXT("Entered Number: %f"), IntVal);
    
    ChangeAlphaDivisor(IntVal);
}

void ULobbyWidget::OnValueCommittedIntensityFloor(const FText& Text, ETextCommit::Type CommitMethod)
{
    const FString StringVal = Text.ToString();
    const float IntVal = FCString::Atof(*StringVal);

    UE_LOG(LogTemp, Log, TEXT("Entered Number: %f"), IntVal);

    ChangeIntensityFloor(IntVal);
}

void ULobbyWidget::OnValueCommittedBrightness(const FText& Text, ETextCommit::Type CommitMethod)
{
    const FString StringVal = Text.ToString();
    const float IntVal = FCString::Atof(*StringVal);

    UE_LOG(LogTemp, Log, TEXT("Entered Number: %f"), IntVal);

    ChangeBrightness(IntVal);
}

void ULobbyWidget::OnValueCommittedContrast(const FText& Text, ETextCommit::Type CommitMethod)
{
    const FString StringVal = Text.ToString();
    const float IntVal = FCString::Atof(*StringVal);

    UE_LOG(LogTemp, Log, TEXT("Entered Number: %f"), IntVal);

    ChangeContrast(IntVal);
}

void ULobbyWidget::OnValueCommittedSaturation(const FText& Text, ETextCommit::Type CommitMethod)
{
    const FString StringVal = Text.ToString();
    const float IntVal = FCString::Atof(*StringVal);

    UE_LOG(LogTemp, Log, TEXT("Entered Number: %f"), IntVal);

    ChangeSaturation(IntVal);
}

void ULobbyWidget::OnValueCommittedHueShift(const FText& Text, ETextCommit::Type CommitMethod)
{
    const FString StringVal = Text.ToString();
    const float IntVal = FCString::Atof(*StringVal);

    UE_LOG(LogTemp, Log, TEXT("Entered Number: %f"), IntVal);

    ChangeHueShift(IntVal);
}

void ULobbyWidget::OnSliderValueChangedLumaMask(const float Value)
{
    ChangeLumaMask(Value);
}

void ULobbyWidget::OnSliderValueChangedAlphaMin(const float Value)
{
    ChangeAlphaMin(Value);
}

void ULobbyWidget::OnSliderValueChangedAlphaDivisor(const float Value)
{
    ChangeAlphaDivisor(Value);
}

void ULobbyWidget::OnSliderValueChangedIntensityFloor(const float Value)
{
    ChangeIntensityFloor(Value);
}

void ULobbyWidget::OnSliderValueChangedBrightness(const float Value)
{
    ChangeBrightness(Value);
}

void ULobbyWidget::OnSliderValueChangedContrast(const float Value)
{
    ChangeContrast(Value);
}

void ULobbyWidget::OnSliderValueChangedSaturation(const float Value)
{
    ChangeSaturation(Value);
}

void ULobbyWidget::OnSliderValueChangedHueShift(const float Value)
{
    ChangeHueShift(Value);
}

void ULobbyWidget::ChangeKeyColor()
{
    UiMID->SetVectorParameterValue("Key Color", PickedColor);
}

void ULobbyWidget::ChangeLumaMask(float f)
{
    UiMID->SetScalarParameterValue("LumaMask", f);

    LumaMask->SetText(FText::AsNumber(f));

    SaveLumaMask = f;
}

void ULobbyWidget::ChangeAlphaMin(float f)
{
    UiMID->SetScalarParameterValue("Alpha Min", f);

    AlphaMin->SetText(FText::AsNumber(f));

    SaveAlphaMin = f;    
}

void ULobbyWidget::ChangeAlphaDivisor(float f)
{
    UiMID->SetScalarParameterValue("Alpha Divisor", f);

    AlphaDivisor->SetText(FText::AsNumber(f));
    
    SaveAlphaDivisor = f;
}

void ULobbyWidget::ChangeIntensityFloor(float f)
{
    UiMID->SetScalarParameterValue("IntensityFloor", f);

    IntensityFloor->SetText(FText::AsNumber(f));
    
    SaveIntensityFloor = f;
}

void ULobbyWidget::ChangeBrightness(float f)
{
    UiMID->SetScalarParameterValue("Brightness", f);

    Brightness->SetText(FText::AsNumber(f));
    
    SaveBrightness = f;
}

void ULobbyWidget::ChangeContrast(float f)
{
    UiMID->SetScalarParameterValue("Contrast", f);

    Contrast->SetText(FText::AsNumber(f));
    
    SaveContrast = f;
}

void ULobbyWidget::ChangeSaturation(float f)
{
    UiMID->SetScalarParameterValue("Saturation", f);

    Saturation->SetText(FText::AsNumber(f));
    
    SaveSaturation = f;
}

void ULobbyWidget::ChangeHueShift(float f)
{
    UiMID->SetScalarParameterValue("Hue Shift", f);

    HueShift->SetText(FText::AsNumber(f));
    
    SaveHueShift = f;
}

void ULobbyWidget::SaveParam()
{
    UScoreSaveGame* SaveObj = nullptr;
    if (UGameplayStatics::DoesSaveGameExist(SaveSlotName, UserIndex))
    {
        SaveObj = Cast<UScoreSaveGame>(UGameplayStatics::LoadGameFromSlot(SaveSlotName, UserIndex));
    }
    if (!SaveObj)
    {
        SaveObj = Cast<UScoreSaveGame>(UGameplayStatics::CreateSaveGameObject(UScoreSaveGame::StaticClass()));
    }

    if(!SaveObj) return;

    SaveObj->SetKeyColor = PickedColor;
    SaveObj->LumaMask = SaveLumaMask;
    SaveObj->AlphaMin = SaveAlphaMin;
    SaveObj->AlphaDivisor = SaveAlphaDivisor;
    SaveObj->IntensityFloor = SaveIntensityFloor;
    SaveObj->Brightness = SaveBrightness;
    SaveObj->Contrast = SaveContrast;
    SaveObj->Saturation = SaveSaturation;
    SaveObj->HueShift = SaveHueShift;

    UGameplayStatics::SaveGameToSlot(SaveObj, SaveSlotName, UserIndex);
}

void ULobbyWidget::ResetParam()
{
    UScoreSaveGame* SaveObj = nullptr;
    if (UGameplayStatics::DoesSaveGameExist(SaveSlotName, UserIndex))
    {
        SaveObj = Cast<UScoreSaveGame>(UGameplayStatics::LoadGameFromSlot(SaveSlotName, UserIndex));
    }
    if (!SaveObj)
    {
        SaveObj = Cast<UScoreSaveGame>(UGameplayStatics::CreateSaveGameObject(UScoreSaveGame::StaticClass()));
    }

    if(!SaveObj) return;

    SaveObj->SetKeyColor = FLinearColor::Green;
    SaveObj->LumaMask = 0.0f;
    SaveObj->AlphaMin = 0.0f;
    SaveObj->AlphaDivisor = 0.15f;
    SaveObj->IntensityFloor = 0.0f;
    SaveObj->Brightness = 1.0f;
    SaveObj->Contrast = 1.0f;
    SaveObj->Saturation = 0.0f;
    SaveObj->HueShift = 0.0f;

    UGameplayStatics::SaveGameToSlot(SaveObj, SaveSlotName, UserIndex);

    ResetMap();
}

void ULobbyWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (VideoImage && UiMaterial)
    {
        UiMID = UMaterialInstanceDynamic::Create(UiMaterial, this);
        VideoImage->SetBrushFromMaterial(UiMID);
    }

    if (RtMaterial)
    {
        RtMID = UMaterialInstanceDynamic::Create(RtMaterial, this);
    }

    UScoreSaveGame* SaveObj = nullptr;
    if (UGameplayStatics::DoesSaveGameExist(SaveSlotName, UserIndex))
    {
        SaveObj = Cast<UScoreSaveGame>(UGameplayStatics::LoadGameFromSlot(SaveSlotName, UserIndex));
    }
    if (!SaveObj)
    {
        SaveObj = Cast<UScoreSaveGame>(UGameplayStatics::CreateSaveGameObject(UScoreSaveGame::StaticClass()));
    }

    if(!SaveObj) return;

    // 세이브 데이터 불러오기
    PickedColor = SaveObj->SetKeyColor;
    SaveLumaMask = SaveObj->LumaMask ;
    SaveAlphaMin = SaveObj->AlphaMin;
    SaveAlphaDivisor = SaveObj->AlphaDivisor;
    SaveIntensityFloor = SaveObj->IntensityFloor;
    SaveBrightness = SaveObj->Brightness;
    SaveContrast = SaveObj->Contrast;
    SaveSaturation = SaveObj->Saturation;
    SaveHueShift = SaveObj->HueShift;

    // 세이브 데이터 적용
    ChangeKeyColor();
    ChangeLumaMask(SaveLumaMask);
    ChangeAlphaMin(SaveAlphaMin);
    ChangeAlphaDivisor(SaveAlphaDivisor);
    ChangeIntensityFloor(SaveIntensityFloor);
    ChangeBrightness(SaveBrightness);
    ChangeContrast(SaveContrast);
    ChangeSaturation(SaveSaturation);
    ChangeHueShift(SaveHueShift);
    test(PickedColor);

    // 실시간 데이터 적용
    if (LumaMask)
    {
        LumaMask->OnTextCommitted.AddDynamic(this, &ULobbyWidget::OnValueCommittedLumaMask);
    }
    if (AlphaMin)
    {
        AlphaMin->OnTextCommitted.AddDynamic(this, &ULobbyWidget::OnValueCommittedAlphaMin);
    }
    if (AlphaDivisor)
    {
        AlphaDivisor->OnTextCommitted.AddDynamic(this, &ULobbyWidget::OnValueCommittedAlphaDivisor);
    }
    if (IntensityFloor)
    {
        IntensityFloor->OnTextCommitted.AddDynamic(this, &ULobbyWidget::OnValueCommittedIntensityFloor);
    }
    if (Brightness)
    {
        Brightness->OnTextCommitted.AddDynamic(this, &ULobbyWidget::OnValueCommittedBrightness);
    }
    if (Contrast)
    {
        Contrast->OnTextCommitted.AddDynamic(this, &ULobbyWidget::OnValueCommittedContrast);
    }
    if (Saturation)
    {
        Saturation->OnTextCommitted.AddDynamic(this, &ULobbyWidget::OnValueCommittedSaturation);
    }
    if (HueShift)
    {
        HueShift->OnTextCommitted.AddDynamic(this, &ULobbyWidget::OnValueCommittedHueShift);
    }

    if (LumaMaskSlider)
    {
        LumaMaskSlider->OnValueChanged.AddDynamic(this, &ULobbyWidget::OnSliderValueChangedLumaMask);
    }
    if (AlphaMinSlider)
    {
        AlphaMinSlider->OnValueChanged.AddDynamic(this, &ULobbyWidget::OnSliderValueChangedAlphaMin);
    }
    if (AlphaDivisorSlider)
    {
        AlphaDivisorSlider->OnValueChanged.AddDynamic(this, &ULobbyWidget::OnSliderValueChangedAlphaDivisor);
    }
    if (IntensityFloorSlider)
    {
        IntensityFloorSlider->OnValueChanged.AddDynamic(this, &ULobbyWidget::OnSliderValueChangedIntensityFloor);
    }
    if (BrightnessSlider)
    {
        BrightnessSlider->OnValueChanged.AddDynamic(this, &ULobbyWidget::OnSliderValueChangedBrightness);
    }
    if (ContrastSlider)
    {
        ContrastSlider->OnValueChanged.AddDynamic(this, &ULobbyWidget::OnSliderValueChangedContrast);
    }
    if (SaturationSlider)
    {
        SaturationSlider->OnValueChanged.AddDynamic(this, &ULobbyWidget::OnSliderValueChangedSaturation);
    }
    if (HueShiftSlider)
    {
        HueShiftSlider->OnValueChanged.AddDynamic(this, &ULobbyWidget::OnSliderValueChangedHueShift);
    }
}

FReply ULobbyWidget::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
    FVector2D UV;
    
    if (!ComputeUVOnImage(InMouseEvent, UV))
    {
        return FReply::Unhandled();
    }

    if (!RenderTarget || !RtMID)
    {
        return FReply::Handled();
    }

    // 1) 클릭 시점의 현재 프레임을 RT로 복사(그리기)
    UKismetRenderingLibrary::DrawMaterialToRenderTarget(this, RenderTarget, RtMID);

    // 2) UV -> 픽셀 좌표
    const int32 RtW = RenderTarget->SizeX;
    const int32 RtH = RenderTarget->SizeY;

    int32 Px = FMath::Clamp(FMath::FloorToInt(UV.X * RtW), 0, RtW - 1);
    int32 Py = FMath::Clamp(FMath::FloorToInt(UV.Y * RtH), 0, RtH - 1);

    // 3) 픽셀 읽기
    PickedColor = UKismetRenderingLibrary::ReadRenderTargetPixel(this, RenderTarget, Px, Py);

    PickedColor.A = 1.0f;

    // 디버그
    UE_LOG(LogTemp, Display, TEXT("PickedColor UV(%.3f, %.3f) -> Pixel(%d, %d) = %s"),
        UV.X, UV.Y, Px, Py, *PickedColor.ToString());
    
    test(PickedColor);
    
    ChangeKeyColor();

    return FReply::Handled();
}

void ULobbyWidget::SetWindowed(int32 Width, int32 Height)
{
    if (!GEngine) return;
    if (UGameUserSettings* GS = GEngine->GetGameUserSettings())
    {
        GS->SetFullscreenMode(EWindowMode::Windowed);
        GS->SetScreenResolution(FIntPoint(Width, Height));
        GS->ApplySettings(false);
        GS->SaveSettings();
    }
}

void ULobbyWidget::SetFullscreen(bool bTrueFullscreen)
{
    if (!GEngine) return;
    if (UGameUserSettings* GS = GEngine->GetGameUserSettings())
    {
        GS->SetFullscreenMode(bTrueFullscreen ? EWindowMode::Fullscreen : EWindowMode::WindowedFullscreen);
        GS->ApplySettings(false);
        GS->SaveSettings();
    }
}

bool ULobbyWidget::ComputeUVOnImage(const FPointerEvent& MouseEvent, FVector2D& OutUV) const
{
    if (!VideoImage)
    {
        return false;
    }

    const FGeometry& ImgGeo = VideoImage->GetCachedGeometry();

    // 스크린 좌표 -> 이미지 로컬 좌표
    const FVector2D ScreenPos = MouseEvent.GetScreenSpacePosition();
    const FVector2D LocalPos = ImgGeo.AbsoluteToLocal(ScreenPos);
    const FVector2D ImgSize = ImgGeo.GetLocalSize();

    if (ImgSize.X <= 0.f || ImgSize.Y <= 0.f)
    {
        return false;
    }

    FVector2D UV(LocalPos.X / ImgSize.X, LocalPos.Y / ImgSize.Y);

    // 범위 체크 (이미지 영역 밖 클릭시 무시)
    if (UV.X < 0.f || UV.X > 1.f || UV.Y < 0.f || UV.Y > 1.f)
    {
        return false;
    }

    OutUV = UV;
    return true;
}

bool ULobbyWidget::ComputeUV_ScaleToFit(const FPointerEvent& MouseEvent, FVector2D& OutUV) const
{
    if (!VideoImage || !RenderTarget)
    {
        return false;
    }

    const FGeometry& ImgGeo = VideoImage->GetCachedGeometry();
    const FVector2D ScreenPos = MouseEvent.GetScreenSpacePosition();
    const FVector2D LocalPos = ImgGeo.AbsoluteToLocal(ScreenPos);
    const FVector2D WwHw = ImgGeo.GetLocalSize();

    const float RtW = RenderTarget->SizeX;
    const float RtH = RenderTarget->SizeY;

    if (WwHw.X <= 0.f || WwHw.Y <= 0.f || RtW <= 0.f || RtH <= 0.f)
    {
        return false;
    }

    const float Scale = FMath::Min(WwHw.X / RtW, WwHw.Y / RtH);
    const FVector2D Ds(RtW * Scale, RtH * Scale);
    const FVector2D Offset((WwHw.X - Ds.X) * 0.5f, (WwHw.Y - Ds.Y) * 0.5f);

    const FVector2D PPrime = LocalPos - Offset;

    if (PPrime.X < 0.f || PPrime.Y < 0.f || PPrime.X > Ds.X || PPrime.Y > Ds.Y)
    {
        return false;
    }

    OutUV = FVector2D(PPrime.X / Ds.X, PPrime.Y / Ds.Y);
    return true;
}
