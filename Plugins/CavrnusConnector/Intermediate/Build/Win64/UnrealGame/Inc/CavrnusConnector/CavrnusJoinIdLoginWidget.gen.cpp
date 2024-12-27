// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CavrnusConnector/Public/UI/JoinCodeLogin/CavrnusJoinIdLoginWidget.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCavrnusJoinIdLoginWidget() {}
// Cross Module References
	CAVRNUSCONNECTOR_API UFunction* Z_Construct_UDelegateFunction_CavrnusConnector_OnJoinIdWidgetCloseButtonClicked__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_CavrnusConnector();
	CAVRNUSCONNECTOR_API UClass* Z_Construct_UClass_UCavrnusJoinIdLoginWidget_NoRegister();
	CAVRNUSCONNECTOR_API UClass* Z_Construct_UClass_UCavrnusJoinIdLoginWidget();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	SLATECORE_API UEnum* Z_Construct_UEnum_SlateCore_ETextCommit();
	CAVRNUSCONNECTOR_API UClass* Z_Construct_UClass_UCavrnusInputField_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
	SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FButtonStyle();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_CavrnusConnector_OnJoinIdWidgetCloseButtonClicked__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_CavrnusConnector_OnJoinIdWidgetCloseButtonClicked__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/UI/JoinCodeLogin/CavrnusJoinIdLoginWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_CavrnusConnector_OnJoinIdWidgetCloseButtonClicked__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_CavrnusConnector, nullptr, "OnJoinIdWidgetCloseButtonClicked__DelegateSignature", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_CavrnusConnector_OnJoinIdWidgetCloseButtonClicked__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_CavrnusConnector_OnJoinIdWidgetCloseButtonClicked__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_CavrnusConnector_OnJoinIdWidgetCloseButtonClicked__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_CavrnusConnector_OnJoinIdWidgetCloseButtonClicked__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	DEFINE_FUNCTION(UCavrnusJoinIdLoginWidget::execCloseButtonClicked)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CloseButtonClicked();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCavrnusJoinIdLoginWidget::execTryJoinSpaceButtonClicked)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->TryJoinSpaceButtonClicked();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCavrnusJoinIdLoginWidget::execJoinCodeInputCommitted)
	{
		P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_Text);
		P_GET_PROPERTY(FByteProperty,Z_Param_CommitMethod);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->JoinCodeInputCommitted(Z_Param_Out_Text,ETextCommit::Type(Z_Param_CommitMethod));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCavrnusJoinIdLoginWidget::execJoinCodeInputUpdated)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_Text);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->JoinCodeInputUpdated(Z_Param_Text);
		P_NATIVE_END;
	}
	void UCavrnusJoinIdLoginWidget::StaticRegisterNativesUCavrnusJoinIdLoginWidget()
	{
		UClass* Class = UCavrnusJoinIdLoginWidget::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CloseButtonClicked", &UCavrnusJoinIdLoginWidget::execCloseButtonClicked },
			{ "JoinCodeInputCommitted", &UCavrnusJoinIdLoginWidget::execJoinCodeInputCommitted },
			{ "JoinCodeInputUpdated", &UCavrnusJoinIdLoginWidget::execJoinCodeInputUpdated },
			{ "TryJoinSpaceButtonClicked", &UCavrnusJoinIdLoginWidget::execTryJoinSpaceButtonClicked },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_CloseButtonClicked_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_CloseButtonClicked_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/UI/JoinCodeLogin/CavrnusJoinIdLoginWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_CloseButtonClicked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCavrnusJoinIdLoginWidget, nullptr, "CloseButtonClicked", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_CloseButtonClicked_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_CloseButtonClicked_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_CloseButtonClicked()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_CloseButtonClicked_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_JoinCodeInputCommitted_Statics
	{
		struct CavrnusJoinIdLoginWidget_eventJoinCodeInputCommitted_Parms
		{
			FText Text;
			TEnumAsByte<ETextCommit::Type> CommitMethod;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Text_MetaData[];
#endif
		static const UECodeGen_Private::FTextPropertyParams NewProp_Text;
		static const UECodeGen_Private::FBytePropertyParams NewProp_CommitMethod;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_JoinCodeInputCommitted_Statics::NewProp_Text_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_JoinCodeInputCommitted_Statics::NewProp_Text = { "Text", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CavrnusJoinIdLoginWidget_eventJoinCodeInputCommitted_Parms, Text), METADATA_PARAMS(Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_JoinCodeInputCommitted_Statics::NewProp_Text_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_JoinCodeInputCommitted_Statics::NewProp_Text_MetaData)) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_JoinCodeInputCommitted_Statics::NewProp_CommitMethod = { "CommitMethod", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CavrnusJoinIdLoginWidget_eventJoinCodeInputCommitted_Parms, CommitMethod), Z_Construct_UEnum_SlateCore_ETextCommit, METADATA_PARAMS(nullptr, 0) }; // 1116915171
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_JoinCodeInputCommitted_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_JoinCodeInputCommitted_Statics::NewProp_Text,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_JoinCodeInputCommitted_Statics::NewProp_CommitMethod,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_JoinCodeInputCommitted_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/UI/JoinCodeLogin/CavrnusJoinIdLoginWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_JoinCodeInputCommitted_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCavrnusJoinIdLoginWidget, nullptr, "JoinCodeInputCommitted", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_JoinCodeInputCommitted_Statics::CavrnusJoinIdLoginWidget_eventJoinCodeInputCommitted_Parms), Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_JoinCodeInputCommitted_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_JoinCodeInputCommitted_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00440401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_JoinCodeInputCommitted_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_JoinCodeInputCommitted_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_JoinCodeInputCommitted()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_JoinCodeInputCommitted_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_JoinCodeInputUpdated_Statics
	{
		struct CavrnusJoinIdLoginWidget_eventJoinCodeInputUpdated_Parms
		{
			FString Text;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Text_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Text;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_JoinCodeInputUpdated_Statics::NewProp_Text_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_JoinCodeInputUpdated_Statics::NewProp_Text = { "Text", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CavrnusJoinIdLoginWidget_eventJoinCodeInputUpdated_Parms, Text), METADATA_PARAMS(Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_JoinCodeInputUpdated_Statics::NewProp_Text_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_JoinCodeInputUpdated_Statics::NewProp_Text_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_JoinCodeInputUpdated_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_JoinCodeInputUpdated_Statics::NewProp_Text,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_JoinCodeInputUpdated_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/UI/JoinCodeLogin/CavrnusJoinIdLoginWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_JoinCodeInputUpdated_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCavrnusJoinIdLoginWidget, nullptr, "JoinCodeInputUpdated", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_JoinCodeInputUpdated_Statics::CavrnusJoinIdLoginWidget_eventJoinCodeInputUpdated_Parms), Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_JoinCodeInputUpdated_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_JoinCodeInputUpdated_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_JoinCodeInputUpdated_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_JoinCodeInputUpdated_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_JoinCodeInputUpdated()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_JoinCodeInputUpdated_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_TryJoinSpaceButtonClicked_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_TryJoinSpaceButtonClicked_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/UI/JoinCodeLogin/CavrnusJoinIdLoginWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_TryJoinSpaceButtonClicked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCavrnusJoinIdLoginWidget, nullptr, "TryJoinSpaceButtonClicked", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_TryJoinSpaceButtonClicked_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_TryJoinSpaceButtonClicked_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_TryJoinSpaceButtonClicked()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_TryJoinSpaceButtonClicked_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCavrnusJoinIdLoginWidget);
	UClass* Z_Construct_UClass_UCavrnusJoinIdLoginWidget_NoRegister()
	{
		return UCavrnusJoinIdLoginWidget::StaticClass();
	}
	struct Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_JoinCodeInputField_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_JoinCodeInputField;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TryJoinSpaceButton_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TryJoinSpaceButton;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CloseButton_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CloseButton;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_JoinSpaceButtonText_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_JoinSpaceButtonText;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnCloseButtonClicked_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCloseButtonClicked;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CurrentSelectedViewButton_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CurrentSelectedViewButton;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InitialButtonStyle_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_InitialButtonStyle;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ActivatedStyle_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ActivatedStyle;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_CavrnusConnector,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_CloseButtonClicked, "CloseButtonClicked" }, // 861360098
		{ &Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_JoinCodeInputCommitted, "JoinCodeInputCommitted" }, // 796535149
		{ &Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_JoinCodeInputUpdated, "JoinCodeInputUpdated" }, // 1777483004
		{ &Z_Construct_UFunction_UCavrnusJoinIdLoginWidget_TryJoinSpaceButtonClicked, "TryJoinSpaceButtonClicked" }, // 2692647975
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "UI/JoinCodeLogin/CavrnusJoinIdLoginWidget.h" },
		{ "ModuleRelativePath", "Public/UI/JoinCodeLogin/CavrnusJoinIdLoginWidget.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::NewProp_JoinCodeInputField_MetaData[] = {
		{ "BindWidget", "" },
		{ "Comment", "// JoinCode Fields\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/JoinCodeLogin/CavrnusJoinIdLoginWidget.h" },
		{ "ToolTip", "JoinCode Fields" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::NewProp_JoinCodeInputField = { "JoinCodeInputField", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCavrnusJoinIdLoginWidget, JoinCodeInputField), Z_Construct_UClass_UCavrnusInputField_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::NewProp_JoinCodeInputField_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::NewProp_JoinCodeInputField_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::NewProp_TryJoinSpaceButton_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/JoinCodeLogin/CavrnusJoinIdLoginWidget.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::NewProp_TryJoinSpaceButton = { "TryJoinSpaceButton", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCavrnusJoinIdLoginWidget, TryJoinSpaceButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::NewProp_TryJoinSpaceButton_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::NewProp_TryJoinSpaceButton_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::NewProp_CloseButton_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/JoinCodeLogin/CavrnusJoinIdLoginWidget.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::NewProp_CloseButton = { "CloseButton", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCavrnusJoinIdLoginWidget, CloseButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::NewProp_CloseButton_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::NewProp_CloseButton_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::NewProp_JoinSpaceButtonText_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/JoinCodeLogin/CavrnusJoinIdLoginWidget.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::NewProp_JoinSpaceButtonText = { "JoinSpaceButtonText", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCavrnusJoinIdLoginWidget, JoinSpaceButtonText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::NewProp_JoinSpaceButtonText_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::NewProp_JoinSpaceButtonText_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::NewProp_OnCloseButtonClicked_MetaData[] = {
		{ "Category", "Cavrnus|InputField" },
		{ "ModuleRelativePath", "Public/UI/JoinCodeLogin/CavrnusJoinIdLoginWidget.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::NewProp_OnCloseButtonClicked = { "OnCloseButtonClicked", nullptr, (EPropertyFlags)0x0040000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCavrnusJoinIdLoginWidget, OnCloseButtonClicked), Z_Construct_UDelegateFunction_CavrnusConnector_OnJoinIdWidgetCloseButtonClicked__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::NewProp_OnCloseButtonClicked_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::NewProp_OnCloseButtonClicked_MetaData)) }; // 461869873
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::NewProp_CurrentSelectedViewButton_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/JoinCodeLogin/CavrnusJoinIdLoginWidget.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::NewProp_CurrentSelectedViewButton = { "CurrentSelectedViewButton", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCavrnusJoinIdLoginWidget, CurrentSelectedViewButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::NewProp_CurrentSelectedViewButton_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::NewProp_CurrentSelectedViewButton_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::NewProp_InitialButtonStyle_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/JoinCodeLogin/CavrnusJoinIdLoginWidget.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::NewProp_InitialButtonStyle = { "InitialButtonStyle", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCavrnusJoinIdLoginWidget, InitialButtonStyle), Z_Construct_UScriptStruct_FButtonStyle, METADATA_PARAMS(Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::NewProp_InitialButtonStyle_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::NewProp_InitialButtonStyle_MetaData)) }; // 2266899118
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::NewProp_ActivatedStyle_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/JoinCodeLogin/CavrnusJoinIdLoginWidget.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::NewProp_ActivatedStyle = { "ActivatedStyle", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCavrnusJoinIdLoginWidget, ActivatedStyle), Z_Construct_UScriptStruct_FButtonStyle, METADATA_PARAMS(Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::NewProp_ActivatedStyle_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::NewProp_ActivatedStyle_MetaData)) }; // 2266899118
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::NewProp_JoinCodeInputField,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::NewProp_TryJoinSpaceButton,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::NewProp_CloseButton,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::NewProp_JoinSpaceButtonText,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::NewProp_OnCloseButtonClicked,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::NewProp_CurrentSelectedViewButton,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::NewProp_InitialButtonStyle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::NewProp_ActivatedStyle,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCavrnusJoinIdLoginWidget>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::ClassParams = {
		&UCavrnusJoinIdLoginWidget::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCavrnusJoinIdLoginWidget()
	{
		if (!Z_Registration_Info_UClass_UCavrnusJoinIdLoginWidget.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCavrnusJoinIdLoginWidget.OuterSingleton, Z_Construct_UClass_UCavrnusJoinIdLoginWidget_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UCavrnusJoinIdLoginWidget.OuterSingleton;
	}
	template<> CAVRNUSCONNECTOR_API UClass* StaticClass<UCavrnusJoinIdLoginWidget>()
	{
		return UCavrnusJoinIdLoginWidget::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCavrnusJoinIdLoginWidget);
	struct Z_CompiledInDeferFile_FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_JoinCodeLogin_CavrnusJoinIdLoginWidget_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_JoinCodeLogin_CavrnusJoinIdLoginWidget_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UCavrnusJoinIdLoginWidget, UCavrnusJoinIdLoginWidget::StaticClass, TEXT("UCavrnusJoinIdLoginWidget"), &Z_Registration_Info_UClass_UCavrnusJoinIdLoginWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCavrnusJoinIdLoginWidget), 2943553990U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_JoinCodeLogin_CavrnusJoinIdLoginWidget_h_1317035144(TEXT("/Script/CavrnusConnector"),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_JoinCodeLogin_CavrnusJoinIdLoginWidget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_JoinCodeLogin_CavrnusJoinIdLoginWidget_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
