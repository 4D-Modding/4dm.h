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
			return reinterpret_cast<void (__thiscall*)(PlayerSkinViewer* self, gui::Window* w)>(getFuncAddr((int)Func::PlayerSkinViewer::render))(this, w);
		}
		void alignX(gui::AlignmentX a) override
		{
			return reinterpret_cast<void (__thiscall*)(PlayerSkinViewer* self, gui::AlignmentX a)>(getFuncAddr((int)Func::PlayerSkinViewer::alignX))(this, a);
		}
		void alignY(gui::AlignmentY a) override
		{
			return reinterpret_cast<void (__thiscall*)(PlayerSkinViewer* self, gui::AlignmentY a)>(getFuncAddr((int)Func::PlayerSkinViewer::alignY))(this, a);
		}
		void getPos(const gui::Window* w, int* x, int* y) const override
		{
			return reinterpret_cast<void (__thiscall*)(const PlayerSkinViewer* self, const gui::Window* w, int* x, int* y)>(getFuncAddr((int)Func::PlayerSkinViewer::getPos))(this, w, x, y);
		}
		void getSize(const gui::Window* w, int* width, int* height) const override
		{
			return reinterpret_cast<void (__thiscall*)(const PlayerSkinViewer* self, const gui::Window* w, int* width, int* height)>(getFuncAddr((int)Func::PlayerSkinViewer::getSize))(this, w, width, height);
		}
		bool mouseInput(const gui::Window* w, double xpos, double ypos) override
		{
			return reinterpret_cast<bool (__thiscall*)(PlayerSkinViewer* self, const gui::Window* w, double xpos, double ypos)>(getFuncAddr((int)Func::PlayerSkinViewer::mouseInput))(this, w, xpos, ypos);
		}
		int getCursorType() override
		{
			return reinterpret_cast<int (__thiscall*)(PlayerSkinViewer* self)>(getFuncAddr((int)Func::PlayerSkinViewer::getCursorType))(this);
		}
		void init(PlayerSkinRenderer* skinRenderer) 
		{
			return reinterpret_cast<void (__thiscall*)(PlayerSkinViewer* self, PlayerSkinRenderer* skinRenderer)>(getFuncAddr((int)Func::PlayerSkinViewer::init))(this, skinRenderer);
		}
		void setupFrameBuffer() 
		{
			return reinterpret_cast<void (__thiscall*)(PlayerSkinViewer* self)>(getFuncAddr((int)Func::PlayerSkinViewer::setupFrameBuffer))(this);
		}
	};
}
