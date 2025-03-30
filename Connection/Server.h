#pragma once

#include "steam/steamnetworkingtypes.h"
#include "steam/isteamnetworkingsockets.h"
#include <type_traits>
#include <set>
#include "../4dm.h"

namespace fdm::Connection
{
	using DisconnectCallback = std::add_pointer<void(uint32_t, void*)>::type;
	// only available for server
	class Server
	{
	public:
		enum MessageTarget : int
		{
			TARGET_SPECIFIC_CLIENT = 0,
			TARGET_ALL_CLIENTS = 1,
			TARGET_ALL_CLIENTS_EXCEPT = 2,
		};
		enum Status : int
		{
			OFFLINE = 0,
			STARTING = 1,
			FAILED_TO_START = 2,
			ONLINE = 3,
			CLOSED = 4,
			CLOSED_ERROR = 5,
		};
		Status status;
		uint32_t listenSocketHandle;
		uint32_t pollGroupHandle;
		PAD(4);
		ISteamNetworkingSockets* Interface;
		std::set<uint32_t> clients;
		void* userPointer;
		DisconnectCallback disconnectCallback = NULL;
		inline static std::unordered_map<uint32_t, Connection::Server*>& instances = *reinterpret_cast<std::unordered_map<uint32_t, Connection::Server*>*>(getDataAddr((int)Data::Connection::Server::instances));

		~Server()
		{
			reinterpret_cast<void(__thiscall*)(Connection::Server * self)>(getFuncAddr((int)Func::Connection::Server::destr_Server))(this);
		}
		void cleanup()
		{
			return reinterpret_cast<void(__thiscall*)(Connection::Server * self)>(getFuncAddr((int)Func::Connection::Server::cleanup))(this);
		}
		void handleConnectionStatusChange(SteamNetConnectionStatusChangedCallback_t* info)
		{
			return reinterpret_cast<void(__thiscall*)(Connection::Server * self, SteamNetConnectionStatusChangedCallback_t*)>(getFuncAddr((int)Func::Connection::Server::handleConnectionStatusChange))(this, info);
		}
		void kickClient(uint32_t client, int reason)
		{
			return reinterpret_cast<void(__thiscall*)(Connection::Server * self, uint32_t, int)>(getFuncAddr((int)Func::Connection::Server::kickClient))(this, client, reason);
		}
		void sendMessage(const Connection::OutMessage& message, Connection::Server::MessageTarget target, uint32_t client, bool reliable = true)
		{
			return reinterpret_cast<void(__thiscall*)(Connection::Server * self, const Connection::OutMessage&, Connection::Server::MessageTarget, uint32_t, bool)>(getFuncAddr((int)Func::Connection::Server::sendMessage))(this, message, target, client, reliable);
		}
		inline static void connectionStatusChangedCallback(SteamNetConnectionStatusChangedCallback_t* info)
		{
			return reinterpret_cast<void(__fastcall*)(SteamNetConnectionStatusChangedCallback_t*)>(getFuncAddr((int)Func::Connection::Server::connectionStatusChangedCallback))(info);
		}
	};
}
