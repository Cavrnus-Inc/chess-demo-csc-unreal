#include "LivePropertyUpdates/CavrnusLivePropertyUpdate.h"
#include "RelayModel/CavrnusVirtualPropertyUpdate.h"
#include "Translation/CavrnusProtoTranslation.h"
#include "Types/CavrnusPropertyValue.h"
#include "Types/PropertyId.h"

UCavrnusLivePropertyUpdate::UCavrnusLivePropertyUpdate() : livePropertyUpdate(nullptr)
{

}

UCavrnusLivePropertyUpdate::~UCavrnusLivePropertyUpdate()
{
	if (livePropertyUpdate)
	{
		delete livePropertyUpdate;
		livePropertyUpdate = nullptr;
	}
}

void UCavrnusLivePropertyUpdate::Cancel()
{
	if (livePropertyUpdate)
		livePropertyUpdate->Cancel();
}

double UCavrnusLivePropertyUpdate::GetLastUpdatedTimeSeconds()
{
	if (livePropertyUpdate)
		return livePropertyUpdate->lastUpdatedTimeSec;
	
	return 0.0f;
}
