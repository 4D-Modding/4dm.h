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
			reinterpret_cast<void(__fastcall*)(SteamNetworkingMessage_t * message)>(getFuncAddr((int)Func::Connection::InMessage::InMessageDeleter))(message);
		}

		std::unique_ptr<SteamNetworkingMessage_t, decltype(&InMessageDeleter)> messagePtr{ nullptr, &InMessageDeleter };
		InMessage() {}
		InMessage(SteamNetworkingMessage_t* msg) : messagePtr(msg, &InMessageDeleter) {}

		size_t getDataSize() const { return messagePtr->m_cbSize; }
		size_t getMsgSize() const { return messagePtr->m_cbSize - sizeof(uint16_t); }
		const char* getData() const { return (char*)messagePtr->m_pData; }
		const char* getMsgData() const { return (char*)messagePtr->m_pData + sizeof(uint16_t); }
		stl::string getStrData() const { return  stl::string(getMsgData(), getMsgSize()); }
		uint16_t getPacketType() const { return *(uint16_t*)messagePtr->m_pData; }
		uint32_t getClient() const { return messagePtr->m_conn; }
	};

}
