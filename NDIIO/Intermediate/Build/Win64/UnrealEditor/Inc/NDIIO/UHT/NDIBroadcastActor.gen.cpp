// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Actors/NDIBroadcastActor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNDIBroadcastActor() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_USoundSubmix_NoRegister();
	NDIIO_API UClass* Z_Construct_UClass_ANDIBroadcastActor();
	NDIIO_API UClass* Z_Construct_UClass_ANDIBroadcastActor_NoRegister();
	NDIIO_API UClass* Z_Construct_UClass_UNDIMediaSender_NoRegister();
	NDIIO_API UClass* Z_Construct_UClass_UNDIViewportCaptureComponent_NoRegister();
	NDIIO_API UClass* Z_Construct_UClass_UPTZControllableInterface_NoRegister();
	NDIIO_API UClass* Z_Construct_UClass_UPTZController_NoRegister();
	UPackage* Z_Construct_UPackage__Script_NDIIO();
// End Cross Module References
	void ANDIBroadcastActor::StaticRegisterNativesANDIBroadcastActor()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ANDIBroadcastActor);
	UClass* Z_Construct_UClass_ANDIBroadcastActor_NoRegister()
	{
		return ANDIBroadcastActor::StaticClass();
	}
	struct Z_Construct_UClass_ANDIBroadcastActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NDIMediaSource_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_NDIMediaSource;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ViewportCaptureComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ViewportCaptureComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SubmixCapture_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SubmixCapture;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PTZController_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PTZController;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ANDIBroadcastActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_NDIIO,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANDIBroadcastActor_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANDIBroadcastActor_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Category", "NDI IO" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09""A quick and easy way to capture the from the perspective of a camera that starts broadcasting the viewport\n\x09immediate upon 'BeginPlay'\n*/" },
#endif
		{ "DisplayName", "NDI Broadcast Actor" },
		{ "IncludePath", "Actors/NDIBroadcastActor.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Actors/NDIBroadcastActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A quick and easy way to capture the from the perspective of a camera that starts broadcasting the viewport\nimmediate upon 'BeginPlay'" },
#endif
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANDIBroadcastActor_Statics::NewProp_NDIMediaSource_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "NDI IO" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09\x09The NDI Media Sender representing the configuration of the network source to send audio, video, and metadata\n\x09*/" },
#endif
		{ "DisplayName", "NDI Media Source" },
		{ "ModuleRelativePath", "Public/Actors/NDIBroadcastActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The NDI Media Sender representing the configuration of the network source to send audio, video, and metadata" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANDIBroadcastActor_Statics::NewProp_NDIMediaSource = { "NDIMediaSource", nullptr, (EPropertyFlags)0x0040000000000805, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANDIBroadcastActor, NDIMediaSource), Z_Construct_UClass_UNDIMediaSender_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANDIBroadcastActor_Statics::NewProp_NDIMediaSource_MetaData), Z_Construct_UClass_ANDIBroadcastActor_Statics::NewProp_NDIMediaSource_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANDIBroadcastActor_Statics::NewProp_ViewportCaptureComponent_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "NDI IO" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09\x09""A component used to capture an additional viewport for broadcasting over NDI\n\x09*/" },
#endif
		{ "DisplayName", "Viewport Capture Component" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Actors/NDIBroadcastActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A component used to capture an additional viewport for broadcasting over NDI" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANDIBroadcastActor_Statics::NewProp_ViewportCaptureComponent = { "ViewportCaptureComponent", nullptr, (EPropertyFlags)0x004000000009000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANDIBroadcastActor, ViewportCaptureComponent), Z_Construct_UClass_UNDIViewportCaptureComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANDIBroadcastActor_Statics::NewProp_ViewportCaptureComponent_MetaData), Z_Construct_UClass_ANDIBroadcastActor_Statics::NewProp_ViewportCaptureComponent_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANDIBroadcastActor_Statics::NewProp_SubmixCapture_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "NDI IO" },
		{ "DisplayName", "Audio Submix Capture" },
		{ "ModuleRelativePath", "Public/Actors/NDIBroadcastActor.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANDIBroadcastActor_Statics::NewProp_SubmixCapture = { "SubmixCapture", nullptr, (EPropertyFlags)0x0040000000000805, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANDIBroadcastActor, SubmixCapture), Z_Construct_UClass_USoundSubmix_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANDIBroadcastActor_Statics::NewProp_SubmixCapture_MetaData), Z_Construct_UClass_ANDIBroadcastActor_Statics::NewProp_SubmixCapture_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANDIBroadcastActor_Statics::NewProp_PTZController_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "NDI IO" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09\x09""Component used for PTZ control\n\x09*/" },
#endif
		{ "DisplayName", "PTZ Controller" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Actors/NDIBroadcastActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Component used for PTZ control" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANDIBroadcastActor_Statics::NewProp_PTZController = { "PTZController", nullptr, (EPropertyFlags)0x004000000009000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANDIBroadcastActor, PTZController), Z_Construct_UClass_UPTZController_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANDIBroadcastActor_Statics::NewProp_PTZController_MetaData), Z_Construct_UClass_ANDIBroadcastActor_Statics::NewProp_PTZController_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ANDIBroadcastActor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANDIBroadcastActor_Statics::NewProp_NDIMediaSource,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANDIBroadcastActor_Statics::NewProp_ViewportCaptureComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANDIBroadcastActor_Statics::NewProp_SubmixCapture,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANDIBroadcastActor_Statics::NewProp_PTZController,
	};
		const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_ANDIBroadcastActor_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UPTZControllableInterface_NoRegister, (int32)VTABLE_OFFSET(ANDIBroadcastActor, IPTZControllableInterface), false },  // 4196887756
		};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANDIBroadcastActor_Statics::InterfaceParams) < 64);
	const FCppClassTypeInfoStatic Z_Construct_UClass_ANDIBroadcastActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANDIBroadcastActor>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ANDIBroadcastActor_Statics::ClassParams = {
		&ANDIBroadcastActor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ANDIBroadcastActor_Statics::PropPointers,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ANDIBroadcastActor_Statics::PropPointers),
		UE_ARRAY_COUNT(InterfaceParams),
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANDIBroadcastActor_Statics::Class_MetaDataParams), Z_Construct_UClass_ANDIBroadcastActor_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANDIBroadcastActor_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ANDIBroadcastActor()
	{
		if (!Z_Registration_Info_UClass_ANDIBroadcastActor.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ANDIBroadcastActor.OuterSingleton, Z_Construct_UClass_ANDIBroadcastActor_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ANDIBroadcastActor.OuterSingleton;
	}
	template<> NDIIO_API UClass* StaticClass<ANDIBroadcastActor>()
	{
		return ANDIBroadcastActor::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ANDIBroadcastActor);
	ANDIBroadcastActor::~ANDIBroadcastActor() {}
	struct Z_CompiledInDeferFile_FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Actors_NDIBroadcastActor_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Actors_NDIBroadcastActor_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ANDIBroadcastActor, ANDIBroadcastActor::StaticClass, TEXT("ANDIBroadcastActor"), &Z_Registration_Info_UClass_ANDIBroadcastActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ANDIBroadcastActor), 3251331830U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Actors_NDIBroadcastActor_h_373342052(TEXT("/Script/NDIIO"),
		Z_CompiledInDeferFile_FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Actors_NDIBroadcastActor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Actors_NDIBroadcastActor_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
