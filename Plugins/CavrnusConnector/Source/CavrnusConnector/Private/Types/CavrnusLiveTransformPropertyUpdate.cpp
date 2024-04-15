#include "Types/CavrnusLiveTransformPropertyUpdate.h"
#include "Translation\CavrnusProtoTranslation.h"

UCavrnusLiveTransformPropertyUpdate::UCavrnusLiveTransformPropertyUpdate()
{

}

UCavrnusLiveTransformPropertyUpdate::~UCavrnusLiveTransformPropertyUpdate()
{
}

void UCavrnusLiveTransformPropertyUpdate::Initialize(Cavrnus::CavrnusRelayModel* relayModel, FCavrnusSpaceConnection spaceConn, const FString& propertyId, FTransform value)
{
	Super::Initialize(relayModel, spaceConn, propertyId);

	RelayModel->SendMessage(Cavrnus::CavrnusProtoTranslation::BuildBeginLiveTransformUpdateMsg(SpaceConn, LiveUpdaterId, PropertyId, value));
}

void UCavrnusLiveTransformPropertyUpdate::UpdateWithNewData(FTransform value)
{
	RelayModel->SendMessage(Cavrnus::CavrnusProtoTranslation::BuildContinueLiveTransformUpdateMsg(SpaceConn, LiveUpdaterId, PropertyId, value));
}

void UCavrnusLiveTransformPropertyUpdate::Finalize(FTransform value)
{
	RelayModel->SendMessage(Cavrnus::CavrnusProtoTranslation::BuildFinalizeLiveTransformUpdateMsg(SpaceConn, LiveUpdaterId, PropertyId, value));
}
