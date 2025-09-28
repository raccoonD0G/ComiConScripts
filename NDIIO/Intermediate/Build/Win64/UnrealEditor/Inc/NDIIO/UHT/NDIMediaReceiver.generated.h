// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Objects/Media/NDIMediaReceiver.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
 
class UNDIMediaReceiver;
class UNDIMediaTexture2D;
struct FFrameRate;
struct FNDIConnectionInformation;
struct FNDIReceiverPerformanceData;
struct FTimecode;
#ifdef NDIIO_NDIMediaReceiver_generated_h
#error "NDIMediaReceiver.generated.h already included, missing '#pragma once' in NDIMediaReceiver.h"
#endif
#define NDIIO_NDIMediaReceiver_generated_h

#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaReceiver_h_38_DELEGATE \
NDIIO_API void FNDIMediaReceiverVideoReceived_DelegateWrapper(const FMulticastScriptDelegate& NDIMediaReceiverVideoReceived, UNDIMediaReceiver* Receiver);


#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaReceiver_h_39_DELEGATE \
NDIIO_API void FNDIMediaReceiverAudioReceived_DelegateWrapper(const FMulticastScriptDelegate& NDIMediaReceiverAudioReceived, UNDIMediaReceiver* Receiver);


#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaReceiver_h_40_DELEGATE \
NDIIO_API void FNDIMediaReceiverMetaDataReceived_DelegateWrapper(const FMulticastScriptDelegate& NDIMediaReceiverMetaDataReceived, UNDIMediaReceiver* Receiver, const FString& Data, bool bAttachedToVideoFrame);


#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaReceiver_h_51_SPARSE_DATA
#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaReceiver_h_51_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaReceiver_h_51_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaReceiver_h_51_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetIsCurrentlyConnected); \
	DECLARE_FUNCTION(execGetPerformanceData); \
	DECLARE_FUNCTION(execGetCurrentConnectionInformation); \
	DECLARE_FUNCTION(execGetCurrentTimecode); \
	DECLARE_FUNCTION(execGetCurrentResolution); \
	DECLARE_FUNCTION(execGetCurrentFrameRate); \
	DECLARE_FUNCTION(execSendMetadataFrameAttrs); \
	DECLARE_FUNCTION(execSendMetadataFrameAttr); \
	DECLARE_FUNCTION(execSendMetadataFrame); \
	DECLARE_FUNCTION(execChangeVideoTexture); \
	DECLARE_FUNCTION(execChangeConnection); \
	DECLARE_FUNCTION(execStopConnection); \
	DECLARE_FUNCTION(execStartConnection);


#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaReceiver_h_51_ACCESSORS
#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaReceiver_h_51_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUNDIMediaReceiver(); \
	friend struct Z_Construct_UClass_UNDIMediaReceiver_Statics; \
public: \
	DECLARE_CLASS(UNDIMediaReceiver, UTimeSynchronizableMediaSource, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/NDIIO"), NO_API) \
	DECLARE_SERIALIZER(UNDIMediaReceiver)


#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaReceiver_h_51_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UNDIMediaReceiver(UNDIMediaReceiver&&); \
	NO_API UNDIMediaReceiver(const UNDIMediaReceiver&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UNDIMediaReceiver); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UNDIMediaReceiver); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UNDIMediaReceiver) \
	NO_API virtual ~UNDIMediaReceiver();


#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaReceiver_h_48_PROLOG
#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaReceiver_h_51_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaReceiver_h_51_SPARSE_DATA \
	FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaReceiver_h_51_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaReceiver_h_51_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaReceiver_h_51_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaReceiver_h_51_ACCESSORS \
	FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaReceiver_h_51_INCLASS_NO_PURE_DECLS \
	FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaReceiver_h_51_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> NDIIO_API UClass* StaticClass<class UNDIMediaReceiver>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaReceiver_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
