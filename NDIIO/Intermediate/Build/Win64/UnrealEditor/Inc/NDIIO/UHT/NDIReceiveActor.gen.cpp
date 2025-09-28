// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Actors/NDIReceiveActor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNDIReceiveActor() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_UAudioComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	NDIIO_API UClass* Z_Construct_UClass_ANDIReceiveActor();
	NDIIO_API UClass* Z_Construct_UClass_ANDIReceiveActor_NoRegister();
	NDIIO_API UClass* Z_Construct_UClass_UNDIMediaReceiver_NoRegister();
	NDIIO_API UClass* Z_Construct_UClass_UNDIMediaSoundWave_NoRegister();
	NDIIO_API UEnum* Z_Construct_UEnum_NDIIO_ENDIAudioChannels();
	UPackage* Z_Construct_UPackage__Script_NDIIO();
// End Cross Module References
	DEFINE_FUNCTION(ANDIReceiveActor::execEnableAlpha)
	{
		P_GET_UBOOL_REF(Z_Param_Out_Enabled);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->EnableAlpha(Z_Param_Out_Enabled);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANDIReceiveActor::execEnableColor)
	{
		P_GET_UBOOL_REF(Z_Param_Out_Enabled);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->EnableColor(Z_Param_Out_Enabled);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANDIReceiveActor::execUpdateAudioPlaybackChannels)
	{
		P_GET_ENUM_REF(ENDIAudioChannels,Z_Param_Out_Channels);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdateAudioPlaybackChannels((ENDIAudioChannels&)(Z_Param_Out_Channels));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANDIReceiveActor::execUpdateAudioPlayback)
	{
		P_GET_UBOOL_REF(Z_Param_Out_Enabled);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdateAudioPlayback(Z_Param_Out_Enabled);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANDIReceiveActor::execSetFrameWidth)
	{
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_InFrameWidth);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetFrameWidth(Z_Param_Out_InFrameWidth);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANDIReceiveActor::execSetFrameHeight)
	{
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_InFrameHeight);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetFrameHeight(Z_Param_Out_InFrameHeight);
		P_NATIVE_END;
	}
	void ANDIReceiveActor::StaticRegisterNativesANDIReceiveActor()
	{
		UClass* Class = ANDIReceiveActor::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "EnableAlpha", &ANDIReceiveActor::execEnableAlpha },
			{ "EnableColor", &ANDIReceiveActor::execEnableColor },
			{ "SetFrameHeight", &ANDIReceiveActor::execSetFrameHeight },
			{ "SetFrameWidth", &ANDIReceiveActor::execSetFrameWidth },
			{ "UpdateAudioPlayback", &ANDIReceiveActor::execUpdateAudioPlayback },
			{ "UpdateAudioPlaybackChannels", &ANDIReceiveActor::execUpdateAudioPlaybackChannels },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ANDIReceiveActor_EnableAlpha_Statics
	{
		struct NDIReceiveActor_eventEnableAlpha_Parms
		{
			bool Enabled;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Enabled_MetaData[];
#endif
		static void NewProp_Enabled_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Enabled;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANDIReceiveActor_EnableAlpha_Statics::NewProp_Enabled_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_ANDIReceiveActor_EnableAlpha_Statics::NewProp_Enabled_SetBit(void* Obj)
	{
		((NDIReceiveActor_eventEnableAlpha_Parms*)Obj)->Enabled = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ANDIReceiveActor_EnableAlpha_Statics::NewProp_Enabled = { "Enabled", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(NDIReceiveActor_eventEnableAlpha_Parms), &Z_Construct_UFunction_ANDIReceiveActor_EnableAlpha_Statics::NewProp_Enabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANDIReceiveActor_EnableAlpha_Statics::NewProp_Enabled_MetaData), Z_Construct_UFunction_ANDIReceiveActor_EnableAlpha_Statics::NewProp_Enabled_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANDIReceiveActor_EnableAlpha_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANDIReceiveActor_EnableAlpha_Statics::NewProp_Enabled,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANDIReceiveActor_EnableAlpha_Statics::Function_MetaDataParams[] = {
		{ "BlueprintSetter", "" },
		{ "ModuleRelativePath", "Public/Actors/NDIReceiveActor.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANDIReceiveActor_EnableAlpha_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANDIReceiveActor, nullptr, "EnableAlpha", nullptr, nullptr, Z_Construct_UFunction_ANDIReceiveActor_EnableAlpha_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANDIReceiveActor_EnableAlpha_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANDIReceiveActor_EnableAlpha_Statics::NDIReceiveActor_eventEnableAlpha_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04440401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANDIReceiveActor_EnableAlpha_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANDIReceiveActor_EnableAlpha_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANDIReceiveActor_EnableAlpha_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ANDIReceiveActor_EnableAlpha_Statics::NDIReceiveActor_eventEnableAlpha_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANDIReceiveActor_EnableAlpha()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANDIReceiveActor_EnableAlpha_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANDIReceiveActor_EnableColor_Statics
	{
		struct NDIReceiveActor_eventEnableColor_Parms
		{
			bool Enabled;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Enabled_MetaData[];
#endif
		static void NewProp_Enabled_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Enabled;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANDIReceiveActor_EnableColor_Statics::NewProp_Enabled_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_ANDIReceiveActor_EnableColor_Statics::NewProp_Enabled_SetBit(void* Obj)
	{
		((NDIReceiveActor_eventEnableColor_Parms*)Obj)->Enabled = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ANDIReceiveActor_EnableColor_Statics::NewProp_Enabled = { "Enabled", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(NDIReceiveActor_eventEnableColor_Parms), &Z_Construct_UFunction_ANDIReceiveActor_EnableColor_Statics::NewProp_Enabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANDIReceiveActor_EnableColor_Statics::NewProp_Enabled_MetaData), Z_Construct_UFunction_ANDIReceiveActor_EnableColor_Statics::NewProp_Enabled_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANDIReceiveActor_EnableColor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANDIReceiveActor_EnableColor_Statics::NewProp_Enabled,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANDIReceiveActor_EnableColor_Statics::Function_MetaDataParams[] = {
		{ "BlueprintSetter", "" },
		{ "ModuleRelativePath", "Public/Actors/NDIReceiveActor.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANDIReceiveActor_EnableColor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANDIReceiveActor, nullptr, "EnableColor", nullptr, nullptr, Z_Construct_UFunction_ANDIReceiveActor_EnableColor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANDIReceiveActor_EnableColor_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANDIReceiveActor_EnableColor_Statics::NDIReceiveActor_eventEnableColor_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04440401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANDIReceiveActor_EnableColor_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANDIReceiveActor_EnableColor_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANDIReceiveActor_EnableColor_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ANDIReceiveActor_EnableColor_Statics::NDIReceiveActor_eventEnableColor_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANDIReceiveActor_EnableColor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANDIReceiveActor_EnableColor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANDIReceiveActor_SetFrameHeight_Statics
	{
		struct NDIReceiveActor_eventSetFrameHeight_Parms
		{
			float InFrameHeight;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InFrameHeight_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_InFrameHeight;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANDIReceiveActor_SetFrameHeight_Statics::NewProp_InFrameHeight_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ANDIReceiveActor_SetFrameHeight_Statics::NewProp_InFrameHeight = { "InFrameHeight", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NDIReceiveActor_eventSetFrameHeight_Parms, InFrameHeight), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANDIReceiveActor_SetFrameHeight_Statics::NewProp_InFrameHeight_MetaData), Z_Construct_UFunction_ANDIReceiveActor_SetFrameHeight_Statics::NewProp_InFrameHeight_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANDIReceiveActor_SetFrameHeight_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANDIReceiveActor_SetFrameHeight_Statics::NewProp_InFrameHeight,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANDIReceiveActor_SetFrameHeight_Statics::Function_MetaDataParams[] = {
		{ "BlueprintSetter", "" },
		{ "ModuleRelativePath", "Public/Actors/NDIReceiveActor.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANDIReceiveActor_SetFrameHeight_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANDIReceiveActor, nullptr, "SetFrameHeight", nullptr, nullptr, Z_Construct_UFunction_ANDIReceiveActor_SetFrameHeight_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANDIReceiveActor_SetFrameHeight_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANDIReceiveActor_SetFrameHeight_Statics::NDIReceiveActor_eventSetFrameHeight_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04440401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANDIReceiveActor_SetFrameHeight_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANDIReceiveActor_SetFrameHeight_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANDIReceiveActor_SetFrameHeight_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ANDIReceiveActor_SetFrameHeight_Statics::NDIReceiveActor_eventSetFrameHeight_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANDIReceiveActor_SetFrameHeight()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANDIReceiveActor_SetFrameHeight_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANDIReceiveActor_SetFrameWidth_Statics
	{
		struct NDIReceiveActor_eventSetFrameWidth_Parms
		{
			float InFrameWidth;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InFrameWidth_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_InFrameWidth;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANDIReceiveActor_SetFrameWidth_Statics::NewProp_InFrameWidth_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ANDIReceiveActor_SetFrameWidth_Statics::NewProp_InFrameWidth = { "InFrameWidth", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NDIReceiveActor_eventSetFrameWidth_Parms, InFrameWidth), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANDIReceiveActor_SetFrameWidth_Statics::NewProp_InFrameWidth_MetaData), Z_Construct_UFunction_ANDIReceiveActor_SetFrameWidth_Statics::NewProp_InFrameWidth_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANDIReceiveActor_SetFrameWidth_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANDIReceiveActor_SetFrameWidth_Statics::NewProp_InFrameWidth,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANDIReceiveActor_SetFrameWidth_Statics::Function_MetaDataParams[] = {
		{ "BlueprintSetter", "" },
		{ "ModuleRelativePath", "Public/Actors/NDIReceiveActor.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANDIReceiveActor_SetFrameWidth_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANDIReceiveActor, nullptr, "SetFrameWidth", nullptr, nullptr, Z_Construct_UFunction_ANDIReceiveActor_SetFrameWidth_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANDIReceiveActor_SetFrameWidth_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANDIReceiveActor_SetFrameWidth_Statics::NDIReceiveActor_eventSetFrameWidth_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04440401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANDIReceiveActor_SetFrameWidth_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANDIReceiveActor_SetFrameWidth_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANDIReceiveActor_SetFrameWidth_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ANDIReceiveActor_SetFrameWidth_Statics::NDIReceiveActor_eventSetFrameWidth_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANDIReceiveActor_SetFrameWidth()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANDIReceiveActor_SetFrameWidth_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANDIReceiveActor_UpdateAudioPlayback_Statics
	{
		struct NDIReceiveActor_eventUpdateAudioPlayback_Parms
		{
			bool Enabled;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Enabled_MetaData[];
#endif
		static void NewProp_Enabled_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Enabled;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANDIReceiveActor_UpdateAudioPlayback_Statics::NewProp_Enabled_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_ANDIReceiveActor_UpdateAudioPlayback_Statics::NewProp_Enabled_SetBit(void* Obj)
	{
		((NDIReceiveActor_eventUpdateAudioPlayback_Parms*)Obj)->Enabled = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ANDIReceiveActor_UpdateAudioPlayback_Statics::NewProp_Enabled = { "Enabled", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(NDIReceiveActor_eventUpdateAudioPlayback_Parms), &Z_Construct_UFunction_ANDIReceiveActor_UpdateAudioPlayback_Statics::NewProp_Enabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANDIReceiveActor_UpdateAudioPlayback_Statics::NewProp_Enabled_MetaData), Z_Construct_UFunction_ANDIReceiveActor_UpdateAudioPlayback_Statics::NewProp_Enabled_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANDIReceiveActor_UpdateAudioPlayback_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANDIReceiveActor_UpdateAudioPlayback_Statics::NewProp_Enabled,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANDIReceiveActor_UpdateAudioPlayback_Statics::Function_MetaDataParams[] = {
		{ "BlueprintSetter", "" },
		{ "ModuleRelativePath", "Public/Actors/NDIReceiveActor.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANDIReceiveActor_UpdateAudioPlayback_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANDIReceiveActor, nullptr, "UpdateAudioPlayback", nullptr, nullptr, Z_Construct_UFunction_ANDIReceiveActor_UpdateAudioPlayback_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANDIReceiveActor_UpdateAudioPlayback_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANDIReceiveActor_UpdateAudioPlayback_Statics::NDIReceiveActor_eventUpdateAudioPlayback_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04440401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANDIReceiveActor_UpdateAudioPlayback_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANDIReceiveActor_UpdateAudioPlayback_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANDIReceiveActor_UpdateAudioPlayback_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ANDIReceiveActor_UpdateAudioPlayback_Statics::NDIReceiveActor_eventUpdateAudioPlayback_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANDIReceiveActor_UpdateAudioPlayback()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANDIReceiveActor_UpdateAudioPlayback_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANDIReceiveActor_UpdateAudioPlaybackChannels_Statics
	{
		struct NDIReceiveActor_eventUpdateAudioPlaybackChannels_Parms
		{
			ENDIAudioChannels Channels;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_Channels_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Channels_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Channels;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ANDIReceiveActor_UpdateAudioPlaybackChannels_Statics::NewProp_Channels_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANDIReceiveActor_UpdateAudioPlaybackChannels_Statics::NewProp_Channels_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_ANDIReceiveActor_UpdateAudioPlaybackChannels_Statics::NewProp_Channels = { "Channels", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NDIReceiveActor_eventUpdateAudioPlaybackChannels_Parms, Channels), Z_Construct_UEnum_NDIIO_ENDIAudioChannels, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANDIReceiveActor_UpdateAudioPlaybackChannels_Statics::NewProp_Channels_MetaData), Z_Construct_UFunction_ANDIReceiveActor_UpdateAudioPlaybackChannels_Statics::NewProp_Channels_MetaData) }; // 1987648875
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANDIReceiveActor_UpdateAudioPlaybackChannels_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANDIReceiveActor_UpdateAudioPlaybackChannels_Statics::NewProp_Channels_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANDIReceiveActor_UpdateAudioPlaybackChannels_Statics::NewProp_Channels,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANDIReceiveActor_UpdateAudioPlaybackChannels_Statics::Function_MetaDataParams[] = {
		{ "BlueprintSetter", "" },
		{ "ModuleRelativePath", "Public/Actors/NDIReceiveActor.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANDIReceiveActor_UpdateAudioPlaybackChannels_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANDIReceiveActor, nullptr, "UpdateAudioPlaybackChannels", nullptr, nullptr, Z_Construct_UFunction_ANDIReceiveActor_UpdateAudioPlaybackChannels_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANDIReceiveActor_UpdateAudioPlaybackChannels_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANDIReceiveActor_UpdateAudioPlaybackChannels_Statics::NDIReceiveActor_eventUpdateAudioPlaybackChannels_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04440401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANDIReceiveActor_UpdateAudioPlaybackChannels_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANDIReceiveActor_UpdateAudioPlaybackChannels_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANDIReceiveActor_UpdateAudioPlaybackChannels_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ANDIReceiveActor_UpdateAudioPlaybackChannels_Statics::NDIReceiveActor_eventUpdateAudioPlaybackChannels_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANDIReceiveActor_UpdateAudioPlaybackChannels()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANDIReceiveActor_UpdateAudioPlaybackChannels_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ANDIReceiveActor);
	UClass* Z_Construct_UClass_ANDIReceiveActor_NoRegister()
	{
		return ANDIReceiveActor::StaticClass();
	}
	struct Z_Construct_UClass_ANDIReceiveActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SceneComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SceneComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FrameWidth_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_FrameWidth;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FrameHeight_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_FrameHeight;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bEnableAudioPlayback_MetaData[];
#endif
		static void NewProp_bEnableAudioPlayback_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableAudioPlayback;
		static const UECodeGen_Private::FBytePropertyParams NewProp_AudioPlaybackChannels_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AudioPlaybackChannels_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_AudioPlaybackChannels;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bEnableColor_MetaData[];
#endif
		static void NewProp_bEnableColor_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableColor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bEnableAlpha_MetaData[];
#endif
		static void NewProp_bEnableAlpha_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableAlpha;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NDIMediaSource_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_NDIMediaSource;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_VideoMeshComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_VideoMeshComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AudioComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AudioComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AudioSoundWave_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AudioSoundWave;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_VideoMaterial_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_VideoMaterial;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_VideoMaterialInstance_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_VideoMaterialInstance;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ANDIReceiveActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_NDIIO,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANDIReceiveActor_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_ANDIReceiveActor_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ANDIReceiveActor_EnableAlpha, "EnableAlpha" }, // 3064465913
		{ &Z_Construct_UFunction_ANDIReceiveActor_EnableColor, "EnableColor" }, // 1647382847
		{ &Z_Construct_UFunction_ANDIReceiveActor_SetFrameHeight, "SetFrameHeight" }, // 1239114547
		{ &Z_Construct_UFunction_ANDIReceiveActor_SetFrameWidth, "SetFrameWidth" }, // 3643335600
		{ &Z_Construct_UFunction_ANDIReceiveActor_UpdateAudioPlayback, "UpdateAudioPlayback" }, // 1199789840
		{ &Z_Construct_UFunction_ANDIReceiveActor_UpdateAudioPlaybackChannels, "UpdateAudioPlaybackChannels" }, // 3038612342
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANDIReceiveActor_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANDIReceiveActor_Statics::Class_MetaDataParams[] = {
		{ "Category", "NDI IO" },
		{ "DisplayName", "NDI Receive Actor" },
		{ "HideCategories", "Activation Rendering AssetUserData Material Attachment Actor Input Cooking LOD StaticMesh Materials" },
		{ "IncludePath", "Actors/NDIReceiveActor.h" },
		{ "ModuleRelativePath", "Public/Actors/NDIReceiveActor.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_SceneComponent_MetaData[] = {
		{ "Category", "NDIReceiveActor" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Actors/NDIReceiveActor.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_SceneComponent = { "SceneComponent", nullptr, (EPropertyFlags)0x00400000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANDIReceiveActor, SceneComponent), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_SceneComponent_MetaData), Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_SceneComponent_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_FrameWidth_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "BlueprintSetter", "SetFrameWidth" },
		{ "Category", "NDI IO" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The desired width of the frame in cm, represented in the virtual scene */" },
#endif
		{ "DisplayName", "Frame Width" },
		{ "ModuleRelativePath", "Public/Actors/NDIReceiveActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The desired width of the frame in cm, represented in the virtual scene" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_FrameWidth = { "FrameWidth", nullptr, (EPropertyFlags)0x0040000200000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANDIReceiveActor, FrameWidth), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_FrameWidth_MetaData), Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_FrameWidth_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_FrameHeight_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "BlueprintSetter", "SetFrameHeight" },
		{ "Category", "NDI IO" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The desired height of the frame in cm, represented in the virtual scene */" },
#endif
		{ "DisplayName", "Frame Height" },
		{ "ModuleRelativePath", "Public/Actors/NDIReceiveActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The desired height of the frame in cm, represented in the virtual scene" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_FrameHeight = { "FrameHeight", nullptr, (EPropertyFlags)0x0040000200000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANDIReceiveActor, FrameHeight), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_FrameHeight_MetaData), Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_FrameHeight_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_bEnableAudioPlayback_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "BlueprintSetter", "UpdateAudioPlayback" },
		{ "Category", "NDI IO" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09\x09Indicates that this object should play the audio.\n\n\x09\x09*Note Audio played by this object will be played as a UI sound, and won't normalize the audio\n\x09\x09\x09  if the same 'MediaSource' object is being used as the audio source on multiple receivers.\n\x09*/" },
#endif
		{ "DisplayName", "Enable Audio Playback?" },
		{ "ModuleRelativePath", "Public/Actors/NDIReceiveActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Indicates that this object should play the audio.\n\nNote Audio played by this object will be played as a UI sound, and won't normalize the audio\n          if the same 'MediaSource' object is being used as the audio source on multiple receivers." },
#endif
	};
#endif
	void Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_bEnableAudioPlayback_SetBit(void* Obj)
	{
		((ANDIReceiveActor*)Obj)->bEnableAudioPlayback = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_bEnableAudioPlayback = { "bEnableAudioPlayback", nullptr, (EPropertyFlags)0x0040000000000805, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ANDIReceiveActor), &Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_bEnableAudioPlayback_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_bEnableAudioPlayback_MetaData), Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_bEnableAudioPlayback_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_AudioPlaybackChannels_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_AudioPlaybackChannels_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "BlueprintSetter", "UpdateAudioPlaybackChannels" },
		{ "Category", "NDI IO" },
		{ "DisplayName", "Audio Playback Channels" },
		{ "ModuleRelativePath", "Public/Actors/NDIReceiveActor.h" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_AudioPlaybackChannels = { "AudioPlaybackChannels", nullptr, (EPropertyFlags)0x0040000000000805, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANDIReceiveActor, AudioPlaybackChannels), Z_Construct_UEnum_NDIIO_ENDIAudioChannels, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_AudioPlaybackChannels_MetaData), Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_AudioPlaybackChannels_MetaData) }; // 1987648875
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_bEnableColor_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "BlueprintSetter", "EnableColor" },
		{ "Category", "NDI IO" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Enable/disable the use of the color channels (if there are any) */" },
#endif
		{ "DisplayName", "Enable Color?" },
		{ "ModuleRelativePath", "Public/Actors/NDIReceiveActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Enable/disable the use of the color channels (if there are any)" },
#endif
	};
#endif
	void Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_bEnableColor_SetBit(void* Obj)
	{
		((ANDIReceiveActor*)Obj)->bEnableColor = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_bEnableColor = { "bEnableColor", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ANDIReceiveActor), &Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_bEnableColor_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_bEnableColor_MetaData), Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_bEnableColor_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_bEnableAlpha_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "BlueprintSetter", "EnableAlpha" },
		{ "Category", "NDI IO" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Enable/disable the use of the alpha channel (if there is one) */" },
#endif
		{ "DisplayName", "Enable Alpha?" },
		{ "ModuleRelativePath", "Public/Actors/NDIReceiveActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Enable/disable the use of the alpha channel (if there is one)" },
#endif
	};
#endif
	void Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_bEnableAlpha_SetBit(void* Obj)
	{
		((ANDIReceiveActor*)Obj)->bEnableAlpha = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_bEnableAlpha = { "bEnableAlpha", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ANDIReceiveActor), &Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_bEnableAlpha_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_bEnableAlpha_MetaData), Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_bEnableAlpha_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_NDIMediaSource_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "NDI IO" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The Receiver object used to get Audio, Video, and Metadata from on the network */" },
#endif
		{ "DisplayName", "NDI Media Source" },
		{ "ModuleRelativePath", "Public/Actors/NDIReceiveActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The Receiver object used to get Audio, Video, and Metadata from on the network" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_NDIMediaSource = { "NDIMediaSource", nullptr, (EPropertyFlags)0x0040000000000805, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANDIReceiveActor, NDIMediaSource), Z_Construct_UClass_UNDIMediaReceiver_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_NDIMediaSource_MetaData), Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_NDIMediaSource_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_VideoMeshComponent_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "NDIReceiveActor" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The component used to display the video received from the Media Sender object */" },
#endif
		{ "DisplayName", "Video Mesh Component" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Actors/NDIReceiveActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The component used to display the video received from the Media Sender object" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_VideoMeshComponent = { "VideoMeshComponent", nullptr, (EPropertyFlags)0x00400000000a201d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANDIReceiveActor, VideoMeshComponent), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_VideoMeshComponent_MetaData), Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_VideoMeshComponent_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_AudioComponent_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "NDI IO" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The component used to play the audio from the NDI Media source */" },
#endif
		{ "DisplayName", "Audio Component" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Actors/NDIReceiveActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The component used to play the audio from the NDI Media source" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_AudioComponent = { "AudioComponent", nullptr, (EPropertyFlags)0x004000000008080d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANDIReceiveActor, AudioComponent), Z_Construct_UClass_UAudioComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_AudioComponent_MetaData), Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_AudioComponent_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_AudioSoundWave_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The audio sound wave which receives the audio from the NDI Media source */" },
#endif
		{ "DisplayName", "Soundwave" },
		{ "ModuleRelativePath", "Public/Actors/NDIReceiveActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The audio sound wave which receives the audio from the NDI Media source" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_AudioSoundWave = { "AudioSoundWave", nullptr, (EPropertyFlags)0x0040000000002000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANDIReceiveActor, AudioSoundWave), Z_Construct_UClass_UNDIMediaSoundWave_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_AudioSoundWave_MetaData), Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_AudioSoundWave_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_VideoMaterial_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "NDIReceiveActor" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The material we are trying to apply to the video mesh */" },
#endif
		{ "ModuleRelativePath", "Public/Actors/NDIReceiveActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The material we are trying to apply to the video mesh" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_VideoMaterial = { "VideoMaterial", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANDIReceiveActor, VideoMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_VideoMaterial_MetaData), Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_VideoMaterial_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_VideoMaterialInstance_MetaData[] = {
		{ "Category", "NDIReceiveActor" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The dynamic material to apply to the plane object of this actor */" },
#endif
		{ "ModuleRelativePath", "Public/Actors/NDIReceiveActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The dynamic material to apply to the plane object of this actor" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_VideoMaterialInstance = { "VideoMaterialInstance", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANDIReceiveActor, VideoMaterialInstance), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_VideoMaterialInstance_MetaData), Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_VideoMaterialInstance_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ANDIReceiveActor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_SceneComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_FrameWidth,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_FrameHeight,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_bEnableAudioPlayback,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_AudioPlaybackChannels_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_AudioPlaybackChannels,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_bEnableColor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_bEnableAlpha,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_NDIMediaSource,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_VideoMeshComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_AudioComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_AudioSoundWave,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_VideoMaterial,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANDIReceiveActor_Statics::NewProp_VideoMaterialInstance,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ANDIReceiveActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANDIReceiveActor>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ANDIReceiveActor_Statics::ClassParams = {
		&ANDIReceiveActor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ANDIReceiveActor_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ANDIReceiveActor_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANDIReceiveActor_Statics::Class_MetaDataParams), Z_Construct_UClass_ANDIReceiveActor_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANDIReceiveActor_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ANDIReceiveActor()
	{
		if (!Z_Registration_Info_UClass_ANDIReceiveActor.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ANDIReceiveActor.OuterSingleton, Z_Construct_UClass_ANDIReceiveActor_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ANDIReceiveActor.OuterSingleton;
	}
	template<> NDIIO_API UClass* StaticClass<ANDIReceiveActor>()
	{
		return ANDIReceiveActor::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ANDIReceiveActor);
	ANDIReceiveActor::~ANDIReceiveActor() {}
	struct Z_CompiledInDeferFile_FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Actors_NDIReceiveActor_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Actors_NDIReceiveActor_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ANDIReceiveActor, ANDIReceiveActor::StaticClass, TEXT("ANDIReceiveActor"), &Z_Registration_Info_UClass_ANDIReceiveActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ANDIReceiveActor), 1236872054U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Actors_NDIReceiveActor_h_1592476894(TEXT("/Script/NDIIO"),
		Z_CompiledInDeferFile_FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Actors_NDIReceiveActor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Actors_NDIReceiveActor_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
