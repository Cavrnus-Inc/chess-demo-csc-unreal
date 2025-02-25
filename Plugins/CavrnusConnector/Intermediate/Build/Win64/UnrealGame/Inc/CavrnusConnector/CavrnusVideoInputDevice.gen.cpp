// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CavrnusConnector/Public/Types/CavrnusVideoInputDevice.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCavrnusVideoInputDevice() {}
// Cross Module References
	CAVRNUSCONNECTOR_API UScriptStruct* Z_Construct_UScriptStruct_FCavrnusVideoInputDevice();
	UPackage* Z_Construct_UPackage__Script_CavrnusConnector();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_CavrnusVideoInputDevice;
class UScriptStruct* FCavrnusVideoInputDevice::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_CavrnusVideoInputDevice.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_CavrnusVideoInputDevice.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FCavrnusVideoInputDevice, Z_Construct_UPackage__Script_CavrnusConnector(), TEXT("CavrnusVideoInputDevice"));
	}
	return Z_Registration_Info_UScriptStruct_CavrnusVideoInputDevice.OuterSingleton;
}
template<> CAVRNUSCONNECTOR_API UScriptStruct* StaticStruct<FCavrnusVideoInputDevice>()
{
	return FCavrnusVideoInputDevice::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FCavrnusVideoInputDevice_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DeviceName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_DeviceName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DeviceId_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_DeviceId;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCavrnusVideoInputDevice_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n  * @brief Structure to hold information about a video input device.\n  *\n  * The FCavrnusVideoInputDevice structure contains the device name and device ID for a video input device.\n  * This information is used to allow users to select from available video input devices.\n  */" },
		{ "ModuleRelativePath", "Public/Types/CavrnusVideoInputDevice.h" },
		{ "ToolTip", "@brief Structure to hold information about a video input device.\n\nThe FCavrnusVideoInputDevice structure contains the device name and device ID for a video input device.\nThis information is used to allow users to select from available video input devices." },
	};
#endif
	void* Z_Construct_UScriptStruct_FCavrnusVideoInputDevice_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCavrnusVideoInputDevice>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCavrnusVideoInputDevice_Statics::NewProp_DeviceName_MetaData[] = {
		{ "Category", "Cavrnus|Input" },
		{ "Comment", "/** The name of the video input device, useful for displaying in a UI selector. */" },
		{ "ModuleRelativePath", "Public/Types/CavrnusVideoInputDevice.h" },
		{ "ToolTip", "The name of the video input device, useful for displaying in a UI selector." },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FCavrnusVideoInputDevice_Statics::NewProp_DeviceName = { "DeviceName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCavrnusVideoInputDevice, DeviceName), METADATA_PARAMS(Z_Construct_UScriptStruct_FCavrnusVideoInputDevice_Statics::NewProp_DeviceName_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCavrnusVideoInputDevice_Statics::NewProp_DeviceName_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCavrnusVideoInputDevice_Statics::NewProp_DeviceId_MetaData[] = {
		{ "Category", "Cavrnus|Input" },
		{ "Comment", "/** The unique ID of the video input device. */" },
		{ "ModuleRelativePath", "Public/Types/CavrnusVideoInputDevice.h" },
		{ "ToolTip", "The unique ID of the video input device." },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FCavrnusVideoInputDevice_Statics::NewProp_DeviceId = { "DeviceId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCavrnusVideoInputDevice, DeviceId), METADATA_PARAMS(Z_Construct_UScriptStruct_FCavrnusVideoInputDevice_Statics::NewProp_DeviceId_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCavrnusVideoInputDevice_Statics::NewProp_DeviceId_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCavrnusVideoInputDevice_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCavrnusVideoInputDevice_Statics::NewProp_DeviceName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCavrnusVideoInputDevice_Statics::NewProp_DeviceId,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCavrnusVideoInputDevice_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_CavrnusConnector,
		nullptr,
		&NewStructOps,
		"CavrnusVideoInputDevice",
		sizeof(FCavrnusVideoInputDevice),
		alignof(FCavrnusVideoInputDevice),
		Z_Construct_UScriptStruct_FCavrnusVideoInputDevice_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCavrnusVideoInputDevice_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FCavrnusVideoInputDevice_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCavrnusVideoInputDevice_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FCavrnusVideoInputDevice()
	{
		if (!Z_Registration_Info_UScriptStruct_CavrnusVideoInputDevice.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_CavrnusVideoInputDevice.InnerSingleton, Z_Construct_UScriptStruct_FCavrnusVideoInputDevice_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_CavrnusVideoInputDevice.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_Types_CavrnusVideoInputDevice_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_Types_CavrnusVideoInputDevice_h_Statics::ScriptStructInfo[] = {
		{ FCavrnusVideoInputDevice::StaticStruct, Z_Construct_UScriptStruct_FCavrnusVideoInputDevice_Statics::NewStructOps, TEXT("CavrnusVideoInputDevice"), &Z_Registration_Info_UScriptStruct_CavrnusVideoInputDevice, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FCavrnusVideoInputDevice), 307921762U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_Types_CavrnusVideoInputDevice_h_2079624593(TEXT("/Script/CavrnusConnector"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_Types_CavrnusVideoInputDevice_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_Types_CavrnusVideoInputDevice_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
