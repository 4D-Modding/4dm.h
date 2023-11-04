#pragma once

#include "4dm.h"

namespace fdm 
{
	class StateCredits : public State 
	{
	public:
		inline static StateCredits* instanceObj = reinterpret_cast<StateCredits*>((base + 0x278BA0));
		glm::mat4 projection2D; // 0x8
		float yOffset; // 0x48
		PAD(0x4);
		FontRenderer font; // 0x50
		QuadRenderer qr; // 0xF0
		Shader* qs; // 0x118
		std::vector<Tex2D> supporters; // 0x120
		std::vector<Tex2D> hyperSupporters; // 0x138

		void init(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateCredits* self, StateManager& s)>(FUNC_STATECREDITS_INIT_A)(this, s);
		}
		void update(StateManager& s, double dt) override
		{
			return reinterpret_cast<void (__thiscall*)(StateCredits* self, StateManager& s, double dt)>(FUNC_STATECREDITS_UPDATE_A)(this, s, dt);
		}
		void render(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateCredits* self, StateManager& s)>(FUNC_STATECREDITS_RENDER_A)(this, s);
		}
		void windowResize(StateManager& s, int width, int height) override
		{
			return reinterpret_cast<void (__thiscall*)(StateCredits* self, StateManager& s, int width, int height)>(FUNC_STATECREDITS_WINDOWRESIZE_A)(this, s, width, height);
		}
		void keyInput(StateManager& s, int key, int scancode, int action, int mods) override
		{
			return reinterpret_cast<void (__thiscall*)(StateCredits* self, StateManager& s, int key, int scancode, int action, int mods)>(FUNC_STATECREDITS_KEYINPUT_A)(this, s, key, scancode, action, mods);
		}
		void updateProjection(int width, int height) 
		{
			return reinterpret_cast<void (__thiscall*)(StateCredits* self, int width, int height)>(FUNC_STATECREDITS_UPDATEPROJECTION_A)(this, width, height);
		}
	};
}
