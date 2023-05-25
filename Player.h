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
        inline static TexRenderer healthRenderer;
        inline static FontRenderer fr;

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
            reinterpret_cast<void(__thiscall*)(Player * self)>(base + idaOffsetFix(0x4FF50))(this);
        }
        Player()
        {
            reinterpret_cast<void(__thiscall*)(Player * self)>(base + idaOffsetFix(0x50130))(this);
        }
        void updatePos(World* world, double dt)
        {
            return reinterpret_cast<void(__thiscall*)(Player * self, World * world, double dt)>(base + idaOffsetFix(0x78690))(this, world, dt);
        }
        void updateCurrentBlock()
        {
            return reinterpret_cast<void(__thiscall*)(Player * self)>(base + idaOffsetFix(0x79390))(this);
        }
        void handleCollision(World* world)
        {
            return reinterpret_cast<void(__thiscall*)(Player * self, World * world)>(base + idaOffsetFix(0x79510))(this, world);
        }
        void updateComponentVectors()
        {
            return reinterpret_cast<void(__thiscall*)(Player * self)>(base + idaOffsetFix(0x7A7C0))(this);
        }
        void removeVelComp(unsigned int comp)
        {
            return reinterpret_cast<void(__thiscall*)(Player * self, unsigned int comp)>(base + idaOffsetFix(0x7B300))(this, comp);
        }
        void updateTargetBlock(World* world, float maxDist)
        {
            return reinterpret_cast<void(__thiscall*)(Player * self, World * world, float maxDist)>(base + idaOffsetFix(0x7B850))(this, world, maxDist);
        }
        void init()
        {
            return reinterpret_cast<void(__thiscall*)(Player * self)>(base + idaOffsetFix(0x7C400))(this);
        }
        void renderHud(GLFWwindow* window)
        {
            return reinterpret_cast<void(__thiscall*)(Player * self, GLFWwindow * window)>(base + idaOffsetFix(0x7C6A0))(this, window);
        }
        void throwItem(World* world, std::unique_ptr<Item>& item)
        {
            return reinterpret_cast<void(__thiscall*)(Player * self, World * world, std::unique_ptr<Item> &item)>(base + idaOffsetFix(0x7E9D0))(this, world, item);
        }
        void update(Entity* window, World* world, double dt)
        {
            return reinterpret_cast<void(__thiscall*)(Player * self, Entity * window, World * world, double dt)>(base + idaOffsetFix(0x7EB40))(this, window, world, dt);
        }
        void updateCameraPos(World* world)
        {
            return reinterpret_cast<void(__thiscall*)(Player * self, World * world)>(base + idaOffsetFix(0x80940))(this, world);
        }
        void resetMouse(GLFWwindow* window)
        {
            return reinterpret_cast<void(__thiscall*)(Player * self, GLFWwindow * window)>(base + idaOffsetFix(0x817A0))(this, window);
        }
        char keyInput(GLFWwindow* window, int key, int scancode, int action, char mods)
        {
            return reinterpret_cast<char(__thiscall*)(Player * self, GLFWwindow * window, int key, int scancode, int action, char mods)>(base + idaOffsetFix(0x81880))(this, window, key, scancode, action, mods);
        }
        void mouseInput(GLFWwindow* window, double xpos, double ypos)
        {
            return reinterpret_cast<void(__thiscall*)(Player * self, GLFWwindow * window, double xpos, double ypos)>(base + idaOffsetFix(0x82040))(this, window, xpos, ypos);
        }
        void mouseButtonInput(GLFWwindow* window, unsigned int button, int action, int mods)
        {
            return reinterpret_cast<void(__thiscall*)(Player * self, GLFWwindow * window, unsigned int button, int action, int mods)>(base + idaOffsetFix(0x82660))(this, window, button, action, mods);
        }
        bool isHoldingGlasses()
        {
            return reinterpret_cast<bool(__thiscall*)(Player * self)>(base + idaOffsetFix(0x827F0))(this);
        }
        bool isHoldingCompass()
        {
            return reinterpret_cast<bool(__thiscall*)(Player * self)>(base + idaOffsetFix(0x82970))(this);
        }
        nlohmann::json* save()
        {
            return reinterpret_cast<nlohmann::json * (__thiscall*)(Player * self, nlohmann::json * result)>(base + idaOffsetFix(0x83F00))(this, nullptr);
        }
        void renderInit(GLFWwindow* window)
        {
            return reinterpret_cast<void(__thiscall*)(Player * self, GLFWwindow * window)>(base + idaOffsetFix(0x84C60))(this, window);
        }
        void load(const nlohmann::json& j)
        {
            return reinterpret_cast<void(__thiscall*)(Player * self, const nlohmann::json & j)>(base + idaOffsetFix(0x82A60))(this, j);
        }
	};
}
#endif