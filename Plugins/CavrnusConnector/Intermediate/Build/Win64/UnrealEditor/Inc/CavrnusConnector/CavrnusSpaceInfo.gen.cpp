// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CavrnusConnector/Public/Types/CavrnusSpaceInfo.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCavrnusSpaceInfo() {}
// Cross Module References
	CAVRNUSCONNECTOR_API UScriptStruct* Z_Construct_UScriptStruct_FCavrnusSpaceInfo();
	UPackage* Z_Construct_UPackage__Script_CavrnusConnector();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_CavrnusSpaceInfo;
class UScriptStruct* FCavrnusSpaceInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_CavrnusSpaceInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_CavrnusSpaceInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FCavrnusSpaceInfo, Z_Construct_UPackage__Script_CavrnusConnector(), TEXT("CavrnusSpaceInfo"));
	}
	return Z_Registration_Info_UScriptStruct_CavrnusSpaceInfo.OuterSingleton;
}
template<> CAVRNUSCONNECTOR_API UScriptStruct* StaticStruct<FCavrnusSpaceInfo>()
{
	return FCavrnusSpaceInfo::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FCavrnusSpaceInfo_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SpaceId_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_SpaceId;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SpaceName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_SpaceName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SpaceThumbnail_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_SpaceThumbnail;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCavrnusSpaceInfo_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n *\n */" },
		{ "ModuleRelativePath", "Public/Types/CavrnusSpaceInfo.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FCavrnusSpaceInfo_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCavrnusSpaceInfo>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCavrnusSpaceInfo_Statics::NewProp_SpaceId_MetaData[] = {
		{ "Category", "Cavrnus|Spaces" },
		{ "ModuleRelativePath", "Public/Types/CavrnusSpaceInfo.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FCavrnusSpaceInfo_Statics::NewProp_SpaceId = { "SpaceId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCavrnusSpaceInfo, SpaceId), METADATA_PARAMS(Z_Construct_UScriptStruct_FCavrnusSpaceInfo_Statics::NewProp_SpaceId_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCavrnusSpaceInfo_Statics::NewProp_SpaceId_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCavrnusSpaceInfo_Statics::NewProp_SpaceName_MetaData[] = {
		{ "Category", "Cavrnus|Spaces" },
		{ "ModuleRelativePath", "Public/Types/CavrnusSpaceInfo.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FCavrnusSpaceInfo_Statics::NewProp_SpaceName = { "SpaceName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCavrnusSpaceInfo, SpaceName), METADATA_PARAMS(Z_Construct_UScriptStruct_FCavrnusSpaceInfo_Statics::NewProp_SpaceName_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCavrnusSpaceInfo_Statics::NewProp_SpaceName_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCavrnusSpaceInfo_Statics::NewProp_SpaceThumbnail_MetaData[] = {
		{ "Category", "Cavrnus|Spaces" },
		{ "ModuleRelativePath", "Public/Types/CavrnusSpaceInfo.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FCavrnusSpaceInfo_Statics::NewProp_SpaceThumbnail = { "SpaceThumbnail", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCavrnusSpaceInfo, SpaceThumbnail), METADATA_PARAMS(Z_Construct_UScriptStruct_FCavrnusSpaceInfo_Statics::NewProp_SpaceThumbnail_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCavrnusSpaceInfo_Statics::NewProp_SpaceThumbnail_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCavrnusSpaceInfo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCavrnusSpaceInfo_Statics::NewProp_SpaceId,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCavrnusSpaceInfo_Statics::NewProp_SpaceName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCavrnusSpaceInfo_Statics::NewProp_SpaceThumbnail,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCavrnusSpaceInfo_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_CavrnusConnector,
		nullptr,
		&NewStructOps,
		"CavrnusSpaceInfo",
		sizeof(FCavrnusSpaceInfo),
		alignof(FCavrnusSpaceInfo),
		Z_Construct_UScriptStruct_FCavrnusSpaceInfo_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCavrnusSpaceInfo_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FCavrnusSpaceInfo_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCavrnusSpaceInfo_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FCavrnusSpaceInfo()
	{
		if (!Z_Registration_Info_UScriptStruct_CavrnusSpaceInfo.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_CavrnusSpaceInfo.InnerSingleton, Z_Construct_UScriptStruct_FCavrnusSpaceInfo_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_CavrnusSpaceInfo.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_Types_CavrnusSpaceInfo_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_Types_CavrnusSpaceInfo_h_Statics::ScriptStructInfo[] = {
		{ FCavrnusSpaceInfo::StaticStruct, Z_Construct_UScriptStruct_FCavrnusSpaceInfo_Statics::NewStructOps, TEXT("CavrnusSpaceInfo"), &Z_Registration_Info_UScriptStruct_CavrnusSpaceInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FCavrnusSpaceInfo), 3347490996U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_Types_CavrnusSpaceInfo_h_3500496969(TEXT("/Script/CavrnusConnector"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_Types_CavrnusSpaceInfo_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_Types_CavrnusSpaceInfo_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS