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
	private:
		static std::unordered_map<int, std::string> itemTypes;
	public:
		int blockID;

		static const int STACK_MAX = 4096;
		static TexRenderer tr;
		
		static std::unordered_map<int, std::string> getItemTypes() 
		{
			BlockItem::itemTypes = *reinterpret_cast<std::unordered_map<int, std::string>*>((base + idaOffsetFix(0x1C1FB0)));
			return itemTypes;
		}
		static void addItemType(const std::string& itemType, nlohmann::json& baseAttributes) 
		{
			reinterpret_cast<void(__fastcall*)(const std::string&, nlohmann::json&)>(
				base + idaOffsetFix(0x160D0)
				)(itemType, baseAttributes);
		}

		BlockItem(const std::string& itemName, nlohmann::json& attributes) 
		{
			reinterpret_cast<void(__thiscall*)(BlockItem*, const std::string&, nlohmann::json&)>(
				base + idaOffsetFix(0x162F0)
				)(this, itemName, attributes);
		}

		std::string getName() override 
		{
			std::string* result = new std::string();
			return reinterpret_cast<std::string(__thiscall*)(BlockItem*, std::string*)>(
				base + idaOffsetFix(0x16510)
				)(this, result);
		}
		void render(const glm::ivec2& pos) override 
		{
			reinterpret_cast<void(__thiscall*)(BlockItem*, const glm::ivec2&)>(
				base + idaOffsetFix(0x165D0)
				)(this, pos);
		}
		void renderEntity(const m4::Mat5& MV, bool inHand) override
		{
			reinterpret_cast<void(__thiscall*)(BlockItem*, const m4::Mat5&, bool)>(
				base + idaOffsetFix(0x16690)
				)(this, MV, inHand);
		}
		bool isDeadly() override 
		{
			return blockID == 8;
		}
		bool isCompatible(const std::unique_ptr<Item>& other) override
		{
			return reinterpret_cast<bool(__thiscall*)(BlockItem*, const std::unique_ptr<Item>&)>(
				base + idaOffsetFix(0x16A10)
				)(this, other);
		}
		bool action(World* world, Player* player, int action) override
		{
			return reinterpret_cast<bool(__thiscall*)(BlockItem*, World*, Player*, int)>(
				base + idaOffsetFix(0x16AA0)
				)(this, world, player, action);
		}
		std::unique_ptr<Item> clone() override 
		{
			std::unique_ptr<Item>* result = new std::unique_ptr<Item>();
			return reinterpret_cast<std::unique_ptr<Item>(__thiscall*)(BlockItem*, std::unique_ptr<Item>*)>(
				base + idaOffsetFix(0x16C10)
				)(this, result);
		}
	};
}
#endif