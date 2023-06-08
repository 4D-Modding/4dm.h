#pragma once
#ifndef TITLESTATE_H
#define TITLESTATE_H
#include "../4dm.h"
#include "State.h"

using namespace fdm::gui;

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

	class TitleState : public State
	{
	public:
		glm::mat4x4 projection2D;
		glm::mat4x4 projection3D;
		
		float displayProgress;

		PAD(4);

		FontRenderer font;
		QuadRenderer qr;

		const Shader* qs;

		TexRenderer logoRenderer;

		float rotation;

		PAD(4);

		World bgWorld;

		glm::ivec3 spawnChunk;
		glm::vec4 bgPos;
		glm::vec3 skyColorTop;
		glm::vec3 skyColorBottom;

		PAD(4);

		Interface ui;
		Button singleplayerButton;
		Button multiplayerButton;
		Button tutorialButton;
		Button settingsButton;
		Button quitButton;
		Button creditsButton;

		inline static TitleState* getInstance() // instanceObj
		{
			return *reinterpret_cast<TitleState**>((base + 0x1C0230));
		}
		TitleState()
		{
			reinterpret_cast<void(__thiscall*)(TitleState*)>(
				FUNC_TITLESTATE_TITLESTATE
				)(this);
		}
		void updateProjection(int width, int height) 
		{
			reinterpret_cast<void(__thiscall*)(TitleState*, int, int)>(
				FUNC_TITLESTATE_UPDATEPROJECTION
				)(this, width, height);
		}
		inline static void singleplayerButtonCallback(void* user)
		{
			reinterpret_cast<void(__fastcall*)(void*)>(
				FUNC_TITLESTATE_SINGLEPLAYERBUTTONCALLBACK
				)(user);
		}
		inline static void creditsButtonCallback(void* user)
		{
			reinterpret_cast<void(__fastcall*)(void*)>(
				FUNC_TITLESTATE_CREDITSBUTTONCALLBACK
				)(user);
		}
		inline static void tutorialButtonCallback(void* user)
		{
			reinterpret_cast<void(__fastcall*)(void*)>(
				FUNC_TITLESTATE_TUTORIALBUTTONCALLBACK
				)(user);
		}
		void init(StateManager& s) override
		{
			reinterpret_cast<void(__thiscall*)(TitleState*, StateManager&)>(
				FUNC_TITLESTATE_INIT
				)(this, s);
		}
		void close(StateManager& s) override
		{
			reinterpret_cast<void(__thiscall*)(TitleState*, StateManager&)>(
				FUNC_TITLESTATE_CLOSE
				)(this, s);
		}
		void update(StateManager& s, double dt) override
		{
			reinterpret_cast<void(__thiscall*)(TitleState*, StateManager&, double)>(
				FUNC_TITLESTATE_UPDATE
				)(this, s, dt);
		}
		void render(StateManager& s) override
		{
			reinterpret_cast<void(__thiscall*)(TitleState*, StateManager&)>(
				FUNC_TITLESTATE_RENDER
				)(this, s);
		}
		void keyInput(StateManager& s, int key, int scancode, int action, int mods) override
		{
			reinterpret_cast<void(__thiscall*)(TitleState*, StateManager&, int, int, int, int)>(
				FUNC_TITLESTATE_KEYINPUT
				)(this, s, key, scancode, action, mods);
		}
		void windowResize(StateManager& s, int width, int height) override
		{
			reinterpret_cast<void(__thiscall*)(TitleState*, StateManager&, int, int)>(
				FUNC_TITLESTATE_WINDOWRESIZE
				)(this, s, width, height);
		}
		void mouseInput(StateManager& s, double xPos, double yPos) override
		{
			reinterpret_cast<void(__thiscall*)(TitleState*, StateManager&, double, double)>(
				FUNC_TITLESTATE_MOUSEINPUT
				)(this, s, xPos, yPos);
		}
		void mouseButtonInput(StateManager& s, int button, int action, int mods) override
		{
			reinterpret_cast<void(__thiscall*)(TitleState*, StateManager&, int, int, int)>(
				FUNC_TITLESTATE_MOUSEBUTTONINPUT
				)(this, s, button, action, mods);
		}
		void resume(StateManager& s) override
		{
			reinterpret_cast<void(__thiscall*)(TitleState*, StateManager&)>(
				FUNC_TITLESTATE_RESUME
				)(this, s);
		}
		void renderBackground(int width, int height)
		{
			reinterpret_cast<void(__thiscall*)(TitleState*, int, int)>(
				FUNC_TITLESTATE_RENDERBACKGROUND
				)(this, width, height);
		}
	};
}
#endif