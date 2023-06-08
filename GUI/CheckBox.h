#pragma once
#ifndef GUI_CHECKBOX_H
#define GUI_CHECKBOX_H
#include "gui.h"
namespace fdm
{
	namespace gui
	{
		using CheckBoxCallback = std::add_pointer<void(void* user, bool checked)>::type;

		class Window;
		class Element;
		enum AlignmentX;
		enum AlignmentY;

		class CheckBox : public Element
		{
		public:
			std::string text;
			bool clickable = true;
			bool mouseDown;
			bool selected;
			PAD(1);
			int xOffset;
			int yOffset;
			AlignmentX xAlign;
			AlignmentY yAlign;
			PAD(4);
			void* user;
			CheckBoxCallback callback = NULL;
			bool checked;

			void offsetX(int offset) override
			{
				this->xOffset = offset;
			}
			void offsetY(int offset) override
			{
				this->yOffset = offset;
			}
			void alignX(AlignmentX a) override
			{
				this->xAlign = a;
			}
			void alignY(AlignmentY a) override
			{
				this->yAlign = a;
			}
			void render(Window* w) override 
			{
				reinterpret_cast<void(__thiscall*)(CheckBox*, Window*)>(
					FUNC_GUI_CHECKBOX_RENDER
					)(this, w);
			}
			bool mouseButtonInput(const Window* w, int button, int action, int mods) override
			{
				return reinterpret_cast<bool(__thiscall*)(CheckBox*, const Window*, int, int, int)>(
					FUNC_GUI_CHECKBOX_MOUSEBUTTONINPUT
					)(this, w, button, action, mods);
			}
			bool keyInput(const Window* w, int key, int scancode, int action, int mods) override
			{
				return reinterpret_cast<bool(__thiscall*)(CheckBox*, const Window*, int, int, int, int)>(
					FUNC_GUI_CHECKBOX_KEYINPUT
					)(this, w, key, scancode, action, mods);
			}
			void getPos(const Window* w, int* x, int* y) override
			{
				reinterpret_cast<void(__thiscall*)(CheckBox*, const Window*, int*, int*)>(
					FUNC_GUI_CHECKBOX_GETPOS
					)(this, w, x, y);
			}
			void getSize(const Window* w, int* width, int* height) override
			{
				reinterpret_cast<void(__thiscall*)(CheckBox*, const Window*, int*, int*)>(
					FUNC_GUI_CHECKBOX_GETSIZE
					)(this, w, width, height);
			}
			bool touchingMouse(const Window* w)
			{
				return reinterpret_cast<bool(__thiscall*)(CheckBox*, const Window*)>(
					FUNC_GUI_CHECKBOX_TOUCHINGMOUSE
					)(this, w);
			}
		};
	}
}
#endif