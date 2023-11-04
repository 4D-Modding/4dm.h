#pragma once

#include "gui.h"

namespace fdm::gui
{
	using TextInputCallback = std::add_pointer<void(void* user, std::string& text)>::type;
	class TextInput : public gui::Element 
	{
	public:
		std::string text; // 0x8
		bool enabled = true; // 0x28
		bool editable = true; // 0x29
		bool mouseDown; // 0x2A
		bool active; // 0x2B
		bool highlight; // 0x2C
		bool passwordMode; // 0x2D
		PAD(0x2);
		std::string passwordVisualText; // 0x30
		int cursorPos; // 0x50
		int highlightStart; // 0x54
		uint32_t width; // 0x58
		uint32_t height; // 0x5C
		inline static const int maxScrollPos = 4; 
		int scrollPos; // 0x60
		inline static const float cursorBlinkTime = 0.5f; 
		float cursorBlinkTimer; // 0x64
		inline static const float lastTypedCharTime = 0.2f; 
		float lastTypedCharTimer; // 0x68
		int lastTypedCharIndex; // 0x6C
		int xOffset; // 0x70
		int yOffset; // 0x74
		gui::AlignmentX xAlign; // 0x78
		gui::AlignmentY yAlign; // 0x7C
		void* user; // 0x80
		TextInputCallback callback = NULL; // 0x88

		void render(gui::Window* w) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::TextInput* self, gui::Window* w)>(FUNC_GUI_TEXTINPUT_RENDER)(this, w);
		}
		void alignX(gui::AlignmentX a) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::TextInput* self, gui::AlignmentX a)>(FUNC_GUI_TEXTINPUT_ALIGNX)(this, a);
		}
		void alignY(gui::AlignmentY a) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::TextInput* self, gui::AlignmentY a)>(FUNC_GUI_TEXTINPUT_ALIGNY)(this, a);
		}
		void offsetX(int offset) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::TextInput* self, int offset)>(FUNC_GUI_TEXTINPUT_OFFSETX)(this, offset);
		}
		void offsetY(int offset) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::TextInput* self, int offset)>(FUNC_GUI_TEXTINPUT_OFFSETY)(this, offset);
		}
		bool mouseButtonInput(gui::Window* w, int button, int action, int mods) override
		{
			return reinterpret_cast<bool (__thiscall*)(gui::TextInput* self, gui::Window* w, int button, int action, int mods)>(FUNC_GUI_TEXTINPUT_MOUSEBUTTONINPUT)(this, w, button, action, mods);
		}
		bool mouseInput(gui::Window* w, double xpos, double ypos) override
		{
			return reinterpret_cast<bool (__thiscall*)(gui::TextInput* self, gui::Window* w, double xpos, double ypos)>(FUNC_GUI_TEXTINPUT_MOUSEINPUT)(this, w, xpos, ypos);
		}
		bool keyInput(gui::Window* w, int key, int scancode, int action, int mods) override
		{
			return reinterpret_cast<bool (__thiscall*)(gui::TextInput* self, gui::Window* w, int key, int scancode, int action, char mods)>(FUNC_GUI_TEXTINPUT_KEYINPUT)(this, w, key, scancode, action, mods);
		}
		bool charInput(gui::Window* w, uint32_t codepoint) override
		{
			return reinterpret_cast<bool (__thiscall*)(gui::TextInput* self, gui::Window* w, uint32_t codepoint)>(FUNC_GUI_TEXTINPUT_CHARINPUT)(this, w, codepoint);
		}
		int getCursorType() override
		{
			return reinterpret_cast<int (__thiscall*)(gui::TextInput* self)>(FUNC_GUI_TEXTINPUT_GETCURSORTYPE)(this);
		}
		void select() override
		{
			return reinterpret_cast<void (__thiscall*)(gui::TextInput* self)>(FUNC_GUI_TEXTINPUT_SELECT)(this);
		}
		void deselect() override
		{
			return reinterpret_cast<void (__thiscall*)(gui::TextInput* self)>(FUNC_GUI_TEXTINPUT_DESELECT)(this);
		}
		void updatePasswordVisualText() 
		{
			return reinterpret_cast<void (__thiscall*)(gui::TextInput* self)>(FUNC_GUI_TEXTINPUT_UPDATEPASSWORDVISUALTEXT)(this);
		}
		void updateScrollPos(gui::Window* w) 
		{
			return reinterpret_cast<void (__thiscall*)(gui::TextInput* self, gui::Window* w)>(FUNC_GUI_TEXTINPUT_UPDATESCROLLPOS)(this, w);
		}
		void getPos(gui::Window* w, int* x, int* y) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::TextInput* self, gui::Window* w, int* x, int* y)>(FUNC_GUI_TEXTINPUT_GETPOS)(this, w, x, y);
		}
		void getSize(gui::Window* w, int* width, int* height) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::TextInput* self, gui::Window* w, int* width, int* height)>(FUNC_GUI_TEXTINPUT_GETSIZE)(this, w, width, height);
		}
		std::string removeInvalidChars(const char* str) 
		{
			std::string result;
			reinterpret_cast<std::string (__thiscall*)(gui::TextInput* self, std::string* result, const char* str)>(FUNC_GUI_TEXTINPUT_REMOVEINVALIDCHARS)(this, &result, str);
			return result;
		}
		void removeHighlightedText() 
		{
			return reinterpret_cast<void (__thiscall*)(gui::TextInput* self)>(FUNC_GUI_TEXTINPUT_REMOVEHIGHLIGHTEDTEXT)(this);
		}
	};
}
