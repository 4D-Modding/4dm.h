#pragma once

#include "4dm.h"
#include "Entity.h"
#include "World.h"

namespace fdm 
{
	class Hitbox;
	using CollisionCallback = std::add_pointer<void(void* user, Hitbox* hitbox, World* world, const glm::ivec4& collisionBlock, int collisionComp, const glm::vec4& prevVel)>::type;
	class Hitbox 
	{
	public:
		glm::vec4 halfDimensions; 
		glm::vec4 pos; // 0x10
		glm::vec4 vel; // 0x20
		glm::vec4 deltaVel; // 0x30
		CollisionCallback collisionCallback = NULL; // 0x40
		void* userPtr; // 0x48

		void addVelWithMaxHorizSpeed(const glm::vec4& adjustment, float maxHorizSpeed) 
		{
			return reinterpret_cast<void (__thiscall*)(Hitbox* self, const glm::vec4& adjustment, float maxHorizSpeed)>(getFuncAddr((int)Func::Hitbox::addVelWithMaxHorizSpeed))(this, adjustment, maxHorizSpeed);
		}
		void update(World* world, double dt) 
		{
			return reinterpret_cast<void (__thiscall*)(Hitbox* self, World* world, double dt)>(getFuncAddr((int)Func::Hitbox::update))(this, world, dt);
		}
		bool isIntersectingRay(const Entity::Ray& ray) 
		{
			return reinterpret_cast<bool (__thiscall*)(Hitbox* self, const Entity::Ray& ray)>(getFuncAddr((int)Func::Hitbox::isIntersectingRay))(this, ray);
		}
		bool takeStep(World* world, uint32_t comp, float step) 
		{
			return reinterpret_cast<bool (__thiscall*)(Hitbox* self, World* world, uint32_t comp, float step)>(getFuncAddr((int)Func::Hitbox::takeStep))(this, world, comp, step);
		}
	};
}
