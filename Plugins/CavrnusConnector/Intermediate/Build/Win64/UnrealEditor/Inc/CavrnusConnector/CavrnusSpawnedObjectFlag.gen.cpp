// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CavrnusConnector/Public/FlagComponents/CavrnusSpawnedObjectFlag.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCavrnusSpawnedObjectFlag() {}
// Cross Module References
	CAVRNUSCONNECTOR_API UClass* Z_Construct_UClass_UCavrnusSpawnedObjectFlag_NoRegister();
	CAVRNUSCONNECTOR_API UClass* Z_Construct_UClass_UCavrnusSpawnedObjectFlag();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent();
	UPackage* Z_Construct_UPackage__Script_CavrnusConnector();
	CAVRNUSCONNECTOR_API UScriptStruct* Z_Construct_UScriptStruct_FCavrnusSpawnedObject();
// End Cross Module References
	void UCavrnusSpawnedObjectFlag::StaticRegisterNativesUCavrnusSpawnedObjectFlag()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCavrnusSpawnedObjectFlag);
	UClass* Z_Construct_UClass_UCavrnusSpawnedObjectFlag_NoRegister()
	{
		return UCavrnusSpawnedObjectFlag::StaticClass();
	}
	struct Z_Construct_UClass_UCavrnusSpawnedObjectFlag_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SpawnedObject_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_SpawnedObject;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCavrnusSpawnedObjectFlag_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USceneComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_CavrnusConnector,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCavrnusSpawnedObjectFlag_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "// Class definition\n" },
		{ "HideCategories", "Trigger PhysicsVolume" },
		{ "IncludePath", "FlagComponents/CavrnusSpawnedObjectFlag.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/FlagComponents/CavrnusSpawnedObjectFlag.h" },
		{ "ToolTip", "Class definition" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCavrnusSpawnedObjectFlag_Statics::NewProp_SpawnedObject_MetaData[] = {
		{ "Category", "Cavrnus" },
		{ "Comment", "/** The spawned object referenced by the component. */" },
		{ "ModuleRelativePath", "Public/FlagComponents/CavrnusSpawnedObjectFlag.h" },
		{ "ToolTip", "The spawned object referenced by the component." },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCavrnusSpawnedObjectFlag_Statics::NewProp_SpawnedObject = { "SpawnedObject", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCavrnusSpawnedObjectFlag, SpawnedObject), Z_Construct_UScriptStruct_FCavrnusSpawnedObject, METADATA_PARAMS(Z_Construct_UClass_UCavrnusSpawnedObjectFlag_Statics::NewProp_SpawnedObject_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCavrnusSpawnedObjectFlag_Statics::NewProp_SpawnedObject_MetaData)) }; // 2817399961
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCavrnusSpawnedObjectFlag_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCavrnusSpawnedObjectFlag_Statics::NewProp_SpawnedObject,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCavrnusSpawnedObjectFlag_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCavrnusSpawnedObjectFlag>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UCavrnusSpawnedObjectFlag_Statics::ClassParams = {
		&UCavrnusSpawnedObjectFlag::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UCavrnusSpawnedObjectFlag_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UCavrnusSpawnedObjectFlag_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UCavrnusSpawnedObjectFlag_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCavrnusSpawnedObjectFlag_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCavrnusSpawnedObjectFlag()
	{
		if (!Z_Registration_Info_UClass_UCavrnusSpawnedObjectFlag.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCavrnusSpawnedObjectFlag.OuterSingleton, Z_Construct_UClass_UCavrnusSpawnedObjectFlag_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UCavrnusSpawnedObjectFlag.OuterSingleton;
	}
	template<> CAVRNUSCONNECTOR_API UClass* StaticClass<UCavrnusSpawnedObjectFlag>()
	{
		return UCavrnusSpawnedObjectFlag::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCavrnusSpawnedObjectFlag);
	struct Z_CompiledInDeferFile_FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_FlagComponents_CavrnusSpawnedObjectFlag_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_FlagComponents_CavrnusSpawnedObjectFlag_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UCavrnusSpawnedObjectFlag, UCavrnusSpawnedObjectFlag::StaticClass, TEXT("UCavrnusSpawnedObjectFlag"), &Z_Registration_Info_UClass_UCavrnusSpawnedObjectFlag, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCavrnusSpawnedObjectFlag), 4229183749U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_FlagComponents_CavrnusSpawnedObjectFlag_h_751185230(TEXT("/Script/CavrnusConnector"),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_FlagComponents_CavrnusSpawnedObjectFlag_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_FlagComponents_CavrnusSpawnedObjectFlag_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
