#pragma once

#include "4dm.h"

namespace fdm 
{
	class World 
	{
	public:
		inline static const float gravity = -32f; 
		std::recursive_mutex chunksMutex; // 0x8
		std::unordered_map<glm::i64vec3,std::unique_ptr<Chunk,std::default_delete<Chunk> >,std::hash<glm::i64vec3 >,std::equal_to<glm::i64vec3 >,std::allocator<std::pair<glm::i64vec3 const ,std::unique_ptr<Chunk,std::default_delete<Chunk> > > > > chunks; // 0x58
		std::mutex entitiesMutex; // 0x98
		EntityManager entities; // 0xE8

		World() 
		{
			return reinterpret_cast<void(__thiscall*)(World* self)>(FUNC_WORLD_WORLD)(this);
		}
		Chunk getChunk(const glm::i64vec3& chunkPos) 
		{
			return reinterpret_cast<Chunk (__thiscall*)(World* self, const glm::i64vec3& chunkPos)>(FUNC_WORLD_GETCHUNK)(this, chunkPos);
		}
		Chunk getChunkFromCoords(float x, float z, float w) 
		{
			return reinterpret_cast<Chunk (__thiscall*)(World* self, float x, float z, float w)>(FUNC_WORLD_GETCHUNKFROMCOORDS)(this, x, z, w);
		}
		Entity getEntityIntersection(glm::vec4& a, glm::vec4& b, const uuid& ignoreEntity) 
		{
			return reinterpret_cast<Entity (__thiscall*)(World* self, glm::vec4& a, glm::vec4& b, const uuid& ignoreEntity)>(FUNC_WORLD_GETENTITYINTERSECTION)(this, a, b, ignoreEntity);
		}
		bool castRay(glm::vec4& currentPos, glm::ivec4& currentBlock, glm::ivec4& intersectBlock, glm::vec4& endpoint) 
		{
			return reinterpret_cast<bool (__thiscall*)(World* self, glm::vec4& currentPos, glm::ivec4& currentBlock, glm::ivec4& intersectBlock, glm::vec4& endpoint)>(FUNC_WORLD_CASTRAY)(this, currentPos, currentBlock, intersectBlock, endpoint);
		}
		bool addEntityToChunk(std::unique_ptr<Entity>& entity, Chunk* c) override
		{
			return reinterpret_cast<bool (__thiscall*)(World* self, std::unique_ptr<Entity>& entity, Chunk* c)>(FUNC_WORLD_ADDENTITYTOCHUNK)(this, entity, c);
		}


		// VIRTUAL FUNCS

		virtual void ~World() = NULL;
		virtual World::Type getType() = NULL;
		virtual void setBlockUpdate(const glm::ivec4&, unsigned char) = NULL;
		virtual void localPlayerEvent(Player *, Packet::ClientPacket, __int64, void *) = NULL;
		virtual void handlePlayerDeath(Player *, std::string_view) = NULL;
	};
}
