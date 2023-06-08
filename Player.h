#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "4dm.h"
#include "InventoryGUI.h"
#include "PlayerInventoryManager.h"
#include "Inventory.h"
namespace fdm
{
	class TexRenderer;
	class FontRenderer;
	class Inventory;
	class PlayerInventoryManager;
	class Item;
	class Player
	{
	public:
        inline static const float zNear = 0.01f; // idk???
        inline static const float zFar = 1000.0f; // idk???
        inline static const float height = 2.f; // idk???
        inline static const float acc = 0.f; // idk???
        inline static const float fric = 0.f; // idk???
        inline static const float maxWalkSpeed = 0.f; // idk???
        inline static const float maxCrouchSpeed = 0.f; // idk???
        inline static const float maxSprintSpeed = 0.f; // idk???
        inline static const glm::vec4 defaultSpawnPos;
        inline static const float maxHealth = 1.f; // idk???
        inline static const float hitCooldown = 0.f; // idk???
        inline static const float damageCooldown = 0.f; // idk???

        inline static TexRenderer getHealthRenderer() // healthRenderer
        {
            return *(reinterpret_cast<TexRenderer*>((base + 0x1BF070)));
        }
        inline static FontRenderer getFontRenderer() // fr
        {
            return *(reinterpret_cast<FontRenderer*>((base + 0x17C120)));
        }
        //inline static TexRenderer healthRenderer;
        //inline static FontRenderer fr;

        struct
        {
            bool w;
            bool a;
            bool s;
            bool d;
            bool x;
            bool z;
            bool q;
            bool e;
            bool space;
            bool shift;
            bool ctrl;
            bool leftMouseDown;
            bool rightMouseDown;
        } keys;

        PAD(3);
        float scrollFactor;
        float lookSensitivity;
        bool touchingGround;
        unsigned char groundBlock;
        bool crouching;
        bool sprinting;
        bool walking;
        PAD(3);
        glm::vec4 pos;
        float headPos;
        glm::vec4 cameraPos;
        PAD(4);
        double walkStartTime;
        float walkAnimOffset;
        float walkAnimTheta;
        double mineStartTime;
        float mineAnimTheta;
        glm::ivec4 currentBlock;
        glm::vec4 lastChunkPos;
        bool hyperplaneUpdateFlag;
        PAD(3);
        glm::vec4 forward;
        glm::vec4 up;
        glm::vec4 right;
        glm::vec4 over;
        m4::Mat5 orientation;
        glm::vec4 vel;
        glm::vec4 deltaVel;
        float angleToRotate;
        double mouseX;
        double mouseY;
        double mouseDownTime;
        double placeTime;
        glm::ivec4 targetBlock;
        bool targetingBlock;
        PAD(7);
        double targetTime;
        float targetDamage;
        glm::ivec4 targetPlaceBlock;
        bool canPlace;
        bool alreadyPlaced;
        PAD(2);
        glm::vec4 reachEndpoint;
        Inventory hotbar;
        Inventory equipment;
        Inventory inventory;
        PlayerInventoryManager inventoryAndEquipment;
        PlayerInventoryManager playerInventory;
        InventoryGUI inventoryGUI;
        bool shouldThrowItem;
        PAD(7);
        std::unique_ptr<Item> queuedTrowItem;
        bool shouldResetMouse;
        PAD(3);
        float health;
        double hitTime;
        double damageTime;
        int headBlock;

