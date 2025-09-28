// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Components/NDIFinderComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UNDIFinderComponent;
struct FNDIConnectionInformation;
#ifdef NDIIO_NDIFinderComponent_generated_h
#error "NDIFinderComponent.generated.h already included, missing '#pragma once' in NDIFinderComponent.h"
#endif
#define NDIIO_NDIFinderComponent_generated_h

#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIFinderComponent_h_20_DELEGATE \
NDIIO_API void FNDIFinderServiceCollectionChangedDelegate_DelegateWrapper(const FMulticastScriptDelegate& NDIFinderServiceCollectionChangedDelegate, UNDIFinderComponent* InComponent);


#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIFinderComponent_h_32_SPARSE_DATA
#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIFinderComponent_h_32_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIFinderComponent_h_32_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIFinderComponent_h_32_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnNetworkSourceCollectionChangedEvent); \
	DECLARE_FUNCTION(execGetNetworkSources); \
	DECLARE_FUNCTION(execFindNetworkSourceByName);


#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIFinderComponent_h_32_ACCESSORS
#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIFinderComponent_h_32_CALLBACK_WRAPPERS
#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIFinderComponent_h_32_INCLASS \
private: \
	static void StaticRegisterNativesUNDIFinderComponent(); \
	friend struct Z_Construct_UClass_UNDIFinderComponent_Statics; \
public: \
	DECLARE_CLASS(UNDIFinderComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/NDIIO"), NO_API) \
	DECLARE_SERIALIZER(UNDIFinderComponent)


#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIFinderComponent_h_32_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UNDIFinderComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UNDIFinderComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UNDIFinderComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UNDIFinderComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UNDIFinderComponent(UNDIFinderComponent&&); \
	NO_API UNDIFinderComponent(const UNDIFinderComponent&); \
public: \
	NO_API virtual ~UNDIFinderComponent();


#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIFinderComponent_h_29_PROLOG
#define FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIFinderComponent_h_32_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIFinderComponent_h_32_SPARSE_DATA \
	FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIFinderComponent_h_32_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIFinderComponent_h_32_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIFinderComponent_h_32_RPC_WRAPPERS \
	FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIFinderComponent_h_32_ACCESSORS \
	FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIFinderComponent_h_32_CALLBACK_WRAPPERS \
	FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIFinderComponent_h_32_INCLASS \
	FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIFinderComponent_h_32_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> NDIIO_API UClass* StaticClass<class UNDIFinderComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIFinderComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
