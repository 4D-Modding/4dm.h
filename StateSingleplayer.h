#pragma once

#include "4dm.h"

namespace fdm 
{
	class StateSingleplayer : public State 
	{
	public:
		inline static StateSingleplayer& instanceObj = *reinterpret_cast<StateSingleplayer*>(getDataAddr((int)Data::StateSingleplayer::instanceObj));
		bool updateViewFlag; // 0x8
		PAD(0x7);
		FontRenderer font; // 0x10
		QuadRenderer qr; // 0xB0
		const Shader* qs; // 0xD8
		gui::Interface ui; // 0xE0
		gui::Button createButton; // 0x148
		gui::Button cancelButton; // 0x1A0
		gui::ContentBox worldListContainer; // 0x1F8
		gui::Text yourWorlds; // 0x278
		gui::Text noWorlds; // 0x2D0
		std::vector<gui::Button> worldButtons; // 0x328
		std::vector<stl::string> worldPaths; // 0x340
		bool shouldLoadWorld; // 0x358

		void mouseButtonInput(StateManager& s, int button, int action, int mods) override
		{
			return reinterpret_cast<void (__thiscall*)(StateSingleplayer* self, StateManager& s, int button, int action, int mods)>(getFuncAddr((int)Func::StateSingleplayer::mouseButtonInput))(this, s, button, action, mods);
		}
		void updateProjection(const glm::ivec2& size, const glm::ivec2& translate2D) 
		{
			return reinterpret_cast<void (__thiscall*)(StateSingleplayer* self, const glm::ivec2& size, const glm::ivec2& translate2D)>(getFuncAddr((int)Func::StateSingleplayer::updateProjection))(this, size, translate2D);
		}
		void charInput(StateManager& s, uint32_t codepoint) override
		{
			return reinterpret_cast<void(__thiscall*)(StateSingleplayer * self, StateManager&, uint32_t)>(getFuncAddr((int)Func::StateSingleplayer::charInput))(this, s, codepoint);
		}
		void keyInput(StateManager& s, int key, int scancode, int action, int mods) override
		{
			return reinterpret_cast<void(__thiscall*)(StateSingleplayer * self, StateManager&, int, int, int, int)>(getFuncAddr((int)Func::StateSingleplayer::keyInput))(this, s, key, scancode, action, mods);
		}
		void render(StateManager& s) override
		{
			return reinterpret_cast<void(__thiscall*)(StateSingleplayer * self, StateManager&)>(getFuncAddr((int)Func::StateSingleplayer::render))(this, s);
		}
		void scrollInput(StateManager& s, double xoffset, double yoffset) override
		{
			return reinterpret_cast<void(__thiscall*)(StateSingleplayer * self, StateManager&, double, double)>(getFuncAddr((int)Func::StateSingleplayer::scrollInput))(this, s, xoffset, yoffset);
		}
		void mouseInput(StateManager& s, double xpos, double ypos) override
		{
			return reinterpret_cast<void(__thiscall*)(StateSingleplayer * self, StateManager&, double, double)>(getFuncAddr((int)Func::StateSingleplayer::mouseInput))(this, s, xpos, ypos);
		}
		StateSingleplayer() 
		{
			reinterpret_cast<void(__thiscall*)(StateSingleplayer* self)>(getFuncAddr((int)Func::StateSingleplayer::StateSingleplayer))(this);
		}
		void updateWorldListContainer(int wWidth, int wHeight) 
		{
			return reinterpret_cast<void (__thiscall*)(StateSingleplayer* self, int wWidth, int wHeight)>(getFuncAddr((int)Func::StateSingleplayer::updateWorldListContainer))(this, wWidth, wHeight);
		}
		inline static void createCallback(void* user) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user)>(getFuncAddr((int)Func::StateSingleplayer::createCallback))(user);
		}
		inline static void viewportCallback(void* user, const glm::ivec4& pos, const glm::ivec2& scroll) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, const glm::ivec4& pos, const glm::ivec2& scroll)>(getFuncAddr((int)Func::StateSingleplayer::viewportCallback))(user, pos, scroll);
		}
		inline static void worldButtonCallback(void* user) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user)>(getFuncAddr((int)Func::StateSingleplayer::worldButtonCallback))(user);
		}
		inline static void cancelCallback(void* user)
		{
			return reinterpret_cast<void(__fastcall*)(void*)>(getFuncAddr((int)Func::StateSingleplayer::cancelCallback))(user);
		}
		void init(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateSingleplayer* self, StateManager& s)>(getFuncAddr((int)Func::StateSingleplayer::init))(this, s);
		}
		void close(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateSingleplayer* self, StateManager& s)>(getFuncAddr((int)Func::StateSingleplayer::close))(this, s);
		}
		void update(StateManager& s, double dt) override
		{
			return reinterpret_cast<void (__thiscall*)(StateSingleplayer* self, StateManager& s, double dt)>(getFuncAddr((int)Func::StateSingleplayer::update))(this, s, dt);
		}
		void resume(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateSingleplayer* self, StateManager& s)>(getFuncAddr((int)Func::StateSingleplayer::resume))(this, s);
		}
		void windowResize(StateManager& s, int width, int height) override
		{
			return reinterpret_cast<void (__thiscall*)(StateSingleplayer* self, StateManager& s, int width, int height)>(getFuncAddr((int)Func::StateSingleplayer::windowResize))(this, s, width, height);
		}
		void queueWorldLoad(stl::string& path) 
		{
			return reinterpret_cast<void (__thiscall*)(StateSingleplayer* self, stl::string& path)>(getFuncAddr((int)Func::StateSingleplayer::queueWorldLoad))(this, path);
		}
	};
}
