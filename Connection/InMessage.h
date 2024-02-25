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
			reinterpret_cast<void(__fastcall*)(SteamNetworkingMessage_t* message)>(getFuncAddr((int)Func::Connection_Nested::InMessage::InMessageDeleter))(message);
		}

		std::unique_ptr<SteamNetworkingMessage_t, void(__cdecl*)(SteamNetworkingMessage_t*)> messagePtr{ nullptr, InMessageDeleter };
		~InMessage()
		{
			reinterpret_cast<void(__thiscall*)(Connection::InMessage* self)>(getFuncAddr((int)Func::Connection_Nested::InMessage::destr_InMessage))(this);
		}
		InMessage() : messagePtr(nullptr, InMessageDeleter) {}
		InMessage(SteamNetworkingMessage_t* msg) : messagePtr(msg, InMessageDeleter) {}
	};

}
