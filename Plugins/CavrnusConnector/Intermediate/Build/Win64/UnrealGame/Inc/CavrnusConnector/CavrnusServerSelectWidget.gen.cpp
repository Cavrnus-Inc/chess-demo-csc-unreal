// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CavrnusConnector/Public/UI/ServerLoginMenu/CavrnusServerSelectWidget.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCavrnusServerSelectWidget() {}
// Cross Module References
	CAVRNUSCONNECTOR_API UClass* Z_Construct_UClass_UCavrnusSeverSelectWidget_NoRegister();
	CAVRNUSCONNECTOR_API UClass* Z_Construct_UClass_UCavrnusSeverSelectWidget();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_CavrnusConnector();
	UMG_API UClass* Z_Construct_UClass_UEditableTextBox_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UCavrnusSeverSelectWidget::execServerTextBoxUpdated)
	{
		P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_Text);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ServerTextBoxUpdated(Z_Param_Out_Text);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCavrnusSeverSelectWidget::execProceedButtonClicked)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ProceedButtonClicked();
		P_NATIVE_END;
	}
	void UCavrnusSeverSelectWidget::StaticRegisterNativesUCavrnusSeverSelectWidget()
	{
		UClass* Class = UCavrnusSeverSelectWidget::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ProceedButtonClicked", &UCavrnusSeverSelectWidget::execProceedButtonClicked },
			{ "ServerTextBoxUpdated", &UCavrnusSeverSelectWidget::execServerTextBoxUpdated },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UCavrnusSeverSelectWidget_ProceedButtonClicked_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCavrnusSeverSelectWidget_ProceedButtonClicked_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/UI/ServerLoginMenu/CavrnusServerSelectWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCavrnusSeverSelectWidget_ProceedButtonClicked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCavrnusSeverSelectWidget, nullptr, "ProceedButtonClicked", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCavrnusSeverSelectWidget_ProceedButtonClicked_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCavrnusSeverSelectWidget_ProceedButtonClicked_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCavrnusSeverSelectWidget_ProceedButtonClicked()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCavrnusSeverSelectWidget_ProceedButtonClicked_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCavrnusSeverSelectWidget_ServerTextBoxUpdated_Statics
	{
		struct CavrnusSeverSelectWidget_eventServerTextBoxUpdated_Parms
		{
			FText Text;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Text_MetaData[];
#endif
		static const UECodeGen_Private::FTextPropertyParams NewProp_Text;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCavrnusSeverSelectWidget_ServerTextBoxUpdated_Statics::NewProp_Text_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UCavrnusSeverSelectWidget_ServerTextBoxUpdated_Statics::NewProp_Text = { "Text", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CavrnusSeverSelectWidget_eventServerTextBoxUpdated_Parms, Text), METADATA_PARAMS(Z_Construct_UFunction_UCavrnusSeverSelectWidget_ServerTextBoxUpdated_Statics::NewProp_Text_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCavrnusSeverSelectWidget_ServerTextBoxUpdated_Statics::NewProp_Text_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCavrnusSeverSelectWidget_ServerTextBoxUpdated_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCavrnusSeverSelectWidget_ServerTextBoxUpdated_Statics::NewProp_Text,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCavrnusSeverSelectWidget_ServerTextBoxUpdated_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/UI/ServerLoginMenu/CavrnusServerSelectWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCavrnusSeverSelectWidget_ServerTextBoxUpdated_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCavrnusSeverSelectWidget, nullptr, "ServerTextBoxUpdated", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCavrnusSeverSelectWidget_ServerTextBoxUpdated_Statics::CavrnusSeverSelectWidget_eventServerTextBoxUpdated_Parms), Z_Construct_UFunction_UCavrnusSeverSelectWidget_ServerTextBoxUpdated_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCavrnusSeverSelectWidget_ServerTextBoxUpdated_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00440401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCavrnusSeverSelectWidget_ServerTextBoxUpdated_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCavrnusSeverSelectWidget_ServerTextBoxUpdated_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCavrnusSeverSelectWidget_ServerTextBoxUpdated()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCavrnusSeverSelectWidget_ServerTextBoxUpdated_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCavrnusSeverSelectWidget);
	UClass* Z_Construct_UClass_UCavrnusSeverSelectWidget_NoRegister()
	{
		return UCavrnusSeverSelectWidget::StaticClass();
	}
	struct Z_Construct_UClass_UCavrnusSeverSelectWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ServerTextBox_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ServerTextBox;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ProceedButton_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ProceedButton;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCavrnusSeverSelectWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_CavrnusConnector,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UCavrnusSeverSelectWidget_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UCavrnusSeverSelectWidget_ProceedButtonClicked, "ProceedButtonClicked" }, // 833912919
		{ &Z_Construct_UFunction_UCavrnusSeverSelectWidget_ServerTextBoxUpdated, "ServerTextBoxUpdated" }, // 2721078419
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCavrnusSeverSelectWidget_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "UI/ServerLoginMenu/CavrnusServerSelectWidget.h" },
		{ "ModuleRelativePath", "Public/UI/ServerLoginMenu/CavrnusServerSelectWidget.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCavrnusSeverSelectWidget_Statics::NewProp_ServerTextBox_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Cavrnus|ServerWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/ServerLoginMenu/CavrnusServerSelectWidget.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCavrnusSeverSelectWidget_Statics::NewProp_ServerTextBox = { "ServerTextBox", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCavrnusSeverSelectWidget, ServerTextBox), Z_Construct_UClass_UEditableTextBox_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UCavrnusSeverSelectWidget_Statics::NewProp_ServerTextBox_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCavrnusSeverSelectWidget_Statics::NewProp_ServerTextBox_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCavrnusSeverSelectWidget_Statics::NewProp_ProceedButton_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Cavrnus|ServerWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/ServerLoginMenu/CavrnusServerSelectWidget.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCavrnusSeverSelectWidget_Statics::NewProp_ProceedButton = { "ProceedButton", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCavrnusSeverSelectWidget, ProceedButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UCavrnusSeverSelectWidget_Statics::NewProp_ProceedButton_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCavrnusSeverSelectWidget_Statics::NewProp_ProceedButton_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCavrnusSeverSelectWidget_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCavrnusSeverSelectWidget_Statics::NewProp_ServerTextBox,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCavrnusSeverSelectWidget_Statics::NewProp_ProceedButton,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCavrnusSeverSelectWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCavrnusSeverSelectWidget>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UCavrnusSeverSelectWidget_Statics::ClassParams = {
		&UCavrnusSeverSelectWidget::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UCavrnusSeverSelectWidget_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UCavrnusSeverSelectWidget_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UCavrnusSeverSelectWidget_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCavrnusSeverSelectWidget_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCavrnusSeverSelectWidget()
	{
		if (!Z_Registration_Info_UClass_UCavrnusSeverSelectWidget.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCavrnusSeverSelectWidget.OuterSingleton, Z_Construct_UClass_UCavrnusSeverSelectWidget_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UCavrnusSeverSelectWidget.OuterSingleton;
	}
	template<> CAVRNUSCONNECTOR_API UClass* StaticClass<UCavrnusSeverSelectWidget>()
	{
		return UCavrnusSeverSelectWidget::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCavrnusSeverSelectWidget);
	struct Z_CompiledInDeferFile_FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_ServerLoginMenu_CavrnusServerSelectWidget_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_ServerLoginMenu_CavrnusServerSelectWidget_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UCavrnusSeverSelectWidget, UCavrnusSeverSelectWidget::StaticClass, TEXT("UCavrnusSeverSelectWidget"), &Z_Registration_Info_UClass_UCavrnusSeverSelectWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCavrnusSeverSelectWidget), 2761967772U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_ServerLoginMenu_CavrnusServerSelectWidget_h_1990818119(TEXT("/Script/CavrnusConnector"),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_ServerLoginMenu_CavrnusServerSelectWidget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_ServerLoginMenu_CavrnusServerSelectWidget_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
