#pragma once

#include "4dm.h"
#include "ChunkLoader.h"

namespace fdm
{
	// only available for server
	class WorldServer : public WorldManager
	{
	public:
		struct PlayerInfo
		{
			enum Status : int
			{
				QUEUED = 0x0,
				JOINING = 0x1,
				REJOINING = 0x2,
				JOINED = 0x3
			};
			std::unique_ptr<Player> player;
			stl::uuid id; // 0x8
			uint32_t handle; // 0x18
			PAD(0x4);
			stl::string displayName; // 0x20
			Status status;
			PAD(0x4);
			Connection::OutMessage skinMessage; // 0x48
			std::unordered_set<Chunk*> chunkList; // 0x60
			double chunkUpdateTime; // 0xA0
			int chunkUpdateCount; // 0xA8
			PAD(0x4);
			double chunkRequestTime; // 0xB0
			int chunkRequestCount; // 0xB8
			PAD(0x4);
			double activityTime; // 0xC0

			PlayerInfo() {}
			PlayerInfo(WorldServer::PlayerInfo&& other)
			{
				reinterpret_cast<void(__thiscall*)(WorldServer::PlayerInfo * self, WorldServer::PlayerInfo&)>(getFuncAddr((int)Func::WorldServer::PlayerInfo::PlayerInfo))(this, other);
			}
			~PlayerInfo()
			{
				reinterpret_cast<void(__thiscall*)(WorldServer::PlayerInfo * self)>(getFuncAddr((int)Func::WorldServer::PlayerInfo::destr_PlayerInfo))(this);
			}
		};
		inline static const uint8_t DEFAULT_RENDER_DIST = 3;
		PAD(0x8); // --> boost::uuids::random_generator_pure uuidGenerator
		PAD(0x1); // --> boost::uuids::string_generator uuidParser
		PAD(0x7);
		Connection::Server server; // 0x1E0
		ChunkLoader chunkLoader; // 0x218
		stl::path playerSavePath; // 0x2B8
		nlohmann::json playerSaves; // 0x2D8
		std::unordered_map<uint32_t, WorldServer::PlayerInfo> players; // 0x2E8
		std::unordered_map<stl::uuid, WorldServer::PlayerInfo*> playerIDs;
		std::unordered_map<stl::uuid, WorldServer::PlayerInfo*> entityPlayerIDs;
		glm::ivec4 spawnPoint; // 0x3A8
		int joinedPlayerCount; // 0x3B8
		int joinedPlayerLimit; // 0x3BC
		int queuedPlayerLimit; // 0x3C0
		PAD(0x4);
		std::vector<uint32_t> queue; // 0x3C8
		std::atomic<bool> shouldStopLoading; // 0x3E0
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
		double inactiveTimeLimit; // 0x500
		int chunkUpdateLimit; // 0x508
		PAD(0x4);
		double chunkUpdateInterval; // 0x510
		int chunkRequestLimit; // 0x518
		PAD(0x4);
		double chunkRequestInterval; // 0x520
		std::unordered_map<glm::i64vec3, nlohmann::json> blockUpdates; // 0x528

