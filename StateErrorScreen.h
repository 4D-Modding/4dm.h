#pragma once

#include "4dm.h"

namespace fdm 
{
	class StateErrorScreen : public State 
	{
	public:
		inline static StateErrorScreen* instanceObj = reinterpret_cast<StateErrorScreen*>((base + 0x278F40));
		FontRenderer font; // 0x8
		QuadRenderer qr; // 0xA8
		Shader* qs; // 0xD0
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
	};
}
