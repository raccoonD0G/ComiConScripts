# ComicCon 실시간 입력 파이프라인

## 개요
이 Unreal Engine 모듈은 ComicCon 경험을 구동하는 두 가지 실시간 데이터 소스를 통합합니다.

- **스켈레탈 모션 캡처** 프레임: `UPoseUdpReceiverComponent`가 UDP로 스트리밍된 포즈 패킷을 수신하여 게임플레이 로직과 디버그 시각화에 전달합니다.
- **라이브 NDI 웹캠 비디오**: `AWebcamReceiver`가 NDI 피드를 받아 키잉된 영상으로 머티리얼을 구동하고, 오퍼레이터가 조정한 값을 세이브 데이터에 보존합니다.

이 문서는 두 파이프라인이 데이터를 수신·정규화·재배포하는 방식을 중심으로 확장 시 고려해야 할 사항을 정리합니다.

## UDP 포즈 스트리밍
### 컴포넌트 라이프사이클
`UPoseUdpReceiverComponent`는 플레이 시작과 동시에 틱을 활성화하고 작업 버퍼를 준비한 뒤, 포트 `7777`에서 재사용 가능한 넌블로킹 UDP 소켓을 엽니다.【F:ComicCon/Components/PoseUdpReceiverComponent.cpp†L12-L141】 매 프레임 `TickComponent` 내에서 패킷을 소비하여 가장 최근에 완전히 수신된 버퍼를 유지하므로, 한 프레임 동안 여러 데이터그램이 도착하더라도 일관된 스냅샷을 청취자에게 제공합니다.【F:ComicCon/Components/PoseUdpReceiverComponent.cpp†L24-L121】

소유 액터가 파괴되면 컴포넌트는 소켓을 닫고 해제하여 운영체제 자원을 정리합니다.【F:ComicCon/Components/PoseUdpReceiverComponent.cpp†L124-L151】

### 패킷 포맷
리시버는 ASCII 매직 문자열 `POSE`와 버전 플래그가 선행되는 이진 포맷을 기대합니다. 버전 1은 바디 포즈만, 버전 2는 정밀 손 추적 블록을 추가로 전송합니다.【F:ComicCon/Components/PoseUdpReceiverComponent.cpp†L153-L256】 헤더 크기, 바디/핸드 블록 크기, COCO 키 인덱스, 스켈레톤 토폴로지 등 상수는 `MotionCapture` 유틸리티에 정의되어 파싱과 게임플레이 로직이 같은 기준을 공유합니다.【F:ComicCon/Utils.h†L16-L47】

각 패킷은 다음 구조로 구성됩니다.
1. **헤더** – 매직(`POSE`), 버전, 예약 플래그, 인원·손 개수, 밀리초 타임스탬프.【F:ComicCon/Components/PoseUdpReceiverComponent.cpp†L178-L185】
2. **인물 블록** – `uint16` 인물 ID, 17개의 (x, y) 좌표, 17개의 신뢰도 float. 불완전 블록 감지 시 수신을 중단하고 이전 버퍼를 유지해 안정성을 보장합니다.【F:ComicCon/Components/PoseUdpReceiverComponent.cpp†L187-L209】
3. **손 블록(v2+)** – 손 ID, 좌우 구분 플래그, 추적 스코어, 21개의 (x, y) 좌표, 21개의 신뢰도 float. 좌우 값은 프로젝트 규칙(0=왼손, 1=오른손)에 맞게 보정되며, 후속 계산을 위한 중심 좌표도 미리 산출합니다.【F:ComicCon/Components/PoseUdpReceiverComponent.cpp†L211-L253】

파싱된 포즈·손 데이터는 최신 타임스탬프와 함께 `LatestPoses`, `LatestHands`에 캐시되어 다른 시스템과 시간 정렬을 쉽게 합니다.【F:ComicCon/Components/PoseUdpReceiverComponent.h†L29-L47】【F:ComicCon/Components/PoseUdpReceiverComponent.cpp†L34-L39】

### 월드 좌표 투영 및 재사용
2D 조인트 좌표는 스케일(`PixelToUU`), 깊이 오프셋, 이미지 원점 값을 이용해 월드 좌표로 변환됩니다. 헬퍼는 이미지 공간 델타를 소유 액터의 로컬 공간으로 옮긴 뒤 월드 공간으로 전환하여, 액터 배치와 관계없이 일관된 시각화·게임플레이 계산을 보장합니다.【F:ComicCon/Components/PoseUdpReceiverComponent.h†L32-L61】【F:ComicCon/Components/PoseUdpReceiverComponent.cpp†L299-L324】

