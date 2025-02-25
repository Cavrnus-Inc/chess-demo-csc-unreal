// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FCavrnusSpaceInfo;
#ifdef CAVRNUSCONNECTOR_CavrnusSpaceListWidget_generated_h
#error "CavrnusSpaceListWidget.generated.h already included, missing '#pragma once' in CavrnusSpaceListWidget.h"
#endif
#define CAVRNUSCONNECTOR_CavrnusSpaceListWidget_generated_h

#define FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_CavrnusSpaceListWidget_h_18_DELEGATE \
struct _Script_CavrnusConnector_eventOnCavrnusSpaceSelected_Parms \
{ \
	FCavrnusSpaceInfo SpaceInfo; \
}; \
static inline void FOnCavrnusSpaceSelected_DelegateWrapper(const FMulticastScriptDelegate& OnCavrnusSpaceSelected, FCavrnusSpaceInfo SpaceInfo) \
{ \
	_Script_CavrnusConnector_eventOnCavrnusSpaceSelected_Parms Parms; \
	Parms.SpaceInfo=SpaceInfo; \
	OnCavrnusSpaceSelected.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_CavrnusSpaceListWidget_h_33_SPARSE_DATA
#define FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_CavrnusSpaceListWidget_h_33_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execBlueprintSelectedSpaceToJoin); \
	DECLARE_FUNCTION(execSearch);


#define FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_CavrnusSpaceListWidget_h_33_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execBlueprintSelectedSpaceToJoin); \
	DECLARE_FUNCTION(execSearch);


#define FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_CavrnusSpaceListWidget_h_33_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCavrnusSpaceListWidget(); \
	friend struct Z_Construct_UClass_UCavrnusSpaceListWidget_Statics; \
public: \
	DECLARE_CLASS(UCavrnusSpaceListWidget, UCavrnusBaseUserWidget, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/CavrnusConnector"), NO_API) \
	DECLARE_SERIALIZER(UCavrnusSpaceListWidget)


#define FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_CavrnusSpaceListWidget_h_33_INCLASS \
private: \
	static void StaticRegisterNativesUCavrnusSpaceListWidget(); \
	friend struct Z_Construct_UClass_UCavrnusSpaceListWidget_Statics; \
public: \
	DECLARE_CLASS(UCavrnusSpaceListWidget, UCavrnusBaseUserWidget, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/CavrnusConnector"), NO_API) \
	DECLARE_SERIALIZER(UCavrnusSpaceListWidget)


#define FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_CavrnusSpaceListWidget_h_33_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCavrnusSpaceListWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCavrnusSpaceListWidget) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCavrnusSpaceListWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCavrnusSpaceListWidget); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCavrnusSpaceListWidget(UCavrnusSpaceListWidget&&); \
	NO_API UCavrnusSpaceListWidget(const UCavrnusSpaceListWidget&); \
public:


#define FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_CavrnusSpaceListWidget_h_33_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCavrnusSpaceListWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCavrnusSpaceListWidget(UCavrnusSpaceListWidget&&); \
	NO_API UCavrnusSpaceListWidget(const UCavrnusSpaceListWidget&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCavrnusSpaceListWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCavrnusSpaceListWidget); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCavrnusSpaceListWidget)


#define FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_CavrnusSpaceListWidget_h_30_PROLOG
#define FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_CavrnusSpaceListWidget_h_33_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_CavrnusSpaceListWidget_h_33_SPARSE_DATA \
	FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_CavrnusSpaceListWidget_h_33_RPC_WRAPPERS \
	FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_CavrnusSpaceListWidget_h_33_INCLASS \
	FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_CavrnusSpaceListWidget_h_33_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_CavrnusSpaceListWidget_h_33_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_CavrnusSpaceListWidget_h_33_SPARSE_DATA \
	FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_CavrnusSpaceListWidget_h_33_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_CavrnusSpaceListWidget_h_33_INCLASS_NO_PURE_DECLS \
	FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_CavrnusSpaceListWidget_h_33_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CAVRNUSCONNECTOR_API UClass* StaticClass<class UCavrnusSpaceListWidget>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_CavrnusSpaceListWidget_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
