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
		inline static glm::u8vec3** wing_tuv = reinterpret_cast<glm::u8vec3**>((base + 0x2ACC90));
		inline static const float hitboxRadius = 1.4f; 
		inline static const float maxSpeed = 1.8f; 
		Hitbox hitbox; // 0x20
		glm::vec4 direction; // 0x70
		float health; // 0x80
		PAD(0x4);
		double hitTime; // 0x88
		inline static const float hitDelay = 0.7f; 
		inline static const int NUM_TYPES = 4; 
		inline static EntityButterfly::ButterflyType** ButterflyTypes = reinterpret_cast<EntityButterfly::ButterflyType**>((base + 0x2783C0));
		int type; // 0x90
		inline static MeshRenderer* wingRenderer = reinterpret_cast<MeshRenderer*>((base + 0x2788C8));
		inline static MeshRenderer* wireframeRenderer = reinterpret_cast<MeshRenderer*>((base + 0x2788A8));
		inline static const float minFlapDelay = NULL; 
		inline static const float maxFlapDelay = NULL; 
		PAD(0x4);
		double remainingFlapTime; // 0x98
		bool shouldUpdate; // 0xA0
		PAD(0x3);
		float flapAnimProgress; // 0xA4
		m4::BiVector4 rotationPlane; // 0xA8
		float angleToRotate; // 0xC0

		std::string getName() override
		{
			std::string result;
			return reinterpret_cast<std::string (__thiscall*)(EntityButterfly* self, std::string* result)>(FUNC_ENTITYBUTTERFLY_GETNAME)(this, &result);
			return result;
		}
		void update(World* world, double dt) override
		{
			return reinterpret_cast<void (__thiscall*)(EntityButterfly* self, World* world, double dt)>(FUNC_ENTITYBUTTERFLY_UPDATE)(this, world, dt);
		}
		void render(const World* world, const m4::Mat5& MV, bool glasses) override
		{
			return reinterpret_cast<void (__thiscall*)(EntityButterfly* self, const World* world, const m4::Mat5& MV, bool glasses)>(FUNC_ENTITYBUTTERFLY_RENDER)(this, world, MV, glasses);
		}
		nlohmann::json getServerUpdateAttributes() override
		{
			nlohmann::json result;
			return reinterpret_cast<nlohmann::json (__thiscall*)(EntityButterfly* self, nlohmann::json* result)>(FUNC_ENTITYBUTTERFLY_GETSERVERUPDATEATTRIBUTES)(this, &result);
			return result;
		}
		void applyServerUpdate(const nlohmann::json& j, World* world) override
		{
			return reinterpret_cast<void (__thiscall*)(EntityButterfly* self, const nlohmann::json& j, World* world)>(FUNC_ENTITYBUTTERFLY_APPLYSERVERUPDATE)(this, j, world);
		}
		void takeDamage(float damage, World* world) override
		{
			return reinterpret_cast<void (__thiscall*)(EntityButterfly* self, float damage, World* world)>(FUNC_ENTITYBUTTERFLY_TAKEDAMAGE)(this, damage, world);
		}
		void playHitSound() 
		{
			return reinterpret_cast<void (__thiscall*)(EntityButterfly* self)>(FUNC_ENTITYBUTTERFLY_PLAYHITSOUND)(this);
		}
		void playDeathSound() 
		{
			return reinterpret_cast<void (__thiscall*)(EntityButterfly* self)>(FUNC_ENTITYBUTTERFLY_PLAYDEATHSOUND)(this);
		}
		inline static void collisionCallback(void* user, Hitbox* hitbox, World* world, const glm::ivec4& collisionBlock, int collisionComp, const glm::vec4& prevVel) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, Hitbox* hitbox, World* world, const glm::ivec4& collisionBlock, int collisionComp, const glm::vec4& prevVel)>(FUNC_ENTITYBUTTERFLY_COLLISIONCALLBACK)(user, hitbox, world, collisionBlock, collisionComp, prevVel);
		}
	};
}
