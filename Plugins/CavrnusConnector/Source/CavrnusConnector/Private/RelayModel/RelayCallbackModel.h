﻿#pragma once

#include <Containers/Map.h>
#include "../../Public/Types/CavrnusBinding.h"
#include "../../Public/Types/CavrnusCallbackTypes.h"
#include "../Translation/CavrnusProtoTranslation.h"
#include "DataState.h"

namespace ServerData
{
	class RelayRemoteMessage;
}

namespace Cavrnus
{
	class CavrnusRelayModel;

	class RelayCallbackModel
	{
	public:
		RelayCallbackModel(CavrnusRelayModel* model);
		virtual ~RelayCallbackModel();

		void HandleServerCallback(int callbackId, const ServerData::RelayRemoteMessage& msg);

		int RegisterLoginPasswordCallback(FCavrnusAuthRecv onSuccess, FCavrnusError onFailure);
		int RegisterLoginGuestCallback(FCavrnusAuthRecv onSuccess, FCavrnusError onFailure);

		void RegisterAuthCallback(FCavrnusAuthRecv onAuth);

		void RegisterBeginLoadingSpaceCallback(FCavrnusSpaceBeginLoading onBeginLoading);
		void HandleSpaceBeginLoading(FString spaceId);

		int RegisterJoinSpaceCallback(FCavrnusSpaceConnected onConnected, FCavrnusError onFailure);

		int RegisterFetchAvailableSpacesCallback(FCavrnusAllSpacesInfoEvent onAllSpacesArrived);

		int RegisterFetchAudioInputs(FCavrnusAvailableInputDevices onRecvDevices);
		int RegisterFetchAudioOutputs(FCavrnusAvailableOutputDevices onRecvDevices);
		int RegisterFetchVideoInputs(FCavrnusAvailableVideoInputDevices onRecvDevices);

	private:
		CavrnusRelayModel* relayModel;

		int currReqId = 0;

		TArray<FCavrnusAuthRecv> AuthCallbacks;
		void HandleAuthRecv(FCavrnusAuthentication auth);

		TMap<int, FCavrnusAuthRecv> LoginPasswordSuccessCallbacks;
		TMap<int, FCavrnusError> LoginPasswordErrorCallbacks;
		void HandleLoginPasswordResponse(int callbackId, ServerData::AuthenticateResp resp);

		TMap<int, FCavrnusAuthRecv> LoginGuestSuccessCallbacks;
		TMap<int, FCavrnusError> LoginGuestErrorCallbacks;
		void HandleLoginGuestResponse(int callbackId, ServerData::AuthenticateGuestResp resp);

		TArray<FCavrnusSpaceBeginLoading> BeginLoadingSpaceCallbacks;
		
		TMap<int, FCavrnusSpaceConnected> JoinSpaceSuccessCallbacks;
		TMap<int, FCavrnusError> JoinSpaceErrorCallbacks;
		void HandleJoinSpaceResponse(int callbackId, ServerData::JoinSpaceFromIdResp resp);

		TMap<int, FCavrnusAllSpacesInfoEvent> AllSpacesInfoCallbacks;
		void HandleJoinableSpacesRecv(int callbackId, ServerData::AllJoinableSpacesResp resp);

		TMap<int, FCavrnusAvailableInputDevices> FetchAudioInputsCallbacks;
		void HandleAudioInputsResponse(int callbackId, ServerData::GetAudioInputDevicesResp resp);

		TMap<int, FCavrnusAvailableOutputDevices> FetchAudioOutputsCallbacks;
		void HandleAudioOutputsResponse(int callbackId, ServerData::GetAudioOutputDevicesResp resp);

		TMap<int, FCavrnusAvailableVideoInputDevices> FetchVideoInputsCallbacks;
		void HandleVideoInputsResponse(int callbackId, ServerData::GetVideoInputDevicesResp resp);
	};

}