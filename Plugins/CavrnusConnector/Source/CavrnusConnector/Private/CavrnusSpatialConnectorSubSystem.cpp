#include "CavrnusSpatialConnectorSubSystem.h"
#include "CavrnusFunctionLibrary.h"
#include "CavrnusSpatialConnector.h"
#include "SpawnedObjectsManager.h"
#include "CavrnusAvatarManager.h"
#include "PDFManager.h"
#include "CavrnusLocalUser.h"
#include <GameFramework/Pawn.h>
#include <GameFramework/PlayerController.h>
#include "TimerManager.h"
#include "Engine/World.h" 

UCavrnusSpatialConnectorSubSystem::UCavrnusSpatialConnectorSubSystem()
{
}


UCavrnusSpatialConnectorSubSystem::~UCavrnusSpatialConnectorSubSystem()
{
	AvatarManager = nullptr;
	SpawnedObjectsManager = nullptr;
	PDFManager = nullptr;
}

void UCavrnusSpatialConnectorSubSystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	AuthSuccess.BindUFunction(this, GET_FUNCTION_NAME_CHECKED(UCavrnusSpatialConnectorSubSystem, OnAuthSuccess));
	AuthFailure.BindUFunction(this, GET_FUNCTION_NAME_CHECKED(UCavrnusSpatialConnectorSubSystem, OnAuthFailure));
	SpaceConnectionSuccess.BindUFunction(this, GET_FUNCTION_NAME_CHECKED(UCavrnusSpatialConnectorSubSystem, OnSpaceConnectionSuccess));
	SpaceConnectionFailure.BindUFunction(this, GET_FUNCTION_NAME_CHECKED(UCavrnusSpatialConnectorSubSystem, OnSpaceConnectionFailure));

	GetSpawnedObjectsManager();
}

void UCavrnusSpatialConnectorSubSystem::Deinitialize()
{
	AvatarManager = nullptr;
	SpawnedObjectsManager = nullptr;
	PDFManager = nullptr;
	UCavrnusFunctionLibrary::KillDataModel();
	Super::Deinitialize();
}

void UCavrnusSpatialConnectorSubSystem::RegisterCavrnusSpatialConnector(ACavrnusSpatialConnector* CavrnusSpatialConnector)
{
	CurrentCavrnusSpatialConnector = CavrnusSpatialConnector;
}

ACavrnusSpatialConnector* UCavrnusSpatialConnectorSubSystem::GetCavrnusSpatialConnector() const
{
	return CurrentCavrnusSpatialConnector.Get();
}

void UCavrnusSpatialConnectorSubSystem::AuthenticateAndJoin()
{
	ACavrnusSpatialConnector* CavrnusSpatialConnector = GetCavrnusSpatialConnector();
	if (!CavrnusSpatialConnector)
		return;

	// TO DO: Check if actually a valid token?
	if (Authentication.Token.IsEmpty())
	{
		if (CavrnusSpatialConnector->AuthMethod == ECavrnusAuthMethod::JoinAsGuest)
		{
			if (CavrnusSpatialConnector->GuestLoginMethod == ECavrnusGuestLoginMethod::EnterNameBelow)
			{
				UCavrnusFunctionLibrary::AuthenticateAsGuest(
					CavrnusSpatialConnector->MyServer,
					CavrnusSpatialConnector->GuestName,
					AuthSuccess, AuthFailure);
			}
			else if(CavrnusSpatialConnector->GuestLoginMethod == ECavrnusGuestLoginMethod::PromptToEnterName)
			{
				ShowGuestLoginWidget();
			}
			else
			{
				UE_LOG(LogCavrnusConnector, Error, TEXT("No guest login method selected in CavrnusSpatialConnector actor!"));
			}
		}
		else if (CavrnusSpatialConnector->AuthMethod == ECavrnusAuthMethod::JoinAsMember)
		{
			if (CavrnusSpatialConnector->MemberLoginMethod == ECavrnusMemberLoginMethod::EnterMemberLoginCredentials)
			{
				UCavrnusFunctionLibrary::AuthenticateWithPassword(
					CavrnusSpatialConnector->MyServer,
					CavrnusSpatialConnector->MemberLoginEmail,
					CavrnusSpatialConnector->MemberLoginPassword,
					AuthSuccess, AuthFailure);
			}
			else if (CavrnusSpatialConnector->MemberLoginMethod == ECavrnusMemberLoginMethod::PromptMemberToLogin)
			{
				ShowLoginWidget();
			}
			else
			{
				UE_LOG(LogCavrnusConnector, Error, TEXT("No member login method selected in CavrnusSpatialConnector actor!"));
			}
		}
		else
		{
			UE_LOG(LogCavrnusConnector, Error, TEXT("No authentication method selected in CavrnusSpatialConnector actor!"));
		}
	}
	else if (!bHasSpaceConnection) // Authenticated but not in a space
	{
		OnAuthSuccess(Authentication);
	}

	if (!AvatarManager)
	{
		AvatarManager = NewObject<UCavrnusAvatarManager>(GetGameInstance());
	}
}

