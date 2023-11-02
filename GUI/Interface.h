#pragma once
#include "Window.h"

#include "gui.h"

namespace fdm
{
	class QuadRenderer;
	class FontRenderer;
	namespace gui
	{
		using ViewportCallback = std::add_pointer<void(void* user, const glm::ivec4& pos, const glm::ivec2& scroll)>::type;

		class Element;
		class ElemContainer;
		class Window;

		class Interface : public gui::Window, public gui::ElemContainer
		{
		public:
			std::vector<gui::Element*> elements; // 0x10
			int selectedElemIndex; // 0x28
			PAD(0x4);
			QuadRenderer* qr; // 0x30
			FontRenderer* font; // 0x38
			GLFWwindow* window; // 0x40
			ViewportCallback viewportCallback = NULL; // 0x48
			void* viewportUser; // 0x50
			bool viewUpdateFlag; // 0x58
			PAD(0x3);
			int currentCursorType; // 0x5C
			GLFWcursor* cursor; // 0x60
			Interface() {}
			Interface(GLFWwindow* window)
			{
				reinterpret_cast<void(__thiscall*)(gui::Interface * self, GLFWwindow * window)>(FUNC_GUI_INTERFACE_INTERFACE)(this, window);
			}
			~Interface()
			{
				reinterpret_cast<void(__thiscall*)(gui::Interface * self)>(FUNC_GUI_INTERFACE_DESTR_INTERFACE)(this);
			}
			void render()
			{
				return reinterpret_cast<void(__thiscall*)(gui::Interface * self)>(FUNC_GUI_INTERFACE_RENDER)(this);
			}
			void mouseInput(double xpos, double ypos)
			{
				return reinterpret_cast<void(__thiscall*)(gui::Interface * self, double xpos, double ypos)>(FUNC_GUI_INTERFACE_MOUSEINPUT)(this, xpos, ypos);
			}
			bool scrollInput(double xoffset, double yoffset)
			{
				return reinterpret_cast<bool(__thiscall*)(gui::Interface * self, double xoffset, double yoffset)>(FUNC_GUI_INTERFACE_SCROLLINPUT)(this, xoffset, yoffset);
			}
			bool mouseButtonInput(int button, int action, int mods)
			{
				return reinterpret_cast<bool(__thiscall*)(gui::Interface * self, int button, int action, int mods)>(FUNC_GUI_INTERFACE_MOUSEBUTTONINPUT)(this, button, action, mods);
			}
			bool keyInput(int key, int scancode, int action, int mods)
			{
				return reinterpret_cast<bool(__thiscall*)(gui::Interface * self, int key, int scancode, int action, int mods)>(FUNC_GUI_INTERFACE_KEYINPUT)(this, key, scancode, action, mods);
			}
			QuadRenderer* getQuadRenderer() override
			{
				return reinterpret_cast<QuadRenderer * (__thiscall*)(gui::Interface * self)>(FUNC_GUI_INTERFACE_GETQUADRENDERER)(this);
			}
			FontRenderer* getFont() override
			{
				return reinterpret_cast<FontRenderer * (__thiscall*)(gui::Interface * self)>(FUNC_GUI_INTERFACE_GETFONT)(this);
			}
			GLFWwindow* getGLFWwindow() override
			{
				return reinterpret_cast<GLFWwindow * (__thiscall*)(gui::Interface * self)>(FUNC_GUI_INTERFACE_GETGLFWWINDOW)(this);
			}
			void getCursorPos(int* x, int* y) override
			{
				return reinterpret_cast<void(__thiscall*)(gui::Interface * self, int* x, int* y)>(FUNC_GUI_INTERFACE_GETCURSORPOS)(this, x, y);
			}
			void getSize(int* x, int* y) override
			{
				return reinterpret_cast<void(__thiscall*)(gui::Interface * self, int* x, int* y)>(FUNC_GUI_INTERFACE_GETSIZE)(this, x, y);
			}
			void changeViewport(const glm::ivec4& pos, const glm::ivec2& scroll) override
			{
				return reinterpret_cast<void(__thiscall*)(gui::Interface * self, const glm::ivec4 & pos, const glm::ivec2 & scroll)>(FUNC_GUI_INTERFACE_CHANGEVIEWPORT)(this, pos, scroll);
			}
			void addElement(gui::Element* e) override
			{
				return reinterpret_cast<void(__thiscall*)(gui::Interface * self, gui::Element * e)>(FUNC_GUI_INTERFACE_ADDELEMENT)(this, e);
			}
			bool removeElement(gui::Element* e) override
			{
				return reinterpret_cast<bool(__thiscall*)(gui::Interface * self, gui::Element * e)>(FUNC_GUI_INTERFACE_REMOVEELEMENT)(this, e);
			}
			bool selectElement(gui::Element* e) override
			{
				return reinterpret_cast<bool(__thiscall*)(gui::Interface * self, gui::Element * e)>(FUNC_GUI_INTERFACE_SELECTELEMENT)(this, e);
			}
			void clear() override
			{
				return reinterpret_cast<void(__thiscall*)(gui::Interface * self)>(FUNC_GUI_INTERFACE_CLEAR)(this);
			}
			bool empty() override
			{
				return reinterpret_cast<bool(__thiscall*)(gui::Interface * self)>(FUNC_GUI_INTERFACE_EMPTY)(this);
			}
		};
	}
}
