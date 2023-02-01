#pragma once
#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "../4dm.h"
#include "State.h"
namespace fdm
{
	struct StateManager;
	class CloudManager;
	class Shader;
	class World;
	class MeshRenderer;
	class TexRenderer;
	class Tex2D;
	class Player;
	class State;
	class GameState : public State
	{
	private:
		static GameState* instanceObj;
	public:
		World world;
		CloudManager clouds;
		glm::mat4x4 projection2D;
		glm::mat4x4 projection3D;
	    Shader* cloudShader;
		unsigned int cloudmvID;
		unsigned int cloudBlendID;
		Shader* levelShader;
		unsigned int levelShadermvID;
		PAD(4);
		MeshRenderer blockRenderer;
		MeshRenderer skyboxRenderer;
		Shader* moonShader;
		Tex2D* moonTex;
		unsigned int moonmvID;
		unsigned int moonBlendID;
		MeshRenderer moonRenderer;
		Shader* tex2DShader;
		TexRenderer crosshairRenderer;
		Shader* blockShader;
		Shader* targetBlockShader;
		float time;
		PAD(4);
		Player player;
		glm::dvec2 initialCursorPos;
		float renderDistance;
		float cloudRenderDistance;
		float FOV;

		static GameState* getInstance() 
		{
			GameState::instanceObj = reinterpret_cast<GameState*>((base + idaOffsetFix(0x17B460)));
			return instanceObj;
		}

		void init(StateManager& s) override
		{
			reinterpret_cast<void(__thiscall*)(GameState*, StateManager&)>(
				base + idaOffsetFix(0x50690)
				)(this, s);
		}
		void close(StateManager& s) override
		{
			reinterpret_cast<void(__thiscall*)(GameState*, StateManager&)>(
				base + idaOffsetFix(0x51340)
				)(this, s);
		}
		void pause(StateManager& s) override
		{
			reinterpret_cast<void(__thiscall*)(GameState*, StateManager&)>(
				base + idaOffsetFix(0x519B0)
				)(this, s);
		}
		void resume(StateManager& s) override
		{
			reinterpret_cast<void(__thiscall*)(GameState*, StateManager&)>(
				base + idaOffsetFix(0x51A00)
				)(this, s);
		}
		void update(StateManager& s, double dt) override
		{
			reinterpret_cast<void(__thiscall*)(GameState*, StateManager&, double)>(
				base + idaOffsetFix(0x51AC0)
				)(this, s, dt);
		}
		void render(StateManager& s) override
		{
			reinterpret_cast<void(__thiscall*)(GameState*, StateManager&)>(
				base + idaOffsetFix(0x51DD0)
				)(this, s);
		}
		void mouseInput(StateManager& s, double xPos, double yPos) override
		{
			reinterpret_cast<void(__thiscall*)(GameState*, StateManager&, double, double)>(
				base + idaOffsetFix(0x53760)
				)(this, s, xPos, yPos);
		}
		void scrollInput(StateManager& s, double xOff, double yOff) override
		{
			reinterpret_cast<void(__thiscall*)(GameState*, StateManager&, double, double)>(
				base + idaOffsetFix(0x53770)
				)(this, s, xOff, yOff);
		}
		void mouseButtonInput(StateManager& s, int button, int action, int mods) override
		{
			reinterpret_cast<void(__thiscall*)(GameState*, StateManager&, int, int, int)>(
				base + idaOffsetFix(0x53870)
				)(this, s, button, action, mods);
		}
		void keyInput(StateManager& s, int key, int scancode, int action, int mods) override
		{
			reinterpret_cast<void(__thiscall*)(GameState*, StateManager&, int, int, int, int)>(
				base + idaOffsetFix(0x53880)
				)(this, s, key, scancode, action, mods);
		}
		void windowResize(StateManager& s, int width, int height) override
		{
			reinterpret_cast<void(__thiscall*)(GameState*, StateManager&, int, int)>(
				base + idaOffsetFix(0x53940)
				)(this, s, width, height);
		}
		void updateProjection(int width, int height)
		{
			reinterpret_cast<void(__thiscall*)(GameState*, int, int)>(
				base + idaOffsetFix(0x53990)
				)(this, width, height);
		}
	};
	GameState* GameState::instanceObj;
}
#endif