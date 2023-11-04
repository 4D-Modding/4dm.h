#pragma once

#include "4dm.h"
#include "Chunk.h"
#include "EntityManager.h"
#include "Player.h"

namespace fdm 
{
	class World 
	{
	public:
		enum Type
		{
			TYPE_CLIENT,
			TYPE_SERVER,
			TYPE_SINGLEPLAYER,
			TYPE_TITLESCREEN
		};

		inline static const float gravity = -32.f; 
		std::recursive_mutex chunksMutex; // 0x8
		std::unordered_map<glm::i64vec3,std::unique_ptr<Chunk>> chunks; // 0x58
		std::mutex entitiesMutex; // 0x98
		EntityManager entities; // 0xE8

		World() 
		{
			reinterpret_cast<void(__thiscall*)(World* self)>(FUNC_WORLD_WORLD)(this);
		}
		Chunk* getChunk(const glm::i64vec3& chunkPos) 
		{
			return reinterpret_cast<Chunk* (__thiscall*)(World* self, const glm::i64vec3& chunkPos)>(FUNC_WORLD_GETCHUNK)(this, chunkPos);
		}
		Chunk* getChunkFromCoords(float x, float z, float w) 
		{
			return reinterpret_cast<Chunk* (__thiscall*)(World* self, float x, float z, float w)>(FUNC_WORLD_GETCHUNKFROMCOORDS)(this, x, z, w);
		}
		Entity* getEntityIntersection(glm::vec4& a, glm::vec4& b, const uuid& ignoreEntity) 
		{
			return reinterpret_cast<Entity* (__thiscall*)(World* self, glm::vec4& a, glm::vec4& b, const uuid& ignoreEntity)>(FUNC_WORLD_GETENTITYINTERSECTION)(this, a, b, ignoreEntity);
		}
		bool castRay(glm::vec4& currentPos, glm::ivec4& currentBlock, glm::ivec4& intersectBlock, glm::vec4& endpoint) 
		{
			return reinterpret_cast<bool (__thiscall*)(World* self, glm::vec4& currentPos, glm::ivec4& currentBlock, glm::ivec4& intersectBlock, glm::vec4& endpoint)>(FUNC_WORLD_CASTRAY)(this, currentPos, currentBlock, intersectBlock, endpoint);
		}
		
		// VIRTUAL FUNCS

		virtual ~World() {}
		virtual World::Type getType() { return TYPE_CLIENT; }
		virtual void setBlockUpdate(const glm::ivec4& block, unsigned char value) {}
		virtual bool addEntityToChunk(std::unique_ptr<Entity>& entity, Chunk* c)
		{
			return reinterpret_cast<bool(__thiscall*)(World * self, std::unique_ptr<Entity>& entity, Chunk* c)>(FUNC_WORLD_ADDENTITYTOCHUNK)(this, entity, c);
		}
		virtual void localPlayerEvent(Player* player, Packet::ClientPacket eventType, int64_t eventValue, void* data) {}
		virtual void handlePlayerDeath(Player* player, std::string_view reason) {}
	};
}
