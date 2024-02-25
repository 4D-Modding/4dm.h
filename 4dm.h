#ifndef __4DM_H__
#define __4DM_H__

#pragma warning(disable: 26495)
#pragma warning(disable: 4819)
#pragma warning(disable: 26444)
#pragma warning(disable: 6387)
#pragma warning(disable: 26800)
#pragma warning(disable: 26819)
#pragma warning(disable: 4267)
#pragma warning(disable: 4244)

#include <algorithm>
#include <map>
#include <unordered_map>
#include <memory>
#include <utility>
#include <stdio.h>
#include <iostream>
#include <windows.h>
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

#include "soil/SOIL2.h"

#define __STR_CAT___(str1, str2) str1##str2
#define CONCAT(str1, str2) __STR_CAT___(str1, str2)

#ifndef PAD
#define PAD(size) char CONCAT(__, CONCAT(pad, __LINE__))[size] = {}
#endif

#ifndef idaOffsetFix
#define idaOffsetFix(offset) (offset + 0xC00)
#endif

#ifndef MBO
#define MBO(t, c, off) *reinterpret_cast<t*>(reinterpret_cast<uintptr_t>(c) + off) // Member By Offset (type, object, offset)
#endif

#include "hook.h"

inline void patchMemory(uintptr_t addressToWrite, byte* valueToWrite, int byteNum)
{
	unsigned long OldProtection;
	VirtualProtect((LPVOID)(addressToWrite), byteNum, PAGE_EXECUTE_READWRITE, &OldProtection);
	memcpy((LPVOID)addressToWrite, valueToWrite, byteNum);
	VirtualProtect((LPVOID)(addressToWrite), byteNum, OldProtection, NULL);
}

namespace fdm
{
	inline uintptr_t base = reinterpret_cast<uintptr_t>(GetModuleHandle(0));

	inline std::string modID = "";

	namespace Func {

