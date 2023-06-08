#pragma once
#ifndef GUI_INTERFACE_H
#define GUI_INTERFACE_H
#include "gui.h"
#include "../Shader.h"
#include "../ShaderManager.h"
namespace fdm
{
	class QuadRenderer;
	class FontRenderer;
	namespace gui
	{
		using ViewportCallback = std::add_pointer<void(void* user, const glm::ivec4& pos, const glm::ivec2& scroll)>::type;

		class Window;
		class ElemContainer;
		class Element;

		class Interface : public Window, public ElemContainer
		{
		public:
			std::vector<Element*> elements;
			int selectedElemIndex;
			PAD(4);
			QuadRenderer* qr;
			FontRenderer* font;
			GLFWwindow* window;
			ViewportCallback viewportCallback = NULL;
			void* viewportUser;
			bool viewUpdateFlag;

			~Interface()
			{
				reinterpret_cast<void(__thiscall*)(Interface*)>(
					FUNC_GUI_INTERFACE_DINTERFACE
					)(this);
			}
			void render()
			{
				reinterpret_cast<void(__thiscall*)(Interface*)>(
					FUNC_GUI_INTERFACE_RENDER
					)(this);
			}
			void mouseInput(double xPos, double yPos)
			{
				reinterpret_cast<void(__thiscall*)(Interface*, double, double)>(
					FUNC_GUI_INTERFACE_MOUSEINPUT
					)(this, xPos, yPos);
			}
			bool scrollInput(double xOff, double yOff)
			{
				return reinterpret_cast<bool(__thiscall*)(Interface*, double, double)>(
					FUNC_GUI_INTERFACE_SCROLLINPUT
					)(this, xOff, yOff);
			}
			bool mouseButtonInput(int button, int action, int mods)
			{
				return reinterpret_cast<bool(__thiscall*)(Interface*, int, int, int)>(
					FUNC_GUI_INTERFACE_MOUSEBUTTONINPUT
					)(this, button, action, mods);
			}
			bool keyInput(int key, int scancode, int action, int mods)
			{
				return reinterpret_cast<bool(__thiscall*)(Interface*, int, int, int, int)>(
					FUNC_GUI_INTERFACE_KEYINPUT
					)(this, key, scancode, action, mods);
			}
			QuadRenderer* getQuadRenderer() override
			{
				return reinterpret_cast<QuadRenderer * (__thiscall*)(Interface*)>(
					FUNC_GUI_INTERFACE_GETQUADRENDERER
					)(this);
			}
			FontRenderer* getFont() override
			{
				return reinterpret_cast<FontRenderer * (__thiscall*)(Interface*)>(
					FUNC_GUI_INTERFACE_GETFONT
					)(this);
			}
			GLFWwindow* getGLFWwindow() override
			{
				return reinterpret_cast<GLFWwindow * (__thiscall*)(Interface*)>(
					FUNC_GUI_INTERFACE_GETGLFWWINDOW
					)(this);
			}
			void getCursorPos(int* x, int* y) override
			{
				reinterpret_cast<void(__thiscall*)(Interface*, int*, int*)>(
					FUNC_GUI_INTERFACE_GETCURSORPOS
					)(this, x, y);
			}
			void getSize(int* w, int* h) override
			{
				reinterpret_cast<void(__thiscall*)(Interface*, int*, int*)>(
					FUNC_GUI_INTERFACE_GETSIZE
					)(this, w, h);
			}
			void changeViewport(const glm::ivec4& pos, const glm::ivec2& scroll) override
			{
				reinterpret_cast<void(__thiscall*)(Interface*, const glm::ivec4&, const glm::ivec2&)>(
					FUNC_GUI_INTERFACE_CHANGEVIEWPORT
					)(this, pos, scroll);
			}
			void addElement(Element* e) override
			{
				elements.push_back(e);
			}
			bool removeElement(Element* e) override
			{
				return reinterpret_cast<bool(__thiscall*)(Interface*, Element*)> (
					FUNC_GUI_INTERFACE_REMOVEELEMENT
					)(this, e);
			}
			bool selectElement(Element* e) override
			{
				return reinterpret_cast<bool(__thiscall*)(Interface*, Element*)> (
					FUNC_GUI_INTERFACE_SELECTELEMENT
					)(this, e);
			}
			void clear() override
			{
				elements.clear();
			}
			bool empty() override
			{
				return elements.empty();
			}
		};
	}
}
#endif