		WorldServer() {}
		WorldServer(const stl::path& worldsPath, const stl::path& settingsPath, const stl::path& biomeInfoPath)
		{
			reinterpret_cast<void(__thiscall*)(WorldServer * self, const stl::path&, const stl::path&, const stl::path&)>(getFuncAddr((int)Func::WorldServer::WorldServer))(this, worldsPath, settingsPath, biomeInfoPath);
		}
		~WorldServer() override
		{
			reinterpret_cast<void(__thiscall*)(WorldServer * self)>(getFuncAddr((int)Func::WorldServer::destr_WorldServer))(this);
		}
		bool addEntityToChunk(std::unique_ptr<Entity>& entity, Chunk* c) override
		{
			return reinterpret_cast<bool(__thiscall*)(WorldServer * self, std::unique_ptr<Entity>&, Chunk*)>(getFuncAddr((int)Func::WorldServer::addEntityToChunk))(this, entity, c);
		}
		World::Type getType() override
		{
			return reinterpret_cast<World::Type(__thiscall*)(WorldServer * self)>(getFuncAddr((int)Func::WorldServer::getType))(this);
		}
		bool giveItem(WorldServer::PlayerInfo* playerInfo, std::unique_ptr<Item>& item)
		{
			return reinterpret_cast<bool(__thiscall*)(WorldServer * self, WorldServer::PlayerInfo*, std::unique_ptr<Item>&)>(getFuncAddr((int)Func::WorldServer::giveItem))(this, playerInfo, item);
		}
		void handleMessage(const Connection::InMessage& message, double dt)
		{
			return reinterpret_cast<void(__thiscall*)(WorldServer * self, const Connection::InMessage&, double)>(getFuncAddr((int)Func::WorldServer::handleMessage))(this, message, dt);
		}
		void handlePlayerDeath(Player* player, std::string_view reason) override
		{
			return reinterpret_cast<void(__thiscall*)(WorldServer * self, Player*, std::string_view)>(getFuncAddr((int)Func::WorldServer::handlePlayerDeath))(this, player, reason);
		}
		bool handlePlayerLogin(const Connection::InMessage& message)
		{
			return reinterpret_cast<bool(__thiscall*)(WorldServer * self, const Connection::InMessage&)>(getFuncAddr((int)Func::WorldServer::handlePlayerLogin))(this, message);
		}
		void loadChunk(Chunk* c)
		{
			return reinterpret_cast<void(__thiscall*)(WorldServer * self, Chunk*)>(getFuncAddr((int)Func::WorldServer::loadChunk))(this, c);
		}
		void loadChunks()
		{
			return reinterpret_cast<void(__thiscall*)(WorldServer * self)>(getFuncAddr((int)Func::WorldServer::loadChunks))(this);
		}
		void localPlayerInit(Player* player)
		{
			return reinterpret_cast<void(__thiscall*)(WorldServer * self, Player*)>(getFuncAddr((int)Func::WorldServer::localPlayerInit))(this, player);
		}
		bool removePlayer(std::unordered_map<uint32_t, WorldServer::PlayerInfo>::iterator entry, bool endConnection)
		{
			return reinterpret_cast<bool(__thiscall*)(WorldServer * self, std::unordered_map<uint32_t, WorldServer::PlayerInfo>::iterator, bool)>(getFuncAddr((int)Func::WorldServer::removePlayer))(this, entry, endConnection);
		}
		void removePlayerChunks(WorldServer::PlayerInfo* playerInfo)
		{
			return reinterpret_cast<void(__thiscall*)(WorldServer * self, WorldServer::PlayerInfo*)>(getFuncAddr((int)Func::WorldServer::removePlayerChunks))(this, playerInfo);
		}
		void savePlayerData()
		{
			return reinterpret_cast<void(__thiscall*)(WorldServer * self)>(getFuncAddr((int)Func::WorldServer::savePlayerData))(this);
		}
		void saveWorldData()
		{
			return reinterpret_cast<void(__thiscall*)(WorldServer * self)>(getFuncAddr((int)Func::WorldServer::saveWorldData))(this);
		}
		void sendEquippedItemUpdate(WorldServer::PlayerInfo* c)
		{
			return reinterpret_cast<void(__thiscall*)(WorldServer * self, WorldServer::PlayerInfo*)>(getFuncAddr((int)Func::WorldServer::sendEquippedItemUpdate))(this, c);
		}
		void sendEquippedItemUpdate(Chunk* c, WorldServer::PlayerInfo* playerInfo)
		{
			return reinterpret_cast<void(__thiscall*)(WorldServer * self, Chunk*, WorldServer::PlayerInfo*)>(getFuncAddr((int)Func::WorldServer::sendEquippedItemUpdateA))(this, c, playerInfo);
		}
		void sendMessage(const Connection::OutMessage& message, Chunk* c, bool reliable)
		{
			return reinterpret_cast<void(__thiscall*)(WorldServer * self, const Connection::OutMessage&, Chunk*, bool)>(getFuncAddr((int)Func::WorldServer::sendMessage))(this, message, c, reliable);
		}
		void sendMessageOtherPlayers(const Connection::OutMessage& message, Chunk* c, WorldServer::PlayerInfo* playerInfo, bool reliable)
		{
			return reinterpret_cast<void(__thiscall*)(WorldServer * self, const Connection::OutMessage&, Chunk*, WorldServer::PlayerInfo*, bool)>(getFuncAddr((int)Func::WorldServer::sendMessageOtherPlayers))(this, message, c, playerInfo, reliable);
		}
		void sendMessagePlayer(const Connection::OutMessage& message, WorldServer::PlayerInfo* playerInfo, bool reliable)
		{
			return reinterpret_cast<void(__thiscall*)(WorldServer * self, const Connection::OutMessage&, WorldServer::PlayerInfo*, bool)>(getFuncAddr((int)Func::WorldServer::sendMessagePlayer))(this, message, playerInfo, reliable);
		}
		void setBlockUpdate(const glm::ivec4& block, uint8_t value) override
		{
			return reinterpret_cast<void(__thiscall*)(WorldServer * self, const glm::ivec4&, uint8_t)>(getFuncAddr((int)Func::WorldServer::setBlockUpdate))(this, block, value);
		}
		void setDifficultyLocal(Player* player, int difficulty)
		{
			return reinterpret_cast<void(__thiscall*)(WorldServer * self, Player*, int)>(getFuncAddr((int)Func::WorldServer::setDifficultyLocal))(this, player, difficulty);
		}
		void setRenderDistanceLocal(Player* player, uint8_t distance)
		{
			return reinterpret_cast<void(__thiscall*)(WorldServer * self, Player*, uint8_t)>(getFuncAddr((int)Func::WorldServer::setRenderDistanceLocal))(this, player, distance);
		}
		void unloadChunk(Chunk* c)
		{
			return reinterpret_cast<void(__thiscall*)(WorldServer * self, Chunk*)>(getFuncAddr((int)Func::WorldServer::unloadChunk))(this, c);
		}
		void updateBackend(double dt)
		{
			return reinterpret_cast<void(__thiscall*)(WorldServer * self, double)>(getFuncAddr((int)Func::WorldServer::updateBackend))(this, dt);
		}
		void updateChunk(const glm::i64vec3& coords, WorldServer::PlayerInfo* playerInfo)
		{
			return reinterpret_cast<void(__thiscall*)(WorldServer * self, const glm::i64vec3&, WorldServer::PlayerInfo*)>(getFuncAddr((int)Func::WorldServer::updateChunk))(this, coords, playerInfo);
		}
		void updateChunks(WorldServer::PlayerInfo* playerInfo)
		{
			return reinterpret_cast<void(__thiscall*)(WorldServer * self, WorldServer::PlayerInfo*)>(getFuncAddr((int)Func::WorldServer::updateChunks))(this, playerInfo);
		}
		void updateLocal(StateManager& s, Player* player, double dt)
		{
			return reinterpret_cast<void(__thiscall*)(WorldServer * self, StateManager&, Player*, double)>(getFuncAddr((int)Func::WorldServer::updateLocal))(this, s, player, dt);
		}
		void updateNewlyLoadedChunks()
		{
			return reinterpret_cast<void(__thiscall*)(WorldServer * self)>(getFuncAddr((int)Func::WorldServer::updateNewlyLoadedChunks))(this);
		}
		inline static void disconnectCallback(uint32_t connHandle, void* userPtr)
		{
			return reinterpret_cast<void(__fastcall*)(uint32_t, void*)>(getFuncAddr((int)Func::WorldServer::disconnectCallback))(connHandle, userPtr);
		}
	};
}
