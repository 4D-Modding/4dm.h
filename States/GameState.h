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

		inline static GameState* getInstance() // instanceObj
		{
			return *reinterpret_cast<GameState**>((base + 0x1BE400));
		}
		GameState()
		{
			reinterpret_cast<void(__thiscall*)(GameState*)>(
				FUNC_GAMESTATE_GAMESTATE
				)(this);
		}
		void init(StateManager& s) override
		{
			reinterpret_cast<void(__thiscall*)(GameState*, StateManager&)>(
				FUNC_GAMESTATE_INIT
				)(this, s);
		}
		void close(StateManager& s) override
		{
			reinterpret_cast<void(__thiscall*)(GameState*, StateManager&)>(
				FUNC_GAMESTATE_CLOSE
				)(this, s);
		}
		void pause(StateManager& s) override
		{
			reinterpret_cast<void(__thiscall*)(GameState*, StateManager&)>(
				FUNC_GAMESTATE_PAUSE
				)(this, s);
		}
		void resume(StateManager& s) override
		{
			reinterpret_cast<void(__thiscall*)(GameState*, StateManager&)>(
				FUNC_GAMESTATE_RESUME
				)(this, s);
		}
		void update(StateManager& s, double dt) override
		{
			reinterpret_cast<void(__thiscall*)(GameState*, StateManager&, double)>(
				FUNC_GAMESTATE_UPDATE
				)(this, s, dt);
		}
		void render(StateManager& s) override
		{
			reinterpret_cast<void(__thiscall*)(GameState*, StateManager&)>(
				FUNC_GAMESTATE_RENDER
				)(this, s);
		}
		void mouseInput(StateManager& s, double xPos, double yPos) override
		{
			reinterpret_cast<void(__thiscall*)(GameState*, StateManager&, double, double)>(
				FUNC_GAMESTATE_MOUSEINPUT
				)(this, s, xPos, yPos);
		}
		void scrollInput(StateManager& s, double xOff, double yOff) override
		{
			reinterpret_cast<void(__thiscall*)(GameState*, StateManager&, double, double)>(
				FUNC_GAMESTATE_SCROLLINPUT
				)(this, s, xOff, yOff);
		}
		void mouseButtonInput(StateManager& s, int button, int action, int mods) override
		{
			reinterpret_cast<void(__thiscall*)(GameState*, StateManager&, int, int, int)>(
				FUNC_GAMESTATE_MOUSEBUTTONINPUT
				)(this, s, button, action, mods);
		}
		void keyInput(StateManager& s, int key, int scancode, int action, int mods) override
		{
			reinterpret_cast<void(__thiscall*)(GameState*, StateManager&, int, int, int, int)>(
				FUNC_GAMESTATE_KEYINPUT
				)(this, s, key, scancode, action, mods);
		}
		void windowResize(StateManager& s, int width, int height) override
		{
			reinterpret_cast<void(__thiscall*)(GameState*, StateManager&, int, int)>(
				FUNC_GAMESTATE_WINDOWRESIZE
				)(this, s, width, height);
		}
		void updateProjection(int width, int height)
		{
			reinterpret_cast<void(__thiscall*)(GameState*, int, int)>(
				FUNC_GAMESTATE_UPDATEPROJECTION
				)(this, width, height);
		}
	};
}
#endif