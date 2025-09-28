// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Objects/Media/NDIMediaSender.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
 
class UNDIMediaSender;
struct FNDIBroadcastConfiguration;
#ifdef NDIIO_NDIMediaSender_generated_h
#error "NDIMediaSender.generated.h already included, missing '#pragma once' in NDIMediaSender.h"
#endif
#define NDIIO_NDIMediaSender_generated_h

#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaSender_h_29_DELEGATE \
NDIIO_API void FNDIMediaSenderPropertyChanged_DelegateWrapper(const FMulticastScriptDelegate& NDIMediaSenderPropertyChanged, UNDIMediaSender* Sender);


#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaSender_h_34_DELEGATE \
NDIIO_API void FNDIMediaSenderMetaDataReceived_DelegateWrapper(const FMulticastScriptDelegate& NDIMediaSenderMetaDataReceived, UNDIMediaSender* Sender, const FString& Data);


#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaSender_h_39_DELEGATE \
NDIIO_API void FNDIMediaSenderVideoPreSend_DelegateWrapper(const FMulticastScriptDelegate& NDIMediaSenderVideoPreSend, UNDIMediaSender* Sender);


#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaSender_h_40_DELEGATE \
NDIIO_API void FNDIMediaSenderVideoSent_DelegateWrapper(const FMulticastScriptDelegate& NDIMediaSenderVideoSent, UNDIMediaSender* Sender);


#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaSender_h_42_DELEGATE \
NDIIO_API void FNDIMediaSenderAudioPreSend_DelegateWrapper(const FMulticastScriptDelegate& NDIMediaSenderAudioPreSend, UNDIMediaSender* Sender);


#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaSender_h_43_DELEGATE \
NDIIO_API void FNDIMediaSenderAudioSent_DelegateWrapper(const FMulticastScriptDelegate& NDIMediaSenderAudioSent, UNDIMediaSender* Sender);


#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaSender_h_45_DELEGATE \
NDIIO_API void FNDIMediaSenderMetaDataPreSend_DelegateWrapper(const FMulticastScriptDelegate& NDIMediaSenderMetaDataPreSend, UNDIMediaSender* Sender);


#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaSender_h_46_DELEGATE \
NDIIO_API void FNDIMediaSenderMetaDataSent_DelegateWrapper(const FMulticastScriptDelegate& NDIMediaSenderMetaDataSent, UNDIMediaSender* Sender);


#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaSender_h_57_SPARSE_DATA
#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaSender_h_57_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaSender_h_57_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaSender_h_57_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSendMetadataFrameAttrs); \
	DECLARE_FUNCTION(execSendMetadataFrameAttr); \
	DECLARE_FUNCTION(execSendMetadataFrame); \
	DECLARE_FUNCTION(execChangeBroadcastConfiguration); \
	DECLARE_FUNCTION(execChangeSourceName);


#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaSender_h_57_ACCESSORS
#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaSender_h_57_INCLASS \
private: \
	static void StaticRegisterNativesUNDIMediaSender(); \
	friend struct Z_Construct_UClass_UNDIMediaSender_Statics; \
public: \
	DECLARE_CLASS(UNDIMediaSender, UBaseMediaSource, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/NDIIO"), NO_API) \
	DECLARE_SERIALIZER(UNDIMediaSender)


#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaSender_h_57_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UNDIMediaSender(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UNDIMediaSender) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UNDIMediaSender); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UNDIMediaSender); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UNDIMediaSender(UNDIMediaSender&&); \
	NO_API UNDIMediaSender(const UNDIMediaSender&); \
public: \
	NO_API virtual ~UNDIMediaSender();


#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaSender_h_54_PROLOG
#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaSender_h_57_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaSender_h_57_SPARSE_DATA \
	FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaSender_h_57_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaSender_h_57_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaSender_h_57_RPC_WRAPPERS \
	FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaSender_h_57_ACCESSORS \
	FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaSender_h_57_INCLASS \
	FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaSender_h_57_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> NDIIO_API UClass* StaticClass<class UNDIMediaSender>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaSender_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
