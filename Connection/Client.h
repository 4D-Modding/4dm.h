#pragma once

#include "steam/steamnetworkingtypes.h"
#include "steam/isteamnetworkingsockets.h"
#include <type_traits>
#include <set>
#include "../4dm.h"

namespace fdm::Connection
{
	class Client
	{
	public:
		enum Status : int
		{
			OFFLINE = 0,
			RESOLVING_HOST = 1,
			CONNECTING = 2,
			CONNECTED = 3,
			FAILED_TO_CONNECT = 4,
			DISCONNECTED_REMOTE = 5,
			DISCONNECTED_LOCAL = 6,
			DISCONNECTED_LOCAL_ERROR = 7,
		};
		Status status;
		std::atomic<bool> resolvingHost;
		PAD(3);
		stl::string address;
		std::thread resolveHostThread;
		uint32_t connectionHandle;
		PAD(4);
		ISteamNetworkingSockets* Interface;
		inline static std::unordered_map<uint32_t, Connection::Client*>& instances = *reinterpret_cast<std::unordered_map<uint32_t, Connection::Client*>*>(getDataAddr((int)Data::Connection::Client::instances));

		void update()
		{
			return reinterpret_cast<void(__thiscall*)(Client * self)>(getFuncAddr((int)Func::Connection::Client::update))(this);
		}
		void resolveHost(stl::string host)
		{
			return reinterpret_cast<void(__thiscall*)(Client * self, stl::string host)>(getFuncAddr((int)Func::Connection::Client::resolveHost))(this, host);
		}
		void cleanup()
		{
			return reinterpret_cast<void(__thiscall*)(Client * self)>(getFuncAddr((int)Func::Connection::Client::cleanup))(this);
		}
		inline static void connectionStatusChangedCallback(SteamNetConnectionStatusChangedCallback_t* info)
		{
			return reinterpret_cast<void(__fastcall*)(SteamNetConnectionStatusChangedCallback_t * info)>(getFuncAddr((int)Func::Connection::Client::connectionStatusChangedCallback))(info);
		}
		void sendMessage(const Connection::OutMessage& message, bool reliable = true)
		{
			SteamNetworkingMessage_t* msg =
				message.createMessage(connectionHandle, reliable ? k_nSteamNetworkingSend_Reliable : k_nSteamNetworkingSend_Unreliable);
			Interface->SendMessages(1, &msg, nullptr);
		}
	};
}
