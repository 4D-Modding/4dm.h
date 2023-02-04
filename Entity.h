#pragma once
#ifndef ENTITY_H
#define ENTITY_H
#include "4dm.h"
#include "World.h"
#include "Player.h"
namespace fdm
{
	class TexRenderer;
	class FontRenderer;
	class World;
	class Player;
	class Entity
	{
	public:
		static const float MAX_HITBOX_RADIUS;
		static TexRenderer ftr;
		static FontRenderer fr;
		static nlohmann::json blueprints;
		// abstract/virtual funcs
		virtual std::string getName() {}
		virtual void render(const World* world, const m4::Mat5& MV, bool glasses) {}
		virtual void update(World* world, Player* player, double dt) {}
		virtual glm::vec4 getPos() {}
		virtual void setPos(const glm::vec4& pos) {}
		virtual bool isDead() {}
		virtual bool shouldSave() {}
		virtual bool isClickable() {}
		virtual bool isBlockEntity() {}
		virtual float getHitboxRadius() {}
		virtual void takeDamage(float dmg, World* world) {}
		virtual bool action(World* world, Player* player, int action) {}
		virtual nlohmann::json saveAttributes() {}
	};
}
#endif