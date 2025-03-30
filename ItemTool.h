#pragma once

#include "4dm.h"

namespace fdm 
{
	class ItemTool : public Item 
	{
	public:
		stl::string name; // 0x10
		inline static constexpr const float scaleFactor = 0.15f;
		inline static std::array<glm::vec4, 40>& pickaxeVerts = *reinterpret_cast<std::array<glm::vec4, 40>*>(getDataAddr((int)Data::ItemTool::pickaxeVerts));
		inline static std::array<glm::vec4, 10>& pickaxeNormals = *reinterpret_cast<std::array<glm::vec4, 10>*>(getDataAddr((int)Data::ItemTool::pickaxeNormals));
		inline static std::array<glm::vec3, 40>& ironPickTUV = *reinterpret_cast<std::array<glm::vec3, 40>*>(getDataAddr((int)Data::ItemTool::ironPickTUV));
		inline static std::array<glm::vec3, 40>& deadlyPickTUV = *reinterpret_cast<std::array<glm::vec3, 40>*>(getDataAddr((int)Data::ItemTool::deadlyPickTUV));
		inline static std::array<const glm::u8vec4, 64>& ultrahammerTUV = *reinterpret_cast<std::array<const glm::u8vec4, 64>*>(getDataAddr((int)Data::ItemTool::ultrahammerTUV));
		inline static std::array<const glm::u8vec4, 64>& solenoidCollectorTUV = *reinterpret_cast<std::array<const glm::u8vec4, 64>*>(getDataAddr((int)Data::ItemTool::solenoidCollectorTUV));
		inline static MeshRenderer& ironPickaxeRenderer = *reinterpret_cast<MeshRenderer*>(getDataAddr((int)Data::ItemTool::ironPickaxeRenderer));
		inline static MeshRenderer& deadlyPickaxeRenderer = *reinterpret_cast<MeshRenderer*>(getDataAddr((int)Data::ItemTool::deadlyPickaxeRenderer));
		inline static MeshRenderer& rockRenderer = *reinterpret_cast<MeshRenderer*>(getDataAddr((int)Data::ItemTool::rockRenderer));
		inline static MeshRenderer& ultrahammerRenderer = *reinterpret_cast<MeshRenderer*>(getDataAddr((int)Data::ItemTool::ultrahammerRenderer));
		inline static MeshRenderer& solenoidCollectorRenderer = *reinterpret_cast<MeshRenderer*>(getDataAddr((int)Data::ItemTool::solenoidCollectorRenderer));
		inline static Coil& coilMesh = *reinterpret_cast<Coil*>(getDataAddr((int)Data::ItemTool::coilMesh));
		inline static MeshRenderer& coilRenderer = *reinterpret_cast<MeshRenderer*>(getDataAddr((int)Data::ItemTool::coilRenderer));
		inline static Dodecaplex& collectorBall = *reinterpret_cast<Dodecaplex*>(getDataAddr((int)Data::ItemTool::collectorBall));
		inline static MeshRenderer& collectorBallRenderer = *reinterpret_cast<MeshRenderer*>(getDataAddr((int)Data::ItemTool::collectorBallRenderer));
		inline static bool& collectorAnimation = *reinterpret_cast<bool*>(getDataAddr((int)Data::ItemTool::collectorAnimation));
		inline static TexRenderer& tr = *reinterpret_cast<TexRenderer*>(getDataAddr((int)Data::ItemTool::tr));

		void render(const glm::ivec2& pos) override
		{
			return reinterpret_cast<void (__thiscall*)(ItemTool* self, const glm::ivec2& pos)>(getFuncAddr((int)Func::ItemTool::render))(this, pos);
		}
		void renderEntity(const m4::Mat5& mat, bool inHand, const glm::vec4& lightDir) override
		{
			return reinterpret_cast<void (__thiscall*)(ItemTool* self, const m4::Mat5& mat, bool inHand, const glm::vec4& lightDir)>(getFuncAddr((int)Func::ItemTool::renderEntity))(this, mat, inHand, lightDir);
		}
		bool isDeadly() override
		{
			return reinterpret_cast<bool (__thiscall*)(ItemTool* self)>(getFuncAddr((int)Func::ItemTool::isDeadly))(this);
		}
		bool isCompatible(const std::unique_ptr<Item>& other) override
		{
			return reinterpret_cast<bool (__thiscall*)(ItemTool* self, const std::unique_ptr<Item>& other)>(getFuncAddr((int)Func::ItemTool::isCompatible))(this, other);
		}
		uint32_t getStackLimit() override
		{
			return reinterpret_cast<uint32_t (__thiscall*)(ItemTool* self)>(getFuncAddr((int)Func::ItemTool::getStackLimit))(this);
		}
		bool action(World* world, Player* player, int action) override
		{
			return reinterpret_cast<bool (__thiscall*)(ItemTool* self, World* world, Player* player, int action)>(getFuncAddr((int)Func::ItemTool::action))(this, world, player, action);
		}
		bool breakBlock(World* world, Player* player, unsigned char block, const glm::ivec4& blockPos) override
		{
			return reinterpret_cast<bool (__thiscall*)(ItemTool* self, World* world, Player* player, unsigned char block, const glm::ivec4& blockPos)>(getFuncAddr((int)Func::ItemTool::breakBlock))(this, world, player, block, blockPos);
		}
		bool entityAction(World* world, Player* player, Entity* entity, int action) override
		{
			return reinterpret_cast<bool (__thiscall*)(ItemTool* self, World* world, Player* player, Entity* entity, int action)>(getFuncAddr((int)Func::ItemTool::entityAction))(this, world, player, entity, action);
		}
		std::unique_ptr<Item> clone() override
		{
			std::unique_ptr<Item> result;
			reinterpret_cast<std::unique_ptr<Item>& (__thiscall*)(ItemTool* self, std::unique_ptr<Item>* result)>(getFuncAddr((int)Func::ItemTool::clone))(this, &result);
			return result;
		}
		stl::string getName() override
		{
			return reinterpret_cast<stl::string(__thiscall*)(ItemTool * self)>(getFuncAddr((int)Func::ItemTool::getName))(this);
		}
		nlohmann::json saveAttributes() override
		{
			nlohmann::json result;
			reinterpret_cast<nlohmann::json& (__thiscall*)(ItemTool * self, nlohmann::json * result)>(getFuncAddr((int)Func::ItemTool::saveAttributes))(this, &result);
			return result;
		}
		inline static void renderInit()
		{
			return reinterpret_cast<void(__fastcall*)()>(getFuncAddr((int)Func::ItemTool::renderInit))();
		}
	};
}
