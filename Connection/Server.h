#pragma once

#include "steam/steamnetworkingtypes.h"
#include "steam/isteamnetworkingsockets.h"
#include <type_traits>
#include <set>
#include "../4dm.h"

namespace fdm::Connection
{
	using DisconnectCallback = std::add_pointer<void(unsigned int, void*)>::type;
	class Server 
	{
	public:
		enum Status
		{
			OFFLINE = 0x0,
			STARTING = 0x1,
			FAILED_TO_START = 0x2,
			ONLINE = 0x3,
			CLOSED = 0x4,
			CLOSED_ERROR = 0x5
		};
		Status status;
		unsigned int listenSocketHandle;
		unsigned int pollGroupHandle;
		PAD(4);
		ISteamNetworkingSockets* Interface;
		std::set<unsigned int> clients;
		void* userPointer;
		DisconnectCallback disconnectCallback = NULL;
		// yea this class is lacking functions because i just copied it from SwockServer. and this doesnt *actually* exist in 4D Miner executable. Even tho WorldServer does.
	};
}