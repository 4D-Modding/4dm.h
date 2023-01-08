#pragma once
#ifndef ENTITY_H
#define ENTITY_H
#include "4dm.h"
namespace fdm
{
	class TexRenderer;
	class FontRenderer;
	class Entity
	{
	public:
		static const float MAX_HITBOX_RADIUS;
		static TexRenderer ftr;
		static FontRenderer fr;
		static nlohmann::json blueprints;
		
		// abstract/virtual funcs
		virtual std::string getName() = NULL;
		virtual void render(const World* world, const m4::Mat5& MV, bool glasses) = NULL;
		virtual void update(World* world, Player* player, double dt) = NULL;
		virtual glm::vec4 getPos() = NULL;
		virtual void setPos(const glm::vec4& pos) = NULL;
		virtual bool isDead() = NULL;
		virtual bool shouldSave() = NULL;
		virtual bool isClickable() = NULL;
		virtual bool isBlockEntity() = NULL;
		virtual float getHitboxRadius() = NULL;
		virtual void takeDamage(float dmg, World* world) = NULL;
		virtual bool action(World* world, Player* player, int action) = NULL;
		virtual nlohmann::json saveAttributes() = NULL;
	};
}
#endif