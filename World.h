#pragma once
#ifndef WORLD_H
#define WORLD_H
#include "4dm.h"
#include "path.h"
#include "Frustum.h"
#include "MeshRenderer.h"
#include "Chunk.h"

namespace fdm
{
	class path;
	struct Frustum;
	class Entity;
	class Chunk;
	class World
	{
	public:

		path worldPath;
		path chunksPath;
		unsigned int seed;
		glm::vec3 terrainOffsets;
		glm::vec3 biomeOffsets;
		glm::vec3 caveOffsets;
		bool flatWorld;
		PAD(7);
		std::unordered_map<glm::i64vec3, Chunk*> world;
		std::mutex worldMutex;
		std::atomic_bool chunksReady;
		PAD(3);
		std::atomic_int loadedChunks;
		std::vector<Chunk*> newChunks;
		std::mutex neighborMutex;
		std::vector<Chunk*> updateNeighbors;
		Frustum frustum;
		std::atomic_bool shouldStopLoading;
		std::atomic_bool shouldSpawnEntities;
		std::atomic_bool shouldSaveUnmodifiedChunks;
		PAD(1);
		std::atomic_int difficulty;
		std::atomic_bool smoothLighting;
		std::atomic_bool shadows;
		std::atomic_bool lights;

		~World()
		{
			reinterpret_cast<void(__thiscall*)(World*)>(
				FUNC_WORLD_DWORLD
				)(this);
		}
		World()
		{
			reinterpret_cast<void(__thiscall*)(World*)>(
				FUNC_WORLD_WORLD
				)(this);
		}
		void setPath(const std::string& path)
		{
			reinterpret_cast<void(__thiscall*)(World*, const std::string&)>(
				FUNC_WORLD_SETPATH
				)(this, path);
		}
		void loadSettings(void)
		{
			reinterpret_cast<void(__thiscall*)(World*)>(
				FUNC_WORLD_LOADSETTINGS
				)(this);
		}
		unsigned char getBlock(const glm::ivec4& block)
		{
			return reinterpret_cast<unsigned char(__thiscall*)(World*, const glm::ivec4&)>(
				FUNC_WORLD_GETBLOCK
				)(this, block);
		}
		bool castRay(glm::vec4& currentPos, glm::ivec4& currentBlock, glm::ivec4& intersectBlock, const glm::vec4& endpoint)
		{
			return reinterpret_cast<bool(__thiscall*)(World*, glm::vec4&, glm::ivec4&, glm::ivec4&, const glm::vec4&)>(
				FUNC_WORLD_CASTRAY
				)(this, currentPos, currentBlock, intersectBlock, endpoint);
		}
		void setBlockUpdate(const glm::ivec4& block, unsigned char value)
		{
			reinterpret_cast<void(__thiscall*)(World*, const glm::ivec4&, unsigned char)>(
				FUNC_WORLD_SETBLOCKUPDATE
				)(this, block, value);
		}
		bool addEntity(std::unique_ptr<Entity>& entity)
		{
			return reinterpret_cast<bool(__thiscall*)(World*, std::unique_ptr<Entity>&)>(
				FUNC_WORLD_ADDENTITY
				)(this, entity);
		}
		void render(const m4::Mat5& MV, bool glasses)
		{
			reinterpret_cast<void(__thiscall*)(World*, const m4::Mat5&, bool)>(
				FUNC_WORLD_RENDER
				)(this, MV, glasses);
		}
		void updateRenderFrustum(const glm::mat4x4& P)
		{
			reinterpret_cast<void(__thiscall*)(World*, const glm::mat4x4&)>(
				FUNC_WORLD_UPDATERENDERFRUSTUM
				)(this, P);
		}
		void loadChunks(void)
		{
			reinterpret_cast<void(__thiscall*)(World*)>(
				FUNC_WORLD_LOADCHUNKS
				)(this);
		}
		void loadChunk(Chunk* chunk)
		{
			reinterpret_cast<void(__thiscall*)(World*, Chunk*)>(
				FUNC_WORLD_LOADCHUNK
				)(this, chunk);
		}
		void updateChunkCacheAndMesh(Chunk* c, bool useSmoothLighting, bool useShadows, bool useLights)
		{
			return reinterpret_cast<void(__thiscall*)(World * self, Chunk * c, bool useSmoothLighting, bool useShadows, bool useLights)>(FUNC_WORLD_UPDATECHUNKCACHEANDMESH)(this, c, useSmoothLighting, useShadows, useLights);
		}
		void updateChunkCache(Chunk* c, bool useSmoothLighting, bool useShadows, bool updateNeighbors)
		{
			return reinterpret_cast<void(__thiscall*)(World * self, Chunk * c, bool useSmoothLighting, bool useShadows, bool updateNeighbors)>(FUNC_WORLD_UPDATECHUNKCACHE)(this, c, useSmoothLighting, useShadows, updateNeighbors);
		}
		void regenerateAllChunkMeshes()
		{
			return reinterpret_cast<void(__thiscall*)(World * self)>(FUNC_WORLD_REGENERATEALLCHUNKMESHES)(this);
		}
		void saveChunk(Chunk* chunk)
		{
			reinterpret_cast<void(__thiscall*)(World*, Chunk*)>(
				FUNC_WORLD_SAVECHUNK
				)(this, chunk);
		}
		void updateChunk(glm::i64vec3& coords)
		{
			reinterpret_cast<void(__thiscall*)(World*, glm::i64vec3&)>(
				FUNC_WORLD_UPDATECHUNK
				)(this, coords);
		}
		void generateChunk(Chunk* chunk)
		{
			reinterpret_cast<void(__thiscall*)(World*, Chunk*)>(
				FUNC_WORLD_GENERATECHUNK
				)(this, chunk);
		}
		void generateTree(unsigned char* blocks, const glm::i64vec3& chunkPos, bool dark)
		{
			reinterpret_cast<void(__thiscall*)(World*, unsigned char*, const glm::i64vec3&, bool)>(
				FUNC_WORLD_GENERATETREE
				)(this, blocks, chunkPos, dark);
		}
		void generateTreeBranch(unsigned char* blocks, const glm::i64vec3& chunkPos, glm::ivec4& startPos, int limit, bool dark)
		{
			reinterpret_cast<void(__thiscall*)(World*, unsigned char*, const glm::i64vec3&, glm::ivec4&, int, bool)>(
				FUNC_WORLD_GENERATETREEBRANCH
				)(this, blocks, chunkPos, startPos, limit, dark);
		}
		Chunk* getChunk(const glm::i64vec3& chunkPos)
		{
			return reinterpret_cast<Chunk * (__thiscall*)(World*, const glm::i64vec3&)>(
				FUNC_WORLD_GETCHUNK
				)(this, chunkPos);
		}
		bool updateChunks(const glm::vec4& pos, const glm::vec4& over, unsigned char renderDistance)
		{
			return reinterpret_cast<bool(__thiscall*)(World*, const glm::vec4&, const glm::vec4&, unsigned char)>(
				FUNC_WORLD_UPDATECHUNKS
				)(this, pos, over, renderDistance);
		}
		void unloadAllChunks(void)
		{
			reinterpret_cast<void(__thiscall*)(World*)>(
				FUNC_WORLD_UNLOADALLCHUNKS
				)(this);
		}
		std::unique_ptr<Entity> getEntityIntersection(const glm::vec4& a, const glm::vec4& b)
		{
			return reinterpret_cast<std::unique_ptr<Entity>(__thiscall*)(World*, const glm::vec4&, const glm::vec4&)>(
				FUNC_WORLD_GETENTITYINTERSECTION
				)(this, a, b);
		}
		bool loadCube(glm::vec4 pos, unsigned char distance)
		{
			return reinterpret_cast<bool(__thiscall*)(World*, glm::vec4, unsigned char)>(
				FUNC_WORLD_LOADCUBE
				)(this, pos, distance);
		}
		bool smoothLightingEnabled()
		{
			return smoothLighting;
		}
		bool shadowsEnabled()
		{
			return shadows;
		}
		bool lightsEnabled()
		{
			return lights;
		}
	};
}
#endif // !WORLD_H