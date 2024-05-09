#include "LivePropertyUpdates/CavrnusLiveFloatPropertyUpdate.h"
#include "RelayModel/CavrnusVirtualPropertyUpdate.h"
#include "Translation/CavrnusProtoTranslation.h"

UCavrnusLiveFloatPropertyUpdate::UCavrnusLiveFloatPropertyUpdate()
{
}

UCavrnusLiveFloatPropertyUpdate::~UCavrnusLiveFloatPropertyUpdate()
{
}

void UCavrnusLiveFloatPropertyUpdate::Initialize(Cavrnus::CavrnusRelayModel* relayModel, FCavrnusSpaceConnection spaceConn, const FPropertyId& propertyId, float value)
{
	livePropertyUpdate = new Cavrnus::CavrnusVirtualPropertyUpdate(relayModel, spaceConn, propertyId, Cavrnus::FPropertyValue::FloatPropValue(value));
}

void UCavrnusLiveFloatPropertyUpdate::UpdateWithNewData(float value)
{
	if (livePropertyUpdate)
		livePropertyUpdate->UpdateWithNewData(Cavrnus::FPropertyValue::FloatPropValue(value));
}

void UCavrnusLiveFloatPropertyUpdate::Finalize(float value)
{
	if (livePropertyUpdate)
		livePropertyUpdate->Finalize(Cavrnus::FPropertyValue::FloatPropValue(value));
}
