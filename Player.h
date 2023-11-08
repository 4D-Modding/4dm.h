#pragma once

#include "4dm.h"
#include "InventoryGrid.h"
#include "InventoryManager.h"
#include "InventoryPlayer.h"
#include "m4.h"
#include "MeshRenderer.h"
#include "TexRenderer.h"
#include "FontRenderer.h"

namespace fdm 
{
	class EntityPlayer;
	class InventoryGrid;
	class InventoryManager;
	class InventoryPlayer;
	class MeshRenderer;
	class TexRenderer;
	class FontRenderer;
	class World;
	class Item;

	class Player 
	{
	public:
		inline static const float Z_NEAR = 0.003f; 
		inline static const float Z_FAR = 1000.f; 
		inline static const float HEIGHT = 1.8f; 
		inline static const float ACC = 25.f; 
		inline static const float FRIC = 15.f; 
		inline static const float MAX_WALK_SPEED = 5.f; 
		inline static const float MAX_CROUCH_SPEED = 2.f; 
		inline static const float MAX_SPRINT_SPEED = 8.f; 
		inline static const float JUMP_VEL = 12.f; 
		inline static const float DAMAGE_COOLDOWN = 1.2f; 
		inline static const glm::ivec4* defaultSpawnPos = reinterpret_cast<const glm::ivec4*>((base + 0x2B3508));
		uuid EntityPlayerID; 
		struct 
		{
			bool w; 
			bool a; // 0x1
			bool s; // 0x2
			bool d; // 0x3
			bool x; // 0x4
			bool z; // 0x5
			bool q; // 0x6
			bool e; // 0x7
			bool m; // 0x8
			bool space; // 0x9
			bool shift; // 0xA
			bool ctrl; // 0xB
			bool leftMouseDown; // 0xC
			bool rightMouseDown; // 0xD
			bool middleMouseDown; // 0xE
		} keys;
		bool touchingGround; // 0x1F
		uint8_t groundBlock; // 0x20
		bool crouching; // 0x21
		bool sprinting; // 0x22
		bool walking; // 0x23
		bool keepOnEdge; // 0x24
		PAD(0x3);
		glm::vec4 pos; // 0x28
		float headPos; // 0x38
		glm::vec4 cameraPos; // 0x3C
		PAD(0x4);
		double walkStartTime; // 0x50
		float walkAnimOffset; // 0x58
		float walkAnimTheta; // 0x5C
		double mineStartTime; // 0x60
		float mineAnimTheta; // 0x68
		glm::ivec4 currentBlock; // 0x6C
		glm::vec4 forward; // 0x7C
		glm::vec4 up; // 0x8C
		glm::vec4 left; // 0x9C
		glm::vec4 over; // 0xAC
		glm::vec3 anchorPoint; // 0xBC
		glm::vec4 lastChunkPos; // 0xC8
		double lastChunkUpdateTime; // 0xD8
		bool hyperplaneUpdateFlag; // 0xE0
		PAD(0x3);
		glm::vec4 lastChunkOver; // 0xE4
		uint8_t renderDistance; // 0xF4
		PAD(0x3);
		m4::Mat5 orientation; // 0xF8
		glm::vec4 vel; // 0x15C
		glm::vec4 deltaVel; // 0x16C
		float angleToRotate; // 0x17C
		double mouseX; // 0x180
		double mouseY; // 0x188
		double mouseDownTime; // 0x190
		glm::ivec4 targetBlock; // 0x198
		bool targetingBlock; // 0x1A8
		PAD(0x3);
		float targetDamage; // 0x1AC
		glm::ivec4 targetPlaceBlock; // 0x1B0
		bool canPlace; // 0x1C0
		bool alreadyPlaced; // 0x1C1
		PAD(0x2);
		glm::vec4 reachEndpoint; // 0x1C4
		PAD(0x4);
		InventoryGrid hotbar; // 0x1D8
		InventoryGrid equipment; // 0x258
		InventoryGrid inventory; // 0x2D8
		InventoryPlayer inventoryAndEquipment; // 0x358
		InventoryPlayer playerInventory; // 0x398
		InventoryManager inventoryManager; // 0x3D8
		bool shouldResetMouse; // 0x5D8
		inline static const float maxHealth = 100.f; 
		PAD(0x3);
		float health; // 0x5DC
		inline static const double leftClickActionCooldown = 0.8f;
		inline static const double rightClickActionCooldown = 0.5f;
		double leftClickActionTime; // 0x5E0
		double rightClickActionTime; // 0x5E8
		double damageTime; // 0x5F0
		inline static MeshRenderer* targetBlockRenderer = reinterpret_cast<MeshRenderer*>((base + 0x279640));
		inline static TexRenderer* healthRenderer = reinterpret_cast<TexRenderer*>((base + 0x2BFA80));
		inline static FontRenderer* fr = reinterpret_cast<FontRenderer*>((base + 0x279660));
		int headBlock; // 0x5F8

