#pragma once

#include "4dm.h"

namespace fdm 
{
	class StateErrorScreen : public State 
	{
	public:
		inline static StateErrorScreen& instanceObj = *reinterpret_cast<StateErrorScreen*>(getDataAddr((int)Data::StateErrorScreen::instanceObj));
		FontRenderer font; // 0x8
		QuadRenderer qr; // 0xA8
		const Shader* qs; // 0xD0
		gui::Interface ui; // 0xD8
		bool updateViewFlag; // 0x140
		PAD(0x7);
		gui::Text errorText; // 0x148
		gui::Button okButton; // 0x1A0

		inline static void okButtonCallback(void* user) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user)>(getFuncAddr((int)Func::StateErrorScreen::okButtonCallback))(user);
		}
		void init(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateErrorScreen* self, StateManager& s)>(getFuncAddr((int)Func::StateErrorScreen::init))(this, s);
		}
		void close(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateErrorScreen* self, StateManager& s)>(getFuncAddr((int)Func::StateErrorScreen::close))(this, s);
		}
		void update(StateManager& s, double dt) override
		{
			return reinterpret_cast<void (__thiscall*)(StateErrorScreen* self, StateManager& s, double dt)>(getFuncAddr((int)Func::StateErrorScreen::update))(this, s, dt);
		}
		void render(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateErrorScreen* self, StateManager& s)>(getFuncAddr((int)Func::StateErrorScreen::render))(this, s);
		}
		void mouseButtonInput(StateManager& s, int button, int action, int mods) override
		{
			return reinterpret_cast<void (__thiscall*)(StateErrorScreen* self, StateManager& s, int button, int action, int mods)>(getFuncAddr((int)Func::StateErrorScreen::mouseButtonInput))(this, s, button, action, mods);
		}
		void windowResize(StateManager& s, int width, int height) override
		{
			return reinterpret_cast<void (__thiscall*)(StateErrorScreen* self, StateManager& s, int width, int height)>(getFuncAddr((int)Func::StateErrorScreen::windowResize))(this, s, width, height);
		}
		void updateProjection(const glm::ivec2& size, const glm::ivec2& translate2D)
		{
			return reinterpret_cast<void(__thiscall*)(StateErrorScreen * self, const glm::ivec2&, const glm::ivec2&)>(getFuncAddr((int)Func::StateErrorScreen::updateProjection))(this, size, translate2D);
		}
		void scrollInput(StateManager& s, double xoffset, double yoffset) override
		{
			return reinterpret_cast<void(__thiscall*)(StateErrorScreen * self, StateManager&, double, double)>(getFuncAddr((int)Func::StateErrorScreen::scrollInput))(this, s, xoffset, yoffset);
		}
		void mouseInput(StateManager& s, double xpos, double ypos) override
		{
			return reinterpret_cast<void(__thiscall*)(StateErrorScreen * self, StateManager&, double, double)>(getFuncAddr((int)Func::StateErrorScreen::mouseInput))(this, s, xpos, ypos);
		}
		void keyInput(StateManager& s, int key, int scancode, int action, int mods) override
		{
			return reinterpret_cast<void(__thiscall*)(StateErrorScreen * self, StateManager&, int, int, int, int)>(getFuncAddr((int)Func::StateErrorScreen::keyInput))(this, s, key, scancode, action, mods);
		}
	};
}
