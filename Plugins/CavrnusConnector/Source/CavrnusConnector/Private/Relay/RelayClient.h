#pragma once

#include "CavrnusRelayLibrary.h"
#include <Containers/UnrealString.h>

class FSocket;

namespace Cavrnus
{
	class RelayClient
	{
	public:
		RelayClient(const FString& ServerAddressIn, int ServerPortIn);
		virtual ~RelayClient();

		bool CreateListenSocket();
		bool Connect();

		bool SendMessage(const ServerData::RelayClientMessage& message);
		bool ReceiveMessage(ServerData::RelayRemoteMessage& message);

		void Disconnect();

		int GetServerPort() const;

	private:
		void HandleSocketError();

		FString ServerAddress;
		int ServerPort;

		FSocket* ListenSocket;
		FSocket* ClientSocket;
	};
}