void UCavrnusSpatialConnectorSubSystem::OnAuthSuccess(FCavrnusAuthentication Auth)
{
	Authentication = Auth;
	ACavrnusSpatialConnector* CavrnusSpatialConnector = GetCavrnusSpatialConnector();
	UE_LOG(LogCavrnusConnector, Log, TEXT("Successfully authenticated"));
	if (CavrnusSpatialConnector->SpaceJoinMethod == ECavrnusSpaceJoinMethod::EnterSpaceId)
	{
		AttemptToJoinSpace(CavrnusSpatialConnector->AutomaticSpaceJoinId);
	}
	else if (CavrnusSpatialConnector->SpaceJoinMethod == ECavrnusSpaceJoinMethod::SpacesList)
	{
		if (UWorld* World = GetWorld())
		{
			if (UCavrnusSpaceListWidget* SpaceListWidget = CreateWidget<UCavrnusSpaceListWidget>(World, CavrnusSpatialConnector->SpaceJoinMenu))
			{
				SpaceListWidget->OnCavrnusSpaceSelected.AddLambda([this, SpaceListWidget](FString SpaceJoinId) {
					SpaceListWidget->RemoveFromParent();
					AttemptToJoinSpace(SpaceJoinId);
					});

				SpaceListWidget->AddToViewport();
			}
		}
	}
}

void UCavrnusSpatialConnectorSubSystem::OnAuthFailure(FString ErrorMessage)
{
	Authentication = FCavrnusAuthentication();
	ACavrnusSpatialConnector* CavrnusSpatialConnector = GetCavrnusSpatialConnector();
	UE_LOG(LogCavrnusConnector, Error, TEXT("Failed to authenticate, error: %s"), *ErrorMessage);
	if (CavrnusSpatialConnector->AuthMethod == ECavrnusAuthMethod::JoinAsMember)
	{
		ShowLoginWidget();
	}
	else if (CavrnusSpatialConnector->AuthMethod == ECavrnusAuthMethod::JoinAsGuest)
	{
		ShowGuestLoginWidget();
	}
}

void UCavrnusSpatialConnectorSubSystem::OnSpaceConnectionSuccess(FCavrnusSpaceConnection SpaceConnection)
{
	bHasSpaceConnection = true;

	// Listen for future controller or pawn changes
	UGameInstance* GameInstance = GetGameInstance();
	if (GameInstance)
	{
		GameInstance->GetOnPawnControllerChanged().AddDynamic(this, &UCavrnusSpatialConnectorSubSystem::OnPawnControllerChanged);
		if (APlayerController* PlayerController = GameInstance->GetFirstLocalPlayerController())
		{
			PlayerController->OnPossessedPawnChanged.AddDynamic(this, &UCavrnusSpatialConnectorSubSystem::OnPossessedPawnChanged);
		}
	}

	AttachLocalUserComponentToPawn();

	ACavrnusSpatialConnector* CavrnusSpatialConnector = GetCavrnusSpatialConnector();
	UE_LOG(LogCavrnusConnector, Log, TEXT("Successfully joined space!"));

	if (LoadingWidget)
	{
		LoadingWidget->RemoveFromParent();
		LoadingWidget = nullptr;
	}

	for (TSubclassOf<UUserWidget>& Widget : CavrnusSpatialConnector->WidgetsToLoad)
	{
		SpawnWidget(Widget);
	}
}