		~Player() 
		{
			reinterpret_cast<void(__thiscall*)(Player* self)>(FUNC_PLAYER_DESTR_PLAYER)(this);
		}
		Player() 
		{
			reinterpret_cast<void(__thiscall*)(Player* self)>(FUNC_PLAYER_PLAYER)(this);
		}
		void updatePos(World* world, double dt) 
		{
			return reinterpret_cast<void (__thiscall*)(Player* self, World* world, double dt)>(FUNC_PLAYER_UPDATEPOS)(this, world, dt);
		}
		void updateCurrentBlock() 
		{
			return reinterpret_cast<void (__thiscall*)(Player* self)>(FUNC_PLAYER_UPDATECURRENTBLOCK)(this);
		}
		void handleCollision(World* world) 
		{
			return reinterpret_cast<void (__thiscall*)(Player* self, World* world)>(FUNC_PLAYER_HANDLECOLLISION)(this, world);
		}
		void updateComponentVectors() 
		{
			return reinterpret_cast<void (__thiscall*)(Player* self)>(FUNC_PLAYER_UPDATECOMPONENTVECTORS)(this);
		}
		void updateAllComponentVectors() 
		{
			return reinterpret_cast<void (__thiscall*)(Player* self)>(FUNC_PLAYER_UPDATEALLCOMPONENTVECTORS)(this);
		}
		void removeVelComp(uint32_t comp) 
		{
			return reinterpret_cast<void (__thiscall*)(Player* self, uint32_t comp)>(FUNC_PLAYER_REMOVEVELCOMP)(this, comp);
		}
		void updateTargetBlock(World* world, float maxDist) 
		{
			return reinterpret_cast<void (__thiscall*)(Player* self, World* world, float maxDist)>(FUNC_PLAYER_UPDATETARGETBLOCK)(this, world, maxDist);
		}
		void init(const glm::ivec4& spawnPoint) 
		{
			return reinterpret_cast<void (__thiscall*)(Player* self, const glm::ivec4& spawnPoint)>(FUNC_PLAYER_INIT)(this, spawnPoint);
		}
		void renderHud(GLFWwindow* window) 
		{
			return reinterpret_cast<void (__thiscall*)(Player* self, GLFWwindow* window)>(FUNC_PLAYER_RENDERHUD)(this, window);
		}
		void renderTargetBlock(const m4::Mat5& MV, bool renderBG) 
		{
			return reinterpret_cast<void (__thiscall*)(Player* self, const m4::Mat5& MV, bool renderBG)>(FUNC_PLAYER_RENDERTARGETBLOCK)(this, MV, renderBG);
		}
		nlohmann::json getMovementUpdate() 
		{
			nlohmann::json result;
			return reinterpret_cast<nlohmann::json (__thiscall*)(Player* self, nlohmann::json* result)>(FUNC_PLAYER_GETMOVEMENTUPDATE)(this, &result);
		}
		void setMovementBehavior(nlohmann::json& movementKeys, bool keepOnEdge) 
		{
			return reinterpret_cast<void (__thiscall*)(Player* self, nlohmann::json& movementKeys, bool keepOnEdge)>(FUNC_PLAYER_SETMOVEMENTBEHAVIOR)(this, movementKeys, keepOnEdge);
		}
		void hitTargetBlock(World* world) 
		{
			return reinterpret_cast<void (__thiscall*)(Player* self, World* world)>(FUNC_PLAYER_HITTARGETBLOCK)(this, world);
		}
		bool breakBlock(World* world) 
		{
			return reinterpret_cast<bool (__thiscall*)(Player* self, World* world)>(FUNC_PLAYER_BREAKBLOCK)(this, world);
		}
		void throwItem(World* world, std::unique_ptr<Item>& item, uint32_t maxCount) 
		{
			return reinterpret_cast<void (__thiscall*)(Player* self, World* world, std::unique_ptr<Item>& item, uint32_t maxCount)>(FUNC_PLAYER_THROWITEM)(this, world, item, maxCount);
		}
		void update(World* world, double dt, EntityPlayer* entityPlayer) 
		{
			return reinterpret_cast<void (__thiscall*)(Player* self, World* world, double dt, EntityPlayer* entityPlayer)>(FUNC_PLAYER_UPDATE)(this, world, dt, entityPlayer);
		}
		void updateLocal(World* world, double dt, GLFWwindow* window) 
		{
			return reinterpret_cast<void (__thiscall*)(Player* self, World* world, double dt, GLFWwindow* window)>(FUNC_PLAYER_UPDATELOCAL)(this, world, dt, window);
		}
		void updateCameraPos(World* world) 
		{
			return reinterpret_cast<void (__thiscall*)(Player* self, World* world)>(FUNC_PLAYER_UPDATECAMERAPOS)(this, world);
		}
		void resetMouse(GLFWwindow* window) 
		{
			return reinterpret_cast<void (__thiscall*)(Player* self, GLFWwindow* window)>(FUNC_PLAYER_RESETMOUSE)(this, window);
		}
		bool keyInput(GLFWwindow* window, World* world, int key, int scancode, int action, char mods) 
		{
			return reinterpret_cast<bool (__thiscall*)(Player* self, GLFWwindow* window, World* world, int key, int scancode, int action, char mods)>(FUNC_PLAYER_KEYINPUT)(this, window, world, key, scancode, action, mods);
		}
		void mouseInput(GLFWwindow* window, World* world, double xpos, double ypos) 
		{
			return reinterpret_cast<void (__thiscall*)(Player* self, GLFWwindow* window, World* world, double xpos, double ypos)>(FUNC_PLAYER_MOUSEINPUT)(this, window, world, xpos, ypos);
		}
		void mouseButtonInput(GLFWwindow* window, World* world, int button, int action, int mods) 
		{
			return reinterpret_cast<void (__thiscall*)(Player* self, GLFWwindow* window, World* world, int button, int action, int mods)>(FUNC_PLAYER_MOUSEBUTTONINPUT)(this, window, world, button, action, mods);
		}
		bool isHoldingGlasses() 
		{
			return reinterpret_cast<bool (__thiscall*)(Player* self)>(FUNC_PLAYER_ISHOLDINGGLASSES)(this);
		}
		bool isHoldingCompass() 
		{
			return reinterpret_cast<bool (__thiscall*)(Player* self)>(FUNC_PLAYER_ISHOLDINGCOMPASS)(this);
		}
		bool isHoldingCollector() 
		{
			return reinterpret_cast<bool (__thiscall*)(Player* self)>(FUNC_PLAYER_ISHOLDINGCOLLECTOR)(this);
		}
		bool headIsInBlock() 
		{
			return reinterpret_cast<bool (__thiscall*)(Player* self)>(FUNC_PLAYER_HEADISINBLOCK)(this);
		}
		uint32_t getHeadBlock() 
		{
			return reinterpret_cast<uint32_t (__thiscall*)(Player* self)>(FUNC_PLAYER_GETHEADBLOCK)(this);
		}
		void respawn(World* world, const glm::ivec4& spawnPoint) 
		{
			return reinterpret_cast<void (__thiscall*)(Player* self, World* world, const glm::ivec4& spawnPoint)>(FUNC_PLAYER_RESPAWN)(this, world, spawnPoint);
		}
		void load(nlohmann::json& j) 
		{
			return reinterpret_cast<void (__thiscall*)(Player* self, nlohmann::json& j)>(FUNC_PLAYER_LOAD)(this, j);
		}
		nlohmann::json save() 
		{
			nlohmann::json result;
			return reinterpret_cast<nlohmann::json (__thiscall*)(Player* self, nlohmann::json* result)>(FUNC_PLAYER_SAVE)(this, &result);
		}
		void loadClientData(nlohmann::json& j) 
		{
			return reinterpret_cast<void (__thiscall*)(Player* self, nlohmann::json& j)>(FUNC_PLAYER_LOADCLIENTDATA)(this, j);
		}
		nlohmann::json saveClientData() 
		{
			nlohmann::json result;
			return reinterpret_cast<nlohmann::json (__thiscall*)(Player* self, nlohmann::json* result)>(FUNC_PLAYER_SAVECLIENTDATA)(this, &result);
		}
		nlohmann::json saveOrientation() 
		{
			nlohmann::json result;
			return reinterpret_cast<nlohmann::json (__thiscall*)(Player* self, nlohmann::json* result)>(FUNC_PLAYER_SAVEORIENTATION)(this,& result);
		}
	};
}
