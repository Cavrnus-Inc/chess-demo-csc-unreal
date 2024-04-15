#include "Types/CavrnusLiveFloatPropertyUpdate.h"
#include "Translation\CavrnusProtoTranslation.h"

UCavrnusLiveFloatPropertyUpdate::UCavrnusLiveFloatPropertyUpdate()
{

}

UCavrnusLiveFloatPropertyUpdate::~UCavrnusLiveFloatPropertyUpdate()
{
}

void UCavrnusLiveFloatPropertyUpdate::Initialize(Cavrnus::CavrnusRelayModel* relayModel, FCavrnusSpaceConnection spaceConn, const FString& propertyId, float value)
{
	Super::Initialize(relayModel, spaceConn, propertyId);

	RelayModel->SendMessage(Cavrnus::CavrnusProtoTranslation::BuildBeginLiveFloatUpdateMsg(SpaceConn, LiveUpdaterId, PropertyId, value));
}

void UCavrnusLiveFloatPropertyUpdate::UpdateWithNewData(float value)
{
	RelayModel->SendMessage(Cavrnus::CavrnusProtoTranslation::BuildContinueLiveFloatUpdateMsg(SpaceConn, LiveUpdaterId, PropertyId, value));
}

void UCavrnusLiveFloatPropertyUpdate::Finalize(float value)
{
	RelayModel->SendMessage(Cavrnus::CavrnusProtoTranslation::BuildFinalizeLiveFloatUpdateMsg(SpaceConn, LiveUpdaterId, PropertyId, value));
}
