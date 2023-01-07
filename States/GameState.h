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
	};
	GameState* GameState::instanceObj;
}
#endif