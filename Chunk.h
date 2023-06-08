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
					FUNC_CHUNK_CHUNKMESH_DCHUNKMESH
					)(this);
			}
			ChunkMesh() 
			{
				reinterpret_cast<void(__thiscall*)(ChunkMesh*)>(
					FUNC_CHUNK_CHUNKMESH_CHUNKMESH
					)(this);
			}
			int buffSize(int buffIndex) override
			{
				return reinterpret_cast<int(__thiscall*)(ChunkMesh*, int)>(
					FUNC_CHUNK_CHUNKMESH_BUFFSIZE
					)(this, buffIndex);
			}
			int attrCount(int buffIndex) override
			{
				return reinterpret_cast<int(__thiscall*)(ChunkMesh*, int)>(
					FUNC_CHUNK_CHUNKMESH_ATTRCOUNT
					)(this, buffIndex);
			}
			unsigned int attrType(int buffIndex, int attrIndex) override
			{
				return reinterpret_cast<unsigned int(__thiscall*)(ChunkMesh*, int, int)>(
					FUNC_CHUNK_CHUNKMESH_ATTRTYPE
					)(this, buffIndex, attrIndex);
			}
			int attrSize(int buffIndex, int attrIndex) override
			{
				return reinterpret_cast<int(__thiscall*)(ChunkMesh*, int, int)>(
					FUNC_CHUNK_CHUNKMESH_ATTRSIZE
					)(this, buffIndex, attrIndex);
			}
			int attrStride(int buffIndex, int attrIndex) override
			{
				return reinterpret_cast<int(__thiscall*)(ChunkMesh*, int, int)>(
					FUNC_CHUNK_CHUNKMESH_ATTRSTRIDE
					)(this, buffIndex, attrIndex);
			}
			const void* indexBuffData() override
			{
				return reinterpret_cast<const void*(__thiscall*)(ChunkMesh*)>(
					FUNC_CHUNK_CHUNKMESH_INDEXBUFFDATA
					)(this);
			}
			ChunkMesh& operator=(ChunkMesh& other) 
			{
				return reinterpret_cast<ChunkMesh&(__thiscall*)(ChunkMesh*, ChunkMesh&)>(
					FUNC_CHUNK_CHUNKMESH_OPERATOR_EQ
					)(this, other);
			}
			void addMeshSide(const glm::u8vec4* side, const glm::u8vec4* side_tuvs, const glm::u8vec4& pos, const glm::u8vec4* light) 
			{
				reinterpret_cast<void(__thiscall*)(ChunkMesh*, const glm::u8vec4*, const glm::u8vec4*, const glm::u8vec4&, const glm::u8vec4*)>(
					FUNC_CHUNK_CHUNKMESH_ADDMESHSIDE
					)(this, side, side_tuvs, pos, light);
			}
			void addMeshPlant(const glm::u8vec4* side, const glm::u8vec4* side_tuvs, const glm::u8vec4& pos, const glm::u8vec4* light)
			{
				reinterpret_cast<void(__thiscall*)(ChunkMesh*, const glm::u8vec4*, const glm::u8vec4*, const glm::u8vec4&, const glm::u8vec4*)>(
					FUNC_CHUNK_CHUNKMESH_ADDMESHPLANT
					)(this, side, side_tuvs, pos, light);
			}
		};
		inline static const unsigned char SIZE = 10; // ig? not sure
		inline static const unsigned char HEIGHT = 128;
		inline static const unsigned char MESH_COUNT = 8; // ig? not sure
		inline static const unsigned char MESH_HEIGHT = 0; // idk number

		unsigned char blocks[HEIGHT][SIZE][SIZE][SIZE];
		unsigned char lightingHeightMap[SIZE][SIZE][SIZE];
		glm::i64vec3 pos;
		bool saved;

		PAD(7);

		ChunkMesh meshData[MESH_COUNT];
		MeshRenderer meshRenderers[MESH_COUNT];
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
				FUNK_CHUNK_CHUNK
				)(this, pos);
		}
		void setBlock(const glm::ivec4& blockPos, unsigned char blockVal) 
		{
			reinterpret_cast<void(__thiscall*)(Chunk*, const glm::ivec4&, unsigned char)>(
				FUNK_CHUNK_SETBLOCK
				)(this, blockPos, blockVal);
		}
		void generateMesh(World* world, bool updateNeighbors)
		{
			reinterpret_cast<void(__thiscall*)(Chunk*, World*, bool)>(
				FUNK_CHUNK_GENERATEMESH
				)(this, world, updateNeighbors);
		}
		void updateEntities(World* world, Player* player, double dt)
		{
			reinterpret_cast<void(__thiscall*)(Chunk*, World*, Player*, double)>(
				FUNK_CHUNK_UPDATEENTITIES
				)(this, world, player, dt);
		}
		void addEntity(std::unique_ptr<Entity> entity)
		{
			reinterpret_cast<void(__thiscall*)(Chunk*, std::unique_ptr<Entity>*)>(
				FUNK_CHUNK_ADDENTITY
				)(this, &entity);
		}
		std::unique_ptr<Entity> getBlockEntity(const glm::u8vec4& relativeCoords)
		{
			return reinterpret_cast<std::unique_ptr<Entity>(__thiscall*)(Chunk*, const glm::u8vec4&)>(
				FUNK_CHUNK_GETBLOCKENTITY
				)(this, relativeCoords);
		}
		void render(const World* world, const m4::Mat5& MV, const Frustum& frustum)
		{
			reinterpret_cast<void(__thiscall*)(Chunk*, const World*, const m4::Mat5&, const Frustum&)>(
				FUNK_CHUNK_RENDER
				)(this, world, MV, frustum);
		}
		void updateLightingHeightMap()
		{
			reinterpret_cast<void(__thiscall*)(Chunk*)>(
				FUNK_CHUNK_UPDATELIGHTINGHEIGHTMAP
				)(this);
		}
		std::int64_t updateMesh(World* world, std::int64_t x, std::int64_t z, std::int64_t w)
		{
			return reinterpret_cast<std::int64_t(__thiscall*)(Chunk*, World*, std::int64_t, std::int64_t, std::int64_t)>(
				FUNK_CHUNK_UPDATEMESH
				)(this, world, x, z, w);
		}
		bool load(const path& chunksFolderPath) 
		{
			return reinterpret_cast<bool(__thiscall*)(Chunk*, const path&)>(
				FUNK_CHUNK_LOAD
				)(this, chunksFolderPath);
		}
		void save(const path& chunksFolderPath) 
		{
			reinterpret_cast<void(__thiscall*)(Chunk*, const path&)>(
				FUNK_CHUNK_SAVE
				)(this, chunksFolderPath);
		}
		void updateCacheSection(const Chunk* other, bool shadows)
		{
			reinterpret_cast<void(__thiscall*)(Chunk*, const Chunk*, bool)>(
				FUNK_CHUNK_UPDATECACHESECTION
				)(this, other, shadows);
		}
		void generateMeshSection(World* world, ChunkMesh& mesh, unsigned char startY)
		{
			reinterpret_cast<void(__thiscall*)(Chunk*, World*, ChunkMesh&, unsigned char)>(
				FUNK_CHUNK_GENERATEMESHSECTION
				)(this, world, mesh, startY);
		}
		void getSmoothLighting(const glm::ivec4& block, unsigned char face, glm::u8vec3* lighting, bool shadows, bool lights)
		{
			reinterpret_cast<void(__thiscall*)(Chunk*, const glm::ivec4&, unsigned char, glm::u8vec3*, bool, bool)>(
				FUNK_CHUNK_GETSMOOTHLIGHTING
				)(this, block, face, lighting, shadows, lights);
		}
		void getLighting(const glm::ivec4& block, unsigned char face, glm::u8vec3* lighting, bool shadows, bool lights)
		{
			reinterpret_cast<void(__thiscall*)(Chunk*, const glm::ivec4&, unsigned char, glm::u8vec3*, bool, bool)>(
				FUNK_CHUNK_GETLIGHTING
				)(this, block, face, lighting, shadows, lights);
		}
		path& getChunkPath(const path& chunksFolderPath) 
		{
			return reinterpret_cast<path&(__thiscall*)(Chunk*, path*, const path&)>(
				FUNK_CHUNK_GETCHUNKPATH
				)(this, nullptr, chunksFolderPath);
		}
	};
}
#endif