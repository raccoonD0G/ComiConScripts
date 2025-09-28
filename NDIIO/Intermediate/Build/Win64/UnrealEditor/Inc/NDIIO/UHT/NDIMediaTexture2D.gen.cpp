// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Objects/Media/NDIMediaTexture2D.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNDIMediaTexture2D() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UTexture();
	NDIIO_API UClass* Z_Construct_UClass_UNDIMediaTexture2D();
	NDIIO_API UClass* Z_Construct_UClass_UNDIMediaTexture2D_NoRegister();
	UPackage* Z_Construct_UPackage__Script_NDIIO();
// End Cross Module References
	void UNDIMediaTexture2D::StaticRegisterNativesUNDIMediaTexture2D()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UNDIMediaTexture2D);
	UClass* Z_Construct_UClass_UNDIMediaTexture2D_NoRegister()
	{
		return UNDIMediaTexture2D::StaticClass();
	}
	struct Z_Construct_UClass_UNDIMediaTexture2D_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultWidth_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_DefaultWidth;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultHeight_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_DefaultHeight;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UNDIMediaTexture2D_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UTexture,
		(UObject* (*)())Z_Construct_UPackage__Script_NDIIO,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UNDIMediaTexture2D_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNDIMediaTexture2D_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09""A Texture Object used by an NDI Media Receiver object for capturing video from\n\x09""a network source\n*/" },
#endif
		{ "DisplayName", "NDI Media Texture 2D" },
		{ "HideCategories", "ImportSettings Compression Texture Adjustments Compositing LevelOfDetail Object" },
		{ "IncludePath", "Objects/Media/NDIMediaTexture2D.h" },
		{ "IsBlueprintBase", "false" },
		{ "ModuleRelativePath", "Public/Objects/Media/NDIMediaTexture2D.h" },
		{ "NotBlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A Texture Object used by an NDI Media Receiver object for capturing video from\na network source" },
#endif
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNDIMediaTexture2D_Statics::NewProp_DefaultWidth_MetaData[] = {
		{ "Category", "NDIMediaTexture2D" },
		{ "ModuleRelativePath", "Public/Objects/Media/NDIMediaTexture2D.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UNDIMediaTexture2D_Statics::NewProp_DefaultWidth = { "DefaultWidth", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNDIMediaTexture2D, DefaultWidth), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UNDIMediaTexture2D_Statics::NewProp_DefaultWidth_MetaData), Z_Construct_UClass_UNDIMediaTexture2D_Statics::NewProp_DefaultWidth_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNDIMediaTexture2D_Statics::NewProp_DefaultHeight_MetaData[] = {
		{ "Category", "NDIMediaTexture2D" },
		{ "ModuleRelativePath", "Public/Objects/Media/NDIMediaTexture2D.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UNDIMediaTexture2D_Statics::NewProp_DefaultHeight = { "DefaultHeight", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNDIMediaTexture2D, DefaultHeight), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UNDIMediaTexture2D_Statics::NewProp_DefaultHeight_MetaData), Z_Construct_UClass_UNDIMediaTexture2D_Statics::NewProp_DefaultHeight_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UNDIMediaTexture2D_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNDIMediaTexture2D_Statics::NewProp_DefaultWidth,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNDIMediaTexture2D_Statics::NewProp_DefaultHeight,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UNDIMediaTexture2D_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UNDIMediaTexture2D>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UNDIMediaTexture2D_Statics::ClassParams = {
		&UNDIMediaTexture2D::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UNDIMediaTexture2D_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UNDIMediaTexture2D_Statics::PropPointers),
		0,
		0x049000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UNDIMediaTexture2D_Statics::Class_MetaDataParams), Z_Construct_UClass_UNDIMediaTexture2D_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UNDIMediaTexture2D_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UNDIMediaTexture2D()
	{
		if (!Z_Registration_Info_UClass_UNDIMediaTexture2D.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UNDIMediaTexture2D.OuterSingleton, Z_Construct_UClass_UNDIMediaTexture2D_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UNDIMediaTexture2D.OuterSingleton;
	}
	template<> NDIIO_API UClass* StaticClass<UNDIMediaTexture2D>()
	{
		return UNDIMediaTexture2D::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UNDIMediaTexture2D);
	UNDIMediaTexture2D::~UNDIMediaTexture2D() {}
	struct Z_CompiledInDeferFile_FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaTexture2D_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaTexture2D_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UNDIMediaTexture2D, UNDIMediaTexture2D::StaticClass, TEXT("UNDIMediaTexture2D"), &Z_Registration_Info_UClass_UNDIMediaTexture2D, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UNDIMediaTexture2D), 2448376608U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaTexture2D_h_4054255423(TEXT("/Script/NDIIO"),
		Z_CompiledInDeferFile_FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaTexture2D_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Objects_Media_NDIMediaTexture2D_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
