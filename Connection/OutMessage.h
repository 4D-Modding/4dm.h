#pragma once

#include <steam/steamnetworkingtypes.h>

#include "../4dm.h"

#include "MessageData.h"
#include "../Packet.h"

namespace fdm::Connection
{
	class OutMessage
	{
	public:
		struct HeapMessageData
		{
			std::atomic<int> refCount; // 0x0
			Connection::MessageData data; // 0x4
		};

		inline static void FreeSteamNetworkingMessagePayload(SteamNetworkingMessage_t* pMsg)
		{
			return reinterpret_cast<void(__fastcall*)(SteamNetworkingMessage_t*)>(getFuncAddr((int)Func::Connection::OutMessage::FreeSteamNetworkingMessagePayload))(pMsg);
		}

		inline static void ReleaseHeapMessageData(Connection::MessageData* data)
		{
			reinterpret_cast<void(__fastcall*)(Connection::MessageData * data)>(getFuncAddr((int)Func::Connection::OutMessage::ReleaseHeapMessageData))(data);
		}

		SteamNetworkingMessage_t* createMessage(uint32_t recipient, int sendFlags = k_nSteamNetworkingSend_Reliable) const
		{
			return reinterpret_cast<SteamNetworkingMessage_t * (__thiscall*)(const Connection::OutMessage*, unsigned int, int)>(getFuncAddr((int)Func::Connection::OutMessage::createMessage))(this, recipient, sendFlags);
		}

		std::unique_ptr<MessageData, void(__cdecl*)(MessageData*)> data{ nullptr, ReleaseHeapMessageData };
		uint64_t dataSize = 0;

		void init(uint16_t type, void* data = nullptr, uint64_t dataSize = 0)
		{
			HeapMessageData* msg = (HeapMessageData*)malloc(sizeof(HeapMessageData) + dataSize);

			if (msg == nullptr) return;

			msg->refCount++;
			msg->data.type = type;

			if (data != nullptr)
				memcpy(&msg->data.content, data, dataSize);

			this->data = std::unique_ptr<MessageData, void(__cdecl*)(MessageData*)>(&msg->data, ReleaseHeapMessageData);
			this->dataSize = dataSize + 2;
		}

		OutMessage() : data(nullptr, ReleaseHeapMessageData) {}
		OutMessage(Connection::MessageData* msgData) : data(msgData, ReleaseHeapMessageData) {}
		OutMessage(uint16_t type, void* data = nullptr, uint64_t dataSize = 0)
		{
			init(type, data, dataSize);
		}
		OutMessage(Packet::ClientPacket type, void* data = nullptr, uint64_t dataSize = 0) : OutMessage((uint16_t)type, data, dataSize) {}
		OutMessage(Packet::ServerPacket type, void* data = nullptr, uint64_t dataSize = 0) : OutMessage((uint16_t)type, data, dataSize) {}

		OutMessage(Packet::ClientPacket type, const stl::string& str) : OutMessage((uint16_t)type, (void*)str.c_str(), str.size()) {}
		OutMessage(Packet::ServerPacket type, const stl::string& str) : OutMessage((uint16_t)type, (void*)str.c_str(), str.size()) {}
	};
}
