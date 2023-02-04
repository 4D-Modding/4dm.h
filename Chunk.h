#pragma once
#ifndef CHUNK_H
#define CHUNK_H
#include "4dm.h"
#include "Entity.h"

namespace fdm
{
	class MeshRenderer;
	class Entity;
	struct Frustum;
	class path;
	class World;
	struct Mesh;
	class Player;
	class Chunk
	{
	public:
		class ChunkMesh : public Mesh
		{
		public:
			struct VertData
			{
				VertData(){}
				glm::u8vec4 vert;
				glm::u8vec4 tuv;
				glm::u8vec3 lighting;
			};
			std::vector<Chunk::ChunkMesh::VertData> verts;
			std::vector<unsigned int> indices;
			bool updateQueued;

			~ChunkMesh()
			{
				reinterpret_cast<void(__thiscall*)(ChunkMesh*)>(
					base + idaOffsetFix(0x1CD80)
					)(this);
			}
			ChunkMesh() 
			{
				reinterpret_cast<void(__thiscall*)(ChunkMesh*)>(
					base + idaOffsetFix(0x2C180)
					)(this);
			}
			int buffSize(int buffIndex) override
			{
				return reinterpret_cast<int(__thiscall*)(ChunkMesh*, int)>(
					base + idaOffsetFix(0x2C1D0)
					)(this, buffIndex);
			}
			int attrCount(int buffIndex) override
			{
				return reinterpret_cast<int(__thiscall*)(ChunkMesh*, int)>(
					base + idaOffsetFix(0x2C200)
					)(this, buffIndex);
			}
			unsigned int attrType(int buffIndex, int attrIndex) override
			{
				return reinterpret_cast<unsigned int(__thiscall*)(ChunkMesh*, int, int)>(
					base + idaOffsetFix(0x2C210)
					)(this, buffIndex, attrIndex);
			}
			int attrSize(int buffIndex, int attrIndex) override
			{
				return reinterpret_cast<int(__thiscall*)(ChunkMesh*, int, int)>(
					base + idaOffsetFix(0x2C220)
					)(this, buffIndex, attrIndex);
			}
			int attrStride(int buffIndex, int attrIndex) override
			{
				return reinterpret_cast<int(__thiscall*)(ChunkMesh*, int, int)>(
					base + idaOffsetFix(0x2C240)
					)(this, buffIndex, attrIndex);
			}
			const void* indexBuffData() override
			{
				return reinterpret_cast<const void*(__thiscall*)(ChunkMesh*)>(
					base + idaOffsetFix(0x2C260)
					)(this);
			}
			ChunkMesh& operator=(ChunkMesh& other) 
			{
				return reinterpret_cast<ChunkMesh&(__thiscall*)(ChunkMesh*, ChunkMesh&)>(
					base + idaOffsetFix(0x2C280)
					)(this, other);
			}
			void addMeshSide(const glm::u8vec4* side, const glm::u8vec4* side_tuvs, const glm::u8vec4& pos, const glm::u8vec4* light) 
			{
				reinterpret_cast<void(__thiscall*)(ChunkMesh*, const glm::u8vec4*, const glm::u8vec4*, const glm::u8vec4&, const glm::u8vec4*)>(
					base + idaOffsetFix(0x2C360)
					)(this, side, side_tuvs, pos, light);
			}
			void addMeshPlant(const glm::u8vec4* side, const glm::u8vec4* side_tuvs, const glm::u8vec4& pos, const glm::u8vec4* light)
			{
				reinterpret_cast<void(__thiscall*)(ChunkMesh*, const glm::u8vec4*, const glm::u8vec4*, const glm::u8vec4&, const glm::u8vec4*)>(
					base + idaOffsetFix(0x2C4F0)
					)(this, side, side_tuvs, pos, light);
			}
		};
		static const unsigned char SIZE;
		static const unsigned char HEIGHT;
		static const unsigned char MESH_COUNT;
		static const unsigned char MESH_HEIGHT;

		unsigned char blocks[128][10][10][10];
		unsigned char lightingHeightMap[10][10][10];
		glm::i64vec3 pos;
		bool saved;

		PAD(7);

		ChunkMesh meshData[8];
		MeshRenderer meshRenderers[8];
		bool meshUpdatesQueued;

		PAD(7);

		std::mutex meshMutex;
		bool meshUpdated;
		std::atomic_bool meshReady;
		std::atomic_bool meshNew;
		std::atomic_bool inBounds;
		std::atomic_bool generatingMeshes;
		std::atomic_bool loaded;
		std::atomic_bool shouldUpdateCache;

		PAD(1);

		std::vector<std::unique_ptr<Entity>> entities;
		std::unordered_map<glm::u8vec4, std::unique_ptr<Entity>> blockEntities;


