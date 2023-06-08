#pragma once
#ifndef BLOCKITEM_H
#define BLOCKITEM_H
#include "4dm.h"
namespace fdm
{
	class Item;
	class TexRenderer;
	class BlockItem : public Item
	{
	public:
		int blockID;

		inline static const int STACK_MAX = 4096;
		inline static TexRenderer tr;
		
		inline static std::unordered_map<int, std::string> getItemTypes() // itemTypes
		{
			return *reinterpret_cast<std::unordered_map<int, std::string>*>((base + 0x1C2830));
		}
		inline static TexRenderer getTexRenderer() // tr
		{
			return *reinterpret_cast<TexRenderer*>((base + 0x1BDD40));
		}

		inline static void addItemType(const std::string itemType, nlohmann::json baseAttributes)
		{
			return reinterpret_cast<void(__fastcall*)(const std::string itemType, nlohmann::json baseAttributes)>(FUNC_BLOCKITEM_ADDITEMTYPE)(itemType, baseAttributes);
		}
		BlockItem(const std::string itemName, nlohmann::json attributes)
		{
			reinterpret_cast<void(__thiscall*)(BlockItem * self, const std::string itemName, nlohmann::json attributes)>(FUNC_BLOCKITEM_BLOCKITEM)(this, itemName, attributes);
		}
		std::string getName() override
		{
			return reinterpret_cast<std::string (__thiscall*)(BlockItem * self, std::string* result)>(FUNC_BLOCKITEM_GETNAME)(this, nullptr);
		}
		void render(const glm::ivec2& pos) override
		{
			return reinterpret_cast<void(__thiscall*)(BlockItem * self, const glm::ivec2& pos)>(FUNC_BLOCKITEM_RENDER)(this, pos);
		}
		void renderEntity(const m4::Mat5& MV, bool inHand) override
		{
			return reinterpret_cast<void(__thiscall*)(BlockItem * self, const m4::Mat5& MV, bool inHand)>(FUNC_BLOCKITEM_RENDERENTITY)(this, MV, inHand);
		}
		bool isDeadly() override
		{
			return reinterpret_cast<bool(__thiscall*)(BlockItem * self)>(FUNC_BLOCKITEM_ISDEADLY)(this);
		}
		bool isCompatible(const std::unique_ptr<Item>& other) override
		{
			return reinterpret_cast<bool(__thiscall*)(BlockItem * self, const std::unique_ptr<Item>& other)>(FUNC_BLOCKITEM_ISCOMPATIBLE)(this, other);
		}
		bool action(World* world, Player* player, int action) override
		{
			return reinterpret_cast<bool(__thiscall*)(BlockItem * self, World * world, Player * player, int action)>(FUNC_BLOCKITEM_ACTION)(this, world, player, action);
		}
		std::unique_ptr<Item> clone() override
		{
			return reinterpret_cast<std::unique_ptr<Item> (__thiscall*)(BlockItem * self, std::unique_ptr<Item> *result)>(FUNC_BLOCKITEM_CLONE)(this, nullptr);
		}
	};
}
#endif