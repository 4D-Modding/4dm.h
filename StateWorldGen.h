#pragma once

#include "4dm.h"

namespace fdm 
{
	class StateWorldGen : public State 
	{
	public:
		inline static StateWorldGen* instanceObj = reinterpret_cast<StateWorldGen*>((base + 0x279EB0));
		glm::mat4 projection2D; // 0x8
		glm::mat4 projection3D; // 0x48
		float displayProgress; // 0x88
		PAD(0x4);
		FontRenderer font; // 0x90
		Shader* shapeShader; // 0x130
		MeshRenderer shapeRenderer; // 0x138
		uint32_t mvID; // 0x158
		float rotation; // 0x15C
		QuadRenderer qr; // 0x160
		Shader* qs; // 0x188

		void updateProjection(int width, int height) 
		{
			return reinterpret_cast<void (__thiscall*)(StateWorldGen* self, int width, int height)>(getFuncAddr((int)Func::StateWorldGen::updateProjection))(this, width, height);
		}
		void init(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateWorldGen* self, StateManager& s)>(getFuncAddr((int)Func::StateWorldGen::init))(this, s);
		}
		void update(StateManager& s, double dt) override
		{
			return reinterpret_cast<void (__thiscall*)(StateWorldGen* self, StateManager& s, double dt)>(getFuncAddr((int)Func::StateWorldGen::update))(this, s, dt);
		}
		void render(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateWorldGen* self, StateManager& s)>(getFuncAddr((int)Func::StateWorldGen::render))(this, s);
		}
		void windowResize(StateManager& s, int width, int height) override
		{
			return reinterpret_cast<void (__thiscall*)(StateWorldGen* self, StateManager& s, int width, int height)>(getFuncAddr((int)Func::StateWorldGen::windowResize))(this, s, width, height);
		}
	};
}
