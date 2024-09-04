// // Copyright (c), Cavrnus. All rights reserved.

#include "UI/UserMenu/CavrnusUserMenu.h"
#include "CavrnusFunctionLibrary.h"
#include "Components/ScrollBox.h"
#include "UI/UserMenu/CavrnusMaximizedUser.h"

void UCavrnusUserMenu::NativeConstruct()
{
	Super::NativeConstruct();

	if (!ScrollBox)
	{
		UE_LOG(LogCavrnusConnector, Error, TEXT("UserMenu Scrollbox is not valid!"));
		return;
	}

	if (!WidgetEntry)
	{
		UE_LOG(LogCavrnusConnector, Error, TEXT("UserMenu WidgetEntry is not valid!"));
		return;
	}

	UCavrnusFunctionLibrary::AwaitAnySpaceConnection([this](const FCavrnusSpaceConnection& CavrnusSpaceConnection)
	{
		UsersBinding = UCavrnusFunctionLibrary::BindSpaceUsers(CavrnusSpaceConnection, [this, CavrnusSpaceConnection](const FCavrnusUser& AddedUser)
		{
			if (ScrollBox == nullptr)
				return;

			if (WidgetEntry == nullptr)
				return;

			if (UCavrnusUserWidget* Widget = CreateWidget<UCavrnusUserWidget>(this, WidgetEntry))
			{
				Widget->InitializeUserConnection(AddedUser);
				ScrollBox->AddChild(Widget);

				Widget->MaximizeUserSelected = [this](const FCavrnusUser& CavrnusUser)
				{
					MaximizeUserSelected(CavrnusUser);
				};
				
				Entries.Add(AddedUser.UserConnectionId, Widget);
			}
		}, [this](const FCavrnusUser& RemovedUser)
		{
			UCavrnusUserWidget** EntryPtr = Entries.Find(RemovedUser.UserConnectionId);
			if (EntryPtr && *EntryPtr)
			{
				UCavrnusUserWidget* Entry = *EntryPtr;
				ScrollBox->RemoveChild(Entry);
				Entries.Remove(RemovedUser.UserConnectionId);
			}
		});
	});
}

void UCavrnusUserMenu::NativeDestruct()
{
	Super::NativeDestruct();

	UsersBinding->Unbind();
}

void UCavrnusUserMenu::MaximizeUserSelected(const FCavrnusUser& MaximizedUser)
{
	UCavrnusMaximizedUser* Widget = CreateWidget<UCavrnusMaximizedUser>(this, MaximizedUserEntry);

	if (Widget)
	{
		Widget->InitializeUserConnection(MaximizedUser);

		if (SecondaryWidgetRequested.IsBound())
		{
			SecondaryWidgetRequested.Broadcast(Widget, "");
		}
	}
}