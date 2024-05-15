﻿#include "RelayModel/RelayCallbackModel.h"
#include "CoreMinimal.h"
#include "RelayModel/CavrnusRelayModel.h"
#include "CavrnusConnectorModule.h"
#include "Types\CavrnusRemoteContent.h"

namespace Cavrnus
{
	RelayCallbackModel::RelayCallbackModel(CavrnusRelayModel* model)
	{
		relayModel = model;
	}

	RelayCallbackModel::~RelayCallbackModel()
	{
	}

	void RelayCallbackModel::HandleServerCallback(int callbackId, const ServerData::RelayRemoteMessage& msg)
	{
		switch (msg.Msg_case())
		{
		case ServerData::RelayRemoteMessage::kAuthenticateResp:
			HandleLoginPasswordResponse(callbackId, msg.authenticateresp());
			break;
		case ServerData::RelayRemoteMessage::kAuthenticateGuestResp:
			HandleLoginGuestResponse(callbackId, msg.authenticateguestresp());
			break;
		case ServerData::RelayRemoteMessage::kJoinSpaceFromIdResp:
			HandleJoinSpaceResponse(callbackId, msg.joinspacefromidresp());
			break;
		case ServerData::RelayRemoteMessage::kGetAudioInputDevicesResp:
			HandleAudioInputsResponse(callbackId, msg.getaudioinputdevicesresp());
			break;
		case ServerData::RelayRemoteMessage::kGetAudioOutputDevicesResp:
			HandleAudioOutputsResponse(callbackId, msg.getaudiooutputdevicesresp());
			break;
		case ServerData::RelayRemoteMessage::kGetVideoInputDevicesResp:
			HandleVideoInputsResponse(callbackId, msg.getvideoinputdevicesresp());
			break;
		case ServerData::RelayRemoteMessage::kAllJoinableSpacesResp:
			HandleJoinableSpacesRecv(callbackId, msg.alljoinablespacesresp());
			break;
		case ServerData::RelayRemoteMessage::kFetchAllUploadedContentResp:
			HandleAllRemoteContentRecv(callbackId, msg.fetchalluploadedcontentresp());
			break;
		case ServerData::RelayRemoteMessage::kUploadLocalFileResp:
			HandleUploadComplete(callbackId, msg.uploadlocalfileresp());
			break;
		default:
			UE_LOG(LogCavrnusConnector, Warning, TEXT("Unhandled server message, message type: %d"), static_cast<int>(msg.Msg_case()));
			break;
		}
	}

	void RelayCallbackModel::HandleAuthRecv(FCavrnusAuthentication auth)
	{
		for (int i = 0; i < AuthCallbacks.Num(); i++) 
		{
			(*AuthCallbacks[i])(auth);
		}
		AuthCallbacks.Empty();
	}

	int RelayCallbackModel::RegisterLoginPasswordCallback(CavrnusAuthRecv onSuccess, CavrnusError onFailure)
	{
		int reqId = ++currReqId;

		CavrnusAuthRecv* callback = new CavrnusAuthRecv(onSuccess);
		LoginPasswordSuccessCallbacks.Add(reqId, callback);

		CavrnusError* errorCallback = new CavrnusError(onFailure);
		LoginPasswordErrorCallbacks.Add(reqId, errorCallback);

		return reqId;
	}

	void RelayCallbackModel::HandleLoginPasswordResponse(int callbackId, ServerData::AuthenticateResp resp)
	{
		if (resp.has_auth())
		{
			FString token = resp.auth().token().c_str();

			FCavrnusAuthentication auth = FCavrnusAuthentication(token);
			HandleAuthRecv(auth);

			relayModel->GetDataState()->CurrentAuthentication = new FCavrnusAuthentication(token);

			UE_LOG(LogCavrnusConnector, Log, TEXT("[AUTH SUCCESS]"));

			if (LoginPasswordSuccessCallbacks.Contains(callbackId))
				(*LoginPasswordSuccessCallbacks[callbackId])(auth);
		}
		else
		{
			FString error = resp.error().c_str();
			UE_LOG(LogCavrnusConnector, Log, TEXT("[AUTH FAILURE]: %s"), *error);

			if (LoginPasswordErrorCallbacks.Contains(callbackId))
				(*LoginPasswordErrorCallbacks[callbackId])(error);
		}

		LoginPasswordSuccessCallbacks.Remove(callbackId);
		LoginPasswordErrorCallbacks.Remove(callbackId);

	}

