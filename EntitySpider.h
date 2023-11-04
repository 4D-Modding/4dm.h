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
				reinterpret_cast<void(__thiscall*)(EntitySpider::SpiderType* self)>(FUNC_ENTITYSPIDER_SPIDERTYPE_DESTR_SPIDERTYPE)(this);
			}
		};
		inline static const float hitboxRadius = 0.6f; 
		inline static const float maxSpeed = 3.f; 
		Hitbox hitbox; // 0x20
		inline static const int NUM_TYPES = 5; 
		inline static EntitySpider::SpiderType** spiderTypes = reinterpret_cast<EntitySpider::SpiderType**>((base + 0x279A30));
		int type; // 0x70
		inline static const int NUM_LEGS = 32; 
		inline static glm::vec4** legPositions = reinterpret_cast<glm::vec4**>((base + 0x29B400));
		inline static MeshRenderer* legRenderer = reinterpret_cast<MeshRenderer*>((base + 0x279D28));
		glm::vec4 direction; // 0x74
		float rotation; // 0x84
		bool touchingGround; // 0x88
		bool shouldJump; // 0x89
		bool walking; // 0x8A
		PAD(0x1);
		glm::vec4 horizAcc; // 0x8C
		float health; // 0x9C
		double hitTime; // 0xA0
		inline static const float hitDelay = 0.7f; 
		uuid target; // 0xA8
		inline static const float updateDelay = 2.f; 
		double lastUpdateTime; // 0xB8
		inline static const float serverUpdateDelay = 0.5f; 
		double lastServerUpdateTime; // 0xC0
		inline static MeshRenderer* wireframeRenderer = reinterpret_cast<MeshRenderer*>((base + 0x279D48));

		bool isIntersectingRay(const Entity::Ray& ray) override
		{
			return reinterpret_cast<bool (__thiscall*)(EntitySpider* self, const Entity::Ray& ray)>(FUNC_ENTITYSPIDER_ISINTERSECTINGRAY)(this, ray);
		}
		glm::vec4 getPos() override
		{
			glm::vec4 result;
			return reinterpret_cast<glm::vec4 (__thiscall*)(EntitySpider* self, glm::vec4* result)>(FUNC_ENTITYSPIDER_GETPOS)(this, &result);
			return result;
		}
		void setPos(const glm::vec4& pos) override
		{
			return reinterpret_cast<void (__thiscall*)(EntitySpider* self, const glm::vec4& pos)>(FUNC_ENTITYSPIDER_SETPOS)(this, pos);
		}
		std::string getName() override
		{
			std::string result;
			return reinterpret_cast<std::string (__thiscall*)(EntitySpider* self, std::string* result)>(FUNC_ENTITYSPIDER_GETNAME)(this, &result);
			return result;
		}
		void update(World* world, double dt) override
		{
			return reinterpret_cast<void (__thiscall*)(EntitySpider* self, World* world, double dt)>(FUNC_ENTITYSPIDER_UPDATE)(this, world, dt);
		}
		void render(const World* world, const m4::Mat5& MV, bool glasses) override
		{
			return reinterpret_cast<void (__thiscall*)(EntitySpider* self, const World* world, const m4::Mat5& MV, bool glasses)>(FUNC_ENTITYSPIDER_RENDER)(this, world, MV, glasses);
		}
		nlohmann::json saveAttributes() override
		{
			nlohmann::json result;
			return reinterpret_cast<nlohmann::json (__thiscall*)(EntitySpider* self, nlohmann::json* result)>(FUNC_ENTITYSPIDER_SAVEATTRIBUTES)(this, &result);
			return result;
		}
		nlohmann::json getServerUpdateAttributes() override
		{
			nlohmann::json result;
			return reinterpret_cast<nlohmann::json (__thiscall*)(EntitySpider* self, nlohmann::json* result)>(FUNC_ENTITYSPIDER_GETSERVERUPDATEATTRIBUTES)(this, &result);
			return result;
		}
		void applyServerUpdate(const nlohmann::json& j, World* world) override
		{
			return reinterpret_cast<void (__thiscall*)(EntitySpider* self, const nlohmann::json& j, World* world)>(FUNC_ENTITYSPIDER_APPLYSERVERUPDATE)(this, j, world);
		}
		void takeDamage(float damage, World* world) override
		{
			return reinterpret_cast<void (__thiscall*)(EntitySpider* self, float damage, World* world)>(FUNC_ENTITYSPIDER_TAKEDAMAGE)(this, damage, world);
		}
		void playHitSound() 
		{
			return reinterpret_cast<void (__thiscall*)(EntitySpider* self)>(FUNC_ENTITYSPIDER_PLAYHITSOUND)(this);
		}
		void playDeathSound() 
		{
			return reinterpret_cast<void (__thiscall*)(EntitySpider* self)>(FUNC_ENTITYSPIDER_PLAYDEATHSOUND)(this);
		}
		inline static void collisionCallback(void* user, Hitbox* hitbox, World* world, const glm::ivec4& collisionBlock, int collisionComp) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, Hitbox* hitbox, World* world, const glm::ivec4& collisionBlock, int collisionComp)>(FUNC_ENTITYSPIDER_COLLISIONCALLBACK)(user, hitbox, world, collisionBlock, collisionComp);
		}
		EntityPlayer* findPlayer(World* world) 
		{
			return reinterpret_cast<EntityPlayer* (__thiscall*)(EntitySpider* self, World* world)>(FUNC_ENTITYSPIDER_FINDPLAYER)(this, world);
		}
		void persuePlayer(World* world, double dt, EntityPlayer* player) 
		{
			return reinterpret_cast<void (__thiscall*)(EntitySpider* self, World* world, double dt, EntityPlayer* player)>(FUNC_ENTITYSPIDER_PERSUEPLAYER)(this, world, dt, player);
		}
	};
}