void UCavrnusSpatialConnectorSubSystem::OnPawnControllerChanged(APawn* InPawn, AController* InController)
{
	if (InController && InController->IsLocalPlayerController() && InPawn)
	{
		AttachLocalUserComponentToPawn();
	}
}

void UCavrnusSpatialConnectorSubSystem::OnPossessedPawnChanged(APawn* OldPawn, APawn* NewPawn)
{
	if (NewPawn)
	{
		AttachLocalUserComponentToPawn();
	}

	if (OldPawn)
	{
		OldPawn->Destroy();
	}
}

void UCavrnusSpatialConnectorSubSystem::AttachLocalUserComponentToPawn()
{
	UGameInstance* GameInstance = GetGameInstance();
	if (!GameInstance)
	{
		return;
	}

	APlayerController* PlayerController = GameInstance->GetFirstLocalPlayerController();
	if (!PlayerController)
	{
		return;
	}

	APawn* Pawn = PlayerController->GetPawn();
	if (Pawn && !Pawn->GetComponentByClass(UCavrnusLocalUser::StaticClass()))
	{
		USceneComponent* PawnRootComponent = Pawn->GetRootComponent();
		ensureAlwaysMsgf(PawnRootComponent != nullptr, TEXT("No root component on pawn when attaching local user component"));
		UCavrnusLocalUser* LocalUserComponent = Cast<UCavrnusLocalUser>(Pawn->AddComponentByClass(
			UCavrnusLocalUser::StaticClass(),
			true,
			FTransform::Identity,
			false));

		ensureAlwaysMsgf(LocalUserComponent != nullptr, TEXT("No local user component to attach"));
		LocalUserComponent->AttachToComponent(PawnRootComponent, FAttachmentTransformRules::KeepRelativeTransform);
		LocalUserComponent->RegisterComponent();
	}
}

UUserWidget* UCavrnusSpatialConnectorSubSystem::SpawnWidget(TSubclassOf<UUserWidget> WidgetClass)
{
	ACavrnusSpatialConnector* CavrnusSpatialConnector = GetCavrnusSpatialConnector();
	if ((CavrnusSpatialConnector->WidgetsToLoad.Contains(WidgetClass)) || (WidgetClass == CavrnusSpatialConnector->LoadingWidgetClass))
	{
		if (UGameInstance* GameInstance = GetGameInstance())
		{
			UUserWidget* CreatedWidget = CreateWidget<UUserWidget>(GameInstance, WidgetClass);
			if (CreatedWidget)
			{
				CreatedWidget->AddToViewport();
			}

			return CreatedWidget;
		}
	}

	return nullptr;
}

void UCavrnusSpatialConnectorSubSystem::OnSpaceConnectionFailure(FString ErrorMessage)
{
	bHasSpaceConnection = false;

	UE_LOG(LogCavrnusConnector, Error, TEXT("Failed to join space, error: %s"), *ErrorMessage);
}

UCavrnusAvatarManager* UCavrnusSpatialConnectorSubSystem::GetAvatarManager() {
	return AvatarManager;
}

void UCavrnusSpatialConnectorSubSystem::AttemptToJoinSpace(FString JoinSpaceId)
{
	ACavrnusSpatialConnector* CavrnusSpatialConnector = GetCavrnusSpatialConnector();
	if (CavrnusSpatialConnector->LoadingWidgetClass)
	{
		LoadingWidget = SpawnWidget(CavrnusSpatialConnector->LoadingWidgetClass);
	}

	UE_LOG(LogCavrnusConnector, Log, TEXT("Attempting to join space: %s"), *JoinSpaceId);
	UCavrnusFunctionLibrary::JoinSpace(JoinSpaceId, SpaceConnectionSuccess, SpaceConnectionFailure);
}