	int RelayCallbackModel::RegisterLoginGuestCallback(CavrnusAuthRecv onSuccess, CavrnusError onFailure)
	{
		int reqId = ++currReqId;

		CavrnusAuthRecv* callback = new CavrnusAuthRecv(onSuccess);
		LoginGuestSuccessCallbacks.Add(reqId, callback);

		CavrnusError* errorCallback = new CavrnusError(onFailure);
		LoginGuestErrorCallbacks.Add(reqId, errorCallback);

		return reqId;
	}

	void RelayCallbackModel::RegisterAuthCallback(CavrnusAuthRecv onAuth)
	{
		if (relayModel->GetDataState()->CurrentAuthentication != nullptr)
		{
			onAuth(*relayModel->GetDataState()->CurrentAuthentication);
		}
		else 
		{
			CavrnusAuthRecv* callback = new CavrnusAuthRecv(onAuth);
			AuthCallbacks.Add(callback);
		}
		
	}

	void RelayCallbackModel::HandleLoginGuestResponse(int callbackId, ServerData::AuthenticateGuestResp resp)
	{
		if (resp.has_auth())
		{
			FString token = resp.auth().token().c_str();

			FCavrnusAuthentication auth = FCavrnusAuthentication(token);
			HandleAuthRecv(auth);

			relayModel->GetDataState()->CurrentAuthentication = new FCavrnusAuthentication(token);

			UE_LOG(LogCavrnusConnector, Log, TEXT("[AUTH SUCCESS]"));

			if (LoginGuestSuccessCallbacks.Contains(callbackId))
				(*LoginGuestSuccessCallbacks[callbackId])(auth);
		}
		else
		{
			FString error = resp.error().c_str();
			UE_LOG(LogCavrnusConnector, Log, TEXT("[AUTH FAILURE]: %s"), *error);

			if (LoginGuestErrorCallbacks.Contains(callbackId))
				(*LoginGuestErrorCallbacks[callbackId])(error);
		}

		LoginGuestSuccessCallbacks.Remove(callbackId);
		LoginGuestErrorCallbacks.Remove(callbackId);
	}

	void RelayCallbackModel::RegisterBeginLoadingSpaceCallback(CavrnusSpaceBeginLoading onBeginLoading)
	{
		CavrnusSpaceBeginLoading* CallbackPtr = new CavrnusSpaceBeginLoading(onBeginLoading);
		BeginLoadingSpaceCallbacks.Add(CallbackPtr);
	}

	void RelayCallbackModel::HandleSpaceBeginLoading(FString spaceId)
	{
		for (int i = 0; i < BeginLoadingSpaceCallbacks.Num(); i++) 
		{
			(*BeginLoadingSpaceCallbacks[i])(spaceId);
		}
		BeginLoadingSpaceCallbacks.Empty();
	}

	int RelayCallbackModel::RegisterJoinSpaceCallback(CavrnusSpaceConnected onConnected, CavrnusError onFailure)
	{
		int reqId = ++currReqId;

		CavrnusSpaceConnected* CallbackPtr = new CavrnusSpaceConnected(onConnected);
		CavrnusError* ErrorPtr = new CavrnusError(onFailure);

		JoinSpaceSuccessCallbacks.Add(reqId, CallbackPtr);
		JoinSpaceErrorCallbacks.Add(reqId, ErrorPtr);

		return reqId;
	}

	int RelayCallbackModel::RegisterFetchAvailableSpacesCallback(CavrnusAllSpacesInfoEvent onAllSpacesArrived)
	{
		int reqId = ++currReqId;

		CavrnusAllSpacesInfoEvent* callback = new CavrnusAllSpacesInfoEvent(onAllSpacesArrived);
		AllSpacesInfoCallbacks.Add(reqId, callback);

		return reqId;
	}

	void RelayCallbackModel::HandleJoinableSpacesRecv(int callbackId, ServerData::AllJoinableSpacesResp resp)
	{
		TArray<FCavrnusSpaceInfo> AvailableSpaces;

		for (int i = 0; i < resp.availablespaces().size(); i++)
		{
			AvailableSpaces.Add(CavrnusProtoTranslation::ToSpaceInfo(resp.availablespaces()[i]));
		}

		if (AllSpacesInfoCallbacks.Contains(callbackId))
			(*AllSpacesInfoCallbacks[callbackId])(AvailableSpaces);

		AllSpacesInfoCallbacks.Remove(callbackId);
	}

	void RelayCallbackModel::HandleJoinSpaceResponse(int callbackId, ServerData::JoinSpaceFromIdResp resp)
	{
		if (resp.Resp_case() == ServerData::JoinSpaceFromIdResp::kSpaceConn)
		{
			FCavrnusSpaceConnection spaceConn = Cavrnus::CavrnusProtoTranslation::FromPb(resp.spaceconn());

			relayModel->GetDataState()->AddSpaceConnection(spaceConn);

			UE_LOG(LogCavrnusConnector, Log, TEXT("[JOIN SPACE SUCCESS]"));
			if (JoinSpaceSuccessCallbacks.Contains(callbackId))
				(*JoinSpaceSuccessCallbacks[callbackId])(FCavrnusSpaceConnection(spaceConn));
		}
		else
		{
			FString error = resp.error().c_str();
			UE_LOG(LogCavrnusConnector, Log, TEXT("[JOIN SPACE FAILURE]: %s"), *error);
			if (JoinSpaceErrorCallbacks.Contains(callbackId))
				(*JoinSpaceErrorCallbacks[callbackId])(error);
		}

		JoinSpaceSuccessCallbacks.Remove(callbackId);
		JoinSpaceErrorCallbacks.Remove(callbackId);
	}

	int RelayCallbackModel::RegisterFetchAudioInputs(CavrnusAvailableInputDevices onRecvDevices)
	{
		int reqId = ++currReqId;

		CavrnusAvailableInputDevices* callback = new CavrnusAvailableInputDevices(onRecvDevices);
		FetchAudioInputsCallbacks.Add(reqId, callback);

		return reqId;
	}

	void RelayCallbackModel::HandleAudioInputsResponse(int callbackId, ServerData::GetAudioInputDevicesResp resp)
	{
		TArray<FCavrnusInputDevice> devices;

		const auto& devices_field = resp.devices();
		for (int i = 0; i < devices_field.devices_size(); ++i)
		{
			const ServerData::RtcAudioInputDevice& device = devices_field.devices(i);
			FCavrnusInputDevice item = FCavrnusInputDevice(device.name().c_str(), device.id().c_str());

			devices.Add(item);
		}

		if (FetchAudioInputsCallbacks.Contains(callbackId))
			(*FetchAudioInputsCallbacks[callbackId])(devices);
	}

	int RelayCallbackModel::RegisterFetchAudioOutputs(CavrnusAvailableOutputDevices onRecvDevices)
	{
		int reqId = ++currReqId;

		CavrnusAvailableOutputDevices* callback = new CavrnusAvailableOutputDevices(onRecvDevices);
		FetchAudioOutputsCallbacks.Add(reqId, callback);

		return reqId;
	}

	void RelayCallbackModel::HandleAudioOutputsResponse(int callbackId, ServerData::GetAudioOutputDevicesResp resp)
	{
		TArray<FCavrnusOutputDevice> devices;

		const auto& devices_field = resp.devices();
		for (int i = 0; i < devices_field.devices_size(); ++i)
		{
			const ServerData::RtcAudioOutputDevice& device = devices_field.devices(i);
			FCavrnusOutputDevice item = FCavrnusOutputDevice(device.name().c_str(), device.id().c_str());

			devices.Add(item);
		}

		if (FetchAudioOutputsCallbacks.Contains(callbackId))
			(*FetchAudioOutputsCallbacks[callbackId])(devices);
	}

