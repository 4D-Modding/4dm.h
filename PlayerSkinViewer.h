#pragma once

#include "4dm.h"
#include "Framebuffer.h"
#include "GUI/Element.h"

namespace fdm 
{
	class PlayerSkinViewer : public gui::Element 
	{
	public:
		uint32_t width; // 0x8
		uint32_t height; // 0xC
		int xOffset; // 0x10
		int yOffset; // 0x14
		gui::AlignmentX xAlign; // 0x18
		gui::AlignmentY yAlign; // 0x1C
		Framebuffer renderFramebuffer; // 0x20
		PlayerSkinRenderer* skinRenderer; // 0x70

		void render(gui::Window* w) override
		{
			return reinterpret_cast<void (__thiscall*)(PlayerSkinViewer* self, gui::Window* w)>(FUNC_PLAYERSKINVIEWER_RENDER)(this, w);
		}
		void alignX(gui::AlignmentX a) override
		{
			return reinterpret_cast<void (__thiscall*)(PlayerSkinViewer* self, gui::AlignmentX a)>(FUNC_PLAYERSKINVIEWER_ALIGNX)(this, a);
		}
		void alignY(gui::AlignmentY a) override
		{
			return reinterpret_cast<void (__thiscall*)(PlayerSkinViewer* self, gui::AlignmentY a)>(FUNC_PLAYERSKINVIEWER_ALIGNY)(this, a);
		}
		void getPos(gui::Window* w, int* x, int* y) override
		{
			return reinterpret_cast<void (__thiscall*)(PlayerSkinViewer* self, gui::Window* w, int* x, int* y)>(FUNC_PLAYERSKINVIEWER_GETPOS)(this, w, x, y);
		}
		void getSize(gui::Window* w, int* width, int* height) override
		{
			return reinterpret_cast<void (__thiscall*)(PlayerSkinViewer* self, gui::Window* w, int* width, int* height)>(FUNC_PLAYERSKINVIEWER_GETSIZE)(this, w, width, height);
		}
		bool mouseInput(gui::Window* w, double xpos, double ypos) override
		{
			return reinterpret_cast<bool (__thiscall*)(PlayerSkinViewer* self, gui::Window* w, double xpos, double ypos)>(FUNC_PLAYERSKINVIEWER_MOUSEINPUT)(this, w, xpos, ypos);
		}
		int getCursorType() override
		{
			return reinterpret_cast<int (__thiscall*)(PlayerSkinViewer* self)>(FUNC_PLAYERSKINVIEWER_GETCURSORTYPE)(this);
		}
		void init(PlayerSkinRenderer* skinRenderer) 
		{
			return reinterpret_cast<void (__thiscall*)(PlayerSkinViewer* self, PlayerSkinRenderer* skinRenderer)>(FUNC_PLAYERSKINVIEWER_INIT)(this, skinRenderer);
		}
		void setupFrameBuffer() 
		{
			return reinterpret_cast<void (__thiscall*)(PlayerSkinViewer* self)>(FUNC_PLAYERSKINVIEWER_SETUPFRAMEBUFFER)(this);
		}
	};
}
