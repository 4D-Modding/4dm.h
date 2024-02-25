#pragma once

#include "4dm.h"

namespace fdm 
{
	class StateTutorial : public State 
	{
	public:
		enum PlayerState
		{
			PLAYER_IDLE = 0x0,
			PLAYER_WALKING = 0x1,
			PLAYER_FALLING = 0x2,
		};

		enum PlayerDirection
		{
			PLAYER_DIRECTION_RIGHT = 0x0,
			PLAYER_DIRECTION_LEFT = 0x1,
		};

		struct blockVert3D 
		{
			glm::u8vec3 vert; 
			glm::u8vec3 uv; // 0x3
			uint32_t lighting; // 0x6
		};

		inline static const float _zero = 1e-08f; 
		inline static StateTutorial* instanceObj = reinterpret_cast<StateTutorial*>((base + 0x2C2860));
		bool updateViewFlag; // 0x8
		PAD(0x3);
		glm::mat4 projection3D; // 0xC
		glm::mat4 projection2D; // 0x4C
		PAD(0x4);
		FontRenderer font; // 0x90
		TexRenderer forgRenderer; // 0x130
		QuadRenderer qr; // 0x158
		const Shader* qs; // 0x180
		gui::Interface ui; // 0x188
		gui::Button backButton; // 0x1F0
		gui::Button nextButton; // 0x248
		std::vector<StateTutorial::blockVert3D> block_verts_3d; // 0x2A0
		std::vector<uint32_t> block_indices_3d; // 0x2B8
		MeshBuilder mesh3d; // 0x2D0
		MeshRenderer mr3d; // 0x308
		MeshBuilder worldCubeMesh; // 0x328
		MeshRenderer worldCubeRenderer; // 0x360
		glm::i8vec3 forg_verts[6]; // 0x380
		glm::u8vec3 forg_uvs[6]; // 0x392
		glm::u8vec3 forg_outline_uvs[6]; // 0x3A4
		PAD(0x2);
		MeshBuilder forgMesh3D; // 0x3B8
		MeshRenderer forgRenderer3D; // 0x3F0
		MeshBuilder forgOutlineMesh3D; // 0x410
		MeshRenderer forgOutlineRenderer3D; // 0x448
		std::vector<glm::u8vec3> block_verts_2d; // 0x468
		std::vector<glm::u8vec4> block_tuvs_2d; // 0x480
		std::vector<uint32_t> block_indices_2d; // 0x498
		MeshBuilder mesh2d; // 0x4B0
		MeshRenderer mr2d; // 0x4E8
		inline static const int demo_size = 16; 
		unsigned char blocks[demo_size][demo_size][demo_size]; 
		struct 
		{
			glm::vec3 pos; 
			float headPos; // 0xC
			glm::vec3 vel; // 0x10
			glm::mat4 orientation; // 0x1C
			glm::vec3 forward; // 0x5C
			glm::vec3 up; // 0x68
			glm::vec3 right; // 0x74
			float angleToRotate; // 0x80
			glm::ivec3 currentBlock; // 0x84
			glm::ivec3 lastCollision; // 0x90
			StateTutorial::PlayerState currentState; // 0x9C
			StateTutorial::PlayerDirection currentDirection; // 0xA0
			PAD(0x4);
			double stateStartTime; // 0xA8
		} player;
		struct 
		{
			bool w; 
			bool a; // 0x1
			bool s; // 0x2
			bool d; // 0x3
			bool space; // 0x4
		} keys;
		PAD(0x3);
		glm::vec2 rotation3D; // 0x15C0
		bool mouseDown3D; // 0x15C8
		PAD(0x3);
		glm::vec2 lastDragPos; // 0x15CC

