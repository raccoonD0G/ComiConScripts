// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Components/NDIViewportCaptureComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UNDIMediaSender;
class UTextureRenderTarget2D;
struct FFrameRate;
struct FNDIBroadcastConfiguration;
#ifdef NDIIO_NDIViewportCaptureComponent_generated_h
#error "NDIViewportCaptureComponent.generated.h already included, missing '#pragma once' in NDIViewportCaptureComponent.h"
#endif
#define NDIIO_NDIViewportCaptureComponent_generated_h

#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIViewportCaptureComponent_h_33_SPARSE_DATA
#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIViewportCaptureComponent_h_33_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIViewportCaptureComponent_h_33_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIViewportCaptureComponent_h_33_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnBroadcastConfigurationChanged); \
	DECLARE_FUNCTION(execGetNumberOfConnections); \
	DECLARE_FUNCTION(execGetTallyInformation); \
	DECLARE_FUNCTION(execChangeCaptureSettings); \
	DECLARE_FUNCTION(execChangeBroadcastTexture); \
	DECLARE_FUNCTION(execChangeBroadcastConfiguration); \
	DECLARE_FUNCTION(execChangeSourceName);


#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIViewportCaptureComponent_h_33_ACCESSORS
#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIViewportCaptureComponent_h_33_INCLASS \
private: \
	static void StaticRegisterNativesUNDIViewportCaptureComponent(); \
	friend struct Z_Construct_UClass_UNDIViewportCaptureComponent_Statics; \
public: \
	DECLARE_CLASS(UNDIViewportCaptureComponent, USceneCaptureComponent2D, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/NDIIO"), NO_API) \
	DECLARE_SERIALIZER(UNDIViewportCaptureComponent)


#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIViewportCaptureComponent_h_33_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UNDIViewportCaptureComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UNDIViewportCaptureComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UNDIViewportCaptureComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UNDIViewportCaptureComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UNDIViewportCaptureComponent(UNDIViewportCaptureComponent&&); \
	NO_API UNDIViewportCaptureComponent(const UNDIViewportCaptureComponent&); \
public:


#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIViewportCaptureComponent_h_30_PROLOG
#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIViewportCaptureComponent_h_33_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIViewportCaptureComponent_h_33_SPARSE_DATA \
	FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIViewportCaptureComponent_h_33_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIViewportCaptureComponent_h_33_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIViewportCaptureComponent_h_33_RPC_WRAPPERS \
	FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIViewportCaptureComponent_h_33_ACCESSORS \
	FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIViewportCaptureComponent_h_33_INCLASS \
	FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIViewportCaptureComponent_h_33_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> NDIIO_API UClass* StaticClass<class UNDIViewportCaptureComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIViewportCaptureComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
