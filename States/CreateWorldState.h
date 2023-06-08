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

        inline static CreateWorldState* getInstance() // instanceObj
        {
            return *reinterpret_cast<CreateWorldState**>((base + 0x1BDDA0));
        }

        CreateWorldState()
        {
            reinterpret_cast<void(__thiscall*)(CreateWorldState * self)>(FUNC_CREATEWORLDSTATE_CREATEWORLDSTATE)(this);
        }
        void updateProjection(const glm::ivec2& size, const glm::ivec2& translate2D)
        {
            return reinterpret_cast<void(__thiscall*)(CreateWorldState * self, const glm::ivec2 & size, const glm::ivec2 & translate2D)>(FUNC_CREATEWORLDSTATE_UPDATEPROJECTION)(this, size, translate2D);
        }
        inline static void createWorldCancel(void* user)
        {
            return reinterpret_cast<void(__fastcall*)(void* user)>(FUNC_CREATEWORLDSTATE_CREATEWORLDCANCEL)(user);
        }
        inline static void createNewWorld(void* user)
        {
            return reinterpret_cast<void(__fastcall*)(void* user)>(FUNC_CREATEWORLDSTATE_CREATENEWWORLD)(user);
        }
        inline static void viewportCallback(void* user, const glm::ivec4& pos, const glm::ivec2& scroll)
        {
            return reinterpret_cast<void(__fastcall*)(void* user, const glm::ivec4 & pos, const glm::ivec2 & scroll)>(FUNC_CREATEWORLDSTATE_VIEWPORTCALLBACK)(user, pos, scroll);
        }
        void init(StateManager& s) override
        {
            return reinterpret_cast<void(__thiscall*)(CreateWorldState * self, StateManager& s)>(FUNC_CREATEWORLDSTATE_INIT)(this, s);
        }
        void close(StateManager& s) override
        {
            return reinterpret_cast<void(__thiscall*)(CreateWorldState * self, StateManager& s)>(FUNC_CREATEWORLDSTATE_CLOSE)(this, s);
        }
        void update(StateManager& s, double dt) override
        {
            return reinterpret_cast<void(__thiscall*)(CreateWorldState * self, StateManager& s, double dt)>(FUNC_CREATEWORLDSTATE_UPDATE)(this, s, dt);
        }
        void resume(StateManager& s) override
        {
            return reinterpret_cast<void(__thiscall*)(CreateWorldState * self, StateManager& s)>(FUNC_CREATEWORLDSTATE_RESUME)(this, s);
        }
        void windowResize(StateManager& s, int width, int height) override
        {
            return reinterpret_cast<void(__thiscall*)(CreateWorldState * self, StateManager& s, int width, int height)>(FUNC_CREATEWORLDSTATE_WINDOWRESIZE)(this, s, width, height);
        }
        bool handleCreateButton()
        {
            return reinterpret_cast<bool(__thiscall*)(CreateWorldState * self)>(FUNC_CREATEWORLDSTATE_HANDLECREATEBUTTON)(this);
        }
    };
}
#endif // !CREATEWORLDSTATE_H