		Chunk(const glm::i64vec3& pos)
		{
			reinterpret_cast<void(__thiscall*)(Chunk*, const glm::i64vec3&)>(
				base + idaOffsetFix(0x1CB40)
				)(this, pos);
		}
		void setBlock(const glm::ivec4& blockPos, unsigned char blockVal) 
		{
			reinterpret_cast<void(__thiscall*)(Chunk*, const glm::ivec4&, unsigned char)>(
				base + idaOffsetFix(0x1CE60)
				)(this, blockPos, blockVal);
		}
		void generateMesh(World* world, bool updateNeighbors)
		{
			reinterpret_cast<void(__thiscall*)(Chunk*, World*, bool)>(
				base + idaOffsetFix(0x1CF40)
				)(this, world, updateNeighbors);
		}
		void updateEntities(World* world, Player* player, double dt)
		{
			reinterpret_cast<void(__thiscall*)(Chunk*, World*, Player*, double)>(
				base + idaOffsetFix(0x1D0B0)
				)(this, world, player, dt);
		}
		void addEntity(std::unique_ptr<Entity> entity)
		{
			reinterpret_cast<void(__thiscall*)(Chunk*, std::unique_ptr<Entity>*)>(
				base + idaOffsetFix(0x1D4B0)
				)(this, &entity);
		}
		std::unique_ptr<Entity>* getBlockEntity(const glm::u8vec4& relativeCoords)
		{
			return reinterpret_cast<std::unique_ptr<Entity>*(__thiscall*)(Chunk*, const glm::u8vec4&)>(
				base + idaOffsetFix(0x1D680)
				)(this, relativeCoords);
		}
		void render(const World* world, const m4::Mat5& MV, const Frustum& frustum)
		{
			reinterpret_cast<void(__thiscall*)(Chunk*, const World*, const m4::Mat5&, const Frustum&)>(
				base + idaOffsetFix(0x1D7C0)
				)(this, world, MV, frustum);
		}
		void updateLightingHeightMap()
		{
			reinterpret_cast<void(__thiscall*)(Chunk*)>(
				base + idaOffsetFix(0x1E1A0)
				)(this);
		}
		std::int64_t updateMesh(World* world, std::int64_t x, std::int64_t z, std::int64_t w)
		{
			return reinterpret_cast<std::int64_t(__thiscall*)(Chunk*, World*, std::int64_t, std::int64_t, std::int64_t)>(
				base + idaOffsetFix(0x1E280)
				)(this, world, x, z, w);
		}
		bool load(const path& chunksFolderPath) 
		{
			return reinterpret_cast<bool(__thiscall*)(Chunk*, const path&)>(
				base + idaOffsetFix(0x1E480)
				)(this, chunksFolderPath);
		}
		void save(const path& chunksFolderPath) 
		{
			reinterpret_cast<void(__thiscall*)(Chunk*, const path&)>(
				base + idaOffsetFix(0x1F070)
				)(this, chunksFolderPath);
		}
		void updateCache(World* world, bool updateNeighbors, bool shadows)
		{
			reinterpret_cast<void(__thiscall*)(Chunk*, World*, bool, bool)>(
				base + idaOffsetFix(0x1F880)
				)(this, world, updateNeighbors, shadows);
		}
		void updateCacheSection(const Chunk* other, bool shadows)
		{
			reinterpret_cast<void(__thiscall*)(Chunk*, const Chunk*, bool)>(
				base + idaOffsetFix(0x20000)
				)(this, other, shadows);
		}
		void generateMeshSection(World* world, ChunkMesh& mesh, unsigned char startY)
		{
			reinterpret_cast<void(__thiscall*)(Chunk*, World*, ChunkMesh&, unsigned char)>(
				base + idaOffsetFix(0x278E0)
				)(this, world, mesh, startY);
		}
		void getSmoothLighting(const glm::ivec4& block, unsigned char face, glm::u8vec3* lighting, bool shadows, bool lights)
		{
			reinterpret_cast<void(__thiscall*)(Chunk*, const glm::ivec4&, unsigned char, glm::u8vec3*, bool, bool)>(
				base + idaOffsetFix(0x2A640)
				)(this, block, face, lighting, shadows, lights);
		}
		void getLighting(const glm::ivec4& block, unsigned char face, glm::u8vec3* lighting, bool shadows, bool lights)
		{
			reinterpret_cast<void(__thiscall*)(Chunk*, const glm::ivec4&, unsigned char, glm::u8vec3*, bool, bool)>(
				base + idaOffsetFix(0x2BB80)
				)(this, block, face, lighting, shadows, lights);
		}
		path& getChunkPath(const path& chunksFolderPath) 
		{
			path* result = new path();
			return reinterpret_cast<path&(__thiscall*)(Chunk*, path*, const path&)>(
				base + idaOffsetFix(0x2BFB0)
				)(this, result, chunksFolderPath);
		}
	};
}
#endif