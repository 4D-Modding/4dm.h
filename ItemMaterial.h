#pragma once

#include "4dm.h"

namespace fdm 
{
	class ItemMaterial : public Item 
	{
	public:
		inline static constexpr const int STACK_MAX = 4096;
		stl::string name; // 0x10
		inline static TexRenderer& tr = *reinterpret_cast<TexRenderer*>(getDataAddr((int)Data::ItemMaterial::tr));
		inline static std::array<const glm::u8vec4, 64>& barTUV = *reinterpret_cast<std::array<const glm::u8vec4, 64>*>(getDataAddr((int)Data::ItemMaterial::barTUV));
		inline static MeshRenderer& hypersilkRenderer = *reinterpret_cast<MeshRenderer*>(getDataAddr((int)Data::ItemMaterial::hypersilkRenderer));
		inline static MeshRenderer& rockRenderer = *reinterpret_cast<MeshRenderer*>(getDataAddr((int)Data::ItemMaterial::rockRenderer));
		inline static MeshRenderer& barRenderer = *reinterpret_cast<MeshRenderer*>(getDataAddr((int)Data::ItemMaterial::barRenderer));
		inline static MeshRenderer& kleinBottleRenderer = *reinterpret_cast<MeshRenderer*>(getDataAddr((int)Data::ItemMaterial::kleinBottleRenderer));
		inline static MeshRenderer& healthPotionRenderer = *reinterpret_cast<MeshRenderer*>(getDataAddr((int)Data::ItemMaterial::healthPotionRenderer));
		inline static MeshRenderer& glassesFrameRenderer = *reinterpret_cast<MeshRenderer*>(getDataAddr((int)Data::ItemMaterial::glassesFrameRenderer));
		inline static MeshRenderer& glassesLensRenderer = *reinterpret_cast<MeshRenderer*>(getDataAddr((int)Data::ItemMaterial::glassesLensRenderer));

		uint32_t getStackLimit() override
		{
			return reinterpret_cast<uint32_t (__thiscall*)(ItemMaterial* self)>(getFuncAddr((int)Func::ItemMaterial::getStackLimit))(this);
		}
		stl::string getName() override
		{
			stl::string result;
			return reinterpret_cast<stl::string& (__thiscall*)(ItemMaterial* self, stl::string* result)>(getFuncAddr((int)Func::ItemMaterial::getName))(this, &result);
		}
		void render(const glm::ivec2& pos) override
		{
			return reinterpret_cast<void (__thiscall*)(ItemMaterial* self, const glm::ivec2& pos)>(getFuncAddr((int)Func::ItemMaterial::render))(this, pos);
		}
		void renderEntity(const m4::Mat5& MV, bool inHand, const glm::vec4& lightDir) override
		{
			return reinterpret_cast<void (__thiscall*)(ItemMaterial* self, const m4::Mat5 & MV, bool inHand, const glm::vec4 & lightDir)>(getFuncAddr((int)Func::ItemMaterial::renderEntity))(this, MV, inHand, lightDir);
		}
		bool isDeadly() override
		{
			return reinterpret_cast<bool (__thiscall*)(ItemMaterial* self)>(getFuncAddr((int)Func::ItemMaterial::isDeadly))(this);
		}
		bool isCompatible(const std::unique_ptr<Item>& other) override
		{
			return reinterpret_cast<bool (__thiscall*)(ItemMaterial* self, const std::unique_ptr<Item>& other)>(getFuncAddr((int)Func::ItemMaterial::isCompatible))(this, other);
		}
		bool action(World* world, Player* player, int action) override
		{
			return reinterpret_cast<bool (__thiscall*)(ItemMaterial* self, World* world, Player* player, int action)>(getFuncAddr((int)Func::ItemMaterial::action))(this, world, player, action);
		}
		void postAction(World* world, Player* player, int action) override
		{
			return reinterpret_cast<void (__thiscall*)(ItemMaterial* self, World* world, Player* player, int action)>(getFuncAddr((int)Func::ItemMaterial::postAction))(this, world, player, action);
		}
		bool breakBlock(World* world, Player* player, uint8_t block, const glm::ivec4& blockPos) override
		{
			return reinterpret_cast<bool(__thiscall*)(ItemMaterial * self, World*, Player*, uint8_t, const glm::ivec4&)>(getFuncAddr((int)Func::ItemMaterial::breakBlock))(this, world, player, block, blockPos);
		}
		bool entityAction(World* world, Player* player, Entity* entity, int action) override
		{
			return reinterpret_cast<bool(__thiscall*)(ItemMaterial * self, World*, Player*, Entity*, int)>(getFuncAddr((int)Func::ItemMaterial::entityAction))(this, world, player, entity, action);
		}
		std::unique_ptr<Item> clone() override
		{
			std::unique_ptr<Item> result;
			reinterpret_cast<std::unique_ptr<Item>& (__thiscall*)(ItemMaterial* self, std::unique_ptr<Item>* result)>(getFuncAddr((int)Func::ItemMaterial::clone))(this, &result);
			return result;
		}
		nlohmann::json saveAttributes() override
		{
			nlohmann::json result;
			reinterpret_cast<nlohmann::json& (__thiscall*)(ItemMaterial * self, nlohmann::json * result)>(getFuncAddr((int)Func::ItemMaterial::saveAttributes))(this, &result);
			return result;
		}
		inline static void initGlassesMesh()
		{
			return reinterpret_cast<void(__fastcall*)()>(getFuncAddr((int)Func::ItemMaterial::initGlassesMesh))();
		}
		inline static void renderInit()
		{
			return reinterpret_cast<void(__fastcall*)()>(getFuncAddr((int)Func::ItemMaterial::renderInit))();
		}
	};
}
