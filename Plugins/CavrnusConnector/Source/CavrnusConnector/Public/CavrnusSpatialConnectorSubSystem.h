#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"

#include "Types/CavrnusAuthentication.h"
#include "Types/CavrnusSpawnedObject.h"
#include "Types/CavrnusCallbackTypes.h"

#include "CavrnusSpatialConnectorSubSystem.generated.h"

class ACavrnusSpatialConnector;
class AController;
class APawn;
class USpawnedObjectsManager;
class UCavrnusAvatarManager;
class UPDFManager;

// Class definition
UCLASS(BlueprintType, Blueprintable)
class CAVRNUSCONNECTOR_API UCavrnusSpatialConnectorSubSystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	// Constructor
	UCavrnusSpatialConnectorSubSystem();

	// Destructor
	~UCavrnusSpatialConnectorSubSystem();

	virtual void Initialize(FSubsystemCollectionBase& Collection);
	virtual void Deinitialize();

	void RegisterCavrnusSpatialConnector(ACavrnusSpatialConnector* CavrnusSpatialConnector);

	UFUNCTION(BlueprintCallable, Category = "Cavrnus")
	ACavrnusSpatialConnector* GetCavrnusSpatialConnector() const;

	void AuthenticateAndJoin();
	void AttemptToJoinSpace(FString JoinSpaceId);

	UFUNCTION()
	void OnAuthSuccess(FCavrnusAuthentication Authentication);

	UFUNCTION()
	void OnAuthFailure(FString Error);

	UFUNCTION()
	void OnSpaceConnectionSuccess(FCavrnusSpaceConnection SpaceConnection);

	UFUNCTION()
	void OnSpaceConnectionFailure(FString Error);

	void SpawnCavrnusActor(const FCavrnusSpawnedObject& SpawnedObject);
	FCavrnusSpawnedObject GetSpawnedObject(AActor* Actor);

	void DestroyCavrnusActor(const FCavrnusSpawnedObject& SpawnedObject);

	UFUNCTION(BlueprintCallable, Category = "Cavrnus")
	UCavrnusAvatarManager* GetAvatarManager();

	UFUNCTION(BlueprintCallable, Category = "Cavrnus")
	USpawnedObjectsManager* GetSpawnedObjectsManager();

	UFUNCTION(BlueprintCallable, Category = "Cavrnus")
	UPDFManager* GetPDFManager();
protected:
	void ShowGuestLoginWidget();

	void ShowLoginWidget();

private:
	TWeakObjectPtr<ACavrnusSpatialConnector> CurrentCavrnusSpatialConnector;

	FCavrnusAuthRecv AuthSuccess;
	FCavrnusError AuthFailure;
	FCavrnusSpaceConnected SpaceConnectionSuccess;
	FCavrnusError SpaceConnectionFailure;

	UPROPERTY()
	FCavrnusAuthentication Authentication;

	UPROPERTY()
	bool bHasSpaceConnection = false;

	UPROPERTY()
	USpawnedObjectsManager* SpawnedObjectsManager;

	UPROPERTY()
	UCavrnusAvatarManager* AvatarManager;

	UPROPERTY()
	UPDFManager* PDFManager;

	UPROPERTY()
	UUserWidget* LoadingWidget;

	UFUNCTION()
	UUserWidget* SpawnWidget(TSubclassOf<UUserWidget> WidgetClass);

	UFUNCTION()
	void OnPawnControllerChanged(APawn* InPawn, AController* InController);

	UFUNCTION()
	void OnPossessedPawnChanged(APawn* OldPawn, APawn* NewPawn);

	UFUNCTION()
	void AttachLocalUserComponentToPawn();
};