		enum class AudioManager : int {
			loadSound = 0,
			playSound4D = 1,
			setListenerInfo4D = 2,
			loadBGMfromJSON = 3,
			updateBGM = 4,
			getSound = 5,
			getVoiceGroupInfo = 6,
		};
		enum class Hitbox : int {
			addVelWithMaxHorizSpeed = 7,
			update = 8,
			isIntersectingRay = 9,
			takeStep = 10,
		};
		enum class KleinBottle : int {
			buffData = 11,
			attrSize = 12,
			KleinBottle = 13,
			buffSize = 14,
			destr_KleinBottle = 15,
		};
		namespace Connection_Nested {
			enum class InMessage : int {
				InMessageDeleter = 16,
				destr_InMessage = 17,
			};
		}
		namespace Connection_Nested {
			enum class OutMessage : int {
				createMessage = 18,
				OutMessage = 19,
				ReleaseHeapMessageData = 20,
			};
		}
		namespace Connection_Nested {
			enum class Client : int {
				update = 21,
				resolveHost = 22,
				cleanup = 23,
				connectionStatusChangedCallback = 24,
			};
		}
		enum class WorldTitleScreen : int {
			loadCube = 25,
			loadChunk = 26,
			updateChunkCache = 27,
			generateMesh = 28,
			loadChunks = 29,
		};
		enum class FontRenderer : int {
			FontRenderer = 30,
			FontRendererA = 31,
			setText = 32,
			render = 33,
			updateModel = 34,
			move = 35,
		};
		enum class TexRenderer : int {
			destr_TexRenderer = 36,
			operatorEq = 37,
			init = 38,
			setClip = 39,
			setColor = 40,
			setPos = 41,
		};
		enum class Dodecaplex : int {
			buffCount = 42,
			buffData = 43,
			buffSize = 44,
			attrSize = 45,
			generateMesh = 46,
			generateCellColors = 47,
			addFaces = 48,
			addCells = 49,
			destr_Dodecaplex = 50,
		};
		enum class Skybox : int {
			buffData = 51,
			buffSize = 52,
			attrSize = 53,
			vertCount = 54,
		};
		enum class PentachoronHollow : int {
			buffData = 55,
			PentachoronHollow = 56,
			buffSize = 57,
			vertCount = 58,
			addTetSide = 59,
		};
		namespace Hypersphere_Nested {
			enum class VertInfo : int {
				VertInfo = 60,
				destr_VertInfo = 61,
				add = 62,
				addA = 63,
			};
		}
		enum class Hypersphere : int {
			attrCount = 64,
			attrType = 65,
			buffCount = 66,
			Hypersphere = 67,
			HypersphereA = 68,
			generateSpherePolygons = 69,
			addWedgeSide = 70,
			addCubeSide = 71,
		};
		enum class MeshRenderer : int {
			MeshRenderer = 72,
			setMesh = 73,
			updateMesh = 74,
			destr_MeshRenderer = 75,
			render = 76,
			init = 77,
			cleanup = 78,
			initAttrs = 79,
		};
		namespace PlayerSkin_Nested {
			enum class SkinMesh : int {
				vertCount = 80,
				destr_SkinMesh = 81,
				generate = 82,
				buffSize = 83,
				attrCount = 84,
				attrType = 85,
				attrSize = 86,
				attrStride = 87,
				addPixelToFace = 88,
			};
		}
		enum class PlayerSkin : int {
			load = 89,
			generateMesh = 90,
			destr_PlayerSkin = 91,
		};
		enum class Tex2D : int {
			destr_Tex2D = 92,
			loadRawImageData = 93,
			initFromTexID = 94,
			loadArrayTexture = 95,
		};
		enum class StateCredits : int {
			init = 96,
			update = 97,
			render = 98,
			windowResize = 99,
			keyInput = 100,
			updateProjection = 101,
		};
		enum class StateCreateWorld : int {
			StateCreateWorld = 102,
			init = 103,
			close = 104,
			update = 105,
			render = 106,
			resume = 107,
			mouseInput = 108,
			scrollInput = 109,
			keyInput = 110,
			windowResize = 111,
			charInput = 112,
			createNewWorld = 113,
			viewportCallback = 114,
			caveCheckboxCallback = 115,
			handleCreateButton = 116,
		};
		enum class StateTitleScreen : int {
			quitGameButtonCallback = 117,
			settingsButtonCallback = 118,
			StateTitleScreen = 119,
			updateProjection = 120,
			singleplayerButtonCallback = 121,
			multiplayerplayerButtonCallback = 122,
			creditsButtonCallback = 123,
			tutorialButtonCallback = 124,
			init = 125,
			close = 126,
			update = 127,
			render = 128,
			pause = 129,
			resume = 130,
			keyInput = 131,
			windowResize = 132,
			mouseInput = 133,
			mouseButtonInput = 134,
			renderBackground = 135,
		};
		enum class StateGame : int {
			StateGame = 136,
			resetMouse = 137,
			updateProjection2D = 138,
			viewportCallback = 139,
			updateChatMessages = 140,
			init = 141,
			close = 142,
			pause = 143,
			resume = 144,
			update = 145,
			render = 146,
			mouseInput = 147,
			scrollInput = 148,
			mouseButtonInput = 149,
			keyInput = 150,
			windowResize = 151,
			charInput = 152,
			updateProjection = 153,
			setWorld = 154,
			addChatMessage = 155,
		};
		enum class StateWorldGen : int {
			updateProjection = 156,
			init = 157,
			update = 158,
			render = 159,
			windowResize = 160,
		};
		enum class StateMultiplayer : int {
			destr_StateMultiplayer = 161,
			StateMultiplayer = 162,
			updateProjection = 163,
			cancelButtonCallback = 164,
			changeSkinButtonCallback = 165,
			joinButtonCallback = 166,
			viewportCallback = 167,
			uuidCopyButtonCallback = 168,
			init = 169,
			close = 170,
			update = 171,
			render = 172,
			mouseInput = 173,
			scrollInput = 174,
			mouseButtonInput = 175,
			keyInput = 176,
			windowResize = 177,
			charInput = 178,
			rejoin = 179,
			connect = 180,
			connectionErrorOkButtonCallback = 181,
		};
		enum class StateSingleplayer : int {
			mouseButtonInput = 182,
			updateProjection = 183,
			StateSingleplayer = 184,
			updateWorldListContainer = 185,
			createCallback = 186,
			viewportCallback = 187,
			worldButtonCallback = 188,
			init = 189,
			close = 190,
			update = 191,
			resume = 192,
			windowResize = 193,
			queueWorldLoad = 194,
		};
		enum class StateDeathScreen : int {
			updateProjection = 195,
			retryButtonCallback = 196,
			init = 197,
			close = 198,
			update = 199,
			render = 200,
			mouseInput = 201,
			scrollInput = 202,
			mouseButtonInput = 203,
			keyInput = 204,
			windowResize = 205,
		};
		enum class StateErrorScreen : int {
			okButtonCallback = 206,
			init = 207,
			close = 208,
			update = 209,
			render = 210,
			mouseButtonInput = 211,
			windowResize = 212,
		};
		enum class StateIntro : int {
			updateProjection = 213,
			loadFiles = 214,
			init = 215,
			update = 216,
			render = 217,
			windowResize = 218,
		};
		enum class StateTutorial : int {
			destr_StateTutorial = 219,
			StateTutorial = 220,
			updateProjection = 221,
			backButtonCallback = 222,
			nextButtonCallback = 223,
			generateMesh = 224,
			getSmoothLighting = 225,
			updatePlayerComponentVectors = 226,
			updatePlayerPos = 227,
			updateCurrentBlock = 228,
			handleCollision = 229,
			setForgSprite = 230,
			init = 231,
			close = 232,
			update = 233,
			render = 234,
			resume = 235,
			mouseInput = 236,
			scrollInput = 237,
			mouseButtonInput = 238,
			keyInput = 239,
			windowResize = 240,
			charInput = 241,
			updateViewport = 242,
		};
		enum class StateTutorialSlideshow : int {
			destr_StateTutorialSlideshow = 243,
			StateTutorialSlideshow = 244,
			updateProjection = 245,
			updateSlideSize = 246,
			viewportCallback = 247,
			init = 248,
			update = 249,
			render = 250,
			resume = 251,
			windowResize = 252,
			continueButtonCallback = 253,
			backButtonCallback = 254,
			setSlide = 255,
		};
		enum class StateSkinChooser : int {
			mouseInput = 256,
			scrollInput = 257,
			keyInput = 258,
			StateSkinChooser = 259,
			updateProjection = 260,
			viewportCallback = 261,
			chooseFileButtonCallback = 262,
			init = 263,
			close = 264,
			update = 265,
			render = 266,
			windowResize = 267,
			fileDrop = 268,
			getSkinMessage = 269,
			loadSkin = 270,
		};
		enum class StateSettings : int {
			updateProjection = 271,
			destr_StateSettings = 272,
			StateSettings = 273,
			getSetting = 274,
			renderDistanceSliderCallback = 275,
			scrollSensitivitySliderCallback = 276,
			lookSensitivitySliderCallback = 277,
			xInvertCheckBoxCallback = 278,
			yInvertCheckBoxCallback = 279,
			fovSliderCallback = 280,
			globalVolumeSliderCallback = 281,
			musicVolumeSliderCallback = 282,
			creatureVolumeSliderCallback = 283,
			ambienceVolumeSliderCallback = 284,
			controlsButtonCallback = 285,
			controlsOkButtonCallback = 286,
			fullscreenButtonCallback = 287,
			difficultySliderCallback = 288,
			smoothLightingCheckBoxCallback = 289,
			shadowsCheckBoxCallback = 290,
			lightsCheckBoxCallback = 291,
			chatCheckBoxCallback = 292,
			nametagsCheckBoxCallback = 293,
			skinsCheckBoxCallback = 294,
			secretButtonCallback = 295,
			viewportCallback = 296,
			updateStateGame = 297,
			updateVolume = 298,
			load = 299,
			save = 300,
			init = 301,
			close = 302,
			render = 303,
			mouseInput = 304,
			scrollInput = 305,
			mouseButtonInput = 306,
			keyInput = 307,
			windowResize = 308,
			updateRenderDistance = 309,
			updateFOV = 310,
			updateCreatureVolume = 311,
			updateAmbienceVolume = 312,
			updateDifficulty = 313,
			setFullscreenMode = 314,
		};
		enum class StatePause : int {
			StatePause = 315,
			updateProjection = 316,
			update = 317,
			render = 318,
			pause = 319,
			resume = 320,
			windowResize = 321,
		};
		enum class StateManager : int {
			pushState = 322,
		};
		namespace m4_Nested {
			enum class Mat5 : int {
				operatorInd = 323,
				Mat5 = 324,
				Mat5A = 325,
				toJson = 326,
				operatorMult = 327,
				operatorMultEQ = 328,
				multiply = 329,
				operatorMult_A = 330,
				translate = 331,
				scale = 332,
			};
		}
		namespace m4_Nested {
			enum class Rotor : int {
				Rotor = 333,
				RotorA = 334,
				operatorMultEq = 335,
				rotate = 336,
				normalize = 337,
			};
		}
		namespace m4_Nested {
			enum class BiVector4 : int {
				BiVector4 = 338,
				BiVector4A = 339,
				toJson = 340,
				normalize = 341,
			};
		}
		enum class m4 : int {
			i64vec3ToJson = 342,
			ivec4ToJson = 343,
			vec4ToJson = 344,
			vec4FromJson = 345,
			cross = 346,
			adjustToMaxHorizSpeed = 347,
			createCamera = 833,
		};
		enum class Item : int {
			loadItemInfo = 348,
			renderItem = 349,
			renderItemDescription = 350,
			createFromJson = 351,
			giveMax = 352,
			giveOne = 353,
			instantiateItem = 354,
			combineItemAttributes = 355,
			save = 356,
			destr_Item = 357,
			takeMax = 358,
			takeHalf = 359,
		};
		enum class World : int {
			World = 360,
			getChunk = 361,
			getChunkFromCoords = 362,
			getEntityIntersection = 363,
			castRay = 364,
			addEntityToChunk = 365,
		};
		namespace BlockInfo_Nested {
			enum class ItemMesh : int {
				destr_ItemMesh = 366,
			};
		}
		enum class BlockInfo : int {
			renderItemMesh = 367,
		};
		enum class ItemBlock : int {
			render = 368,
			renderEntity = 369,
			isDeadly = 370,
			isCompatible = 371,
			saveAttributes = 372,
			action = 373,
			postAction = 374,
			clone = 375,
		};
		enum class ItemTool : int {
			render = 376,
			renderEntity = 377,
			isDeadly = 378,
			isCompatible = 379,
			getStackLimit = 380,
			action = 381,
			breakBlock = 382,
			entityAction = 383,
			clone = 384,
		};
		enum class ItemMaterial : int {
			getStackLimit = 385,
			getName = 386,
			render = 387,
			renderEntity = 388,
			isDeadly = 389,
			isCompatible = 390,
			action = 391,
			postAction = 392,
			clone = 393,
		};
		namespace Chunk_Nested {
			enum class ChunkMesh : int {
				destr_ChunkMesh = 394,
				ChunkMesh = 395,
				buffSize = 396,
				attrCount = 397,
				attrType = 398,
				attrSize = 399,
				attrStride = 400,
				indexBuffData = 401,
				move = 402,
				addMeshSide = 403,
				addMeshPlant = 404,
			};
		}
		enum class Chunk : int {
			Chunk = 405,
			setBlock = 406,
			generateMesh = 407,
			updateEntitiesClient = 408,
			clearEntities = 409,
			render = 410,
			updateLightingHeightMap = 411,
			updateMesh = 412,
			load = 413,
			save = 414,
			loadFromMessage = 415,
			updateCacheSection = 416,
			updateHeightmapCacheSection = 417,
			generateMeshSection = 418,
			getSmoothLighting = 419,
			getLighting = 420,
			enableMesh = 421,
			loadEntitiesFromJson = 422,
			getFilenamePrefix = 423,
		};
		namespace ChunkLoader_Nested {
			enum class BiomeInfo : int {
				destr_BiomeInfo = 424,
				BiomeInfo = 425,
			};
		}
		enum class ChunkLoader : int {
			init = 426,
			loadChunk = 427,
			loadBiomes = 428,
			loadInfo = 429,
			generateChunk = 430,
			getBiome = 431,
			generateTree = 432,
			generateTreeBranch = 433,
			generateTaigaTree = 434,
			createFlatWorldChests = 435,
		};
		namespace CloudChunk_Nested {
			enum class CloudChunkMesh : int {
				indexBuffSize = 436,
				buffSize = 437,
				attrSize = 438,
				attrStride = 439,
				move = 440,
				destr_CloudChunkMesh = 441,
			};
		}
		enum class CloudChunk : int {
			generateMesh = 442,
		};
		enum class CloudManager : int {
			destr_CloudManager = 443,
			render = 444,
			updateChunks = 445,
			unloadAllChunks = 446,
			loadChunks = 447,
			updateChunk = 448,
		};
		namespace CraftingMenu_Nested {
			enum class CraftableRecipe : int {
				destr_CraftableRecipe = 449,
				CraftableRecipe = 450,
			};
		}
		enum class CraftingMenu : int {
			loadRecipes = 451,
			render = 452,
			offsetX = 453,
			offsetY = 454,
			getPos = 455,
			getSize = 456,
			mouseButtonInput = 457,
			updateAvailableRecipes = 458,
		};
		enum class Entity : int {
			loadEntityInfo = 459,
			createFromJson = 460,
			createWithAttributes = 461,
			save = 462,
			instantiateEntity = 463,
			combineEntityAttributes = 464,
			destr_Entity = 465,
		};
		enum class InventoryPlayer : int {
			addItem = 466,
			begin = 467,
			render = 468,
			combineItem = 469,
			placeItem = 470,
			getSlotIndex = 471,
			getSlotCount = 472,
			getSlot = 473,
			end = 474,
		};
		enum class InventoryGrid : int {
			destr_InventoryGrid = 475,
			InventoryGrid = 476,
			render = 477,
			combineItem = 478,
			placeItem = 479,
			getSlotIndex = 480,
			getSlotCount = 481,
			getSlot = 482,
			end = 483,
			load = 484,
			save = 485,
		};
		enum class InventorySession : int {
			destr_InventorySession = 486,
		};
		enum class InventoryManager : int {
			destr_InventoryManager = 487,
			renderInit = 488,
			mouseButtonInput = 489,
			windowResize = 490,
			applyAction = 491,
			applyTransfer = 492,
			findInventory = 493,
			updateCraftingMenuBox = 494,
			craftingMenuCallback = 495,
			viewportCallback = 496,
			updateProjection = 497,
		};
		enum class MeshBuilder : int {
			MeshBuilder = 498,
			MeshBuilder_A = 499,
			destr_MeshBuilder = 500,
			buffCount = 501,
			buffSize = 502,
			attrCount = 503,
			vertCount = 504,
			indexBuffSize = 505,
			addBuff = 506,
			attrType = 507,
			attrSize = 508,
			attrStride = 509,
			addAttr = 510,
			clear = 511,
		};
		enum class Player : int {
			destr_Player = 512,
			Player = 513,
			updatePos = 514,
			updateCurrentBlock = 515,
			handleCollision = 516,
			updateComponentVectors = 517,
			updateAllComponentVectors = 518,
			removeVelComp = 519,
			updateTargetBlock = 520,
			init = 521,
			renderHud = 522,
			renderTargetBlock = 523,
			getMovementUpdate = 524,
			setMovementBehavior = 525,
			hitTargetBlock = 526,
			breakBlock = 527,
			throwItem = 528,
			update = 529,
			updateLocal = 530,
			updateCameraPos = 531,
			resetMouse = 532,
			keyInput = 533,
			mouseInput = 534,
			mouseButtonInput = 535,
			isHoldingGlasses = 536,
			isHoldingCompass = 537,
			isHoldingCollector = 538,
			headIsInBlock = 539,
			getHeadBlock = 540,
			respawn = 541,
			load = 542,
			save = 543,
			loadClientData = 544,
			saveClientData = 545,
			saveOrientation = 546,
		};
		enum class QuadRenderer : int {
			destr_QuadRenderer = 547,
			init = 548,
			setColor = 549,
			setPos = 550,
		};
		enum class ResourceManager : int {
			loadArrayTexture = 551,
			get = 552,
		};
		enum class ShaderManager : int {
			loadFromShaderList = 553,
			get = 554,
		};
		enum class Shader : int {
			load = 555,
			compileShader = 556,
		};
		enum class WorldManager : int {
			destr_WorldManager = 557,
			updateRenderFrustum = 558,
			setBlockUpdate = 559,
			render = 560,
		};
		enum class WorldClient : int {
			destr_WorldClient = 561,
			addEntityToChunk = 562,
			localPlayerEvent = 563,
			updateLocal = 564,
			setRenderDistanceLocal = 565,
			setSkinVisibility = 566,
			localPlayerInit = 567,
			localPlayerRespawn = 568,
			sendChatMessage = 569,
			updatePhysics = 570,
			handleWorldMessage = 571,
			handleLightingOptionsUpdate = 572,
			updateChunks = 573,
			updateChunk = 574,
			generateChunkMeshes = 575,
			updateChunkCacheAndMesh = 576,
			updateChunkCache = 577,
			regenerateAllChunkMeshes = 578,
			joinAllChunkLoadingThreads = 579,
			handleMessage = 580,
			inventoryUpdateCallback = 581,
		};
		enum class WorldSingleplayer : int {
			WorldSingleplayer = 582,
			destr_WorldSingleplayer = 583,
			localPlayerEvent = 584,
			updateLocal = 585,
			cleanupLocal = 586,
			setRenderDistanceLocal = 587,
			setDifficultyLocal = 588,
			localPlayerInit = 589,
			localPlayerRespawn = 590,
			handleLightingOptionsUpdate = 591,
			updateChunks = 592,
			updateChunk = 593,
			loadChunks = 594,
			loadChunk = 595,
			updateChunkCacheAndMesh = 596,
			updateChunkCache = 597,
			regenerateAllChunkMeshes = 598,
		};
		namespace gui_Nested {
			enum class Button : int {
				destr_Button = 599,
				render = 600,
				mouseButtonInput = 601,
				keyInput = 602,
				offsetX = 603,
				enabled = 604,
				select = 605,
				getPos = 606,
				getSize = 607,
				touchingMouse = 608,
			};
		}
		namespace gui_Nested {
			enum class CheckBox : int {
				render = 609,
				mouseButtonInput = 610,
				keyInput = 611,
				getPos = 612,
				getSize = 613,
				touchingMouse = 614,
			};
		}
		namespace gui_Nested {
			enum class ContentBox : int {
				destr_ContentBox = 615,
				getQuadRenderer = 616,
				getFont = 617,
				getGLFWwindow = 618,
				getCursorPos = 619,
				getSize = 620,
				changeViewport = 621,
				getPos = 622,
				getSizeA = 623,
				touchingMouse = 624,
				resetViewport = 625,
				render = 626,
				alignX = 627,
				alignY = 628,
				offsetX = 629,
				offsetY = 630,
				mouseInput = 631,
				scrollInput = 632,
				mouseButtonInput = 633,
				keyInput = 634,
				select = 635,
				deselect = 636,
				addElement = 637,
				removeElement = 638,
				selectElement = 639,
				clear = 640,
				empty = 641,
			};
		}
		namespace gui_Nested {
			enum class Element : int {
				enabled = 642,
				getCursorType = 643,
			};
		}
		namespace gui_Nested {
			enum class Image : int {
				offsetX = 644,
				offsetY = 645,
				render = 646,
				getPos = 647,
				getSize = 648,
			};
		}
		namespace gui_Nested {
			enum class Interface : int {
				Interface = 649,
				destr_Interface = 650,
				render = 651,
				mouseInput = 652,
				scrollInput = 653,
				mouseButtonInput = 654,
				keyInput = 655,
				getQuadRenderer = 656,
				getFont = 657,
				getGLFWwindow = 658,
				getCursorPos = 659,
				getSize = 660,
				changeViewport = 661,
				addElement = 662,
				removeElement = 663,
				selectElement = 664,
				clear = 665,
				empty = 666,
			};
		}
		namespace gui_Nested {
			enum class Slider : int {
				offsetX = 667,
				offsetY = 668,
				deselect = 669,
				render = 670,
				mouseButtonInput = 671,
				mouseInput = 672,
				keyInput = 673,
				alignX = 674,
				alignY = 675,
				getPos = 676,
				getSize = 677,
			};
		}
		namespace gui_Nested {
			enum class Text : int {
				render = 678,
				offsetX = 679,
				getPos = 680,
				getSize = 681,
				setText = 682,
				renderText = 683,
			};
		}
		namespace gui_Nested {
			enum class TextInput : int {
				render = 684,
				alignX = 685,
				alignY = 686,
				offsetX = 687,
				offsetY = 688,
				mouseButtonInput = 689,
				mouseInput = 690,
				keyInput = 691,
				charInput = 692,
				getCursorType = 693,
				select = 694,
				deselect = 695,
				updatePasswordVisualText = 696,
				updateScrollPos = 697,
				getPos = 698,
				getSize = 699,
				removeInvalidChars = 700,
				removeHighlightedText = 701,
			};
		}
		enum class EntityButterfly : int {
			getName = 702,
			update = 703,
			render = 704,
			getServerUpdateAttributes = 705,
			applyServerUpdate = 706,
			takeDamage = 707,
			playHitSound = 708,
			playDeathSound = 709,
			collisionCallback = 710,
		};
		namespace EntityAlidade_Nested {
			enum class SPInfo : int {
				SPInfo = 711,
				destr_SPInfo = 712,
			};
		}
		enum class EntityAlidade : int {
			getName = 713,
			update = 714,
			render = 715,
			saveAttributes = 716,
			getPos = 717,
			setPos = 718,
			takeDamage = 719,
			action = 720,
			postAction = 721,
			generateSpherinder = 722,
			generateSpherinderHollow = 723,
			generateSemicircle = 724,
		};
		enum class EntityItem : int {
			createWithItem = 725,
			getName = 726,
			update = 727,
			render = 728,
			saveAttributes = 729,
			applyServerUpdate = 730,
			getPos = 731,
			setPos = 732,
			shouldSave = 733,
			isIntersectingRay = 734,
			give = 735,
			combineWithNearby = 736,
			collisionCallback = 737,
		};
		enum class EntityPlayer : int {
			createFromPlayer = 738,
			EntityPlayer = 739,
			getName = 740,
			update = 741,
			render = 742,
			saveAttributes = 743,
			applyServerUpdate = 744,
			getPos = 745,
			setPos = 746,
			isIntersectingRay = 747,
			takeDamage = 748,
			deathTimer = 749,
			applyMovementUpdate = 750,
			collectItems = 751,
		};
		namespace EntitySpider_Nested {
			enum class SpiderType : int {
				destr_SpiderType = 752,
			};
		}
		enum class EntitySpider : int {
			isIntersectingRay = 753,
			getPos = 754,
			setPos = 755,
			getName = 756,
			update = 757,
			render = 758,
			saveAttributes = 759,
			getServerUpdateAttributes = 760,
			applyServerUpdate = 761,
			takeDamage = 762,
			playHitSound = 763,
			playDeathSound = 764,
			collisionCallback = 765,
			findPlayer = 766,
			persuePlayer = 767,
		};
		enum class EntityChest : int {
			isClickable = 768,
			getName = 769,
			update = 770,
			render = 771,
			saveAttributes = 772,
			getServerUpdateAttributes = 773,
			applyServerUpdate = 774,
			getPos = 775,
			setPos = 776,
			action = 777,
		};
		enum class EntityDying : int {
			deathTimer = 778,
			createWithEntity = 779,
			getName = 780,
			update = 781,
			render = 782,
			getServerUpdateAttributes = 783,
			applyServerUpdate = 784,
			getPos = 785,
			setPos = 786,
			isBlockEntity = 787,
			isIntersectingRay = 788,
		};
		enum class EntityManager : int {
			extract = 789,
			get = 790,
			getBlockEntity = 791,
		};
		enum class Coil : int {
			Coil = 792,
			buffSize = 793,
			attrSize = 794,
		};
		enum class CompassRenderer : int {
			renderHand = 795,
			renderItemDrop = 796,
		};
		enum class DodecaplexWireframe : int {
			generateMesh = 797,
			addFaces = 798,
			addCells = 799,
		};
		enum class Framebuffer : int {
			destr_Framebuffer = 800,
			render = 801,
			init = 802,
			cleanup = 803,
		};
		enum class HypercubeHollow : int {
			attrSize = 804,
			attrStride = 805,
			HypercubeHollow = 806,
			addCubeSide = 807,
		};
		enum class PlayerSkinRenderer : int {
			PlayerSkinRenderer = 808,
			render = 809,
			updateAnimation = 810,
			resetTransformations = 811,
		};
		enum class PlayerSkinViewer : int {
			render = 812,
			alignX = 813,
			alignY = 814,
			getPos = 815,
			getSize = 816,
			mouseInput = 817,
			getCursorType = 818,
			init = 819,
			setupFrameBuffer = 820,
		};
		enum class Sphere : int {
			vertCount = 821,
			buffSize = 822,
			Sphere = 823,
			generateCirclePolygons = 824,
		};
		enum class main_cpp : int {
			main = 825,
			handleRawMouseInput = 826,
			scrollCallback = 827,
			mouseButtonCallback = 828,
			keyCallback = 829,
			framebufferSizeCallback = 830,
			charCallback = 831,
			fileDropCallback = 832,
		};
	}

