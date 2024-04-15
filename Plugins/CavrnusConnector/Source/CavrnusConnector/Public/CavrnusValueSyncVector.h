#pragma once
#include "CoreMinimal.h"
#include "CavrnusValueSyncBase.h"
#include "CavrnusFunctionLibrary.h"
#include "Types\CavrnusCallbackTypes.h"
#include <Components/ActorComponent.h>
#include "CavrnusValueSyncVector.generated.h"

// Class definition
UCLASS(BlueprintType, Blueprintable)
class CAVRNUSCONNECTOR_API UCavrnusValueSyncVector : public UCavrnusValueSyncBase
{
	GENERATED_BODY()

public:
	// Constructor
	UCavrnusValueSyncVector();

	// Destructor
	~UCavrnusValueSyncVector();

	virtual void BeginPlay();
	virtual void EndPlay(EEndPlayReason::Type Reason);

	UFUNCTION(BlueprintImplementableEvent)
	FVector GetVector();

	UFUNCTION(BlueprintImplementableEvent)
	void SetVector(FVector PropertyValue);

	UFUNCTION()
	void VectorPropertyUpdated(FVector PropertyValue);

	UFUNCTION(BlueprintCallable, Category = "Cavrnus")
	void SetMaterialDoubleVectorParameterValue(UMaterialInstanceDynamic* Material, const FVector& Value);

	void PostVectorToServerTransiently();

	// --------------------- IPropertySyncInterface implementation ---------------------------------------

	void DefineDefaultPropertyValue();

	FCavrnusBinding BindPropertyValue();

	void SendPropertyChanges();

	// ----------------------------------------------------------------------------------------------------

protected:

	FCavrnusSpaceConnected OnSpaceConnected;
	FVectorPropertyUpdated OnVectorPropertyUpdated;
	FVector lastPostedTransientValue;
};