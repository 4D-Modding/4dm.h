#pragma once

#include "4dm.h"

namespace fdm 
{
	class WorldTitleScreen : public WorldManager 
	{
	public:
		std::vector<Chunk *> chunksToLoad; // 0x1D0
		ChunkLoader chunkLoader; // 0x1E8
		std::atomic<bool> chunksReady; // 0x288

		bool loadCube(const glm::vec4& pos, uint8_t distance) 
		{
			return reinterpret_cast<bool (__thiscall*)(WorldTitleScreen* self, const glm::vec4& pos, uint8_t distance)>(getFuncAddr((int)Func::WorldTitleScreen::loadCube))(this, pos, distance);
		}
		void loadChunk(Chunk* c, bool shadows) 
		{
			return reinterpret_cast<void (__thiscall*)(WorldTitleScreen* self, Chunk* c, bool shadows)>(getFuncAddr((int)Func::WorldTitleScreen::loadChunk))(this, c, shadows);
		}
		void updateChunkCache(Chunk* c, bool useSmoothLighting, bool useShadows) 
		{
			return reinterpret_cast<void (__thiscall*)(WorldTitleScreen* self, Chunk* c, bool useSmoothLighting, bool useShadows)>(getFuncAddr((int)Func::WorldTitleScreen::updateChunkCache))(this, c, useSmoothLighting, useShadows);
		}
		void generateMesh(Chunk* c, bool useSmoothLighting, bool useShadows, bool useLights) 
		{
			return reinterpret_cast<void (__thiscall*)(WorldTitleScreen* self, Chunk* c, bool useSmoothLighting, bool useShadows, bool useLights)>(getFuncAddr((int)Func::WorldTitleScreen::generateMesh))(this, c, useSmoothLighting, useShadows, useLights);
		}
		void loadChunks() 
		{
			return reinterpret_cast<void (__thiscall*)(WorldTitleScreen* self)>(getFuncAddr((int)Func::WorldTitleScreen::loadChunks))(this);
		}
		World::Type getType() override
		{
			return reinterpret_cast<World::Type(__thiscall*)(WorldTitleScreen * self)>(getFuncAddr((int)Func::WorldTitleScreen::getType))(this);
		}
		void handleLightingOptionsUpdate() override
		{
			return reinterpret_cast<void(__thiscall*)(WorldTitleScreen * self)>(getFuncAddr((int)Func::WorldTitleScreen::handleLightingOptionsUpdate))(this);
		}
		void localPlayerEvent(Player* player, Packet::ClientPacket eventType, int64_t eventValue, void* data) override
		{
			return reinterpret_cast<void(__thiscall*)(WorldTitleScreen * self, Player*, Packet::ClientPacket, int64_t, void*)>(getFuncAddr((int)Func::WorldTitleScreen::localPlayerEvent))(this, player, eventType, eventValue, data);
		}
		void localPlayerInit(Player* player) override
		{
			return reinterpret_cast<void(__thiscall*)(WorldTitleScreen * self, Player*)>(getFuncAddr((int)Func::WorldTitleScreen::localPlayerInit))(this, player);
		}
		void localPlayerRespawn(StateManager& s, Player* player) override
		{
			return reinterpret_cast<void(__thiscall*)(WorldTitleScreen * self, StateManager&, Player*)>(getFuncAddr((int)Func::WorldTitleScreen::localPlayerRespawn))(this, s, player);
		}
	};
}
