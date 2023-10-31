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
		float animationStartTime; // 0x220

		void updateProjection(const glm::ivec2& size, const glm::ivec2& translate2D) 
		{
			return reinterpret_cast<void (__thiscall*)(StateDeathScreen* self, const glm::ivec2& size, const glm::ivec2& translate2D)>(FUNC_STATEDEATHSCREEN_UPDATEPROJECTION)(this, size, translate2D);
		}
		inline static void retryButtonCallback(void* user) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user)>(FUNC_STATEDEATHSCREEN_RETRYBUTTONCALLBACK)(user);
		}
		void init(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateDeathScreen* self, StateManager& s)>(FUNC_STATEDEATHSCREEN_INIT)(this, s);
		}
		void close(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateDeathScreen* self, StateManager& s)>(FUNC_STATEDEATHSCREEN_CLOSE)(this, s);
		}
		void update(StateManager& s, double dt) override
		{
			return reinterpret_cast<void (__thiscall*)(StateDeathScreen* self, StateManager& s, double dt)>(FUNC_STATEDEATHSCREEN_UPDATE)(this, s, dt);
		}
		void render(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateDeathScreen* self, StateManager& s)>(FUNC_STATEDEATHSCREEN_RENDER)(this, s);
		}
		void mouseInput(StateManager& s, double xpos, double ypos) override
		{
			return reinterpret_cast<void (__thiscall*)(StateDeathScreen* self, StateManager& s, double xpos, double ypos)>(FUNC_STATEDEATHSCREEN_MOUSEINPUT)(this, s, xpos, ypos);
		}
		void scrollInput(StateManager& s, double xoffset, double yoffset) override
		{
			return reinterpret_cast<void (__thiscall*)(StateDeathScreen* self, StateManager& s, double xoffset, double yoffset)>(FUNC_STATEDEATHSCREEN_SCROLLINPUT)(this, s, xoffset, yoffset);
		}
		void mouseButtonInput(StateManager& s, int button, int action, int mods) override
		{
			return reinterpret_cast<void (__thiscall*)(StateDeathScreen* self, StateManager& s, int button, int action, int mods)>(FUNC_STATEDEATHSCREEN_MOUSEBUTTONINPUT)(this, s, button, action, mods);
		}
		void keyInput(StateManager& s, int key, int scancode, int action, int mods) override
		{
			return reinterpret_cast<void (__thiscall*)(StateDeathScreen* self, StateManager& s, int key, int scancode, int action, int mods)>(FUNC_STATEDEATHSCREEN_KEYINPUT)(this, s, key, scancode, action, mods);
		}
		void windowResize(StateManager& s, int width, int height) override
		{
			return reinterpret_cast<void (__thiscall*)(StateDeathScreen* self, StateManager& s, int width, int height)>(FUNC_STATEDEATHSCREEN_WINDOWRESIZE)(this, s, width, height);
		}
	};
}
