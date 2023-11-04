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
#include <cstdint>
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
#include <set>
#include <unordered_set>

#include "soil/SOIL.h"

#define __STR_CAT___(str1, str2) str1##str2
#define __STR_CAT__(str1, str2) __STR_CAT___(str1, str2)

#ifndef PAD
#define PAD(size) char __STR_CAT__(__, __STR_CAT__(pad, __LINE__))[size] = {}
#endif

#ifndef idaOffsetFix
#define idaOffsetFix(offset) (offset + 0xC00)
#endif

#ifndef MBO
#define MBO(t, c, off) *reinterpret_cast<t*>(reinterpret_cast<uintptr_t>(c) + off) // Member By Offset (type, object, offset)
#endif

#include "hook.h"

void patchMemory(uintptr_t addressToWrite, byte* valueToWrite, int byteNum)
{
	unsigned long OldProtection;
	VirtualProtect((LPVOID)(addressToWrite), byteNum, PAGE_EXECUTE_READWRITE, &OldProtection);
	memcpy((LPVOID)addressToWrite, valueToWrite, byteNum);
	VirtualProtect((LPVOID)(addressToWrite), byteNum, OldProtection, NULL);
}

namespace fdm
{
	inline uintptr_t base = reinterpret_cast<uintptr_t>(GetModuleHandle(0));
}

#include "addresses.h"

// Connection namespace
#include "Connection/MessageData.h"
#include "Connection/InMessage.h"
#include "Connection/OutMessage.h"
#include "Connection/Server.h"
#include "Connection/Client.h"
#include "Packet.h" // thats not in Connection namespace for some reason even tho it relates to networking but k

// fuck boost
#include "path.h"
#include "uuid.h"

// mesh related stuff mostly
#include "Mesh.h"
#include "MeshBuilder.h"
#include "GlobalShapes.h"
#include "Coil.h"
#include "Dodecaplex.h"
#include "DodecaplexWireframe.h"
#include "HypercubeHollow.h"
#include "Hypersphere.h"
#include "PentachoronHollow.h"
#include "Skybox.h"
#include "Sphere.h"
#include "KleinBottle.h"

// general
#include "m4.h"
#include "Frustum.h"
#include "BlockInfo.h"
#include "Tex2D.h"
#include "Shader.h"
#include "ResourceManager.h"
#include "ShaderManager.h"
#include "Hitbox.h"

// audio lol!!!
#include "AudioManager.h"

// renderers
#include "TexRenderer.h"
#include "FontRenderer.h"
#include "QuadRenderer.h"
#include "CompassRenderer.h"
#include "MeshRenderer.h"


// PlayerSkin
#include "PlayerSkin.h"
#include "PlayerSkinRenderer.h"
#include "PlayerSkinViewer.h"

// items
#include "Item.h"
#include "ItemBlock.h"
#include "ItemMaterial.h"
#include "ItemTool.h"

// entities
#include "Entity.h"
#include "EntityAlidade.h"
#include "EntityButterfly.h"
#include "EntityChest.h"
#include "EntityDying.h"
#include "EntityItem.h"
#include "EntityPlayer.h"
#include "EntitySpider.h"
#include "EntityManager.h"

#include "GUI/gui.h"

// inventory related stuff
#include "Inventory.h"
#include "InventoryGrid.h"
#include "InventoryCursor.h"
#include "InventoryManager.h"
#include "InventoryPlayer.h"
#include "InventorySession.h"
#include "CraftingMenu.h"

// world related stuff
#include "World.h"
#include "WorldClient.h"
#include "WorldManager.h"
#include "WorldServer.h"
#include "WorldSingleplayer.h"
#include "WorldTitleScreen.h"
#include "Player.h"
#include "Chunk.h"
#include "CloudChunk.h"
#include "CloudManager.h"
#include "ChunkLoader.h"

// states
#include "State.h"
#include "StateManager.h"
#include "StateCreateWorld.h"
#include "StateCredits.h"
#include "StateDeathScreen.h"
#include "StateErrorScreen.h"
#include "StateGame.h"
#include "StateIntro.h"
#include "StateMultiplayer.h"
#include "StatePause.h"
#include "StateSettings.h"
#include "StateSingleplayer.h"
#include "StateSkinChooser.h"
#include "StateTitleScreen.h"
#include "StateTutorial.h"
#include "StateTutorialSlideshow.h"
#include "StateWorldGen.h"

extern "C" inline __declspec(dllexport) const char* getModName() { return MOD_NAME; }
extern "C" inline __declspec(dllexport) const char* getModVer() { return MOD_VER; }

#endif