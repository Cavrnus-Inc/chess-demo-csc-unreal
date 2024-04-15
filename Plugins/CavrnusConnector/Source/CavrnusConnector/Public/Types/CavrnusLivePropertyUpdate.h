#pragma once

#include "CoreMinimal.h"
#include "CavrnusSpaceConnection.h"
#include "RelayModel/CavrnusRelayModel.h"

// Always last
#include "CavrnusLivePropertyUpdate.generated.h"
/**
 *
 */


UCLASS(Abstract, BlueprintType)
class CAVRNUSCONNECTOR_API UCavrnusLivePropertyUpdate : public UObject
{
	GENERATED_BODY()

public:
	// Constructor
	UCavrnusLivePropertyUpdate();

	// Destructor
	~UCavrnusLivePropertyUpdate();

	void Initialize(Cavrnus::CavrnusRelayModel* relayModel, FCavrnusSpaceConnection spaceConn, const FString& propertyId);

	UFUNCTION(BlueprintCallable, CallInEditor, Exec, Category = "Cavrnus|Properties",
		meta = (ToolTip = "Cancels transient operations sent to the server.", ShortToolTip = "Cancels transient operations sent to the server"))
	void Cancel();

protected:
	FCavrnusSpaceConnection SpaceConn;

	FString LiveUpdaterId;

	FString PropertyId;

	Cavrnus::CavrnusRelayModel* RelayModel;
};