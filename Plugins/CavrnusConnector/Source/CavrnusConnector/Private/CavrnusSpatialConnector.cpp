#include "CavrnusSpatialConnector.h"

#include "CavrnusAvatarManager.h"
#include "CavrnusConnectorModule.h"
#include "CavrnusFunctionLibrary.h"
#include "CavrnusSpatialConnectorSubSystem.h"
#include "CavrnusActorComponent.h"
#include "SpawnedObjectsManager.h"
#include <Engine/GameInstance.h>
#include <EngineUtils.h>

// Sets default values
ACavrnusSpatialConnector::ACavrnusSpatialConnector()
{
	// Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	AuthMethod = ECavrnusAuthMethod::JoinAsMember;
	MemberLoginMethod = ECavrnusMemberLoginMethod::EnterMemberLoginCredentials;
	GuestLoginMethod = ECavrnusGuestLoginMethod::EnterNameBelow;
	SpaceJoinMethod = ECavrnusSpaceJoinMethod::SpacesList;
	MemberLoginMenu = GetDefaultBlueprint(TEXT("/CavrnusConnector/HUD/CavrnusCore/WBP_LoginCredentials.WBP_LoginCredentials_C"), UCavrnusLoginWidget::StaticClass());
	GuestJoinMenu = GetDefaultBlueprint(TEXT("/CavrnusConnector/HUD/CavrnusCore/WBP_GuestLoginCredentials.WBP_GuestLoginCredentials_C"), UCavrnusGuestLoginWidget::StaticClass());
	SpaceJoinMenu = GetDefaultBlueprint(TEXT("/CavrnusConnector/HUD/CavrnusCore/WBP_SpaceSelection.WBP_SpaceSelection_C"), UCavrnusSpaceListWidget::StaticClass());
	LoadingWidgetClass = GetDefaultBlueprint(TEXT("/CavrnusConnector/HUD/WBP_LoadingWidget.WBP_LoadingWidget_C"), UUserWidget::StaticClass());
	WidgetsToLoad.Add(GetDefaultBlueprint(TEXT("/CavrnusConnector/Menus/WBP_AudioVideoWidget.WBP_AudioVideoWidget_C"), UUserWidget::StaticClass()));
	WidgetsToLoad.Add(GetDefaultBlueprint(TEXT("/CavrnusConnector/HUD/WBP_UserListWidget.WBP_UserListWidget_C"), UUserWidget::StaticClass()));
	RemoteAvatarClass = GetDefaultBlueprint(TEXT("/CavrnusConnector/Pawns/Blueprints/BP_TouchFlyModePawn.BP_TouchFlyModePawn_C"), AActor::StaticClass());
}

void ACavrnusSpatialConnector::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	UWorld* WorldPtr = GetWorld();
	if (WorldPtr)
	{
		UGameInstance* GameInstance = WorldPtr->GetGameInstance();
		if (GameInstance)
		{
			UCavrnusSpatialConnectorSubSystem* CavrnusSubSystem = GameInstance->GetSubsystem<UCavrnusSpatialConnectorSubSystem>();

			if (CavrnusSubSystem)
			{
				CavrnusSubSystem->RegisterCavrnusSpatialConnector(this);
			}
		}
	}
}

// Called when the game starts or when spawned
void ACavrnusSpatialConnector::BeginPlay()
{
	Super::BeginPlay();

	UWorld* WorldPtr = GetWorld();
	if (!WorldPtr)
	{
		UE_LOG(LogCavrnusConnector, Error, TEXT("No world in ACavrnusSpatialConnector::BeginPlay()"));
		return;
	}

	UGameInstance* GameInstance = WorldPtr->GetGameInstance();
	if (UCavrnusSpatialConnectorSubSystem* CavrnusSubSystem = GameInstance->GetSubsystem<UCavrnusSpatialConnectorSubSystem>())
	{
		CavrnusSubSystem->AuthenticateAndJoin();
	}
}

void ACavrnusSpatialConnector::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

UClass* ACavrnusSpatialConnector::GetDefaultBlueprint(const FString& Path, UClass* BaseClass) const
{
	// Use BP as default value
	UClass* LoadedBlueprintClass = StaticLoadClass(BaseClass, nullptr, *Path, nullptr, LOAD_None, nullptr);
	if (!LoadedBlueprintClass)
	{
		UE_LOG(LogCavrnusConnector, Error, TEXT("Blueprint asset failed to load from path: %s, base class name: %s"), *Path, *BaseClass->GetName());
	}

	return LoadedBlueprintClass;
}

AActor* ACavrnusSpatialConnector::SpawnActorFromIdentifier_Implementation(const FString& Identifier, const FTransform& Transform)
{
	AActor* SpawnedActor = nullptr;
	if (TSubclassOf<AActor>* ActorClass = SpawnableIdentifiers.Find(Identifier))
	{
		SpawnedActor = GetWorld()->SpawnActor(*ActorClass, &Transform);
	}
	else
	{
		UE_LOG(LogCavrnusConnector, Warning, TEXT("No actor was spawned as identifier %s was not in the 'SpawnableIdentifiers' map of the CavrnusSpatialConnector"), *Identifier);
	}

	return SpawnedActor;
}

void ACavrnusSpatialConnector::DestroyCavrnusActor_Implementation(const FCavrnusSpawnedObject& SpawnedObject)
{
	UGameInstance* GameInstance = GetGameInstance();
	if (!GameInstance)
	{
		UE_LOG(LogCavrnusConnector, Error, TEXT("Attempting to delete object but Game Instance not found"));
		return;
	}

	UWorld* World = GameInstance->GetWorld();
	if (!World)
	{
		UE_LOG(LogCavrnusConnector, Error, TEXT("Attempting to delete object but World not found"));
		return;
	}

	UCavrnusSpatialConnectorSubSystem* CavrnusSubsystem = GameInstance->GetSubsystem<UCavrnusSpatialConnectorSubSystem>();
	TSet<AActor*> ActorsToDelete;
	for (TActorIterator<AActor> It(World); It; ++It)
	{
		FCavrnusSpawnedObject ActorSpawnedObject = CavrnusSubsystem->GetSpawnedObject(*It);
		if (ActorSpawnedObject.PropertiesContainerName.IsEmpty())
			continue;

		if (ActorSpawnedObject.PropertiesContainerName == SpawnedObject.PropertiesContainerName)
		{
			ActorsToDelete.Add(*It);
		}
	}

	for (AActor* Actor : ActorsToDelete)
	{
		Actor->Destroy();
		Actor = nullptr;
	}
}

