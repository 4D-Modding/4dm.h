#pragma once

#include "4dm.h"

namespace fdm 
{
	class EntityDying : public Entity 
	{
	public:
		std::unique_ptr<Entity> entity; // 0x20
		float deathTime; // 0x28

		float deathTimer() override
		{
			return reinterpret_cast<float (__thiscall*)(EntityDying* self)>(FUNC_ENTITYDYING_DEATHTIMER)(this);
		}
		inline static std::unique_ptr<Entity> createWithEntity(const std::unique_ptr<Entity>& entity, uuid* id) 
		{
			return reinterpret_cast<std::unique_ptr<Entity> (__fastcall*)(const std::unique_ptr<Entity>&entity, uuid* id)>(FUNC_ENTITYDYING_CREATEWITHENTITY)(entity, id);
		}
		std::string getName() override
		{
			std::string result;
			return reinterpret_cast<std::string (__thiscall*)(EntityDying* self, std::string* result)>(FUNC_ENTITYDYING_GETNAME)(this, &result);
			return result;
		}
		void update(World* world, double dt) override
		{
			return reinterpret_cast<void (__thiscall*)(EntityDying* self, World* world, double dt)>(FUNC_ENTITYDYING_UPDATE)(this, world, dt);
		}
		void render(const World* world, const m4::Mat5& MV, bool glasses) override
		{
			return reinterpret_cast<void (__thiscall*)(EntityDying* self, const World* world, const m4::Mat5& MV, bool glasses)>(FUNC_ENTITYDYING_RENDER)(this, world, MV, glasses);
		}
		nlohmann::json getServerUpdateAttributes() override
		{
			nlohmann::json result;
			return reinterpret_cast<nlohmann::json (__thiscall*)(EntityDying* self, nlohmann::json* result)>(FUNC_ENTITYDYING_GETSERVERUPDATEATTRIBUTES)(this, &result);
			return result;
		}
		void applyServerUpdate(const nlohmann::json& j, World* world) override
		{
			return reinterpret_cast<void (__thiscall*)(EntityDying* self, const nlohmann::json& j, World* world)>(FUNC_ENTITYDYING_APPLYSERVERUPDATE)(this, j, world);
		}
		glm::vec4 getPos() override
		{
			glm::vec4 result;
			return reinterpret_cast<glm::vec4 (__thiscall*)(EntityDying* self, glm::vec4* result)>(FUNC_ENTITYDYING_GETPOS)(this, &result);
			return result;
		}
		void setPos(const glm::vec4& pos) override
		{
			return reinterpret_cast<void (__thiscall*)(EntityDying* self, const glm::vec4& pos)>(FUNC_ENTITYDYING_SETPOS)(this, pos);
		}
		bool isBlockEntity() override
		{
			return reinterpret_cast<bool (__thiscall*)(EntityDying* self)>(FUNC_ENTITYDYING_ISBLOCKENTITY)(this);
		}
		bool isIntersectingRay(const Entity::Ray& ray) override
		{
			return reinterpret_cast<bool (__thiscall*)(EntityDying* self, const Entity::Ray& ray)>(FUNC_ENTITYDYING_ISINTERSECTINGRAY)(this, ray);
		}
	};
}
