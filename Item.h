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
			return reinterpret_cast<bool (__fastcall*)()>(FUNC_ITEM_LOADITEMINFO)();
		}
		inline static void renderItem(std::unique_ptr<Item>& item, const glm::ivec2& pos) 
		{
			return reinterpret_cast<void (__fastcall*)(std::unique_ptr<Item>& item, const glm::ivec2& pos)>(FUNC_ITEM_RENDERITEM)(item, pos);
		}
		inline static void renderItemDescription(std::unique_ptr<Item>& item, const glm::ivec2& pos) 
		{
			return reinterpret_cast<void (__fastcall*)(std::unique_ptr<Item>& item, const glm::ivec2& pos)>(FUNC_ITEM_RENDERITEMDESCRIPTION)(item, pos);
		}
		inline static std::unique_ptr<Item> createFromJson(nlohmann::json& j) 
		{
			return reinterpret_cast<std::unique_ptr<Item> (__fastcall*)(nlohmann::json& j)>(FUNC_ITEM_CREATEFROMJSON)(j);
		}
		inline static bool giveMax(std::unique_ptr<Item>& from, std::unique_ptr<Item>& to) 
		{
			return reinterpret_cast<bool (__fastcall*)(std::unique_ptr<Item>& from, std::unique_ptr<Item>& to)>(FUNC_ITEM_GIVEMAX)(from, to);
		}
		inline static bool giveOne(std::unique_ptr<Item>& from, std::unique_ptr<Item>& to) 
		{
			return reinterpret_cast<bool (__fastcall*)(std::unique_ptr<Item>& from, std::unique_ptr<Item>& to)>(FUNC_ITEM_GIVEONE)(from, to);
		}
		inline static std::unique_ptr<Item> instantiateItem(const std::string& itemName, uint32_t count, const std::string& type, nlohmann::json& attributes) 
		{
			return reinterpret_cast<std::unique_ptr<Item> (__fastcall*)(const std::string& itemName, uint32_t count, const std::string& type, nlohmann::json& attributes)>(FUNC_ITEM_INSTANTIATEITEM)(itemName, count, type, attributes);
		}
		inline static nlohmann::json combineItemAttributes(nlohmann::json& baseAttributes, nlohmann::json& additions) 
		{
			return reinterpret_cast<nlohmann::json (__fastcall*)(nlohmann::json& baseAttributes, nlohmann::json& additions)>(FUNC_ITEM_COMBINEITEMATTRIBUTES)(baseAttributes, additions);
		}
		nlohmann::json save() 
		{
			nlohmann::json result;
			return reinterpret_cast<nlohmann::json (__thiscall*)(Item* self, nlohmann::json* result)>(FUNC_ITEM_SAVE)(this, &result);
			return result;
		}
		~Item()
		{
			reinterpret_cast<void(__thiscall*)(Item* self)>(FUNC_ITEM_DESTR_ITEM)(this);
		}
		bool takeMax(std::unique_ptr<Item>& other) 
		{
			return reinterpret_cast<bool (__thiscall*)(Item* self, std::unique_ptr<Item>& other)>(FUNC_ITEM_TAKEMAX)(this, other);
		}
		bool takeHalf(std::unique_ptr<Item>& other) 
		{
			return reinterpret_cast<bool (__thiscall*)(Item* self, std::unique_ptr<Item>& other)>(FUNC_ITEM_TAKEHALF)(this, other);
		}


		// VIRTUAL FUNCS

		virtual std::string getName() { return ""; }
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
