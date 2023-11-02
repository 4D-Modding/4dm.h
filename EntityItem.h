#pragma once

#include "4dm.h"

namespace fdm 
{
	class EntityItem : public Entity 
	{
	public:
		inline static const float COLLECTION_DIST = 0.8f; 
		std::unique_ptr<Item> item; // 0x20
		inline static const float hitboxRadius = 0.1f; 
		Hitbox hitbox; // 0x28
		float rotation; // 0x78
		inline static MeshRenderer* wireframeRenderer = reinterpret_cast<MeshRenderer*>((base + 0x279540));
		PAD(0x4);
		double spawnTime; // 0x80
		inline static const float serverUpdateDelay = 0.5f; 
		double lastServerUpdateTime; // 0x88

		inline static std::unique_ptr<Entity> createWithItem(const std::unique_ptr<Item>& item, const glm::vec4& pos, const glm::vec4& vel) 
		{
			return reinterpret_cast<std::unique_ptr<Entity> (__fastcall*)(const std::unique_ptr<Item>& item, const glm::vec4& pos, const glm::vec4& vel)>(FUNC_ENTITYITEM_CREATEWITHITEM)(item, pos, vel);
		}
		std::string getName() override
		{
			std::string result;
			return reinterpret_cast<std::string (__thiscall*)(EntityItem* self, std::string* result)>(FUNC_ENTITYITEM_GETNAME)(this, &result);
			return result;
		}
		void update(World* world, double dt) override
		{
			return reinterpret_cast<void (__thiscall*)(EntityItem* self, World* world, double dt)>(FUNC_ENTITYITEM_UPDATE)(this, world, dt);
		}
		void render(const World* world, const m4::Mat5& MV, bool glasses) override
		{
			return reinterpret_cast<void (__thiscall*)(EntityItem* self, const World* world, const m4::Mat5& MV, bool glasses)>(FUNC_ENTITYITEM_RENDER)(this, world, MV, glasses);
		}
		nlohmann::json saveAttributes() override
		{
			nlohmann::json result;
			return reinterpret_cast<nlohmann::json (__thiscall*)(EntityItem* self, nlohmann::json* result)>(FUNC_ENTITYITEM_SAVEATTRIBUTES)(this, &result);
			return result;
		}
		void applyServerUpdate(const nlohmann::json& j, World* world) override
		{
			return reinterpret_cast<void (__thiscall*)(EntityItem* self, const nlohmann::json& j, World* world)>(FUNC_ENTITYITEM_APPLYSERVERUPDATE)(this, j, world);
		}
		glm::vec4 getPos() override
		{
			glm::vec4 result;
			return reinterpret_cast<glm::vec4 (__thiscall*)(EntityItem* self, glm::vec4* result)>(FUNC_ENTITYITEM_GETPOS)(this, &result);
			return result;
		}
		void setPos(const glm::vec4& pos) override
		{
			return reinterpret_cast<void (__thiscall*)(EntityItem* self, const glm::vec4& pos)>(FUNC_ENTITYITEM_SETPOS)(this, pos);
		}
		bool shouldSave() override
		{
			return reinterpret_cast<bool (__thiscall*)(EntityItem* self)>(FUNC_ENTITYITEM_SHOULDSAVE)(this);
		}
		bool isIntersectingRay(const Entity::Ray& ray) override
		{
			return reinterpret_cast<bool (__thiscall*)(EntityItem* self, const Entity::Ray& ray)>(FUNC_ENTITYITEM_ISINTERSECTINGRAY)(this, ray);
		}
		uint32_t give(Inventory* inventory, int maxCount) 
		{
			return reinterpret_cast<uint32_t (__thiscall*)(EntityItem* self, Inventory* inventory, int maxCount)>(FUNC_ENTITYITEM_GIVE)(this, inventory, maxCount);
		}
		void combineWithNearby(World* world) 
		{
			return reinterpret_cast<void (__thiscall*)(EntityItem* self, World* world)>(FUNC_ENTITYITEM_COMBINEWITHNEARBY)(this, world);
		}
		inline static void collisionCallback(void* user, Hitbox* hitbox, World* world, const glm::ivec4& collisionBlock, int collisionComp, const glm::vec4& prevVel) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, Hitbox* hitbox, World* world, const glm::ivec4& collisionBlock, int collisionComp, const glm::vec4& prevVel)>(FUNC_ENTITYITEM_COLLISIONCALLBACK)(user, hitbox, world, collisionBlock, collisionComp, prevVel);
		}
	};
}
