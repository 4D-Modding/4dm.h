#pragma once
#ifndef GUI_TEXTINPUT_H
#define GUI_TEXTINPUT_H
#include "gui.h"
namespace fdm
{
	namespace gui
	{
		using TextInputCallback = std::add_pointer<void(void* user, std::string& text)>::type;
		class Element;
		enum AlignmentX;
		enum AlignmentY;
		class Window;

		class TextInput : public Element
		{
		public:
			static const int maxScrollPos;
			static const float cursorBlinkTime;
			static const float lastTypedCharTime;
			std::string text = "";
			bool enabled = true;
			bool mouseDown;
			bool active;
			bool highlight = false;
			int cursorPos = 0;
			int highlightStart;
			unsigned int height = 50;
			unsigned int width = 300;
			int scrollPos = 4;
			float cursorBlinkTimer;
			float lastTypedCharTimer = 0.0f;
			int lastTypedCharIndex;
			int xOffset;
			int yOffset;
			enum AlignmentX xAlign;
			enum AlignmentY yAlign;
			PAD(4);
			void* user;
			TextInputCallback callback = NULL;
			void select() override
			{
				this->active = true;
			}
			void render(Window* w) override
			{
				reinterpret_cast<void(__thiscall*)(TextInput*, gui::Window*)>(
					base + idaOffsetFix(0x586E0)
					)(this, w);
			}
			void alignX(AlignmentX a) override
			{
				this->xAlign = a;
			}
			void alignY(AlignmentY a) override
			{
				this->yAlign = a;
			}
			void offsetX(int offset) override
			{
				this->xOffset = offset;
			}
			void offsetY(int offset) override
			{
				this->yOffset = offset;
			}
			bool mouseButtonInput(const Window* w, int button, int action, int mods) override
			{
				return reinterpret_cast<bool(__thiscall*)(TextInput*, const gui::Window*, int, int, int)>(
					base + idaOffsetFix(0x59240)
					)(this, w, button, action, mods);
			}
			void mouseInput(const Window* w, double xPos, double yPos) override
			{
				reinterpret_cast<void(__thiscall*)(TextInput*, const gui::Window*, double, double)>(
					base + idaOffsetFix(0x593A0)
					)(this, w, xPos, yPos);
			}
			bool keyInput(const Window* w, int key, int scancode, int action, int mods) override 
			{
				return reinterpret_cast<bool(__thiscall*)(TextInput*, const gui::Window*, int, int, int, int)>(
					base + idaOffsetFix(0x59460)
					)(this, w, key, scancode, action, mods);
			}
			bool charInput(const Window* w, unsigned int codepoint) override
			{
				return reinterpret_cast<bool(__thiscall*)(TextInput*, const gui::Window*, unsigned int)>(
					base + idaOffsetFix(0x59B50)
					)(this, w, codepoint);
			}
			void deselect() override 
			{
				this->highlightStart = this->cursorPos;
				this->active = false;
			}
			void updateScrollPos(const Window* w)
			{
				reinterpret_cast<void(__thiscall*)(TextInput*, const gui::Window*)>(
					base + idaOffsetFix(0x59C60)
					)(this, w);
			}
			void getPos(const Window* w, int* x, int* y) override
			{
				reinterpret_cast<void(__thiscall*)(TextInput*, const Window*, int*, int*)>(
					base + idaOffsetFix(0x59CE0)
					)(this, w, x, y);
			}
			void getSize(const Window* w, int* width, int* height) override
			{
				reinterpret_cast<void(__thiscall*)(TextInput*, const Window*, int*, int*)>(
					base + idaOffsetFix(0x59DA0)
					)(this, w, width, height);
			}
			void removedHighlightedText() 
			{
				reinterpret_cast<void(__thiscall*)(TextInput*)>(
					base + idaOffsetFix(0x59DB0)
					)(this);
			}
		};
	}
}
#endif