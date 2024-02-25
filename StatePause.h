#pragma once

#include "4dm.h"

namespace fdm 
{
	class StatePause : public State 
	{
	public:
		inline static StatePause* instanceObj = reinterpret_cast<StatePause*>((base + 0x2BF7D0));
		bool paused; // 0x8
		PAD(0x7);
		FontRenderer font; // 0x10
		QuadRenderer qr; // 0xB0
		Shader* qs; // 0xD8
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
	};
}
