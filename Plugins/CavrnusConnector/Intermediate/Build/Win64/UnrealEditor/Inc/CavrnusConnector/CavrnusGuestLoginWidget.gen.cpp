// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CavrnusConnector/Public/UI/CavrnusGuestLoginWidget.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCavrnusGuestLoginWidget() {}
// Cross Module References
	CAVRNUSCONNECTOR_API UClass* Z_Construct_UClass_UCavrnusGuestLoginWidget_NoRegister();
	CAVRNUSCONNECTOR_API UClass* Z_Construct_UClass_UCavrnusGuestLoginWidget();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_CavrnusConnector();
	UMG_API UClass* Z_Construct_UClass_UEditableTextBox_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UCavrnusGuestLoginWidget::execOnLoginClicked)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnLoginClicked();
		P_NATIVE_END;
	}
	void UCavrnusGuestLoginWidget::StaticRegisterNativesUCavrnusGuestLoginWidget()
	{
		UClass* Class = UCavrnusGuestLoginWidget::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnLoginClicked", &UCavrnusGuestLoginWidget::execOnLoginClicked },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UCavrnusGuestLoginWidget_OnLoginClicked_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCavrnusGuestLoginWidget_OnLoginClicked_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/UI/CavrnusGuestLoginWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCavrnusGuestLoginWidget_OnLoginClicked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCavrnusGuestLoginWidget, nullptr, "OnLoginClicked", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCavrnusGuestLoginWidget_OnLoginClicked_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCavrnusGuestLoginWidget_OnLoginClicked_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCavrnusGuestLoginWidget_OnLoginClicked()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCavrnusGuestLoginWidget_OnLoginClicked_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCavrnusGuestLoginWidget);
	UClass* Z_Construct_UClass_UCavrnusGuestLoginWidget_NoRegister()
	{
		return UCavrnusGuestLoginWidget::StaticClass();
	}
	struct Z_Construct_UClass_UCavrnusGuestLoginWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GuestUsernameInput_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_GuestUsernameInput;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LoginButton_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_LoginButton;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCavrnusGuestLoginWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_CavrnusConnector,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UCavrnusGuestLoginWidget_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UCavrnusGuestLoginWidget_OnLoginClicked, "OnLoginClicked" }, // 605781110
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCavrnusGuestLoginWidget_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "UI/CavrnusGuestLoginWidget.h" },
		{ "ModuleRelativePath", "Public/UI/CavrnusGuestLoginWidget.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCavrnusGuestLoginWidget_Statics::NewProp_GuestUsernameInput_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Cavrnus" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/CavrnusGuestLoginWidget.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCavrnusGuestLoginWidget_Statics::NewProp_GuestUsernameInput = { "GuestUsernameInput", nullptr, (EPropertyFlags)0x001000000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCavrnusGuestLoginWidget, GuestUsernameInput), Z_Construct_UClass_UEditableTextBox_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UCavrnusGuestLoginWidget_Statics::NewProp_GuestUsernameInput_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCavrnusGuestLoginWidget_Statics::NewProp_GuestUsernameInput_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCavrnusGuestLoginWidget_Statics::NewProp_LoginButton_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Cavrnus" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/CavrnusGuestLoginWidget.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCavrnusGuestLoginWidget_Statics::NewProp_LoginButton = { "LoginButton", nullptr, (EPropertyFlags)0x001000000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCavrnusGuestLoginWidget, LoginButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UCavrnusGuestLoginWidget_Statics::NewProp_LoginButton_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCavrnusGuestLoginWidget_Statics::NewProp_LoginButton_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCavrnusGuestLoginWidget_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCavrnusGuestLoginWidget_Statics::NewProp_GuestUsernameInput,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCavrnusGuestLoginWidget_Statics::NewProp_LoginButton,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCavrnusGuestLoginWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCavrnusGuestLoginWidget>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UCavrnusGuestLoginWidget_Statics::ClassParams = {
		&UCavrnusGuestLoginWidget::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UCavrnusGuestLoginWidget_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UCavrnusGuestLoginWidget_Statics::PropPointers),
		0,
		0x00B010A1u,
		METADATA_PARAMS(Z_Construct_UClass_UCavrnusGuestLoginWidget_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCavrnusGuestLoginWidget_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCavrnusGuestLoginWidget()
	{
		if (!Z_Registration_Info_UClass_UCavrnusGuestLoginWidget.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCavrnusGuestLoginWidget.OuterSingleton, Z_Construct_UClass_UCavrnusGuestLoginWidget_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UCavrnusGuestLoginWidget.OuterSingleton;
	}
	template<> CAVRNUSCONNECTOR_API UClass* StaticClass<UCavrnusGuestLoginWidget>()
	{
		return UCavrnusGuestLoginWidget::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCavrnusGuestLoginWidget);
	struct Z_CompiledInDeferFile_FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_CavrnusGuestLoginWidget_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_CavrnusGuestLoginWidget_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UCavrnusGuestLoginWidget, UCavrnusGuestLoginWidget::StaticClass, TEXT("UCavrnusGuestLoginWidget"), &Z_Registration_Info_UClass_UCavrnusGuestLoginWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCavrnusGuestLoginWidget), 464768938U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_CavrnusGuestLoginWidget_h_1883376036(TEXT("/Script/CavrnusConnector"),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_CavrnusGuestLoginWidget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_CavrnusGuestLoginWidget_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS