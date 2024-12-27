// Copyright(c) Cavrnus. All rights reserved.
#include "CavrnusProtoTranslation.h"

namespace Cavrnus
{

	CavrnusProtoTranslation::CavrnusProtoTranslation()
	{
	}

	CavrnusProtoTranslation::~CavrnusProtoTranslation()
	{

	}

#pragma region Message Builders

	const ServerData::RelayClientMessage CavrnusProtoTranslation::BuildKeepAliveMsg()
	{
		ServerData::KeepAlive keepAlive;

		ServerData::RelayClientMessage msg;
		msg.mutable_keepalive()->CopyFrom(keepAlive);
		return msg;
	}

	const ServerData::RelayClientMessage CavrnusProtoTranslation::BuildUpdateTimeMsg(double currTime)
	{
		ServerData::UpdateTime t;
		t.set_time(currTime);

		ServerData::RelayClientMessage msg;
		msg.mutable_updatetime()->CopyFrom(t);
		return msg;
	}

	const ServerData::RelayClientMessage CavrnusProtoTranslation::BuildAuthenticateWithPassword(int callbackId, const FString& server, const FString& email, const FString& password)
	{
		ServerData::AuthenticateReq req;
		req.set_reqid(callbackId);
		req.set_server(TCHAR_TO_UTF8(*server));
		req.set_email(TCHAR_TO_UTF8(*email));
		req.set_password(TCHAR_TO_UTF8(*password));

		ServerData::RelayClientMessage msg;
		msg.mutable_authenticatereq()->CopyFrom(req);
		return msg;
	}

	const ServerData::RelayClientMessage CavrnusProtoTranslation::BuildAuthenticateGuest(int callbackId, const FString& server, const FString& screenName)
	{
		ServerData::AuthenticateGuestReq req;
		req.set_reqid(callbackId);
		req.set_server(TCHAR_TO_UTF8(*server));
		req.set_screenname(TCHAR_TO_UTF8(*screenName));

		ServerData::RelayClientMessage msg;
		msg.mutable_authenticateguestreq()->CopyFrom(req);
		return msg;
	}

	const ServerData::RelayClientMessage CavrnusProtoTranslation::BuildFetchAvailableSpaces(int callbackId)
	{
		ServerData::AllJoinableSpacesReq req;
		req.set_reqid(callbackId);

		ServerData::RelayClientMessage msg;
		msg.mutable_alljoinablespacesreq()->CopyFrom(req);

		return msg;
	}

	const ServerData::RelayClientMessage CavrnusProtoTranslation::BuildCreateSpaceMsg(int callbackId, const FString& spaceName)
	{
		ServerData::CreateSpaceReq req;
		req.set_reqid(callbackId);
		req.set_newspacename(TCHAR_TO_UTF8(*spaceName));

		ServerData::RelayClientMessage msg;
		msg.mutable_createspacereq()->CopyFrom(req);

		return msg;
	}

	const ServerData::RelayClientMessage CavrnusProtoTranslation::BuildJoinSpaceWithId(int callbackId, const FString& spaceId)
	{
		ServerData::JoinSpaceFromIdReq req;
		req.set_reqid(callbackId);
		req.set_spaceid(TCHAR_TO_UTF8(*spaceId));

		ServerData::RelayClientMessage msg;
		msg.mutable_joinspacefromidreq()->CopyFrom(req);

		return msg;
	}

	const ServerData::RelayClientMessage CavrnusProtoTranslation::BuildExitSpaceMsg(const FCavrnusSpaceConnection& spaceConn)
	{
		ServerData::ShutdownSpaceConnectionReq req;
		req.mutable_spaceconnection()->CopyFrom(ToPb(spaceConn));

		ServerData::RelayClientMessage msg;
		msg.mutable_shutdownspaceconnectionreq()->CopyFrom(req);

		return msg;
	}

	const ServerData::RelayClientMessage CavrnusProtoTranslation::BuildDefinePropMsg(const FCavrnusSpaceConnection& spaceConn, const FAbsolutePropertyId& propertyId, const FPropertyValue& value, const int localChangeId)
	{
		ServerData::DefinePropertyDefaultValue req;
		req.mutable_spaceconn()->CopyFrom(ToPb(spaceConn));
		req.set_propertyid(TCHAR_TO_UTF8(*(FAbsolutePropertyId::GetCombinedName(propertyId))));
		req.mutable_propertyvalue()->CopyFrom(GeneratePropVal(value));
		req.set_localchangeid(localChangeId);

		ServerData::RelayClientMessage msg;
		msg.mutable_definepropertydefaultvalue()->CopyFrom(req);

		return msg;
	}

	const ServerData::RelayClientMessage CavrnusProtoTranslation::BuildUpdatePropMsg(const FCavrnusSpaceConnection& spaceConn, const FAbsolutePropertyId& propertyId, const FPropertyValue& value, const int localChangeId, const FPropertyPostOptions& options)
	{
		ServerData::PostPropertyUpdate req;
		req.mutable_spaceconn()->CopyFrom(ToPb(spaceConn));
		req.set_propertyid(TCHAR_TO_UTF8(*(FAbsolutePropertyId::GetCombinedName(propertyId))));
		req.mutable_propertyvalue()->CopyFrom(GeneratePropVal(value));
		req.set_localchangeid(localChangeId);
		req.set_smooth(options.Smoothed);

		ServerData::RelayClientMessage msg;
		msg.mutable_postpropertyupdate()->CopyFrom(req);

		return msg;
	}

	const ServerData::RelayClientMessage CavrnusProtoTranslation::BuildBeginLivePropertyUpdateMsg(const FCavrnusSpaceConnection& spaceConn, const FString& liveUpdaterId, const FAbsolutePropertyId& propertyId, const FPropertyValue& value, const int localChangeId, const FPropertyPostOptions& options)
	{
		ServerData::BeginTransientPropertyUpdate transMsg;
		transMsg.set_liveupdaterid(TCHAR_TO_UTF8(*liveUpdaterId));
		transMsg.mutable_spaceconn()->CopyFrom(ToPb(spaceConn));
		transMsg.set_propertyid(TCHAR_TO_UTF8(*(FAbsolutePropertyId::GetCombinedName(propertyId))));
		transMsg.mutable_propertyvalue()->CopyFrom(GeneratePropVal(value));
		transMsg.set_localchangeid(localChangeId);
		transMsg.set_smooth(options.Smoothed);

		ServerData::RelayClientMessage msg;
		msg.mutable_begintransientpropertyupdate()->CopyFrom(transMsg);
		return msg;
	}

	const ServerData::RelayClientMessage CavrnusProtoTranslation::BuildContinueLivePropertyUpdateMsg(const FCavrnusSpaceConnection& spaceConn, const FString& liveUpdaterId, const FAbsolutePropertyId& propertyId, const FPropertyValue& value, const int localChangeId, const FPropertyPostOptions& options)
	{
		ServerData::ContinueTransientPropertyUpdate transMsg;
		transMsg.set_liveupdaterid(TCHAR_TO_UTF8(*liveUpdaterId));
		transMsg.mutable_spaceconn()->CopyFrom(ToPb(spaceConn));
		transMsg.set_propertyid(TCHAR_TO_UTF8(*(FAbsolutePropertyId::GetCombinedName(propertyId))));
		transMsg.mutable_propertyvalue()->CopyFrom(GeneratePropVal(value));
		transMsg.set_localchangeid(localChangeId);
		transMsg.set_smooth(options.Smoothed);

		ServerData::RelayClientMessage msg;
		msg.mutable_continuetransientpropertyupdate()->CopyFrom(transMsg);
		return msg;
	}

	const ServerData::RelayClientMessage CavrnusProtoTranslation::BuildFinalizeLivePropertyUpdateMsg(const FCavrnusSpaceConnection& spaceConn, const FString& liveUpdaterId, const FAbsolutePropertyId& propertyId, const FPropertyValue& value, const int localChangeId, const FPropertyPostOptions& options)
	{
		ServerData::FinalizeTransientPropertyUpdate transMsg;
		transMsg.set_liveupdaterid(TCHAR_TO_UTF8(*liveUpdaterId));
		transMsg.mutable_spaceconn()->CopyFrom(ToPb(spaceConn));
		transMsg.set_propertyid(TCHAR_TO_UTF8(*(FAbsolutePropertyId::GetCombinedName(propertyId))));
		transMsg.mutable_propertyvalue()->CopyFrom(GeneratePropVal(value));
		transMsg.set_localchangeid(localChangeId);
		transMsg.set_smooth(options.Smoothed);

		ServerData::RelayClientMessage msg;
		msg.mutable_finalizetransientpropertyupdate()->CopyFrom(transMsg);
		return msg;
	}

	const ServerData::RelayClientMessage CavrnusProtoTranslation::BuildCancelLiveUpdateMsg(const FCavrnusSpaceConnection& spaceConn, const FString& liveUpdaterId)
	{
		ServerData::CancelTransientPropertyUpdate cancelMsg;
		cancelMsg.set_liveupdaterid(TCHAR_TO_UTF8(*liveUpdaterId));
		cancelMsg.mutable_spaceconn()->CopyFrom(ToPb(spaceConn));

		ServerData::RelayClientMessage msg;
		msg.mutable_canceltransientpropertyupdate()->CopyFrom(cancelMsg);
		return msg;
	}

	const ServerData::RelayClientMessage CavrnusProtoTranslation::BuildSetLocalUserMuted(FCavrnusSpaceConnection spaceConn, bool muted)
	{
		ServerData::UpdateLocalUserMuted mutedMsg;
		mutedMsg.set_muted(muted);
		mutedMsg.mutable_spaceconn()->CopyFrom(ToPb(spaceConn));

		ServerData::RelayClientMessage msg;
		msg.mutable_updatelocalusermuted()->CopyFrom(mutedMsg);
		return msg;
	}

	const ServerData::RelayClientMessage CavrnusProtoTranslation::BuildSetLocalUserStreaming(FCavrnusSpaceConnection spaceConn, bool streaming)
	{
		ServerData::UpdateLocalUserStreamState streamStateMsg;
		streamStateMsg.set_streaming(streaming);
		streamStateMsg.mutable_spaceconn()->CopyFrom(ToPb(spaceConn));

		ServerData::RelayClientMessage msg;
		msg.mutable_updatelocaluserstreamstate()->CopyFrom(streamStateMsg);
		return msg;
	}

	const ServerData::RelayClientMessage CavrnusProtoTranslation::BuildRequestAudioInputs(int callbackId)
	{
		ServerData::GetAudioInputDevicesReq req;
		req.set_reqid(callbackId);

		ServerData::RelayClientMessage msg;
		msg.mutable_getaudioinputdevicesreq()->CopyFrom(req);
		return msg;
	}

	const ServerData::RelayClientMessage CavrnusProtoTranslation::BuildRequestAudioOutputs(int callbackId)
	{
		ServerData::GetAudioOutputDevicesReq req;
		req.set_reqid(callbackId);

		ServerData::RelayClientMessage msg;
		msg.mutable_getaudiooutputdevicesreq()->CopyFrom(req);
		return msg;
	}

	const ServerData::RelayClientMessage CavrnusProtoTranslation::BuildRequestVideoInputs(int callbackId)
	{
		ServerData::GetVideoInputDevicesReq req;
		req.set_reqid(callbackId);

		ServerData::RelayClientMessage msg;
		msg.mutable_getvideoinputdevicesreq()->CopyFrom(req);
		return msg;
	}

	const ServerData::RelayClientMessage CavrnusProtoTranslation::BuildSetAudioInput(const FCavrnusInputDevice& device)
	{
		ServerData::SetAudioInputDeviceReq req;
		req.mutable_device()->set_id(TCHAR_TO_UTF8(*device.DeviceId));
		req.mutable_device()->set_name(TCHAR_TO_UTF8(*device.DeviceName));

		ServerData::RelayClientMessage msg;
		msg.mutable_setaudioinputdevicereq()->CopyFrom(req);
		return msg;
	}
	const ServerData::RelayClientMessage CavrnusProtoTranslation::BuildSetAudioOutput(const FCavrnusOutputDevice& device)
	{
		ServerData::SetAudioOutputDeviceReq req;
		req.mutable_device()->set_id(TCHAR_TO_UTF8(*device.DeviceId));
		req.mutable_device()->set_name(TCHAR_TO_UTF8(*device.DeviceName));

		ServerData::RelayClientMessage msg;
		msg.mutable_setaudiooutputdevicereq()->CopyFrom(req);
		return msg;
	}
	const ServerData::RelayClientMessage CavrnusProtoTranslation::BuildSetVideoInput(const FCavrnusVideoInputDevice& device)
	{
		ServerData::SetVideoInputDeviceReq req;
		req.mutable_device()->set_id(TCHAR_TO_UTF8(*device.DeviceId));
		req.mutable_device()->set_name(TCHAR_TO_UTF8(*device.DeviceName));

		ServerData::RelayClientMessage msg;
		msg.mutable_setvideoinputdevicereq()->CopyFrom(req);
		return msg;
	}

	const ServerData::RelayClientMessage CavrnusProtoTranslation::BuildCreateOp(const FCavrnusSpaceConnection& spaceConn, const FString& uniqueObjectId, const FString& instanceId)
	{
		ServerData::PostCreateObject req;
		req.set_newinstanceid(TCHAR_TO_UTF8(*instanceId));
		req.set_uniqueobjectident(TCHAR_TO_UTF8(*uniqueObjectId));
		req.mutable_spaceconn()->CopyFrom(ToPb(spaceConn));

		ServerData::RelayClientMessage msg;
		msg.mutable_postcreateobject()->CopyFrom(req);
		return msg;
	}

	const ServerData::ObjectAdded CavrnusProtoTranslation::BuildObjectAdded(const FCavrnusSpaceConnection& spaceConn, const FString& uniqueObjectId, const FString& instanceId)
	{
		ServerData::ObjectAdded added;
		added.set_objectcreated(TCHAR_TO_UTF8(*uniqueObjectId));
		added.set_propertiescontainer(TCHAR_TO_UTF8(*instanceId));
		added.mutable_spaceconn()->CopyFrom(ToPb(spaceConn));
		//We don't currently use this anywhere
		//added.mutable_createdtime()->CopyFrom();

		return added;
	}

	const ServerData::RelayClientMessage CavrnusProtoTranslation::BuildDestroyOp(const FCavrnusSpaceConnection& spaceConn, const FString& containerName)
	{
		ServerData::PostRemoveObject req;
		req.set_containerid(TCHAR_TO_UTF8(*containerName));
		req.mutable_spaceconn()->CopyFrom(ToPb(spaceConn));

		ServerData::RelayClientMessage msg;
		msg.mutable_postremoveobject()->CopyFrom(req);
		return msg;
	}

	const ServerData::ObjectRemoved CavrnusProtoTranslation::BuildObjectRemoved(const FCavrnusSpaceConnection& spaceConn, const FString& instanceId)
	{
		ServerData::ObjectRemoved added;
		added.set_propertiescontainer(TCHAR_TO_UTF8(*instanceId));
		added.mutable_spaceconn()->CopyFrom(ToPb(spaceConn));
		//We don't currently use this anywhere
		//added.mutable_createdtime()->CopyFrom();

		return added;
	}

	const ServerData::RelayClientMessage CavrnusProtoTranslation::BuildRequestGlobalPermission(const FString& permission)
	{
		ServerData::PermissionStatusReq req;
		req.set_permission(TCHAR_TO_UTF8(*permission));

		ServerData::RelayClientMessage msg;
		msg.mutable_permissionstatusreq()->CopyFrom(req);
		return msg;
	}
	const ServerData::RelayClientMessage CavrnusProtoTranslation::BuildRequestSpacePermission(const FCavrnusSpaceConnection& spaceConn, const FString& permission)
	{
		ServerData::PermissionStatusReq req;
		req.set_permission(TCHAR_TO_UTF8(*permission));
		req.mutable_spaceconn()->CopyFrom(ToPb(spaceConn));

		ServerData::RelayClientMessage msg;
		msg.mutable_permissionstatusreq()->CopyFrom(req);
		return msg;
	}
	const ServerData::RelayClientMessage CavrnusProtoTranslation::BuildRequestFileById(const FString& contentId)
	{
		ServerData::FetchFileByIdReq req;
		req.set_contentid(TCHAR_TO_UTF8(*contentId));

		ServerData::RelayClientMessage msg;
		msg.mutable_fetchfilebyidreq()->CopyFrom(req);
		return msg;
	}
	const ServerData::RelayClientMessage CavrnusProtoTranslation::BuildRequestAllUploadedContent(int callbackId)
	{
		ServerData::FetchAllUploadedContentReq req;
		req.set_reqid(callbackId);

		ServerData::RelayClientMessage msg;
		msg.mutable_fetchalluploadedcontentreq()->CopyFrom(req);
		return msg;
	}
	const ServerData::RelayClientMessage CavrnusProtoTranslation::BuildUploadContent(int callbackId, const FString& filePath, const TMap<FString, FString>& tags)
	{
		ServerData::UploadLocalFileReq req;
		req.set_reqid(callbackId);
		req.set_filepath(TCHAR_TO_UTF8(*filePath));

		for (const TPair<FString, FString>& tag : tags)
		{
			req.add_tagkeys(TCHAR_TO_UTF8(*tag.Key));
			req.add_tagvalues(TCHAR_TO_UTF8(*tag.Value));
		}

		ServerData::RelayClientMessage msg;
		msg.mutable_uploadlocalfilereq()->CopyFrom(req);
		return msg;
	}
#pragma endregion


#pragma region Type Conversions

	FLinearColor CavrnusProtoTranslation::ToFLinearColor(const Common::Color4& color4)
	{
		return FLinearColor(color4.r(), color4.g(), color4.b(), color4.a());
	}

	Common::Color4 CavrnusProtoTranslation::ToProtoColor(const FLinearColor& color)
	{
		Common::Color4 c;
		c.set_r(color.R);
		c.set_g(color.G);
		c.set_b(color.B);
		c.set_a(color.A);
		return c;
	}

	ServerData::TransformPropertyValue CavrnusProtoTranslation::ToProtoTransform(const FTransform& transform)
	{
		Common::Float3 pos;
		pos.set_x(-transform.GetTranslation().Y / (float)100);
		pos.set_y(transform.GetTranslation().Z / (float)100);
		pos.set_z(-transform.GetTranslation().X / (float)100);

		Common::Float3 rot;
		rot.set_x(transform.GetRotation().Euler().Y);
		rot.set_y(transform.GetRotation().Euler().Z - 180);
		rot.set_z(transform.GetRotation().Euler().X);

		Common::Float3 scl;
		scl.set_x(transform.GetScale3D().Y);
		scl.set_y(transform.GetScale3D().Z);
		scl.set_z(transform.GetScale3D().X);

		ServerData::TransformPropertyValue v;
		v.mutable_pos()->CopyFrom(pos);
		v.mutable_rot()->CopyFrom(rot);
		v.mutable_scl()->CopyFrom(scl);
		return v;
	}

	FTransform CavrnusProtoTranslation::ToFTransform(const ServerData::TransformPropertyValue& propVal)
	{
		FVector pos = FVector(-propVal.pos().z() * (float)100, -propVal.pos().x() * (float)100, propVal.pos().y() * (float)100);
		FVector rot = FVector(propVal.rot().z(), propVal.rot().x(), propVal.rot().y() + 180);
		FVector scl = FVector(propVal.scl().z(), propVal.scl().x(), propVal.scl().y());

		FQuat r = FQuat::MakeFromEuler(rot);

		return FTransform(r, pos, scl);
	}

	FVector4 CavrnusProtoTranslation::ToFVector4(const Common::Float4& float4)
	{
		return FVector4(float4.x(), float4.y(), float4.z(), float4.w());
	}

	Common::Float4 CavrnusProtoTranslation::ToProtoVector(const FVector4& vector)
	{
		Common::Float4 v;
		v.set_x(vector.X);
		v.set_y(vector.Y);
		v.set_z(vector.Z);
		v.set_w(vector.W);
		return v;
	}

	FCavrnusSpaceConnection CavrnusProtoTranslation::FromPb(ServerData::CavrnusSpaceConnection InSpaceConnection)
	{
		FString usersContainerPrefix = "users/";
		return FCavrnusSpaceConnection(InSpaceConnection.spaceconnectionid(), UTF8_TO_TCHAR(InSpaceConnection.localuserconnectionid().c_str()), usersContainerPrefix + UTF8_TO_TCHAR(InSpaceConnection.localuserconnectionid().c_str()));
	}

	ServerData::CavrnusSpaceConnection CavrnusProtoTranslation::ToPb(FCavrnusSpaceConnection InSpaceConnection)
	{
		ServerData::CavrnusSpaceConnection SpaceConnection;
		SpaceConnection.set_spaceconnectionid(InSpaceConnection.SpaceConnectionId);
		SpaceConnection.set_localuserconnectionid(TCHAR_TO_UTF8(*InSpaceConnection.LocalUserConnectionId));

		return SpaceConnection;
	}

	FCavrnusSpaceInfo CavrnusProtoTranslation::ToSpaceInfo(ServerData::SpaceInfo space)
	{
		FDateTime lastAccess = FDateTime::MinValue();
		if (space.has_lastaccess())
			lastAccess = FDateTime::FromUnixTimestamp(space.lastaccess().seconds());

		return FCavrnusSpaceInfo(UTF8_TO_TCHAR(space.spaceid().c_str()), UTF8_TO_TCHAR(space.spacename().c_str()), UTF8_TO_TCHAR(space.spacethumbnailurl().c_str()), lastAccess);
	}

	FCavrnusUser CavrnusProtoTranslation::ToCavrnusUser(ServerData::CavrnusUser user, const FCavrnusSpaceConnection& spaceConn)
	{
		FString UserConnectionId = UTF8_TO_TCHAR(user.userconnectionid().c_str());

		return FCavrnusUser(user.islocaluser(), ("users/" + UserConnectionId), UserConnectionId, spaceConn);
	}

	FChatEntry CavrnusProtoTranslation::ToFChatEntry(FString id, ServerData::ChatBase chat)
	{
		FChatEntry entry = FChatEntry();
		entry.ChatId = id;
		entry.ChatDisplayText = UTF8_TO_TCHAR(chat.text().c_str());
		entry.ChatCreatorIsLocalUser = chat.creatorislocal();
		entry.ChatCreatorName = UTF8_TO_TCHAR(chat.creatorname().c_str());
		entry.ChatCreatorPictureUrl = UTF8_TO_TCHAR(chat.creatorpicurl().c_str());
		entry.Complete = chat.complete();
		entry.WasTranslated = chat.wastranslated();
		entry.IsTranscription = chat.chattype() == ServerData::ChatBase_ChatMessageSourceTypeEnum_Transcription;

		FDateTime createdTime = FDateTime::MinValue();
		if (chat.has_createdtime())
			createdTime = FDateTime::FromUnixTimestamp(chat.createdtime().seconds());
		entry.CreatedTime = createdTime;

		return entry;
	}

	const ServerData::RelayClientMessage CavrnusProtoTranslation::BuildPostChatEntry(const FCavrnusSpaceConnection& spaceConn, const FString& chat)
	{
		ServerData::PostChat req;
		req.mutable_spaceconn()->CopyFrom(ToPb(spaceConn));
		req.set_chattext(TCHAR_TO_UTF8(*(chat)));

		ServerData::RelayClientMessage msg;
		msg.mutable_postchat()->CopyFrom(req);

		return msg;
	}
#pragma endregion


} // namespace CavrnusRelay