	int RelayCallbackModel::RegisterFetchVideoInputs(CavrnusAvailableVideoInputDevices onRecvDevices)
	{
		int reqId = ++currReqId;

		CavrnusAvailableVideoInputDevices* callback = new CavrnusAvailableVideoInputDevices(onRecvDevices);
		FetchVideoInputsCallbacks.Add(reqId, callback);

		return reqId;
	}

	void RelayCallbackModel::HandleVideoInputsResponse(int callbackId, ServerData::GetVideoInputDevicesResp resp)
	{
		TArray<FCavrnusVideoInputDevice> devices;

		const auto& devices_field = resp.devices();
		for (int i = 0; i < devices_field.devices_size(); ++i)
		{
			const ServerData::RtcVideoInputDevice& device = devices_field.devices(i);
			FCavrnusVideoInputDevice item = FCavrnusVideoInputDevice(device.name().c_str(), device.id().c_str());

			devices.Add(item);
		}

		if (FetchVideoInputsCallbacks.Contains(callbackId))
			(*FetchVideoInputsCallbacks[callbackId])(devices);
	}

	int RelayCallbackModel::RegisterFetchAllAvailableContent(CavrnusRemoteContentFunction onfetchedContent)
	{
		int reqId = ++currReqId;

		CavrnusRemoteContentFunction* CallbackPtr = new CavrnusRemoteContentFunction(onfetchedContent);

		AllRemoteContentCallbacks.Add(reqId, CallbackPtr);

		return reqId;
	}

	void RelayCallbackModel::HandleAllRemoteContentRecv(int callbackId, ServerData::FetchAllUploadedContentResp resp)
	{
		TArray<FCavrnusRemoteContent> remoteContent;
		for (int i = 0; i < resp.availablecontent().size(); i++) 
		{
			TMap<FString, FString> tags;
			for (int j = 0; j < resp.availablecontent()[i].tagkeys_size(); j++) 
			{
				tags.Add(resp.availablecontent()[i].tagkeys()[j].c_str(), resp.availablecontent()[i].tagvalues()[j].c_str());
			}

			remoteContent.Add(FCavrnusRemoteContent(resp.availablecontent()[i].id().c_str(), resp.availablecontent()[i].name().c_str(), resp.availablecontent()[i].filename().c_str(), resp.availablecontent()[i].thumbnailurl().c_str(), tags));
		}

		if (AllRemoteContentCallbacks.Contains(callbackId))
		{
			(*AllRemoteContentCallbacks[callbackId])(remoteContent);
			AllRemoteContentCallbacks.Remove(callbackId);
		}
	}

	int RelayCallbackModel::RegisterUploadContent(CavrnusUploadCompleteFunction onUploadComplete)
	{
		int reqId = ++currReqId;

		CavrnusUploadCompleteFunction* CallbackPtr = new CavrnusUploadCompleteFunction(onUploadComplete);

		AllUploadContentCallbacks.Add(reqId, CallbackPtr);

		return reqId;
	}

	void RelayCallbackModel::HandleUploadComplete(int callbackId, ServerData::UploadLocalFileResp resp)
	{
		TMap<FString, FString> tags;
		for (int j = 0; j < resp.uploadedcontent().tagkeys_size(); j++)
		{
			tags.Add(resp.uploadedcontent().tagkeys()[j].c_str(), resp.uploadedcontent().tagvalues()[j].c_str());
		}

		FCavrnusRemoteContent remoteContent = FCavrnusRemoteContent(resp.uploadedcontent().id().c_str(), resp.uploadedcontent().name().c_str(), resp.uploadedcontent().filename().c_str(), resp.uploadedcontent().thumbnailurl().c_str(), tags);

		if (AllUploadContentCallbacks.Contains(callbackId))
		{
			(*AllUploadContentCallbacks[callbackId])(remoteContent);
			AllUploadContentCallbacks.Remove(callbackId);
		}
	}
}