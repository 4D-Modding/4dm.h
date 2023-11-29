#pragma once

#include "gui.h"

namespace fdm
{
	class QuadRenderer;
	class FontRenderer;
	namespace gui
	{
		enum AlignmentX;
		enum AlignmentY;

		class Window;
		class ElemContainer;
		class Element;

		class ContentBox : public gui::Element, public gui::Window, public gui::ElemContainer
		{
		public:
			gui::Window* parent = nullptr; // 0x18
			std::vector<gui::Element*> elements{}; // 0x20
			int selectedElemIndex = -1; // 0x38
			bool active = false; // 0x3C
			PAD(0x3);
			uint32_t width = 100; // 0x40
			uint32_t height = 100; // 0x44
			int xOffset = 0; // 0x48
			int yOffset = 0; // 0x4C
			gui::AlignmentX xAlign = AlignmentX::ALIGN_LEFT; // 0x50
			gui::AlignmentY yAlign = AlignmentY::ALIGN_TOP; // 0x54
			int xScroll = 0; // 0x58
			int yScroll = 0; // 0x5C
			int scrollW = 0; // 0x60
			int scrollH = 0; // 0x64
			inline static const int scrollbarWidth = 15;
			bool scrollingX = false; // 0x68
			bool scrollingY = false; // 0x69
			PAD(0x2);
			int scrollbarClickPos = 0; // 0x6C
			int scrollStep = 20; // 0x70
			bool viewUpdateFlag = false; // 0x74
			PAD(0x3);
			int currentCursorType = GLFW_ARROW_CURSOR; // 0x78

