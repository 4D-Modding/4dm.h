#pragma once

#include "4dm.h"

namespace fdm 
{
	class gui::Element 
	{
	public:

		bool enabled() override
		{
			return reinterpret_cast<bool (__thiscall*)(gui::Element* self)>(FUNC_GUI_ELEMENT_ENABLED)(this);
		}
		int getCursorType() override
		{
			return reinterpret_cast<int (__thiscall*)(gui::Element* self)>(FUNC_GUI_ELEMENT_GETCURSORTYPE)(this);
		}


		// VIRTUAL FUNCS

		virtual void render(gui::Window *) = NULL;
		virtual void alignX(gui::AlignmentX) = NULL;
		virtual void alignY(gui::AlignmentY) = NULL;
		virtual void offsetX(int) = NULL;
		virtual void offsetY(int) = NULL;
		virtual void getPos(const gui::Window &, int *, int *) = NULL;
		virtual void getSize(const gui::Window &, int *, int *) = NULL;
		virtual bool mouseInput(const gui::Window &, double, double) = NULL;
		virtual bool scrollInput(const gui::Window &, double, double) = NULL;
		virtual bool mouseButtonInput(const gui::Window &, int, int, int) = NULL;
		virtual bool keyInput(const gui::Window &, int, int, int, int) = NULL;
		virtual bool charInput(const gui::Window &, uint32_t) = NULL;
		virtual void select() = NULL;
		virtual void deselect() = NULL;
	};
}
