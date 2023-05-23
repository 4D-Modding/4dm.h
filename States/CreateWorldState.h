#pragma once
#ifndef CREATEWORLDSTATE_H
#define CREATEWORLDSTATE_H
#include "../4dm.h"
#include "State.h"
namespace fdm
{
    class FontRenderer;
    class QuadRenderer;
    class Shader;
    class CreateWorldState : public State
    {
    public:
        bool updateViewFlag;
        PAD(7);
        FontRenderer font;
        QuadRenderer qr;
        const Shader* qs;
        gui::Interface ui;
        gui::Button createButton;
        gui::Button cancelButton;
        gui::Text worldNameText;
        gui::Text worldSeedText;
        gui::Text noNameErrorMsg;
        gui::TextInput worldNameInput;
        gui::TextInput worldSeedInput;
        gui::CheckBox flatWorldCheckBox;

        CreateWorldState()
        {
            reinterpret_cast<void(__thiscall*)(CreateWorldState * self)>(base + idaOffsetFix(0x3EFB0))(this);
        }
        void updateProjection(const glm::ivec2& size, const glm::ivec2& translate2D)
        {
            return reinterpret_cast<void(__thiscall*)(CreateWorldState * self, const glm::ivec2 & size, const glm::ivec2 & translate2D)>(base + idaOffsetFix(0x3F3F0))(this, size, translate2D);
        }
        static void createWorldCancel(void* user)
        {
            return reinterpret_cast<void(__fastcall*)(void* user)>(base + idaOffsetFix(0x3F8A0))(user);
        }
        static void createNewWorld(void* user)
        {
            return reinterpret_cast<void(__fastcall*)(void* user)>(base + idaOffsetFix(0x3F8F0))(user);
        }
        static void viewportCallback(void* user, const glm::ivec4& pos, const glm::ivec2& scroll)
        {
            return reinterpret_cast<void(__fastcall*)(void* user, const glm::ivec4 & pos, const glm::ivec2 & scroll)>(base + idaOffsetFix(0x3FA80))(user, pos, scroll);
        }
        void init(StateManager& s) override
        {
            return reinterpret_cast<void(__thiscall*)(CreateWorldState * self, StateManager& s)>(base + idaOffsetFix(0x3FB10))(this, s);
        }
        void close(StateManager& s) override
        {
            return reinterpret_cast<void(__thiscall*)(CreateWorldState * self, StateManager& s)>(base + idaOffsetFix(0x402B0))(this, s);
        }
        void update(StateManager& s, double dt) override
        {
            return reinterpret_cast<void(__thiscall*)(CreateWorldState * self, StateManager& s, double dt)>(base + idaOffsetFix(0x402C0))(this, s, dt);
        }
        void resume(StateManager& s) override
        {
            return reinterpret_cast<void(__thiscall*)(CreateWorldState * self, StateManager& s)>(base + idaOffsetFix(0x40520))(this, s);
        }
        void windowResize(StateManager& s, int width, int height) override
        {
            return reinterpret_cast<void(__thiscall*)(CreateWorldState * self, StateManager& s, int width, int height)>(base + idaOffsetFix(0x40670))(this, s, width, height);
        }
        bool handleCreateButton()
        {
            return reinterpret_cast<bool(__thiscall*)(CreateWorldState * self)>(base + idaOffsetFix(0x406D0))(this);
        }
    };
}
#endif // !CREATEWORLDSTATE_H