	inline void startConsole()
	{
		return reinterpret_cast<void(__stdcall*)()>(GetProcAddress(GetModuleHandleA("4DModLoader-Core.dll"), "startConsole"))();
	}

	inline uint64_t getFuncAddr(int func)
	{
		return reinterpret_cast<uint64_t(__stdcall*)(int)>(GetProcAddress(GetModuleHandleA("4DModLoader-Core.dll"), "getFuncAddr"))(func);
	}
	inline bool isModLoaded(const std::string& modId)
	{
		return reinterpret_cast<bool(__stdcall*)(const std::string&)>(GetProcAddress(GetModuleHandleA("4DModLoader-Core.dll"), "isModLoaded"))(modId);
	}
	inline bool isDLLLoaded(const std::string& dllFileName)
	{
		return reinterpret_cast<bool(__stdcall*)(const std::string&)>(GetProcAddress(GetModuleHandleA("4DModLoader-Core.dll"), "isDLLLoaded"))(dllFileName);
	}
	inline std::string getModDLL(const std::string& modId)
	{
		return reinterpret_cast<std::string(__stdcall*)(const std::string&)>(GetProcAddress(GetModuleHandleA("4DModLoader-Core.dll"), "getModDLL"))(modId);
	}
	inline std::string getModVersion(const std::string& modId)
	{
		return reinterpret_cast<std::string(__stdcall*)(const std::string&)>(GetProcAddress(GetModuleHandleA("4DModLoader-Core.dll"), "getModVersion"))(modId);
	}
	inline std::string getModName(const std::string& modId)
	{
		return reinterpret_cast<std::string(__stdcall*)(const std::string&)>(GetProcAddress(GetModuleHandleA("4DModLoader-Core.dll"), "getModName"))(modId);
	}
	inline std::string getModAuthor(const std::string& modId)
	{
		return reinterpret_cast<std::string(__stdcall*)(const std::string&)>(GetProcAddress(GetModuleHandleA("4DModLoader-Core.dll"), "getModAuthor"))(modId);
	}
	inline std::string getModDescription(const std::string& modId)
	{
		return reinterpret_cast<std::string(__stdcall*)(const std::string&)>(GetProcAddress(GetModuleHandleA("4DModLoader-Core.dll"), "getModDescription"))(modId);
	}
	inline HMODULE getModHandle(const std::string& modId)
	{
		return reinterpret_cast<HMODULE(__stdcall*)(const std::string&)>(GetProcAddress(GetModuleHandleA("4DModLoader-Core.dll"), "getModHandle"))(modId);
	}
	inline std::string getModloaderVersion()
	{
		return reinterpret_cast<std::string(__stdcall*)()>(GetProcAddress(GetModuleHandleA("4DModLoader-Core.dll"), "getModloaderVersion"))();
	}
	inline std::string getGameVersion()
	{
		return reinterpret_cast<std::string(__stdcall*)()>(GetProcAddress(GetModuleHandleA("4DModLoader-Core.dll"), "getGameVersion"))();
	}
	inline std::string getModPath(const std::string& modId)
	{
		return reinterpret_cast<std::string(__stdcall*)(const std::string&)>(GetProcAddress(GetModuleHandleA("4DModLoader-Core.dll"), "getModPath"))(modId);
	}
	// useful for creating library mod headers
	inline FARPROC getModFuncPointer(const std::string& modId, const std::string& funcName)
	{
		HMODULE modModule = getModHandle(modId);
		if (modModule == nullptr) return nullptr;
		return GetProcAddress(modModule, funcName.c_str());
	}

