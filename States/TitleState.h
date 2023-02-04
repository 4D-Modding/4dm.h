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
	private:
		static TitleState* instanceObj;
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

		static TitleState* getInstance()
		{
			TitleState::instanceObj = reinterpret_cast<TitleState*>((base + idaOffsetFix(0x1BFA10)));
			return instanceObj;
		}
		void updateProjection(int width, int height) 
		{
			reinterpret_cast<void(__thiscall*)(TitleState*, int, int)>(
				base + idaOffsetFix(0x93A70)
				)(this, width, height);
		}
		static void singleplayerButtonCallback(void* user)
		{
			reinterpret_cast<void(__fastcall*)(void*)>(
				base + idaOffsetFix(0x93EF0)
				)(user);
		}
		static void creditsButtonCallback(void* user)
		{
			reinterpret_cast<void(__fastcall*)(void*)>(
				base + idaOffsetFix(0x93F80)
				)(user);
		}
		static void tutorialButtonCallback(void* user)
		{
			reinterpret_cast<void(__fastcall*)(void*)>(
				base + idaOffsetFix(0x94010)
				)(user);
		}
		void init(StateManager& s) override
		{
			reinterpret_cast<void(__thiscall*)(TitleState*, StateManager&)>(
				base + idaOffsetFix(0x940A0)
				)(this, s);
		}
		void close(StateManager& s) override
		{
			reinterpret_cast<void(__thiscall*)(TitleState*, StateManager&)>(
				base + idaOffsetFix(0x94990)
				)(this, s);
		}
		void update(StateManager& s, double dt) override
		{
			reinterpret_cast<void(__thiscall*)(TitleState*, StateManager&, double)>(
				base + idaOffsetFix(0x94B00)
				)(this, s, dt);
		}
		void render(StateManager& s) override
		{
			reinterpret_cast<void(__thiscall*)(TitleState*, StateManager&)>(
				base + idaOffsetFix(0x94BF0)
				)(this, s);
		}
		void keyInput(StateManager& s, int key, int scancode, int action, int mods) override
		{
			reinterpret_cast<void(__thiscall*)(TitleState*, StateManager&, int, int, int, int)>(
				base + idaOffsetFix(0x953D0)
				)(this, s, key, scancode, action, mods);
		}
		void windowResize(StateManager& s, int width, int height) override
		{
			reinterpret_cast<void(__thiscall*)(TitleState*, StateManager&, int, int)>(
				base + idaOffsetFix(0x95460)
				)(this, s, width, height);
		}
		void mouseInput(StateManager& s, double xPos, double yPos) override
		{
			reinterpret_cast<void(__thiscall*)(TitleState*, StateManager&, double, double)>(
				base + idaOffsetFix(0x95470)
				)(this, s, xPos, yPos);
		}
		void mouseButtonInput(StateManager& s, int button, int action, int mods) override
		{
			reinterpret_cast<void(__thiscall*)(TitleState*, StateManager&, int, int, int)>(
				base + idaOffsetFix(0x95490)
				)(this, s, button, action, mods);
		}
		void resume(StateManager& s) override
		{
			reinterpret_cast<void(__thiscall*)(TitleState*, StateManager&)>(
				base + idaOffsetFix(0x954C0)
				)(this, s);
		}
		void renderBackground(int width, int height)
		{
			reinterpret_cast<void(__thiscall*)(TitleState*, int, int)>(
				base + idaOffsetFix(0x95520)
				)(this, width, height);
		}
	};
	TitleState* TitleState::instanceObj;
}
#endif