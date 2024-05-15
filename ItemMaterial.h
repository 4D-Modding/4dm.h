#pragma once

#include "4dm.h"

namespace fdm 
{
	class ItemMaterial : public Item 
	{
	public:
		inline static const int STACK_MAX = 4096; 
		stl::string name; // 0x10
		inline static TexRenderer* tr = reinterpret_cast<TexRenderer*>((base + 0x2BF0A8));
		inline static glm::u8vec4* barTUV = reinterpret_cast<glm::u8vec4*>((base + 0x2AD220));
		inline static MeshRenderer *hypersilkRenderer = reinterpret_cast<MeshRenderer*>((base + 0x2795C0)); 
		inline static MeshRenderer *rockRenderer = reinterpret_cast<MeshRenderer*>((base + 0x2795E0)); 
		inline static MeshRenderer *barRenderer = reinterpret_cast<MeshRenderer*>((base + 0x279580)); 
		inline static MeshRenderer *kleinBottleRenderer = reinterpret_cast<MeshRenderer*>((base + 0x279560)); 
		inline static MeshRenderer *healthPotionRenderer = reinterpret_cast<MeshRenderer*>((base + 0x2795A0)); 
		inline static MeshRenderer *glassesFrameRenderer = reinterpret_cast<MeshRenderer*>((base + 0x279600)); 
		inline static MeshRenderer *glassesLensRenderer = reinterpret_cast<MeshRenderer*>((base + 0x279620)); 

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
		std::unique_ptr<Item> clone() override
		{
			std::unique_ptr<Item> result;
			reinterpret_cast<std::unique_ptr<Item>* (__thiscall*)(ItemMaterial* self, std::unique_ptr<Item>* result)>(getFuncAddr((int)Func::ItemMaterial::clone))(this, &result);
			return result;
		}
	};
}