`bDrawDebug`를 활성화하면 매 프레임 스켈레톤 라인, 관절 구, 손 키포인트를 렌더링하여 빠른 디버깅이 가능합니다.【F:ComicCon/Components/PoseUdpReceiverComponent.cpp†L46-L105】 다운스트림 시스템은 `OnPoseBufferChanged`, `OnHandBufferChanged` 멀티캐스트 델리게이트에 바인딩하여 공유 프레임 원점과 함께 최신 버퍼를 전달받고, 각 소비자는 이를 동일한 좌표계로 정렬할 수 있습니다.【F:ComicCon/Components/PoseUdpReceiverComponent.h†L10-L71】【F:ComicCon/Components/PoseUdpReceiverComponent.cpp†L108-L121】 또한 `GetShoulderMidWorld`와 같은 유틸리티를 활용해 안정적인 기준점을 확보할 수 있습니다.【F:ComicCon/Components/PoseUdpReceiverComponent.cpp†L259-L304】

## NDI 웹캠 수신
### 액터 책임
`AWebcamReceiver`는 `ANDIReceiveActor`를 상속해 NDI IO 미디어 파이프라인을 이용하며, 공간 경계 검사를 위한 클램프 볼륨과 크로마 키 머티리얼 관리 기능을 추가합니다.【F:ComicCon/Actors/WebcamReceiver.h†L13-L30】 이 액터는 틱을 비활성화하고, 필요 시 플레이어 영역을 정의하기 위한 숨겨진 충돌 없는 박스를 생성합니다.【F:ComicCon/Actors/WebcamReceiver.cpp†L15-L31】

### 머티리얼 초기화
`BeginPlay`에서 표시용 메시를 검증하고, 기존 동적 머티리얼 인스턴스(MID)를 재사용하거나 기본 머티리얼만 존재할 경우 새로 생성합니다.【F:ComicCon/Actors/WebcamReceiver.cpp†L34-L62】 MID가 준비되면 NDI 미디어 텍스처와 알파 플레인이 머티리얼을 구동하도록 필요한 파라미터를 활성화하고, 프리뷰 전용 알파 경로를 비활성화합니다.【F:ComicCon/Actors/WebcamReceiver.cpp†L64-L68】

### 크로마 키 설정 유지
크로마 키 튜닝 값은 `BattleSave` 슬롯에 저장된 `UScoreSaveGame`으로부터 불러옵니다. 이 세이브는 게임플레이 통계뿐 아니라 키 색상, 루마 마스크, 알파 임계값, 색 보정 값 등 비디오 처리 파라미터도 저장합니다.【F:ComicCon/Actors/WebcamReceiver.cpp†L70-L102】【F:ComicCon/SaveGames/ScoreSaveGame.h†L29-L73】 세이브 파일이 없으면 경고를 기록하고 기본 머티리얼 값을 유지해 운영자가 중단 없이 작업할 수 있도록 합니다.【F:ComicCon/Actors/WebcamReceiver.cpp†L70-L80】 적용된 설정은 로그와 온스크린 디버그 메시지로 보고되어 현재 구성 상태를 확인할 수 있습니다.【F:ComicCon/Actors/WebcamReceiver.cpp†L94-L101】

저장되는 주요 파라미터의 의미는 다음과 같습니다.【F:ComicCon/SaveGames/ScoreSaveGame.h†L29-L73】

