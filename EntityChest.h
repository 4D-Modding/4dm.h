#pragma once

#include "4dm.h"
#include "InventoryGrid.h"
#include "InventorySession.h"

namespace fdm 
{
	class EntityChest : public Entity 
	{
	public:
		inline static const int COLS = 4; 
		inline static const int ROWS = 8; 
		inline static const int SLOTS = 32; 
		glm::vec4 pos; // 0x20
		InventoryGrid inventory; // 0x30
		InventorySession openInstance; // 0xB0
		inline static MeshRenderer& wireframeRenderer = *reinterpret_cast<MeshRenderer*>(getDataAddr((int)Data::EntityChest::wireframeRenderer));

		bool isClickable() override
		{
			return reinterpret_cast<bool (__thiscall*)(EntityChest* self)>(getFuncAddr((int)Func::EntityChest::isClickable))(this);
		}
		stl::string getName() override
		{
			stl::string result;
			return reinterpret_cast<stl::string& (__thiscall*)(EntityChest* self, stl::string* result)>(getFuncAddr((int)Func::EntityChest::getName))(this, &result);
			return result;
		}
		void update(World* world, double dt) override
		{
			return reinterpret_cast<void (__thiscall*)(EntityChest* self, World* world, double dt)>(getFuncAddr((int)Func::EntityChest::update))(this, world, dt);
		}
		void render(const World* world, const m4::Mat5& MV, bool glasses) override
		{
			return reinterpret_cast<void (__thiscall*)(EntityChest* self, const World* world, const m4::Mat5& MV, bool glasses)>(getFuncAddr((int)Func::EntityChest::render))(this, world, MV, glasses);
		}
		nlohmann::json saveAttributes() override
		{
			nlohmann::json result;
			return reinterpret_cast<nlohmann::json& (__thiscall*)(EntityChest* self, nlohmann::json* result)>(getFuncAddr((int)Func::EntityChest::saveAttributes))(this, &result);
			return result;
		}
		nlohmann::json getServerUpdateAttributes() override
		{
			nlohmann::json result;
			return reinterpret_cast<nlohmann::json& (__thiscall*)(EntityChest* self, nlohmann::json* result)>(getFuncAddr((int)Func::EntityChest::getServerUpdateAttributes))(this, &result);
			return result;
		}
		void applyServerUpdate(const nlohmann::json& j, World* world) override
		{
			return reinterpret_cast<void (__thiscall*)(EntityChest* self, const nlohmann::json& j, World* world)>(getFuncAddr((int)Func::EntityChest::applyServerUpdate))(this, j, world);
		}
		glm::vec4 getPos() override
		{
			glm::vec4 result;
			return reinterpret_cast<glm::vec4& (__thiscall*)(EntityChest* self, glm::vec4* result)>(getFuncAddr((int)Func::EntityChest::getPos))(this, &result);
			return result;
		}
		void setPos(const glm::vec4& pos) override
		{
			return reinterpret_cast<void (__thiscall*)(EntityChest* self, const glm::vec4& pos)>(getFuncAddr((int)Func::EntityChest::setPos))(this, pos);
		}
		bool action(World* world, Entity* actor, int action, const nlohmann::json& details) override
		{
			return reinterpret_cast<bool (__thiscall*)(EntityChest* self, World* world, Entity* actor, int action, const nlohmann::json& details)>(getFuncAddr((int)Func::EntityChest::action))(this, world, actor, action, details);
		}
		float deathTimer() override
		{
			return reinterpret_cast<float(__thiscall*)(EntityChest * self)>(getFuncAddr((int)Func::EntityChest::deathTimer))(this);
		}
		bool isBlockEntity() override
		{
			return reinterpret_cast<bool(__thiscall*)(EntityChest * self)>(getFuncAddr((int)Func::EntityChest::isBlockEntity))(this);
		}
		bool isIntersectingRay(const Entity::Ray& ray) override
		{
			return reinterpret_cast<bool(__thiscall*)(EntityChest * self, const Entity::Ray&)>(getFuncAddr((int)Func::EntityChest::isIntersectingRay))(this, ray);
		}
		bool shouldSave() override
		{
			return reinterpret_cast<bool(__thiscall*)(EntityChest * self)>(getFuncAddr((int)Func::EntityChest::shouldSave))(this);
		}
		void takeDamage(float damage, World* world) override
		{
			return reinterpret_cast<void(__thiscall*)(EntityChest * self, float, World*)>(getFuncAddr((int)Func::EntityChest::takeDamage))(this, damage, world);
		}
	};
}
