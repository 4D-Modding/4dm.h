#pragma once
#ifndef GUI_SLIDER_H
#define GUI_SLIDER_H
#include "gui.h"
namespace fdm
{
	namespace gui
	{
		using SliderCallback = std::add_pointer<void(void* user, int value)>::type;

		class Element;
		enum AlignmentX;
		enum AlignmentY;
		class Window;

		class Slider : public Element
		{
		public:
			static const int height = 50;
			std::string text;
			bool clickable = true;
			bool mouseDown;
			bool selected;
			PAD(1);
			int range;
			int width = 200;
			int value;
			int xOffset;
			int yOffset;
			AlignmentX xAlign;
			AlignmentY yAlign;
			void* user;
			SliderCallback callback = NULL;

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
			void deselect() override
			{
				this->mouseDown = false;
			}
			void render(Window* w) override 
			{
				reinterpret_cast<void(__thiscall*)(Slider*)>(
					base + idaOffsetFix(0x57DC0)
					)(this);
			}
			void mouseInput(const Window* w, double xPos, double yPos) override
			{
				reinterpret_cast<void(__thiscall*)(Slider*, const Window*, double, double)>(
					base + idaOffsetFix(0x584E0)
					)(this, w, xPos, yPos);
			}
			bool mouseButtonInput(const Window* w, int button, int action, int mods) override
			{
				return reinterpret_cast<bool(__thiscall*)(Slider*, const Window*, int, int, int)>(
					base + idaOffsetFix(0x58400)
					)(this, w, button, action, mods);
			}
			bool keyInput(const Window* w, int key, int scancode, int action, int mods) override
			{
				return reinterpret_cast<bool(__thiscall*)(Slider*, const Window*, int, int, int, int)>(
					base + idaOffsetFix(0x585A0)
					)(this, w, key, scancode, action, mods);
			}
			void getPos(const Window* w, int* x, int* y) override
			{
				reinterpret_cast<void(__thiscall*)(Slider*, const Window*, int*, int*)>(
					base + idaOffsetFix(0x58620)
					)(this, w, x, y);
			}
			void getSize(const Window* w, int* width, int* height) override
			{
				reinterpret_cast<void(__thiscall*)(Slider*, const Window*, int*, int*)>(
					base + idaOffsetFix(0x586D0)
					)(this, w, width, height);
			}
		};
	}
}
#endif