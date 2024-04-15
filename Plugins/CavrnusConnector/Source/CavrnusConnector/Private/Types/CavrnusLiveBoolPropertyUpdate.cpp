#include "Types/CavrnusLiveBoolPropertyUpdate.h"
#include "Translation\CavrnusProtoTranslation.h"

UCavrnusLiveBoolPropertyUpdate::UCavrnusLiveBoolPropertyUpdate()
{

}

UCavrnusLiveBoolPropertyUpdate::~UCavrnusLiveBoolPropertyUpdate()
{
}

void UCavrnusLiveBoolPropertyUpdate::Initialize(Cavrnus::CavrnusRelayModel* relayModel, FCavrnusSpaceConnection spaceConn, const FString& propertyId, bool value)
{
	Super::Initialize(relayModel, spaceConn, propertyId);

	RelayModel->SendMessage(Cavrnus::CavrnusProtoTranslation::BuildBeginLiveBoolUpdateMsg(SpaceConn, LiveUpdaterId, PropertyId, value));
}

void UCavrnusLiveBoolPropertyUpdate::UpdateWithNewData(bool value)
{
	RelayModel->SendMessage(Cavrnus::CavrnusProtoTranslation::BuildContinueLiveBoolUpdateMsg(SpaceConn, LiveUpdaterId, PropertyId, value));
}

void UCavrnusLiveBoolPropertyUpdate::Finalize(bool value)
{
	RelayModel->SendMessage(Cavrnus::CavrnusProtoTranslation::BuildFinalizeLiveBoolUpdateMsg(SpaceConn, LiveUpdaterId, PropertyId, value));
}
