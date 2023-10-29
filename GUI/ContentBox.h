#pragma once

#include "4dm.h"

namespace fdm 
{
	class gui::ContentBox : public gui::Element, public gui::Window, public gui::ElemContainer 
	{
	public:
		gui::Window* parent; // 0x18
		std::vector<gui::Element *,std::allocator<gui::Element *> > elements; // 0x20
		int selectedElemIndex; // 0x38
		bool active; // 0x3C
		PAD(0x3);
		uint32_t width; // 0x40
		uint32_t height; // 0x44
		int xOffset; // 0x48
		int yOffset; // 0x4C
		gui::AlignmentX xAlign; // 0x50
		gui::AlignmentY yAlign; // 0x54
		int xScroll; // 0x58
		int yScroll; // 0x5C
		int scrollW; // 0x60
		int scrollH; // 0x64
		inline static const int scrollbarWidth = 15; 
		bool scrollingX; // 0x68
		bool scrollingY; // 0x69
		PAD(0x2);
		int scrollbarClickPos; // 0x6C
		int scrollStep; // 0x70
		bool viewUpdateFlag; // 0x74
		PAD(0x3);
		int currentCursorType; // 0x78

		void ~ContentBox() 
		{
			return reinterpret_cast<void (__thiscall*)(gui::ContentBox* self)>(FUNC_GUI_CONTENTBOX_DESTR_CONTENTBOX)(this);
		}
		QuadRenderer getQuadRenderer() override
		{
			return reinterpret_cast<QuadRenderer (__thiscall*)(gui::ContentBox* self)>(FUNC_GUI_CONTENTBOX_GETQUADRENDERER)(this);
		}
		FontRenderer getFont() override
		{
			return reinterpret_cast<FontRenderer (__thiscall*)(gui::ContentBox* self)>(FUNC_GUI_CONTENTBOX_GETFONT)(this);
		}
		GLFWwindow getGLFWwindow() override
		{
			return reinterpret_cast<GLFWwindow (__thiscall*)(gui::ContentBox* self)>(FUNC_GUI_CONTENTBOX_GETGLFWWINDOW)(this);
		}
		void getCursorPos(int* x, int* y) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::ContentBox* self, int* x, int* y)>(FUNC_GUI_CONTENTBOX_GETCURSORPOS)(this, x, y);
		}
		void getSize(int* x, int* y) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::ContentBox* self, int* x, int* y)>(FUNC_GUI_CONTENTBOX_GETSIZE)(this, x, y);
		}
		void changeViewport(const glm::ivec4& pos, const glm::ivec2& scroll) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::ContentBox* self, const glm::ivec4& pos, const glm::ivec2& scroll)>(FUNC_GUI_CONTENTBOX_CHANGEVIEWPORT)(this, pos, scroll);
		}
		void getPos(const gui::Window* w, int* x, int* y) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::ContentBox* self, const gui::Window* w, int* x, int* y)>(FUNC_GUI_CONTENTBOX_GETPOS)(this, w, x, y);
		}
		void getSize(const gui::Window* w, uint32_t* width, uint32_t* height) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::ContentBox* self, const gui::Window* w, uint32_t* width, uint32_t* height)>(FUNC_GUI_CONTENTBOX_GETSIZE_A)(this, w, width, height);
		}
		bool touchingMouse() 
		{
			return reinterpret_cast<bool (__thiscall*)(gui::ContentBox* self)>(FUNC_GUI_CONTENTBOX_TOUCHINGMOUSE)(this);
		}
		void resetViewport(bool applyScroll) 
		{
			return reinterpret_cast<void (__thiscall*)(gui::ContentBox* self, bool applyScroll)>(FUNC_GUI_CONTENTBOX_RESETVIEWPORT)(this, applyScroll);
		}
		void render(gui::Window* w) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::ContentBox* self, gui::Window* w)>(FUNC_GUI_CONTENTBOX_RENDER)(this, w);
		}
		void alignX(gui::AlignmentX a) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::ContentBox* self, gui::AlignmentX a)>(FUNC_GUI_CONTENTBOX_ALIGNX)(this, a);
		}
		void alignY(gui::AlignmentY a) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::ContentBox* self, gui::AlignmentY a)>(FUNC_GUI_CONTENTBOX_ALIGNY)(this, a);
		}
		void offsetX(int offset) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::ContentBox* self, int offset)>(FUNC_GUI_CONTENTBOX_OFFSETX)(this, offset);
		}
		void offsetY(int offset) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::ContentBox* self, int offset)>(FUNC_GUI_CONTENTBOX_OFFSETY)(this, offset);
		}
		bool mouseInput(const gui::Window* w, double xpos, double ypos) override
		{
			return reinterpret_cast<bool (__thiscall*)(gui::ContentBox* self, const gui::Window* w, double xpos, double ypos)>(FUNC_GUI_CONTENTBOX_MOUSEINPUT)(this, w, xpos, ypos);
		}
		bool scrollInput(const gui::Window* w, double xoffset, double yoffset) override
		{
			return reinterpret_cast<bool (__thiscall*)(gui::ContentBox* self, const gui::Window* w, double xoffset, double yoffset)>(FUNC_GUI_CONTENTBOX_SCROLLINPUT)(this, w, xoffset, yoffset);
		}
		bool mouseButtonInput(const gui::Window* w, uint32_t button, uint32_t action, int mods) override
		{
			return reinterpret_cast<bool (__thiscall*)(gui::ContentBox* self, const gui::Window* w, uint32_t button, uint32_t action, int mods)>(FUNC_GUI_CONTENTBOX_MOUSEBUTTONINPUT)(this, w, button, action, mods);
		}
		bool keyInput(const gui::Window* w, __int64 key, __int64 scancode, int action, int mods) override
		{
			return reinterpret_cast<bool (__thiscall*)(gui::ContentBox* self, const gui::Window* w, __int64 key, __int64 scancode, int action, int mods)>(FUNC_GUI_CONTENTBOX_KEYINPUT)(this, w, key, scancode, action, mods);
		}
		void select() override
		{
			return reinterpret_cast<void (__thiscall*)(gui::ContentBox* self)>(FUNC_GUI_CONTENTBOX_SELECT)(this);
		}
		void deselect() override
		{
			return reinterpret_cast<void (__thiscall*)(gui::ContentBox* self)>(FUNC_GUI_CONTENTBOX_DESELECT)(this);
		}
		void addElement(Chunk* e) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::ContentBox* self, Chunk* e)>(FUNC_GUI_CONTENTBOX_ADDELEMENT)(this, e);
		}
		bool removeElement(gui::Element* e) override
		{
			return reinterpret_cast<bool (__thiscall*)(gui::ContentBox* self, gui::Element* e)>(FUNC_GUI_CONTENTBOX_REMOVEELEMENT)(this, e);
		}
		bool selectElement(gui::Element* e) override
		{
			return reinterpret_cast<bool (__thiscall*)(gui::ContentBox* self, gui::Element* e)>(FUNC_GUI_CONTENTBOX_SELECTELEMENT)(this, e);
		}
		void clear() override
		{
			return reinterpret_cast<void (__thiscall*)(gui::ContentBox* self)>(FUNC_GUI_CONTENTBOX_CLEAR)(this);
		}
		bool empty() override
		{
			return reinterpret_cast<bool (__thiscall*)(gui::ContentBox* self)>(FUNC_GUI_CONTENTBOX_EMPTY)(this);
		}
	};
}
