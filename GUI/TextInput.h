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

		class TextInput : public Element
		{
		public:
			static const int maxScrollPos;
			static const float cursorBlinkTime;
			static const float lastTypedCharTime;
			std::string text = "";
			bool enabled = true;
			bool mouseDown = false;
			bool active = false;
			bool highlight = false;
			int cursorPos = 0;
			int highlightStart = 0;
			unsigned int height = 50;
			unsigned int width = 100;
			int scrollPos = 4;
			float cursorBlinkTimer = 0.0f;
			float lastTypedCharTimer = 0.0f;
			int lastTypedCharIndex = 0;
			int xOffset = 0;
			int yOffset = 0;
			enum AlignmentX xAlign = AlignmentX::ALIGN_LEFT;
			enum AlignmentY yAlign = AlignmentY::ALIGN_TOP;
			PAD(4);
			void* user = NULL;
			TextInputCallback callback = NULL;
			void select() override
			{
				this->active = true;
			}
			void render(gui::Window* w) override
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
			bool mouseButtonInput(const gui::Window* w, int button, int action, int mods) override
			{
				return reinterpret_cast<bool(__thiscall*)(TextInput*, const gui::Window*, int, int, int)>(
					base + idaOffsetFix(0x59240)
					)(this, w, button, action, mods);
			}
			void mouseInput(const gui::Window* w, double xPos, double yPos) override
			{
				reinterpret_cast<void(__thiscall*)(TextInput*, const gui::Window*, double, double)>(
					base + idaOffsetFix(0x593A0)
					)(this, w, xPos, yPos);
			}
			bool keyInput(const gui::Window* w, int key, int scancode, int action, int mods) override
			{
				return reinterpret_cast<bool(__thiscall*)(TextInput*, const gui::Window*, int, int, int, int)>(
					base + idaOffsetFix(0x59460)
					)(this, w, key, scancode, action, mods);
			}
			bool charInput(const gui::Window* w, unsigned int codepoint) override
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
			void updateScrollPos(const gui::Window* w)
			{
				reinterpret_cast<void(__thiscall*)(TextInput*, const gui::Window*)>(
					base + idaOffsetFix(0x59C60)
					)(this, w);
			}
			void getPos(const gui::Window* w, int* x, int* y) override
			{
				reinterpret_cast<void(__thiscall*)(TextInput*, const gui::Window*, int*, int*)>(
					base + idaOffsetFix(0x59CE0)
					)(this, w, x, y);
			}
			void getSize(const gui::Window* w, int* width, int* height) override
			{
				reinterpret_cast<void(__thiscall*)(TextInput*, const gui::Window*, int*, int*)>(
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
		const int TextInput::maxScrollPos = 4;
		const float TextInput::cursorBlinkTime = 1;
		const float TextInput::lastTypedCharTime = 1;
	}
}
#endif