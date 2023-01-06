#pragma once
#ifndef WORLD_H
#define WORLD_H
#include "4dm.h"
#include "path.h"
#include "Frustum.h"
#include "MeshRenderer.h"
namespace fdm
{
	class path;
	struct Frustum;
	class Entity;
	class Chunk;

	class World
	{
	public:
		union
		{
			const float gravity;
			path worldPath;
		};

		path chunksPath;
		unsigned int seed;
		glm::vec3 terrainOffsets;
		glm::vec3 biomeOffsets;
		glm::vec3 caveOffsets;
		bool flatWorld;
		PAD(7);
		std::map<glm::i64vec3, Chunk*> world;
		PAD(48);
		std::mutex worldMutex;
		std::atomic_bool chunksReady;
		PAD(3);
		std::atomic_int loadedChunks;
		std::vector<Chunk*> newChunks;
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
				base + idaOffsetFix(0x4FE20)
				)(this);
		}
		World()
		{
			reinterpret_cast<void(__thiscall*)(World*)>(
				base + idaOffsetFix(0xA7C10)
				)(this);
		}
		void setPath(const std::string& path)
		{
			reinterpret_cast<void(__thiscall*)(World*, const std::string&)>(
				base + idaOffsetFix(0xA7CD0)
				)(this, path);
		}
		void loadSettings(void)
		{
			reinterpret_cast<void(__thiscall*)(World*)>(
				base + idaOffsetFix(0xA7F20)
				)(this);
		}
		unsigned char getBlock(const glm::ivec4& block)
		{
			return reinterpret_cast<unsigned char(__thiscall*)(World*, const glm::ivec4&)>(
				base + idaOffsetFix(0xA87D0)
				)(this, block);
		}
		bool castRay(glm::vec4& currentPos, glm::ivec4& currentBlock, glm::ivec4& intersectBlock, const glm::vec4& endpoint)
		{
			return reinterpret_cast<bool(__thiscall*)(World*, glm::vec4&, glm::ivec4&, glm::ivec4&, const glm::vec4&)>(
				base + idaOffsetFix(0xA8980)
				)(this, currentPos, currentBlock, intersectBlock, endpoint);
		}
		void setBlockUpdate(const glm::ivec4& block, unsigned char value)
		{
			reinterpret_cast<void(__thiscall*)(World*, const glm::ivec4&, unsigned char)>(
				base + idaOffsetFix(0xA9AB0)
				)(this, block, value);
		}
		bool addEntity(std::unique_ptr<Entity>& entity)
		{
			return reinterpret_cast<bool(__thiscall*)(World*, std::unique_ptr<Entity>&)>(
				base + idaOffsetFix(0xAA2E0)
				)(this, entity);
		}
		void render(const m4::Mat5& MV, bool glasses)
		{
			reinterpret_cast<void(__thiscall*)(World*, const m4::Mat5&, bool)>(
				base + idaOffsetFix(0xAA3B0)
				)(this, MV, glasses);
		}
		void updateRenderFrustum(const glm::mat4x4& P)
		{
			reinterpret_cast<void(__thiscall*)(World*, const glm::mat4x4&)>(
				base + idaOffsetFix(0xAA870)
				)(this, P);
		}
		void loadChunks(void)
		{
			reinterpret_cast<void(__thiscall*)(World*)>(
				base + idaOffsetFix(0xAADA0)
				)(this);
		}
		void loadChunk(Chunk* chunk)
		{
			reinterpret_cast<void(__thiscall*)(World*, Chunk*)>(
				base + idaOffsetFix(0xAB310)
				)(this, chunk);
		}
		void saveChunk(Chunk* chunk)
		{
			reinterpret_cast<void(__thiscall*)(World*, Chunk*)>(
				base + idaOffsetFix(0xAB650)
				)(this, chunk);
		}
		void updateChunk(glm::i64vec3& coords)
		{
			reinterpret_cast<void(__thiscall*)(World*, glm::i64vec3&)>(
				base + idaOffsetFix(0xAB760)
				)(this, coords);
		}
		void generateChunk(Chunk* chunk)
		{
			reinterpret_cast<void(__thiscall*)(World*, Chunk*)>(
				base + idaOffsetFix(0xAB920)
				)(this, chunk);
		}
		void generateTree(unsigned char* blocks, const glm::i64vec3& chunkPos, bool dark)
		{
			reinterpret_cast<void(__thiscall*)(World*, unsigned char*, const glm::i64vec3&, bool)>(
				base + idaOffsetFix(0xACB40)
				)(this, blocks, chunkPos, dark);
		}
		void generateTreeBranch(unsigned char* blocks, const glm::i64vec3& chunkPos, glm::ivec4& startPos, int limit, bool dark)
		{
			reinterpret_cast<void(__thiscall*)(World*, unsigned char*, const glm::i64vec3&, glm::ivec4&, int, bool)>(
				base + idaOffsetFix(0xAD1F0)
				)(this, blocks, chunkPos, startPos, limit, dark);
		}
		Chunk* getChunk(const glm::i64vec3& chunkPos)
		{
			return reinterpret_cast<Chunk * (__thiscall*)(World*, const glm::i64vec3&)>(
				base + idaOffsetFix(0xADB90)
				)(this, chunkPos);
		}
		bool updateChunks(const glm::vec4& pos, const glm::vec4& over, unsigned char renderDistance)
		{
			return reinterpret_cast<bool(__thiscall*)(World*, const glm::vec4&, const glm::vec4&, unsigned char)>(
				base + idaOffsetFix(0xADC60)
				)(this, pos, over, renderDistance);
		}
		void unloadAllChunks(void)
		{
			reinterpret_cast<void(__thiscall*)(World*)>(
				base + idaOffsetFix(0xAEDF0)
				)(this);
		}
		std::unique_ptr<Entity>* getEntityIntersection(const glm::vec4& a, const glm::vec4& b)
		{
			return reinterpret_cast<std::unique_ptr<Entity>*(__thiscall*)(World*, const glm::vec4&, const glm::vec4&)>(
				base + idaOffsetFix(0xAEF60)
				)(this, a, b);
		}
		bool loadCube(glm::vec4 pos, unsigned char distance)
		{
			return reinterpret_cast<bool(__thiscall*)(World*, glm::vec4, unsigned char)>(
				base + idaOffsetFix(0xAF7D0)
				)(this, pos, distance);
		}
		bool smoothLightingEnabled()
		{
			return reinterpret_cast<bool(__thiscall*)(World*)>(
				base + idaOffsetFix(0xAFB60)
				)(this);
		}
		bool shadowsEnabled()
		{
			return reinterpret_cast<bool(__thiscall*)(World*)>(
				base + idaOffsetFix(0xAFB70)
				)(this);
		}
		bool lightsEnabled()
		{
			return reinterpret_cast<bool(__thiscall*)(World*)>(
				base + idaOffsetFix(0xAFB80)
				)(this);
		}
	};
}
#endif // !WORLD_H