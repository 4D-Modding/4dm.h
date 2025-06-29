#pragma once

#include "4dm.h"
#include "Chunk.h"
#include "EntityManager.h"

namespace fdm 
{
	class Player;
	class World 
	{
	public:
		enum Type : int
		{
			TYPE_CLIENT,
			TYPE_SERVER,
			TYPE_SINGLEPLAYER,
			TYPE_TITLESCREEN
		};

		inline static const float gravity = -32.0f; 
		std::recursive_mutex chunksMutex; // 0x8
		std::unordered_map<glm::i64vec3,std::unique_ptr<Chunk>> chunks; // 0x58
		std::mutex entitiesMutex; // 0x98
		EntityManager entities; // 0xE8

		World() 
		{
			reinterpret_cast<void(__thiscall*)(World* self)>(getFuncAddr((int)Func::World::World))(this);
		}
		Chunk* getChunk(const glm::i64vec3& chunkPos) 
		{
			return reinterpret_cast<Chunk* (__thiscall*)(World* self, const glm::i64vec3& chunkPos)>(getFuncAddr((int)Func::World::getChunk))(this, chunkPos);
		}
		Chunk* getChunkFromCoords(float x, float z, float w) 
		{
			return reinterpret_cast<Chunk* (__thiscall*)(World* self, float x, float z, float w)>(getFuncAddr((int)Func::World::getChunkFromCoords))(this, x, z, w);
		}
		Entity* getEntityIntersection(glm::vec4& a, glm::vec4& b, const stl::uuid& ignoreEntity) 
		{
			return reinterpret_cast<Entity* (__thiscall*)(World* self, glm::vec4& a, glm::vec4& b, const stl::uuid& ignoreEntity)>(getFuncAddr((int)Func::World::getEntityIntersection))(this, a, b, ignoreEntity);
		}
		bool castRay(glm::vec4& currentPos, glm::ivec4& currentBlock, glm::ivec4& intersectBlock, glm::vec4& endpoint) 
		{
			return reinterpret_cast<bool (__thiscall*)(World* self, glm::vec4& currentPos, glm::ivec4& currentBlock, glm::ivec4& intersectBlock, glm::vec4& endpoint)>(getFuncAddr((int)Func::World::castRay))(this, currentPos, currentBlock, intersectBlock, endpoint);
		}
		/*uint8_t getBlock(const glm::ivec4& block)
		{
			return reinterpret_cast<uint8_t(__thiscall*)(World * self, const glm::ivec4&)>(getFuncAddr((int)Func::World::getBlock))(this, block);
		}*/
		uint8_t getBlock(const glm::ivec4& block)
		{
			if (block.y >= Chunk::HEIGHT || block.y < 0)
			{
				return 0;
			}

			Chunk* c = getChunkFromCoords(block.x, block.z, block.w);
			if (c != nullptr)
			{
				// coords must be floats
				glm::vec4 coords = block;

				glm::ivec4 b = {
					coords.x - (glm::floor(coords.x / Chunk::SIZE) * Chunk::SIZE),
					coords.y,
					coords.z - (glm::floor(coords.z / Chunk::SIZE) * Chunk::SIZE),
					coords.w - (glm::floor(coords.w / Chunk::SIZE) * Chunk::SIZE),
				};

				return c->blocks[b.x + 1][b.z + 1][b.w + 1][b.y];
			}
			return BlockInfo::BARRIER;
		}

		// only available for server
		/*Entity* getEntity(const stl::uuid& id)
		{
			return reinterpret_cast<Entity* (__thiscall*)(World* self, const stl::uuid&)>(getFuncAddr((int)Func::World::getEntity))(this, id);
		}*/

		Entity* getEntity(const stl::uuid& id)
		{
			std::lock_guard<std::mutex> lock(entitiesMutex);
			return entities.get(id);
		}
		
		// VIRTUAL FUNCS

		virtual ~World() {}
		virtual World::Type getType() { return TYPE_CLIENT; }
		virtual void setBlockUpdate(const glm::ivec4& block, uint8_t value) {}
		virtual bool addEntityToChunk(std::unique_ptr<Entity>& entity, Chunk* c)
		{
			return reinterpret_cast<bool(__thiscall*)(World * self, std::unique_ptr<Entity>& entity, Chunk* c)>(getFuncAddr((int)Func::World::addEntityToChunk))(this, entity, c);
		}
		virtual void localPlayerEvent(Player* player, Packet::ClientPacket eventType, int64_t eventValue, void* data) {}
		virtual void handlePlayerDeath(Player* player, std::string_view reason)
		{
			return reinterpret_cast<void(__thiscall*)(World * self, Player*, std::basic_string_view<char, std::char_traits<char> >)>(getFuncAddr((int)Func::World::handlePlayerDeath))(this, player, reason);
		}
	};
}
