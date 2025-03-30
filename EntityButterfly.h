#pragma once

#include "4dm.h"

namespace fdm 
{
	class EntityButterfly : public Entity 
	{
	public:
		struct ButterflyType 
		{
			const glm::vec4 colorA; 
			const glm::vec4 colorB; // 0x10
		};
		Hitbox hitbox; // 0x20
		glm::vec4 direction; // 0x70
		float health; // 0x80
		PAD(0x4);
		double hitTime; // 0x88
		int type; // 0x90
		PAD(0x4);
		double remainingFlapTime; // 0x98
		bool shouldUpdate; // 0xA0
		PAD(0x3);
		float flapAnimProgress; // 0xA4
		m4::BiVector4 rotationPlane; // 0xA8
		float angleToRotate; // 0xC0

		inline static std::array<const glm::u8vec3, 8>& wing_tuv = *reinterpret_cast<std::array<const glm::u8vec3, 8>*>(getDataAddr((int)Data::EntityButterfly::wing_tuv));
		inline static constexpr const float hitboxRadius = 1.4f;
		inline static constexpr const float maxSpeed = 1.8f;
		inline static constexpr const float hitDelay = 0.7f;
		inline static constexpr const int NUM_TYPES = 4;
		inline static std::array<EntityButterfly::ButterflyType, 4>& ButterflyTypes = *reinterpret_cast<std::array<EntityButterfly::ButterflyType, 4>*>(getDataAddr((int)Data::EntityButterfly::ButterflyTypes));
		inline static MeshRenderer& wingRenderer = *reinterpret_cast<MeshRenderer*>(getDataAddr((int)Data::EntityButterfly::wingRenderer));
		inline static MeshRenderer& wireframeRenderer = *reinterpret_cast<MeshRenderer*>(getDataAddr((int)Data::EntityButterfly::wireframeRenderer));
		inline static constexpr const double minFlapDelay = 0.2f;
		inline static constexpr const double maxFlapDelay = 0.7f;

		bool action(World* world, Entity* actor, int action, const nlohmann::json& details) override
		{
			return reinterpret_cast<bool(__thiscall*)(EntityButterfly * self, World*, Entity*, int, const nlohmann::json&)>(getFuncAddr((int)Func::EntityButterfly::action))(this, world, actor, action, details);
		}
		float deathTimer() override
		{
			return reinterpret_cast<float(__thiscall*)(EntityButterfly * self)>(getFuncAddr((int)Func::EntityButterfly::deathTimer))(this);
		}
		stl::string getName() override
		{
			stl::string result;
			return reinterpret_cast<stl::string& (__thiscall*)(EntityButterfly* self, stl::string* result)>(getFuncAddr((int)Func::EntityButterfly::getName))(this, &result);
			return result;
		}
		void update(World* world, double dt) override
		{
			return reinterpret_cast<void (__thiscall*)(EntityButterfly* self, World* world, double dt)>(getFuncAddr((int)Func::EntityButterfly::update))(this, world, dt);
		}
		void render(const World* world, const m4::Mat5& MV, bool glasses) override
		{
			return reinterpret_cast<void (__thiscall*)(EntityButterfly* self, const World* world, const m4::Mat5& MV, bool glasses)>(getFuncAddr((int)Func::EntityButterfly::render))(this, world, MV, glasses);
		}
		nlohmann::json getServerUpdateAttributes() override
		{
			nlohmann::json result;
			return reinterpret_cast<nlohmann::json& (__thiscall*)(EntityButterfly* self, nlohmann::json* result)>(getFuncAddr((int)Func::EntityButterfly::getServerUpdateAttributes))(this, &result);
			return result;
		}
		void applyServerUpdate(const nlohmann::json& j, World* world) override
		{
			return reinterpret_cast<void (__thiscall*)(EntityButterfly* self, const nlohmann::json& j, World* world)>(getFuncAddr((int)Func::EntityButterfly::applyServerUpdate))(this, j, world);
		}
		void takeDamage(float damage, World* world) override
		{
			return reinterpret_cast<void (__thiscall*)(EntityButterfly* self, float damage, World* world)>(getFuncAddr((int)Func::EntityButterfly::takeDamage))(this, damage, world);
		}
		void playHitSound() 
		{
			return reinterpret_cast<void (__thiscall*)(EntityButterfly* self)>(getFuncAddr((int)Func::EntityButterfly::playHitSound))(this);
		}
		void playDeathSound() 
		{
			return reinterpret_cast<void (__thiscall*)(EntityButterfly* self)>(getFuncAddr((int)Func::EntityButterfly::playDeathSound))(this);
		}
		glm::vec4 getPos() override
		{
			return reinterpret_cast<glm::vec4(__thiscall*)(EntityButterfly * self)>(getFuncAddr((int)Func::EntityButterfly::getPos))(this);
		}
		bool isBlockEntity() override
		{
			return reinterpret_cast<bool(__thiscall*)(EntityButterfly * self)>(getFuncAddr((int)Func::EntityButterfly::isBlockEntity))(this);
		}
		bool isClickable() override
		{
			return reinterpret_cast<bool(__thiscall*)(EntityButterfly * self)>(getFuncAddr((int)Func::EntityButterfly::isClickable))(this);
		}
		bool isIntersectingRay(const Entity::Ray& ray) override
		{
			return reinterpret_cast<bool(__thiscall*)(EntityButterfly * self, const Entity::Ray&)>(getFuncAddr((int)Func::EntityButterfly::isIntersectingRay))(this, ray);
		}
		nlohmann::json saveAttributes() override
		{
			return reinterpret_cast<nlohmann::json(__thiscall*)(EntityButterfly * self)>(getFuncAddr((int)Func::EntityButterfly::saveAttributes))(this);
		}
		void setPos(const glm::vec4& pos) override
		{
			return reinterpret_cast<void(__thiscall*)(EntityButterfly * self, const glm::vec4&)>(getFuncAddr((int)Func::EntityButterfly::setPos))(this, pos);
		}
		bool shouldSave() override
		{
			return reinterpret_cast<bool(__thiscall*)(EntityButterfly * self)>(getFuncAddr((int)Func::EntityButterfly::shouldSave))(this);
		}
		inline static void collisionCallback(void* user, Hitbox* hitbox, World* world, const glm::ivec4& collisionBlock, int collisionComp, const glm::vec4& prevVel) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, Hitbox* hitbox, World* world, const glm::ivec4& collisionBlock, int collisionComp, const glm::vec4& prevVel)>(getFuncAddr((int)Func::EntityButterfly::collisionCallback))(user, hitbox, world, collisionBlock, collisionComp, prevVel);
		}
		inline static void renderInit()
		{
			return reinterpret_cast<void(__fastcall*)()>(getFuncAddr((int)Func::EntityButterfly::renderInit))();
		}
		inline static void renderLens()
		{
			return reinterpret_cast<void(__fastcall*)()>(getFuncAddr((int)Func::EntityButterfly::renderLens))();
		}
	};
}
