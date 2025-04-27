#pragma once

#include "4dm.h"
#include "CraftingMenu.h"
#include "GUI/gui.h"

namespace fdm 
{
	using InventoryUpdateCallback = std::add_pointer<bool(const nlohmann::json& action, void* user)>::type;
	class InventoryManager 
	{
	public:
		enum TransferAction : int
		{
			ACTION_SWAP = 0x0,
			ACTION_TAKE_HALF = 0x1,
			ACTION_GIVE_MAX = 0x2,
			ACTION_GIVE_ONE = 0x3,
			ACTION_MOVE = 0x4,
		};
		class iterator 
		{
		public:
			InventoryManager* Interface; 
			int index; // 0x8
		};
		inline static const int scale = 2; 
		inline static FontRenderer& font = *reinterpret_cast<FontRenderer*>(getDataAddr((int)Data::InventoryManager::font));
		Inventory* primary; 
		Inventory* secondary; // 0x8
		InventoryCursor cursor; // 0x10
		PAD(0x1); // --> boost::uuids::string_generator uuidParser
		PAD(0x3);
		int wWidth; // 0x24
		int wHeight; // 0x28
		PAD(0x4);
		QuadRenderer qr; // 0x30
		const Shader* qs; // 0x58
		gui::Interface ui; // 0x60
		gui::Text craftingText; // 0xC8
		gui::ContentBox craftingMenuBox; // 0x120
		CraftingMenu craftingMenu; // 0x1A0
		InventoryUpdateCallback callback = NULL; // 0x1F0
		void* user; // 0x1F8

		InventoryManager(){}
		~InventoryManager() 
		{
			reinterpret_cast<void(__thiscall*)(InventoryManager* self)>(getFuncAddr((int)Func::InventoryManager::destr_InventoryManager))(this);
		}
		void renderInit(GLFWwindow* w) 
		{
			return reinterpret_cast<void (__thiscall*)(InventoryManager* self, GLFWwindow* w)>(getFuncAddr((int)Func::InventoryManager::renderInit))(this, w);
		}
		bool mouseButtonInput(uint32_t x, uint32_t y, uint32_t button, int action, int mods) 
		{
			return reinterpret_cast<bool (__thiscall*)(InventoryManager* self, uint32_t x, uint32_t y, uint32_t button, int action, int mods)>(getFuncAddr((int)Func::InventoryManager::mouseButtonInput))(this, x, y, button, action, mods);
		}
		void windowResize(GLFWwindow* w, int width, int height) 
		{
			return reinterpret_cast<void (__thiscall*)(InventoryManager* self, GLFWwindow* w, int width, int height)>(getFuncAddr((int)Func::InventoryManager::windowResize))(this, w, width, height);
		}
		bool applyAction(World* world, Player* player, const nlohmann::json& action)
		{
			return reinterpret_cast<bool (__thiscall*)(InventoryManager* self, World* world, Player* player, const nlohmann::json& action)>(getFuncAddr((int)Func::InventoryManager::applyAction))(this, world, player, action);
		}
		bool applyTransfer(InventoryManager::TransferAction action, std::unique_ptr<Item>& selectedSlot, std::unique_ptr<Item>& cursorSlot, Inventory* other) 
		{
			return reinterpret_cast<bool (__thiscall*)(InventoryManager* self, InventoryManager::TransferAction action, std::unique_ptr<Item>& selectedSlot, std::unique_ptr<Item>& cursorSlot, Inventory* other)>(getFuncAddr((int)Func::InventoryManager::applyTransfer))(this, action, selectedSlot, cursorSlot, other);
		}
		Inventory* findInventory(World* world, Player* player, const stl::string& inventoryName) 
		{
			return reinterpret_cast<Inventory* (__thiscall*)(InventoryManager* self, World* world, Player* player, const stl::string& inventoryName)>(getFuncAddr((int)Func::InventoryManager::findInventory))(this, world, player, inventoryName);
		}
		void updateCraftingMenuBox() 
		{
			return reinterpret_cast<void (__thiscall*)(InventoryManager* self)>(getFuncAddr((int)Func::InventoryManager::updateCraftingMenuBox))(this);
		}
		inline static bool craftingMenuCallback(int recipeIndex, void* user) 
		{
			return reinterpret_cast<bool (__fastcall*)(int recipeIndex, void* user)>(getFuncAddr((int)Func::InventoryManager::craftingMenuCallback))(recipeIndex, user);
		}
		inline static void viewportCallback(void* user, const glm::ivec4& pos, const glm::ivec2& scroll) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, const glm::ivec4& pos, const glm::ivec2& scroll)>(getFuncAddr((int)Func::InventoryManager::viewportCallback))(user, pos, scroll);
		}
		void updateProjection(const glm::ivec2& size, const glm::ivec2& translate2D) 
		{
			return reinterpret_cast<void (__thiscall*)(InventoryManager* self, const glm::ivec2& size, const glm::ivec2& translate2D)>(getFuncAddr((int)Func::InventoryManager::updateProjection))(this, size, translate2D);
		}
		bool isOpen()
		{
			return primary && secondary;
		}
	};
}