- **SetKeyColor**: 키잉할 대상 배경색으로, 크로마 키가 제거할 픽셀의 기준 색상입니다. 녹색 배경을 촬영하는 경우 기본값인 `FLinearColor::Green`이 사용되며, 다른 색상 배경을 사용할 때는 보정 도구에서 갱신됩니다.
- **LumaMask**: 밝기 기반 마스크 강도로, 조명 조건에 따라 배경 밝기가 달라졌을 때 제거 범위를 확장하거나 축소합니다. 값이 높을수록 어두운 영역까지 키잉 범위에 포함됩니다.
- **AlphaMin**: 머티리얼이 허용하는 알파 최솟값으로, 키잉된 결과가 완전히 투명해지기 위한 기준점입니다. 노이즈가 많을 경우 이 값을 올려 배경 잔존 픽셀을 제거할 수 있습니다.
- **AlphaDivisor**: `AlphaMin` 이상 픽셀의 알파를 보간할 때 사용하는 분모로, 크로마 키 가장자리의 부드러움과 투명도 변화 속도를 제어합니다. 낮은 값은 날카로운 경계를, 높은 값은 부드러운 전환을 제공합니다.
- **IntensityFloor**: 입력 영상의 최소 밝기를 설정해 어두운 피사체가 과도하게 지워지지 않도록 하는 안전망 역할을 합니다. 조명이 불안정할 때 피사체가 사라지는 현상을 방지합니다.
- **Brightness**: 입력 영상의 전체적인 노출을 보정합니다. 조명이 약해 피사체가 어둡게 보일 때 값을 높여 밝기를 끌어올리고, 반대로 과도한 조명으로 하이라이트가 날아갈 경우 값을 낮춰 디테일을 복원합니다.
- **Contrast**: 밝은 영역과 어두운 영역의 차이를 조정해 입체감을 제어합니다. 대비를 높이면 피사체 윤곽이 또렷해지지만 노이즈도 강조될 수 있고, 대비를 낮추면 부드러운 톤이 되지만 크로마 키 가장자리가 흐릿해질 수 있습니다.
- **Saturation**: 색상의 채도를 증감시키는 파라미터입니다. 카메라 화이트밸런스 오류나 조명 색온도 변화로 색이 바랬을 때 채도를 올려 생동감을 회복하고, 반대로 색이 과도하게 진할 경우 채도를 줄여 자연스러운 피부 톤을 만듭니다.
- **HueShift**: 전체 영상의 색상 각도를 회전시켜 색조를 미세하게 이동합니다. 조명 색 변화로 피부색이 녹색 또는 자주색으로 치우칠 때 몇 도만 이동시켜 자연스러운 색 균형을 맞출 수 있으며, 다른 파라미터로 해결되지 않는 색 틀어짐 보정에 유용합니다.

튜닝 도중 이 값들이 업데이트되면 `SaveGame`에 즉시 기록되어 재시작 후에도 동일한 머티리얼 상태를 재현할 수 있습니다. 따라서 NDI 수신 액터를 교체하거나 메시 재질을 재구성할 때도 세이브 데이터를 불러오면 운용자가 마지막으로 확인한 비주얼을 그대로 유지할 수 있습니다.

## 파이프라인 확장 가이드
- **커스텀 포즈 소비자**는 `UPoseUdpReceiverComponent`의 멀티캐스트 델리게이트에 바인딩하고, 공유된 `Anchor2D` 및 `PixelToUU` 값을 사용해 라이브 비디오 피드와 정렬을 유지해야 합니다. 녹화된 미디어 스트림 또는 분석과 동기화할 때는 `GetLatestTimestamp()`를 활용하세요.【F:ComicCon/Components/PoseUdpReceiverComponent.h†L10-L71】
- **새로운 NDI 비주얼라이제이션**은 `AWebcamReceiver`를 상속하거나 해당 머티리얼 워크플로를 재사용하여 저장된 크로마 키 파라미터가 추가 메시에도 전파되도록 합니다. 새로운 튜닝 항목을 도입한다면 `UScoreSaveGame`을 확장해 캘리브레이션 도구와 인게임 재생이 동일 값을 공유하게 하세요.【F:ComicCon/Actors/WebcamReceiver.cpp†L70-L102】【F:ComicCon/SaveGames/ScoreSaveGame.h†L29-L73】

## 빌드 의존성
`ComicCon.Build.cs`는 UDP 소켓 레이어와 NDI 미디어 파이프라인에 필요한 `Networking`, `Sockets`, `NDIIO`, `MediaPlate` 등을 이미 의존성으로 선언합니다. 프로젝트에서 해당 플러그인을 활성화하면 추가 설정 없이 동작합니다.【F:ComicCon/ComicCon.Build.cs†L5-L19】

## 트러블슈팅 팁
- 포즈 데이터가 멈춘 것처럼 보이면 송신기가 포트 `7777`을 향하고 매직 문자열과 버전이 기대값과 일치하는지 확인하세요. 리시버는 잘못된 패킷을 조용히 폐기하므로, `bDrawDebug`를 켜면 실제로 프레임이 파싱되는지 확인할 수 있습니다.【F:ComicCon/Components/PoseUdpReceiverComponent.cpp†L34-L256】
- NDI 피드가 검은 화면이라면 메시가 동적 머티리얼 인스턴스를 사용하고 `Enable Video Texture`/`Enable Video Alpha`가 `1.0`으로 유지되는지 확인하세요. `BattleSave`에 저장된 크로마 키 파라미터를 다시 적용하면 초기화된 머티리얼을 복구할 수 있습니다.【F:ComicCon/Actors/WebcamReceiver.cpp†L46-L102】
