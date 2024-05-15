#pragma once

#include "4dm.h"
#include "FontRenderer.h"
#include "QuadRenderer.h"
#include "Player.h"

namespace fdm 
{
	class FontRenderer;
	class QuadRenderer;
	class Player;
	class Item 
	{
	public:
		inline static FontRenderer* fr = reinterpret_cast<FontRenderer*>((base + 0x2794A0));
		inline static QuadRenderer* qr = reinterpret_cast<QuadRenderer*>((base + 0x278F18));
		inline static nlohmann::json* blueprints = reinterpret_cast<nlohmann::json*>((base + 0x2BF098));
		uint32_t count; // 0x8

		inline static bool loadItemInfo() 
		{
			return reinterpret_cast<bool (__fastcall*)()>(getFuncAddr((int)Func::Item::loadItemInfo))();
		}
		inline static void renderItem(std::unique_ptr<Item>& item, const glm::ivec2& pos) 
		{
			return reinterpret_cast<void (__fastcall*)(std::unique_ptr<Item>& item, const glm::ivec2& pos)>(getFuncAddr((int)Func::Item::renderItem))(item, pos);
		}
		inline static void renderItemDescription(std::unique_ptr<Item>& item, const glm::ivec2& pos) 
		{
			return reinterpret_cast<void (__fastcall*)(std::unique_ptr<Item>& item, const glm::ivec2& pos)>(getFuncAddr((int)Func::Item::renderItemDescription))(item, pos);
		}
		inline static std::unique_ptr<Item> createFromJson(nlohmann::json& j) 
		{
			return reinterpret_cast<std::unique_ptr<Item> (__fastcall*)(nlohmann::json& j)>(getFuncAddr((int)Func::Item::createFromJson))(j);
		}
		inline static bool giveMax(std::unique_ptr<Item>& from, std::unique_ptr<Item>& to) 
		{
			return reinterpret_cast<bool (__fastcall*)(std::unique_ptr<Item>& from, std::unique_ptr<Item>& to)>(getFuncAddr((int)Func::Item::giveMax))(from, to);
		}
		inline static bool giveOne(std::unique_ptr<Item>& from, std::unique_ptr<Item>& to) 
		{
			return reinterpret_cast<bool (__fastcall*)(std::unique_ptr<Item>& from, std::unique_ptr<Item>& to)>(getFuncAddr((int)Func::Item::giveOne))(from, to);
		}
		inline static std::unique_ptr<Item> instantiateItem(const stl::string& itemName, uint32_t count, const stl::string& type, nlohmann::json& attributes) 
		{
			return reinterpret_cast<std::unique_ptr<Item> (__fastcall*)(const stl::string& itemName, uint32_t count, const stl::string& type, nlohmann::json& attributes)>(getFuncAddr((int)Func::Item::instantiateItem))(itemName, count, type, attributes);
		}
		inline static nlohmann::json combineItemAttributes(nlohmann::json& baseAttributes, nlohmann::json& additions) 
		{
			return reinterpret_cast<nlohmann::json (__fastcall*)(nlohmann::json& baseAttributes, nlohmann::json& additions)>(getFuncAddr((int)Func::Item::combineItemAttributes))(baseAttributes, additions);
		}
		nlohmann::json save() 
		{
			nlohmann::json result;
			return reinterpret_cast<nlohmann::json& (__thiscall*)(Item* self, nlohmann::json* result)>(getFuncAddr((int)Func::Item::save))(this, &result);
			return result;
		}
		virtual ~Item()
		{
			reinterpret_cast<void(__thiscall*)(Item* self)>(getFuncAddr((int)Func::Item::destr_Item))(this);
		}
		bool takeMax(std::unique_ptr<Item>& other) 
		{
			return reinterpret_cast<bool (__thiscall*)(Item* self, std::unique_ptr<Item>& other)>(getFuncAddr((int)Func::Item::takeMax))(this, other);
		}
		bool takeHalf(std::unique_ptr<Item>& other) 
		{
			return reinterpret_cast<bool (__thiscall*)(Item* self, std::unique_ptr<Item>& other)>(getFuncAddr((int)Func::Item::takeHalf))(this, other);
		}


		// VIRTUAL FUNCS

		virtual stl::string getName() { return ""; }
		virtual void render(const glm::ivec2& pos) {}
		virtual void renderEntity(const m4::Mat5& MV, bool inHand, const glm::vec4& lightDir) {}
		virtual bool isDeadly() { return false; }
		virtual bool isCompatible(const std::unique_ptr<Item>& other) { return false; }
		virtual uint32_t getStackLimit() { return 4096; }
		virtual bool action(World* world, Player* player, int action) { return false; }
		virtual void postAction(World* world, Player* player, int action) {}
		virtual bool breakBlock(World* world, Player* player, unsigned char block, const glm::ivec4& blockPos) { return false; }
		virtual void postBreakBlock(World* world, Player* player) {}
		virtual bool entityAction(World* world, Player* player, Entity* entity, int action) { return false; }
		virtual void postEntityAction(World* world, Player* player, int action) {}
		virtual std::unique_ptr<Item> clone() { return NULL; }
		virtual nlohmann::json saveAttributes() { return NULL; }
	};
}
