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
		inline static MeshRenderer* wireframeRenderer = reinterpret_cast<MeshRenderer*>((base + 0x2788E8));

		bool isClickable() override
		{
			return reinterpret_cast<bool (__thiscall*)(EntityChest* self)>(FUNC_ENTITYCHEST_ISCLICKABLE)(this);
		}
		std::string getName() override
		{
			std::string result;
			return reinterpret_cast<std::string (__thiscall*)(EntityChest* self, std::string* result)>(FUNC_ENTITYCHEST_GETNAME)(this, &result);
			return result;
		}
		void update(World* world, double dt) override
		{
			return reinterpret_cast<void (__thiscall*)(EntityChest* self, World* world, double dt)>(FUNC_ENTITYCHEST_UPDATE)(this, world, dt);
		}
		void render(const World* world, const m4::Mat5& MV, bool glasses) override
		{
			return reinterpret_cast<void (__thiscall*)(EntityChest* self, const World* world, const m4::Mat5& MV, bool glasses)>(FUNC_ENTITYCHEST_RENDER)(this, world, MV, glasses);
		}
		nlohmann::json saveAttributes() override
		{
			nlohmann::json result;
			return reinterpret_cast<nlohmann::json (__thiscall*)(EntityChest* self, nlohmann::json* result)>(FUNC_ENTITYCHEST_SAVEATTRIBUTES)(this, &result);
			return result;
		}
		nlohmann::json getServerUpdateAttributes() override
		{
			nlohmann::json result;
			return reinterpret_cast<nlohmann::json (__thiscall*)(EntityChest* self, nlohmann::json* result)>(FUNC_ENTITYCHEST_GETSERVERUPDATEATTRIBUTES)(this, &result);
			return result;
		}
		void applyServerUpdate(const nlohmann::json& j, World* world) override
		{
			return reinterpret_cast<void (__thiscall*)(EntityChest* self, const nlohmann::json& j, World* world)>(FUNC_ENTITYCHEST_APPLYSERVERUPDATE)(this, j, world);
		}
		glm::vec4 getPos() override
		{
			glm::vec4 result;
			return reinterpret_cast<glm::vec4 (__thiscall*)(EntityChest* self, glm::vec4* result)>(FUNC_ENTITYCHEST_GETPOS)(this, &result);
			return result;
		}
		void setPos(const glm::vec4& pos) override
		{
			return reinterpret_cast<void (__thiscall*)(EntityChest* self, const glm::vec4& pos)>(FUNC_ENTITYCHEST_SETPOS)(this, pos);
		}
		bool action(World* world, Entity* actor, int action, const nlohmann::json& details) override
		{
			return reinterpret_cast<bool (__thiscall*)(EntityChest* self, World* world, Entity* actor, int action, const nlohmann::json& details)>(FUNC_ENTITYCHEST_ACTION)(this, world, actor, action, details);
		}
	};
}
