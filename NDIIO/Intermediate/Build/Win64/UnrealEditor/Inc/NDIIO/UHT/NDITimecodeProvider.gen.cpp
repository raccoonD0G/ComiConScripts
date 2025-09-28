// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Assets/NDITimecodeProvider.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNDITimecodeProvider() {}
// Cross Module References
	NDIIO_API UClass* Z_Construct_UClass_UNDIMediaReceiver_NoRegister();
	NDIIO_API UClass* Z_Construct_UClass_UNDITimecodeProvider();
	NDIIO_API UClass* Z_Construct_UClass_UNDITimecodeProvider_NoRegister();
	TIMEMANAGEMENT_API UClass* Z_Construct_UClass_UGenlockedTimecodeProvider();
	UPackage* Z_Construct_UPackage__Script_NDIIO();
// End Cross Module References
	void UNDITimecodeProvider::StaticRegisterNativesUNDITimecodeProvider()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UNDITimecodeProvider);
	UClass* Z_Construct_UClass_UNDITimecodeProvider_NoRegister()
	{
		return UNDITimecodeProvider::StaticClass();
	}
	struct Z_Construct_UClass_UNDITimecodeProvider_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NDIMediaSource_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_NDIMediaSource;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UNDITimecodeProvider_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGenlockedTimecodeProvider,
		(UObject* (*)())Z_Construct_UPackage__Script_NDIIO,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UNDITimecodeProvider_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNDITimecodeProvider_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09Timecode provider from an NDI source\n*/" },
#endif
		{ "DisplayName", "NDI Timecode Provider" },
		{ "IncludePath", "Assets/NDITimecodeProvider.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Assets/NDITimecodeProvider.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Timecode provider from an NDI source" },
#endif
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNDITimecodeProvider_Statics::NewProp_NDIMediaSource_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "NDI IO" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The Receiver object used to get timecodes from */" },
#endif
		{ "DisplayName", "NDI Media Source" },
		{ "ModuleRelativePath", "Public/Assets/NDITimecodeProvider.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The Receiver object used to get timecodes from" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UNDITimecodeProvider_Statics::NewProp_NDIMediaSource = { "NDIMediaSource", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNDITimecodeProvider, NDIMediaSource), Z_Construct_UClass_UNDIMediaReceiver_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UNDITimecodeProvider_Statics::NewProp_NDIMediaSource_MetaData), Z_Construct_UClass_UNDITimecodeProvider_Statics::NewProp_NDIMediaSource_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UNDITimecodeProvider_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNDITimecodeProvider_Statics::NewProp_NDIMediaSource,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UNDITimecodeProvider_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UNDITimecodeProvider>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UNDITimecodeProvider_Statics::ClassParams = {
		&UNDITimecodeProvider::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UNDITimecodeProvider_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UNDITimecodeProvider_Statics::PropPointers),
		0,
		0x001010A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UNDITimecodeProvider_Statics::Class_MetaDataParams), Z_Construct_UClass_UNDITimecodeProvider_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UNDITimecodeProvider_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UNDITimecodeProvider()
	{
		if (!Z_Registration_Info_UClass_UNDITimecodeProvider.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UNDITimecodeProvider.OuterSingleton, Z_Construct_UClass_UNDITimecodeProvider_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UNDITimecodeProvider.OuterSingleton;
	}
	template<> NDIIO_API UClass* StaticClass<UNDITimecodeProvider>()
	{
		return UNDITimecodeProvider::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UNDITimecodeProvider);
	UNDITimecodeProvider::~UNDITimecodeProvider() {}
	struct Z_CompiledInDeferFile_FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Assets_NDITimecodeProvider_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Assets_NDITimecodeProvider_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UNDITimecodeProvider, UNDITimecodeProvider::StaticClass, TEXT("UNDITimecodeProvider"), &Z_Registration_Info_UClass_UNDITimecodeProvider, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UNDITimecodeProvider), 2468354010U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Assets_NDITimecodeProvider_h_2733100991(TEXT("/Script/NDIIO"),
		Z_CompiledInDeferFile_FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Assets_NDITimecodeProvider_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Assets_NDITimecodeProvider_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
