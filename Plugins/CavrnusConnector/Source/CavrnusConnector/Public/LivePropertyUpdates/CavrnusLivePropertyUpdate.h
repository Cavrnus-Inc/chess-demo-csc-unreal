// Copyright(c) Cavrnus. All rights reserved.
/**
 * @file CavrnusLivePropertyUpdate.h
 * @brief This file defines the UCavrnusLivePropertyUpdate class used for handling live property updates in Cavrnus.
 *
 * The UCavrnusLivePropertyUpdate class provides functionality for managing temporary and transient property updates
 * in the Cavrnus system. It offers methods to cancel updates and track the last update time.
 */
#pragma once

#include "CoreMinimal.h"
#include "Types/CavrnusSpaceConnection.h"
#include "Types/PropertyId.h"

#include "CavrnusLivePropertyUpdate.generated.h"		// Always last

struct FPropertyId;

namespace Cavrnus
{
	class CavrnusVirtualPropertyUpdate;
}

/**
 * @brief UCavrnusLivePropertyUpdate class for managing live property updates in Cavrnus.
 *
 * This abstract class serves as a base for specific property update classes, providing common functionality such as
 * canceling updates and tracking the last updated time.
 */
UCLASS(Abstract, BlueprintType)
class CAVRNUSCONNECTOR_API UCavrnusLivePropertyUpdate : public UObject
{
	GENERATED_BODY()

public:
	// Default Constructor
	UCavrnusLivePropertyUpdate();

	// Destructor
	virtual ~UCavrnusLivePropertyUpdate();

	/**
	 * @brief Cancels transient operations sent to the server.
	 *
	 * This method cancels any temporary or transient property updates that have been sent to the server.
	 */
	UFUNCTION(BlueprintCallable, CallInEditor, Exec, Category = "Cavrnus|Properties",
		meta = (ToolTip = "Cancels transient operations sent to the server.", ShortToolTip = "Cancels transient operations sent to the server"))
	void Cancel();

	/**
	 * @brief Gets the last updated time in seconds.
	 *
	 * This method returns the time in seconds since the last property update was made.
	 *
	 * @return The time in seconds since the last update.
	 */
	double GetLastUpdatedTimeSeconds();

protected:

	/** Pointer to the live property update instance */
	Cavrnus::CavrnusVirtualPropertyUpdate* livePropertyUpdate = nullptr;
};