#pragma once

#include "4dm.h"
#include "Player.h"
#include "PlayerSkin.h"
#include "PlayerSkinRenderer.h"
#include "FontRenderer.h"
#include "World.h"
#include "Entity.h"

namespace fdm 
{
	class Player;
	class PlayerSkin;
	class PlayerSkinRenderer;
	class FontRenderer;
	class World;
	class Entity;

	class EntityPlayer : public Entity 
	{
	public:
		struct SkinMessageData 
		{
			uuid id; 
			uint32_t* skinData; // 0x10
		};
		Player* player; // 0x20
		std::unique_ptr<Player> ownedPlayer; // 0x28
		inline static PlayerSkin* defaultSkin = reinterpret_cast<PlayerSkin*>((base + 0x2797A0)); // lmfao it was "defualtSkin" in game :misinformation:
		PlayerSkin skin; // 0x30
		PlayerSkinRenderer skinRenderer; // 0x180
		inline static glm::mat4* projection3D = reinterpret_cast<glm::mat4*>((base + 0x278490));
		inline static int* wWidth = reinterpret_cast<int*>((base + 0x29B3F4));
		inline static int* wHeight = reinterpret_cast<int*>((base + 0x29B3F0));
		inline static FontRenderer* fr = reinterpret_cast<FontRenderer*>((base + 0x279700));
		std::string displayName; // 0x710
		double lastMovementUpdateTime; // 0x730
		bool justDamaged; // 0x738
		PAD(0x3);
		glm::vec4 interpEndpoint; // 0x73C
		glm::vec4 interpVel; // 0x74C

		inline static std::unique_ptr<Entity> createFromPlayer(Player* p) 
		{
			return reinterpret_cast<std::unique_ptr<Entity> (__fastcall*)(Player* p)>(FUNC_ENTITYPLAYER_CREATEFROMPLAYER)(p);
		}
		EntityPlayer(nlohmann::json& j) 
		{
			reinterpret_cast<void(__thiscall*)(EntityPlayer* self, nlohmann::json& j)>(FUNC_ENTITYPLAYER_ENTITYPLAYER)(this, j);
		}
		std::string getName() override
		{
			std::string result;
			return reinterpret_cast<std::string (__thiscall*)(EntityPlayer* self, std::string* result)>(FUNC_ENTITYPLAYER_GETNAME)(this, &result);
			return result;
		}
		void update(World* world, double dt) override
		{
			return reinterpret_cast<void (__thiscall*)(EntityPlayer* self, World* world, double dt)>(FUNC_ENTITYPLAYER_UPDATE)(this, world, dt);
		}
		void render(const World* world, const m4::Mat5& MV, bool glasses) override
		{
			return reinterpret_cast<void (__thiscall*)(EntityPlayer* self, const World* world, const m4::Mat5& MV, bool glasses)>(FUNC_ENTITYPLAYER_RENDER)(this, world, MV, glasses);
		}
		nlohmann::json saveAttributes() override
		{
			nlohmann::json result;
			return reinterpret_cast<nlohmann::json (__thiscall*)(EntityPlayer* self, nlohmann::json* result)>(FUNC_ENTITYPLAYER_SAVEATTRIBUTES)(this, &result);
			return result;
		}
		void applyServerUpdate(const nlohmann::json& j, World* world) override
		{
			return reinterpret_cast<void (__thiscall*)(EntityPlayer* self, const nlohmann::json& j, World* world)>(FUNC_ENTITYPLAYER_APPLYSERVERUPDATE)(this, j, world);
		}
		glm::vec4 getPos() override
		{
			glm::vec4 result;
			return reinterpret_cast<glm::vec4 (__thiscall*)(EntityPlayer* self, glm::vec4* result)>(FUNC_ENTITYPLAYER_GETPOS)(this, &result);
			return result;
		}
		void setPos(const glm::vec4& pos) override
		{
			return reinterpret_cast<void (__thiscall*)(EntityPlayer* self, const glm::vec4& pos)>(FUNC_ENTITYPLAYER_SETPOS)(this, pos);
		}
		bool isIntersectingRay(const Entity::Ray& ray) override
		{
			return reinterpret_cast<bool (__thiscall*)(EntityPlayer* self, const Entity::Ray& ray)>(FUNC_ENTITYPLAYER_ISINTERSECTINGRAY)(this, ray);
		}
		void takeDamage(float damage, World* world) override
		{
			return reinterpret_cast<void (__thiscall*)(EntityPlayer* self, float damage, World* world)>(FUNC_ENTITYPLAYER_TAKEDAMAGE)(this, damage, world);
		}
		float deathTimer() override
		{
			return reinterpret_cast<float (__thiscall*)(EntityPlayer* self)>(FUNC_ENTITYPLAYER_DEATHTIMER)(this);
		}
		void applyMovementUpdate(nlohmann::json& j) 
		{
			return reinterpret_cast<void (__thiscall*)(EntityPlayer* self, nlohmann::json& j)>(FUNC_ENTITYPLAYER_APPLYMOVEMENTUPDATE)(this, j);
		}
		void collectItems(World* world) 
		{
			return reinterpret_cast<void (__thiscall*)(EntityPlayer* self, World* world)>(FUNC_ENTITYPLAYER_COLLECTITEMS)(this, world);
		}
	};
}
