#pragma once

#include "4dm.h"

namespace fdm 
{
	class StateDeathScreen : public State 
	{
	public:
		inline static StateDeathScreen* instanceObj = reinterpret_cast<StateDeathScreen*>((base + 0x278CF0));
		TexRenderer skullRenderer; // 0x8
		FontRenderer font; // 0x30
		QuadRenderer qr; // 0xD0
		Shader* qs; // 0xF8
		gui::Interface ui; // 0x100
		bool updateViewFlag; // 0x168
		PAD(0x7);
		gui::Button retryButton; // 0x170
		gui::Button quitButton; // 0x1C8
		inline static const float bgFadeTime = 1.f; 
		inline static const float skullFadeTime = 1.f; 
		double animationStartTime; // 0x220

		void updateProjection(const glm::ivec2& size, const glm::ivec2& translate2D) 
		{
			return reinterpret_cast<void (__thiscall*)(StateDeathScreen* self, const glm::ivec2& size, const glm::ivec2& translate2D)>(getFuncAddr((int)Func::StateDeathScreen::updateProjection))(this, size, translate2D);
		}
		inline static void retryButtonCallback(void* user) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user)>(getFuncAddr((int)Func::StateDeathScreen::retryButtonCallback))(user);
		}
		void init(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateDeathScreen* self, StateManager& s)>(getFuncAddr((int)Func::StateDeathScreen::init))(this, s);
		}
		void close(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateDeathScreen* self, StateManager& s)>(getFuncAddr((int)Func::StateDeathScreen::close))(this, s);
		}
		void update(StateManager& s, double dt) override
		{
			return reinterpret_cast<void (__thiscall*)(StateDeathScreen* self, StateManager& s, double dt)>(getFuncAddr((int)Func::StateDeathScreen::update))(this, s, dt);
		}
		void render(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateDeathScreen* self, StateManager& s)>(getFuncAddr((int)Func::StateDeathScreen::render))(this, s);
		}
		void mouseInput(StateManager& s, double xpos, double ypos) override
		{
			return reinterpret_cast<void (__thiscall*)(StateDeathScreen* self, StateManager& s, double xpos, double ypos)>(getFuncAddr((int)Func::StateDeathScreen::mouseInput))(this, s, xpos, ypos);
		}
		void scrollInput(StateManager& s, double xoffset, double yoffset) override
		{
			return reinterpret_cast<void (__thiscall*)(StateDeathScreen* self, StateManager& s, double xoffset, double yoffset)>(getFuncAddr((int)Func::StateDeathScreen::scrollInput))(this, s, xoffset, yoffset);
		}
		void mouseButtonInput(StateManager& s, int button, int action, int mods) override
		{
			return reinterpret_cast<void (__thiscall*)(StateDeathScreen* self, StateManager& s, int button, int action, int mods)>(getFuncAddr((int)Func::StateDeathScreen::mouseButtonInput))(this, s, button, action, mods);
		}
		void keyInput(StateManager& s, int key, int scancode, int action, int mods) override
		{
			return reinterpret_cast<void (__thiscall*)(StateDeathScreen* self, StateManager& s, int key, int scancode, int action, int mods)>(getFuncAddr((int)Func::StateDeathScreen::keyInput))(this, s, key, scancode, action, mods);
		}
		void windowResize(StateManager& s, int width, int height) override
		{
			return reinterpret_cast<void (__thiscall*)(StateDeathScreen* self, StateManager& s, int width, int height)>(getFuncAddr((int)Func::StateDeathScreen::windowResize))(this, s, width, height);
		}
	};
}
