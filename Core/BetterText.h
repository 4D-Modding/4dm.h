#pragma once

#include "../4dm.h"

namespace fdm::Core
{
	class BetterText : public gui::Text
	{
	public:
		int fontSize = 16;
		TTFRenderer ttf;
		void render(gui::Window* w) override
		{
			reinterpret_cast<void(__thiscall*)(BetterText * self, gui::Window * w)>(getFuncAddr((int)Func::Core::BetterText::render))(this, w);
		}
		void getSize(const gui::Window* w, int* width, int* height) const override
		{
			reinterpret_cast<void(__thiscall*)(const BetterText * self, const gui::Window * w, int* width, int* height)>(getFuncAddr((int)Func::Core::BetterText::getSize))(this, w, width, height);
		}
		void updateTTF()
		{
			reinterpret_cast<void(__thiscall*)(BetterText * self)>(getFuncAddr((int)Func::Core::BetterText::updateTTF))(this);
		}
	};
}
