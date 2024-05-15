#pragma once

#include "4dm.h"
#include "CloudManager.h"

namespace fdm 
{
	class StateGame : public State 
	{
	public:
		inline static StateGame* instanceObj = reinterpret_cast<StateGame*>((base + 0x2BE5E0));
		std::unique_ptr<WorldManager> world; // 0x8
		CloudManager clouds; // 0x10
		glm::mat4 projection2D; // 0xB0
		glm::mat4 projection3D; // 0xF0
		Shader* cloudShader; // 0x130
		uint32_t cloudmvID; // 0x138
		uint32_t cloudBlendID; // 0x13C
		MeshRenderer skyboxRenderer; // 0x140
		Shader* moonShader; // 0x160
		Tex2D* moonTex; // 0x168
		uint32_t moonmvID; // 0x170
		PAD(0x4);
		MeshRenderer moonRenderer; // 0x178
		Shader* tex2DShader; // 0x198
		TexRenderer crosshairRenderer; // 0x1A0
		Shader* blockShader; // 0x1C8
		Framebuffer renderFramebuffer; // 0x1D0
		float time; // 0x220
		PAD(0x4);
		Player player; // 0x228
		glm::dvec2 initialCursorPos; // 0x828
		float cloudRenderDistance; // 0x838
		float FOV; // 0x83C
		bool smoothLighting; // 0x840
		bool shadows; // 0x841
		bool lights; // 0x842
		PAD(0x5);
		FontRenderer font; // 0x848
		QuadRenderer qr; // 0x8E8
		gui::Interface ui; // 0x910
		bool updateViewFlag; // 0x978
		inline static const int MESSAGE_DISPLAY_MAX = 100; 
		PAD(0x7);
		std::vector<std::unique_ptr<gui::Text>> chatMessages; // 0x980
		gui::ContentBox chatMessageContainer; // 0x998
		gui::TextInput chatInput; // 0xA18
		bool chatOpen; // 0xAA8
		bool chatReady; // 0xAA9
		PAD(0x6);
		double lastChatMessageTime; // 0xAB0

		StateGame() 
		{
			reinterpret_cast<void(__thiscall*)(StateGame* self)>(getFuncAddr((int)Func::StateGame::StateGame))(this);
		}
		void resetMouse(GLFWwindow* w) 
		{
			return reinterpret_cast<void (__thiscall*)(StateGame* self, GLFWwindow* w)>(getFuncAddr((int)Func::StateGame::resetMouse))(this, w);
		}
		void updateProjection2D(const glm::ivec2& size, const glm::ivec2& translate2D) 
		{
			return reinterpret_cast<void (__thiscall*)(StateGame* self, const glm::ivec2& size, const glm::ivec2& translate2D)>(getFuncAddr((int)Func::StateGame::updateProjection2D))(this, size, translate2D);
		}
		inline static void viewportCallback(void* user, const glm::ivec4& pos, const glm::ivec2& scroll) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, const glm::ivec4& pos, const glm::ivec2& scroll)>(getFuncAddr((int)Func::StateGame::viewportCallback))(user, pos, scroll);
		}
		void updateChatMessages() 
		{
			return reinterpret_cast<void (__thiscall*)(StateGame* self)>(getFuncAddr((int)Func::StateGame::updateChatMessages))(this);
		}
		void init(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateGame* self, StateManager& s)>(getFuncAddr((int)Func::StateGame::init))(this, s);
		}
		void close(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateGame* self, StateManager& s)>(getFuncAddr((int)Func::StateGame::close))(this, s);
		}
		void pause(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateGame* self, StateManager& s)>(getFuncAddr((int)Func::StateGame::pause))(this, s);
		}
		void resume(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateGame* self, StateManager& s)>(getFuncAddr((int)Func::StateGame::resume))(this, s);
		}
		void update(StateManager& s, double dt) override
		{
			return reinterpret_cast<void (__thiscall*)(StateGame* self, StateManager& s, double dt)>(getFuncAddr((int)Func::StateGame::update))(this, s, dt);
		}
		void render(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateGame* self, StateManager& s)>(getFuncAddr((int)Func::StateGame::render))(this, s);
		}
		void mouseInput(StateManager& s, double xpos, double ypos) override
		{
			return reinterpret_cast<void (__thiscall*)(StateGame* self, StateManager& s, double xpos, double ypos)>(getFuncAddr((int)Func::StateGame::mouseInput))(this, s, xpos, ypos);
		}
		void scrollInput(StateManager& s, double xoffset, double yoffset) override
		{
			return reinterpret_cast<void (__thiscall*)(StateGame* self, StateManager& s, double xoffset, double yoffset)>(getFuncAddr((int)Func::StateGame::scrollInput))(this, s, xoffset, yoffset);
		}
		void mouseButtonInput(StateManager& s, int button, int action, int mods) override
		{
			return reinterpret_cast<void (__thiscall*)(StateGame* self, StateManager& s, int button, int action, int mods)>(getFuncAddr((int)Func::StateGame::mouseButtonInput))(this, s, button, action, mods);
		}
		void keyInput(StateManager& s, int key, int scancode, int action, int mods) override
		{
			return reinterpret_cast<void (__thiscall*)(StateGame* self, StateManager& s, int key, int scancode, int action, int mods)>(getFuncAddr((int)Func::StateGame::keyInput))(this, s, key, scancode, action, mods);
		}
		void windowResize(StateManager& s, GLsizei width, GLsizei height) override
		{
			return reinterpret_cast<void (__thiscall*)(StateGame* self, StateManager& s, GLsizei width, GLsizei height)>(getFuncAddr((int)Func::StateGame::windowResize))(this, s, width, height);
		}
		void charInput(StateManager& s, uint32_t codepoint) override
		{
			return reinterpret_cast<void (__thiscall*)(StateGame* self, StateManager& s, uint32_t codepoint)>(getFuncAddr((int)Func::StateGame::charInput))(this, s, codepoint);
		}
		void updateProjection(GLsizei width, GLsizei height) 
		{
			return reinterpret_cast<void (__thiscall*)(StateGame* self, GLsizei width, GLsizei height)>(getFuncAddr((int)Func::StateGame::updateProjection))(this, width, height);
		}
		void setWorld(std::unique_ptr<WorldManager>& world) 
		{
			return reinterpret_cast<void (__thiscall*)(StateGame* self, std::unique_ptr<WorldManager>& world)>(getFuncAddr((int)Func::StateGame::setWorld))(this, world);
		}
		void addChatMessage(Player* player, const stl::string& message, uint32_t color) 
		{
			return reinterpret_cast<void (__thiscall*)(StateGame* self, Player* player, const stl::string& message, uint32_t color)>(getFuncAddr((int)Func::StateGame::addChatMessage))(this, player, message, color);
		}
	};
}
