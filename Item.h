#pragma once

#include "4dm.h"

namespace fdm 
{
	class Item 
	{
	public:
		inline static constexpr FontRenderer fr = *reinterpret_cast<FontRenderer*>((base + 0x2794A0)); 
		inline static constexpr QuadRenderer qr = *reinterpret_cast<QuadRenderer*>((base + 0x278F18)); 
		inline static constexpr nlohmann::json blueprints = *reinterpret_cast<nlohmann::json*>((base + 0x2BF098)); 
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
		inline static std::unique_ptr<Item,std::default_delete<Item> > createFromJson(nlohmann::json& j) 
		{
			return reinterpret_cast<std::unique_ptr<Item,std::default_delete<Item> > (__fastcall*)(std::unique_ptr<Item>& result, nlohmann::json& j)>(FUNC_ITEM_CREATEFROMJSON)(result, j);
		}
		inline static bool giveMax(std::unique_ptr<Item>& from, std::unique_ptr<Item>& to) 
		{
			return reinterpret_cast<bool (__fastcall*)(std::unique_ptr<Item>& from, std::unique_ptr<Item>& to)>(FUNC_ITEM_GIVEMAX)(from, to);
		}
		inline static bool giveOne(std::unique_ptr<Item>& from, std::unique_ptr<Item>& to) 
		{
			return reinterpret_cast<bool (__fastcall*)(std::unique_ptr<Item>& from, std::unique_ptr<Item>& to)>(FUNC_ITEM_GIVEONE)(from, to);
		}
		inline static std::unique_ptr<Item,std::default_delete<Item> > instantiateItem(const std::string& itemName, uint32_t count, const std::string& type, nlohmann::json& attributes) 
		{
			return reinterpret_cast<std::unique_ptr<Item,std::default_delete<Item> > (__fastcall*)(std::unique_ptr<Item>& result, const std::string& itemName, uint32_t count, const std::string& type, nlohmann::json& attributes)>(FUNC_ITEM_INSTANTIATEITEM)(result, itemName, count, type, attributes);
		}
		inline static nlohmann::json combineItemAttributes(nlohmann::json& baseAttributes, nlohmann::json& additions) 
		{
			return reinterpret_cast<nlohmann::json (__fastcall*)(nlohmann::json& result, nlohmann::json& baseAttributes, nlohmann::json& additions)>(FUNC_ITEM_COMBINEITEMATTRIBUTES)(result, baseAttributes, additions);
		}
		nlohmann::json save() 
		{
			return reinterpret_cast<nlohmann::json (__thiscall*)(Item* self, nlohmann::json& result)>(FUNC_ITEM_SAVE)(this, result);
		}
		~Item() override
		{
			return reinterpret_cast<void(__thiscall*)(Item* self)>(FUNC_ITEM_DESTR_ITEM)(this);
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

		virtual std::string getName() = NULL;
		virtual void render(const glm::ivec2& pos) = NULL;
		virtual void renderEntity(const m4::Mat5& MV, bool inHand, const glm::vec4& lightDir) = NULL;
		virtual bool isDeadly() = NULL;
		virtual bool isCompatible(const std::unique_ptr<Item>& other) = NULL;
		virtual uint32_t getStackLimit() = NULL;
		virtual bool action(World* world, Player* player, int action) = NULL;
		virtual void postAction(World* world, Player* player, int action) = NULL;
		virtual bool breakBlock(World* world, Player* player, unsigned char block, const glm::ivec4& blockPos) = NULL;
		virtual void postBreakBlock(World* world, Player* player) = NULL;
		virtual bool entityAction(World* world, Player* player, Entity* entity, int action) = NULL;
		virtual void postEntityAction(World* world, Player* player, int action) = NULL;
		virtual std::unique_ptr<Item,std::default_delete<Item> > clone() = NULL;
		virtual nlohmann::json saveAttributes() = NULL;
	};
}
