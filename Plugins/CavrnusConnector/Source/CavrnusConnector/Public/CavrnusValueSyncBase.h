#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Interfaces/IPropertySyncInterface.h"
#include "Types/CavrnusBinding.h"
#include "Types/CavrnusSpaceConnection.h"

#include "CavrnusValueSyncBase.generated.h"

class UCavrnusPropertiesContainer;
class UCavrnusLivePropertyUpdate;

// Class definition
UCLASS(BlueprintType, abstract)
class CAVRNUSCONNECTOR_API UCavrnusValueSyncBase : public USceneComponent, public IPropertySyncInterface
{
	GENERATED_BODY()

public:
	// Constructor
	UCavrnusValueSyncBase();

	// Destructor
	~UCavrnusValueSyncBase();

	UCavrnusPropertiesContainer* GetContainer() const;

	virtual void BeginPlay();
	virtual void EndPlay(const EEndPlayReason::Type Reason);

	void OnComponentCreated() override;
	void AutoAttachPropertiesContainer();
	FString GetGeneratedContainerName() const;

	UFUNCTION()
	void SpaceConnected(FCavrnusSpaceConnection spaceConn);

	UFUNCTION()
	void PollForPropertyChanges();

	UPROPERTY()
	FCavrnusSpaceConnection SpaceConn;

	UPROPERTY()
	FCavrnusBinding PropertyBinding;

	UPROPERTY()
	FTimerHandle PollTimer;

	UPROPERTY()
	FString ContainerName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Cavrnus")
	FString PropertyName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Cavrnus")
	bool SendChanges = true;

	bool RecvChanges = true;

	// IPropertySyncInterface implementation
	virtual void DefineDefaultPropertyValue() PURE_VIRTUAL(IPropertySyncInterface::DefineDefaultPropertyValue);
	virtual FCavrnusBinding BindPropertyValue() PURE_VIRTUAL(IPropertySyncInterface::BindPropertyValue, return FCavrnusBinding([]() {}););
	virtual void SendPropertyChanges() PURE_VIRTUAL(IPropertySyncInterface::SendPropertyChanges);

protected:

	UPROPERTY()
	UCavrnusLivePropertyUpdate* liveUpdater = nullptr;

	FString ReportOwnerName() const;

private:
	bool ShouldAutoAddPropertiesContainer() const;
};