void UCavrnusSpatialConnectorSubSystem::ShowGuestLoginWidget()
{
	ACavrnusSpatialConnector* CavrnusSpatialConnector = GetCavrnusSpatialConnector();
	if (UWorld* World = GetWorld())
	{
		if (UCavrnusGuestLoginWidget* LoginWidget = CreateWidget<UCavrnusGuestLoginWidget>(World, CavrnusSpatialConnector->GuestJoinMenu))
		{
			LoginWidget->OnLogin.AddLambda([this, CavrnusSpatialConnector, LoginWidget](FString GuestLoginUsername) {
				LoginWidget->RemoveFromParent();
				UCavrnusFunctionLibrary::AuthenticateAsGuest(CavrnusSpatialConnector->MyServer, GuestLoginUsername, AuthSuccess, AuthFailure);
				});

			LoginWidget->AddToViewport();
		}
	}
}

void UCavrnusSpatialConnectorSubSystem::ShowLoginWidget()
{
	ACavrnusSpatialConnector* CavrnusSpatialConnector = GetCavrnusSpatialConnector();

	// Spawn a widget and get credentials from that
	if (UWorld* World = GetWorld())
	{
		if (UCavrnusLoginWidget* LoginWidget = CreateWidget<UCavrnusLoginWidget>(World, CavrnusSpatialConnector->MemberLoginMenu))
		{
			LoginWidget->OnLogin.AddLambda([this, CavrnusSpatialConnector, LoginWidget](FString LoginEmail, FString LoginPassword) {
				LoginWidget->RemoveFromParent();
				UCavrnusFunctionLibrary::AuthenticateWithPassword(CavrnusSpatialConnector->MyServer, LoginEmail, LoginPassword, AuthSuccess, AuthFailure);
				});

			LoginWidget->AddToViewport();
		}
	}
}

USpawnedObjectsManager* UCavrnusSpatialConnectorSubSystem::GetSpawnedObjectsManager()
{
	if (!SpawnedObjectsManager)
	{
		SpawnedObjectsManager = NewObject<USpawnedObjectsManager>(GetGameInstance());
		USpawnedObjectsManager::RegisterSpawnManager(SpawnedObjectsManager);
	}

	return SpawnedObjectsManager;
}

UPDFManager* UCavrnusSpatialConnectorSubSystem::GetPDFManager()
{
	if (!PDFManager)
	{
		PDFManager = NewObject<UPDFManager>(GetGameInstance());
		PDFManager->Init();
		UCavrnusFunctionLibrary::GetDataModel()->SetPDFManager(PDFManager);
	}

	return PDFManager;
}

void UCavrnusSpatialConnectorSubSystem::SpawnCavrnusActor(const FCavrnusSpawnedObject& SpawnedObject)
{
	if (ACavrnusSpatialConnector* CavrnusSpatialConnector = GetCavrnusSpatialConnector())
	{
		if (USpawnedObjectsManager* SpawnedObjectManager = GetSpawnedObjectsManager())
		{
			FTimerHandle UnusedHandle;
			FTimerDelegate Delegate;
			Delegate.BindUFunction(SpawnedObjectManager, "SpawnCavrnusActor", SpawnedObject, CavrnusSpatialConnector);

			GetWorld()->GetTimerManager().SetTimer(UnusedHandle, Delegate, .1f, false);
		}
	}
}

void UCavrnusSpatialConnectorSubSystem::DestroyCavrnusActor(const FCavrnusSpawnedObject& SpawnedObject)
{
	if (ACavrnusSpatialConnector* CavrnusSpatialConnector = GetCavrnusSpatialConnector())
	{
		CavrnusSpatialConnector->DestroyCavrnusActor(SpawnedObject);
	}
}

FCavrnusSpawnedObject UCavrnusSpatialConnectorSubSystem::GetSpawnedObject(AActor* Actor)
{
	if (USpawnedObjectsManager* SpawnedObjectManager = GetSpawnedObjectsManager())
	{
		return SpawnedObjectManager->GetSpawnedObject(Actor);
	}

	return FCavrnusSpawnedObject();
}
