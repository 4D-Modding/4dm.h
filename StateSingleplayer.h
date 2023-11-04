#pragma once

#include "4dm.h"

namespace fdm 
{
	class StateSingleplayer : public State 
	{
	public:
		inline static StateSingleplayer* instanceObj = reinterpret_cast<StateSingleplayer*>((base + 0x2C0BE0));
		bool updateViewFlag; // 0x8
		PAD(0x7);
		FontRenderer font; // 0x10
		QuadRenderer qr; // 0xB0
		Shader* qs; // 0xD8
		gui::Interface ui; // 0xE0
		gui::Button createButton; // 0x148
		gui::Button cancelButton; // 0x1A0
		gui::ContentBox worldListContainer; // 0x1F8
		gui::Text yourWorlds; // 0x278
		gui::Text noWorlds; // 0x2D0
		std::vector<gui::Button> worldButtons; // 0x328
		std::vector<std::string> worldPaths; // 0x340
		bool shouldLoadWorld; // 0x358

		void mouseButtonInput(StateManager& s, int button, int action, int mods) override
		{
			return reinterpret_cast<void (__thiscall*)(StateSingleplayer* self, StateManager& s, int button, int action, int mods)>(FUNC_STATESINGLEPLAYER_MOUSEBUTTONINPUT)(this, s, button, action, mods);
		}
		void updateProjection(const glm::ivec2& size, const glm::ivec2& translate2D) 
		{
			return reinterpret_cast<void (__thiscall*)(StateSingleplayer* self, const glm::ivec2& size, const glm::ivec2& translate2D)>(FUNC_STATESINGLEPLAYER_UPDATEPROJECTION)(this, size, translate2D);
		}
		StateSingleplayer() 
		{
			reinterpret_cast<void(__thiscall*)(StateSingleplayer* self)>(FUNC_STATESINGLEPLAYER_STATESINGLEPLAYER)(this);
		}
		void updateWorldListContainer(int wWidth, int wHeight) 
		{
			return reinterpret_cast<void (__thiscall*)(StateSingleplayer* self, int wWidth, int wHeight)>(FUNC_STATESINGLEPLAYER_UPDATEWORLDLISTCONTAINER)(this, wWidth, wHeight);
		}
		inline static void createCallback(void* user) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user)>(FUNC_STATESINGLEPLAYER_CREATECALLBACK)(user);
		}
		inline static void viewportCallback(void* user, const glm::ivec4& pos, const glm::ivec2& scroll) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, const glm::ivec4& pos, const glm::ivec2& scroll)>(FUNC_STATESINGLEPLAYER_VIEWPORTCALLBACK)(user, pos, scroll);
		}
		inline static void worldButtonCallback(void* user) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user)>(FUNC_STATESINGLEPLAYER_WORLDBUTTONCALLBACK)(user);
		}
		void init(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateSingleplayer* self, StateManager& s)>(FUNC_STATESINGLEPLAYER_INIT)(this, s);
		}
		void close(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateSingleplayer* self, StateManager& s)>(FUNC_STATESINGLEPLAYER_CLOSE)(this, s);
		}
		void update(StateManager& s, double dt) override
		{
			return reinterpret_cast<void (__thiscall*)(StateSingleplayer* self, StateManager& s, double dt)>(FUNC_STATESINGLEPLAYER_UPDATE)(this, s, dt);
		}
		void resume(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateSingleplayer* self, StateManager& s)>(FUNC_STATESINGLEPLAYER_RESUME)(this, s);
		}
		void windowResize(StateManager& s, int width, int height) override
		{
			return reinterpret_cast<void (__thiscall*)(StateSingleplayer* self, StateManager& s, int width, int height)>(FUNC_STATESINGLEPLAYER_WINDOWRESIZE)(this, s, width, height);
		}
		void queueWorldLoad(std::string& path) 
		{
			return reinterpret_cast<void (__thiscall*)(StateSingleplayer* self, std::string& path)>(FUNC_STATESINGLEPLAYER_QUEUEWORLDLOAD)(this, path);
		}
	};
}
