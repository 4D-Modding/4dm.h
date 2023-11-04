#pragma once

#include "4dm.h"
#include "Entity.h"
#include "World.h"
#include "EntityManager.h"

namespace fdm 
{
	class Entity;
	class World;
	class EntityManager;
	class Chunk 
	{
	public:
		class ChunkMesh : public Mesh 
		{
		public:
			struct VertData 
			{
				glm::u8vec4 vert; 
				glm::u8vec4 tuv; // 0x4
				BlockInfo::VertLighting lighting; // 0x8

			};
			std::vector<Chunk::ChunkMesh::VertData> verts; // 0x8
			std::vector<uint32_t> indices; // 0x20
			bool updateQueued; // 0x38

			~ChunkMesh() 
			{
				reinterpret_cast<void(__thiscall*)(Chunk::ChunkMesh* self)>(FUNC_CHUNK_CHUNKMESH_DESTR_CHUNKMESH)(this);
			}
			ChunkMesh() 
			{
				reinterpret_cast<void(__thiscall*)(Chunk::ChunkMesh* self)>(FUNC_CHUNK_CHUNKMESH_CHUNKMESH)(this);
			}
			int buffSize(int buffIndex) const override
			{
				return reinterpret_cast<int (__thiscall*)(const Chunk::ChunkMesh* self, int buffIndex)>(FUNC_CHUNK_CHUNKMESH_BUFFSIZE)(this, buffIndex);
			}
			int attrCount(int buffIndex) const override
			{
				return reinterpret_cast<int (__thiscall*)(const Chunk::ChunkMesh* self, int buffIndex)>(FUNC_CHUNK_CHUNKMESH_ATTRCOUNT)(this, buffIndex);
			}
			unsigned int attrType(int buffIndex, int attrIndex) const override
			{
				return reinterpret_cast<unsigned int (__thiscall*)(const Chunk::ChunkMesh* self, int buffIndex, int attrIndex)>(FUNC_CHUNK_CHUNKMESH_ATTRTYPE)(this, buffIndex, attrIndex);
			}
			int attrSize(int buffIndex, int attrIndex) const override
			{
				return reinterpret_cast<int (__thiscall*)(const Chunk::ChunkMesh* self, int buffIndex, int attrIndex)>(FUNC_CHUNK_CHUNKMESH_ATTRSIZE)(this, buffIndex, attrIndex);
			}
			int attrStride(int buffIndex, int attrIndex) const override
			{
				return reinterpret_cast<int (__thiscall*)(const Chunk::ChunkMesh* self, int buffIndex, int attrIndex)>(FUNC_CHUNK_CHUNKMESH_ATTRSTRIDE)(this, buffIndex, attrIndex);
			}
			const void* indexBuffData() const override
			{
				return reinterpret_cast<const void* (__thiscall*)(const Chunk::ChunkMesh* self)>(FUNC_CHUNK_CHUNKMESH_INDEXBUFFDATA)(this);
			}
			void move(Chunk::ChunkMesh* other) 
			{
				return reinterpret_cast<void (__thiscall*)(Chunk::ChunkMesh* self, Chunk::ChunkMesh* other)>(FUNC_CHUNK_CHUNKMESH_MOVE)(this, other);
			}
			void addMeshSide(const glm::u8vec4& side, const glm::u8vec4& side_tuvs, const glm::u8vec4& pos, const BlockInfo::VertLighting* lighting) 
			{
				return reinterpret_cast<void (__thiscall*)(Chunk::ChunkMesh* self, const glm::u8vec4& side, const glm::u8vec4& side_tuvs, const glm::u8vec4& pos, const BlockInfo::VertLighting* lighting)>(FUNC_CHUNK_CHUNKMESH_ADDMESHSIDE)(this, side, side_tuvs, pos, lighting);
			}
			void addMeshPlant(const glm::u8vec4& plant, const glm::u8vec4& plant_tuvs, const glm::u8vec4& pos, const BlockInfo::VertLighting* lighting) 
			{
				return reinterpret_cast<void (__thiscall*)(Chunk::ChunkMesh* self, const glm::u8vec4& plant, const glm::u8vec4& plant_tuvs, const glm::u8vec4& pos, const BlockInfo::VertLighting* lighting)>(FUNC_CHUNK_CHUNKMESH_ADDMESHPLANT)(this, plant, plant_tuvs, pos, lighting);
			}
		};
		inline static const uint32_t SIZE = 8; 
		inline static const uint32_t HEIGHT = 128; 
		inline static const uint32_t BLOCK_DATA_SIZE = 128000; 
		unsigned char blocks[SIZE + 2][SIZE + 2][SIZE + 2][HEIGHT];
		unsigned char lightingHeightMap[SIZE + 2][SIZE + 2][SIZE + 2];
		glm::i64vec3 pos; // 0x1F7E8
		bool saved; // 0x1F800
		inline static const uint32_t MESH_COUNT = 8; 
		inline static const uint32_t MESH_HEIGHT = 16; 
		Chunk::ChunkMesh meshData[MESH_COUNT];
		MeshRenderer meshRenderers[MESH_COUNT];
		bool meshUpdatesQueued; // 0x1FB08
		PAD(0x7);
		std::mutex meshMutex; // 0x1FB10
		bool meshUpdated; // 0x1FB60
		std::atomic_bool meshReady; // 0x1FB61
		std::atomic_bool meshOutdated; // 0x1FB62
		std::atomic_bool inBounds; // 0x1FB63
		std::atomic_bool generatingMeshes; // 0x1FB64
		std::atomic_bool loaded; // 0x1FB65
		PAD(0x2);
		std::vector<Entity*> entities; // 0x1FB68
		int prevEntityCount; // 0x1FB80
		PAD(0x4);
		std::set<uint32_t> ownerPlayers; // 0x1FB88

