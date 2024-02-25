#pragma once

#include "4dm.h"

namespace fdm 
{
	class WorldSingleplayer : public WorldManager 
	{
	public:
		ChunkLoader chunkLoader; // 0x1D0
		std::atomic_bool chunksReady; // 0x270
		std::atomic_bool shouldStopLoading; // 0x271
		PAD(0x6);
		std::vector<Chunk*> newChunks; // 0x278
		std::mutex updatedNeighborsMutex; // 0x290
		std::vector<Chunk*> updatedNeighbors; // 0x2E0
		std::thread chunkLoadingThread; // 0x2F8
		std::thread meshRegeneratingThread; // 0x308

		WorldSingleplayer(const path& worldPath, const path& biomeInfoPath) 
		{
			reinterpret_cast<void(__thiscall*)(WorldSingleplayer* self, const path& worldPath, const path& biomeInfoPath)>(getFuncAddr((int)Func::WorldSingleplayer::WorldSingleplayer))(this, worldPath, biomeInfoPath);
		}
		~WorldSingleplayer() override
		{
			reinterpret_cast<void(__thiscall*)(WorldSingleplayer* self)>(getFuncAddr((int)Func::WorldSingleplayer::destr_WorldSingleplayer))(this);
		}
		void localPlayerEvent(Player* player, Packet::ClientPacket eventType, int64_t eventValue, void* data) override
		{
			return reinterpret_cast<void (__thiscall*)(WorldSingleplayer* self, Player* player, Packet::ClientPacket eventType, int64_t eventValue, void* data)>(getFuncAddr((int)Func::WorldSingleplayer::localPlayerEvent))(this, player, eventType, eventValue, data);
		}
		void updateLocal(StateManager& s, Player* player, double dt) override
		{
			return reinterpret_cast<void (__thiscall*)(WorldSingleplayer* self, StateManager& s, Player* player, double dt)>(getFuncAddr((int)Func::WorldSingleplayer::updateLocal))(this, s, player, dt);
		}
		void cleanupLocal(Player* player) override
		{
			return reinterpret_cast<void (__thiscall*)(WorldSingleplayer* self, Player* player)>(getFuncAddr((int)Func::WorldSingleplayer::cleanupLocal))(this, player);
		}
		void setRenderDistanceLocal(Player* player, unsigned char distance) override
		{
			return reinterpret_cast<void (__thiscall*)(WorldSingleplayer* self, Player* player, unsigned char distance)>(getFuncAddr((int)Func::WorldSingleplayer::setRenderDistanceLocal))(this, player, distance);
		}
		void setDifficultyLocal(Player* player, int difficulty) override
		{
			return reinterpret_cast<void (__thiscall*)(WorldSingleplayer* self, Player* player, int difficulty)>(getFuncAddr((int)Func::WorldSingleplayer::setDifficultyLocal))(this, player, difficulty);
		}
		void localPlayerInit(Player* player) override
		{
			return reinterpret_cast<void (__thiscall*)(WorldSingleplayer* self, Player* player)>(getFuncAddr((int)Func::WorldSingleplayer::localPlayerInit))(this, player);
		}
		void localPlayerRespawn(StateManager& s, Player* player) override
		{
			return reinterpret_cast<void (__thiscall*)(WorldSingleplayer* self, StateManager& s, Player* player)>(getFuncAddr((int)Func::WorldSingleplayer::localPlayerRespawn))(this, s, player);
		}
		void handleLightingOptionsUpdate() override
		{
			return reinterpret_cast<void (__thiscall*)(WorldSingleplayer* self)>(getFuncAddr((int)Func::WorldSingleplayer::handleLightingOptionsUpdate))(this);
		}
		bool updateChunks(Player* player) 
		{
			return reinterpret_cast<bool (__thiscall*)(WorldSingleplayer* self, Player* player)>(getFuncAddr((int)Func::WorldSingleplayer::updateChunks))(this, player);
		}
		void updateChunk(const glm::i64vec3& coords) 
		{
			return reinterpret_cast<void (__thiscall*)(WorldSingleplayer* self, const glm::i64vec3& coords)>(getFuncAddr((int)Func::WorldSingleplayer::updateChunk))(this, coords);
		}
		void loadChunks() 
		{
			return reinterpret_cast<void (__thiscall*)(WorldSingleplayer* self)>(getFuncAddr((int)Func::WorldSingleplayer::loadChunks))(this);
		}
		void loadChunk(Chunk* c, bool shadows) 
		{
			return reinterpret_cast<void (__thiscall*)(WorldSingleplayer* self, Chunk* c, bool shadows)>(getFuncAddr((int)Func::WorldSingleplayer::loadChunk))(this, c, shadows);
		}
		void updateChunkCacheAndMesh(Chunk* c, bool useSmoothLighting, bool useShadows, bool useLights) 
		{
			return reinterpret_cast<void (__thiscall*)(WorldSingleplayer* self, Chunk* c, bool useSmoothLighting, bool useShadows, bool useLights)>(getFuncAddr((int)Func::WorldSingleplayer::updateChunkCacheAndMesh))(this, c, useSmoothLighting, useShadows, useLights);
		}
		void updateChunkCache(Chunk* c, bool useSmoothLighting, bool useShadows, bool updateNeighbors) 
		{
			return reinterpret_cast<void (__thiscall*)(WorldSingleplayer* self, Chunk* c, bool useSmoothLighting, bool useShadows, bool updateNeighbors)>(getFuncAddr((int)Func::WorldSingleplayer::updateChunkCache))(this, c, useSmoothLighting, useShadows, updateNeighbors);
		}
		void regenerateAllChunkMeshes() 
		{
			return reinterpret_cast<void (__thiscall*)(WorldSingleplayer* self)>(getFuncAddr((int)Func::WorldSingleplayer::regenerateAllChunkMeshes))(this);
		}
	};
}
