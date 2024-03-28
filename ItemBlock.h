#pragma once

#include "4dm.h"
#include "Player.h"

namespace fdm 
{
	class ItemBlock : public Item 
	{
	public:
		inline static const int STACK_MAX = 4096; 
		inline static TexRenderer* tr = reinterpret_cast<TexRenderer*>((base + 0x2BDF18));
		int blockID; // 0x10

		void render(const glm::ivec2& pos) override
		{
			return reinterpret_cast<void (__thiscall*)(ItemBlock* self, const glm::ivec2& pos)>(getFuncAddr((int)Func::ItemBlock::render))(this, pos);
		}
		void renderEntity(const m4::Mat5& MV, bool inHand, const glm::vec4& lightDir) override
		{
			return reinterpret_cast<void (__thiscall*)(ItemBlock* self, const m4::Mat5& MV, bool inHand, const glm::vec4& lightDir)>(getFuncAddr((int)Func::ItemBlock::renderEntity))(this, MV, inHand, lightDir);
		}
		bool isDeadly() override
		{
			return reinterpret_cast<bool (__thiscall*)(ItemBlock* self)>(getFuncAddr((int)Func::ItemBlock::isDeadly))(this);
		}
		bool isCompatible(const std::unique_ptr<Item>& other) override
		{
			return reinterpret_cast<bool (__thiscall*)(ItemBlock* self, const std::unique_ptr<Item>& other)>(getFuncAddr((int)Func::ItemBlock::isCompatible))(this, other);
		}
		nlohmann::json saveAttributes() override
		{
			nlohmann::json result;
			return reinterpret_cast<nlohmann::json& (__thiscall*)(ItemBlock* self, nlohmann::json* result)>(getFuncAddr((int)Func::ItemBlock::saveAttributes))(this, &result);
		}
		bool action(World* world, Player* player, int action) override
		{
			return reinterpret_cast<bool (__thiscall*)(ItemBlock* self, World* world, Player* player, int action)>(getFuncAddr((int)Func::ItemBlock::action))(this, world, player, action);
		}
		void postAction(World* world, Player* player, int action) override
		{
			return reinterpret_cast<void (__thiscall*)(ItemBlock* self, World* world, Player* player, int action)>(getFuncAddr((int)Func::ItemBlock::postAction))(this, world, player, action);
		}
		std::unique_ptr<Item> clone() override
		{
			std::unique_ptr<Item> item;
			return reinterpret_cast<std::unique_ptr<Item> (__thiscall*)(ItemBlock* self, std::unique_ptr<Item>* result)>(getFuncAddr((int)Func::ItemBlock::clone))(this, &item);
		}
	};
}
