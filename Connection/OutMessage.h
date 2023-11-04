#pragma once

#include <steam/steamnetworkingtypes.h>

#include "../4dm.h"

#include "MessageData.h"

namespace fdm::Connection
{
	class OutMessage
	{
	public:
		std::unique_ptr<Connection::MessageData, void(__cdecl*)(Connection::MessageData*)> data;
		uint64_t dataSize = 0;

		SteamNetworkingMessage_t* createMessage(unsigned int recipient, int sendFlags)
		{
			return reinterpret_cast<SteamNetworkingMessage_t* (__thiscall*)(Connection::OutMessage*, unsigned int, int)>(FUNC_CONNECTION_OUTMESSAGE_CREATEMESSAGE)(this, recipient, sendFlags);
		}
		OutMessage(unsigned short type, const std::string& content) : data(nullptr, ReleaseHeapMessageData)
		{
			reinterpret_cast<void(__thiscall*)(Connection::OutMessage*, unsigned short type, const std::string& content)>(FUNC_CONNECTION_OUTMESSAGE_OUTMESSAGE)(this, type, content);
		}
		OutMessage() : data(nullptr, ReleaseHeapMessageData){}
		OutMessage(Connection::MessageData* msgData) : data(msgData, ReleaseHeapMessageData){}
		inline static void ReleaseHeapMessageData(Connection::MessageData* data)
		{
			reinterpret_cast<void(__fastcall*)(Connection::MessageData* data)>(FUNC_CONNECTION_OUTMESSAGE_RELEASEHEAPMESSAGEDATA)(data);
		}
	};
}