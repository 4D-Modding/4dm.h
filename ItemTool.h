#pragma once

#include "4dm.h"

namespace fdm 
{
	class ItemTool : public Item 
	{
	public:
		std::string name; // 0x10
		inline static const float scaleFactor = 0.15f; 
		inline static glm::vec4* *pickaxeVerts = reinterpret_cast<glm::vec4**>((base + 0x29B600)); 
		inline static glm::vec4* *pickaxeNormals = reinterpret_cast<glm::vec4**>((base + 0x29BC40)); 
		inline static glm::vec3* *ironPickTUV = reinterpret_cast<glm::vec3**>((base + 0x29BA60)); 
		inline static glm::vec3* *deadlyPickTUV = reinterpret_cast<glm::vec3**>((base + 0x29B880)); 
		inline static glm::u8vec4* *ultrahammerTUV = reinterpret_cast<glm::u8vec4**>((base + 0x2AF3F0)); 
		inline static glm::u8vec4* *solenoidCollectorTUV = reinterpret_cast<glm::u8vec4**>((base + 0x2AF2F0)); 
		inline static MeshRenderer *ironPickaxeRenderer = reinterpret_cast<MeshRenderer*>((base + 0x279D68)); 
		inline static MeshRenderer *deadlyPickaxeRenderer = reinterpret_cast<MeshRenderer*>((base + 0x279D88)); 
		inline static MeshRenderer *rockRenderer = reinterpret_cast<MeshRenderer*>((base + 0x279E48)); 
		inline static MeshRenderer *ultrahammerRenderer = reinterpret_cast<MeshRenderer*>((base + 0x279E68)); 
		inline static MeshRenderer *solenoidCollectorRenderer = reinterpret_cast<MeshRenderer*>((base + 0x279DC8)); 
		inline static Coil* coilMesh = reinterpret_cast<Coil*>((base + 0x2C1E48));
		inline static MeshRenderer* coilRenderer = reinterpret_cast<MeshRenderer*>((base + 0x279DA8));
		inline static Dodecaplex* collectorBall = reinterpret_cast<Dodecaplex*>((base + 0x279DF0));
		inline static MeshRenderer* collectorBallRenderer = reinterpret_cast<MeshRenderer*>((base + 0x279E88));
		inline static bool* collectorAnimation = reinterpret_cast<bool*>((base + 0x29B3E1));
		inline static TexRenderer* tr = reinterpret_cast<TexRenderer*>((base + 0x2C1E20));

		void render(const glm::ivec2& pos) override
		{
			return reinterpret_cast<void (__thiscall*)(ItemTool* self, const glm::ivec2& pos)>(FUNC_ITEMTOOL_RENDER)(this, pos);
		}
		void renderEntity(const m4::Mat5& mat, bool inHand, const glm::vec4& lightDir) override
		{
			return reinterpret_cast<void (__thiscall*)(ItemTool* self, const m4::Mat5& mat, bool inHand, const glm::vec4& lightDir)>(FUNC_ITEMTOOL_RENDERENTITY)(this, mat, inHand, lightDir);
		}
		bool isDeadly() override
		{
			return reinterpret_cast<bool (__thiscall*)(ItemTool* self)>(FUNC_ITEMTOOL_ISDEADLY)(this);
		}
		bool isCompatible(const std::unique_ptr<Item>& other) override
		{
			return reinterpret_cast<bool (__thiscall*)(ItemTool* self, const std::unique_ptr<Item>& other)>(FUNC_ITEMTOOL_ISCOMPATIBLE)(this, other);
		}
		uint32_t getStackLimit() override
		{
			return reinterpret_cast<uint32_t (__thiscall*)(ItemTool* self)>(FUNC_ITEMTOOL_GETSTACKLIMIT)(this);
		}
		bool action(World* world, Player* player, int action) override
		{
			return reinterpret_cast<bool (__thiscall*)(ItemTool* self, World* world, Player* player, int action)>(FUNC_ITEMTOOL_ACTION)(this, world, player, action);
		}
		bool breakBlock(World* world, Player* player, unsigned char block, const glm::ivec4& blockPos) override
		{
			return reinterpret_cast<bool (__thiscall*)(ItemTool* self, World* world, Player* player, unsigned char block, const glm::ivec4& blockPos)>(FUNC_ITEMTOOL_BREAKBLOCK)(this, world, player, block, blockPos);
		}
		bool entityAction(World* world, Player* player, Entity* entity, int action) override
		{
			return reinterpret_cast<bool (__thiscall*)(ItemTool* self, World* world, Player* player, Entity* entity, int action)>(FUNC_ITEMTOOL_ENTITYACTION)(this, world, player, entity, action);
		}
		std::unique_ptr<Item> clone() override
		{
			std::unique_ptr<Item> result;
			return reinterpret_cast<std::unique_ptr<Item> (__thiscall*)(ItemTool* self, std::unique_ptr<Item>* result)>(FUNC_ITEMTOOL_CLONE)(this, &result);
		}
	};
}