			void changeSelection(int index)
			{
				// don't deselect if it's already selected
				if (selectedElemIndex != -1 && selectedElemIndex != index)
				{
					elements[selectedElemIndex]->deselect();
				}
				selectedElemIndex = index;
				if (index != -1)
				{
					elements[index]->select();
				}
			}
			~ContentBox()
			{
				reinterpret_cast<void(__thiscall*)(gui::ContentBox * self)>(FUNC_GUI_CONTENTBOX_DESTR_CONTENTBOX)(this);
			}
			QuadRenderer* getQuadRenderer() override
			{
				return parent->getQuadRenderer();
			}
			FontRenderer* getFont() override
			{
				return parent->getFont();
			}
			GLFWwindow* getGLFWwindow() override
			{
				return parent->getGLFWwindow();
			}
			void getCursorPos(int* x, int* y) override
			{
				int startX, startY;
				getPos(parent, &startX, &startY);
				parent->getCursorPos(x, y);
				*x -= xScroll + startX;
				*y -= xScroll + startY;
			}
			void getSize(int* x, int* y) override
			{
				*x = width;
				*y = height;
			}
			void changeViewport(const glm::ivec4& pos, const glm::ivec2& scroll) override
			{
				// update the viewport relative to this container
				int xStart, yStart;
				getPos(parent, &xStart, &yStart);

				glm::ivec4 adjustedPos;

				adjustedPos.x = glm::max(0, glm::min((int)width, pos.x + xScroll));
				adjustedPos.y = glm::max(0, glm::min((int)height, pos.y + yScroll));

				adjustedPos.z = glm::max(0, glm::min((int)width, pos.x + pos.z + xScroll));
				adjustedPos.z -= adjustedPos.x;

				adjustedPos.w = glm::max(0, glm::min((int)height, pos.y + pos.w + yScroll));
				adjustedPos.w -= adjustedPos.y;

				glm::ivec2 adjustedScroll{ scroll.x + pos.x + xScroll - adjustedPos.x, scroll.y + pos.y + yScroll - adjustedPos.y };

				adjustedPos.x += xStart;
				adjustedPos.y += yStart;

				parent->changeViewport(
					adjustedPos,
					adjustedScroll
				);
				viewUpdateFlag = true;
			}
			void getPos(gui::Window* w, int* x, int* y) override
			{
				return reinterpret_cast<void(__thiscall*)(gui::ContentBox * self, gui::Window * w, int* x, int* y)>(FUNC_GUI_CONTENTBOX_GETPOS)(this, w, x, y);
			}
			void getSize(gui::Window* w, int* width, int* height) override
			{
				return reinterpret_cast<void(__thiscall*)(gui::ContentBox * self, gui::Window * w, int* width, int* height)>(FUNC_GUI_CONTENTBOX_GETSIZE_A)(this, w, width, height);
			}
			bool touchingMouse()
			{
				return reinterpret_cast<bool(__thiscall*)(gui::ContentBox * self)>(FUNC_GUI_CONTENTBOX_TOUCHINGMOUSE)(this);
			}
			void resetViewport(bool applyScroll)
			{
				return reinterpret_cast<void(__thiscall*)(gui::ContentBox * self, bool applyScroll)>(FUNC_GUI_CONTENTBOX_RESETVIEWPORT)(this, applyScroll);
			}
			void render(gui::Window* w) override
			{
				return reinterpret_cast<void(__thiscall*)(gui::ContentBox * self, gui::Window * w)>(FUNC_GUI_CONTENTBOX_RENDER)(this, w);
			}
			void offsetX(int offset) override
			{
				this->xOffset = offset;
			}
			void offsetY(int offset) override
			{
				this->yOffset = offset;
			}
			void alignX(gui::AlignmentX a)
			{
				this->xAlign = a;
			}
			void alignY(gui::AlignmentY a)
			{
				this->yAlign = a;
			}
			bool mouseInput(gui::Window* w, double xpos, double ypos) override
			{
				return reinterpret_cast<bool(__thiscall*)(gui::ContentBox * self, gui::Window * w, double xpos, double ypos)>(FUNC_GUI_CONTENTBOX_MOUSEINPUT)(this, w, xpos, ypos);
			}
			bool scrollInput(gui::Window* w, double xoffset, double yoffset) override
			{
				return reinterpret_cast<bool(__thiscall*)(gui::ContentBox * self, gui::Window * w, double xoffset, double yoffset)>(FUNC_GUI_CONTENTBOX_SCROLLINPUT)(this, w, xoffset, yoffset);
			}
			bool mouseButtonInput(gui::Window* w, int button, int action, int mods) override
			{
				return reinterpret_cast<bool(__thiscall*)(gui::ContentBox * self, gui::Window * w, int button, int action, int mods)>(FUNC_GUI_CONTENTBOX_MOUSEBUTTONINPUT)(this, w, button, action, mods);
			}
			bool keyInput(gui::Window* w, int key, int scancode, int action, int mods) override
			{
				return reinterpret_cast<bool(__thiscall*)(gui::ContentBox * self, gui::Window * w, int key, int scancode, int action, int mods)>(FUNC_GUI_CONTENTBOX_KEYINPUT)(this, w, key, scancode, action, mods);
			}
			void select() override
			{
				return reinterpret_cast<void(__thiscall*)(gui::ContentBox * self)>(FUNC_GUI_CONTENTBOX_SELECT)(this);
			}
			void deselect() override
			{
				return reinterpret_cast<void(__thiscall*)(gui::ContentBox * self)>(FUNC_GUI_CONTENTBOX_DESELECT)(this);
			}
			void addElement(gui::Element* e) override
			{
				elements.push_back(e);
			}
			bool removeElement(gui::Element* e) override
			{
				return std::erase(elements,e);
			}
			bool selectElement(gui::Element* e) override
			{
				if (e == nullptr)
				{
					changeSelection(-1);
					return false;
				}

				for (int i = 0; i < elements.size(); ++i)
				{
					if (elements[i] == e)
					{
						changeSelection(i);
						return true;
					}
				}

				return false;
			}
			void clear() override
			{
				changeSelection(-1);
				elements.clear();
			}
			bool empty() override
			{
				return elements.empty();
			}
		};
	}
}