		Chunk(const glm::i64vec3& pos) 
		{
			reinterpret_cast<void(__thiscall*)(Chunk* self, const glm::i64vec3& pos)>(FUNC_CHUNK_CHUNK)(this, pos);
		}
		void setBlock(const glm::ivec4& block, unsigned char value) 
		{
			return reinterpret_cast<void (__thiscall*)(Chunk* self, const glm::ivec4& block, unsigned char value)>(FUNC_CHUNK_SETBLOCK)(this, block, value);
		}
		void generateMesh(bool smoothLighting, bool shadows, bool lights) 
		{
			return reinterpret_cast<void (__thiscall*)(Chunk* self, bool smoothLighting, bool shadows, bool lights)>(FUNC_CHUNK_GENERATEMESH)(this, smoothLighting, shadows, lights);
		}
		void updateEntitiesClient(World* world, double dt, EntityManager* entityManager) 
		{
			return reinterpret_cast<void (__thiscall*)(Chunk* self, World* world, double dt, EntityManager* entityManager)>(FUNC_CHUNK_UPDATEENTITIESCLIENT)(this, world, dt, entityManager);
		}
		void clearEntities(EntityManager* entityManager) 
		{
			return reinterpret_cast<void (__thiscall*)(Chunk* self, EntityManager* entityManager)>(FUNC_CHUNK_CLEARENTITIES)(this, entityManager);
		}
		void render(const World* world, const m4::Mat5& MV, const Frustum* frustum) 
		{
			return reinterpret_cast<void (__thiscall*)(Chunk* self, const World* world, const m4::Mat5& MV, const Frustum* frustum)>(FUNC_CHUNK_RENDER)(this, world, MV, frustum);
		}
		void updateLightingHeightMap() 
		{
			return reinterpret_cast<void (__thiscall*)(Chunk* self)>(FUNC_CHUNK_UPDATELIGHTINGHEIGHTMAP)(this);
		}
		void updateMesh(bool smoothLighting, bool shadows, bool lights) 
		{
			return reinterpret_cast<void (__thiscall*)(Chunk* self, bool smoothLighting, bool shadows, bool lights)>(FUNC_CHUNK_UPDATEMESH)(this, smoothLighting, shadows, lights);
		}
		bool load(const path& chunksFolderPath, World* world) 
		{
			return reinterpret_cast<bool (__thiscall*)(Chunk* self, const path& chunksFolderPath, World* world)>(FUNC_CHUNK_LOAD)(this, chunksFolderPath, world);
		}
		void save(const path& chunksFolderPath) 
		{
			return reinterpret_cast<void (__thiscall*)(Chunk* self, const path& chunksFolderPath)>(FUNC_CHUNK_SAVE)(this, chunksFolderPath);
		}
		void loadFromMessage(const Connection::InMessage& message, World* world) 
		{
			return reinterpret_cast<void (__thiscall*)(Chunk* self, const Connection::InMessage& message, World* world)>(FUNC_CHUNK_LOADFROMMESSAGE)(this, message, world);
		}
		void updateCacheSection(const Chunk& other, bool shadows) 
		{
			return reinterpret_cast<void (__thiscall*)(Chunk* self, const Chunk& other, bool shadows)>(FUNC_CHUNK_UPDATECACHESECTION)(this, other, shadows);
		}
		void updateHeightmapCacheSection(glm::i64vec3* borderingChunkPos) 
		{
			return reinterpret_cast<void (__thiscall*)(Chunk* self, glm::i64vec3* borderingChunkPos)>(FUNC_CHUNK_UPDATEHEIGHTMAPCACHESECTION)(this, borderingChunkPos);
		}
		void generateMeshSection(Chunk::ChunkMesh* mesh, unsigned char startY, bool smoothLighting, bool shadows, bool lights) 
		{
			return reinterpret_cast<void (__thiscall*)(Chunk* self, Chunk::ChunkMesh* mesh, unsigned char startY, bool smoothLighting, bool shadows, bool lights)>(FUNC_CHUNK_GENERATEMESHSECTION)(this, mesh, startY, smoothLighting, shadows, lights);
		}
		void getSmoothLighting(const glm::ivec4& block, unsigned char face, BlockInfo::VertLighting* lighting, bool shadows, bool lights) 
		{
			return reinterpret_cast<void (__thiscall*)(Chunk* self, const glm::ivec4& block, unsigned char face, BlockInfo::VertLighting* lighting, bool shadows, bool lights)>(FUNC_CHUNK_GETSMOOTHLIGHTING)(this, block, face, lighting, shadows, lights);
		}
		void getLighting(const glm::ivec4& block, unsigned char face, BlockInfo::VertLighting* lighting, bool shadows, bool lights) 
		{
			return reinterpret_cast<void (__thiscall*)(Chunk* self, const glm::ivec4& block, unsigned char face, BlockInfo::VertLighting* lighting, bool shadows, bool lights)>(FUNC_CHUNK_GETLIGHTING)(this, block, face, lighting, shadows, lights);
		}
		void enableMesh() 
		{
			return reinterpret_cast<void (__thiscall*)(Chunk* self)>(FUNC_CHUNK_ENABLEMESH)(this);
		}
		void loadEntitiesFromJson(nlohmann::json& j, World* world) 
		{
			return reinterpret_cast<void (__thiscall*)(Chunk* self, nlohmann::json& j, World* world)>(FUNC_CHUNK_LOADENTITIESFROMJSON)(this, j, world);
		}
		std::string getFilenamePrefix() 
		{
			std::string result;
			return reinterpret_cast<std::string (__thiscall*)(Chunk* self, std::string* result)>(FUNC_CHUNK_GETFILENAMEPREFIX)(this, &result);
			return result;
		}
	};
}
