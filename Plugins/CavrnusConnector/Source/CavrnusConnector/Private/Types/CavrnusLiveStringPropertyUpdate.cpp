#include "Types/CavrnusLiveStringPropertyUpdate.h"
#include "Translation\CavrnusProtoTranslation.h"

UCavrnusLiveStringPropertyUpdate::UCavrnusLiveStringPropertyUpdate()
{

}

UCavrnusLiveStringPropertyUpdate::~UCavrnusLiveStringPropertyUpdate()
{
}

void UCavrnusLiveStringPropertyUpdate::Initialize(Cavrnus::CavrnusRelayModel* relayModel, FCavrnusSpaceConnection spaceConn, const FString& propertyId, FString value)
{
	Super::Initialize(relayModel, spaceConn, propertyId);

	RelayModel->SendMessage(Cavrnus::CavrnusProtoTranslation::BuildBeginLiveStringUpdateMsg(SpaceConn, LiveUpdaterId, PropertyId, value));
}

void UCavrnusLiveStringPropertyUpdate::UpdateWithNewData(FString value)
{
	RelayModel->SendMessage(Cavrnus::CavrnusProtoTranslation::BuildContinueLiveStringUpdateMsg(SpaceConn, LiveUpdaterId, PropertyId, value));
}

void UCavrnusLiveStringPropertyUpdate::Finalize(FString value)
{
	RelayModel->SendMessage(Cavrnus::CavrnusProtoTranslation::BuildFinalizeLiveStringUpdateMsg(SpaceConn, LiveUpdaterId, PropertyId, value));
}
