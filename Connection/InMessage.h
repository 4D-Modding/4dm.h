#pragma once

#include <steam/steamnetworkingtypes.h>
#include "../4dm.h"

namespace fdm::Connection
{
	class InMessage
	{
	public:
		inline static void InMessageDeleter(SteamNetworkingMessage_t* message)
		{
			reinterpret_cast<void(__fastcall*)(SteamNetworkingMessage_t* message)>(FUNC_CONNECTION_INMESSAGE_INMESSAGEDELETER)(message);
		}

		std::unique_ptr<SteamNetworkingMessage_t, void(__cdecl*)(SteamNetworkingMessage_t*)> messagePtr{ nullptr, InMessageDeleter };
		~InMessage()
		{
			reinterpret_cast<void(__thiscall*)(Connection::InMessage* self)>(FUNC_CONNECTION_INMESSAGE_DESTR_INMESSAGE)(this);
		}
		InMessage() : messagePtr(nullptr, InMessageDeleter) {}
		InMessage(SteamNetworkingMessage_t* msg) : messagePtr(msg, InMessageDeleter) {}
	};

}