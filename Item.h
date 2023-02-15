#pragma once
#ifndef ITEM_H
#define ITEM_H
#include "4dm.h"
#include "World.h"
#include "Player.h"
#include "Entity.h"
namespace fdm
{
	class FontRenderer;
	class QuadRenderer;
	class Entity;
	class World;
	class Player;
	
	class Item
	{
	private:
		static nlohmann::json blueprints;
	public:
		static FontRenderer fr;
		static QuadRenderer qr;
		
		unsigned int count;
		static nlohmann::json getBlueprints()
		{
			Item::blueprints = *reinterpret_cast<nlohmann::json*>((base + idaOffsetFix(0x1327B0)));
			return blueprints;
		}
		bool loadItemInfo(void) 
		{
			return reinterpret_cast<bool(__thiscall*)(Item*)>(
				base + idaOffsetFix(0x67A00)
				)(this);
		}
		void renderInit(void) 
		{
			return reinterpret_cast<void(__thiscall*)(Item*)>(
				base + idaOffsetFix(0x68090)
				)(this);
		}
		nlohmann::json save(void) 
		{
			nlohmann::json* result = new nlohmann::json();
			return reinterpret_cast<nlohmann::json(__thiscall*)(Item*, nlohmann::json*)>(
				base + idaOffsetFix(0x6A300)
				)(this, result);
		}
		bool takeHalf(std::unique_ptr<Item>& other) 
		{
			return reinterpret_cast<nlohmann::json(__thiscall*)(Item*, std::unique_ptr<Item>&)>(
				base + idaOffsetFix(0x6A500)
				)(this, other);
		}

		// static funcs fr
		static void renderItem(std::unique_ptr<Item>& item, const glm::ivec2& pos)
		{
			return reinterpret_cast<void(__fastcall*)(std::unique_ptr<Item>&, const glm::ivec2&)>(
				base + idaOffsetFix(0x683B0)
				)(item, pos);
		}
		static void renderItemDescription(std::unique_ptr<Item>& item, const glm::ivec2& pos)
		{
			return reinterpret_cast<void(__fastcall*)(std::unique_ptr<Item>&, const glm::ivec2&)>(
				base + idaOffsetFix(0x68540)
				)(item, pos);
		}
		static std::unique_ptr<Item> createFromJson(const nlohmann::json& j)
		{
			return reinterpret_cast<std::unique_ptr<Item>(__fastcall*)(std::unique_ptr<Item>*, const nlohmann::json&)>(
				base + idaOffsetFix(0x68A80)
				)(nullptr, j);
		}
		static std::unique_ptr<Item> create(const std::string& itemName, unsigned int count)
		{
			return reinterpret_cast<std::unique_ptr<Item>(__fastcall*)(std::unique_ptr<Item>*, const std::string&, unsigned int)>(
				base + idaOffsetFix(0x69710)
				)(nullptr, itemName, count);
		}
		static bool giveMax(std::unique_ptr<Item>& from, std::unique_ptr<Item>& to)
		{
			return reinterpret_cast<bool(__fastcall*)(std::unique_ptr<Item>&, std::unique_ptr<Item>&)>(
				base + idaOffsetFix(0x69BD0)
				)(from, to);
		}
		static bool giveOne(std::unique_ptr<Item>& from, std::unique_ptr<Item>& to)
		{
			return reinterpret_cast<bool(__fastcall*)(std::unique_ptr<Item>&, std::unique_ptr<Item>&)>(
				base + idaOffsetFix(0x69D90)
				)(from, to);
		}
		static std::unique_ptr<Item> instantiateItem(const std::string& itemName, unsigned int count, const std::string& type, const nlohmann::json& attributes)
		{
			std::unique_ptr<Item>* result = new std::unique_ptr<Item>();
			return reinterpret_cast<std::unique_ptr<Item>(__fastcall*)(std::unique_ptr<Item>*, const std::string&, unsigned int, const std::string&, const nlohmann::json&)>(
				base + idaOffsetFix(0x69F00)
				)(result, itemName, count, type, attributes);
		}
		static nlohmann::json combineItemAttributes(const nlohmann::json& baseAttributes, const nlohmann::json& additions)
		{
			nlohmann::json* result = new nlohmann::json();
			return reinterpret_cast<nlohmann::json(__fastcall*)(nlohmann::json*, const nlohmann::json&, const nlohmann::json&)>(
				base + idaOffsetFix(0x6A050)
				)(result, baseAttributes, additions);
		}

		// abstract/virtual funcs
		virtual std::string getName() {}
		virtual void render(const glm::ivec2& pos) {}
		virtual void renderEntity(const m4::Mat5& mat, bool inHand) {}
		virtual bool isDeadly() {}
		virtual bool isCompatible(const std::unique_ptr<Item>& other) {}
		virtual unsigned int getStackLimit() {}
		virtual bool action(World* world, Player* player, int action) {}
		virtual bool breakBlock(World* world, Player* player, unsigned char block, const glm::ivec4& blockPos) {}
		virtual bool entityAction(World* world, Player* player, std::unique_ptr<Entity>& entity, int action) {}
		virtual std::unique_ptr<Item> clone() { return NULL; }
		nlohmann::json saveAttributes() { return NULL; }
	};
	nlohmann::json Item::blueprints{};

}
#endif