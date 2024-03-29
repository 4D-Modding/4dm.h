#pragma once

#include "4dm.h"

namespace fdm 
{
	class WorldTitleScreen : public WorldManager 
	{
	public:
		std::vector<Chunk *> chunksToLoad; // 0x1D0
		ChunkLoader chunkLoader; // 0x1E8
		std::atomic_bool chunksReady; // 0x288

		bool loadCube(const glm::vec4& pos, unsigned char distance) 
		{
			return reinterpret_cast<bool (__thiscall*)(WorldTitleScreen* self, const glm::vec4& pos, unsigned char distance)>(getFuncAddr((int)Func::WorldTitleScreen::loadCube))(this, pos, distance);
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
	};
}
