// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Components/NDITriCasterExtComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNDITriCasterExtComponent() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTimespan();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	NDIIO_API UClass* Z_Construct_UClass_UNDIMediaSender_NoRegister();
	NDIIO_API UClass* Z_Construct_UClass_UTriCasterExtComponent();
	NDIIO_API UClass* Z_Construct_UClass_UTriCasterExtComponent_NoRegister();
	NDIIO_API UFunction* Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnTriCasterExt__DelegateSignature();
	NDIIO_API UFunction* Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnTriCasterExtCustom__DelegateSignature();
	NDIIO_API UScriptStruct* Z_Construct_UScriptStruct_FTriCasterExt();
	UPackage* Z_Construct_UPackage__Script_NDIIO();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_TriCasterExt;
class UScriptStruct* FTriCasterExt::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_TriCasterExt.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_TriCasterExt.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FTriCasterExt, (UObject*)Z_Construct_UPackage__Script_NDIIO(), TEXT("TriCasterExt"));
	}
	return Z_Registration_Info_UScriptStruct_TriCasterExt.OuterSingleton;
}
template<> NDIIO_API UScriptStruct* StaticStruct<FTriCasterExt>()
{
	return FTriCasterExt::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FTriCasterExt_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Value;
		static const UECodeGen_Private::FStrPropertyParams NewProp_KeyValues_ValueProp;
		static const UECodeGen_Private::FNamePropertyParams NewProp_KeyValues_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_KeyValues_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_KeyValues;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTriCasterExt_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Category", "NDI IO" },
		{ "DisplayName", "NDI TricasterExt" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Components/NDITriCasterExtComponent.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FTriCasterExt_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FTriCasterExt>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTriCasterExt_Statics::NewProp_Value_MetaData[] = {
		{ "Category", "TricasterExt" },
		{ "ModuleRelativePath", "Public/Components/NDITriCasterExtComponent.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FTriCasterExt_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FTriCasterExt, Value), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTriCasterExt_Statics::NewProp_Value_MetaData), Z_Construct_UScriptStruct_FTriCasterExt_Statics::NewProp_Value_MetaData) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FTriCasterExt_Statics::NewProp_KeyValues_ValueProp = { "KeyValues", nullptr, (EPropertyFlags)0x0000000000020001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FTriCasterExt_Statics::NewProp_KeyValues_Key_KeyProp = { "KeyValues_Key", nullptr, (EPropertyFlags)0x0000000000020001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTriCasterExt_Statics::NewProp_KeyValues_MetaData[] = {
		{ "Category", "TricasterExt" },
		{ "ModuleRelativePath", "Public/Components/NDITriCasterExtComponent.h" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UScriptStruct_FTriCasterExt_Statics::NewProp_KeyValues = { "KeyValues", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FTriCasterExt, KeyValues), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTriCasterExt_Statics::NewProp_KeyValues_MetaData), Z_Construct_UScriptStruct_FTriCasterExt_Statics::NewProp_KeyValues_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FTriCasterExt_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTriCasterExt_Statics::NewProp_Value,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTriCasterExt_Statics::NewProp_KeyValues_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTriCasterExt_Statics::NewProp_KeyValues_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTriCasterExt_Statics::NewProp_KeyValues,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FTriCasterExt_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_NDIIO,
		nullptr,
		&NewStructOps,
		"TriCasterExt",
		Z_Construct_UScriptStruct_FTriCasterExt_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTriCasterExt_Statics::PropPointers),
		sizeof(FTriCasterExt),
		alignof(FTriCasterExt),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTriCasterExt_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FTriCasterExt_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTriCasterExt_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FTriCasterExt()
	{
		if (!Z_Registration_Info_UScriptStruct_TriCasterExt.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_TriCasterExt.InnerSingleton, Z_Construct_UScriptStruct_FTriCasterExt_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_TriCasterExt.InnerSingleton;
	}
	struct Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnTriCasterExt__DelegateSignature_Statics
	{
		struct _Script_NDIIO_eventNDIEventDelegate_OnTriCasterExt_Parms
		{
			AActor* Actor;
			UObject* Object;
			FString PropertyElementName;
			FString PropertyValueStr;
			FTimespan EasingDuration;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Actor;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Object;
		static const UECodeGen_Private::FStrPropertyParams NewProp_PropertyElementName;
		static const UECodeGen_Private::FStrPropertyParams NewProp_PropertyValueStr;
		static const UECodeGen_Private::FStructPropertyParams NewProp_EasingDuration;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnTriCasterExt__DelegateSignature_Statics::NewProp_Actor = { "Actor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_NDIIO_eventNDIEventDelegate_OnTriCasterExt_Parms, Actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnTriCasterExt__DelegateSignature_Statics::NewProp_Object = { "Object", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_NDIIO_eventNDIEventDelegate_OnTriCasterExt_Parms, Object), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnTriCasterExt__DelegateSignature_Statics::NewProp_PropertyElementName = { "PropertyElementName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_NDIIO_eventNDIEventDelegate_OnTriCasterExt_Parms, PropertyElementName), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnTriCasterExt__DelegateSignature_Statics::NewProp_PropertyValueStr = { "PropertyValueStr", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_NDIIO_eventNDIEventDelegate_OnTriCasterExt_Parms, PropertyValueStr), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnTriCasterExt__DelegateSignature_Statics::NewProp_EasingDuration = { "EasingDuration", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_NDIIO_eventNDIEventDelegate_OnTriCasterExt_Parms, EasingDuration), Z_Construct_UScriptStruct_FTimespan, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnTriCasterExt__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnTriCasterExt__DelegateSignature_Statics::NewProp_Actor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnTriCasterExt__DelegateSignature_Statics::NewProp_Object,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnTriCasterExt__DelegateSignature_Statics::NewProp_PropertyElementName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnTriCasterExt__DelegateSignature_Statics::NewProp_PropertyValueStr,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnTriCasterExt__DelegateSignature_Statics::NewProp_EasingDuration,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnTriCasterExt__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/NDITriCasterExtComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnTriCasterExt__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_NDIIO, nullptr, "NDIEventDelegate_OnTriCasterExt__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnTriCasterExt__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnTriCasterExt__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnTriCasterExt__DelegateSignature_Statics::_Script_NDIIO_eventNDIEventDelegate_OnTriCasterExt_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnTriCasterExt__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnTriCasterExt__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnTriCasterExt__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnTriCasterExt__DelegateSignature_Statics::_Script_NDIIO_eventNDIEventDelegate_OnTriCasterExt_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnTriCasterExt__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnTriCasterExt__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FNDIEventDelegate_OnTriCasterExt_DelegateWrapper(const FMulticastScriptDelegate& NDIEventDelegate_OnTriCasterExt, AActor* Actor, UObject* Object, const FString& PropertyElementName, const FString& PropertyValueStr, FTimespan EasingDuration)
{
	struct _Script_NDIIO_eventNDIEventDelegate_OnTriCasterExt_Parms
	{
		AActor* Actor;
		UObject* Object;
		FString PropertyElementName;
		FString PropertyValueStr;
		FTimespan EasingDuration;
	};
	_Script_NDIIO_eventNDIEventDelegate_OnTriCasterExt_Parms Parms;
	Parms.Actor=Actor;
	Parms.Object=Object;
	Parms.PropertyElementName=PropertyElementName;
	Parms.PropertyValueStr=PropertyValueStr;
	Parms.EasingDuration=EasingDuration;
	NDIEventDelegate_OnTriCasterExt.ProcessMulticastDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnTriCasterExtCustom__DelegateSignature_Statics
	{
		struct _Script_NDIIO_eventNDIEventDelegate_OnTriCasterExtCustom_Parms
		{
			FTriCasterExt TCData;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TCData_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_TCData;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnTriCasterExtCustom__DelegateSignature_Statics::NewProp_TCData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnTriCasterExtCustom__DelegateSignature_Statics::NewProp_TCData = { "TCData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_NDIIO_eventNDIEventDelegate_OnTriCasterExtCustom_Parms, TCData), Z_Construct_UScriptStruct_FTriCasterExt, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnTriCasterExtCustom__DelegateSignature_Statics::NewProp_TCData_MetaData), Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnTriCasterExtCustom__DelegateSignature_Statics::NewProp_TCData_MetaData) }; // 4217628928
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnTriCasterExtCustom__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnTriCasterExtCustom__DelegateSignature_Statics::NewProp_TCData,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnTriCasterExtCustom__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/NDITriCasterExtComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnTriCasterExtCustom__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_NDIIO, nullptr, "NDIEventDelegate_OnTriCasterExtCustom__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnTriCasterExtCustom__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnTriCasterExtCustom__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnTriCasterExtCustom__DelegateSignature_Statics::_Script_NDIIO_eventNDIEventDelegate_OnTriCasterExtCustom_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnTriCasterExtCustom__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnTriCasterExtCustom__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnTriCasterExtCustom__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnTriCasterExtCustom__DelegateSignature_Statics::_Script_NDIIO_eventNDIEventDelegate_OnTriCasterExtCustom_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnTriCasterExtCustom__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnTriCasterExtCustom__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FNDIEventDelegate_OnTriCasterExtCustom_DelegateWrapper(const FMulticastScriptDelegate& NDIEventDelegate_OnTriCasterExtCustom, FTriCasterExt const& TCData)
{
	struct _Script_NDIIO_eventNDIEventDelegate_OnTriCasterExtCustom_Parms
	{
		FTriCasterExt TCData;
	};
	_Script_NDIIO_eventNDIEventDelegate_OnTriCasterExtCustom_Parms Parms;
	Parms.TCData=TCData;
	NDIEventDelegate_OnTriCasterExtCustom.ProcessMulticastDelegate<UObject>(&Parms);
}
	DEFINE_FUNCTION(UTriCasterExtComponent::execReceiveMetaDataFromSender)
	{
		P_GET_OBJECT(UNDIMediaSender,Z_Param_Sender);
		P_GET_PROPERTY(FStrProperty,Z_Param_Data);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ReceiveMetaDataFromSender(Z_Param_Sender,Z_Param_Data);
		P_NATIVE_END;
	}
	void UTriCasterExtComponent::StaticRegisterNativesUTriCasterExtComponent()
	{
		UClass* Class = UTriCasterExtComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ReceiveMetaDataFromSender", &UTriCasterExtComponent::execReceiveMetaDataFromSender },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UTriCasterExtComponent_ReceiveMetaDataFromSender_Statics
	{
		struct TriCasterExtComponent_eventReceiveMetaDataFromSender_Parms
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
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UTriCasterExtComponent_ReceiveMetaDataFromSender_Statics::NewProp_Sender = { "Sender", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TriCasterExtComponent_eventReceiveMetaDataFromSender_Parms, Sender), Z_Construct_UClass_UNDIMediaSender_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UTriCasterExtComponent_ReceiveMetaDataFromSender_Statics::NewProp_Data = { "Data", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TriCasterExtComponent_eventReceiveMetaDataFromSender_Parms, Data), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTriCasterExtComponent_ReceiveMetaDataFromSender_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTriCasterExtComponent_ReceiveMetaDataFromSender_Statics::NewProp_Sender,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTriCasterExtComponent_ReceiveMetaDataFromSender_Statics::NewProp_Data,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UTriCasterExtComponent_ReceiveMetaDataFromSender_Statics::Function_MetaDataParams[] = {
		{ "Category", "NDI IO" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Call with the TriCasterExt metadata received from an NDI media sender */" },
#endif
		{ "DisplayName", "Receive Metadata From Sender" },
		{ "ModuleRelativePath", "Public/Components/NDITriCasterExtComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Call with the TriCasterExt metadata received from an NDI media sender" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTriCasterExtComponent_ReceiveMetaDataFromSender_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UTriCasterExtComponent, nullptr, "ReceiveMetaDataFromSender", nullptr, nullptr, Z_Construct_UFunction_UTriCasterExtComponent_ReceiveMetaDataFromSender_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UTriCasterExtComponent_ReceiveMetaDataFromSender_Statics::PropPointers), sizeof(Z_Construct_UFunction_UTriCasterExtComponent_ReceiveMetaDataFromSender_Statics::TriCasterExtComponent_eventReceiveMetaDataFromSender_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UTriCasterExtComponent_ReceiveMetaDataFromSender_Statics::Function_MetaDataParams), Z_Construct_UFunction_UTriCasterExtComponent_ReceiveMetaDataFromSender_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UTriCasterExtComponent_ReceiveMetaDataFromSender_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UTriCasterExtComponent_ReceiveMetaDataFromSender_Statics::TriCasterExtComponent_eventReceiveMetaDataFromSender_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UTriCasterExtComponent_ReceiveMetaDataFromSender()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTriCasterExtComponent_ReceiveMetaDataFromSender_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UTriCasterExtComponent);
	UClass* Z_Construct_UClass_UTriCasterExtComponent_NoRegister()
	{
		return UTriCasterExtComponent::StaticClass();
	}
	struct Z_Construct_UClass_UTriCasterExtComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EnableTriCasterExt_MetaData[];
#endif
		static void NewProp_EnableTriCasterExt_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_EnableTriCasterExt;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NDIMediaSource_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_NDIMediaSource;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnTriCasterExt_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnTriCasterExt;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnTriCasterExtCustom_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnTriCasterExtCustom;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UTriCasterExtComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_NDIIO,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UTriCasterExtComponent_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UTriCasterExtComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UTriCasterExtComponent_ReceiveMetaDataFromSender, "ReceiveMetaDataFromSender" }, // 1778236909
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UTriCasterExtComponent_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTriCasterExtComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "Category", "NDI IO" },
		{ "DisplayName", "NDI TricasterExt Component" },
		{ "IncludePath", "Components/NDITriCasterExtComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Components/NDITriCasterExtComponent.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTriCasterExtComponent_Statics::NewProp_EnableTriCasterExt_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "TricasterExt" },
		{ "DisplayName", "Enable TricasterExt" },
		{ "ModuleRelativePath", "Public/Components/NDITriCasterExtComponent.h" },
	};
#endif
	void Z_Construct_UClass_UTriCasterExtComponent_Statics::NewProp_EnableTriCasterExt_SetBit(void* Obj)
	{
		((UTriCasterExtComponent*)Obj)->EnableTriCasterExt = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UTriCasterExtComponent_Statics::NewProp_EnableTriCasterExt = { "EnableTriCasterExt", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UTriCasterExtComponent), &Z_Construct_UClass_UTriCasterExtComponent_Statics::NewProp_EnableTriCasterExt_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UTriCasterExtComponent_Statics::NewProp_EnableTriCasterExt_MetaData), Z_Construct_UClass_UTriCasterExtComponent_Statics::NewProp_EnableTriCasterExt_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTriCasterExtComponent_Statics::NewProp_NDIMediaSource_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "NDI IO" },
		{ "DisplayName", "NDI Media Source" },
		{ "ModuleRelativePath", "Public/Components/NDITriCasterExtComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UTriCasterExtComponent_Statics::NewProp_NDIMediaSource = { "NDIMediaSource", nullptr, (EPropertyFlags)0x0020080000000805, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTriCasterExtComponent, NDIMediaSource), Z_Construct_UClass_UNDIMediaSender_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UTriCasterExtComponent_Statics::NewProp_NDIMediaSource_MetaData), Z_Construct_UClass_UTriCasterExtComponent_Statics::NewProp_NDIMediaSource_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTriCasterExtComponent_Statics::NewProp_OnTriCasterExt_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "NDI Events" },
		{ "DisplayName", "On TricasterExt" },
		{ "ModuleRelativePath", "Public/Components/NDITriCasterExtComponent.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UTriCasterExtComponent_Statics::NewProp_OnTriCasterExt = { "OnTriCasterExt", nullptr, (EPropertyFlags)0x0020180010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTriCasterExtComponent, OnTriCasterExt), Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnTriCasterExt__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UTriCasterExtComponent_Statics::NewProp_OnTriCasterExt_MetaData), Z_Construct_UClass_UTriCasterExtComponent_Statics::NewProp_OnTriCasterExt_MetaData) }; // 3981490082
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTriCasterExtComponent_Statics::NewProp_OnTriCasterExtCustom_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "NDI Events" },
		{ "DisplayName", "On TricasterExt Custom" },
		{ "ModuleRelativePath", "Public/Components/NDITriCasterExtComponent.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UTriCasterExtComponent_Statics::NewProp_OnTriCasterExtCustom = { "OnTriCasterExtCustom", nullptr, (EPropertyFlags)0x0020180010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTriCasterExtComponent, OnTriCasterExtCustom), Z_Construct_UDelegateFunction_NDIIO_NDIEventDelegate_OnTriCasterExtCustom__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UTriCasterExtComponent_Statics::NewProp_OnTriCasterExtCustom_MetaData), Z_Construct_UClass_UTriCasterExtComponent_Statics::NewProp_OnTriCasterExtCustom_MetaData) }; // 290805080
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UTriCasterExtComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTriCasterExtComponent_Statics::NewProp_EnableTriCasterExt,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTriCasterExtComponent_Statics::NewProp_NDIMediaSource,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTriCasterExtComponent_Statics::NewProp_OnTriCasterExt,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTriCasterExtComponent_Statics::NewProp_OnTriCasterExtCustom,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UTriCasterExtComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UTriCasterExtComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UTriCasterExtComponent_Statics::ClassParams = {
		&UTriCasterExtComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UTriCasterExtComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UTriCasterExtComponent_Statics::PropPointers),
		0,
		0x00A000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UTriCasterExtComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UTriCasterExtComponent_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UTriCasterExtComponent_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UTriCasterExtComponent()
	{
		if (!Z_Registration_Info_UClass_UTriCasterExtComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UTriCasterExtComponent.OuterSingleton, Z_Construct_UClass_UTriCasterExtComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UTriCasterExtComponent.OuterSingleton;
	}
	template<> NDIIO_API UClass* StaticClass<UTriCasterExtComponent>()
	{
		return UTriCasterExtComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UTriCasterExtComponent);
	struct Z_CompiledInDeferFile_FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDITriCasterExtComponent_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDITriCasterExtComponent_h_Statics::ScriptStructInfo[] = {
		{ FTriCasterExt::StaticStruct, Z_Construct_UScriptStruct_FTriCasterExt_Statics::NewStructOps, TEXT("TriCasterExt"), &Z_Registration_Info_UScriptStruct_TriCasterExt, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FTriCasterExt), 4217628928U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDITriCasterExtComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UTriCasterExtComponent, UTriCasterExtComponent::StaticClass, TEXT("UTriCasterExtComponent"), &Z_Registration_Info_UClass_UTriCasterExtComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UTriCasterExtComponent), 533818622U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDITriCasterExtComponent_h_2734310736(TEXT("/Script/NDIIO"),
		Z_CompiledInDeferFile_FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDITriCasterExtComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDITriCasterExtComponent_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDITriCasterExtComponent_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_play_Documents_GitHub_ComiCon_Plugins_NDIIO_Source_Core_Public_Components_NDITriCasterExtComponent_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
