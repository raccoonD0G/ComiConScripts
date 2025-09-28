// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Enumerations/NDIAudioChannels.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNDIAudioChannels() {}
// Cross Module References
	NDIIO_API UEnum* Z_Construct_UEnum_NDIIO_ENDIAudioChannels();
	UPackage* Z_Construct_UPackage__Script_NDIIO();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ENDIAudioChannels;
	static UEnum* ENDIAudioChannels_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ENDIAudioChannels.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ENDIAudioChannels.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_NDIIO_ENDIAudioChannels, (UObject*)Z_Construct_UPackage__Script_NDIIO(), TEXT("ENDIAudioChannels"));
		}
		return Z_Registration_Info_UEnum_ENDIAudioChannels.OuterSingleton;
	}
	template<> NDIIO_API UEnum* StaticEnum<ENDIAudioChannels>()
	{
		return ENDIAudioChannels_StaticEnum();
	}
	struct Z_Construct_UEnum_NDIIO_ENDIAudioChannels_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_NDIIO_ENDIAudioChannels_Statics::Enumerators[] = {
		{ "ENDIAudioChannels::Mono", (int64)ENDIAudioChannels::Mono },
		{ "ENDIAudioChannels::Stereo", (int64)ENDIAudioChannels::Stereo },
		{ "ENDIAudioChannels::Source", (int64)ENDIAudioChannels::Source },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_NDIIO_ENDIAudioChannels_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09Receiver Bandwidth modes\n*/" },
#endif
		{ "DisplayName", "NDI Audio Channels" },
		{ "ModuleRelativePath", "Public/Enumerations/NDIAudioChannels.h" },
		{ "Mono.Comment", "/** Mono. */" },
		{ "Mono.DisplayName", "Mono" },
		{ "Mono.Name", "ENDIAudioChannels::Mono" },
		{ "Mono.ToolTip", "Mono." },
		{ "Source.Comment", "/** Whatever the number of channels in the source is. */" },
		{ "Source.DisplayName", "Source" },
		{ "Source.Name", "ENDIAudioChannels::Source" },
		{ "Source.ToolTip", "Whatever the number of channels in the source is." },
		{ "Stereo.Comment", "/** Stereo. */" },
		{ "Stereo.DisplayName", "Stereo" },
		{ "Stereo.Name", "ENDIAudioChannels::Stereo" },
		{ "Stereo.ToolTip", "Stereo." },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Receiver Bandwidth modes" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_NDIIO_ENDIAudioChannels_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_NDIIO,
		nullptr,
		"ENDIAudioChannels",
		"ENDIAudioChannels",
		Z_Construct_UEnum_NDIIO_ENDIAudioChannels_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_NDIIO_ENDIAudioChannels_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_NDIIO_ENDIAudioChannels_Statics::Enum_MetaDataParams), Z_Construct_UEnum_NDIIO_ENDIAudioChannels_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_NDIIO_ENDIAudioChannels()
	{
		if (!Z_Registration_Info_UEnum_ENDIAudioChannels.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ENDIAudioChannels.InnerSingleton, Z_Construct_UEnum_NDIIO_ENDIAudioChannels_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ENDIAudioChannels.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Enumerations_NDIAudioChannels_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Enumerations_NDIAudioChannels_h_Statics::EnumInfo[] = {
		{ ENDIAudioChannels_StaticEnum, TEXT("ENDIAudioChannels"), &Z_Registration_Info_UEnum_ENDIAudioChannels, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1987648875U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Enumerations_NDIAudioChannels_h_3043965697(TEXT("/Script/NDIIO"),
		nullptr, 0,
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Enumerations_NDIAudioChannels_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Enumerations_NDIAudioChannels_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
