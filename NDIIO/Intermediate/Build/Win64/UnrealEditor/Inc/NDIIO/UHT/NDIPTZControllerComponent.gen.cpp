// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Components/NDIPTZControllerComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNDIPTZControllerComponent() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	NDIIO_API UClass* Z_Construct_UClass_UNDIMediaSender_NoRegister();
	NDIIO_API UClass* Z_Construct_UClass_UPTZControllableInterface();
	NDIIO_API UClass* Z_Construct_UClass_UPTZControllableInterface_NoRegister();
	NDIIO_API UClass* Z_Construct_UClass_UPTZController();
	NDIIO_API UClass* Z_Construct_UClass_UPTZController_NoRegister();
	NDIIO_API UFunction* Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZFocus__DelegateSignature();
	NDIIO_API UFunction* Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZPanTiltSpeed__DelegateSignature();
	NDIIO_API UFunction* Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZRecall__DelegateSignature();
	NDIIO_API UFunction* Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZStore__DelegateSignature();
	NDIIO_API UFunction* Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZZoomSpeed__DelegateSignature();
	NDIIO_API UScriptStruct* Z_Construct_UScriptStruct_FPTZState();
	UPackage* Z_Construct_UPackage__Script_NDIIO();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PTZState;
class UScriptStruct* FPTZState::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PTZState.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PTZState.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPTZState, (UObject*)Z_Construct_UPackage__Script_NDIIO(), TEXT("PTZState"));
	}
	return Z_Registration_Info_UScriptStruct_PTZState.OuterSingleton;
}
template<> NDIIO_API UScriptStruct* StaticStruct<FPTZState>()
{
	return FPTZState::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FPTZState_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Pan_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Pan;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Tilt_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Tilt;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FieldOfView_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_FieldOfView;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FocusDistance_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_FocusDistance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bAutoFocus_MetaData[];
#endif
		static void NewProp_bAutoFocus_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoFocus;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CameraTransform_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_CameraTransform;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPTZState_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Category", "NDI IO" },
		{ "DisplayName", "NDI PTZ State" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Components/NDIPTZControllerComponent.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPTZState_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPTZState>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPTZState_Statics::NewProp_Pan_MetaData[] = {
		{ "Category", "PTZ" },
		{ "ModuleRelativePath", "Public/Components/NDIPTZControllerComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPTZState_Statics::NewProp_Pan = { "Pan", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPTZState, Pan), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPTZState_Statics::NewProp_Pan_MetaData), Z_Construct_UScriptStruct_FPTZState_Statics::NewProp_Pan_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPTZState_Statics::NewProp_Tilt_MetaData[] = {
		{ "Category", "PTZ" },
		{ "ModuleRelativePath", "Public/Components/NDIPTZControllerComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPTZState_Statics::NewProp_Tilt = { "Tilt", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPTZState, Tilt), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPTZState_Statics::NewProp_Tilt_MetaData), Z_Construct_UScriptStruct_FPTZState_Statics::NewProp_Tilt_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPTZState_Statics::NewProp_FieldOfView_MetaData[] = {
		{ "Category", "PTZ" },
		{ "ModuleRelativePath", "Public/Components/NDIPTZControllerComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPTZState_Statics::NewProp_FieldOfView = { "FieldOfView", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPTZState, FieldOfView), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPTZState_Statics::NewProp_FieldOfView_MetaData), Z_Construct_UScriptStruct_FPTZState_Statics::NewProp_FieldOfView_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPTZState_Statics::NewProp_FocusDistance_MetaData[] = {
		{ "Category", "PTZ" },
		{ "ModuleRelativePath", "Public/Components/NDIPTZControllerComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPTZState_Statics::NewProp_FocusDistance = { "FocusDistance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPTZState, FocusDistance), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPTZState_Statics::NewProp_FocusDistance_MetaData), Z_Construct_UScriptStruct_FPTZState_Statics::NewProp_FocusDistance_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPTZState_Statics::NewProp_bAutoFocus_MetaData[] = {
		{ "Category", "PTZ" },
		{ "ModuleRelativePath", "Public/Components/NDIPTZControllerComponent.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FPTZState_Statics::NewProp_bAutoFocus_SetBit(void* Obj)
	{
		((FPTZState*)Obj)->bAutoFocus = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FPTZState_Statics::NewProp_bAutoFocus = { "bAutoFocus", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FPTZState), &Z_Construct_UScriptStruct_FPTZState_Statics::NewProp_bAutoFocus_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPTZState_Statics::NewProp_bAutoFocus_MetaData), Z_Construct_UScriptStruct_FPTZState_Statics::NewProp_bAutoFocus_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPTZState_Statics::NewProp_CameraTransform_MetaData[] = {
		{ "Category", "PTZ" },
		{ "ModuleRelativePath", "Public/Components/NDIPTZControllerComponent.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPTZState_Statics::NewProp_CameraTransform = { "CameraTransform", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPTZState, CameraTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPTZState_Statics::NewProp_CameraTransform_MetaData), Z_Construct_UScriptStruct_FPTZState_Statics::NewProp_CameraTransform_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPTZState_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPTZState_Statics::NewProp_Pan,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPTZState_Statics::NewProp_Tilt,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPTZState_Statics::NewProp_FieldOfView,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPTZState_Statics::NewProp_FocusDistance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPTZState_Statics::NewProp_bAutoFocus,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPTZState_Statics::NewProp_CameraTransform,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPTZState_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_NDIIO,
		nullptr,
		&NewStructOps,
		"PTZState",
		Z_Construct_UScriptStruct_FPTZState_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPTZState_Statics::PropPointers),
		sizeof(FPTZState),
		alignof(FPTZState),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPTZState_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPTZState_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPTZState_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FPTZState()
	{
		if (!Z_Registration_Info_UScriptStruct_PTZState.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PTZState.InnerSingleton, Z_Construct_UScriptStruct_FPTZState_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_PTZState.InnerSingleton;
	}
	struct Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZPanTiltSpeed__DelegateSignature_Statics
	{
		struct _Script_NDIIO_eventNDIEventDelegate_OnPTZPanTiltSpeed_Parms
		{
			float PanSpeed;
			float TiltSpeed;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_PanSpeed;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_TiltSpeed;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZPanTiltSpeed__DelegateSignature_Statics::NewProp_PanSpeed = { "PanSpeed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_NDIIO_eventNDIEventDelegate_OnPTZPanTiltSpeed_Parms, PanSpeed), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZPanTiltSpeed__DelegateSignature_Statics::NewProp_TiltSpeed = { "TiltSpeed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_NDIIO_eventNDIEventDelegate_OnPTZPanTiltSpeed_Parms, TiltSpeed), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZPanTiltSpeed__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZPanTiltSpeed__DelegateSignature_Statics::NewProp_PanSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZPanTiltSpeed__DelegateSignature_Statics::NewProp_TiltSpeed,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZPanTiltSpeed__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/NDIPTZControllerComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZPanTiltSpeed__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_NDIIO, nullptr, "NDIEventDelegate_OnPTZPanTiltSpeed__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZPanTiltSpeed__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZPanTiltSpeed__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZPanTiltSpeed__DelegateSignature_Statics::_Script_NDIIO_eventNDIEventDelegate_OnPTZPanTiltSpeed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZPanTiltSpeed__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZPanTiltSpeed__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZPanTiltSpeed__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZPanTiltSpeed__DelegateSignature_Statics::_Script_NDIIO_eventNDIEventDelegate_OnPTZPanTiltSpeed_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZPanTiltSpeed__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZPanTiltSpeed__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FNDIEventDelegate_OnPTZPanTiltSpeed_DelegateWrapper(const FMulticastScriptDelegate& NDIEventDelegate_OnPTZPanTiltSpeed, float PanSpeed, float TiltSpeed)
{
	struct _Script_NDIIO_eventNDIEventDelegate_OnPTZPanTiltSpeed_Parms
	{
		float PanSpeed;
		float TiltSpeed;
	};
	_Script_NDIIO_eventNDIEventDelegate_OnPTZPanTiltSpeed_Parms Parms;
	Parms.PanSpeed=PanSpeed;
	Parms.TiltSpeed=TiltSpeed;
	NDIEventDelegate_OnPTZPanTiltSpeed.ProcessMulticastDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZZoomSpeed__DelegateSignature_Statics
	{
		struct _Script_NDIIO_eventNDIEventDelegate_OnPTZZoomSpeed_Parms
		{
			float ZoomSpeed;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ZoomSpeed;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZZoomSpeed__DelegateSignature_Statics::NewProp_ZoomSpeed = { "ZoomSpeed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_NDIIO_eventNDIEventDelegate_OnPTZZoomSpeed_Parms, ZoomSpeed), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZZoomSpeed__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZZoomSpeed__DelegateSignature_Statics::NewProp_ZoomSpeed,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZZoomSpeed__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/NDIPTZControllerComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZZoomSpeed__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_NDIIO, nullptr, "NDIEventDelegate_OnPTZZoomSpeed__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZZoomSpeed__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZZoomSpeed__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZZoomSpeed__DelegateSignature_Statics::_Script_NDIIO_eventNDIEventDelegate_OnPTZZoomSpeed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZZoomSpeed__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZZoomSpeed__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZZoomSpeed__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZZoomSpeed__DelegateSignature_Statics::_Script_NDIIO_eventNDIEventDelegate_OnPTZZoomSpeed_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZZoomSpeed__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZZoomSpeed__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FNDIEventDelegate_OnPTZZoomSpeed_DelegateWrapper(const FMulticastScriptDelegate& NDIEventDelegate_OnPTZZoomSpeed, float ZoomSpeed)
{
	struct _Script_NDIIO_eventNDIEventDelegate_OnPTZZoomSpeed_Parms
	{
		float ZoomSpeed;
	};
	_Script_NDIIO_eventNDIEventDelegate_OnPTZZoomSpeed_Parms Parms;
	Parms.ZoomSpeed=ZoomSpeed;
	NDIEventDelegate_OnPTZZoomSpeed.ProcessMulticastDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZFocus__DelegateSignature_Statics
	{
		struct _Script_NDIIO_eventNDIEventDelegate_OnPTZFocus_Parms
		{
			bool AutoMode;
			float Distance;
		};
		static void NewProp_AutoMode_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_AutoMode;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Distance;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZFocus__DelegateSignature_Statics::NewProp_AutoMode_SetBit(void* Obj)
	{
		((_Script_NDIIO_eventNDIEventDelegate_OnPTZFocus_Parms*)Obj)->AutoMode = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZFocus__DelegateSignature_Statics::NewProp_AutoMode = { "AutoMode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_NDIIO_eventNDIEventDelegate_OnPTZFocus_Parms), &Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZFocus__DelegateSignature_Statics::NewProp_AutoMode_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZFocus__DelegateSignature_Statics::NewProp_Distance = { "Distance", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_NDIIO_eventNDIEventDelegate_OnPTZFocus_Parms, Distance), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZFocus__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZFocus__DelegateSignature_Statics::NewProp_AutoMode,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZFocus__DelegateSignature_Statics::NewProp_Distance,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZFocus__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/NDIPTZControllerComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZFocus__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_NDIIO, nullptr, "NDIEventDelegate_OnPTZFocus__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZFocus__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZFocus__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZFocus__DelegateSignature_Statics::_Script_NDIIO_eventNDIEventDelegate_OnPTZFocus_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZFocus__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZFocus__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZFocus__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZFocus__DelegateSignature_Statics::_Script_NDIIO_eventNDIEventDelegate_OnPTZFocus_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZFocus__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZFocus__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FNDIEventDelegate_OnPTZFocus_DelegateWrapper(const FMulticastScriptDelegate& NDIEventDelegate_OnPTZFocus, bool AutoMode, float Distance)
{
	struct _Script_NDIIO_eventNDIEventDelegate_OnPTZFocus_Parms
	{
		bool AutoMode;
		float Distance;
	};
	_Script_NDIIO_eventNDIEventDelegate_OnPTZFocus_Parms Parms;
	Parms.AutoMode=AutoMode ? true : false;
	Parms.Distance=Distance;
	NDIEventDelegate_OnPTZFocus.ProcessMulticastDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZStore__DelegateSignature_Statics
	{
		struct _Script_NDIIO_eventNDIEventDelegate_OnPTZStore_Parms
		{
			int32 Index;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZStore__DelegateSignature_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_NDIIO_eventNDIEventDelegate_OnPTZStore_Parms, Index), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZStore__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZStore__DelegateSignature_Statics::NewProp_Index,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZStore__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/NDIPTZControllerComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZStore__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_NDIIO, nullptr, "NDIEventDelegate_OnPTZStore__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZStore__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZStore__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZStore__DelegateSignature_Statics::_Script_NDIIO_eventNDIEventDelegate_OnPTZStore_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZStore__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZStore__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZStore__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZStore__DelegateSignature_Statics::_Script_NDIIO_eventNDIEventDelegate_OnPTZStore_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZStore__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZStore__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FNDIEventDelegate_OnPTZStore_DelegateWrapper(const FMulticastScriptDelegate& NDIEventDelegate_OnPTZStore, int32 Index)
{
	struct _Script_NDIIO_eventNDIEventDelegate_OnPTZStore_Parms
	{
		int32 Index;
	};
	_Script_NDIIO_eventNDIEventDelegate_OnPTZStore_Parms Parms;
	Parms.Index=Index;
	NDIEventDelegate_OnPTZStore.ProcessMulticastDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZRecall__DelegateSignature_Statics
	{
		struct _Script_NDIIO_eventNDIEventDelegate_OnPTZRecall_Parms
		{
			int32 Index;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZRecall__DelegateSignature_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_NDIIO_eventNDIEventDelegate_OnPTZRecall_Parms, Index), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZRecall__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZRecall__DelegateSignature_Statics::NewProp_Index,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZRecall__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/NDIPTZControllerComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZRecall__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_NDIIO, nullptr, "NDIEventDelegate_OnPTZRecall__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZRecall__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZRecall__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZRecall__DelegateSignature_Statics::_Script_NDIIO_eventNDIEventDelegate_OnPTZRecall_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZRecall__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZRecall__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZRecall__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZRecall__DelegateSignature_Statics::_Script_NDIIO_eventNDIEventDelegate_OnPTZRecall_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZRecall__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZRecall__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FNDIEventDelegate_OnPTZRecall_DelegateWrapper(const FMulticastScriptDelegate& NDIEventDelegate_OnPTZRecall, int32 Index)
{
	struct _Script_NDIIO_eventNDIEventDelegate_OnPTZRecall_Parms
	{
		int32 Index;
	};
	_Script_NDIIO_eventNDIEventDelegate_OnPTZRecall_Parms Parms;
	Parms.Index=Index;
	NDIEventDelegate_OnPTZRecall.ProcessMulticastDelegate<UObject>(&Parms);
}
	void UPTZControllableInterface::StaticRegisterNativesUPTZControllableInterface()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPTZControllableInterface);
	UClass* Z_Construct_UClass_UPTZControllableInterface_NoRegister()
	{
		return UPTZControllableInterface::StaticClass();
	}
	struct Z_Construct_UClass_UPTZControllableInterface_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPTZControllableInterface_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_NDIIO,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPTZControllableInterface_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPTZControllableInterface_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "Category", "NDI IO" },
		{ "DisplayName", "NDI PTZ Controllable" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Components/NDIPTZControllerComponent.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPTZControllableInterface_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IPTZControllableInterface>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPTZControllableInterface_Statics::ClassParams = {
		&UPTZControllableInterface::StaticClass,
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
		0x001040A1u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPTZControllableInterface_Statics::Class_MetaDataParams), Z_Construct_UClass_UPTZControllableInterface_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UPTZControllableInterface()
	{
		if (!Z_Registration_Info_UClass_UPTZControllableInterface.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPTZControllableInterface.OuterSingleton, Z_Construct_UClass_UPTZControllableInterface_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPTZControllableInterface.OuterSingleton;
	}
	template<> NDIIO_API UClass* StaticClass<UPTZControllableInterface>()
	{
		return UPTZControllableInterface::StaticClass();
	}
	UPTZControllableInterface::UPTZControllableInterface(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPTZControllableInterface);
	UPTZControllableInterface::~UPTZControllableInterface() {}
	DEFINE_FUNCTION(UPTZController::execReceiveMetaDataFromSender)
	{
		P_GET_OBJECT(UNDIMediaSender,Z_Param_Sender);
		P_GET_PROPERTY(FStrProperty,Z_Param_Data);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ReceiveMetaDataFromSender(Z_Param_Sender,Z_Param_Data);
		P_NATIVE_END;
	}
	void UPTZController::StaticRegisterNativesUPTZController()
	{
		UClass* Class = UPTZController::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ReceiveMetaDataFromSender", &UPTZController::execReceiveMetaDataFromSender },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPTZController_ReceiveMetaDataFromSender_Statics
	{
		struct PTZController_eventReceiveMetaDataFromSender_Parms
		{
			UNDIMediaSender* Sender;
			FString Data;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Sender;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Data;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPTZController_ReceiveMetaDataFromSender_Statics::NewProp_Sender = { "Sender", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PTZController_eventReceiveMetaDataFromSender_Parms, Sender), Z_Construct_UClass_UNDIMediaSender_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPTZController_ReceiveMetaDataFromSender_Statics::NewProp_Data = { "Data", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PTZController_eventReceiveMetaDataFromSender_Parms, Data), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPTZController_ReceiveMetaDataFromSender_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPTZController_ReceiveMetaDataFromSender_Statics::NewProp_Sender,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPTZController_ReceiveMetaDataFromSender_Statics::NewProp_Data,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPTZController_ReceiveMetaDataFromSender_Statics::Function_MetaDataParams[] = {
		{ "Category", "NDI IO" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Call with the PTZ metadata received from an NDI media sender */" },
#endif
		{ "DisplayName", "Receive Metadata From Sender" },
		{ "ModuleRelativePath", "Public/Components/NDIPTZControllerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Call with the PTZ metadata received from an NDI media sender" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPTZController_ReceiveMetaDataFromSender_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPTZController, nullptr, "ReceiveMetaDataFromSender", nullptr, nullptr, Z_Construct_UFunction_UPTZController_ReceiveMetaDataFromSender_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPTZController_ReceiveMetaDataFromSender_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPTZController_ReceiveMetaDataFromSender_Statics::PTZController_eventReceiveMetaDataFromSender_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPTZController_ReceiveMetaDataFromSender_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPTZController_ReceiveMetaDataFromSender_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPTZController_ReceiveMetaDataFromSender_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPTZController_ReceiveMetaDataFromSender_Statics::PTZController_eventReceiveMetaDataFromSender_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPTZController_ReceiveMetaDataFromSender()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPTZController_ReceiveMetaDataFromSender_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPTZController);
	UClass* Z_Construct_UClass_UPTZController_NoRegister()
	{
		return UPTZController::StaticClass();
	}
	struct Z_Construct_UClass_UPTZController_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EnablePTZ_MetaData[];
#endif
		static void NewProp_EnablePTZ_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_EnablePTZ;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PTZWithPanLimit_MetaData[];
#endif
		static void NewProp_PTZWithPanLimit_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_PTZWithPanLimit;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PTZPanMinLimit_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_PTZPanMinLimit;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PTZPanMaxLimit_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_PTZPanMaxLimit;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bPTZPanInvert_MetaData[];
#endif
		static void NewProp_bPTZPanInvert_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bPTZPanInvert;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PTZWithTiltLimit_MetaData[];
#endif
		static void NewProp_PTZWithTiltLimit_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_PTZWithTiltLimit;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PTZTiltMinLimit_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_PTZTiltMinLimit;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PTZTiltMaxLimit_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_PTZTiltMaxLimit;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bPTZTiltInvert_MetaData[];
#endif
		static void NewProp_bPTZTiltInvert_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bPTZTiltInvert;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PTZWithFoVLimit_MetaData[];
#endif
		static void NewProp_PTZWithFoVLimit_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_PTZWithFoVLimit;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PTZFoVMinLimit_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_PTZFoVMinLimit;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PTZFoVMaxLimit_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_PTZFoVMaxLimit;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PTZRecallEasing_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_PTZRecallEasing;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PTZPanSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_PTZPanSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PTZTiltSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_PTZTiltSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PTZZoomSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_PTZZoomSpeed;
		static const UECodeGen_Private::FStructPropertyParams NewProp_PTZStoredStates_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PTZStoredStates_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_PTZStoredStates;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NDIMediaSource_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_NDIMediaSource;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnPTZPanTiltSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnPTZPanTiltSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnPTZZoomSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnPTZZoomSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnPTZFocus_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnPTZFocus;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnPTZStore_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnPTZStore;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnPTZRecall_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnPTZRecall;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPTZController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_NDIIO,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPTZController_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPTZController_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPTZController_ReceiveMetaDataFromSender, "ReceiveMetaDataFromSender" }, // 4250480560
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPTZController_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPTZController_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "Category", "NDI IO" },
		{ "DisplayName", "NDI PTZ Controller" },
		{ "IncludePath", "Components/NDIPTZControllerComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Components/NDIPTZControllerComponent.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPTZController_Statics::NewProp_EnablePTZ_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "PTZ" },
		{ "DisplayName", "Enable PTZ" },
		{ "ModuleRelativePath", "Public/Components/NDIPTZControllerComponent.h" },
	};
#endif
	void Z_Construct_UClass_UPTZController_Statics::NewProp_EnablePTZ_SetBit(void* Obj)
	{
		((UPTZController*)Obj)->EnablePTZ = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPTZController_Statics::NewProp_EnablePTZ = { "EnablePTZ", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPTZController), &Z_Construct_UClass_UPTZController_Statics::NewProp_EnablePTZ_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPTZController_Statics::NewProp_EnablePTZ_MetaData), Z_Construct_UClass_UPTZController_Statics::NewProp_EnablePTZ_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPTZController_Statics::NewProp_PTZWithPanLimit_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "PTZ" },
		{ "DisplayName", "Pan Limit" },
		{ "ModuleRelativePath", "Public/Components/NDIPTZControllerComponent.h" },
	};
#endif
	void Z_Construct_UClass_UPTZController_Statics::NewProp_PTZWithPanLimit_SetBit(void* Obj)
	{
		((UPTZController*)Obj)->PTZWithPanLimit = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPTZController_Statics::NewProp_PTZWithPanLimit = { "PTZWithPanLimit", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPTZController), &Z_Construct_UClass_UPTZController_Statics::NewProp_PTZWithPanLimit_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPTZController_Statics::NewProp_PTZWithPanLimit_MetaData), Z_Construct_UClass_UPTZController_Statics::NewProp_PTZWithPanLimit_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPTZController_Statics::NewProp_PTZPanMinLimit_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "PTZ" },
		{ "DisplayName", "Pan Min Limit" },
		{ "ModuleRelativePath", "Public/Components/NDIPTZControllerComponent.h" },
		{ "UIMax", "180" },
		{ "UIMin", "-180" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPTZController_Statics::NewProp_PTZPanMinLimit = { "PTZPanMinLimit", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPTZController, PTZPanMinLimit), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPTZController_Statics::NewProp_PTZPanMinLimit_MetaData), Z_Construct_UClass_UPTZController_Statics::NewProp_PTZPanMinLimit_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPTZController_Statics::NewProp_PTZPanMaxLimit_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "PTZ" },
		{ "DisplayName", "Pan Max Limit" },
		{ "ModuleRelativePath", "Public/Components/NDIPTZControllerComponent.h" },
		{ "UIMax", "180" },
		{ "UIMin", "-180" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPTZController_Statics::NewProp_PTZPanMaxLimit = { "PTZPanMaxLimit", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPTZController, PTZPanMaxLimit), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPTZController_Statics::NewProp_PTZPanMaxLimit_MetaData), Z_Construct_UClass_UPTZController_Statics::NewProp_PTZPanMaxLimit_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPTZController_Statics::NewProp_bPTZPanInvert_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "PTZ" },
		{ "DisplayName", "Invert Pan" },
		{ "ModuleRelativePath", "Public/Components/NDIPTZControllerComponent.h" },
	};
#endif
	void Z_Construct_UClass_UPTZController_Statics::NewProp_bPTZPanInvert_SetBit(void* Obj)
	{
		((UPTZController*)Obj)->bPTZPanInvert = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPTZController_Statics::NewProp_bPTZPanInvert = { "bPTZPanInvert", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPTZController), &Z_Construct_UClass_UPTZController_Statics::NewProp_bPTZPanInvert_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPTZController_Statics::NewProp_bPTZPanInvert_MetaData), Z_Construct_UClass_UPTZController_Statics::NewProp_bPTZPanInvert_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPTZController_Statics::NewProp_PTZWithTiltLimit_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "PTZ" },
		{ "DisplayName", "Tilt Limit" },
		{ "ModuleRelativePath", "Public/Components/NDIPTZControllerComponent.h" },
	};
#endif
	void Z_Construct_UClass_UPTZController_Statics::NewProp_PTZWithTiltLimit_SetBit(void* Obj)
	{
		((UPTZController*)Obj)->PTZWithTiltLimit = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPTZController_Statics::NewProp_PTZWithTiltLimit = { "PTZWithTiltLimit", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPTZController), &Z_Construct_UClass_UPTZController_Statics::NewProp_PTZWithTiltLimit_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPTZController_Statics::NewProp_PTZWithTiltLimit_MetaData), Z_Construct_UClass_UPTZController_Statics::NewProp_PTZWithTiltLimit_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPTZController_Statics::NewProp_PTZTiltMinLimit_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "PTZ" },
		{ "DisplayName", "Tilt Min Limit" },
		{ "ModuleRelativePath", "Public/Components/NDIPTZControllerComponent.h" },
		{ "UIMax", "180" },
		{ "UIMin", "-180" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPTZController_Statics::NewProp_PTZTiltMinLimit = { "PTZTiltMinLimit", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPTZController, PTZTiltMinLimit), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPTZController_Statics::NewProp_PTZTiltMinLimit_MetaData), Z_Construct_UClass_UPTZController_Statics::NewProp_PTZTiltMinLimit_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPTZController_Statics::NewProp_PTZTiltMaxLimit_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "PTZ" },
		{ "DisplayName", "Tilt Max Limit" },
		{ "ModuleRelativePath", "Public/Components/NDIPTZControllerComponent.h" },
		{ "UIMax", "180" },
		{ "UIMin", "-180" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPTZController_Statics::NewProp_PTZTiltMaxLimit = { "PTZTiltMaxLimit", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPTZController, PTZTiltMaxLimit), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPTZController_Statics::NewProp_PTZTiltMaxLimit_MetaData), Z_Construct_UClass_UPTZController_Statics::NewProp_PTZTiltMaxLimit_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPTZController_Statics::NewProp_bPTZTiltInvert_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "PTZ" },
		{ "DisplayName", "Invert Tilt" },
		{ "ModuleRelativePath", "Public/Components/NDIPTZControllerComponent.h" },
	};
#endif
	void Z_Construct_UClass_UPTZController_Statics::NewProp_bPTZTiltInvert_SetBit(void* Obj)
	{
		((UPTZController*)Obj)->bPTZTiltInvert = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPTZController_Statics::NewProp_bPTZTiltInvert = { "bPTZTiltInvert", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPTZController), &Z_Construct_UClass_UPTZController_Statics::NewProp_bPTZTiltInvert_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPTZController_Statics::NewProp_bPTZTiltInvert_MetaData), Z_Construct_UClass_UPTZController_Statics::NewProp_bPTZTiltInvert_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPTZController_Statics::NewProp_PTZWithFoVLimit_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "PTZ" },
		{ "DisplayName", "Field of View Limit" },
		{ "ModuleRelativePath", "Public/Components/NDIPTZControllerComponent.h" },
	};
#endif
	void Z_Construct_UClass_UPTZController_Statics::NewProp_PTZWithFoVLimit_SetBit(void* Obj)
	{
		((UPTZController*)Obj)->PTZWithFoVLimit = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPTZController_Statics::NewProp_PTZWithFoVLimit = { "PTZWithFoVLimit", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPTZController), &Z_Construct_UClass_UPTZController_Statics::NewProp_PTZWithFoVLimit_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPTZController_Statics::NewProp_PTZWithFoVLimit_MetaData), Z_Construct_UClass_UPTZController_Statics::NewProp_PTZWithFoVLimit_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPTZController_Statics::NewProp_PTZFoVMinLimit_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "PTZ" },
		{ "DisplayName", "Field of View Min Limit" },
		{ "ModuleRelativePath", "Public/Components/NDIPTZControllerComponent.h" },
		{ "UIMax", "170" },
		{ "UIMin", "5" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPTZController_Statics::NewProp_PTZFoVMinLimit = { "PTZFoVMinLimit", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPTZController, PTZFoVMinLimit), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPTZController_Statics::NewProp_PTZFoVMinLimit_MetaData), Z_Construct_UClass_UPTZController_Statics::NewProp_PTZFoVMinLimit_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPTZController_Statics::NewProp_PTZFoVMaxLimit_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "PTZ" },
		{ "DisplayName", "Field of View Max Limit" },
		{ "ModuleRelativePath", "Public/Components/NDIPTZControllerComponent.h" },
		{ "UIMax", "170" },
		{ "UIMin", "5" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPTZController_Statics::NewProp_PTZFoVMaxLimit = { "PTZFoVMaxLimit", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPTZController, PTZFoVMaxLimit), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPTZController_Statics::NewProp_PTZFoVMaxLimit_MetaData), Z_Construct_UClass_UPTZController_Statics::NewProp_PTZFoVMaxLimit_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPTZController_Statics::NewProp_PTZRecallEasing_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "PTZ" },
		{ "DisplayName", "Preset Recall Easing" },
		{ "ModuleRelativePath", "Public/Components/NDIPTZControllerComponent.h" },
		{ "UIMax", "60" },
		{ "UIMin", "0" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPTZController_Statics::NewProp_PTZRecallEasing = { "PTZRecallEasing", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPTZController, PTZRecallEasing), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPTZController_Statics::NewProp_PTZRecallEasing_MetaData), Z_Construct_UClass_UPTZController_Statics::NewProp_PTZRecallEasing_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPTZController_Statics::NewProp_PTZPanSpeed_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "PTZ" },
		{ "ModuleRelativePath", "Public/Components/NDIPTZControllerComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPTZController_Statics::NewProp_PTZPanSpeed = { "PTZPanSpeed", nullptr, (EPropertyFlags)0x0020080000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPTZController, PTZPanSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPTZController_Statics::NewProp_PTZPanSpeed_MetaData), Z_Construct_UClass_UPTZController_Statics::NewProp_PTZPanSpeed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPTZController_Statics::NewProp_PTZTiltSpeed_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "PTZ" },
		{ "ModuleRelativePath", "Public/Components/NDIPTZControllerComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPTZController_Statics::NewProp_PTZTiltSpeed = { "PTZTiltSpeed", nullptr, (EPropertyFlags)0x0020080000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPTZController, PTZTiltSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPTZController_Statics::NewProp_PTZTiltSpeed_MetaData), Z_Construct_UClass_UPTZController_Statics::NewProp_PTZTiltSpeed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPTZController_Statics::NewProp_PTZZoomSpeed_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "PTZ" },
		{ "ModuleRelativePath", "Public/Components/NDIPTZControllerComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPTZController_Statics::NewProp_PTZZoomSpeed = { "PTZZoomSpeed", nullptr, (EPropertyFlags)0x0020080000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPTZController, PTZZoomSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPTZController_Statics::NewProp_PTZZoomSpeed_MetaData), Z_Construct_UClass_UPTZController_Statics::NewProp_PTZZoomSpeed_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPTZController_Statics::NewProp_PTZStoredStates_Inner = { "PTZStoredStates", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FPTZState, METADATA_PARAMS(0, nullptr) }; // 1674629710
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPTZController_Statics::NewProp_PTZStoredStates_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "PTZ" },
		{ "DisplayName", "PTZ Presets" },
		{ "ModuleRelativePath", "Public/Components/NDIPTZControllerComponent.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UPTZController_Statics::NewProp_PTZStoredStates = { "PTZStoredStates", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPTZController, PTZStoredStates), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPTZController_Statics::NewProp_PTZStoredStates_MetaData), Z_Construct_UClass_UPTZController_Statics::NewProp_PTZStoredStates_MetaData) }; // 1674629710
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPTZController_Statics::NewProp_NDIMediaSource_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "NDI IO" },
		{ "DisplayName", "NDI Media Source" },
		{ "ModuleRelativePath", "Public/Components/NDIPTZControllerComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPTZController_Statics::NewProp_NDIMediaSource = { "NDIMediaSource", nullptr, (EPropertyFlags)0x0020080000000805, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPTZController, NDIMediaSource), Z_Construct_UClass_UNDIMediaSender_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPTZController_Statics::NewProp_NDIMediaSource_MetaData), Z_Construct_UClass_UPTZController_Statics::NewProp_NDIMediaSource_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPTZController_Statics::NewProp_OnPTZPanTiltSpeed_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "NDI Events" },
		{ "DisplayName", "On PTZ Pan Tilt Speed" },
		{ "ModuleRelativePath", "Public/Components/NDIPTZControllerComponent.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UPTZController_Statics::NewProp_OnPTZPanTiltSpeed = { "OnPTZPanTiltSpeed", nullptr, (EPropertyFlags)0x0020080010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPTZController, OnPTZPanTiltSpeed), Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZPanTiltSpeed__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPTZController_Statics::NewProp_OnPTZPanTiltSpeed_MetaData), Z_Construct_UClass_UPTZController_Statics::NewProp_OnPTZPanTiltSpeed_MetaData) }; // 666156964
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPTZController_Statics::NewProp_OnPTZZoomSpeed_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "NDI Events" },
		{ "DisplayName", "On PTZ Zoom Speed" },
		{ "ModuleRelativePath", "Public/Components/NDIPTZControllerComponent.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UPTZController_Statics::NewProp_OnPTZZoomSpeed = { "OnPTZZoomSpeed", nullptr, (EPropertyFlags)0x0020080010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPTZController, OnPTZZoomSpeed), Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZZoomSpeed__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPTZController_Statics::NewProp_OnPTZZoomSpeed_MetaData), Z_Construct_UClass_UPTZController_Statics::NewProp_OnPTZZoomSpeed_MetaData) }; // 4113550608
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPTZController_Statics::NewProp_OnPTZFocus_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "NDI Events" },
		{ "DisplayName", "On PTZ Focus" },
		{ "ModuleRelativePath", "Public/Components/NDIPTZControllerComponent.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UPTZController_Statics::NewProp_OnPTZFocus = { "OnPTZFocus", nullptr, (EPropertyFlags)0x0020080010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPTZController, OnPTZFocus), Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZFocus__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPTZController_Statics::NewProp_OnPTZFocus_MetaData), Z_Construct_UClass_UPTZController_Statics::NewProp_OnPTZFocus_MetaData) }; // 1196318244
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPTZController_Statics::NewProp_OnPTZStore_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "NDI Events" },
		{ "DisplayName", "On PTZ Store" },
		{ "ModuleRelativePath", "Public/Components/NDIPTZControllerComponent.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UPTZController_Statics::NewProp_OnPTZStore = { "OnPTZStore", nullptr, (EPropertyFlags)0x0020080010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPTZController, OnPTZStore), Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZStore__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPTZController_Statics::NewProp_OnPTZStore_MetaData), Z_Construct_UClass_UPTZController_Statics::NewProp_OnPTZStore_MetaData) }; // 4097558210
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPTZController_Statics::NewProp_OnPTZRecall_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "NDI Events" },
		{ "DisplayName", "On PTZ Recall" },
		{ "ModuleRelativePath", "Public/Components/NDIPTZControllerComponent.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UPTZController_Statics::NewProp_OnPTZRecall = { "OnPTZRecall", nullptr, (EPropertyFlags)0x0020080010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPTZController, OnPTZRecall), Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnPTZRecall__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPTZController_Statics::NewProp_OnPTZRecall_MetaData), Z_Construct_UClass_UPTZController_Statics::NewProp_OnPTZRecall_MetaData) }; // 2942106862
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPTZController_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPTZController_Statics::NewProp_EnablePTZ,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPTZController_Statics::NewProp_PTZWithPanLimit,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPTZController_Statics::NewProp_PTZPanMinLimit,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPTZController_Statics::NewProp_PTZPanMaxLimit,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPTZController_Statics::NewProp_bPTZPanInvert,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPTZController_Statics::NewProp_PTZWithTiltLimit,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPTZController_Statics::NewProp_PTZTiltMinLimit,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPTZController_Statics::NewProp_PTZTiltMaxLimit,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPTZController_Statics::NewProp_bPTZTiltInvert,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPTZController_Statics::NewProp_PTZWithFoVLimit,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPTZController_Statics::NewProp_PTZFoVMinLimit,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPTZController_Statics::NewProp_PTZFoVMaxLimit,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPTZController_Statics::NewProp_PTZRecallEasing,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPTZController_Statics::NewProp_PTZPanSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPTZController_Statics::NewProp_PTZTiltSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPTZController_Statics::NewProp_PTZZoomSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPTZController_Statics::NewProp_PTZStoredStates_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPTZController_Statics::NewProp_PTZStoredStates,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPTZController_Statics::NewProp_NDIMediaSource,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPTZController_Statics::NewProp_OnPTZPanTiltSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPTZController_Statics::NewProp_OnPTZZoomSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPTZController_Statics::NewProp_OnPTZFocus,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPTZController_Statics::NewProp_OnPTZStore,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPTZController_Statics::NewProp_OnPTZRecall,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPTZController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPTZController>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPTZController_Statics::ClassParams = {
		&UPTZController::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UPTZController_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UPTZController_Statics::PropPointers),
		0,
		0x00A000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPTZController_Statics::Class_MetaDataParams), Z_Construct_UClass_UPTZController_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPTZController_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPTZController()
	{
		if (!Z_Registration_Info_UClass_UPTZController.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPTZController.OuterSingleton, Z_Construct_UClass_UPTZController_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPTZController.OuterSingleton;
	}
	template<> NDIIO_API UClass* StaticClass<UPTZController>()
	{
		return UPTZController::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPTZController);
	struct Z_CompiledInDeferFile_FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIPTZControllerComponent_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIPTZControllerComponent_h_Statics::ScriptStructInfo[] = {
		{ FPTZState::StaticStruct, Z_Construct_UScriptStruct_FPTZState_Statics::NewStructOps, TEXT("PTZState"), &Z_Registration_Info_UScriptStruct_PTZState, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPTZState), 1674629710U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIPTZControllerComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPTZControllableInterface, UPTZControllableInterface::StaticClass, TEXT("UPTZControllableInterface"), &Z_Registration_Info_UClass_UPTZControllableInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPTZControllableInterface), 4196887756U) },
		{ Z_Construct_UClass_UPTZController, UPTZController::StaticClass, TEXT("UPTZController"), &Z_Registration_Info_UClass_UPTZController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPTZController), 709676305U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIPTZControllerComponent_h_1478488824(TEXT("/Script/NDIIO"),
		Z_CompiledInDeferFile_FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIPTZControllerComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIPTZControllerComponent_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIPTZControllerComponent_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDIPTZControllerComponent_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
