#pragma once
#include "CoreMinimal.h"

class APlayerController;
class UTexture2D;
struct FPersonPose;

namespace QR
{
    // ===== Net / Texture =====
    void UploadFileToServer(const FString& FilePath, const FString& ServerBase, TFunction<void(bool, FString /*qrUrl*/)> Done);
    UTexture2D* CreateTextureFromPng(const TArray<uint8>& InPngData);
    void FetchQrTexture(const FString& QrUrl, TFunction<void(bool, UTexture2D*)> Done);
}

namespace MotionCapture // ���ӽ����̽��� �浹 ����
{
    // COCO �ε��� ���
    static constexpr int32 COCO_LSH = 5;
    static constexpr int32 COCO_RSH = 6;
    static constexpr int32 COCO_LEL = 7;
    static constexpr int32 COCO_REL = 8;
    static constexpr int32 COCO_LWR = 9;
    static constexpr int32 COCO_RWR = 10;
    static constexpr int32 COCO_LHIP = 11;
    static constexpr int32 COCO_RHIP = 12;

    // COCO skeleton edges
    static const int32 EDGES[][2] = {
        {0,1},{0,2},{1,3},{2,4},
        {5,6},
        {5,7},{7,9},
        {6,8},{8,10},
        {11,12},
        {5,11},{6,12},
        {11,13},{13,15},
        {12,14},{14,16}
    };
    static const int32 NUM_EDGES = sizeof(EDGES) / sizeof(EDGES[0]);

    static const int32 HEADER_SIZE = 18; // 4+1+1+2+2+8

    // v2 hand block: hand_id(H=2) + handed(B=1) + score(f=4) + (21*2*4=168) + (21*4=84) = 259
    static const int32 EXPECTED_HAND_BLOCK = 259;

    // ��� ����� ���� (pid 2 + 34 floats + 17 floats = 206)
    static const int32 EXPECTED_PERSON_BLOCK = 2 + (34 * 4) + (17 * 4); // 206
}
