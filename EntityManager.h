#pragma once

#include "4dm.h"

namespace fdm 
{
	class EntityManager 
	{
	public:
		PAD(0x40); // --> std::unordered_map<uuid,std::unique_ptr<Entity,std::default_delete<Entity> >,boost::hash<uuid>,std::equal_to<uuid>,std::allocator<std::pair<uuid const ,std::unique_ptr<Entity,std::default_delete<Entity> > > > > entities
		std::unordered_map<glm::ivec4,uuid,std::hash<glm::ivec4 >,std::equal_to<glm::ivec4 >,std::allocator<std::pair<glm::ivec4 const ,uuid> > > blockEntities; // 0x40

		std::unique_ptr<Entity,std::default_delete<Entity> > extract(const uuid& id) 
		{
			return reinterpret_cast<std::unique_ptr<Entity,std::default_delete<Entity> > (__thiscall*)(EntityManager* self, std::unique_ptr<Entity>& result, const uuid& id)>(FUNC_ENTITYMANAGER_EXTRACT)(this, result, id);
		}
		Entity get(const uuid& id) 
		{
			return reinterpret_cast<Entity (__thiscall*)(EntityManager* self, const uuid& id)>(FUNC_ENTITYMANAGER_GET)(this, id);
		}
		Entity getBlockEntity(const glm::ivec4& pos) 
		{
			return reinterpret_cast<Entity (__thiscall*)(EntityManager* self, const glm::ivec4& pos)>(FUNC_ENTITYMANAGER_GETBLOCKENTITY)(this, pos);
		}
	};
}
