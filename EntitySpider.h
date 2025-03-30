#pragma once

#include "4dm.h"

namespace fdm 
{
	class EntitySpider : public Entity 
	{
	public:
		struct SpiderType 
		{
			const glm::vec4 colorA; 
			const glm::vec4 colorB; // 0x10
			const Dodecaplex mesh; // 0x20
			MeshRenderer bodyRenderer; // 0x78

			~SpiderType() 
			{
				reinterpret_cast<void(__thiscall*)(EntitySpider::SpiderType* self)>(getFuncAddr((int)Func::EntitySpider::SpiderType::destr_SpiderType))(this);
			}
		};
		Hitbox hitbox; // 0x20
		int type; // 0x70
		glm::vec4 direction; // 0x74
		float rotation; // 0x84
		bool touchingGround; // 0x88
		bool shouldJump; // 0x89
		bool walking; // 0x8A
		PAD(0x1);
		glm::vec4 horizAcc; // 0x8C
		float health; // 0x9C
		double hitTime; // 0xA0
		stl::uuid target; // 0xA8
		double lastUpdateTime; // 0xB8
		double lastServerUpdateTime; // 0xC0
		inline static const float hitboxRadius = 0.6f; 
		inline static const float maxSpeed = 3.f; 
		inline static const int NUM_TYPES = 5; 
		inline static std::array<EntitySpider::SpiderType, 5>& spiderTypes = *reinterpret_cast<std::array<EntitySpider::SpiderType, 5>*>(getDataAddr((int)Data::EntitySpider::spiderTypes));
		inline static const int NUM_LEGS = 32; 
		inline static std::array<glm::vec4, 32>& legPositions = *reinterpret_cast<std::array<glm::vec4, 32>*>(getDataAddr((int)Data::EntitySpider::legPositions));
		inline static MeshRenderer& legRenderer = *reinterpret_cast<MeshRenderer*>(getDataAddr((int)Data::EntitySpider::legRenderer));
		inline static const float hitDelay = 0.7f; 
		inline static const float updateDelay = 2.f; 
		inline static const float serverUpdateDelay = 0.5f;
		inline static MeshRenderer& wireframeRenderer = *reinterpret_cast<MeshRenderer*>(getDataAddr((int)Data::EntitySpider::wireframeRenderer));

		bool isIntersectingRay(const Entity::Ray& ray) override
		{
			return reinterpret_cast<bool (__thiscall*)(EntitySpider* self, const Entity::Ray& ray)>(getFuncAddr((int)Func::EntitySpider::isIntersectingRay))(this, ray);
		}
		glm::vec4 getPos() override
		{
			glm::vec4 result;
			return reinterpret_cast<glm::vec4& (__thiscall*)(EntitySpider* self, glm::vec4* result)>(getFuncAddr((int)Func::EntitySpider::getPos))(this, &result);
			return result;
		}
		void setPos(const glm::vec4& pos) override
		{
			return reinterpret_cast<void (__thiscall*)(EntitySpider* self, const glm::vec4& pos)>(getFuncAddr((int)Func::EntitySpider::setPos))(this, pos);
		}
		stl::string getName() override
		{
			stl::string result;
			return reinterpret_cast<stl::string& (__thiscall*)(EntitySpider* self, stl::string* result)>(getFuncAddr((int)Func::EntitySpider::getName))(this, &result);
			return result;
		}
		void update(World* world, double dt) override
		{
			return reinterpret_cast<void (__thiscall*)(EntitySpider* self, World* world, double dt)>(getFuncAddr((int)Func::EntitySpider::update))(this, world, dt);
		}
		void render(const World* world, const m4::Mat5& MV, bool glasses) override
		{
			return reinterpret_cast<void (__thiscall*)(EntitySpider* self, const World* world, const m4::Mat5& MV, bool glasses)>(getFuncAddr((int)Func::EntitySpider::render))(this, world, MV, glasses);
		}
		nlohmann::json saveAttributes() override
		{
			nlohmann::json result;
			return reinterpret_cast<nlohmann::json& (__thiscall*)(EntitySpider* self, nlohmann::json* result)>(getFuncAddr((int)Func::EntitySpider::saveAttributes))(this, &result);
			return result;
		}
		nlohmann::json getServerUpdateAttributes() override
		{
			nlohmann::json result;
			return reinterpret_cast<nlohmann::json& (__thiscall*)(EntitySpider* self, nlohmann::json* result)>(getFuncAddr((int)Func::EntitySpider::getServerUpdateAttributes))(this, &result);
			return result;
		}
		void applyServerUpdate(const nlohmann::json& j, World* world) override
		{
			return reinterpret_cast<void (__thiscall*)(EntitySpider* self, const nlohmann::json& j, World* world)>(getFuncAddr((int)Func::EntitySpider::applyServerUpdate))(this, j, world);
		}
		void takeDamage(float damage, World* world) override
		{
			return reinterpret_cast<void (__thiscall*)(EntitySpider* self, float damage, World* world)>(getFuncAddr((int)Func::EntitySpider::takeDamage))(this, damage, world);
		}
		void playHitSound() 
		{
			return reinterpret_cast<void (__thiscall*)(EntitySpider* self)>(getFuncAddr((int)Func::EntitySpider::playHitSound))(this);
		}
		void playDeathSound() 
		{
			return reinterpret_cast<void (__thiscall*)(EntitySpider* self)>(getFuncAddr((int)Func::EntitySpider::playDeathSound))(this);
		}
		inline static void collisionCallback(void* user, Hitbox* hitbox, World* world, const glm::ivec4& collisionBlock, int collisionComp) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, Hitbox* hitbox, World* world, const glm::ivec4& collisionBlock, int collisionComp)>(getFuncAddr((int)Func::EntitySpider::collisionCallback))(user, hitbox, world, collisionBlock, collisionComp);
		}
		EntityPlayer* findPlayer(World* world) 
		{
			return reinterpret_cast<EntityPlayer* (__thiscall*)(EntitySpider* self, World* world)>(getFuncAddr((int)Func::EntitySpider::findPlayer))(this, world);
		}
		void persuePlayer(World* world, double dt, EntityPlayer* player) 
		{
			return reinterpret_cast<void (__thiscall*)(EntitySpider* self, World* world, double dt, EntityPlayer* player)>(getFuncAddr((int)Func::EntitySpider::persuePlayer))(this, world, dt, player);
		}
		bool action(World* world, Entity* actor, int action, const nlohmann::json& details) override
		{
			return reinterpret_cast<bool(__thiscall*)(EntitySpider * self, World*, Entity*, int, const nlohmann::json&)>(getFuncAddr((int)Func::EntitySpider::action))(this, world, actor, action, details);
		}
		float deathTimer() override
		{
			return reinterpret_cast<float(__thiscall*)(EntitySpider * self)>(getFuncAddr((int)Func::EntitySpider::deathTimer))(this);
		}
		bool isBlockEntity() override
		{
			return reinterpret_cast<bool(__thiscall*)(EntitySpider * self)>(getFuncAddr((int)Func::EntitySpider::isBlockEntity))(this);
		}
		bool isClickable() override
		{
			return reinterpret_cast<bool(__thiscall*)(EntitySpider * self)>(getFuncAddr((int)Func::EntitySpider::isClickable))(this);
		}
		bool shouldSave() override
		{
			return reinterpret_cast<bool(__thiscall*)(EntitySpider * self)>(getFuncAddr((int)Func::EntitySpider::shouldSave))(this);
		}
	};
}
