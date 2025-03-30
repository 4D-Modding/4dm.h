#pragma once

#include "4dm.h"

namespace fdm 
{
	class StatePause : public State 
	{
	public:
		inline static StatePause& instanceObj = *reinterpret_cast<StatePause*>(getDataAddr((int)Data::StatePause::instanceObj));
		bool paused; // 0x8
		PAD(0x7);
		FontRenderer font; // 0x10
		QuadRenderer qr; // 0xB0
		const Shader* qs; // 0xD8
		gui::Interface ui; // 0xE0
		bool updateViewFlag; // 0x148
		PAD(0x7);
		gui::Button returnButton; // 0x150
		gui::Button quitButton; // 0x1A8
		gui::Button settingsButton; // 0x200
		gui::Text pausedText; // 0x258

		StatePause() 
		{
			reinterpret_cast<void(__thiscall*)(StatePause* self)>(getFuncAddr((int)Func::StatePause::StatePause))(this);
		}
		void updateProjection(const glm::ivec2& size, const glm::ivec2& translate2D) 
		{
			return reinterpret_cast<void (__thiscall*)(StatePause* self, const glm::ivec2& size, const glm::ivec2& translate2D)>(getFuncAddr((int)Func::StatePause::updateProjection))(this, size, translate2D);
		}
		void update(StateManager& s, double dt) override
		{
			return reinterpret_cast<void (__thiscall*)(StatePause* self, StateManager& s, double dt)>(getFuncAddr((int)Func::StatePause::update))(this, s, dt);
		}
		void render(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StatePause* self, StateManager& s)>(getFuncAddr((int)Func::StatePause::render))(this, s);
		}
		void pause(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StatePause* self, StateManager& s)>(getFuncAddr((int)Func::StatePause::pause))(this, s);
		}
		void resume(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StatePause* self, StateManager& s)>(getFuncAddr((int)Func::StatePause::resume))(this, s);
		}
		void windowResize(StateManager& s, int width, int height) override
		{
			return reinterpret_cast<void (__thiscall*)(StatePause* self, StateManager& s, int width, int height)>(getFuncAddr((int)Func::StatePause::windowResize))(this, s, width, height);
		}
		void close(StateManager& s) override
		{
			return reinterpret_cast<void(__thiscall*)(StatePause * self, StateManager&)>(getFuncAddr((int)Func::StatePause::close))(this, s);
		}
		void init(StateManager& s) override
		{
			return reinterpret_cast<void(__thiscall*)(StatePause * self, StateManager&)>(getFuncAddr((int)Func::StatePause::init))(this, s);
		}
		void keyInput(StateManager& s, int key, int scancode, int action, int mods) override
		{
			return reinterpret_cast<void(__thiscall*)(StatePause * self, StateManager&, int, int, int, int)>(getFuncAddr((int)Func::StatePause::keyInput))(this, s, key, scancode, action, mods);
		}
		void mouseButtonInput(StateManager& s, int button, int action, int mods) override
		{
			return reinterpret_cast<void(__thiscall*)(StatePause * self, StateManager&, int, int, int)>(getFuncAddr((int)Func::StatePause::mouseButtonInput))(this, s, button, action, mods);
		}
		void mouseInput(StateManager& s, double xpos, double ypos) override
		{
			return reinterpret_cast<void(__thiscall*)(StatePause * self, StateManager&, double, double)>(getFuncAddr((int)Func::StatePause::mouseInput))(this, s, xpos, ypos);
		}
		void scrollInput(StateManager& s, double xoffset, double yoffset) override
		{
			return reinterpret_cast<void(__thiscall*)(StatePause * self, StateManager&, double, double)>(getFuncAddr((int)Func::StatePause::scrollInput))(this, s, xoffset, yoffset);
		}
		inline static void quitButtonCallback(void* user)
		{
			return reinterpret_cast<void(__fastcall*)(void*)>(getFuncAddr((int)Func::StatePause::quitButtonCallback))(user);
		}
		inline static void returnButtonCallback(void* user)
		{
			return reinterpret_cast<void(__fastcall*)(void*)>(getFuncAddr((int)Func::StatePause::returnButtonCallback))(user);
		}
		inline static void settingsButtonCallback(void* user)
		{
			return reinterpret_cast<void(__fastcall*)(void*)>(getFuncAddr((int)Func::StatePause::settingsButtonCallback))(user);
		}
	};
}
