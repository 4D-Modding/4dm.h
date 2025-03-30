#pragma once

#include "../4dm.h"
#include "Counter.h"
#include "Mod.h"

namespace fdm::Core
{
	class ModElement : public gui::Button
	{
	public:
		Mod* modInfo;

		TexRenderer iconTex;
		gui::Image iconImage;
		gui::Text nameText;
		gui::Text authorText;
		gui::Text modVerText;
		gui::Text idText;
		gui::CheckBox enabledCheckbox;
		bool isLoaded;
		Counter errors;
		Counter warnings;

		gui::ContentBox* cb;

		bool isSelected = false;

		ModElement() { }
		ModElement(Mod* modInfo, gui::ContentBox* cb, bool isLoaded, int criticalErrors, int warningErrors)
		{
			reinterpret_cast<void(__thiscall*)(ModElement* self, Mod*, gui::ContentBox*, bool, int, int)>(getFuncAddr((int)Func::Core::ModElement::ModElement))(this, modInfo, cb, isLoaded, criticalErrors, warningErrors);
		}

		void render(gui::Window* w) override
		{
			reinterpret_cast<void(__thiscall*)(ModElement * self, gui::Window*)>(getFuncAddr((int)Func::Core::ModElement::render))(this, w);
		}
		bool mouseButtonInput(const gui::Window* w, int button, int action, int mods) override
		{
			return reinterpret_cast<bool(__thiscall*)(ModElement * self, const gui::Window*, int, int, int)>(getFuncAddr((int)Func::Core::ModElement::mouseButtonInput))(this, w, button, action, mods);
		}
	};
}
