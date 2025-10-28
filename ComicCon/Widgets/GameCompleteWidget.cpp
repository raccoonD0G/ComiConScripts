#include "Widgets/GameCompleteWidget.h"
#include "Components/Image.h"
#include "Slate/WidgetTransform.h"
#include "Kismet/GameplayStatics.h"


// GameCompleteWidget.cpp 변경점
void UGameCompleteWidget::NativeConstruct()
{
    Super::NativeConstruct();

    SetVisibility(ESlateVisibility::Visible);
    bImpactPlaying = false;
    Elapsed = 0.f;

    // 초기에는 "보이는 상태"로 두자 (스케일만 시작 스케일)
    if (TextImage)
    {
        TextImage->SetRenderTransformPivot(FVector2D(0.5f, 0.5f));
        FWidgetTransform T;
        T.Scale = FVector2D(StartScale, StartScale);
        TextImage->SetRenderTransform(T);
        TextImage->SetRenderOpacity(1.f); // <-- 여기!
    }
    else
    {
        // 폴백: 위젯 전체에 적용 (TextImage 누락/미바인딩 대비)
        SetRenderTransformPivot(FVector2D(0.5f, 0.5f));
        FWidgetTransform T;
        T.Scale = FVector2D(StartScale, StartScale);
        SetRenderTransform(T);
        SetRenderOpacity(1.f);
    }

    if (bAutoPlayOnConstruct)
    {
        StartImpact(0.f); // 즉시 팡 재생
    }

    StartSound();
}

void UGameCompleteWidget::StartImpact(float InDuration)
{
    Duration = (InDuration > 0.f) ? InDuration : DefaultDuration;
    Elapsed = 0.f;
    bImpactPlaying = true;

    // 팡 시작하면서만 0에서부터 페이드인
    ApplyTransform(StartScale, 0.f);
}

void UGameCompleteWidget::ApplyTransform(float Scale, float Opacity)
{
    if (TextImage)
    {
        FWidgetTransform T;
        T.Scale = FVector2D(Scale, Scale);
        TextImage->SetRenderTransform(T);
        TextImage->SetRenderOpacity(Opacity);
    }
    else
    {
        // 폴백: 루트 위젯에 적용
        FWidgetTransform T;
        T.Scale = FVector2D(Scale, Scale);
        SetRenderTransform(T);
        SetRenderOpacity(Opacity);
    }
}

void UGameCompleteWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
    Super::NativeTick(MyGeometry, InDeltaTime);

    if (!bImpactPlaying || Duration <= KINDA_SMALL_NUMBER)
    {
        return;
    }

    Elapsed += InDeltaTime;
    const float T = FMath::Clamp(Elapsed / Duration, 0.f, 1.f);

    // ----- Scale timeline -----
    float ScaleNow = EndScale;
    if (T <= PopPhase)
    {
        // StartScale -> OvershootScale (팡)
        const float nt = T / FMath::Max(PopPhase, KINDA_SMALL_NUMBER);
        const float e = EaseOutBack(nt, 1.8f);
        ScaleNow = FMath::Lerp(StartScale, OvershootScale, e);
    }
    else if (T <= SettlePhase)
    {
        // OvershootScale -> EndScale (안정화)
        const float nt = (T - PopPhase) / FMath::Max(SettlePhase - PopPhase, KINDA_SMALL_NUMBER);
        const float e = SmoothStep(0.f, 1.f, nt);
        ScaleNow = FMath::Lerp(OvershootScale, EndScale, e);
    }
    else
    {
        ScaleNow = EndScale;
    }

    // ----- Opacity: 초반만 부드럽게 켜짐 -----
    const float ntFade = FMath::Clamp(T / FMath::Max(FadeInPhase, KINDA_SMALL_NUMBER), 0.f, 1.f);
    const float OpacityNow = SmoothStep(0.f, 1.f, ntFade);

    ApplyTransform(ScaleNow, OpacityNow);

    if (T >= 1.f)
    {
        bImpactPlaying = false;
        ApplyTransform(EndScale, 1.f);
    }
}

// s-curve: 0→1 구간을 부드럽게(미분 연속)
float UGameCompleteWidget::SmoothStep(float A, float B, float X)
{
    const float t = FMath::Clamp((X - A) / FMath::Max(B - A, KINDA_SMALL_NUMBER), 0.f, 1.f);
    return t * t * (3.f - 2.f * t);
}

// EaseOutBack: 살짝 튕기며 빠르게
float UGameCompleteWidget::EaseOutBack(float T, float Overshoot)
{
    const float s = Overshoot;   // 기본 1.70158, 값이 클수록 튕김 큼
    const float t = T - 1.f;
    return (t * t * ((s + 1.f) * t + s) + 1.f);
}

void UGameCompleteWidget::StartSound()
{
    if (!StartSoundAsset)
    {
        UE_LOG(LogTemp, Warning, TEXT("StartSoundAsset is null in %s"), *GetName());
        return;
    }

    UGameplayStatics::PlaySound2D(
        this,             // WorldContextObject
        StartSoundAsset,  // Sound
        1.0f,             // VolumeMultiplier
        1.0f,             // PitchMultiplier
        0.0f,             // StartTime
        nullptr,          // ConcurrencySettings
        nullptr,          // OwningActor
        true              // bIsUISound
    );
}