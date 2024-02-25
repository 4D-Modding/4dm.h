#pragma once

#include "4dm.h"

namespace fdm 
{
	class StateIntro : public State 
	{
	public:
		inline static StateIntro* instanceObj = reinterpret_cast<StateIntro*>((base + 0x279140));
		glm::mat4 projection2D; // 0x8
		glm::mat4 projection3D; // 0x48
		inline static const int fileCount = 6;
		inline static const char* fileNames[fileCount] = { "logo.png", "moon.png", "sun.png", "crosshair.png", "targetBlock.png", "forg.png" }; // rip "ock.png"
		struct 
		{
			unsigned char* data;
			int width;
			int height;
			int channels;
		} imageData[fileCount];
		std::atomic_int filesLoaded; // 0x118
		float displayProgress; // 0x11C
		FontRenderer font; // 0x120
		Shader* hypercubeShader; // 0x1C0
		MeshRenderer hypercubeRenderer; // 0x1C8
		uint32_t mvID; // 0x1E8
		float rotation; // 0x1EC
		QuadRenderer qr; // 0x1F0
		Shader* qs; // 0x218

		void updateProjection(int width, int height) 
		{
			return reinterpret_cast<void (__thiscall*)(StateIntro* self, int width, int height)>(getFuncAddr((int)Func::StateIntro::updateProjection))(this, width, height);
		}
		void loadFiles() 
		{
			return reinterpret_cast<void (__thiscall*)(StateIntro* self)>(getFuncAddr((int)Func::StateIntro::loadFiles))(this);
		}
		void init(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateIntro* self, StateManager& s)>(getFuncAddr((int)Func::StateIntro::init))(this, s);
		}
		void update(StateManager& s, double dt) override
		{
			return reinterpret_cast<void (__thiscall*)(StateIntro* self, StateManager& s, double dt)>(getFuncAddr((int)Func::StateIntro::update))(this, s, dt);
		}
		void render(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateIntro* self, StateManager& s)>(getFuncAddr((int)Func::StateIntro::render))(this, s);
		}
		void windowResize(StateManager& s, int width, int height) override
		{
			return reinterpret_cast<void (__thiscall*)(StateIntro* self, StateManager& s, int width, int height)>(getFuncAddr((int)Func::StateIntro::windowResize))(this, s, width, height);
		}
	};
}
