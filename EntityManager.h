#pragma once

#include "4dm.h"
#include "Entity.h"

namespace fdm 
{
	class Entity;

	class EntityManager 
	{
	public:
		std::unordered_map<stl::uuid, std::unique_ptr<Entity>> entities;
		std::unordered_map<glm::ivec4,stl::uuid> blockEntities; // 0x40

		std::unique_ptr<Entity>* extract(const stl::uuid& id) 
		{
			return reinterpret_cast<std::unique_ptr<Entity>* (__thiscall*)(EntityManager* self, const stl::uuid& id)>(getFuncAddr((int)Func::EntityManager::extract))(this, id);
		}
		Entity* get(const stl::uuid& id) 
		{
			return reinterpret_cast<Entity* (__thiscall*)(EntityManager* self, const stl::uuid& id)>(getFuncAddr((int)Func::EntityManager::get))(this, id);
		}
		void relocateBlockEntities()
		{
			return reinterpret_cast<void(__thiscall*)(EntityManager * self)>(getFuncAddr((int)Func::EntityManager::relocateBlockEntities))(this);
		}
		Entity* getBlockEntity(const glm::ivec4& pos) 
		{
			return reinterpret_cast<Entity* (__thiscall*)(EntityManager* self, const glm::ivec4& pos)>(getFuncAddr((int)Func::EntityManager::getBlockEntity))(this, pos);
		}
	};
}
