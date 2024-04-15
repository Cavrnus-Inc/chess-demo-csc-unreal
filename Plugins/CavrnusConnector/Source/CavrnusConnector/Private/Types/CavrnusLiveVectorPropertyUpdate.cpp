#include "Types/CavrnusLiveVectorPropertyUpdate.h"
#include "Translation\CavrnusProtoTranslation.h"

UCavrnusLiveVectorPropertyUpdate::UCavrnusLiveVectorPropertyUpdate()
{

}

UCavrnusLiveVectorPropertyUpdate::~UCavrnusLiveVectorPropertyUpdate()
{
}

void UCavrnusLiveVectorPropertyUpdate::Initialize(Cavrnus::CavrnusRelayModel* relayModel, FCavrnusSpaceConnection spaceConn, const FString& propertyId, FVector value)
{
	Super::Initialize(relayModel, spaceConn, propertyId);

	RelayModel->SendMessage(Cavrnus::CavrnusProtoTranslation::BuildBeginLiveVectorUpdateMsg(SpaceConn, LiveUpdaterId, PropertyId, value));
}

void UCavrnusLiveVectorPropertyUpdate::UpdateWithNewData(FVector value)
{
	RelayModel->SendMessage(Cavrnus::CavrnusProtoTranslation::BuildContinueLiveVectorUpdateMsg(SpaceConn, LiveUpdaterId, PropertyId, value));
}

void UCavrnusLiveVectorPropertyUpdate::Finalize(FVector value)
{
	RelayModel->SendMessage(Cavrnus::CavrnusProtoTranslation::BuildFinalizeLiveVectorUpdateMsg(SpaceConn, LiveUpdaterId, PropertyId, value));
}
