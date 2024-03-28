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
		uint32_t width = 100; // 0x58
		uint32_t height = 50; // 0x5C
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
			return reinterpret_cast<void (__thiscall*)(gui::TextInput* self, gui::Window* w)>(getFuncAddr((int)Func::gui_Nested::TextInput::render))(this, w);
		}
		void alignX(gui::AlignmentX a) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::TextInput* self, gui::AlignmentX a)>(getFuncAddr((int)Func::gui_Nested::TextInput::alignX))(this, a);
		}
		void alignY(gui::AlignmentY a) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::TextInput* self, gui::AlignmentY a)>(getFuncAddr((int)Func::gui_Nested::TextInput::alignY))(this, a);
		}
		void offsetX(int offset) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::TextInput* self, int offset)>(getFuncAddr((int)Func::gui_Nested::TextInput::offsetX))(this, offset);
		}
		void offsetY(int offset) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::TextInput* self, int offset)>(getFuncAddr((int)Func::gui_Nested::TextInput::offsetY))(this, offset);
		}
		bool mouseButtonInput(const gui::Window* w, int button, int action, int mods) override
		{
			return reinterpret_cast<bool (__thiscall*)(gui::TextInput* self, const gui::Window* w, int button, int action, int mods)>(getFuncAddr((int)Func::gui_Nested::TextInput::mouseButtonInput))(this, w, button, action, mods);
		}
		bool mouseInput(const gui::Window* w, double xpos, double ypos) override
		{
			return reinterpret_cast<bool (__thiscall*)(gui::TextInput* self, const gui::Window* w, double xpos, double ypos)>(getFuncAddr((int)Func::gui_Nested::TextInput::mouseInput))(this, w, xpos, ypos);
		}
		bool keyInput(const gui::Window* w, int key, int scancode, int action, int mods) override
		{
			return reinterpret_cast<bool (__thiscall*)(gui::TextInput* self, const gui::Window* w, int key, int scancode, int action, char mods)>(getFuncAddr((int)Func::gui_Nested::TextInput::keyInput))(this, w, key, scancode, action, mods);
		}
		bool charInput(const gui::Window* w, uint32_t codepoint) override
		{
			return reinterpret_cast<bool (__thiscall*)(gui::TextInput* self, const gui::Window* w, uint32_t codepoint)>(getFuncAddr((int)Func::gui_Nested::TextInput::charInput))(this, w, codepoint);
		}
		int getCursorType() override
		{
			return reinterpret_cast<int (__thiscall*)(gui::TextInput* self)>(getFuncAddr((int)Func::gui_Nested::TextInput::getCursorType))(this);
		}
		void select() override
		{
			return reinterpret_cast<void (__thiscall*)(gui::TextInput* self)>(getFuncAddr((int)Func::gui_Nested::TextInput::select))(this);
		}
		void deselect() override
		{
			return reinterpret_cast<void (__thiscall*)(gui::TextInput* self)>(getFuncAddr((int)Func::gui_Nested::TextInput::deselect))(this);
		}
		void updatePasswordVisualText() 
		{
			return reinterpret_cast<void (__thiscall*)(gui::TextInput* self)>(getFuncAddr((int)Func::gui_Nested::TextInput::updatePasswordVisualText))(this);
		}
		void updateScrollPos(const gui::Window* w)
		{
			return reinterpret_cast<void (__thiscall*)(gui::TextInput* self, const gui::Window* w)>(getFuncAddr((int)Func::gui_Nested::TextInput::updateScrollPos))(this, w);
		}
		void getPos(const gui::Window* w, int* x, int* y) const override
		{
			return reinterpret_cast<void (__thiscall*)(const gui::TextInput* self, const gui::Window* w, int* x, int* y)>(getFuncAddr((int)Func::gui_Nested::TextInput::getPos))(this, w, x, y);
		} 
		void getSize(const gui::Window* w, int* width, int* height) const override
		{
			return reinterpret_cast<void (__thiscall*)(const gui::TextInput* self, const gui::Window* w, int* width, int* height)>(getFuncAddr((int)Func::gui_Nested::TextInput::getSize))(this, w, width, height);
		}
		std::string removeInvalidChars(const char* str) 
		{
			std::string result;
			reinterpret_cast<std::string& (__thiscall*)(gui::TextInput* self, std::string* result, const char* str)>(getFuncAddr((int)Func::gui_Nested::TextInput::removeInvalidChars))(this, &result, str);
			return result;
		}
		void removeHighlightedText() 
		{
			return reinterpret_cast<void (__thiscall*)(gui::TextInput* self)>(getFuncAddr((int)Func::gui_Nested::TextInput::removeHighlightedText))(this);
		}
	};
}
