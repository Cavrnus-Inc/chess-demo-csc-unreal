// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CavrnusConnector/Public/UI/SpaceList/SpaceListOption.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSpaceListOption() {}
// Cross Module References
	CAVRNUSCONNECTOR_API UClass* Z_Construct_UClass_USpaceListOption_NoRegister();
	CAVRNUSCONNECTOR_API UClass* Z_Construct_UClass_USpaceListOption();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_CavrnusConnector();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2DDynamic_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UImage_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UAsyncTaskDownloadImage_NoRegister();
	CAVRNUSCONNECTOR_API UScriptStruct* Z_Construct_UScriptStruct_FCavrnusSpaceInfo();
// End Cross Module References
	DEFINE_FUNCTION(USpaceListOption::execButtonSpaceSelected)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ButtonSpaceSelected();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USpaceListOption::execOnGetThumbnail)
	{
		P_GET_OBJECT(UTexture2DDynamic,Z_Param_Texture);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnGetThumbnail(Z_Param_Texture);
		P_NATIVE_END;
	}
	void USpaceListOption::StaticRegisterNativesUSpaceListOption()
	{
		UClass* Class = USpaceListOption::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ButtonSpaceSelected", &USpaceListOption::execButtonSpaceSelected },
			{ "OnGetThumbnail", &USpaceListOption::execOnGetThumbnail },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USpaceListOption_ButtonSpaceSelected_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USpaceListOption_ButtonSpaceSelected_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/**\n\x09 * @brief Callback function for when the space selection button is clicked.\n\x09 */" },
		{ "ModuleRelativePath", "Public/UI/SpaceList/SpaceListOption.h" },
		{ "ToolTip", "@brief Callback function for when the space selection button is clicked." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USpaceListOption_ButtonSpaceSelected_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USpaceListOption, nullptr, "ButtonSpaceSelected", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USpaceListOption_ButtonSpaceSelected_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USpaceListOption_ButtonSpaceSelected_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USpaceListOption_ButtonSpaceSelected()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USpaceListOption_ButtonSpaceSelected_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USpaceListOption_OnGetThumbnail_Statics
	{
		struct SpaceListOption_eventOnGetThumbnail_Parms
		{
			UTexture2DDynamic* Texture;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Texture;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USpaceListOption_OnGetThumbnail_Statics::NewProp_Texture = { "Texture", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SpaceListOption_eventOnGetThumbnail_Parms, Texture), Z_Construct_UClass_UTexture2DDynamic_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USpaceListOption_OnGetThumbnail_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USpaceListOption_OnGetThumbnail_Statics::NewProp_Texture,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USpaceListOption_OnGetThumbnail_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/**\n\x09 * @brief Callback function for when the thumbnail image is downloaded.\n\x09 *\n\x09 * @param Texture The downloaded texture.\n\x09 */" },
		{ "ModuleRelativePath", "Public/UI/SpaceList/SpaceListOption.h" },
		{ "ToolTip", "@brief Callback function for when the thumbnail image is downloaded.\n\n@param Texture The downloaded texture." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USpaceListOption_OnGetThumbnail_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USpaceListOption, nullptr, "OnGetThumbnail", nullptr, nullptr, sizeof(Z_Construct_UFunction_USpaceListOption_OnGetThumbnail_Statics::SpaceListOption_eventOnGetThumbnail_Parms), Z_Construct_UFunction_USpaceListOption_OnGetThumbnail_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USpaceListOption_OnGetThumbnail_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USpaceListOption_OnGetThumbnail_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USpaceListOption_OnGetThumbnail_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USpaceListOption_OnGetThumbnail()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USpaceListOption_OnGetThumbnail_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USpaceListOption);
	UClass* Z_Construct_UClass_USpaceListOption_NoRegister()
	{
		return USpaceListOption::StaticClass();
	}
	struct Z_Construct_UClass_USpaceListOption_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ThumbnailDefault_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ThumbnailDefault;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Thumbnail_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Thumbnail;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SpaceNameTextBlock_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SpaceNameTextBlock;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Button_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Button;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DownloadTask_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DownloadTask;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SpaceInfo_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_SpaceInfo;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USpaceListOption_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_CavrnusConnector,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USpaceListOption_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USpaceListOption_ButtonSpaceSelected, "ButtonSpaceSelected" }, // 1327335095
		{ &Z_Construct_UFunction_USpaceListOption_OnGetThumbnail, "OnGetThumbnail" }, // 2148422576
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USpaceListOption_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * @brief A widget class for displaying space options in a list.\n *\n * This class represents an individual entry in a space list, showing details\n * like the space thumbnail and name. It allows users to select a space\n * by clicking a button.\n */" },
		{ "IncludePath", "UI/SpaceList/SpaceListOption.h" },
		{ "ModuleRelativePath", "Public/UI/SpaceList/SpaceListOption.h" },
		{ "ToolTip", "@brief A widget class for displaying space options in a list.\n\nThis class represents an individual entry in a space list, showing details\nlike the space thumbnail and name. It allows users to select a space\nby clicking a button." },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USpaceListOption_Statics::NewProp_ThumbnailDefault_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Cavrnus" },
		{ "Comment", "/** The default thumbnail image displayed before the actual thumbnail is downloaded. */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/SpaceList/SpaceListOption.h" },
		{ "ToolTip", "The default thumbnail image displayed before the actual thumbnail is downloaded." },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USpaceListOption_Statics::NewProp_ThumbnailDefault = { "ThumbnailDefault", nullptr, (EPropertyFlags)0x001000000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USpaceListOption, ThumbnailDefault), Z_Construct_UClass_UImage_NoRegister, METADATA_PARAMS(Z_Construct_UClass_USpaceListOption_Statics::NewProp_ThumbnailDefault_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USpaceListOption_Statics::NewProp_ThumbnailDefault_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USpaceListOption_Statics::NewProp_Thumbnail_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Cavrnus" },
		{ "Comment", "/** The actual thumbnail image of the space. */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/SpaceList/SpaceListOption.h" },
		{ "ToolTip", "The actual thumbnail image of the space." },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USpaceListOption_Statics::NewProp_Thumbnail = { "Thumbnail", nullptr, (EPropertyFlags)0x001000000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USpaceListOption, Thumbnail), Z_Construct_UClass_UImage_NoRegister, METADATA_PARAMS(Z_Construct_UClass_USpaceListOption_Statics::NewProp_Thumbnail_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USpaceListOption_Statics::NewProp_Thumbnail_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USpaceListOption_Statics::NewProp_SpaceNameTextBlock_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Cavrnus" },
		{ "Comment", "/** The text block displaying the name of the space. */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/SpaceList/SpaceListOption.h" },
		{ "ToolTip", "The text block displaying the name of the space." },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USpaceListOption_Statics::NewProp_SpaceNameTextBlock = { "SpaceNameTextBlock", nullptr, (EPropertyFlags)0x001000000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USpaceListOption, SpaceNameTextBlock), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(Z_Construct_UClass_USpaceListOption_Statics::NewProp_SpaceNameTextBlock_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USpaceListOption_Statics::NewProp_SpaceNameTextBlock_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USpaceListOption_Statics::NewProp_Button_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Cavrnus" },
		{ "Comment", "/** The button used to select the space. */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/SpaceList/SpaceListOption.h" },
		{ "ToolTip", "The button used to select the space." },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USpaceListOption_Statics::NewProp_Button = { "Button", nullptr, (EPropertyFlags)0x001000000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USpaceListOption, Button), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(Z_Construct_UClass_USpaceListOption_Statics::NewProp_Button_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USpaceListOption_Statics::NewProp_Button_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USpaceListOption_Statics::NewProp_DownloadTask_MetaData[] = {
		{ "Comment", "/** The async task responsible for downloading the thumbnail image. */" },
		{ "ModuleRelativePath", "Public/UI/SpaceList/SpaceListOption.h" },
		{ "ToolTip", "The async task responsible for downloading the thumbnail image." },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USpaceListOption_Statics::NewProp_DownloadTask = { "DownloadTask", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USpaceListOption, DownloadTask), Z_Construct_UClass_UAsyncTaskDownloadImage_NoRegister, METADATA_PARAMS(Z_Construct_UClass_USpaceListOption_Statics::NewProp_DownloadTask_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USpaceListOption_Statics::NewProp_DownloadTask_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USpaceListOption_Statics::NewProp_SpaceInfo_MetaData[] = {
		{ "Comment", "/** Information about the space. */" },
		{ "ModuleRelativePath", "Public/UI/SpaceList/SpaceListOption.h" },
		{ "ToolTip", "Information about the space." },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USpaceListOption_Statics::NewProp_SpaceInfo = { "SpaceInfo", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USpaceListOption, SpaceInfo), Z_Construct_UScriptStruct_FCavrnusSpaceInfo, METADATA_PARAMS(Z_Construct_UClass_USpaceListOption_Statics::NewProp_SpaceInfo_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USpaceListOption_Statics::NewProp_SpaceInfo_MetaData)) }; // 25966878
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USpaceListOption_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USpaceListOption_Statics::NewProp_ThumbnailDefault,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USpaceListOption_Statics::NewProp_Thumbnail,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USpaceListOption_Statics::NewProp_SpaceNameTextBlock,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USpaceListOption_Statics::NewProp_Button,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USpaceListOption_Statics::NewProp_DownloadTask,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USpaceListOption_Statics::NewProp_SpaceInfo,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USpaceListOption_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USpaceListOption>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USpaceListOption_Statics::ClassParams = {
		&USpaceListOption::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_USpaceListOption_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_USpaceListOption_Statics::PropPointers),
		0,
		0x00B010A1u,
		METADATA_PARAMS(Z_Construct_UClass_USpaceListOption_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USpaceListOption_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USpaceListOption()
	{
		if (!Z_Registration_Info_UClass_USpaceListOption.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USpaceListOption.OuterSingleton, Z_Construct_UClass_USpaceListOption_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USpaceListOption.OuterSingleton;
	}
	template<> CAVRNUSCONNECTOR_API UClass* StaticClass<USpaceListOption>()
	{
		return USpaceListOption::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USpaceListOption);
	struct Z_CompiledInDeferFile_FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_SpaceList_SpaceListOption_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_SpaceList_SpaceListOption_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USpaceListOption, USpaceListOption::StaticClass, TEXT("USpaceListOption"), &Z_Registration_Info_UClass_USpaceListOption, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USpaceListOption), 39845868U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_SpaceList_SpaceListOption_h_598661820(TEXT("/Script/CavrnusConnector"),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_SpaceList_SpaceListOption_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_SpaceList_SpaceListOption_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
