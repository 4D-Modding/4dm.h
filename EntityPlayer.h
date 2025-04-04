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
			stl::uuid id; 
			uint32_t* skinData; // 0x10
		};
		Player* player; // 0x20
		std::unique_ptr<Player> ownedPlayer; // 0x28
		PlayerSkin skin; // 0x30
		PlayerSkinRenderer skinRenderer; // 0x180
		stl::string displayName; // 0x710
		double lastMovementUpdateTime; // 0x730
		bool justDamaged; // 0x738
		PAD(0x3);
		glm::vec4 interpEndpoint; // 0x73C
		glm::vec4 interpVel; // 0x74C

		inline static PlayerSkin& defaultSkin = *reinterpret_cast<PlayerSkin*>(getDataAddr((int)Data::EntityPlayer::defualtSkin)); // lmfao it is "defualtSkin" in game :misinformation:
		inline static glm::mat4& projection3D = *reinterpret_cast<glm::mat4*>(getDataAddr((int)Data::EntityPlayer::projection3D));
		inline static int& wWidth = *reinterpret_cast<int*>(getDataAddr((int)Data::EntityPlayer::wWidth));
		inline static int& wHeight = *reinterpret_cast<int*>(getDataAddr((int)Data::EntityPlayer::wHeight));
		inline static FontRenderer& fr = *reinterpret_cast<FontRenderer*>(getDataAddr((int)Data::EntityPlayer::fr));

		inline static void renderInit()
		{
			return reinterpret_cast<void(__fastcall*)()>(getFuncAddr((int)Func::EntityPlayer::renderInit))();
		}
		inline static std::unique_ptr<Entity> createFromPlayer(Player* p) 
		{
			return reinterpret_cast<std::unique_ptr<Entity> (__fastcall*)(Player* p)>(getFuncAddr((int)Func::EntityPlayer::createFromPlayer))(p);
		}
		EntityPlayer() {}
		EntityPlayer(nlohmann::json& j) 
		{
			reinterpret_cast<void(__thiscall*)(EntityPlayer* self, nlohmann::json& j)>(getFuncAddr((int)Func::EntityPlayer::EntityPlayer))(this, j);
		}
		stl::string getName() override
		{
			stl::string result;
			return reinterpret_cast<stl::string& (__thiscall*)(EntityPlayer* self, stl::string* result)>(getFuncAddr((int)Func::EntityPlayer::getName))(this, &result);
			return result;
		}
		void update(World* world, double dt) override
		{
			return reinterpret_cast<void (__thiscall*)(EntityPlayer* self, World* world, double dt)>(getFuncAddr((int)Func::EntityPlayer::update))(this, world, dt);
		}
		void render(const World* world, const m4::Mat5& MV, bool glasses) override
		{
			return reinterpret_cast<void (__thiscall*)(EntityPlayer* self, const World* world, const m4::Mat5& MV, bool glasses)>(getFuncAddr((int)Func::EntityPlayer::render))(this, world, MV, glasses);
		}
		nlohmann::json saveAttributes() override
		{
			nlohmann::json result;
			return reinterpret_cast<nlohmann::json& (__thiscall*)(EntityPlayer* self, nlohmann::json* result)>(getFuncAddr((int)Func::EntityPlayer::saveAttributes))(this, &result);
			return result;
		}
		void applyServerUpdate(const nlohmann::json& j, World* world) override
		{
			return reinterpret_cast<void (__thiscall*)(EntityPlayer* self, const nlohmann::json& j, World* world)>(getFuncAddr((int)Func::EntityPlayer::applyServerUpdate))(this, j, world);
		}
		glm::vec4 getPos() override
		{
			glm::vec4 result;
			return reinterpret_cast<glm::vec4& (__thiscall*)(EntityPlayer* self, glm::vec4* result)>(getFuncAddr((int)Func::EntityPlayer::getPos))(this, &result);
			return result;
		}
		void setPos(const glm::vec4& pos) override
		{
			return reinterpret_cast<void (__thiscall*)(EntityPlayer* self, const glm::vec4& pos)>(getFuncAddr((int)Func::EntityPlayer::setPos))(this, pos);
		}
		bool isIntersectingRay(const Entity::Ray& ray) override
		{
			return reinterpret_cast<bool (__thiscall*)(EntityPlayer* self, const Entity::Ray& ray)>(getFuncAddr((int)Func::EntityPlayer::isIntersectingRay))(this, ray);
		}
		void takeDamage(float damage, World* world) override
		{
			return reinterpret_cast<void (__thiscall*)(EntityPlayer* self, float damage, World* world)>(getFuncAddr((int)Func::EntityPlayer::takeDamage))(this, damage, world);
		}
		float deathTimer() override
		{
			return reinterpret_cast<float (__thiscall*)(EntityPlayer* self)>(getFuncAddr((int)Func::EntityPlayer::deathTimer))(this);
		}
		void applyMovementUpdate(nlohmann::json& j) 
		{
			return reinterpret_cast<void (__thiscall*)(EntityPlayer* self, nlohmann::json& j)>(getFuncAddr((int)Func::EntityPlayer::applyMovementUpdate))(this, j);
		}
		void collectItems(World* world) 
		{
			return reinterpret_cast<void (__thiscall*)(EntityPlayer* self, World* world)>(getFuncAddr((int)Func::EntityPlayer::collectItems))(this, world);
		}
		bool isBlockEntity() override
		{
			return reinterpret_cast<bool(__thiscall*)(EntityPlayer * self)>(getFuncAddr((int)Func::EntityPlayer::isBlockEntity))(this);
		}
		bool isClickable() override
		{
			return reinterpret_cast<bool(__thiscall*)(EntityPlayer * self)>(getFuncAddr((int)Func::EntityPlayer::isClickable))(this);
		}
		nlohmann::json getServerUpdateAttributes() override
		{
			return reinterpret_cast<nlohmann::json(__thiscall*)(EntityPlayer * self)>(getFuncAddr((int)Func::EntityPlayer::getServerUpdateAttributes))(this);
		}
		bool shouldSave() override
		{
			return reinterpret_cast<bool(__thiscall*)(EntityPlayer * self)>(getFuncAddr((int)Func::EntityPlayer::shouldSave))(this);
		}
		// only available for server
		void setPerformingAction(bool performingAction)
		{
			return reinterpret_cast<void(__thiscall*)(EntityPlayer * self, bool)>(getFuncAddr((int)Func::EntityPlayer::setPerformingAction))(this, performingAction);
		}
	};
}
