// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Components/NDIBroadcastComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UTextureRenderTarget2D;
struct FNDIBroadcastConfiguration;
#ifdef NDIIO_NDIBroadcastComponent_generated_h
#error "NDIBroadcastComponent.generated.h already included, missing '#pragma once' in NDIBroadcastComponent.h"
#endif
#define NDIIO_NDIBroadcastComponent_generated_h

#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIBroadcastComponent_h_26_SPARSE_DATA
#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIBroadcastComponent_h_26_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIBroadcastComponent_h_26_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIBroadcastComponent_h_26_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execStopBroadcasting); \
	DECLARE_FUNCTION(execGetNumberOfConnections); \
	DECLARE_FUNCTION(execGetTallyInformation); \
	DECLARE_FUNCTION(execChangeBroadcastTexture); \
	DECLARE_FUNCTION(execChangeBroadcastConfiguration); \
	DECLARE_FUNCTION(execChangeSourceName); \
	DECLARE_FUNCTION(execStartBroadcasting);


#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIBroadcastComponent_h_26_ACCESSORS
#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIBroadcastComponent_h_26_INCLASS \
private: \
	static void StaticRegisterNativesUNDIBroadcastComponent(); \
	friend struct Z_Construct_UClass_UNDIBroadcastComponent_Statics; \
public: \
	DECLARE_CLASS(UNDIBroadcastComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/NDIIO"), NO_API) \
	DECLARE_SERIALIZER(UNDIBroadcastComponent)


#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIBroadcastComponent_h_26_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UNDIBroadcastComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UNDIBroadcastComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UNDIBroadcastComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UNDIBroadcastComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UNDIBroadcastComponent(UNDIBroadcastComponent&&); \
	NO_API UNDIBroadcastComponent(const UNDIBroadcastComponent&); \
public: \
	NO_API virtual ~UNDIBroadcastComponent();


#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIBroadcastComponent_h_23_PROLOG
#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIBroadcastComponent_h_26_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIBroadcastComponent_h_26_SPARSE_DATA \
	FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIBroadcastComponent_h_26_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIBroadcastComponent_h_26_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIBroadcastComponent_h_26_RPC_WRAPPERS \
	FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIBroadcastComponent_h_26_ACCESSORS \
	FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIBroadcastComponent_h_26_INCLASS \
	FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIBroadcastComponent_h_26_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> NDIIO_API UClass* StaticClass<class UNDIBroadcastComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIBroadcastComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
