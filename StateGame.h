#pragma once

#include "4dm.h"
#include "CloudManager.h"

namespace fdm 
{
	class StateGame : public State 
	{
	public:
		inline static StateGame* instanceObj = reinterpret_cast<StateGame*>((base + 0x2BE5E0));
		std::unique_ptr<WorldManager,std::default_delete<WorldManager> > world; // 0x8
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
		float lastChatMessageTime; // 0xAB0

		StateGame() 
		{
			reinterpret_cast<void(__thiscall*)(StateGame* self)>(FUNC_STATEGAME_STATEGAME)(this);
		}
		void resetMouse(GLFWwindow* w) 
		{
			return reinterpret_cast<void (__thiscall*)(StateGame* self, GLFWwindow* w)>(FUNC_STATEGAME_RESETMOUSE)(this, w);
		}
		void updateProjection2D(const glm::ivec2& size, const glm::ivec2& translate2D) 
		{
			return reinterpret_cast<void (__thiscall*)(StateGame* self, const glm::ivec2& size, const glm::ivec2& translate2D)>(FUNC_STATEGAME_UPDATEPROJECTION2D)(this, size, translate2D);
		}
		inline static void viewportCallback(void* user, const glm::ivec4& pos, const glm::ivec2& scroll) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, const glm::ivec4& pos, const glm::ivec2& scroll)>(FUNC_STATEGAME_VIEWPORTCALLBACK)(user, pos, scroll);
		}
		void updateChatMessages() 
		{
			return reinterpret_cast<void (__thiscall*)(StateGame* self)>(FUNC_STATEGAME_UPDATECHATMESSAGES)(this);
		}
		void init(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateGame* self, StateManager& s)>(FUNC_STATEGAME_INIT)(this, s);
		}
		void close(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateGame* self, StateManager& s)>(FUNC_STATEGAME_CLOSE)(this, s);
		}
		void pause(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateGame* self, StateManager& s)>(FUNC_STATEGAME_PAUSE)(this, s);
		}
		void resume(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateGame* self, StateManager& s)>(FUNC_STATEGAME_RESUME)(this, s);
		}
		void update(StateManager& s, double dt) override
		{
			return reinterpret_cast<void (__thiscall*)(StateGame* self, StateManager& s, double dt)>(FUNC_STATEGAME_UPDATE)(this, s, dt);
		}
		void render(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateGame* self, StateManager& s)>(FUNC_STATEGAME_RENDER)(this, s);
		}
		void mouseInput(StateManager& s, double xpos, double ypos) override
		{
			return reinterpret_cast<void (__thiscall*)(StateGame* self, StateManager& s, double xpos, double ypos)>(FUNC_STATEGAME_MOUSEINPUT)(this, s, xpos, ypos);
		}
		void scrollInput(StateManager& s, double xoffset, double yoffset) override
		{
			return reinterpret_cast<void (__thiscall*)(StateGame* self, StateManager& s, double xoffset, double yoffset)>(FUNC_STATEGAME_SCROLLINPUT)(this, s, xoffset, yoffset);
		}
		void mouseButtonInput(StateManager& s, int button, int action, int mods) override
		{
			return reinterpret_cast<void (__thiscall*)(StateGame* self, StateManager& s, int button, int action, int mods)>(FUNC_STATEGAME_MOUSEBUTTONINPUT)(this, s, button, action, mods);
		}
		void keyInput(StateManager& s, int key, int scancode, int action, int mods) override
		{
			return reinterpret_cast<void (__thiscall*)(StateGame* self, StateManager& s, int key, int scancode, int action, int mods)>(FUNC_STATEGAME_KEYINPUT)(this, s, key, scancode, action, mods);
		}
		void windowResize(StateManager& s, GLsizei width, GLsizei height) override
		{
			return reinterpret_cast<void (__thiscall*)(StateGame* self, StateManager& s, GLsizei width, GLsizei height)>(FUNC_STATEGAME_WINDOWRESIZE)(this, s, width, height);
		}
		void charInput(StateManager& s, uint32_t codepoint) override
		{
			return reinterpret_cast<void (__thiscall*)(StateGame* self, StateManager& s, uint32_t codepoint)>(FUNC_STATEGAME_CHARINPUT)(this, s, codepoint);
		}
		void updateProjection(GLsizei width, GLsizei height) 
		{
			return reinterpret_cast<void (__thiscall*)(StateGame* self, GLsizei width, GLsizei height)>(FUNC_STATEGAME_UPDATEPROJECTION)(this, width, height);
		}
		void setWorld(std::unique_ptr<WorldManager>& world) 
		{
			return reinterpret_cast<void (__thiscall*)(StateGame* self, std::unique_ptr<WorldManager>& world)>(FUNC_STATEGAME_SETWORLD)(this, world);
		}
		void addChatMessage(Player* player, const std::string& message, uint32_t color) 
		{
			return reinterpret_cast<void (__thiscall*)(StateGame* self, Player* player, const std::string& message, uint32_t color)>(FUNC_STATEGAME_ADDCHATMESSAGE)(this, player, message, color);
		}
	};
}
