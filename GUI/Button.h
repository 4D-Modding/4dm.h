#pragma once
#ifndef GUI_BTN_H
#define GUI_BTN_H
#include "gui.h"
namespace fdm
{
	namespace gui
	{
		using ButtonCallback = std::add_pointer<void(void* user)>::type;

		class Element;
		class Window;
		enum AlignmentX;
		enum AlignmentY;

		class Button : public Element
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
			int width = 200;
			int height = 50;
			PAD(4);
			void* user;
			ButtonCallback callback = NULL;

			~Button() 
			{
				reinterpret_cast<void(__thiscall*)(Button*)>(
					base + idaOffsetFix(0x3EFA0)
					)(this);
			}
			void render(Window* w) override 
			{
				reinterpret_cast<void(__thiscall*)(Button*, Window*)>(
					base + idaOffsetFix(0x56A00)
					)(this, w);
			}
			bool mouseButtonInput(const Window* w, int button, int action, int mods) override
			{
				return reinterpret_cast<bool(__thiscall*)(Button*, const Window*, int, int, int)>(
					base + idaOffsetFix(0x57110)
					)(this, w, button, action, mods);
			}
			bool keyInput(const Window* w, int key, int scancode, int action, int mods) override 
			{
				return reinterpret_cast<bool(__thiscall*)(Button*, const Window*, int, int, int, int)>(
					base + idaOffsetFix(0x57190)
					)(this, w, key, scancode, action, mods);
			}
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
			bool enabled() override 
			{
				return this->clickable;
			}
			void getPos(const Window* w, int* x, int* y) override 
			{
				reinterpret_cast<void(__thiscall*)(Button*, const Window*, int*, int*)>(
					base + idaOffsetFix(0x57220)
					)(this, w, x, y);
			}
			void getSize(const Window* w, int* width, int* height) override
			{
				reinterpret_cast<void(__thiscall*)(Button*, const Window*, int*, int*)>(
					base + idaOffsetFix(0x572E0)
					)(this, w, width, height);
			}
			bool touchingMouse(const Window* w) 
			{
				return reinterpret_cast<bool(__thiscall*)(Button*, const Window*)>(
					base + idaOffsetFix(0x572F0)
					)(this, w);
			}

		};
	}
}
#endif