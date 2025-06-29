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
			std::atomic<int> refCount = 0; // 0x0
			Connection::MessageData data; // 0x4
		};
		inline static void ReleaseHeapMessageData(Connection::MessageData* data)
		{
			reinterpret_cast<void(__fastcall*)(Connection::MessageData * data)>(getFuncAddr((int)Func::Connection::OutMessage::ReleaseHeapMessageData))(data);
		}
		inline static MessageData* CreateHeapMessageData(size_t contentSize)
		{
			HeapMessageData* heapMessageData = (HeapMessageData*)malloc(sizeof(HeapMessageData) + contentSize);
			heapMessageData->refCount = 1;
			return &heapMessageData->data;
		}

		inline static void FreeSteamNetworkingMessagePayload(SteamNetworkingMessage_t* pMsg)
		{
			return reinterpret_cast<void(__fastcall*)(SteamNetworkingMessage_t*)>(getFuncAddr((int)Func::Connection::OutMessage::FreeSteamNetworkingMessagePayload))(pMsg);
		}
		SteamNetworkingMessage_t* createMessage(uint32_t recipient, int sendFlags = k_nSteamNetworkingSend_Reliable) const
		{
			return reinterpret_cast<SteamNetworkingMessage_t * (__thiscall*)(const Connection::OutMessage*, unsigned int, int)>(getFuncAddr((int)Func::Connection::OutMessage::createMessage))(this, recipient, sendFlags);
		}

		using DataOwner = std::unique_ptr<MessageData, decltype(&ReleaseHeapMessageData)>;
		DataOwner data{ nullptr, &ReleaseHeapMessageData };
		uint64_t dataSize = 0;

		OutMessage() { }
		OutMessage(uint16_t type, size_t contentSize) :
			dataSize(sizeof(MessageData) + contentSize),
			data(DataOwner{ CreateHeapMessageData(contentSize), &ReleaseHeapMessageData })
		{
			data->type = type;
		}
		OutMessage(uint16_t type, void* data = nullptr, size_t dataSize = 0) :
			OutMessage(type, dataSize)
		{
			if (data)
			{
				std::memcpy(this->data->content, data, dataSize);
			}
		}
		OutMessage(uint16_t type, const stl::string& str) :
			OutMessage(type, (void*)str.c_str(), str.size()) { }
	};
}
