#ifndef __4DM_H__
#define __4DM_H__
#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <string>
#include <vector>
#include "json.hpp"
#include "glm/glm.hpp"
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
namespace fdm
{
	inline uintptr_t base = reinterpret_cast<uintptr_t>(GetModuleHandle(0));
}
#include "m4.h"
#include "Mesh.h"
#include "TexRenderer.h"
#include "FontRenderer.h"
#include "QuadRenderer.h"
#include "Inventory.h"
#include "Item.h"
#include "PlayerInventoryManager.h"
#include "InventoryCursor.h"
#include "InventoryManager.h"
#include "Tex2D.h"
#include "Shader.h"
#include "World.h"
#include "Frustum.h"
#include "Chunk.h"
#include "MeshRenderer.h"
#include "Entity.h"
#include "Player.h"
//#include "InventoryGUI.h"
#include "path.h"
#include "CloudChunk.h"
#include "CloudManager.h"
#include "States/StateManager.h"
#include "States/State.h"
#include "States/GameState.h"
#endif