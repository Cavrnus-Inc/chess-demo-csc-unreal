#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CavrnusValueSyncBase.h"
#include <CavrnusFunctionLibrary.h>
#include "Types\CavrnusCallbackTypes.h"

#include "CavrnusValueSyncColor.generated.h"

// Class definition
UCLASS(BlueprintType, Blueprintable)
class CAVRNUSCONNECTOR_API UCavrnusValueSyncColor : public UCavrnusValueSyncBase
{
	GENERATED_BODY()

public:
	// Constructor
	UCavrnusValueSyncColor();

	// Destructor
	~UCavrnusValueSyncColor();

	virtual void BeginPlay();
	virtual void EndPlay(EEndPlayReason::Type Reason);

	UFUNCTION(BlueprintImplementableEvent)
	FLinearColor GetColor();

	UFUNCTION(BlueprintImplementableEvent)
	void SetColor(FLinearColor PropertyValue);

	UFUNCTION()
	void ColorPropertyUpdated(FLinearColor PropertyValue);

	void PostColorToServerTransiently();

	// --------------------- IPropertySyncInterface implementation ---------------------------------------

	void DefineDefaultPropertyValue();

	FCavrnusBinding BindPropertyValue();

	void SendPropertyChanges();

	// ----------------------------------------------------------------------------------------------------

protected:

	FCavrnusSpaceConnected OnSpaceConnected;
	FColorPropertyUpdated OnColorPropertyUpdated;

	FLinearColor lastPostedTransientValue;
};