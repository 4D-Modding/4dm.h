#pragma once

#include "4dm.h"
#include "ChunkLoader.h"

namespace fdm 
{
	class WorldServer : public WorldManager 
	{
	public:
		struct PlayerInfo 
		{
			enum Status
			{
				QUEUED = 0x0,
				JOINING = 0x1,
				REJOINING = 0x2,
				JOINED = 0x3
			};
			std::unique_ptr<Player> player; 
			uuid id; // 0x8
			uint32_t handle; // 0x18
			PAD(0x4);
			std::string displayName; // 0x20
			Status status;
			PAD(0x8);
			Connection::OutMessage skinMessage; // 0x48
			std::unordered_set<Chunk *,std::hash<Chunk *>,std::equal_to<Chunk *>,std::allocator<Chunk *> > chunkList; // 0x60
			double chunkUpdateTime; // 0xA0
			int chunkUpdateCount; // 0xA8
			PAD(0x4);
			double chunkRequestTime; // 0xB0
			int chunkRequestCount; // 0xB8
			PAD(0x4);
			double activityTime; // 0xC0
		};
		inline static const uint32_t DEFAULT_RENDER_DIST = 3; 
		PAD(0x8); // --> boost::uuids::random_generator_pure uuidGenerator
		PAD(0x1); // --> boost::uuids::string_generator uuidParser
		PAD(0x7);
		Connection::Server server; // 0x1E0
		ChunkLoader chunkLoader; // 0x218
		path playerSavePath; // 0x2B8
		nlohmann::json playerSaves; // 0x2D8
		std::unordered_map<uint32_t,WorldServer::PlayerInfo> players; // 0x2E8
		std::unordered_map<uuid, WorldServer::PlayerInfo*> playerIDs;
		std::unordered_map<uuid, WorldServer::PlayerInfo*> entityPlayerIDs;
		glm::ivec4 spawnPoint; // 0x3A8
		int joinedPlayerCount; // 0x3B8
		int joinedPlayerLimit; // 0x3BC
		int queuedPlayerLimit; // 0x3C0
		PAD(0x4);
		std::vector<uint32_t> queue; // 0x3C8
		std::atomic_bool shouldStopLoading; // 0x3E0
		PAD(0x7);
		std::thread chunkLoadingThread; // 0x3E8
		std::mutex newChunksMutex; // 0x3F8
		std::vector<Chunk*> newChunks; // 0x448
		std::mutex newlyLoadedChunkMutex; // 0x460
		std::vector<Chunk*> newlyLoadedChunks; // 0x4B0
		int maxRenderDistance; // 0x4C8
		PAD(0x4);
		double autosaveInterval; // 0x4D0
		double autosaveTime; // 0x4D8
		double restartInterval; // 0x4E0
		double restartTime; // 0x4E8
		double restartCountdownTime; // 0x4F0
		bool restartCountdownStarted; // 0x4F8
		PAD(0x7);
		float inactiveTimeLimit; // 0x500
		int chunkUpdateLimit; // 0x508
		PAD(0x4);
		double chunkUpdateInterval; // 0x510
		int chunkRequestLimit; // 0x518
		PAD(0x4);
		double chunkRequestInterval; // 0x520
		std::unordered_map<glm::i64vec3,nlohmann::json> blockUpdates; // 0x528

		// no function were compiled lol
	};
}
