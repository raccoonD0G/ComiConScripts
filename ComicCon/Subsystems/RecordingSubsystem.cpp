// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/RecordingSubsystem.h"
#include "HAL/PlatformProcess.h"
#include "Misc/Paths.h"
#include "HAL/PlatformFilemanager.h"

#if PLATFORM_WINDOWS
#include "Windows/WindowsHWrapper.h"
#include "Windows/AllowWindowsPlatformTypes.h"
#include <windows.h>
#include "Windows/HideWindowsPlatformTypes.h"
#endif

#if PLATFORM_WINDOWS

DEFINE_LOG_CATEGORY_STATIC(LogRecording, Log, All);

static bool GetMonitorRectForGameWindow(int32& OutX, int32& OutY, int32& OutW, int32& OutH)
{
    // 1) ���� ������ �ڵ� ��� (������Ʈ �ֻ��� ������ �� ����Ƽ�� �ڵ�)
    TSharedPtr<SWindow> Top = FSlateApplication::Get().GetActiveTopLevelWindow();
    if (!Top.IsValid())
    {
        if (GEngine && GEngine->GameViewport)
        {
            Top = GEngine->GameViewport->GetWindow();
        }
    }
    if (!Top.IsValid())
    {
        return false;
    }

    TSharedPtr<FGenericWindow> Native = Top->GetNativeWindow();
    if (!Native.IsValid())
    {
        return false;
    }

    HWND Hwnd = static_cast<HWND>(Native->GetOSWindowHandle());
    if (!Hwnd)
    {
        return false;
    }

    // 2) �����찡 ��ġ�� ������� ��ü ����(rcMonitor)�� ��´�
    HMONITOR HMon = MonitorFromWindow(Hwnd, MONITOR_DEFAULTTONEAREST);
    if (!HMon) return false;

    MONITORINFO Mi;
    Mi.cbSize = sizeof(MONITORINFO);
    if (!GetMonitorInfo(HMon, &Mi))
    {
        return false;
    }

    // rcMonitor�� �ش� ������� ��ü �ȼ� ��ǥ(���� ����ũž ����)
    OutX = Mi.rcMonitor.left;
    OutY = Mi.rcMonitor.top;
    OutW = Mi.rcMonitor.right - Mi.rcMonitor.left;
    OutH = Mi.rcMonitor.bottom - Mi.rcMonitor.top;

    // ¦�� ����(���ڴ��� 4:2:0�� �� ����)
    if (OutW % 2) OutW -= 1;
    if (OutH % 2) OutH -= 1;

    return (OutW > 0 && OutH > 0);
}
#endif

void URecordingSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    // ��� ����: <ProjectDir>/Saved/Captures
    if (OutputDir.IsEmpty())
    {
        OutputDir = FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("Captures"));
    }
    OutputDir = FPaths::ConvertRelativePathToFull(OutputDir);

#if PLATFORM_WINDOWS
    // ffmpeg ���� ����: <ProjectDir>/ffmpeg/bin/ffmpeg.exe
    FfmpegExe = FPaths::ConvertRelativePathToFull(
        FPaths::Combine(FPaths::ProjectContentDir(), TEXT("ffmpeg/bin/ffmpeg.exe"))
    );
#endif

    // ���� ����
    IPlatformFile& PF = FPlatformFileManager::Get().GetPlatformFile();
    if (!PF.DirectoryExists(*OutputDir))
    {
        PF.CreateDirectoryTree(*OutputDir);
    }
}

void URecordingSubsystem::Deinitialize()
{
    KillIfRunning();
}

void URecordingSubsystem::StartRecording()
{
    if (bRecording) return;

#if PLATFORM_WINDOWS
    // 0) ����� ����
    int32 MonX = 0, MonY = 0, MonW = 0, MonH = 0;
    const bool bGotMon = GetMonitorRectForGameWindow(MonX, MonY, MonW, MonH);

    // 1) ��� ���/������
    const FString Ts = FString::Printf(TEXT("%lld"), FDateTime::UtcNow().ToUnixTimestamp());
    OutputPath = FPaths::ConvertRelativePathToFull(
        FPaths::Combine(OutputDir, FString::Printf(TEXT("match_%s.mp4"), *Ts))
    );

    FPlatformProcess::CreatePipe(ChildStdIn_Read, ChildStdIn_Write, /*bWritePipeLocal=*/true);

    // 2) ddagrab �켱 �� ���� �� gdigrab
    bool bOK = LaunchFF(/*bUseGdi*/false, bGotMon, MonX, MonY, MonW, MonH);
    if (!bOK)
        bOK = LaunchFF(/*bUseGdi*/true, bGotMon, MonX, MonY, MonW, MonH);

    bRecording = bOK;
    StartTimeSec = bOK ? FPlatformTime::Seconds() : 0.0;

    if (!bRecording)
    {
        if (ChildStdIn_Read || ChildStdIn_Write)
            FPlatformProcess::ClosePipe(ChildStdIn_Read, ChildStdIn_Write);
        ChildStdIn_Read = ChildStdIn_Write = nullptr;
    }
#endif
}

