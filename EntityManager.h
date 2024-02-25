#pragma once

#include "4dm.h"
#include "Entity.h"

namespace fdm 
{
	class Entity;

	class EntityManager 
	{
	public:
		std::unordered_map<uuid,std::unique_ptr<Entity>> entities;
		std::unordered_map<glm::ivec4,uuid> blockEntities; // 0x40

		std::unique_ptr<Entity>* extract(const uuid& id) 
		{
			return reinterpret_cast<std::unique_ptr<Entity>* (__thiscall*)(EntityManager* self, const uuid& id)>(getFuncAddr((int)Func::EntityManager::extract))(this, id);
		}
		Entity* get(const uuid& id) 
		{
			return reinterpret_cast<Entity* (__thiscall*)(EntityManager* self, const uuid& id)>(getFuncAddr((int)Func::EntityManager::get))(this, id);
		}
		Entity* getBlockEntity(const glm::ivec4& pos) 
		{
			return reinterpret_cast<Entity* (__thiscall*)(EntityManager* self, const glm::ivec4& pos)>(getFuncAddr((int)Func::EntityManager::getBlockEntity))(this, pos);
		}
	};
}
