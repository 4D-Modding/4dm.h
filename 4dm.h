/*
 * that was kinda helpful for RE rendering : https://javagl.github.io/GLConstantsTranslator/GLConstantsTranslator.html
 * and some other stuff
*/
#ifndef __4DM_H__
#define __4DM_H__

#ifndef MOD_NAME
#define MOD_NAME "Unknown Mod"
#endif
#ifndef MOD_VER
#define MOD_VER "0.0"
#endif

#include <algorithm>
#include <map>
#include <unordered_map>
#include <memory>
#include <utility>
#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <string>
#include <vector>
#include "json.hpp"
#include "glm/glm.hpp"
#include "glm/trigonometric.hpp"
#include "glm/ext/matrix_transform.hpp"
#include "glm/ext/matrix_clip_space.hpp"
#include "glm/gtx/hash.hpp"
#include "GL/glew.h"
#include "glfw.h"
#include <mutex>
#define __STR_CAT___(str1, str2) str1##str2
#define __STR_CAT__(str1, str2) __STR_CAT___(str1, str2)

#ifndef PAD
#define PAD(size) char __STR_CAT__(__, __STR_CAT__(pad, __LINE__))[size] = {}
#endif

#ifndef idaOffsetFix
#define idaOffsetFix(offset) (offset + 0xC00)
#endif

#ifndef MBO
#define MBO(t, c, off) *reinterpret_cast<t*>(reinterpret_cast<uintptr_t>(c) + off) // member by offset
#endif

#include "hook.h"

namespace fdm
{
	//const char* modName = "";
	//const char* modVer = "";
	inline uintptr_t base = reinterpret_cast<uintptr_t>(GetModuleHandle(0));
}

#include "addresses.h"

#include "path.h"
#include "m4.h"
#include "Mesh.h"
#include "Entity.h"
#include "MeshBuilder.h"
#include "MeshRenderer.h"
#include "TexRenderer.h"
#include "FontRenderer.h"
#include "QuadRenderer.h"
#include "Item.h"
#include "InventoryCursor.h"
#include "InventoryManager.h"
#include "Inventory.h"
#include "PlayerInventoryManager.h"
#include "Tex2D.h"
#include "Shader.h"
#include "World.h"
#include "Frustum.h"
#include "Player.h"
#include "Chunk.h"
#include "ShaderManager.h"
#include "ResourceManager.h"
#include "GUI/gui.h"
#include "CraftingMenu.h"
#include "InventoryGUI.h"
#include "CloudChunk.h"
#include "CloudManager.h"
#include "BlockItem.h"
#include "BlockHelper.h"
#include "States/StateManager.h"
#include "States/State.h"
#include "States/GameState.h"
#include "States/TitleState.h"
#include "States/CreateWorldState.h"

extern "C" inline __declspec(dllexport) const char* getModName() { return MOD_NAME; }
extern "C" inline __declspec(dllexport) const char* getModVer() { return MOD_VER; }

//extern "C" __declspec(dllexport) void setModName(const char* newName) { fdm::modName = newName; }
//extern "C" __declspec(dllexport) void setModVer(const char* newVer) { fdm::modVer = newVer; }

#endif