        ~Player()
        {
            reinterpret_cast<void(__thiscall*)(Player * self)>(FUNC_PLAYER_DPLAYER)(this);
        }
        Player()
        {
            reinterpret_cast<void(__thiscall*)(Player * self)>(FUNC_PLAYER_PLAYER)(this);
        }
        void updatePos(World* world, double dt)
        {
            return reinterpret_cast<void(__thiscall*)(Player * self, World * world, double dt)>(FUNC_PLAYER_UPDATEPOS)(this, world, dt);
        }
        void updateCurrentBlock()
        {
            return reinterpret_cast<void(__thiscall*)(Player * self)>(FUNC_PLAYER_UPDATECURRENTBLOCK)(this);
        }
        void handleCollision(World* world)
        {
            return reinterpret_cast<void(__thiscall*)(Player * self, World * world)>(FUNC_PLAYER_HANDLECOLLISION)(this, world);
        }
        void updateComponentVectors()
        {
            return reinterpret_cast<void(__thiscall*)(Player * self)>(FUNC_PLAYER_UPDATECOMPONENTVECTORS)(this);
        }
        void removeVelComp(unsigned int comp)
        {
            return reinterpret_cast<void(__thiscall*)(Player * self, unsigned int comp)>(FUNC_PLAYER_REMOVEVELCOMP)(this, comp);
        }
        void updateTargetBlock(World* world, float maxDist)
        {
            return reinterpret_cast<void(__thiscall*)(Player * self, World * world, float maxDist)>(FUNC_PLAYER_UPDATETARGETBLOCK)(this, world, maxDist);
        }
        void init()
        {
            return reinterpret_cast<void(__thiscall*)(Player * self)>(FUNC_PLAYER_INIT)(this);
        }
        void renderHud(GLFWwindow* window)
        {
            return reinterpret_cast<void(__thiscall*)(Player * self, GLFWwindow * window)>(FUNC_PLAYER_RENDERHUD)(this, window);
        }
        void throwItem(World* world, std::unique_ptr<Item>& item)
        {
            return reinterpret_cast<void(__thiscall*)(Player * self, World * world, std::unique_ptr<Item> &item)>(FUNC_PLAYER_THROWITEM)(this, world, item);
        }
        void update(Entity* window, World* world, double dt)
        {
            return reinterpret_cast<void(__thiscall*)(Player * self, Entity * window, World * world, double dt)>(FUNC_PLAYER_UPDATE)(this, window, world, dt);
        }
        void updateCameraPos(World* world)
        {
            return reinterpret_cast<void(__thiscall*)(Player * self, World * world)>(FUNC_PLAYER_UPDATECAMERAPOS)(this, world);
        }
        void resetMouse(GLFWwindow* window)
        {
            return reinterpret_cast<void(__thiscall*)(Player * self, GLFWwindow * window)>(FUNC_PLAYER_RESETMOUSE)(this, window);
        }
        char keyInput(GLFWwindow* window, int key, int scancode, int action, char mods)
        {
            return reinterpret_cast<char(__thiscall*)(Player * self, GLFWwindow * window, int key, int scancode, int action, char mods)>(FUNC_PLAYER_KEYINPUT)(this, window, key, scancode, action, mods);
        }
        void mouseInput(GLFWwindow* window, double xpos, double ypos)
        {
            return reinterpret_cast<void(__thiscall*)(Player * self, GLFWwindow * window, double xpos, double ypos)>(FUNC_PLAYER_MOUSEINPUT)(this, window, xpos, ypos);
        }
        void mouseButtonInput(GLFWwindow* window, unsigned int button, int action, int mods)
        {
            return reinterpret_cast<void(__thiscall*)(Player * self, GLFWwindow * window, unsigned int button, int action, int mods)>(FUNC_PLAYER_MOUSEBUTTONINPUT)(this, window, button, action, mods);
        }
        bool isHoldingGlasses()
        {
            return reinterpret_cast<bool(__thiscall*)(Player * self)>(FUNC_PLAYER_ISHOLDINGGLASSES)(this);
        }
        bool isHoldingCompass()
        {
            return reinterpret_cast<bool(__thiscall*)(Player * self)>(FUNC_PLAYER_ISHOLDINGCOMPASS)(this);
        }
        nlohmann::json* save()
        {
            return reinterpret_cast<nlohmann::json * (__thiscall*)(Player * self, nlohmann::json * result)>(FUNC_PLAYER_SAVE)(this, nullptr);
        }
        void renderInit(GLFWwindow* window)
        {
            return reinterpret_cast<void(__thiscall*)(Player * self, GLFWwindow * window)>(FUNC_PLAYER_RENDERINIT)(this, window);
        }
        void load(const nlohmann::json& j)
        {
            return reinterpret_cast<void(__thiscall*)(Player * self, const nlohmann::json & j)>(FUNC_PLAYER_LOAD)(this, j);
        }
	};
}
#endif