		~StateTutorial() 
		{
			reinterpret_cast<void(__thiscall*)(StateTutorial* self)>(getFuncAddr((int)Func::StateTutorial::destr_StateTutorial))(this);
		}
		StateTutorial() 
		{
			reinterpret_cast<void(__thiscall*)(StateTutorial* self)>(getFuncAddr((int)Func::StateTutorial::StateTutorial))(this);
		}
		void updateProjection(const glm::ivec2& size, const glm::ivec2& translate2D) 
		{
			return reinterpret_cast<void (__thiscall*)(StateTutorial* self, const glm::ivec2& size, const glm::ivec2& translate2D)>(getFuncAddr((int)Func::StateTutorial::updateProjection))(this, size, translate2D);
		}
		inline static void backButtonCallback(void* user) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user)>(getFuncAddr((int)Func::StateTutorial::backButtonCallback))(user);
		}
		inline static void nextButtonCallback(void* user) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user)>(getFuncAddr((int)Func::StateTutorial::nextButtonCallback))(user);
		}
		void generateMesh() 
		{
			return reinterpret_cast<void (__thiscall*)(StateTutorial* self)>(getFuncAddr((int)Func::StateTutorial::generateMesh))(this);
		}
		void getSmoothLighting(const glm::ivec3& block, unsigned char face, unsigned char* lighting) 
		{
			return reinterpret_cast<void (__thiscall*)(StateTutorial* self, const glm::ivec3& block, unsigned char face, unsigned char* lighting)>(getFuncAddr((int)Func::StateTutorial::getSmoothLighting))(this, block, face, lighting);
		}
		void updatePlayerComponentVectors() 
		{
			return reinterpret_cast<void (__thiscall*)(StateTutorial* self)>(getFuncAddr((int)Func::StateTutorial::updatePlayerComponentVectors))(this);
		}
		void updatePlayerPos() 
		{
			return reinterpret_cast<void (__thiscall*)(StateTutorial* self)>(getFuncAddr((int)Func::StateTutorial::updatePlayerPos))(this);
		}
		void updateCurrentBlock() 
		{
			return reinterpret_cast<void (__thiscall*)(StateTutorial* self)>(getFuncAddr((int)Func::StateTutorial::updateCurrentBlock))(this);
		}
		bool handleCollision(const glm::vec3& foot, const glm::vec3& head, uint32_t face) 
		{
			return reinterpret_cast<bool (__thiscall*)(StateTutorial* self, const glm::vec3& foot, const glm::vec3& head, uint32_t face)>(getFuncAddr((int)Func::StateTutorial::handleCollision))(this, foot, head, face);
		}
		void setForgSprite(int x, int y) 
		{
			return reinterpret_cast<void (__thiscall*)(StateTutorial* self, int x, int y)>(getFuncAddr((int)Func::StateTutorial::setForgSprite))(this, x, y);
		}
		void init(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateTutorial* self, StateManager& s)>(getFuncAddr((int)Func::StateTutorial::init))(this, s);
		}
		void close(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateTutorial* self, StateManager& s)>(getFuncAddr((int)Func::StateTutorial::close))(this, s);
		}
		void update(StateManager& s, double dt) override
		{
			return reinterpret_cast<void (__thiscall*)(StateTutorial* self, StateManager& s, double dt)>(getFuncAddr((int)Func::StateTutorial::update))(this, s, dt);
		}
		void render(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateTutorial* self, StateManager& s)>(getFuncAddr((int)Func::StateTutorial::render))(this, s);
		}
		void resume(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateTutorial* self, StateManager& s)>(getFuncAddr((int)Func::StateTutorial::resume))(this, s);
		}
		void mouseInput(StateManager& s, double xpos, double ypos) override
		{
			return reinterpret_cast<void (__thiscall*)(StateTutorial* self, StateManager& s, double xpos, double ypos)>(getFuncAddr((int)Func::StateTutorial::mouseInput))(this, s, xpos, ypos);
		}
		void scrollInput(StateManager& s, double xoffset, double yoffset) override
		{
			return reinterpret_cast<void (__thiscall*)(StateTutorial* self, StateManager& s, double xoffset, double yoffset)>(getFuncAddr((int)Func::StateTutorial::scrollInput))(this, s, xoffset, yoffset);
		}
		void mouseButtonInput(StateManager& s, int button, int action, int mods) override
		{
			return reinterpret_cast<void (__thiscall*)(StateTutorial* self, StateManager& s, int button, int action, int mods)>(getFuncAddr((int)Func::StateTutorial::mouseButtonInput))(this, s, button, action, mods);
		}
		void keyInput(StateManager& s, int key, int scancode, int action, int mods) override
		{
			return reinterpret_cast<void (__thiscall*)(StateTutorial* self, StateManager& s, int key, int scancode, int action, int mods)>(getFuncAddr((int)Func::StateTutorial::keyInput))(this, s, key, scancode, action, mods);
		}
		void windowResize(StateManager& s, int width, int height) override
		{
			return reinterpret_cast<void (__thiscall*)(StateTutorial* self, StateManager& s, int width, int height)>(getFuncAddr((int)Func::StateTutorial::windowResize))(this, s, width, height);
		}
		void charInput(StateManager& s, uint32_t codepoint) override
		{
			return reinterpret_cast<void (__thiscall*)(StateTutorial* self, StateManager& s, uint32_t codepoint)>(getFuncAddr((int)Func::StateTutorial::charInput))(this, s, codepoint);
		}
		void updateViewport(GLFWwindow* w, const glm::ivec4& pos, const glm::ivec2& scroll) 
		{
			return reinterpret_cast<void (__thiscall*)(StateTutorial* self, GLFWwindow* w, const glm::ivec4& pos, const glm::ivec2& scroll)>(getFuncAddr((int)Func::StateTutorial::updateViewport))(this, w, pos, scroll);
		}
	};
}
