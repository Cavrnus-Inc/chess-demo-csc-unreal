#pragma once
#include "CoreMinimal.h"
#include "CavrnusFunctionLibrary.h"
#include <Components/SceneComponent.h>
#include <Materials/MaterialInstanceDynamic.h>
#include "CavrnusLocalUserFlag.generated.h"

// Class definition
UCLASS(BlueprintType, Blueprintable)
class CAVRNUSCONNECTOR_API UCavrnusLocalUserFlag : public USceneComponent
{
	GENERATED_BODY()

public:
	// Constructor
	UCavrnusLocalUserFlag(){}

	// Destructor
	~UCavrnusLocalUserFlag(){}

	UPROPERTY(BlueprintReadWrite, Category = "Cavrnus")
	FCavrnusUser LocalUser = FCavrnusUser();
};