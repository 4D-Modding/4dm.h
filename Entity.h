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
		const float MAX_HITBOX_RADIUS;
		static TexRenderer ftr;
		static FontRenderer fr;
		static nlohmann::json blueprints;
	};
}
#endif