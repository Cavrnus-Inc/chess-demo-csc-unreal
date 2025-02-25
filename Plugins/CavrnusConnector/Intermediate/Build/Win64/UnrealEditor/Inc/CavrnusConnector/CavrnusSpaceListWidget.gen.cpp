// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CavrnusConnector/Public/UI/CavrnusSpaceListWidget.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCavrnusSpaceListWidget() {}
// Cross Module References
	CAVRNUSCONNECTOR_API UFunction* Z_Construct_UDelegateFunction_CavrnusConnector_OnCavrnusSpaceSelected__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_CavrnusConnector();
	CAVRNUSCONNECTOR_API UScriptStruct* Z_Construct_UScriptStruct_FCavrnusSpaceInfo();
	CAVRNUSCONNECTOR_API UClass* Z_Construct_UClass_UCavrnusSpaceListWidget_NoRegister();
	CAVRNUSCONNECTOR_API UClass* Z_Construct_UClass_UCavrnusSpaceListWidget();
	CAVRNUSCONNECTOR_API UClass* Z_Construct_UClass_UCavrnusBaseUserWidget();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
	CAVRNUSCONNECTOR_API UClass* Z_Construct_UClass_UPagination_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UEditableTextBox_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
	CAVRNUSCONNECTOR_API UClass* Z_Construct_UClass_UCavrnusBinding_NoRegister();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_CavrnusConnector_OnCavrnusSpaceSelected__DelegateSignature_Statics
	{
		struct _Script_CavrnusConnector_eventOnCavrnusSpaceSelected_Parms
		{
			FCavrnusSpaceInfo SpaceInfo;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_SpaceInfo;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_CavrnusConnector_OnCavrnusSpaceSelected__DelegateSignature_Statics::NewProp_SpaceInfo = { "SpaceInfo", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_CavrnusConnector_eventOnCavrnusSpaceSelected_Parms, SpaceInfo), Z_Construct_UScriptStruct_FCavrnusSpaceInfo, METADATA_PARAMS(nullptr, 0) }; // 25966878
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_CavrnusConnector_OnCavrnusSpaceSelected__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_CavrnusConnector_OnCavrnusSpaceSelected__DelegateSignature_Statics::NewProp_SpaceInfo,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_CavrnusConnector_OnCavrnusSpaceSelected__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/**\n * @brief Delegate for handling the selection of a Cavrnus space.\n * @param FString The ID of the selected space.\n */" },
		{ "ModuleRelativePath", "Public/UI/CavrnusSpaceListWidget.h" },
		{ "ToolTip", "@brief Delegate for handling the selection of a Cavrnus space.\n@param FString The ID of the selected space." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_CavrnusConnector_OnCavrnusSpaceSelected__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_CavrnusConnector, nullptr, "OnCavrnusSpaceSelected__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_CavrnusConnector_OnCavrnusSpaceSelected__DelegateSignature_Statics::_Script_CavrnusConnector_eventOnCavrnusSpaceSelected_Parms), Z_Construct_UDelegateFunction_CavrnusConnector_OnCavrnusSpaceSelected__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_CavrnusConnector_OnCavrnusSpaceSelected__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_CavrnusConnector_OnCavrnusSpaceSelected__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_CavrnusConnector_OnCavrnusSpaceSelected__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_CavrnusConnector_OnCavrnusSpaceSelected__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_CavrnusConnector_OnCavrnusSpaceSelected__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	DEFINE_FUNCTION(UCavrnusSpaceListWidget::execBlueprintSelectedSpaceToJoin)
	{
		P_GET_STRUCT(FCavrnusSpaceInfo,Z_Param_SpaceInfo);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BlueprintSelectedSpaceToJoin(Z_Param_SpaceInfo);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCavrnusSpaceListWidget::execSearch)
	{
		P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_SearchValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Search(Z_Param_Out_SearchValue);
		P_NATIVE_END;
	}
	void UCavrnusSpaceListWidget::StaticRegisterNativesUCavrnusSpaceListWidget()
	{
		UClass* Class = UCavrnusSpaceListWidget::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "BlueprintSelectedSpaceToJoin", &UCavrnusSpaceListWidget::execBlueprintSelectedSpaceToJoin },
			{ "Search", &UCavrnusSpaceListWidget::execSearch },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UCavrnusSpaceListWidget_BlueprintSelectedSpaceToJoin_Statics
	{
		struct CavrnusSpaceListWidget_eventBlueprintSelectedSpaceToJoin_Parms
		{
			FCavrnusSpaceInfo SpaceInfo;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_SpaceInfo;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCavrnusSpaceListWidget_BlueprintSelectedSpaceToJoin_Statics::NewProp_SpaceInfo = { "SpaceInfo", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CavrnusSpaceListWidget_eventBlueprintSelectedSpaceToJoin_Parms, SpaceInfo), Z_Construct_UScriptStruct_FCavrnusSpaceInfo, METADATA_PARAMS(nullptr, 0) }; // 25966878
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCavrnusSpaceListWidget_BlueprintSelectedSpaceToJoin_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCavrnusSpaceListWidget_BlueprintSelectedSpaceToJoin_Statics::NewProp_SpaceInfo,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCavrnusSpaceListWidget_BlueprintSelectedSpaceToJoin_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/UI/CavrnusSpaceListWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCavrnusSpaceListWidget_BlueprintSelectedSpaceToJoin_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCavrnusSpaceListWidget, nullptr, "BlueprintSelectedSpaceToJoin", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCavrnusSpaceListWidget_BlueprintSelectedSpaceToJoin_Statics::CavrnusSpaceListWidget_eventBlueprintSelectedSpaceToJoin_Parms), Z_Construct_UFunction_UCavrnusSpaceListWidget_BlueprintSelectedSpaceToJoin_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCavrnusSpaceListWidget_BlueprintSelectedSpaceToJoin_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCavrnusSpaceListWidget_BlueprintSelectedSpaceToJoin_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCavrnusSpaceListWidget_BlueprintSelectedSpaceToJoin_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCavrnusSpaceListWidget_BlueprintSelectedSpaceToJoin()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCavrnusSpaceListWidget_BlueprintSelectedSpaceToJoin_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCavrnusSpaceListWidget_Search_Statics
	{
		struct CavrnusSpaceListWidget_eventSearch_Parms
		{
			FText SearchValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SearchValue_MetaData[];
#endif
		static const UECodeGen_Private::FTextPropertyParams NewProp_SearchValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCavrnusSpaceListWidget_Search_Statics::NewProp_SearchValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UCavrnusSpaceListWidget_Search_Statics::NewProp_SearchValue = { "SearchValue", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CavrnusSpaceListWidget_eventSearch_Parms, SearchValue), METADATA_PARAMS(Z_Construct_UFunction_UCavrnusSpaceListWidget_Search_Statics::NewProp_SearchValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCavrnusSpaceListWidget_Search_Statics::NewProp_SearchValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCavrnusSpaceListWidget_Search_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCavrnusSpaceListWidget_Search_Statics::NewProp_SearchValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCavrnusSpaceListWidget_Search_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/**\n\x09 * @brief Searches the space list based on the input search value.\n\x09 * @param SearchValue The text to search for.\n\x09 */" },
		{ "ModuleRelativePath", "Public/UI/CavrnusSpaceListWidget.h" },
		{ "ToolTip", "@brief Searches the space list based on the input search value.\n@param SearchValue The text to search for." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCavrnusSpaceListWidget_Search_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCavrnusSpaceListWidget, nullptr, "Search", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCavrnusSpaceListWidget_Search_Statics::CavrnusSpaceListWidget_eventSearch_Parms), Z_Construct_UFunction_UCavrnusSpaceListWidget_Search_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCavrnusSpaceListWidget_Search_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCavrnusSpaceListWidget_Search_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCavrnusSpaceListWidget_Search_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCavrnusSpaceListWidget_Search()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCavrnusSpaceListWidget_Search_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCavrnusSpaceListWidget);
	UClass* Z_Construct_UClass_UCavrnusSpaceListWidget_NoRegister()
	{
		return UCavrnusSpaceListWidget::StaticClass();
	}
	struct Z_Construct_UClass_UCavrnusSpaceListWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PaginationItemWidget_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_PaginationItemWidget;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SpacePagination_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SpacePagination;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SearchTextBox_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SearchTextBox;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ButtonCreateSpace_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ButtonCreateSpace;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnCavrnusSpaceSelected_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCavrnusSpaceSelected;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_JoinableSpacesBinding_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_JoinableSpacesBinding;
		static const UECodeGen_Private::FStructPropertyParams NewProp_AllSpaces_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AllSpaces_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_AllSpaces;
		static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentDisplayedSpaces_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CurrentDisplayedSpaces_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_CurrentDisplayedSpaces;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UCavrnusBaseUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_CavrnusConnector,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UCavrnusSpaceListWidget_BlueprintSelectedSpaceToJoin, "BlueprintSelectedSpaceToJoin" }, // 3403013500
		{ &Z_Construct_UFunction_UCavrnusSpaceListWidget_Search, "Search" }, // 2897231799
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * @brief Widget class for displaying and managing a list of Cavrnus spaces.\n * This widget allows users to search, paginate, and select spaces from a list.\n */" },
		{ "IncludePath", "UI/CavrnusSpaceListWidget.h" },
		{ "ModuleRelativePath", "Public/UI/CavrnusSpaceListWidget.h" },
		{ "ToolTip", "@brief Widget class for displaying and managing a list of Cavrnus spaces.\nThis widget allows users to search, paginate, and select spaces from a list." },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::NewProp_PaginationItemWidget_MetaData[] = {
		{ "Category", "Cavrnus|SpaceList" },
		{ "Comment", "/** The widget class for pagination items. */" },
		{ "ModuleRelativePath", "Public/UI/CavrnusSpaceListWidget.h" },
		{ "ToolTip", "The widget class for pagination items." },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::NewProp_PaginationItemWidget = { "PaginationItemWidget", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCavrnusSpaceListWidget, PaginationItemWidget), Z_Construct_UClass_UUserWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::NewProp_PaginationItemWidget_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::NewProp_PaginationItemWidget_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::NewProp_SpacePagination_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Cavrnus|SpaceList" },
		{ "Comment", "/** The pagination widget for navigating through spaces. */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/CavrnusSpaceListWidget.h" },
		{ "ToolTip", "The pagination widget for navigating through spaces." },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::NewProp_SpacePagination = { "SpacePagination", nullptr, (EPropertyFlags)0x001000000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCavrnusSpaceListWidget, SpacePagination), Z_Construct_UClass_UPagination_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::NewProp_SpacePagination_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::NewProp_SpacePagination_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::NewProp_SearchTextBox_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Cavrnus|SpaceList" },
		{ "Comment", "/** The text box for entering search terms. */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/CavrnusSpaceListWidget.h" },
		{ "ToolTip", "The text box for entering search terms." },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::NewProp_SearchTextBox = { "SearchTextBox", nullptr, (EPropertyFlags)0x0010000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCavrnusSpaceListWidget, SearchTextBox), Z_Construct_UClass_UEditableTextBox_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::NewProp_SearchTextBox_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::NewProp_SearchTextBox_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::NewProp_ButtonCreateSpace_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Cavrnus|SpaceList" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/CavrnusSpaceListWidget.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::NewProp_ButtonCreateSpace = { "ButtonCreateSpace", nullptr, (EPropertyFlags)0x0010000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCavrnusSpaceListWidget, ButtonCreateSpace), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::NewProp_ButtonCreateSpace_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::NewProp_ButtonCreateSpace_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::NewProp_OnCavrnusSpaceSelected_MetaData[] = {
		{ "Category", "Cavrnus|SpaceList" },
		{ "Comment", "/** Delegate for handling the selection of a Cavrnus space. */" },
		{ "ModuleRelativePath", "Public/UI/CavrnusSpaceListWidget.h" },
		{ "ToolTip", "Delegate for handling the selection of a Cavrnus space." },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::NewProp_OnCavrnusSpaceSelected = { "OnCavrnusSpaceSelected", nullptr, (EPropertyFlags)0x0010100010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCavrnusSpaceListWidget, OnCavrnusSpaceSelected), Z_Construct_UDelegateFunction_CavrnusConnector_OnCavrnusSpaceSelected__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::NewProp_OnCavrnusSpaceSelected_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::NewProp_OnCavrnusSpaceSelected_MetaData)) }; // 2874705462
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::NewProp_JoinableSpacesBinding_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/CavrnusSpaceListWidget.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::NewProp_JoinableSpacesBinding = { "JoinableSpacesBinding", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCavrnusSpaceListWidget, JoinableSpacesBinding), Z_Construct_UClass_UCavrnusBinding_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::NewProp_JoinableSpacesBinding_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::NewProp_JoinableSpacesBinding_MetaData)) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::NewProp_AllSpaces_Inner = { "AllSpaces", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FCavrnusSpaceInfo, METADATA_PARAMS(nullptr, 0) }; // 25966878
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::NewProp_AllSpaces_MetaData[] = {
		{ "Comment", "/** List of all spaces available. */" },
		{ "ModuleRelativePath", "Public/UI/CavrnusSpaceListWidget.h" },
		{ "ToolTip", "List of all spaces available." },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::NewProp_AllSpaces = { "AllSpaces", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCavrnusSpaceListWidget, AllSpaces), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::NewProp_AllSpaces_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::NewProp_AllSpaces_MetaData)) }; // 25966878
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::NewProp_CurrentDisplayedSpaces_Inner = { "CurrentDisplayedSpaces", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FCavrnusSpaceInfo, METADATA_PARAMS(nullptr, 0) }; // 25966878
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::NewProp_CurrentDisplayedSpaces_MetaData[] = {
		{ "Comment", "/** List of currently displayed spaces based on search and pagination. */" },
		{ "ModuleRelativePath", "Public/UI/CavrnusSpaceListWidget.h" },
		{ "ToolTip", "List of currently displayed spaces based on search and pagination." },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::NewProp_CurrentDisplayedSpaces = { "CurrentDisplayedSpaces", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCavrnusSpaceListWidget, CurrentDisplayedSpaces), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::NewProp_CurrentDisplayedSpaces_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::NewProp_CurrentDisplayedSpaces_MetaData)) }; // 25966878
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::NewProp_PaginationItemWidget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::NewProp_SpacePagination,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::NewProp_SearchTextBox,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::NewProp_ButtonCreateSpace,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::NewProp_OnCavrnusSpaceSelected,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::NewProp_JoinableSpacesBinding,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::NewProp_AllSpaces_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::NewProp_AllSpaces,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::NewProp_CurrentDisplayedSpaces_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::NewProp_CurrentDisplayedSpaces,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCavrnusSpaceListWidget>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::ClassParams = {
		&UCavrnusSpaceListWidget::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::PropPointers),
		0,
		0x00B010A1u,
		METADATA_PARAMS(Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCavrnusSpaceListWidget()
	{
		if (!Z_Registration_Info_UClass_UCavrnusSpaceListWidget.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCavrnusSpaceListWidget.OuterSingleton, Z_Construct_UClass_UCavrnusSpaceListWidget_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UCavrnusSpaceListWidget.OuterSingleton;
	}
	template<> CAVRNUSCONNECTOR_API UClass* StaticClass<UCavrnusSpaceListWidget>()
	{
		return UCavrnusSpaceListWidget::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCavrnusSpaceListWidget);
	struct Z_CompiledInDeferFile_FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_CavrnusSpaceListWidget_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_CavrnusSpaceListWidget_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UCavrnusSpaceListWidget, UCavrnusSpaceListWidget::StaticClass, TEXT("UCavrnusSpaceListWidget"), &Z_Registration_Info_UClass_UCavrnusSpaceListWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCavrnusSpaceListWidget), 1935807608U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_CavrnusSpaceListWidget_h_3708251562(TEXT("/Script/CavrnusConnector"),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_CavrnusSpaceListWidget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_CavrnusSpaceListWidget_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
