#pragma once

#include "4dm.h"

namespace fdm 
{
	class EntityItem : public Entity 
	{
	public:
		std::unique_ptr<Item> item; // 0x20
		Hitbox hitbox; // 0x28
		float rotation; // 0x78
		PAD(0x4);
		double spawnTime; // 0x80
		double lastServerUpdateTime; // 0x88

		inline static constexpr const float COLLECTION_DIST = 0.8f;
		inline static constexpr const float hitboxRadius = 0.1f;
		inline static MeshRenderer& wireframeRenderer = *reinterpret_cast<MeshRenderer*>(getDataAddr((int)Data::EntityItem::wireframeRenderer));
		inline static constexpr const float serverUpdateDelay = 0.5f;

		bool action(World* world, Entity* actor, int action, const nlohmann::json& details) override
		{
			return reinterpret_cast<bool(__thiscall*)(EntityItem * self, World*, Entity*, int, const nlohmann::json&)>(getFuncAddr((int)Func::EntityItem::action))(this, world, actor, action, details);
		}
		inline static std::unique_ptr<Entity> createWithItem(std::unique_ptr<Item> item, const glm::vec4& pos, const glm::vec4& vel)
		{
			std::unique_ptr<Entity> result;
			reinterpret_cast<std::unique_ptr<Entity>&(__fastcall*)(std::unique_ptr<Entity>*, std::unique_ptr<Item>, const glm::vec4&, const glm::vec4&)>(getFuncAddr((int)Func::EntityItem::createWithItem))(&result, std::move(item), pos, vel);
			return result;
		}
		stl::string getName() override
		{
			stl::string result;
			return reinterpret_cast<stl::string& (__thiscall*)(EntityItem* self, stl::string* result)>(getFuncAddr((int)Func::EntityItem::getName))(this, &result);
			return result;
		}
		void update(World* world, double dt) override
		{
			return reinterpret_cast<void (__thiscall*)(EntityItem* self, World* world, double dt)>(getFuncAddr((int)Func::EntityItem::update))(this, world, dt);
		}
		void render(const World* world, const m4::Mat5& MV, bool glasses) override
		{
			return reinterpret_cast<void (__thiscall*)(EntityItem* self, const World* world, const m4::Mat5& MV, bool glasses)>(getFuncAddr((int)Func::EntityItem::render))(this, world, MV, glasses);
		}
		nlohmann::json saveAttributes() override
		{
			nlohmann::json result;
			return reinterpret_cast<nlohmann::json& (__thiscall*)(EntityItem* self, nlohmann::json* result)>(getFuncAddr((int)Func::EntityItem::saveAttributes))(this, &result);
			return result;
		}
		void applyServerUpdate(const nlohmann::json& j, World* world) override
		{
			return reinterpret_cast<void (__thiscall*)(EntityItem* self, const nlohmann::json& j, World* world)>(getFuncAddr((int)Func::EntityItem::applyServerUpdate))(this, j, world);
		}
		glm::vec4 getPos() override
		{
			glm::vec4 result;
			return reinterpret_cast<glm::vec4& (__thiscall*)(EntityItem* self, glm::vec4* result)>(getFuncAddr((int)Func::EntityItem::getPos))(this, &result);
			return result;
		}
		void setPos(const glm::vec4& pos) override
		{
			return reinterpret_cast<void (__thiscall*)(EntityItem* self, const glm::vec4& pos)>(getFuncAddr((int)Func::EntityItem::setPos))(this, pos);
		}
		bool shouldSave() override
		{
			return reinterpret_cast<bool (__thiscall*)(EntityItem* self)>(getFuncAddr((int)Func::EntityItem::shouldSave))(this);
		}
		uint32_t give(Inventory* inventory, int maxCount) 
		{
			return reinterpret_cast<uint32_t (__thiscall*)(EntityItem* self, Inventory* inventory, int maxCount)>(getFuncAddr((int)Func::EntityItem::give))(this, inventory, maxCount);
		}
		void combineWithNearby(World* world) 
		{
			return reinterpret_cast<void (__thiscall*)(EntityItem* self, World* world)>(getFuncAddr((int)Func::EntityItem::combineWithNearby))(this, world);
		}
		inline static void collisionCallback(void* user, Hitbox* hitbox, World* world, const glm::ivec4& collisionBlock, int collisionComp, const glm::vec4& prevVel) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, Hitbox* hitbox, World* world, const glm::ivec4& collisionBlock, int collisionComp, const glm::vec4& prevVel)>(getFuncAddr((int)Func::EntityItem::collisionCallback))(user, hitbox, world, collisionBlock, collisionComp, prevVel);
		}
		float deathTimer() override
		{
			return reinterpret_cast<float(__thiscall*)(EntityItem * self)>(getFuncAddr((int)Func::EntityItem::deathTimer))(this);
		}
		nlohmann::json getServerUpdateAttributes() override
		{
			return reinterpret_cast<nlohmann::json(__thiscall*)(EntityItem * self)>(getFuncAddr((int)Func::EntityItem::getServerUpdateAttributes))(this);
		}
		bool isBlockEntity() override
		{
			return reinterpret_cast<bool(__thiscall*)(EntityItem * self)>(getFuncAddr((int)Func::EntityItem::isBlockEntity))(this);
		}
		bool isClickable() override
		{
			return reinterpret_cast<bool(__thiscall*)(EntityItem * self)>(getFuncAddr((int)Func::EntityItem::isClickable))(this);
		}
		bool isIntersectingRay(const Entity::Ray& ray) override
		{
			return reinterpret_cast<bool(__thiscall*)(EntityItem * self, const Entity::Ray&)>(getFuncAddr((int)Func::EntityItem::isIntersectingRay))(this, ray);
		}
		void takeDamage(float damage, World* world) override
		{
			return reinterpret_cast<void(__thiscall*)(EntityItem * self, float, World*)>(getFuncAddr((int)Func::EntityItem::takeDamage))(this, damage, world);
		}
	};
}
