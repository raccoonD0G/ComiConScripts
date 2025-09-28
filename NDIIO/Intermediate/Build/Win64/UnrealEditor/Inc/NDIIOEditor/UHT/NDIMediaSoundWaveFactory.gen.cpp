// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Factories/NDIMediaSoundWaveFactory.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNDIMediaSoundWaveFactory() {}
// Cross Module References
	NDIIOEDITOR_API UClass* Z_Construct_UClass_UNDIMediaSoundWaveFactory();
	NDIIOEDITOR_API UClass* Z_Construct_UClass_UNDIMediaSoundWaveFactory_NoRegister();
	UNREALED_API UClass* Z_Construct_UClass_UFactory();
	UPackage* Z_Construct_UPackage__Script_NDIIOEditor();
// End Cross Module References
	void UNDIMediaSoundWaveFactory::StaticRegisterNativesUNDIMediaSoundWaveFactory()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UNDIMediaSoundWaveFactory);
	UClass* Z_Construct_UClass_UNDIMediaSoundWaveFactory_NoRegister()
	{
		return UNDIMediaSoundWaveFactory::StaticClass();
	}
	struct Z_Construct_UClass_UNDIMediaSoundWaveFactory_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UNDIMediaSoundWaveFactory_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UFactory,
		(UObject* (*)())Z_Construct_UPackage__Script_NDIIOEditor,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UNDIMediaSoundWaveFactory_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNDIMediaSoundWaveFactory_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09""Factory Class used to create assets via content browser for NDI Sound Wave objects\n*/" },
#endif
		{ "IncludePath", "Factories/NDIMediaSoundWaveFactory.h" },
		{ "ModuleRelativePath", "Public/Factories/NDIMediaSoundWaveFactory.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Factory Class used to create assets via content browser for NDI Sound Wave objects" },
#endif
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UNDIMediaSoundWaveFactory_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UNDIMediaSoundWaveFactory>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UNDIMediaSoundWaveFactory_Statics::ClassParams = {
		&UNDIMediaSoundWaveFactory::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UNDIMediaSoundWaveFactory_Statics::Class_MetaDataParams), Z_Construct_UClass_UNDIMediaSoundWaveFactory_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UNDIMediaSoundWaveFactory()
	{
		if (!Z_Registration_Info_UClass_UNDIMediaSoundWaveFactory.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UNDIMediaSoundWaveFactory.OuterSingleton, Z_Construct_UClass_UNDIMediaSoundWaveFactory_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UNDIMediaSoundWaveFactory.OuterSingleton;
	}
	template<> NDIIOEDITOR_API UClass* StaticClass<UNDIMediaSoundWaveFactory>()
	{
		return UNDIMediaSoundWaveFactory::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UNDIMediaSoundWaveFactory);
	UNDIMediaSoundWaveFactory::~UNDIMediaSoundWaveFactory() {}
	struct Z_CompiledInDeferFile_FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Editor_Public_Factories_NDIMediaSoundWaveFactory_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Editor_Public_Factories_NDIMediaSoundWaveFactory_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UNDIMediaSoundWaveFactory, UNDIMediaSoundWaveFactory::StaticClass, TEXT("UNDIMediaSoundWaveFactory"), &Z_Registration_Info_UClass_UNDIMediaSoundWaveFactory, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UNDIMediaSoundWaveFactory), 2689586035U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Editor_Public_Factories_NDIMediaSoundWaveFactory_h_3421430433(TEXT("/Script/NDIIOEditor"),
		Z_CompiledInDeferFile_FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Editor_Public_Factories_NDIMediaSoundWaveFactory_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Editor_Public_Factories_NDIMediaSoundWaveFactory_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
