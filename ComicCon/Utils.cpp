#include "Utils.h"
#include "HttpModule.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "Dom/JsonObject.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"
#include "IImageWrapperModule.h"
#include "IImageWrapper.h"
#include "Modules/ModuleManager.h"
#include "Engine/Texture2D.h"
#include "RenderUtils.h"
#include "Async/Async.h"
#include "Global/UdpStruct.h"

namespace QR
{
    void UploadFileToServer(const FString& FilePath, const FString& ServerBase, TFunction<void(bool, FString)> Done)
    {
        TArray<uint8> FileData;
        if (!FFileHelper::LoadFileToArray(FileData, *FilePath)) { Done(false, TEXT("")); return; }

        const FString Boundary = TEXT("----UEForm") + FGuid::NewGuid().ToString(EGuidFormats::Digits);
        const FString Url = ServerBase + TEXT("/api/upload");

        TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Req = FHttpModule::Get().CreateRequest();
        Req->SetURL(Url);
        Req->SetVerb(TEXT("POST"));
        Req->SetHeader(TEXT("Content-Type"), FString::Printf(TEXT("multipart/form-data; boundary=%s"), *Boundary));

        TArray<uint8> Payload;
        auto AddTextField = [&](const FString& Name, const FString& Value)
            {
                const FString Preamble = FString::Printf(TEXT("--%s\r\nContent-Disposition: form-data; name=\"%s\"\r\n\r\n%s\r\n"), *Boundary, *Name, *Value);
                FTCHARToUTF8 Conv(*Preamble); Payload.Append((uint8*)Conv.Get(), Conv.Length());
            };
        auto AddFileField = [&](const FString& Name, const FString& Filename, const TArray<uint8>& Data, const FString& ContentType)
            {
                const FString Header = FString::Printf(TEXT("--%s\r\nContent-Disposition: form-data; name=\"%s\"; filename=\"%s\"\r\nContent-Type: %s\r\n\r\n"),
                    *Boundary, *Name, *Filename, *ContentType);
                FTCHARToUTF8 Hdr(*Header); Payload.Append((uint8*)Hdr.Get(), Hdr.Length());
                Payload.Append(Data);
                FTCHARToUTF8 CRLF(TEXT("\r\n")); Payload.Append((uint8*)CRLF.Get(), CRLF.Length());
            };

        AddTextField(TEXT("max_downloads"), TEXT("3"));
        AddFileField(TEXT("file"), FPaths::GetCleanFilename(FilePath), FileData, TEXT("video/mp4"));

        const FString Tail = FString::Printf(TEXT("--%s--\r\n"), *Boundary);
        { FTCHARToUTF8 T(*Tail); Payload.Append((uint8*)T.Get(), T.Length()); }

        Req->SetContent(MoveTemp(Payload));
        Req->OnProcessRequestComplete().BindLambda([Done](FHttpRequestPtr, FHttpResponsePtr Resp, bool bOK)
            {
                const auto Finish = [Done](bool ok, const FString& url) {
                    // HTTP 콜백이 보통 GameThread지만, 안전하게 보장
                    AsyncTask(ENamedThreads::GameThread, [Done, ok, url] { Done(ok, url); });
                    };

                if (!bOK || !Resp.IsValid() || Resp->GetResponseCode() != 200) { Finish(false, TEXT("")); return; }

                TSharedPtr<FJsonObject> Json;
                const auto Reader = TJsonReaderFactory<>::Create(Resp->GetContentAsString());
                if (FJsonSerializer::Deserialize(Reader, Json) && Json.IsValid() && Json->GetBoolField(TEXT("ok")))
                {
                    Finish(true, Json->GetStringField(TEXT("qr_png_url")));
                }
                else { Finish(false, TEXT("")); }
            });
        Req->ProcessRequest();
    }

    UTexture2D* CreateTextureFromPng(const TArray<uint8>& InPngData)
    {
        IImageWrapperModule& ImageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>("ImageWrapper");
        TSharedPtr<IImageWrapper> Wrapper = ImageWrapperModule.CreateImageWrapper(EImageFormat::PNG);
        if (!Wrapper.IsValid() || !Wrapper->SetCompressed(InPngData.GetData(), InPngData.Num())) return nullptr;

        const int32 Width = Wrapper->GetWidth();
        const int32 Height = Wrapper->GetHeight();

        TArray<uint8> RawBGRA;
        if (!Wrapper->GetRaw(ERGBFormat::BGRA, 8, RawBGRA)) return nullptr;

        UTexture2D* Tex = UTexture2D::CreateTransient(Width, Height, PF_B8G8R8A8);
        if (!Tex) return nullptr;
        Tex->SRGB = true;

        FTexture2DMipMap& Mip = Tex->GetPlatformData()->Mips[0];
        void* Data = Mip.BulkData.Lock(LOCK_READ_WRITE);
        FMemory::Memcpy(Data, RawBGRA.GetData(), RawBGRA.Num());
        Mip.BulkData.Unlock();

        Tex->UpdateResource();
        return Tex;
    }

    void FetchQrTexture(const FString& QrUrl, TFunction<void(bool, UTexture2D*)> Done)
    {
        TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Req = FHttpModule::Get().CreateRequest();
        Req->SetURL(QrUrl);
        Req->SetVerb(TEXT("GET"));
        Req->OnProcessRequestComplete().BindLambda([Done](FHttpRequestPtr, FHttpResponsePtr Resp, bool bOK)
            {
                auto Finish = [Done](bool ok, UTexture2D* tex) {
                    AsyncTask(ENamedThreads::GameThread, [Done, ok, tex] { Done(ok, tex); });
                    };
                if (!bOK || !Resp.IsValid() || Resp->GetResponseCode() != 200) { Finish(false, nullptr); return; }

                const TArray<uint8>& PngData = Resp->GetContent();
                if (UTexture2D* Tex = CreateTextureFromPng(PngData)) { Finish(true, Tex); }
                else { Finish(false, nullptr); }
            });
        Req->ProcessRequest();
    }
}