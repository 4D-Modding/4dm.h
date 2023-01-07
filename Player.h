#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "4dm.h"
#include "InventoryGUI.h"
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
        static const float zNear;
        static const float zFar;
        static const float height;
        static const float acc;
        static const float fric;
        static const float maxWalkSpeed;
        static const float maxCrouchSpeed;
        static const float maxSprintSpeed;
        static const glm::vec4 defaultSpawnPos;
        static const float maxHealth;
        static const float hitCooldown;
        static const float damageCooldown;
        static TexRenderer healthRenderer;
        static FontRenderer fr;

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
	};
}
#endif