void URecordingSubsystem::StopRecording()
{
    KillIfRunning();
}

bool URecordingSubsystem::LaunchFF(bool bUseGdi, bool bGotMon, int32 MonX, int32 MonY, int32 MonW, int32 MonH)
{
    const TCHAR* Grab = bUseGdi ? TEXT("gdigrab") : TEXT("ddagrab");

    // (A) ���� �Է�
    FString VideoInput =
        FString::Printf(TEXT("-y -f %s "), Grab) +
        (bGotMon
            ? FString::Printf(TEXT("-offset_x %d -offset_y %d -video_size %dx%d "), MonX, MonY, MonW, MonH)
            : FString()) +
        FString::Printf(TEXT("-framerate %d -i desktop "), Framerate);

    // (B) ����� �Է� (DirectShow)
    FString AudioInput;
    if (bCaptureSystemAudio)
    {
        AudioInput = TEXT("-f dshow -thread_queue_size 4096 -i audio=\"virtual-audio-capturer\" ");
    }

    // (C) ���/�ڵ�/����
    FString OutputCodec =
        TEXT("-pix_fmt yuv420p ")
        TEXT("-vcodec libx264 -preset veryfast ") +
        FString::Printf(TEXT("-crf %d "), CRF) +
        TEXT("-vf pad=ceil(iw/2)*2:ceil(ih/2)*2 ");

    if (bCaptureSystemAudio)
    {
        OutputCodec += FString::Printf(
            TEXT("-c:a aac -b:a %dk -ar %d -ac 2 "),
            AudioBitrateKbps,
            AudioSampleRate
        );
        OutputCodec += TEXT("-map 0:v:0 -map 1:a:0 ");
    }
    else
    {
        OutputCodec += TEXT("-an ");
        OutputCodec += TEXT("-map 0:v:0 ");
    }

    // (D) ������
    const FString Tail = TEXT("-movflags +faststart ");

    const FString Args = VideoInput + AudioInput + OutputCodec + Tail +
        FString::Printf(TEXT("\"%s\""), *OutputPath);

    const FString WorkDir = FPaths::GetPath(FfmpegExe);

    FfmpegHandle = FPlatformProcess::CreateProc(
        *FfmpegExe, *Args,
        /*Detached*/ true,
        /*Hidden*/   bHideWindow,
        /*ReallyHidden*/ false,
        /*PID*/      nullptr,
        /*Priority*/ 0,
        /*WorkDir*/  WorkDir.IsEmpty() ? nullptr : *WorkDir,
        /*PipeWrite*/ nullptr,       // child stdout/err
        /*PipeRead*/  ChildStdIn_Read // child stdin
    );

    FPlatformProcess::Sleep(0.1f);
    return FPlatformProcess::IsProcRunning(FfmpegHandle);
}

void URecordingSubsystem::KillIfRunning()
{
#if PLATFORM_WINDOWS
    // �ʹ� ���� ���߸� 0������ �� �ּ� 0.5s ����
    if (bRecording)
    {
        const double MinDur = 0.5;
        const double Now = FPlatformTime::Seconds();
        if (StartTimeSec > 0 && Now - StartTimeSec < MinDur)
            FPlatformProcess::Sleep(static_cast<float>(MinDur - (Now - StartTimeSec)));
    }

    if (FPlatformProcess::IsProcRunning(FfmpegHandle))
    {
        // �׷��̽�Ǯ ����: stdin���� 'q\n'
        if (ChildStdIn_Write)
        {
            FPlatformProcess::WritePipe(ChildStdIn_Write, TEXT("q\n"));
            // ���ϸ� ��� EOF ��ȣ: ������ �ݱ�
            // FPlatformProcess::ClosePipe(ChildStdIn_Read, ChildStdIn_Write);
            // ChildStdIn_Read = ChildStdIn_Write = nullptr;
        }

        // �ִ� 10�� ���
        const double Deadline = FPlatformTime::Seconds() + 10.0;
        while (FPlatformTime::Seconds() < Deadline && FPlatformProcess::IsProcRunning(FfmpegHandle))
            FPlatformProcess::Sleep(0.1f);

        // �׷��� ��������� ���� ����
        if (FPlatformProcess::IsProcRunning(FfmpegHandle))
            FPlatformProcess::TerminateProc(FfmpegHandle, true);

        FPlatformProcess::CloseProc(FfmpegHandle);
    }

    // ���� ������ ����
    if (ChildStdIn_Read || ChildStdIn_Write)
        FPlatformProcess::ClosePipe(ChildStdIn_Read, ChildStdIn_Write);
    ChildStdIn_Read = ChildStdIn_Write = nullptr;

    bRecording = false;
#endif
}