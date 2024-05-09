﻿#include "RelayModel/CavrnusVirtualPropertyUpdate.h"
#include "RelayModel/CavrnusRelayModel.h"
#include "Types/CavrnusPropertyValue.h"
#include "Types/PropertyId.h"
#include "Translation/CavrnusProtoTranslation.h"

namespace Cavrnus
{
	CavrnusVirtualPropertyUpdate::CavrnusVirtualPropertyUpdate()
	{
	}

	CavrnusVirtualPropertyUpdate::CavrnusVirtualPropertyUpdate(Cavrnus::CavrnusRelayModel* relayModel, FCavrnusSpaceConnection spaceConn, const FPropertyId& propertyId, const FPropertyValue& propVal)
	{
		RelayModel = relayModel;
		SpaceConn = spaceConn;
		PropertyId = propertyId;

		LiveUpdaterId = FGuid::NewGuid().ToString();

		lastSentValue = propVal;

		int localChangeId = RelayModel->GetSpacePropertyModel(SpaceConn)->SetLocalPropVal(PropertyId, propVal);
		RelayModel->SendMessage(Cavrnus::CavrnusProtoTranslation::BuildBeginLivePropertyUpdateMsg(SpaceConn, LiveUpdaterId, PropertyId, propVal, localChangeId));

		lastUpdatedTimeSec = FPlatformTime::Seconds();
	}

	CavrnusVirtualPropertyUpdate::~CavrnusVirtualPropertyUpdate()
	{
	}

	void CavrnusVirtualPropertyUpdate::UpdateWithNewData(const FPropertyValue& propVal)
	{
		lastSentValue = propVal;

		int localChangeId = RelayModel->GetSpacePropertyModel(SpaceConn)->SetLocalPropVal(PropertyId, propVal);
		RelayModel->SendMessage(Cavrnus::CavrnusProtoTranslation::BuildContinueLivePropertyUpdateMsg(SpaceConn, LiveUpdaterId, PropertyId, propVal, localChangeId));

		lastUpdatedTimeSec = FPlatformTime::Seconds();
	}

	void CavrnusVirtualPropertyUpdate::Finalize()
	{
		int localChangeId = RelayModel->GetSpacePropertyModel(SpaceConn)->SetLocalPropVal(PropertyId, lastSentValue);
		RelayModel->SendMessage(Cavrnus::CavrnusProtoTranslation::BuildFinalizeLivePropertyUpdateMsg(SpaceConn, LiveUpdaterId, PropertyId, lastSentValue, localChangeId));

		lastUpdatedTimeSec = FPlatformTime::Seconds();
	}

	void CavrnusVirtualPropertyUpdate::Finalize(const FPropertyValue& propVal)
	{
		lastSentValue = propVal;

		int localChangeId = RelayModel->GetSpacePropertyModel(SpaceConn)->SetLocalPropVal(PropertyId, propVal);
		RelayModel->SendMessage(Cavrnus::CavrnusProtoTranslation::BuildFinalizeLivePropertyUpdateMsg(SpaceConn, LiveUpdaterId, PropertyId, propVal, localChangeId));

		lastUpdatedTimeSec = FPlatformTime::Seconds();
	}

	void CavrnusVirtualPropertyUpdate::Cancel()
	{
		RelayModel->SendMessage(Cavrnus::CavrnusProtoTranslation::BuildCancelLiveUpdateMsg(SpaceConn, LiveUpdaterId));
	}
}

