#include "Types/CavrnusLiveColorPropertyUpdate.h"
#include "Translation\CavrnusProtoTranslation.h"

UCavrnusLiveColorPropertyUpdate::UCavrnusLiveColorPropertyUpdate()
{

}

UCavrnusLiveColorPropertyUpdate::~UCavrnusLiveColorPropertyUpdate()
{
}

void UCavrnusLiveColorPropertyUpdate::Initialize(Cavrnus::CavrnusRelayModel* relayModel, FCavrnusSpaceConnection spaceConn, const FString& propertyId, FLinearColor value)
{
	Super::Initialize(relayModel, spaceConn, propertyId);

	RelayModel->SendMessage(Cavrnus::CavrnusProtoTranslation::BuildBeginLiveColorUpdateMsg(SpaceConn, LiveUpdaterId, PropertyId, value));
}

void UCavrnusLiveColorPropertyUpdate::UpdateWithNewData(FLinearColor value)
{
	RelayModel->SendMessage(Cavrnus::CavrnusProtoTranslation::BuildContinueLiveColorUpdateMsg(SpaceConn, LiveUpdaterId, PropertyId, value));
}

void UCavrnusLiveColorPropertyUpdate::Finalize(FLinearColor value)
{
	RelayModel->SendMessage(Cavrnus::CavrnusProtoTranslation::BuildFinalizeLiveColorUpdateMsg(SpaceConn, LiveUpdaterId, PropertyId, value));
}
