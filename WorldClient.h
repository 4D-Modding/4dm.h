#pragma once

#include "4dm.h"
#include "WorldManager.h"

namespace fdm 
{
	class WorldClient : public WorldManager 
	{
	public:
		inline static const float MESH_GEN_DELAY = NULL; 
		PAD(0x1); // --> boost::uuids::string_generator uuidParser
		PAD(0x7);
		std::shared_ptr<Connection::Client> client; // 0x1D8
		std::atomic_bool chunksReady; // 0x1E8
		std::atomic_bool shouldStopLoading; // 0x1E9
		PAD(0x6);
		std::vector<Chunk*> newChunks; // 0x1F0
		std::mutex updatedNeighborsMutex; // 0x208
		std::vector<Chunk*> updatedNeighbors; // 0x258
		double oldestChunkTime; // 0x270
		double lastUpdateTime; // 0x278
		std::thread meshGeneratingThread; // 0x280
		std::thread meshRegeneratingThread; // 0x290

		~WorldClient() override
		{
			reinterpret_cast<void(__thiscall*)(WorldClient* self)>(FUNC_WORLDCLIENT_DESTR_WORLDCLIENT)(this);
		}
		bool addEntityToChunk(std::unique_ptr<Entity>& entity, Chunk* c) override
		{
			return reinterpret_cast<bool (__thiscall*)(WorldClient* self, std::unique_ptr<Entity>& entity, Chunk* c)>(FUNC_WORLDCLIENT_ADDENTITYTOCHUNK)(this, entity, c);
		}
		void localPlayerEvent(Player* player, Packet::ClientPacket eventType, __int64 eventValue, void* data) override
		{
			return reinterpret_cast<void (__thiscall*)(WorldClient* self, Player* player, Packet::ClientPacket eventType, __int64 eventValue, void* data)>(FUNC_WORLDCLIENT_LOCALPLAYEREVENT)(this, player, eventType, eventValue, data);
		}
		void updateLocal(StateManager& s, Player* player, double dt) override
		{
			return reinterpret_cast<void (__thiscall*)(WorldClient* self, StateManager& s, Player* player, double dt)>(FUNC_WORLDCLIENT_UPDATELOCAL)(this, s, player, dt);
		}
		void setRenderDistanceLocal(Player* player, unsigned char distance) override
		{
			return reinterpret_cast<void (__thiscall*)(WorldClient* self, Player* player, unsigned char distance)>(FUNC_WORLDCLIENT_SETRENDERDISTANCELOCAL)(this, player, distance);
		}
		void setSkinVisibility(bool visible) override
		{
			return reinterpret_cast<void (__thiscall*)(WorldClient* self, bool visible)>(FUNC_WORLDCLIENT_SETSKINVISIBILITY)(this, visible);
		}
		void localPlayerInit(Player* player) override
		{
			return reinterpret_cast<void (__thiscall*)(WorldClient* self, Player* player)>(FUNC_WORLDCLIENT_LOCALPLAYERINIT)(this, player);
		}
		void localPlayerRespawn(StateManager& s, Player* player) override
		{
			return reinterpret_cast<void (__thiscall*)(WorldClient* self, StateManager& s, Player* player)>(FUNC_WORLDCLIENT_LOCALPLAYERRESPAWN)(this, s, player);
		}
		void sendChatMessage(Player* player, const std::string& message) override
		{
			return reinterpret_cast<void (__thiscall*)(WorldClient* self, Player* player, const std::string& message)>(FUNC_WORLDCLIENT_SENDCHATMESSAGE)(this, player, message);
		}
		void updatePhysics(Player* player, double dt) 
		{
			return reinterpret_cast<void (__thiscall*)(WorldClient* self, Player* player, double dt)>(FUNC_WORLDCLIENT_UPDATEPHYSICS)(this, player, dt);
		}
		bool handleWorldMessage(const Connection::InMessage& message, Player* player) 
		{
			return reinterpret_cast<bool (__thiscall*)(WorldClient* self, const Connection::InMessage& message, Player* player)>(FUNC_WORLDCLIENT_HANDLEWORLDMESSAGE)(this, message, player);
		}
		void handleLightingOptionsUpdate() override
		{
			return reinterpret_cast<void (__thiscall*)(WorldClient* self)>(FUNC_WORLDCLIENT_HANDLELIGHTINGOPTIONSUPDATE)(this);
		}
		bool updateChunks(Player* player) 
		{
			return reinterpret_cast<bool (__thiscall*)(WorldClient* self, Player* player)>(FUNC_WORLDCLIENT_UPDATECHUNKS)(this, player);
		}
		void updateChunk(const glm::i64vec3& coords, float theta, const glm::vec3& playerPos, unsigned char renderDist) 
		{
			return reinterpret_cast<void (__thiscall*)(WorldClient* self, const glm::i64vec3& coords, float theta, const glm::vec3& playerPos, unsigned char renderDist)>(FUNC_WORLDCLIENT_UPDATECHUNK)(this, coords, theta, playerPos, renderDist);
		}
		void generateChunkMeshes() 
		{
			return reinterpret_cast<void (__thiscall*)(WorldClient* self)>(FUNC_WORLDCLIENT_GENERATECHUNKMESHES)(this);
		}
		void updateChunkCacheAndMesh(Chunk* c, bool useSmoothLighting, bool useShadows, bool useLights) 
		{
			return reinterpret_cast<void (__thiscall*)(WorldClient* self, Chunk* c, bool useSmoothLighting, bool useShadows, bool useLights)>(FUNC_WORLDCLIENT_UPDATECHUNKCACHEANDMESH)(this, c, useSmoothLighting, useShadows, useLights);
		}
		void updateChunkCache(Chunk* c, bool useSmoothLighting, bool useShadows) 
		{
			return reinterpret_cast<void (__thiscall*)(WorldClient* self, Chunk* c, bool useSmoothLighting, bool useShadows)>(FUNC_WORLDCLIENT_UPDATECHUNKCACHE)(this, c, useSmoothLighting, useShadows);
		}
		void regenerateAllChunkMeshes() 
		{
			return reinterpret_cast<void (__thiscall*)(WorldClient* self)>(FUNC_WORLDCLIENT_REGENERATEALLCHUNKMESHES)(this);
		}
		void joinAllChunkLoadingThreads() 
		{
			return reinterpret_cast<void (__thiscall*)(WorldClient* self)>(FUNC_WORLDCLIENT_JOINALLCHUNKLOADINGTHREADS)(this);
		}
		void handleMessage(const Connection::InMessage& message, Player* player) 
		{
			return reinterpret_cast<void (__thiscall*)(WorldClient* self, const Connection::InMessage& message, Player* player)>(FUNC_WORLDCLIENT_HANDLEMESSAGE)(this, message, player);
		}
		inline static bool inventoryUpdateCallback(nlohmann::json& action, void* user) 
		{
			return reinterpret_cast<bool (__fastcall*)(nlohmann::json& action, void* user)>(FUNC_WORLDCLIENT_INVENTORYUPDATECALLBACK)(action, user);
		}
	};
}
