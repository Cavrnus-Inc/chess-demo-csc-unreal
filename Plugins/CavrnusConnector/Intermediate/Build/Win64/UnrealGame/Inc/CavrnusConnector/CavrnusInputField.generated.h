// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CAVRNUSCONNECTOR_CavrnusInputField_generated_h
#error "CavrnusInputField.generated.h already included, missing '#pragma once' in CavrnusInputField.h"
#endif
#define CAVRNUSCONNECTOR_CavrnusInputField_generated_h

#define FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_Components_CavrnusInputField_h_13_DELEGATE \
struct _Script_CavrnusConnector_eventOnInputUpdated_Parms \
{ \
	FString InputText; \
}; \
static inline void FOnInputUpdated_DelegateWrapper(const FMulticastScriptDelegate& OnInputUpdated, const FString& InputText) \
{ \
	_Script_CavrnusConnector_eventOnInputUpdated_Parms Parms; \
	Parms.InputText=InputText; \
	OnInputUpdated.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_Components_CavrnusInputField_h_14_DELEGATE \
struct _Script_CavrnusConnector_eventOnInputCommitted_Parms \
{ \
	FString InputText; \
	TEnumAsByte<ETextCommit::Type> CommitMethod; \
}; \
static inline void FOnInputCommitted_DelegateWrapper(const FMulticastScriptDelegate& OnInputCommitted, const FString& InputText, ETextCommit::Type CommitMethod) \
{ \
	_Script_CavrnusConnector_eventOnInputCommitted_Parms Parms; \
	Parms.InputText=InputText; \
	Parms.CommitMethod=CommitMethod; \
	OnInputCommitted.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_Components_CavrnusInputField_h_19_SPARSE_DATA
#define FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_Components_CavrnusInputField_h_19_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execFieldCommitted); \
	DECLARE_FUNCTION(execFieldUpdated);


#define FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_Components_CavrnusInputField_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execFieldCommitted); \
	DECLARE_FUNCTION(execFieldUpdated);


#define FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_Components_CavrnusInputField_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCavrnusInputField(); \
	friend struct Z_Construct_UClass_UCavrnusInputField_Statics; \
public: \
	DECLARE_CLASS(UCavrnusInputField, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CavrnusConnector"), NO_API) \
	DECLARE_SERIALIZER(UCavrnusInputField)


#define FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_Components_CavrnusInputField_h_19_INCLASS \
private: \
	static void StaticRegisterNativesUCavrnusInputField(); \
	friend struct Z_Construct_UClass_UCavrnusInputField_Statics; \
public: \
	DECLARE_CLASS(UCavrnusInputField, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CavrnusConnector"), NO_API) \
	DECLARE_SERIALIZER(UCavrnusInputField)


#define FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_Components_CavrnusInputField_h_19_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCavrnusInputField(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCavrnusInputField) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCavrnusInputField); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCavrnusInputField); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCavrnusInputField(UCavrnusInputField&&); \
	NO_API UCavrnusInputField(const UCavrnusInputField&); \
public:


#define FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_Components_CavrnusInputField_h_19_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCavrnusInputField(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCavrnusInputField(UCavrnusInputField&&); \
	NO_API UCavrnusInputField(const UCavrnusInputField&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCavrnusInputField); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCavrnusInputField); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCavrnusInputField)


#define FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_Components_CavrnusInputField_h_16_PROLOG
#define FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_Components_CavrnusInputField_h_19_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_Components_CavrnusInputField_h_19_SPARSE_DATA \
	FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_Components_CavrnusInputField_h_19_RPC_WRAPPERS \
	FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_Components_CavrnusInputField_h_19_INCLASS \
	FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_Components_CavrnusInputField_h_19_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_Components_CavrnusInputField_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_Components_CavrnusInputField_h_19_SPARSE_DATA \
	FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_Components_CavrnusInputField_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_Components_CavrnusInputField_h_19_INCLASS_NO_PURE_DECLS \
	FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_Components_CavrnusInputField_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CAVRNUSCONNECTOR_API UClass* StaticClass<class UCavrnusInputField>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_CavrnusConnector_Source_CavrnusConnector_Public_UI_Components_CavrnusInputField_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
