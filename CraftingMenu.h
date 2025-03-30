#pragma once

#include "4dm.h"
#include "InventoryCursor.h"
#include "GUI/Window.h"
#include "GUI/Element.h"
#include "Item.h"

namespace fdm 
{
	using CraftingMenuCallback = std::add_pointer<bool(int reciperIndex, void* user)>::type;

	class InventoryManager;
	class InventoryCursor;
	class gui::Window;
	class gui::Element;

	class CraftingMenu : public gui::Element 
	{
	public:
		struct CraftableRecipe 
		{
			int recipeIndex; 
			PAD(0x4);
			std::vector<std::unique_ptr<Item>> recipe; // 0x8
			std::unique_ptr<Item> result; // 0x20
			int availableCount; // 0x28

			CraftableRecipe(int recipeIndex, nlohmann::json& j, int availableCount) 
			{
				reinterpret_cast<void(__thiscall*)(CraftingMenu::CraftableRecipe* self, int recipeIndex, nlohmann::json& j, int availableCount)>(getFuncAddr((int)Func::CraftingMenu::CraftableRecipe::CraftableRecipe))(this, recipeIndex, j, availableCount);
			}
			CraftableRecipe() { }

			void copy(const CraftableRecipe& other)
			{
				recipeIndex = other.recipeIndex;
				availableCount = other.availableCount;

				result = other.result->clone();
				result->count = other.result->count;

				recipe.clear();
				recipe.reserve(other.recipe.size());
				for (auto& itemB : other.recipe)
				{
					recipe.push_back(itemB->clone());
					recipe.back()->count = itemB->count;
				}
			}
			CraftableRecipe(const CraftableRecipe& other)
			{
				copy(other);
			}
			CraftableRecipe& operator=(const CraftableRecipe& other)
			{
				copy(other);
				return *this;
			}
			CraftableRecipe(CraftableRecipe&& other) noexcept
			{
				copy(other);

				other.recipeIndex = -1;
				other.availableCount = 0;
				other.result = NULL;
				other.recipe.clear();
			}
			CraftableRecipe& operator=(CraftableRecipe&& other) noexcept
			{
				copy(other);

				other.recipeIndex = -1;
				other.availableCount = 0;
				other.result = NULL;
				other.recipe.clear();

				return *this;
			}
		};
		InventoryManager* Interface; // 0x8
		InventoryCursor* cursor; // 0x10
		std::vector<CraftingMenu::CraftableRecipe> craftableRecipes; // 0x18
		int xOffset; // 0x30
		int yOffset; // 0x34
		gui::AlignmentX xAlign; // 0x38
		gui::AlignmentY yAlign; // 0x3C
		CraftingMenuCallback callback = NULL; // 0x40
		void* user; // 0x48
		inline static nlohmann::json& recipes = *reinterpret_cast<nlohmann::json*>(getDataAddr((int)Data::CraftingMenu::recipes));
		inline static TexRenderer& tr = *reinterpret_cast<TexRenderer*>(getDataAddr((int)Data::CraftingMenu::tr));

		inline static bool loadRecipes() 
		{
			return reinterpret_cast<bool (__fastcall*)()>(getFuncAddr((int)Func::CraftingMenu::loadRecipes))();
		}
		inline static void renderInit()
		{
			return reinterpret_cast<void (__fastcall*)()>(getFuncAddr((int)Func::CraftingMenu::renderInit))();
		}
		void render(gui::Window* w) override
		{
			return reinterpret_cast<void (__thiscall*)(CraftingMenu* self, gui::Window* w)>(getFuncAddr((int)Func::CraftingMenu::render))(this, w);
		}
		void offsetX(int offset) override
		{
			return reinterpret_cast<void (__thiscall*)(CraftingMenu* self, int offset)>(getFuncAddr((int)Func::CraftingMenu::offsetX))(this, offset);
		}
		void offsetY(int offset) override
		{
			return reinterpret_cast<void (__thiscall*)(CraftingMenu* self, int offset)>(getFuncAddr((int)Func::CraftingMenu::offsetY))(this, offset);
		}
		void alignX(gui::AlignmentX a) override
		{
			return reinterpret_cast<void(__thiscall*)(CraftingMenu * self, gui::AlignmentX)>(getFuncAddr((int)Func::CraftingMenu::alignX))(this, a);
		}
		void alignY(gui::AlignmentY a) override
		{
			return reinterpret_cast<void(__thiscall*)(CraftingMenu * self, gui::AlignmentY)>(getFuncAddr((int)Func::CraftingMenu::alignY))(this, a);
		}
		bool mouseInput(const gui::Window* w, double xpos, double ypos) override
		{
			return reinterpret_cast<bool(__thiscall*)(CraftingMenu * self, const gui::Window*, double, double)>(getFuncAddr((int)Func::CraftingMenu::mouseInput))(this, w, xpos, ypos);
		}
		void getPos(const gui::Window* w, int* x, int* y) const override
		{
			return reinterpret_cast<void (__thiscall*)(const CraftingMenu* self, const gui::Window* w, int* x, int* y)>(getFuncAddr((int)Func::CraftingMenu::getPos))(this, w, x, y);
		}
		void getSize(const gui::Window* w, int* width, int* height) const override
		{
			return reinterpret_cast<void (__thiscall*)(const CraftingMenu* self, const gui::Window* w, int* width, int* height)>(getFuncAddr((int)Func::CraftingMenu::getSize))(this, w, width, height);
		}
		bool mouseButtonInput(const gui::Window* w, int button, int action, int mods) override
		{
			return reinterpret_cast<bool (__thiscall*)(CraftingMenu* self, const gui::Window* w, int button, int action, int mods)>(getFuncAddr((int)Func::CraftingMenu::mouseButtonInput))(this, w, button, action, mods);
		}
		void updateAvailableRecipes() 
		{
			return reinterpret_cast<void (__thiscall*)(CraftingMenu* self)>(getFuncAddr((int)Func::CraftingMenu::updateAvailableRecipes))(this);
		}
		bool craftRecipe(int recipeIndex)
		{
			return reinterpret_cast<bool(__thiscall*)(CraftingMenu * self, int)>(getFuncAddr((int)Func::CraftingMenu::craftRecipe))(this, recipeIndex);
		}
	};
}
