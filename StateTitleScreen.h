#pragma once

#include "4dm.h"

namespace fdm 
{
	class StateTitleScreen : public State 
	{
	public:
		inline static StateTitleScreen* instanceObj = reinterpret_cast<StateTitleScreen*>((base + 0x2C1980));
		glm::mat4 projection2D; // 0x8
		glm::mat4 projection3D; // 0x48
		bool paused; // 0x88
		PAD(0x3);
		float displayProgress; // 0x8C
		FontRenderer font; // 0x90
		QuadRenderer qr; // 0x130
		Shader* qs; // 0x158
		TexRenderer logoRenderer; // 0x160
		float rotation; // 0x188
		PAD(0x4);
		std::unique_ptr<WorldTitleScreen,std::default_delete<WorldTitleScreen> > bgWorld; // 0x190
		glm::ivec3 spawnChunk; // 0x198
		glm::vec4 bgPos; // 0x1A4
		glm::vec3 skyColorTop; // 0x1B4
		glm::vec3 skyColorBottom; // 0x1C0
		PAD(0x4);
		gui::Interface ui; // 0x1D0
		gui::Button singleplayerButton; // 0x238
		gui::Button multiplayerButton; // 0x290
		gui::Button tutorialButton; // 0x2E8
		gui::Button settingsButton; // 0x340
		gui::Button quitButton; // 0x398
		gui::Button creditsButton; // 0x3F0
		gui::Text versionText; // 0x448

		inline static void quitGameButtonCallback(void* user) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user)>(FUNC_STATETITLESCREEN_QUITGAMEBUTTONCALLBACK)(user);
		}
		inline static void settingsButtonCallback(void* user) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user)>(FUNC_STATETITLESCREEN_SETTINGSBUTTONCALLBACK)(user);
		}
		StateTitleScreen() 
		{
			reinterpret_cast<void(__thiscall*)(StateTitleScreen* self)>(FUNC_STATETITLESCREEN_STATETITLESCREEN)(this);
		}
		void updateProjection(int width, int height) 
		{
			return reinterpret_cast<void (__thiscall*)(StateTitleScreen* self, int width, int height)>(FUNC_STATETITLESCREEN_UPDATEPROJECTION)(this, width, height);
		}
		inline static void singleplayerButtonCallback(void* user) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user)>(FUNC_STATETITLESCREEN_SINGLEPLAYERBUTTONCALLBACK)(user);
		}
		inline static void multiplayerplayerButtonCallback(void* user) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user)>(FUNC_STATETITLESCREEN_MULTIPLAYERPLAYERBUTTONCALLBACK)(user);
		}
		inline static void creditsButtonCallback(void* user) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user)>(FUNC_STATETITLESCREEN_CREDITSBUTTONCALLBACK)(user);
		}
		inline static void tutorialButtonCallback(void* user) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user)>(FUNC_STATETITLESCREEN_TUTORIALBUTTONCALLBACK)(user);
		}
		void init(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateTitleScreen* self, StateManager& s)>(FUNC_STATETITLESCREEN_INIT)(this, s);
		}
		void close(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateTitleScreen* self, StateManager& s)>(FUNC_STATETITLESCREEN_CLOSE)(this, s);
		}
		void update(StateManager& s, double dt) override
		{
			return reinterpret_cast<void (__thiscall*)(StateTitleScreen* self, StateManager& s, double dt)>(FUNC_STATETITLESCREEN_UPDATE)(this, s, dt);
		}
		void render(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateTitleScreen* self, StateManager& s)>(FUNC_STATETITLESCREEN_RENDER)(this, s);
		}
		void pause(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateTitleScreen* self, StateManager& s)>(FUNC_STATETITLESCREEN_PAUSE)(this, s);
		}
		void resume(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateTitleScreen* self, StateManager& s)>(FUNC_STATETITLESCREEN_RESUME)(this, s);
		}
		void keyInput(StateManager& s, int key, int scancode, int action, int mods) override
		{
			return reinterpret_cast<void (__thiscall*)(StateTitleScreen* self, StateManager& s, int key, int scancode, int action, int mods)>(FUNC_STATETITLESCREEN_KEYINPUT)(this, s, key, scancode, action, mods);
		}
		void windowResize(StateManager& s, int width, int height) override
		{
			return reinterpret_cast<void (__thiscall*)(StateTitleScreen* self, StateManager& s, int width, int height)>(FUNC_STATETITLESCREEN_WINDOWRESIZE)(this, s, width, height);
		}
		void mouseInput(StateManager& s, double xpos, double ypos) override
		{
			return reinterpret_cast<void (__thiscall*)(StateTitleScreen* self, StateManager& s, double xpos, double ypos)>(FUNC_STATETITLESCREEN_MOUSEINPUT)(this, s, xpos, ypos);
		}
		void mouseButtonInput(StateManager& s, int button, int action, int mods) override
		{
			return reinterpret_cast<void (__thiscall*)(StateTitleScreen* self, StateManager& s, int button, int action, int mods)>(FUNC_STATETITLESCREEN_MOUSEBUTTONINPUT)(this, s, button, action, mods);
		}
		void renderBackground(int width, int height) 
		{
			return reinterpret_cast<void (__thiscall*)(StateTitleScreen* self, int width, int height)>(FUNC_STATETITLESCREEN_RENDERBACKGROUND)(this, width, height);
		}
	};
}