	/* 
	Compares two version strings with an operator string
	operators are "==" | ">=" | "<=" | "<" | ">" | "!="
	it is used by modloader to check dependency versions
	*/
	inline bool versionCompare(const std::string& aVer, const std::string& op, const std::string& bVer)
	{
		return reinterpret_cast<bool(__stdcall*)(const std::string&, const std::string&, const std::string&)>(GetProcAddress(GetModuleHandleA("4DModLoader-Core.dll"), "versionCompare"))(aVer, op, bVer);
	}
	// splits string by a delimiter
	inline std::vector<std::string> splitStr(const std::string& str, char delim)
	{
		std::vector<std::string> tokens;
		size_t pos = 0;
		size_t len = str.length();
		tokens.reserve(len / 2);  // allocate memory for expected number of tokens

		while (pos < len)
		{
			size_t end = str.find_first_of(delim, pos);
			if (end == std::string::npos)
			{
				tokens.emplace_back(str.substr(pos));
				break;
			}
			tokens.emplace_back(str.substr(pos, end - pos));
			pos = end + 1;
		}

		return tokens;
	}
}

#include "Console.h"

// used by modloader
extern "C" inline __declspec(dllexport) void setModID(const std::string& modID) { fdm::modID = modID; }

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

// allows to execute any code at any location
#define $exec                                                                                  \
	template <class>                                                                              \
	void CONCAT(fdmEFunc, __LINE__)();                                             \
	namespace \
	{                                                                                   \
		struct CONCAT(fdmEFuncU, __LINE__) {};                                         \
	}                                                                                             \
	static inline auto CONCAT(fdmEFuncC, __LINE__) =                                             \
		(CONCAT(fdmEFunc, __LINE__) < CONCAT(fdmEFuncU, __LINE__) > (), \
		 0);                                                                                      \
	template <class>                                                                              \
	void CONCAT(fdmEFunc, __LINE__)()

