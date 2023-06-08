#pragma once
#ifndef GUI_CONTENTBOX_H
#define GUI_CONTENTBOX_H
#include "gui.h"
namespace fdm
{
	class QuadRenderer;
	class FontRenderer;
	namespace gui
	{
		class Element;
		class Window;
		class ElemContainer;
		enum AlignmentX;
		enum AlignmentY;
		
		class ContentBox : public Element, public Window, public ElemContainer 
		{
		public:
			inline static const int scrollbarWidth = 20;
			gui::Window* parent;
			std::vector<gui::Element*> elements;
			int selectedElemIndex;
			bool active;
			PAD(3);
			unsigned int width;
			unsigned int height;
			int xOffset;
			int yOffset;
			AlignmentX xAlign;
			AlignmentY yAlign;
			int xScroll;
			int yScroll;
			unsigned int scrollW = 0;
			unsigned int scrollH = 0;
			bool scrollingX;
			bool scrollingY;
			PAD(2);
			int scrollbarClickPos;
			int scrollStep;
			bool viewUpdateFlag;

			~ContentBox()
			{
				reinterpret_cast<void(__thiscall*)(gui::ContentBox*)>(
					FUNC_GUI_CONTENTBOX_DCONTENTBOX
					)(this);
			}
			void offsetY(int offset) override
			{
				this->yOffset = offset;
			}
			QuadRenderer* getQuadRenderer() override 
			{
				return reinterpret_cast<QuadRenderer* (__thiscall*)(gui::ContentBox*)>(
					FUNC_GUI_CONTENTBOX_GETQUADRENDERER
					)(this);
			}
			FontRenderer* getFont() override
			{
				return reinterpret_cast<FontRenderer* (__thiscall*)(gui::ContentBox*)>(
					FUNC_GUI_CONTENTBOX_GETFONT
					)(this);
			}
			GLFWwindow* getGLFWwindow() override
			{
				return reinterpret_cast<GLFWwindow* (__thiscall*)(gui::ContentBox*)>(
					FUNC_GUI_CONTENTBOX_GETGLFWWINDOW
					)(this);
			}
			void getCursorPos(int* x, int* y) override
			{
				reinterpret_cast<void(__thiscall*)(gui::ContentBox*, int*, int*)>(
					FUNC_GUI_CONTENTBOX_GETCURSORPOS
					)(this, x, y);
			}
			void getSize(int* width, int* height) override
			{
				reinterpret_cast<void(__thiscall*)(gui::ContentBox*, int*, int*)>(
					FUNC_GUI_CONTENTBOX_GETSIZE
					)(this, width, height);
			}
			void changeViewport(const glm::ivec4& pos, const glm::ivec2& scroll) override
			{
				reinterpret_cast<void(__thiscall*)(gui::ContentBox*, const glm::ivec4&, const glm::ivec2&)>(
					FUNC_GUI_CONTENTBOX_CHANGEVIEWPORT
					)(this, pos, scroll);
			}
			void getPos(const gui::Window* w, int* x, int* y) override
			{
				reinterpret_cast<void(__thiscall*)(gui::ContentBox*, const gui::Window*, int*, int*)>(
					FUNC_GUI_CONTENTBOX_GETPOS
					)(this, w, x, y);
			}
			void getSize(const gui::Window* w, int* width, int* height) override
			{
				reinterpret_cast<void(__thiscall*)(gui::ContentBox*, const gui::Window*, int*, int*)>(
					FUNC_GUI_CONTENTBOX_GETSIZE
					)(this, w, width, height);
			}
			bool touchingMouse() 
			{
				return reinterpret_cast<bool(__thiscall*)(gui::ContentBox*)>(
					FUNC_GUI_CONTENTBOX_TOUCHINGMOUSE
					)(this);
			}
			void resetViewport(bool applyScroll)
			{
				reinterpret_cast<void(__thiscall*)(gui::ContentBox*, bool)>(
					FUNC_GUI_CONTENTBOX_RESETVIEWPORT
					)(this, applyScroll);
			}
			void render(gui::Window* w) override
			{
				reinterpret_cast<void(__thiscall*)(gui::ContentBox*, gui::Window*)>(
					FUNC_GUI_CONTENTBOX_RENDER
					)(this, w);
			}
			void mouseInput(const gui::Window* w, double xPos, double yPos) override
			{
				reinterpret_cast<void(__thiscall*)(gui::ContentBox*, const gui::Window*, double, double)>(
					FUNC_GUI_CONTENTBOX_MOUSEINPUT
					)(this, w, xPos, yPos);
			}
			bool scrollInput(const gui::Window* w, double xOff, double yOff) override
			{
				return reinterpret_cast<bool(__thiscall*)(gui::ContentBox*, const gui::Window*, double, double)>(
					FUNC_GUI_CONTENTBOX_SCROLLINPUT
					)(this, w, xOff, yOff);
			}
			bool mouseButtonInput(const gui::Window* w, int button, int action, int mods) override
			{
				return reinterpret_cast<bool(__thiscall*)(gui::ContentBox*, const gui::Window*, int, int, int)>(
					FUNC_GUI_CONTENTBOX_MOUSEBUTTONINPUT
					)(this, w, button, action, mods);
			}
			bool keyInput(const gui::Window* w, int key, int scancode, int action, int mods) override
			{
				return reinterpret_cast<bool(__thiscall*)(gui::ContentBox*, const gui::Window*, int, int, int, int)>(
					FUNC_GUI_CONTENTBOX_KEYINPUT
					)(this, w, key, scancode, action, mods);
			}
			void select() override
			{
				reinterpret_cast<void(__thiscall*)(gui::ContentBox*)>(
					FUNC_GUI_CONTENTBOX_SELECT
					)(this);
			}
			void deselect() override
			{
				reinterpret_cast<void(__thiscall*)(gui::ContentBox*)>(
					FUNC_GUI_CONTENTBOX_DESELECT
					)(this);
			}
			void addElement(gui::Element* e) override
			{
				elements.push_back(e);
			}
			bool removeElement(gui::Element* e) override
			{
				return reinterpret_cast<bool(__thiscall*)(gui::ContentBox*, gui::Element*)> (
					FUNC_GUI_CONTENTBOX_REMOVEELEMENT
					)(this, e);
			}
			bool selectElement(gui::Element* e) override
			{
				return reinterpret_cast<bool(__thiscall*)(gui::ContentBox*, gui::Element*)> (
					FUNC_GUI_CONTENTBOX_SELECTELEMENT
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
		};

	}
}
#endif