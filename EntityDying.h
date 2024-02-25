#pragma once

#include "4dm.h"

namespace fdm 
{
	class EntityDying : public Entity 
	{
	public:
		std::unique_ptr<Entity> entity; // 0x20
		double deathTime; // 0x28

		float deathTimer() override
		{
			return reinterpret_cast<float (__thiscall*)(EntityDying* self)>(getFuncAddr((int)Func::EntityDying::deathTimer))(this);
		}
		inline static std::unique_ptr<Entity> createWithEntity(const std::unique_ptr<Entity>& entity, uuid* id) 
		{
			return reinterpret_cast<std::unique_ptr<Entity> (__fastcall*)(const std::unique_ptr<Entity>&entity, uuid* id)>(getFuncAddr((int)Func::EntityDying::createWithEntity))(entity, id);
		}
		std::string getName() override
		{
			std::string result;
			return reinterpret_cast<std::string (__thiscall*)(EntityDying* self, std::string* result)>(getFuncAddr((int)Func::EntityDying::getName))(this, &result);
			return result;
		}
		void update(World* world, double dt) override
		{
			return reinterpret_cast<void (__thiscall*)(EntityDying* self, World* world, double dt)>(getFuncAddr((int)Func::EntityDying::update))(this, world, dt);
		}
		void render(const World* world, const m4::Mat5& MV, bool glasses) override
		{
			return reinterpret_cast<void (__thiscall*)(EntityDying* self, const World* world, const m4::Mat5& MV, bool glasses)>(getFuncAddr((int)Func::EntityDying::render))(this, world, MV, glasses);
		}
		nlohmann::json getServerUpdateAttributes() override
		{
			nlohmann::json result;
			return reinterpret_cast<nlohmann::json (__thiscall*)(EntityDying* self, nlohmann::json* result)>(getFuncAddr((int)Func::EntityDying::getServerUpdateAttributes))(this, &result);
			return result;
		}
		void applyServerUpdate(const nlohmann::json& j, World* world) override
		{
			return reinterpret_cast<void (__thiscall*)(EntityDying* self, const nlohmann::json& j, World* world)>(getFuncAddr((int)Func::EntityDying::applyServerUpdate))(this, j, world);
		}
		glm::vec4 getPos() override
		{
			glm::vec4 result;
			return reinterpret_cast<glm::vec4 (__thiscall*)(EntityDying* self, glm::vec4* result)>(getFuncAddr((int)Func::EntityDying::getPos))(this, &result);
			return result;
		}
		void setPos(const glm::vec4& pos) override
		{
			return reinterpret_cast<void (__thiscall*)(EntityDying* self, const glm::vec4& pos)>(getFuncAddr((int)Func::EntityDying::setPos))(this, pos);
		}
		bool isBlockEntity() override
		{
			return reinterpret_cast<bool (__thiscall*)(EntityDying* self)>(getFuncAddr((int)Func::EntityDying::isBlockEntity))(this);
		}
		bool isIntersectingRay(const Entity::Ray& ray) override
		{
			return reinterpret_cast<bool (__thiscall*)(EntityDying* self, const Entity::Ray& ray)>(getFuncAddr((int)Func::EntityDying::isIntersectingRay))(this, ray);
		}
	};
}
