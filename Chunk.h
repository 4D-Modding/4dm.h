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
				reinterpret_cast<void(__thiscall*)(Chunk::ChunkMesh* self)>(getFuncAddr((int)Func::Chunk::ChunkMesh::destr_ChunkMesh))(this);
			}
			ChunkMesh() 
			{
				reinterpret_cast<void(__thiscall*)(Chunk::ChunkMesh* self)>(getFuncAddr((int)Func::Chunk::ChunkMesh::ChunkMesh))(this);
			}
			int buffSize(int buffIndex) const override
			{
				return reinterpret_cast<int (__thiscall*)(const Chunk::ChunkMesh* self, int buffIndex)>(getFuncAddr((int)Func::Chunk::ChunkMesh::buffSize))(this, buffIndex);
			}
			int attrCount(int buffIndex) const override
			{
				return reinterpret_cast<int (__thiscall*)(const Chunk::ChunkMesh* self, int buffIndex)>(getFuncAddr((int)Func::Chunk::ChunkMesh::attrCount))(this, buffIndex);
			}
			unsigned int attrType(int buffIndex, int attrIndex) const override
			{
				return reinterpret_cast<unsigned int (__thiscall*)(const Chunk::ChunkMesh* self, int buffIndex, int attrIndex)>(getFuncAddr((int)Func::Chunk::ChunkMesh::attrType))(this, buffIndex, attrIndex);
			}
			int attrSize(int buffIndex, int attrIndex) const override
			{
				return reinterpret_cast<int (__thiscall*)(const Chunk::ChunkMesh* self, int buffIndex, int attrIndex)>(getFuncAddr((int)Func::Chunk::ChunkMesh::attrSize))(this, buffIndex, attrIndex);
			}
			int attrStride(int buffIndex, int attrIndex) const override
			{
				return reinterpret_cast<int (__thiscall*)(const Chunk::ChunkMesh* self, int buffIndex, int attrIndex)>(getFuncAddr((int)Func::Chunk::ChunkMesh::attrStride))(this, buffIndex, attrIndex);
			}
			const void* indexBuffData() const override
			{
				return reinterpret_cast<const void* (__thiscall*)(const Chunk::ChunkMesh* self)>(getFuncAddr((int)Func::Chunk::ChunkMesh::indexBuffData))(this);
			}
			void move(Chunk::ChunkMesh* other) 
			{
				return reinterpret_cast<void (__thiscall*)(Chunk::ChunkMesh* self, Chunk::ChunkMesh* other)>(getFuncAddr((int)Func::Chunk::ChunkMesh::move))(this, other);
			}
			void addMeshSide(const glm::u8vec4* side, const glm::u8vec4* side_tuvs, const glm::u8vec4& pos, const BlockInfo::VertLighting lighting[8]) 
			{
				return reinterpret_cast<void (__thiscall*)(Chunk::ChunkMesh* self, const glm::u8vec4* side, const glm::u8vec4* side_tuvs, const glm::u8vec4& pos, const BlockInfo::VertLighting lighting[8])>(getFuncAddr((int)Func::Chunk::ChunkMesh::addMeshSide))(this, side, side_tuvs, pos, lighting);
			}
			void addMeshPlant(const glm::u8vec4* plant, const glm::u8vec4* plant_tuvs, const glm::u8vec4& pos, const BlockInfo::VertLighting lighting[16]) 
			{
				return reinterpret_cast<void (__thiscall*)(Chunk::ChunkMesh* self, const glm::u8vec4* plant, const glm::u8vec4* plant_tuvs, const glm::u8vec4& pos, const BlockInfo::VertLighting lighting[16])>(getFuncAddr((int)Func::Chunk::ChunkMesh::addMeshPlant))(this, plant, plant_tuvs, pos, lighting);
			}
		};
		inline static const uint32_t SIZE = 8; 
		inline static const uint32_t HEIGHT = 128; 
		inline static const uint32_t BLOCK_DATA_SIZE = 128000; 
		unsigned char blocks[SIZE + 2][SIZE + 2][SIZE + 2][HEIGHT];
		unsigned char lightingHeightMap[SIZE + 2][SIZE + 2][SIZE + 2];
		glm::i64vec3 pos; // 0x1F7E8
		bool saved; // 0x1F800
		PAD(0x7);
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
			reinterpret_cast<void(__thiscall*)(Chunk* self, const glm::i64vec3& pos)>(getFuncAddr((int)Func::Chunk::Chunk))(this, pos);
		}
		void setBlock(const glm::ivec4& block, unsigned char value) 
		{
			return reinterpret_cast<void (__thiscall*)(Chunk* self, const glm::ivec4& block, unsigned char value)>(getFuncAddr((int)Func::Chunk::setBlock))(this, block, value);
		}
		void generateMesh(bool smoothLighting, bool shadows, bool lights) 
		{
			return reinterpret_cast<void (__thiscall*)(Chunk* self, bool smoothLighting, bool shadows, bool lights)>(getFuncAddr((int)Func::Chunk::generateMesh))(this, smoothLighting, shadows, lights);
		}
		void updateEntitiesClient(World* world, double dt, EntityManager& entityManager) 
		{
			return reinterpret_cast<void (__thiscall*)(Chunk* self, World* world, double dt, EntityManager& entityManager)>(getFuncAddr((int)Func::Chunk::updateEntitiesClient))(this, world, dt, entityManager);
		}
		void clearEntities(EntityManager* entityManager) 
		{
			return reinterpret_cast<void (__thiscall*)(Chunk* self, EntityManager* entityManager)>(getFuncAddr((int)Func::Chunk::clearEntities))(this, entityManager);
		}
		void render(const World* world, const m4::Mat5& MV, const Frustum& frustum) 
		{
			return reinterpret_cast<void (__thiscall*)(Chunk* self, const World* world, const m4::Mat5& MV, const Frustum& frustum)>(getFuncAddr((int)Func::Chunk::render))(this, world, MV, frustum);
		}
		void updateLightingHeightMap() 
		{
			return reinterpret_cast<void (__thiscall*)(Chunk* self)>(getFuncAddr((int)Func::Chunk::updateLightingHeightMap))(this);
		}
		void updateMesh(bool smoothLighting, bool shadows, bool lights) 
		{
			return reinterpret_cast<void (__thiscall*)(Chunk* self, bool smoothLighting, bool shadows, bool lights)>(getFuncAddr((int)Func::Chunk::updateMesh))(this, smoothLighting, shadows, lights);
		}
		bool load(const stl::path& chunksFolderPath, World* world)
		{
			return reinterpret_cast<bool (__thiscall*)(Chunk* self, const stl::path& chunksFolderPath, World* world)>(getFuncAddr((int)Func::Chunk::load))(this, chunksFolderPath, world);
		}
		void save(const stl::path& chunksFolderPath)
		{
			return reinterpret_cast<void (__thiscall*)(Chunk* self, const stl::path& chunksFolderPath)>(getFuncAddr((int)Func::Chunk::save))(this, chunksFolderPath);
		}
		void loadFromMessage(const Connection::InMessage& message, World* world) 
		{
			return reinterpret_cast<void (__thiscall*)(Chunk* self, const Connection::InMessage& message, World* world)>(getFuncAddr((int)Func::Chunk::loadFromMessage))(this, message, world);
		}
		void updateCacheSection(const Chunk* other, bool shadows) 
		{
			return reinterpret_cast<void (__thiscall*)(Chunk* self, const Chunk* other, bool shadows)>(getFuncAddr((int)Func::Chunk::updateCacheSection))(this, other, shadows);
		}
		void updateHeightmapCacheSection(glm::i64vec3 borderingChunkPos) 
		{
			return reinterpret_cast<void (__thiscall*)(Chunk* self, glm::i64vec3 borderingChunkPos)>(getFuncAddr((int)Func::Chunk::updateHeightmapCacheSection))(this, borderingChunkPos);
		}
		void generateMeshSection(Chunk::ChunkMesh& mesh, unsigned char startY, bool smoothLighting, bool shadows, bool lights) 
		{
			return reinterpret_cast<void (__thiscall*)(Chunk* self, Chunk::ChunkMesh& mesh, unsigned char startY, bool smoothLighting, bool shadows, bool lights)>(getFuncAddr((int)Func::Chunk::generateMeshSection))(this, mesh, startY, smoothLighting, shadows, lights);
		}
		void getSmoothLighting(const glm::ivec4& block, unsigned char face, BlockInfo::VertLighting lighting[8], bool shadows, bool lights) 
		{
			return reinterpret_cast<void (__thiscall*)(Chunk* self, const glm::ivec4& block, unsigned char face, BlockInfo::VertLighting* lighting, bool shadows, bool lights)>(getFuncAddr((int)Func::Chunk::getSmoothLighting))(this, block, face, lighting, shadows, lights);
		}
		void getLighting(const glm::ivec4& block, unsigned char face, BlockInfo::VertLighting lighting[8], bool shadows, bool lights) 
		{
			return reinterpret_cast<void (__thiscall*)(Chunk* self, const glm::ivec4& block, unsigned char face, BlockInfo::VertLighting* lighting, bool shadows, bool lights)>(getFuncAddr((int)Func::Chunk::getLighting))(this, block, face, lighting, shadows, lights);
		}
		void enableMesh() 
		{
			return reinterpret_cast<void (__thiscall*)(Chunk* self)>(getFuncAddr((int)Func::Chunk::enableMesh))(this);
		}
		void loadEntitiesFromJson(nlohmann::json& j, World* world) 
		{
			return reinterpret_cast<void (__thiscall*)(Chunk* self, nlohmann::json& j, World* world)>(getFuncAddr((int)Func::Chunk::loadEntitiesFromJson))(this, j, world);
		}
		stl::string getFilenamePrefix() 
		{
			stl::string result;
			return reinterpret_cast<stl::string& (__thiscall*)(Chunk* self, stl::string* result)>(getFuncAddr((int)Func::Chunk::getFilenamePrefix))(this, &result);
			return result;
		}
	};
}
