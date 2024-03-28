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
			std::vector<gui::Element*> elements{}; // 0x10
			int selectedElemIndex; // 0x28
			PAD(0x4);
			QuadRenderer* qr; // 0x30
			FontRenderer* font; // 0x38
			GLFWwindow* window; // 0x40
			ViewportCallback viewportCallback = NULL; // 0x48
			void* viewportUser; // 0x50
			bool viewUpdateFlag; // 0x58
			PAD(0x3);
			int currentCursorType = GLFW_ARROW_CURSOR; // 0x5C
			GLFWcursor* cursor; // 0x60
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
			Interface(GLFWwindow* window = nullptr)
			{
				selectedElemIndex = -1;
				currentCursorType = GLFW_ARROW_CURSOR;
				elements.clear();
				qr = nullptr;
				font = nullptr;
				this->window = window;
				viewportCallback = nullptr;
				viewportUser = nullptr;
				viewUpdateFlag = false;
				cursor = glfwCreateStandardCursor(currentCursorType);
			}
			~Interface()
			{
				glfwDestroyCursor(this->cursor);

				if (!this->elements.empty())
				{
					for (auto it = this->elements.begin(); it != this->elements.end(); ++it)
					{
						delete* it;
					}

					this->elements.clear();
				}
			}
			void render()
			{
				if (!elements.empty())
				{
					for (int i = 0; i < elements.size(); i++)
					{
						elements[i]->render(this);

						if (viewUpdateFlag)
						{
							int width, height;
							glfwGetWindowSize(window, &width, &height);

							if (width > 0 && height > 0)
								changeViewport({ 0, 0, width, height }, { 0, 0 });

							viewUpdateFlag = false;
						}
					}
				}
			}
			void mouseInput(double xpos, double ypos)
			{
				if (elements.empty()) return;
				return reinterpret_cast<void(__thiscall*)(gui::Interface * self, double xpos, double ypos)>(getFuncAddr((int)Func::gui_Nested::Interface::mouseInput))(this, xpos, ypos);
			}
			bool scrollInput(double xoffset, double yoffset)
			{
				return reinterpret_cast<bool(__thiscall*)(gui::Interface * self, double xoffset, double yoffset)>(getFuncAddr((int)Func::gui_Nested::Interface::scrollInput))(this, xoffset, yoffset);
			}
			bool mouseButtonInput(int button, int action, int mods)
			{
				if (elements.empty()) return false;
				return reinterpret_cast<bool(__thiscall*)(gui::Interface * self, int button, int action, int mods)>(getFuncAddr((int)Func::gui_Nested::Interface::mouseButtonInput))(this, button, action, mods);
			}
			bool keyInput(int key, int scancode, int action, int mods)
			{
				return reinterpret_cast<bool(__thiscall*)(gui::Interface * self, int key, int scancode, int action, int mods)>(getFuncAddr((int)Func::gui_Nested::Interface::keyInput))(this, key, scancode, action, mods);
			}
			QuadRenderer* getQuadRenderer() const override
			{
				return reinterpret_cast<QuadRenderer * (__thiscall*)(const gui::Interface * self)>(getFuncAddr((int)Func::gui_Nested::Interface::getQuadRenderer))(this);
			}
			FontRenderer* getFont() const override
			{
				return reinterpret_cast<FontRenderer * (__thiscall*)(const gui::Interface * self)>(getFuncAddr((int)Func::gui_Nested::Interface::getFont))(this);
			}
			GLFWwindow* getGLFWwindow() const override
			{
				return reinterpret_cast<GLFWwindow * (__thiscall*)(const gui::Interface * self)>(getFuncAddr((int)Func::gui_Nested::Interface::getGLFWwindow))(this);
			}
			void getCursorPos(int* x, int* y) const override
			{
				double xd, yd;
				glfwGetCursorPos(window, &xd, &yd);
				*x = xd;
				*y = yd;
			}
			void getSize(int* x, int* y) const override
			{
				glfwGetWindowSize(window, x, y);
			}
			void changeViewport(const glm::ivec4& pos, const glm::ivec2& scroll) override
			{
				if (viewportCallback)
				{
					viewUpdateFlag = true;
					viewportCallback(viewportUser, pos, scroll);
				}
			}
			void addElement(gui::Element* e) override
			{
				elements.push_back(e);
			}
			bool removeElement(gui::Element* e) override
			{
				return elements.erase(std::remove(elements.begin(), elements.end(), e), elements.end()) != elements.end();
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
				elements.clear();
				changeSelection(-1);
			}
			bool empty() override
			{
				return elements.empty();
			}
			bool charInput(uint32_t codepoint)
			{
				if (!empty() && selectedElemIndex != -1)
					return elements[selectedElemIndex]->charInput(this, codepoint);
				return false;
			}
		};
	}
}
