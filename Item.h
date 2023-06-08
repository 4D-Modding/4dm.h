#pragma once
#ifndef ITEM_H
#define ITEM_H
#include "4dm.h"
#include "World.h"
#include "Player.h"
#include "Entity.h"
#include "FontRenderer.h"
#include "QuadRenderer.h"

namespace fdm
{
	class FontRenderer;
	class QuadRenderer;
	class Entity;
	class World;
	class Player;
	
	class Item
	{
	public:
		//inline static FontRenderer fr;
		//inline static QuadRenderer qr;

		inline static FontRenderer getFontRenderer() // fr
		{
			return *reinterpret_cast<FontRenderer*>((base + 0x17BF80));
		}

		inline static QuadRenderer getQuadRenderer() // qr
		{
			return *reinterpret_cast<QuadRenderer*>((base + 0x17BAA8));
		}
		
		unsigned int count;

		inline static nlohmann::json getBlueprints() // blueprints
		{
			return *reinterpret_cast<nlohmann::json*>((base + 0x1BED98));
		}

		bool loadItemInfo(void) 
		{
			return reinterpret_cast<bool(__thiscall*)(Item*)>(
				FUNC_ITEM_LOADITEMINFO
				)(this);
		}
		void renderInit(void) 
		{
			return reinterpret_cast<void(__thiscall*)(Item*)>(
				FUNC_ITEM_RENDERINIT
				)(this);
		}
		nlohmann::json save(void) 
		{
			return reinterpret_cast<nlohmann::json(__thiscall*)(Item*, nlohmann::json*)>(
				FUNC_ITEM_SAVE
				)(this, nullptr);
		}
		bool takeHalf(std::unique_ptr<Item>& other) 
		{
			return reinterpret_cast<nlohmann::json(__thiscall*)(Item*, std::unique_ptr<Item>&)>(
				FUNC_ITEM_TAKEHALF
				)(this, other);
		}

		// inline static funcs fr
		inline static void renderItem(std::unique_ptr<Item>& item, const glm::ivec2& pos)
		{
			return reinterpret_cast<void(__fastcall*)(std::unique_ptr<Item>&, const glm::ivec2&)>(
				FUNC_ITEM_RENDERITEM
				)(item, pos);
		}
		inline static void renderItemDescription(std::unique_ptr<Item>& item, const glm::ivec2& pos)
		{
			return reinterpret_cast<void(__fastcall*)(std::unique_ptr<Item>&, const glm::ivec2&)>(
				FUNC_ITEM_RENDERITEMDESCRIPTION
				)(item, pos);
		}
		inline static std::unique_ptr<Item> createFromJson(const nlohmann::json& j)
		{
			return reinterpret_cast<std::unique_ptr<Item>(__fastcall*)(std::unique_ptr<Item>*, const nlohmann::json&)>(
				FUNC_ITEM_CREATEFROMJSON
				)(nullptr, j);
		}
		inline static std::unique_ptr<Item> create(const std::string& itemName, unsigned int count)
		{
			return reinterpret_cast<std::unique_ptr<Item>(__fastcall*)(std::unique_ptr<Item>*, const std::string&, unsigned int)>(
				FUNC_ITEM_CREATE
				)(nullptr, itemName, count);
		}
		inline static bool giveMax(std::unique_ptr<Item>& from, std::unique_ptr<Item>& to)
		{
			return reinterpret_cast<bool(__fastcall*)(std::unique_ptr<Item>&, std::unique_ptr<Item>&)>(
				FUNC_ITEM_GIVEMAX
				)(from, to);
		}
		inline static bool giveOne(std::unique_ptr<Item>& from, std::unique_ptr<Item>& to)
		{
			return reinterpret_cast<bool(__fastcall*)(std::unique_ptr<Item>&, std::unique_ptr<Item>&)>(
				FUNC_ITEM_GIVEONE
				)(from, to);
		}
		inline static std::unique_ptr<Item> instantiateItem(const std::string& itemName, unsigned int count, const std::string& type, const nlohmann::json& attributes)
		{
			return reinterpret_cast<std::unique_ptr<Item>(__fastcall*)(std::unique_ptr<Item>*, const std::string&, unsigned int, const std::string&, const nlohmann::json&)>(
				FUNC_ITEM_INSTANTIATEITEM
				)(nullptr, itemName, count, type, attributes);
		}
		inline static nlohmann::json combineItemAttributes(const nlohmann::json& baseAttributes, const nlohmann::json& additions)
		{
			return reinterpret_cast<nlohmann::json(__fastcall*)(nlohmann::json*, const nlohmann::json&, const nlohmann::json&)>(
				FUNC_ITEM_COMBINEITEMATTRIBUTES
				)(nullptr, baseAttributes, additions);
		}

		// abstract/virtual funcs
		virtual std::string getName() { return ""; }
		virtual void render(const glm::ivec2& pos) {}
		virtual void renderEntity(const m4::Mat5& mat, bool inHand) {}
		virtual bool isDeadly() { return false; }
		virtual bool isCompatible(const std::unique_ptr<Item>& other) { return false; }
		virtual unsigned int getStackLimit() { return 4096; }
		virtual bool action(World* world, Player* player, int action) { return false; }
		virtual bool breakBlock(World* world, Player* player, unsigned char block, const glm::ivec4& blockPos) { return false; }
		virtual bool entityAction(World* world, Player* player, std::unique_ptr<Entity>& entity, int action) { return false; }
		virtual std::unique_ptr<Item> clone() { return NULL; }
		virtual nlohmann::json saveAttributes() { return NULL; }
	};
}
#endif