/*
creates a hook for a member function (__thiscall)
to call the original function, do `original(self, <all of the you have arguments>)`
`this` pointer is called `self`
*/
#define $hook(returnType, cl, function, ...) \
	namespace fdmHooks::cl \
	{ \
		class CONCAT(function, H) \
		{ \
		public: \
			inline static returnType(__thiscall* original)(fdm::cl* self, __VA_ARGS__) = nullptr; \
			static returnType __fastcall hook(fdm::cl* self, __VA_ARGS__); \
		}; \
	} \
	$exec \
	{ \
		uint64_t hookAddr = getFuncAddr((int)(fdm::Func::cl::function)); \
		if(hookAddr <= 0) { printf("Failed To Hook " #cl "::" #function "\n"); return; } \
		Hook(hookAddr, &fdmHooks::cl::CONCAT(function, H)::hook, &fdmHooks::cl::CONCAT(function, H)::original); \
		EnableHook(); \
	} \
	inline returnType __fastcall fdmHooks::cl::CONCAT(function, H)::hook(fdm::cl* self, __VA_ARGS__)

/*
creates a hook for a member function (__thiscall) using Func namespace. Useful for hooking functions of classes inside classes/namespaces (like gui classes). Because it turned out to not work properly with those (yea i havent tested it properly previously bruh)
to call the original function, do `original(self, <all of the you have arguments>)`
`this` pointer is called `self`
*/
#define $hookByFunc(returnType, className, func, ...) \
	namespace fdmHooks::func \
	{ \
		class CONCAT(className, H) \
		{ \
		public: \
			inline static returnType(__thiscall* original)(fdm::className* self, __VA_ARGS__) = nullptr; \
			static returnType __fastcall hook(fdm::className* self, __VA_ARGS__); \
		}; \
	} \
	$exec \
	{ \
		uint64_t hookAddr = getFuncAddr((int)(fdm::func)); \
		if(hookAddr <= 0) { printf("Failed To Hook " #func "\n"); return; } \
		Hook(hookAddr, &fdmHooks::func::CONCAT(className, H)::hook, &fdmHooks::func::CONCAT(className, H)::original); \
		EnableHook(); \
	} \
	inline returnType __fastcall fdmHooks::func::CONCAT(className, H)::hook(fdm::className* self, __VA_ARGS__)

/*
creates a hook for a static function (__fastcall)
to call the original function, do `original(<all of the you have arguments>)`
*/
#define $hookStatic(returnType, cl, function, ...) \
	namespace fdmHooks::cl \
	{ \
		class CONCAT(function, H)  \
		{ \
		public: \
			inline static returnType(__fastcall* original)(__VA_ARGS__) = nullptr;\
			static returnType __fastcall hook(__VA_ARGS__); \
		}; \
	} \
	$exec \
	{ \
		uint64_t hookAddr = getFuncAddr((int)(fdm::Func::cl::function)); \
		if(hookAddr <= 0) { printf("Failed To Hook " #cl "::" #function "\n"); return; } \
		Hook(hookAddr, &fdmHooks::cl::CONCAT(function, H)::hook, &fdmHooks::cl::CONCAT(function, H)::original); \
		EnableHook(); \
	} \
	inline returnType __fastcall fdmHooks::cl::CONCAT(function, H)::hook(__VA_ARGS__)

/*
creates a hook for a static function (__fastcall) using Func namespace. Useful for hooking functions of classes inside classes/namespaces (like gui classes). Because it turned out to not work properly with those (yea i havent tested it properly previously bruh)
to call the original function, do `original(<all of the you have arguments>)`
*/
#define $hookStaticByFunc(returnType, className, func, ...) \
	namespace fdmHooks::func \
	{ \
		class CONCAT(className, H) \
		{ \
		public: \
			inline static returnType(__fastcall* original)(__VA_ARGS__) = nullptr; \
			static returnType __fastcall hook(__VA_ARGS__); \
		}; \
	} \
	$exec \
	{ \
		uint64_t hookAddr = getFuncAddr((int)(fdm::func)); \
		if(hookAddr <= 0) { printf("Failed To Hook " #func "\n"); return; } \
		Hook(hookAddr, &fdmHooks::func::CONCAT(className, H)::hook, &fdmHooks::func::CONCAT(className, H)::original); \
		EnableHook(); \
	} \
	inline returnType __fastcall fdmHooks::func::CONCAT(className, H)::hook(__VA_ARGS__)

#ifdef DEBUG_CONSOLE
#define initDLL \
	BOOL APIENTRY DllMain(HMODULE hModule, DWORD _reason, LPVOID lpReserved) \
	{ \
		if (_reason == DLL_PROCESS_ATTACH) \
			fdm::startConsole(); \
		return TRUE; \
	}
#else
#define initDLL \
	BOOL APIENTRY DllMain(HMODULE hModule, DWORD _reason, LPVOID lpReserved) \
	{ \
		return TRUE; \
	}
#endif

#endif
