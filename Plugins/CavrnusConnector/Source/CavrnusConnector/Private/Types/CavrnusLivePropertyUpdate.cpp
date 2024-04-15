#include "Types/CavrnusLivePropertyUpdate.h"
#include "Translation\CavrnusProtoTranslation.h"

UCavrnusLivePropertyUpdate::UCavrnusLivePropertyUpdate()
{

}

UCavrnusLivePropertyUpdate::~UCavrnusLivePropertyUpdate()
{
}

void UCavrnusLivePropertyUpdate::Initialize(Cavrnus::CavrnusRelayModel* relayModel, FCavrnusSpaceConnection spaceConn, const FString& propertyId)
{
	SpaceConn = spaceConn;
	LiveUpdaterId = FGuid::NewGuid().ToString();
	RelayModel = relayModel;
	PropertyId = propertyId;
}

void UCavrnusLivePropertyUpdate::Cancel()
{
	RelayModel->SendMessage(Cavrnus::CavrnusProtoTranslation::BuildCancelLiveUpdateMsg(SpaceConn, LiveUpdaterId));
}
