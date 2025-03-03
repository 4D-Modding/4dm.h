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
#include <sstream>
#include <windows.h>
#include <cstdint>
#include <stdio.h>
#include "stl/string.hpp"
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

inline void patchMemory(uintptr_t addressToWrite, uint8_t* valueToWrite, int byteNum)
{
	unsigned long OldProtection;
	VirtualProtect((LPVOID)(addressToWrite), byteNum, PAGE_EXECUTE_READWRITE, &OldProtection);
	memcpy((LPVOID)addressToWrite, valueToWrite, byteNum);
	VirtualProtect((LPVOID)(addressToWrite), byteNum, OldProtection, NULL);
}

namespace fdm
{
	inline uintptr_t base = reinterpret_cast<uintptr_t>(GetModuleHandle(0));

	inline fdm::stl::string modID = "";
	
	namespace Func {
		namespace AudioManager {
			inline constexpr int loadSound = 0;
			inline constexpr int playSound4D = 1;
			inline constexpr int setListenerInfo4D = 2;
			inline constexpr int loadBGMfromJSON = 3;
			inline constexpr int updateBGM = 4;
			inline constexpr int getSound = 5;
			inline constexpr int getVoiceGroupInfo = 6;
		}
		namespace Hitbox {
			inline constexpr int addVelWithMaxHorizSpeed = 7;
			inline constexpr int update = 8;
			inline constexpr int isIntersectingRay = 9;
			inline constexpr int takeStep = 10;
		}
		namespace KleinBottle {
			inline constexpr int buffData = 11;
			inline constexpr int attrSize = 12;
			inline constexpr int KleinBottle = 13;
			inline constexpr int buffSize = 14;
			inline constexpr int destr_KleinBottle = 15;
		}
		namespace Connection {
			namespace InMessage {
				inline constexpr int InMessageDeleter = 16;
				inline constexpr int destr_InMessage = 17;
			}
		}
		namespace Connection {
			namespace OutMessage {
				inline constexpr int createMessage = 18;
				inline constexpr int OutMessage = 19;
				inline constexpr int ReleaseHeapMessageData = 20;
			}
		}
		namespace Connection {
			namespace Client {
				inline constexpr int update = 21;
				inline constexpr int resolveHost = 22;
				inline constexpr int cleanup = 23;
				inline constexpr int connectionStatusChangedCallback = 24;
			}
		}
		namespace WorldTitleScreen {
			inline constexpr int loadCube = 25;
			inline constexpr int loadChunk = 26;
			inline constexpr int updateChunkCache = 27;
			inline constexpr int generateMesh = 28;
			inline constexpr int loadChunks = 29;
		}
		namespace FontRenderer {
			inline constexpr int FontRenderer = 30;
			inline constexpr int FontRendererA = 31;
			inline constexpr int setText = 32;
			inline constexpr int render = 33;
			inline constexpr int updateModel = 34;
			inline constexpr int move = 35;
		}
		namespace TexRenderer {
			inline constexpr int destr_TexRenderer = 36;
			inline constexpr int operatorEq = 37;
			inline constexpr int init = 38;
			inline constexpr int setClip = 39;
			inline constexpr int setColor = 40;
			inline constexpr int setPos = 41;
		}
		namespace Dodecaplex {
			inline constexpr int buffCount = 42;
			inline constexpr int buffData = 43;
			inline constexpr int buffSize = 44;
			inline constexpr int attrSize = 45;
			inline constexpr int generateMesh = 46;
			inline constexpr int generateCellColors = 47;
			inline constexpr int addFaces = 48;
			inline constexpr int addCells = 49;
			inline constexpr int destr_Dodecaplex = 50;
		}
		namespace Skybox {
			inline constexpr int buffData = 51;
			inline constexpr int buffSize = 52;
			inline constexpr int attrSize = 53;
			inline constexpr int vertCount = 54;
		}
		namespace PentachoronHollow {
			inline constexpr int buffData = 55;
			inline constexpr int PentachoronHollow = 56;
			inline constexpr int buffSize = 57;
			inline constexpr int vertCount = 58;
			inline constexpr int addTetSide = 59;
		}
		namespace Hypersphere {
			namespace VertInfo {
				inline constexpr int VertInfo = 60;
				inline constexpr int destr_VertInfo = 61;
				inline constexpr int add = 62;
				inline constexpr int addA = 63;
			}
		}
		namespace Hypersphere {
			inline constexpr int attrCount = 64;
			inline constexpr int attrType = 65;
			inline constexpr int buffCount = 66;
			inline constexpr int Hypersphere = 67;
			inline constexpr int HypersphereA = 68;
			inline constexpr int generateSpherePolygons = 69;
			inline constexpr int addWedgeSide = 70;
			inline constexpr int addCubeSide = 71;
		}
		namespace MeshRenderer {
			inline constexpr int MeshRenderer = 72;
			inline constexpr int setMesh = 73;
			inline constexpr int updateMesh = 74;
			inline constexpr int destr_MeshRenderer = 75;
			inline constexpr int render = 76;
			inline constexpr int init = 77;
			inline constexpr int cleanup = 78;
			inline constexpr int initAttrs = 79;
		}
		namespace PlayerSkin {
			namespace SkinMesh {
				inline constexpr int vertCount = 80;
				inline constexpr int destr_SkinMesh = 81;
				inline constexpr int generate = 82;
				inline constexpr int buffSize = 83;
				inline constexpr int attrCount = 84;
				inline constexpr int attrType = 85;
				inline constexpr int attrSize = 86;
				inline constexpr int attrStride = 87;
				inline constexpr int addPixelToFace = 88;
			}
		}
		namespace PlayerSkin {
			inline constexpr int load = 89;
			inline constexpr int generateMesh = 90;
			inline constexpr int destr_PlayerSkin = 91;
		}
		namespace Tex2D {
			inline constexpr int destr_Tex2D = 92;
			inline constexpr int loadRawImageData = 93;
			inline constexpr int initFromTexID = 94;
			inline constexpr int loadArrayTexture = 95;
		}
		namespace StateCredits {
			inline constexpr int init = 96;
			inline constexpr int update = 97;
			inline constexpr int render = 98;
			inline constexpr int windowResize = 99;
			inline constexpr int keyInput = 100;
			inline constexpr int updateProjection = 101;
		}
		namespace StateCreateWorld {
			inline constexpr int StateCreateWorld = 102;
			inline constexpr int init = 103;
			inline constexpr int close = 104;
			inline constexpr int update = 105;
			inline constexpr int render = 106;
			inline constexpr int resume = 107;
			inline constexpr int mouseInput = 108;
			inline constexpr int scrollInput = 109;
			inline constexpr int keyInput = 110;
			inline constexpr int windowResize = 111;
			inline constexpr int charInput = 112;
			inline constexpr int createNewWorld = 113;
			inline constexpr int viewportCallback = 114;
			inline constexpr int caveCheckboxCallback = 115;
			inline constexpr int handleCreateButton = 116;
		}
		namespace StateTitleScreen {
			inline constexpr int quitGameButtonCallback = 117;
			inline constexpr int settingsButtonCallback = 118;
			inline constexpr int StateTitleScreen = 119;
			inline constexpr int updateProjection = 120;
			inline constexpr int singleplayerButtonCallback = 121;
			inline constexpr int multiplayerplayerButtonCallback = 122;
			inline constexpr int creditsButtonCallback = 123;
			inline constexpr int tutorialButtonCallback = 124;
			inline constexpr int init = 125;
			inline constexpr int close = 126;
			inline constexpr int update = 127;
			inline constexpr int render = 128;
			inline constexpr int pause = 129;
			inline constexpr int resume = 130;
			inline constexpr int keyInput = 131;
			inline constexpr int windowResize = 132;
			inline constexpr int mouseInput = 133;
			inline constexpr int mouseButtonInput = 134;
			inline constexpr int renderBackground = 135;
		}
		namespace StateGame {
			inline constexpr int StateGame = 136;
			inline constexpr int resetMouse = 137;
			inline constexpr int updateProjection2D = 138;
			inline constexpr int viewportCallback = 139;
			inline constexpr int updateChatMessages = 140;
			inline constexpr int init = 141;
			inline constexpr int close = 142;
			inline constexpr int pause = 143;
			inline constexpr int resume = 144;
			inline constexpr int update = 145;
			inline constexpr int render = 146;
			inline constexpr int mouseInput = 147;
			inline constexpr int scrollInput = 148;
			inline constexpr int mouseButtonInput = 149;
			inline constexpr int keyInput = 150;
			inline constexpr int windowResize = 151;
			inline constexpr int charInput = 152;
			inline constexpr int updateProjection = 153;
			inline constexpr int setWorld = 154;
			inline constexpr int addChatMessage = 155;
		}
		namespace StateWorldGen {
			inline constexpr int updateProjection = 156;
			inline constexpr int init = 157;
			inline constexpr int update = 158;
			inline constexpr int render = 159;
			inline constexpr int windowResize = 160;
		}
		namespace StateMultiplayer {
			inline constexpr int destr_StateMultiplayer = 161;
			inline constexpr int StateMultiplayer = 162;
			inline constexpr int updateProjection = 163;
			inline constexpr int cancelButtonCallback = 164;
			inline constexpr int changeSkinButtonCallback = 165;
			inline constexpr int joinButtonCallback = 166;
			inline constexpr int viewportCallback = 167;
			inline constexpr int uuidCopyButtonCallback = 168;
			inline constexpr int init = 169;
			inline constexpr int close = 170;
			inline constexpr int update = 171;
			inline constexpr int render = 172;
			inline constexpr int mouseInput = 173;
			inline constexpr int scrollInput = 174;
			inline constexpr int mouseButtonInput = 175;
			inline constexpr int keyInput = 176;
			inline constexpr int windowResize = 177;
			inline constexpr int charInput = 178;
			inline constexpr int rejoin = 179;
			inline constexpr int connect = 180;
			inline constexpr int connectionErrorOkButtonCallback = 181;
		}
		namespace StateSingleplayer {
			inline constexpr int mouseButtonInput = 182;
			inline constexpr int updateProjection = 183;
			inline constexpr int StateSingleplayer = 184;
			inline constexpr int updateWorldListContainer = 185;
			inline constexpr int createCallback = 186;
			inline constexpr int viewportCallback = 187;
			inline constexpr int worldButtonCallback = 188;
			inline constexpr int init = 189;
			inline constexpr int close = 190;
			inline constexpr int update = 191;
			inline constexpr int resume = 192;
			inline constexpr int windowResize = 193;
			inline constexpr int queueWorldLoad = 194;
		}
		namespace StateDeathScreen {
			inline constexpr int updateProjection = 195;
			inline constexpr int retryButtonCallback = 196;
			inline constexpr int init = 197;
			inline constexpr int close = 198;
			inline constexpr int update = 199;
			inline constexpr int render = 200;
			inline constexpr int mouseInput = 201;
			inline constexpr int scrollInput = 202;
			inline constexpr int mouseButtonInput = 203;
			inline constexpr int keyInput = 204;
			inline constexpr int windowResize = 205;
		}
		namespace StateErrorScreen {
			inline constexpr int okButtonCallback = 206;
			inline constexpr int init = 207;
			inline constexpr int close = 208;
			inline constexpr int update = 209;
			inline constexpr int render = 210;
			inline constexpr int mouseButtonInput = 211;
			inline constexpr int windowResize = 212;
		}
		namespace StateIntro {
			inline constexpr int updateProjection = 213;
			inline constexpr int loadFiles = 214;
			inline constexpr int init = 215;
			inline constexpr int update = 216;
			inline constexpr int render = 217;
			inline constexpr int windowResize = 218;
		}
		namespace StateTutorial {
			inline constexpr int destr_StateTutorial = 219;
			inline constexpr int StateTutorial = 220;
			inline constexpr int updateProjection = 221;
			inline constexpr int backButtonCallback = 222;
			inline constexpr int nextButtonCallback = 223;
			inline constexpr int generateMesh = 224;
			inline constexpr int getSmoothLighting = 225;
			inline constexpr int updatePlayerComponentVectors = 226;
			inline constexpr int updatePlayerPos = 227;
			inline constexpr int updateCurrentBlock = 228;
			inline constexpr int handleCollision = 229;
			inline constexpr int setForgSprite = 230;
			inline constexpr int init = 231;
			inline constexpr int close = 232;
			inline constexpr int update = 233;
			inline constexpr int render = 234;
			inline constexpr int resume = 235;
			inline constexpr int mouseInput = 236;
			inline constexpr int scrollInput = 237;
			inline constexpr int mouseButtonInput = 238;
			inline constexpr int keyInput = 239;
			inline constexpr int windowResize = 240;
			inline constexpr int charInput = 241;
			inline constexpr int updateViewport = 242;
		}
		namespace StateTutorialSlideshow {
			inline constexpr int destr_StateTutorialSlideshow = 243;
			inline constexpr int StateTutorialSlideshow = 244;
			inline constexpr int updateProjection = 245;
			inline constexpr int updateSlideSize = 246;
			inline constexpr int viewportCallback = 247;
			inline constexpr int init = 248;
			inline constexpr int update = 249;
			inline constexpr int render = 250;
			inline constexpr int resume = 251;
			inline constexpr int windowResize = 252;
			inline constexpr int continueButtonCallback = 253;
			inline constexpr int backButtonCallback = 254;
			inline constexpr int setSlide = 255;
		}
		namespace StateSkinChooser {
			inline constexpr int mouseInput = 256;
			inline constexpr int scrollInput = 257;
			inline constexpr int keyInput = 258;
			inline constexpr int StateSkinChooser = 259;
			inline constexpr int updateProjection = 260;
			inline constexpr int viewportCallback = 261;
			inline constexpr int chooseFileButtonCallback = 262;
			inline constexpr int init = 263;
			inline constexpr int close = 264;
			inline constexpr int update = 265;
			inline constexpr int render = 266;
			inline constexpr int windowResize = 267;
			inline constexpr int fileDrop = 268;
			inline constexpr int getSkinMessage = 269;
			inline constexpr int loadSkin = 270;
		}
		namespace StateSettings {
			inline constexpr int updateProjection = 271;
			inline constexpr int destr_StateSettings = 272;
			inline constexpr int StateSettings = 273;
			inline constexpr int getSetting = 274;
			inline constexpr int renderDistanceSliderCallback = 275;
			inline constexpr int scrollSensitivitySliderCallback = 276;
			inline constexpr int lookSensitivitySliderCallback = 277;
			inline constexpr int xInvertCheckBoxCallback = 278;
			inline constexpr int yInvertCheckBoxCallback = 279;
			inline constexpr int fovSliderCallback = 280;
			inline constexpr int globalVolumeSliderCallback = 281;
			inline constexpr int musicVolumeSliderCallback = 282;
			inline constexpr int creatureVolumeSliderCallback = 283;
			inline constexpr int ambienceVolumeSliderCallback = 284;
			inline constexpr int controlsButtonCallback = 285;
			inline constexpr int controlsOkButtonCallback = 286;
			inline constexpr int fullscreenButtonCallback = 287;
			inline constexpr int difficultySliderCallback = 288;
			inline constexpr int smoothLightingCheckBoxCallback = 289;
			inline constexpr int shadowsCheckBoxCallback = 290;
			inline constexpr int lightsCheckBoxCallback = 291;
			inline constexpr int chatCheckBoxCallback = 292;
			inline constexpr int nametagsCheckBoxCallback = 293;
			inline constexpr int skinsCheckBoxCallback = 294;
			inline constexpr int secretButtonCallback = 295;
			inline constexpr int viewportCallback = 296;
			inline constexpr int updateStateGame = 297;
			inline constexpr int updateVolume = 298;
			inline constexpr int load = 299;
			inline constexpr int save = 300;
			inline constexpr int init = 301;
			inline constexpr int close = 302;
			inline constexpr int render = 303;
			inline constexpr int mouseInput = 304;
			inline constexpr int scrollInput = 305;
			inline constexpr int mouseButtonInput = 306;
			inline constexpr int keyInput = 307;
			inline constexpr int windowResize = 308;
			inline constexpr int updateRenderDistance = 309;
			inline constexpr int updateFOV = 310;
			inline constexpr int updateCreatureVolume = 311;
			inline constexpr int updateAmbienceVolume = 312;
			inline constexpr int updateDifficulty = 313;
			inline constexpr int setFullscreenMode = 314;
		}
		namespace StatePause {
			inline constexpr int StatePause = 315;
			inline constexpr int updateProjection = 316;
			inline constexpr int update = 317;
			inline constexpr int render = 318;
			inline constexpr int pause = 319;
			inline constexpr int resume = 320;
			inline constexpr int windowResize = 321;
		}
		namespace StateManager {
			inline constexpr int pushState = 322;
		}
		namespace m4 {
			namespace Mat5 {
				inline constexpr int operatorInd = 323;
				inline constexpr int Mat5 = 324;
				inline constexpr int Mat5A = 325;
				inline constexpr int toJson = 326;
				inline constexpr int operatorMult = 327;
				inline constexpr int operatorMultEQ = 328;
				inline constexpr int multiply = 329;
				inline constexpr int operatorMult_A = 330;
				inline constexpr int translate = 331;
				inline constexpr int scale = 332;
			}
		}
		namespace m4 {
			namespace Rotor {
				inline constexpr int Rotor = 333;
				inline constexpr int RotorA = 334;
				inline constexpr int operatorMultEq = 335;
				inline constexpr int rotate = 336;
				inline constexpr int normalize = 337;
			}
		}
		namespace m4 {
			namespace BiVector4 {
				inline constexpr int BiVector4 = 338;
				inline constexpr int BiVector4A = 339;
				inline constexpr int toJson = 340;
				inline constexpr int normalize = 341;
			}
		}
		namespace m4 {
			inline constexpr int i64vec3ToJson = 342;
			inline constexpr int ivec4ToJson = 343;
			inline constexpr int vec4ToJson = 344;
			inline constexpr int vec4FromJson = 345;
			inline constexpr int cross = 346;
			inline constexpr int adjustToMaxHorizSpeed = 347;
			inline constexpr int createCamera = 833;
		}
		namespace Item {
			inline constexpr int loadItemInfo = 348;
			inline constexpr int renderItem = 349;
			inline constexpr int renderItemDescription = 350;
			inline constexpr int createFromJson = 351;
			inline constexpr int giveMax = 352;
			inline constexpr int giveOne = 353;
			inline constexpr int instantiateItem = 354;
			inline constexpr int combineItemAttributes = 355;
			inline constexpr int save = 356;
			inline constexpr int destr_Item = 357;
			inline constexpr int takeMax = 358;
			inline constexpr int takeHalf = 359;
		}
		namespace World {
			inline constexpr int World = 360;
			inline constexpr int getChunk = 361;
			inline constexpr int getChunkFromCoords = 362;
			inline constexpr int getEntityIntersection = 363;
			inline constexpr int castRay = 364;
			inline constexpr int addEntityToChunk = 365;
		}
		namespace BlockInfo {
			namespace ItemMesh {
				inline constexpr int destr_ItemMesh = 366;
			}
		}
		namespace BlockInfo {
			inline constexpr int renderItemMesh = 367;
		}
		namespace ItemBlock {
			inline constexpr int render = 368;
			inline constexpr int renderEntity = 369;
			inline constexpr int isDeadly = 370;
			inline constexpr int isCompatible = 371;
			inline constexpr int saveAttributes = 372;
			inline constexpr int action = 373;
			inline constexpr int postAction = 374;
			inline constexpr int clone = 375;
		}
		namespace ItemTool {
			inline constexpr int render = 376;
			inline constexpr int renderEntity = 377;
			inline constexpr int isDeadly = 378;
			inline constexpr int isCompatible = 379;
			inline constexpr int getStackLimit = 380;
			inline constexpr int action = 381;
			inline constexpr int breakBlock = 382;
			inline constexpr int entityAction = 383;
			inline constexpr int clone = 384;
		}
		namespace ItemMaterial {
			inline constexpr int getStackLimit = 385;
			inline constexpr int getName = 386;
			inline constexpr int render = 387;
			inline constexpr int renderEntity = 388;
			inline constexpr int isDeadly = 389;
			inline constexpr int isCompatible = 390;
			inline constexpr int action = 391;
			inline constexpr int postAction = 392;
			inline constexpr int clone = 393;
		}
		namespace Chunk {
			namespace ChunkMesh {
				inline constexpr int destr_ChunkMesh = 394;
				inline constexpr int ChunkMesh = 395;
				inline constexpr int buffSize = 396;
				inline constexpr int attrCount = 397;
				inline constexpr int attrType = 398;
				inline constexpr int attrSize = 399;
				inline constexpr int attrStride = 400;
				inline constexpr int indexBuffData = 401;
				inline constexpr int move = 402;
				inline constexpr int addMeshSide = 403;
				inline constexpr int addMeshPlant = 404;
			}
		}
		namespace Chunk {
			inline constexpr int Chunk = 405;
			inline constexpr int setBlock = 406;
			inline constexpr int generateMesh = 407;
			inline constexpr int updateEntitiesClient = 408;
			inline constexpr int clearEntities = 409;
			inline constexpr int render = 410;
			inline constexpr int updateLightingHeightMap = 411;
			inline constexpr int updateMesh = 412;
			inline constexpr int load = 413;
			inline constexpr int save = 414;
			inline constexpr int loadFromMessage = 415;
			inline constexpr int updateCacheSection = 416;
			inline constexpr int updateHeightmapCacheSection = 417;
			inline constexpr int generateMeshSection = 418;
			inline constexpr int getSmoothLighting = 419;
			inline constexpr int getLighting = 420;
			inline constexpr int enableMesh = 421;
			inline constexpr int loadEntitiesFromJson = 422;
			inline constexpr int getFilenamePrefix = 423;
		}
		namespace ChunkLoader {
			namespace BiomeInfo {
				inline constexpr int destr_BiomeInfo = 424;
				inline constexpr int BiomeInfo = 425;
			}
		}
		namespace ChunkLoader {
			inline constexpr int init = 426;
			inline constexpr int loadChunk = 427;
			inline constexpr int loadBiomes = 428;
			inline constexpr int loadInfo = 429;
			inline constexpr int generateChunk = 430;
			inline constexpr int getBiome = 431;
			inline constexpr int generateTree = 432;
			inline constexpr int generateTreeBranch = 433;
			inline constexpr int generateTaigaTree = 434;
			inline constexpr int createFlatWorldChests = 435;
		}
		namespace CloudChunk {
			namespace CloudChunkMesh {
				inline constexpr int indexBuffSize = 436;
				inline constexpr int buffSize = 437;
				inline constexpr int attrSize = 438;
				inline constexpr int attrStride = 439;
				inline constexpr int move = 440;
				inline constexpr int destr_CloudChunkMesh = 441;
			}
		}
		namespace CloudChunk {
			inline constexpr int generateMesh = 442;
		}
		namespace CloudManager {
			inline constexpr int destr_CloudManager = 443;
			inline constexpr int render = 444;
			inline constexpr int updateChunks = 445;
			inline constexpr int unloadAllChunks = 446;
			inline constexpr int loadChunks = 447;
			inline constexpr int updateChunk = 448;
		}
		namespace CraftingMenu {
			namespace CraftableRecipe {
				inline constexpr int destr_CraftableRecipe = 449;
				inline constexpr int CraftableRecipe = 450;
			}
		}
		namespace CraftingMenu {
			inline constexpr int loadRecipes = 451;
			inline constexpr int render = 452;
			inline constexpr int offsetX = 453;
			inline constexpr int offsetY = 454;
			inline constexpr int getPos = 455;
			inline constexpr int getSize = 456;
			inline constexpr int mouseButtonInput = 457;
			inline constexpr int updateAvailableRecipes = 458;
		}
		namespace Entity {
			inline constexpr int loadEntityInfo = 459;
			inline constexpr int createFromJson = 460;
			inline constexpr int createWithAttributes = 461;
			inline constexpr int save = 462;
			inline constexpr int instantiateEntity = 463;
			inline constexpr int combineEntityAttributes = 464;
			inline constexpr int destr_Entity = 465;
		}
		namespace InventoryPlayer {
			inline constexpr int addItem = 466;
			inline constexpr int begin = 467;
			inline constexpr int render = 468;
			inline constexpr int combineItem = 469;
			inline constexpr int placeItem = 470;
			inline constexpr int getSlotIndex = 471;
			inline constexpr int getSlotCount = 472;
			inline constexpr int getSlot = 473;
			inline constexpr int end = 474;
		}
		namespace InventoryGrid {
			inline constexpr int destr_InventoryGrid = 475;
			inline constexpr int InventoryGrid = 476;
			inline constexpr int render = 477;
			inline constexpr int combineItem = 478;
			inline constexpr int placeItem = 479;
			inline constexpr int getSlotIndex = 480;
			inline constexpr int getSlotCount = 481;
			inline constexpr int getSlot = 482;
			inline constexpr int end = 483;
			inline constexpr int load = 484;
			inline constexpr int save = 485;
		}
		namespace InventorySession {
			inline constexpr int destr_InventorySession = 486;
		}
		namespace InventoryManager {
			inline constexpr int destr_InventoryManager = 487;
			inline constexpr int renderInit = 488;
			inline constexpr int mouseButtonInput = 489;
			inline constexpr int windowResize = 490;
			inline constexpr int applyAction = 491;
			inline constexpr int applyTransfer = 492;
			inline constexpr int findInventory = 493;
			inline constexpr int updateCraftingMenuBox = 494;
			inline constexpr int craftingMenuCallback = 495;
			inline constexpr int viewportCallback = 496;
			inline constexpr int updateProjection = 497;
		}
		namespace MeshBuilder {
			inline constexpr int MeshBuilder = 498;
			inline constexpr int MeshBuilder_A = 499;
			inline constexpr int destr_MeshBuilder = 500;
			inline constexpr int buffCount = 501;
			inline constexpr int buffSize = 502;
			inline constexpr int attrCount = 503;
			inline constexpr int vertCount = 504;
			inline constexpr int indexBuffSize = 505;
			inline constexpr int addBuff = 506;
			inline constexpr int attrType = 507;
			inline constexpr int attrSize = 508;
			inline constexpr int attrStride = 509;
			inline constexpr int addAttr = 510;
			inline constexpr int clear = 511;
		}
		namespace Player {
			inline constexpr int destr_Player = 512;
			inline constexpr int Player = 513;
			inline constexpr int updatePos = 514;
			inline constexpr int updateCurrentBlock = 515;
			inline constexpr int handleCollision = 516;
			inline constexpr int updateComponentVectors = 517;
			inline constexpr int updateAllComponentVectors = 518;
			inline constexpr int removeVelComp = 519;
			inline constexpr int updateTargetBlock = 520;
			inline constexpr int init = 521;
			inline constexpr int renderHud = 522;
			inline constexpr int renderTargetBlock = 523;
			inline constexpr int getMovementUpdate = 524;
			inline constexpr int setMovementBehavior = 525;
			inline constexpr int hitTargetBlock = 526;
			inline constexpr int breakBlock = 527;
			inline constexpr int throwItem = 528;
			inline constexpr int update = 529;
			inline constexpr int updateLocal = 530;
			inline constexpr int updateCameraPos = 531;
			inline constexpr int resetMouse = 532;
			inline constexpr int keyInput = 533;
			inline constexpr int mouseInput = 534;
			inline constexpr int mouseButtonInput = 535;
			inline constexpr int isHoldingGlasses = 536;
			inline constexpr int isHoldingCompass = 537;
			inline constexpr int isHoldingCollector = 538;
			inline constexpr int headIsInBlock = 539;
			inline constexpr int getHeadBlock = 540;
			inline constexpr int respawn = 541;
			inline constexpr int load = 542;
			inline constexpr int save = 543;
			inline constexpr int loadClientData = 544;
			inline constexpr int saveClientData = 545;
			inline constexpr int saveOrientation = 546;
		}
		namespace QuadRenderer {
			inline constexpr int destr_QuadRenderer = 547;
			inline constexpr int init = 548;
			inline constexpr int setColor = 549;
			inline constexpr int setPos = 550;
		}
		namespace ResourceManager {
			inline constexpr int loadArrayTexture = 551;
			inline constexpr int get = 552;
		}
		namespace ShaderManager {
			inline constexpr int loadFromShaderList = 553;
			inline constexpr int get = 554;
		}
		namespace Shader {
			inline constexpr int load = 555;
			inline constexpr int compileShader = 556;
		}
		namespace WorldManager {
			inline constexpr int destr_WorldManager = 557;
			inline constexpr int updateRenderFrustum = 558;
			inline constexpr int setBlockUpdate = 559;
			inline constexpr int render = 560;
		}
		namespace WorldClient {
			inline constexpr int destr_WorldClient = 561;
			inline constexpr int addEntityToChunk = 562;
			inline constexpr int localPlayerEvent = 563;
			inline constexpr int updateLocal = 564;
			inline constexpr int setRenderDistanceLocal = 565;
			inline constexpr int setSkinVisibility = 566;
			inline constexpr int localPlayerInit = 567;
			inline constexpr int localPlayerRespawn = 568;
			inline constexpr int sendChatMessage = 569;
			inline constexpr int updatePhysics = 570;
			inline constexpr int handleWorldMessage = 571;
			inline constexpr int handleLightingOptionsUpdate = 572;
			inline constexpr int updateChunks = 573;
			inline constexpr int updateChunk = 574;
			inline constexpr int generateChunkMeshes = 575;
			inline constexpr int updateChunkCacheAndMesh = 576;
			inline constexpr int updateChunkCache = 577;
			inline constexpr int regenerateAllChunkMeshes = 578;
			inline constexpr int joinAllChunkLoadingThreads = 579;
			inline constexpr int handleMessage = 580;
			inline constexpr int inventoryUpdateCallback = 581;
		}
		namespace WorldSingleplayer {
			inline constexpr int WorldSingleplayer = 582;
			inline constexpr int destr_WorldSingleplayer = 583;
			inline constexpr int localPlayerEvent = 584;
			inline constexpr int updateLocal = 585;
			inline constexpr int cleanupLocal = 586;
			inline constexpr int setRenderDistanceLocal = 587;
			inline constexpr int setDifficultyLocal = 588;
			inline constexpr int localPlayerInit = 589;
			inline constexpr int localPlayerRespawn = 590;
			inline constexpr int handleLightingOptionsUpdate = 591;
			inline constexpr int updateChunks = 592;
			inline constexpr int updateChunk = 593;
			inline constexpr int loadChunks = 594;
			inline constexpr int loadChunk = 595;
			inline constexpr int updateChunkCacheAndMesh = 596;
			inline constexpr int updateChunkCache = 597;
			inline constexpr int regenerateAllChunkMeshes = 598;
		}
		namespace gui {
			namespace Button {
				inline constexpr int destr_Button = 599;
				inline constexpr int render = 600;
				inline constexpr int mouseButtonInput = 601;
				inline constexpr int keyInput = 602;
				inline constexpr int offsetX = 603;
				inline constexpr int enabled = 604;
				inline constexpr int select = 605;
				inline constexpr int getPos = 606;
				inline constexpr int getSize = 607;
				inline constexpr int touchingMouse = 608;
			}
		}
		namespace gui {
			namespace CheckBox {
				inline constexpr int render = 609;
				inline constexpr int mouseButtonInput = 610;
				inline constexpr int keyInput = 611;
				inline constexpr int getPos = 612;
				inline constexpr int getSize = 613;
				inline constexpr int touchingMouse = 614;
			}
		}
		namespace gui {
			namespace ContentBox {
				inline constexpr int destr_ContentBox = 615;
				inline constexpr int getQuadRenderer = 616;
				inline constexpr int getFont = 617;
				inline constexpr int getGLFWwindow = 618;
				inline constexpr int getCursorPos = 619;
				inline constexpr int getSize = 620;
				inline constexpr int changeViewport = 621;
				inline constexpr int getPos = 622;
				inline constexpr int getSizeA = 623;
				inline constexpr int touchingMouse = 624;
				inline constexpr int resetViewport = 625;
				inline constexpr int render = 626;
				inline constexpr int alignX = 627;
				inline constexpr int alignY = 628;
				inline constexpr int offsetX = 629;
				inline constexpr int offsetY = 630;
				inline constexpr int mouseInput = 631;
				inline constexpr int scrollInput = 632;
				inline constexpr int mouseButtonInput = 633;
				inline constexpr int keyInput = 634;
				inline constexpr int select = 635;
				inline constexpr int deselect = 636;
				inline constexpr int addElement = 637;
				inline constexpr int removeElement = 638;
				inline constexpr int selectElement = 639;
				inline constexpr int clear = 640;
				inline constexpr int empty = 641;
			}
		}
		namespace gui {
			namespace Element {
				inline constexpr int enabled = 642;
				inline constexpr int getCursorType = 643;
			}
		}
		namespace gui {
			namespace Image {
				inline constexpr int offsetX = 644;
				inline constexpr int offsetY = 645;
				inline constexpr int render = 646;
				inline constexpr int getPos = 647;
				inline constexpr int getSize = 648;
			}
		}
		namespace gui {
			namespace Interface {
				inline constexpr int Interface = 649;
				inline constexpr int destr_Interface = 650;
				inline constexpr int render = 651;
				inline constexpr int mouseInput = 652;
				inline constexpr int scrollInput = 653;
				inline constexpr int mouseButtonInput = 654;
				inline constexpr int keyInput = 655;
				inline constexpr int getQuadRenderer = 656;
				inline constexpr int getFont = 657;
				inline constexpr int getGLFWwindow = 658;
				inline constexpr int getCursorPos = 659;
				inline constexpr int getSize = 660;
				inline constexpr int changeViewport = 661;
				inline constexpr int addElement = 662;
				inline constexpr int removeElement = 663;
				inline constexpr int selectElement = 664;
				inline constexpr int clear = 665;
				inline constexpr int empty = 666;
			}
		}
		namespace gui {
			namespace Slider {
				inline constexpr int offsetX = 667;
				inline constexpr int offsetY = 668;
				inline constexpr int deselect = 669;
				inline constexpr int render = 670;
				inline constexpr int mouseButtonInput = 671;
				inline constexpr int mouseInput = 672;
				inline constexpr int keyInput = 673;
				inline constexpr int alignX = 674;
				inline constexpr int alignY = 675;
				inline constexpr int getPos = 676;
				inline constexpr int getSize = 677;
			}
		}
		namespace gui {
			namespace Text {
				inline constexpr int render = 678;
				inline constexpr int offsetX = 679;
				inline constexpr int getPos = 680;
				inline constexpr int getSize = 681;
				inline constexpr int setText = 682;
				inline constexpr int renderText = 683;
			}
		}
		namespace gui {
			namespace TextInput {
				inline constexpr int render = 684;
				inline constexpr int alignX = 685;
				inline constexpr int alignY = 686;
				inline constexpr int offsetX = 687;
				inline constexpr int offsetY = 688;
				inline constexpr int mouseButtonInput = 689;
				inline constexpr int mouseInput = 690;
				inline constexpr int keyInput = 691;
				inline constexpr int charInput = 692;
				inline constexpr int getCursorType = 693;
				inline constexpr int select = 694;
				inline constexpr int deselect = 695;
				inline constexpr int updatePasswordVisualText = 696;
				inline constexpr int updateScrollPos = 697;
				inline constexpr int getPos = 698;
				inline constexpr int getSize = 699;
				inline constexpr int removeInvalidChars = 700;
				inline constexpr int removeHighlightedText = 701;
			}
		}
		namespace EntityButterfly {
			inline constexpr int getName = 702;
			inline constexpr int update = 703;
			inline constexpr int render = 704;
			inline constexpr int getServerUpdateAttributes = 705;
			inline constexpr int applyServerUpdate = 706;
			inline constexpr int takeDamage = 707;
			inline constexpr int playHitSound = 708;
			inline constexpr int playDeathSound = 709;
			inline constexpr int collisionCallback = 710;
		}
		namespace EntityAlidade {
			namespace SPInfo {
				inline constexpr int SPInfo = 711;
				inline constexpr int destr_SPInfo = 712;
			}
		}
		namespace EntityAlidade {
			inline constexpr int getName = 713;
			inline constexpr int update = 714;
			inline constexpr int render = 715;
			inline constexpr int saveAttributes = 716;
			inline constexpr int getPos = 717;
			inline constexpr int setPos = 718;
			inline constexpr int takeDamage = 719;
			inline constexpr int action = 720;
			inline constexpr int postAction = 721;
			inline constexpr int generateSpherinder = 722;
			inline constexpr int generateSpherinderHollow = 723;
			inline constexpr int generateSemicircle = 724;
		}
		namespace EntityItem {
			inline constexpr int createWithItem = 725;
			inline constexpr int getName = 726;
			inline constexpr int update = 727;
			inline constexpr int render = 728;
			inline constexpr int saveAttributes = 729;
			inline constexpr int applyServerUpdate = 730;
			inline constexpr int getPos = 731;
			inline constexpr int setPos = 732;
			inline constexpr int shouldSave = 733;
			inline constexpr int isIntersectingRay = 734;
			inline constexpr int give = 735;
			inline constexpr int combineWithNearby = 736;
			inline constexpr int collisionCallback = 737;
		}
		namespace EntityPlayer {
			inline constexpr int createFromPlayer = 738;
			inline constexpr int EntityPlayer = 739;
			inline constexpr int getName = 740;
			inline constexpr int update = 741;
			inline constexpr int render = 742;
			inline constexpr int saveAttributes = 743;
			inline constexpr int applyServerUpdate = 744;
			inline constexpr int getPos = 745;
			inline constexpr int setPos = 746;
			inline constexpr int isIntersectingRay = 747;
			inline constexpr int takeDamage = 748;
			inline constexpr int deathTimer = 749;
			inline constexpr int applyMovementUpdate = 750;
			inline constexpr int collectItems = 751;
		}
		namespace EntitySpider {
			namespace SpiderType {
				inline constexpr int destr_SpiderType = 752;
			}
		}
		namespace EntitySpider {
			inline constexpr int isIntersectingRay = 753;
			inline constexpr int getPos = 754;
			inline constexpr int setPos = 755;
			inline constexpr int getName = 756;
			inline constexpr int update = 757;
			inline constexpr int render = 758;
			inline constexpr int saveAttributes = 759;
			inline constexpr int getServerUpdateAttributes = 760;
			inline constexpr int applyServerUpdate = 761;
			inline constexpr int takeDamage = 762;
			inline constexpr int playHitSound = 763;
			inline constexpr int playDeathSound = 764;
			inline constexpr int collisionCallback = 765;
			inline constexpr int findPlayer = 766;
			inline constexpr int persuePlayer = 767;
		}
		namespace EntityChest {
			inline constexpr int isClickable = 768;
			inline constexpr int getName = 769;
			inline constexpr int update = 770;
			inline constexpr int render = 771;
			inline constexpr int saveAttributes = 772;
			inline constexpr int getServerUpdateAttributes = 773;
			inline constexpr int applyServerUpdate = 774;
			inline constexpr int getPos = 775;
			inline constexpr int setPos = 776;
			inline constexpr int action = 777;
		}
		namespace EntityDying {
			inline constexpr int deathTimer = 778;
			inline constexpr int createWithEntity = 779;
			inline constexpr int getName = 780;
			inline constexpr int update = 781;
			inline constexpr int render = 782;
			inline constexpr int getServerUpdateAttributes = 783;
			inline constexpr int applyServerUpdate = 784;
			inline constexpr int getPos = 785;
			inline constexpr int setPos = 786;
			inline constexpr int isBlockEntity = 787;
			inline constexpr int isIntersectingRay = 788;
		}
		namespace EntityManager {
			inline constexpr int extract = 789;
			inline constexpr int get = 790;
			inline constexpr int getBlockEntity = 791;
		}
		namespace Coil {
			inline constexpr int Coil = 792;
			inline constexpr int buffSize = 793;
			inline constexpr int attrSize = 794;
		}
		namespace CompassRenderer {
			inline constexpr int renderHand = 795;
			inline constexpr int renderItemDrop = 796;
		}
		namespace DodecaplexWireframe {
			inline constexpr int generateMesh = 797;
			inline constexpr int addFaces = 798;
			inline constexpr int addCells = 799;
		}
		namespace Framebuffer {
			inline constexpr int destr_Framebuffer = 800;
			inline constexpr int render = 801;
			inline constexpr int init = 802;
			inline constexpr int cleanup = 803;
		}
		namespace HypercubeHollow {
			inline constexpr int attrSize = 804;
			inline constexpr int attrStride = 805;
			inline constexpr int HypercubeHollow = 806;
			inline constexpr int addCubeSide = 807;
		}
		namespace PlayerSkinRenderer {
			inline constexpr int PlayerSkinRenderer = 808;
			inline constexpr int render = 809;
			inline constexpr int updateAnimation = 810;
			inline constexpr int resetTransformations = 811;
		}
		namespace PlayerSkinViewer {
			inline constexpr int render = 812;
			inline constexpr int alignX = 813;
			inline constexpr int alignY = 814;
			inline constexpr int getPos = 815;
			inline constexpr int getSize = 816;
			inline constexpr int mouseInput = 817;
			inline constexpr int getCursorType = 818;
			inline constexpr int init = 819;
			inline constexpr int setupFrameBuffer = 820;
		}
		namespace Sphere {
			inline constexpr int vertCount = 821;
			inline constexpr int buffSize = 822;
			inline constexpr int Sphere = 823;
			inline constexpr int generateCirclePolygons = 824;
		}
		namespace main_cpp {
			inline constexpr int main = 825;
			inline constexpr int handleRawMouseInput = 826;
			inline constexpr int scrollCallback = 827;
			inline constexpr int mouseButtonCallback = 828;
			inline constexpr int keyCallback = 829;
			inline constexpr int framebufferSizeCallback = 830;
			inline constexpr int charCallback = 831;
			inline constexpr int fileDropCallback = 832;
		}
	}

	inline void startConsole()
	{
		return reinterpret_cast<void(__stdcall*)()>(GetProcAddress(GetModuleHandleA("4DModLoader-Core.dll"), "startConsole"))();
	}

	inline LPVOID getFuncAddr(int func)
	{
		return reinterpret_cast<LPVOID(__stdcall*)(int)>(GetProcAddress(GetModuleHandleA("4DModLoader-Core.dll"), "getFuncAddr"))(func);
	}
	inline bool isModLoaded(const fdm::stl::string& modId)
	{
		return reinterpret_cast<bool(__stdcall*)(const fdm::stl::string&)>(GetProcAddress(GetModuleHandleA("4DModLoader-Core.dll"), "isModLoaded"))(modId);
	}
	inline bool isDLLLoaded(const fdm::stl::string& dllFileName)
	{
		return reinterpret_cast<bool(__stdcall*)(const fdm::stl::string&)>(GetProcAddress(GetModuleHandleA("4DModLoader-Core.dll"), "isDLLLoaded"))(dllFileName);
	}
	inline fdm::stl::string getModDLL(const fdm::stl::string& modId)
	{
		return reinterpret_cast<fdm::stl::string(__stdcall*)(const fdm::stl::string&)>(GetProcAddress(GetModuleHandleA("4DModLoader-Core.dll"), "getModDLL"))(modId);
	}
	inline fdm::stl::string getModVersion(const fdm::stl::string& modId)
	{
		return reinterpret_cast<fdm::stl::string(__stdcall*)(const fdm::stl::string&)>(GetProcAddress(GetModuleHandleA("4DModLoader-Core.dll"), "getModVersion"))(modId);
	}
	inline fdm::stl::string getModName(const fdm::stl::string& modId)
	{
		return reinterpret_cast<fdm::stl::string(__stdcall*)(const fdm::stl::string&)>(GetProcAddress(GetModuleHandleA("4DModLoader-Core.dll"), "getModName"))(modId);
	}
	inline fdm::stl::string getModAuthor(const fdm::stl::string& modId)
	{
		return reinterpret_cast<fdm::stl::string(__stdcall*)(const fdm::stl::string&)>(GetProcAddress(GetModuleHandleA("4DModLoader-Core.dll"), "getModAuthor"))(modId);
	}
	inline fdm::stl::string getModDescription(const fdm::stl::string& modId)
	{
		return reinterpret_cast<fdm::stl::string(__stdcall*)(const fdm::stl::string&)>(GetProcAddress(GetModuleHandleA("4DModLoader-Core.dll"), "getModDescription"))(modId);
	}
	inline HMODULE getModHandle(const fdm::stl::string& modId)
	{
		return reinterpret_cast<HMODULE(__stdcall*)(const fdm::stl::string&)>(GetProcAddress(GetModuleHandleA("4DModLoader-Core.dll"), "getModHandle"))(modId);
	}
	inline fdm::stl::string getModloaderVersion()
	{
		return reinterpret_cast<fdm::stl::string(__stdcall*)()>(GetProcAddress(GetModuleHandleA("4DModLoader-Core.dll"), "getModloaderVersion"))();
	}
	inline fdm::stl::string getGameVersion()
	{
		return reinterpret_cast<fdm::stl::string(__stdcall*)()>(GetProcAddress(GetModuleHandleA("4DModLoader-Core.dll"), "getGameVersion"))();
	}
	inline fdm::stl::string getModPath(const fdm::stl::string& modId)
	{
		return reinterpret_cast<fdm::stl::string(__stdcall*)(const fdm::stl::string&)>(GetProcAddress(GetModuleHandleA("4DModLoader-Core.dll"), "getModPath"))(modId);
	}
	// useful for creating library mod headers
	inline FARPROC getModFuncPointer(const fdm::stl::string& modId, const fdm::stl::string& funcName)
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
	inline bool versionCompare(const fdm::stl::string& aVer, const fdm::stl::string& op, const fdm::stl::string& bVer)
	{
		return reinterpret_cast<bool(__stdcall*)(const fdm::stl::string&, const fdm::stl::string&, const fdm::stl::string&)>(GetProcAddress(GetModuleHandleA("4DModLoader-Core.dll"), "versionCompare"))(aVer, op, bVer);
	}
	// splits string by a delimiter
	inline std::vector<fdm::stl::string> splitStr(const fdm::stl::string& str, char delim)
	{
		std::vector<fdm::stl::string> tokens;
		size_t pos = 0;
		size_t len = str.length();
		tokens.reserve(len / 2);  // allocate memory for expected number of tokens

		while (pos < len)
		{
			size_t end = str.find_first_of(delim, pos);
			if (end == fdm::stl::string::npos)
			{
				tokens.emplace_back(str.substr(pos));
				break;
			}
			tokens.emplace_back(str.substr(pos, end - pos));
			pos = end + 1;
		}

		return tokens;
	}
	
	inline std::vector<void(*)()> execMacroFunctions;
}

#include "hook.h"
#include "Console.h"

// used by modloader
extern "C" inline __declspec(dllexport) void setModID(const fdm::stl::string& modID) {
	fdm::modID = modID;
	
	for (const auto& execMacroFunction : fdm::execMacroFunctions)
		execMacroFunction();
}

// allows to execute any code at any location, which is run when setModID is called by the modloader
#define $exec \
	template <class> void CONCAT(fdmEFunc, __LINE__)();\
	namespace{ /* empty namespace is only accessible in that file*/\
		struct CONCAT(fdmEStruct, __LINE__) {};\
		inline auto CONCAT(_fdmEVar, __LINE__) = [](){\
			fdm::execMacroFunctions.push_back(&CONCAT(fdmEFunc, __LINE__)<CONCAT(fdmEStruct, __LINE__)>);\
			return true;\
		}();\
	}\
	template <class> void CONCAT(fdmEFunc, __LINE__)()

// Connection namespace
#include "Connection/MessageData.h"
#include "Connection/InMessage.h"
#include "Connection/OutMessage.h"
#include "Connection/Server.h"
#include "Connection/Client.h"
#include "Packet.h" // thats not in Connection namespace for some reason even tho it relates to networking but k

// fuck boost
#include "stl/path.h"
#include "stl/uuid.h"

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

// allows to execute any code at any location, which is run when the dll is loaded
#define $execAtLoad \
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
	namespace CONCAT(fdmHooks, __LINE__) \
	{ \
		class CONCAT(function, H) \
		{ \
		public: \
			inline static returnType(__thiscall* original)(cl* self, ##__VA_ARGS__) = nullptr; \
			static returnType __fastcall hook(cl* self, ##__VA_ARGS__); \
		}; \
	} \
	$exec \
	{ \
		Hook( Func::cl::function, &CONCAT(fdmHooks, __LINE__)::CONCAT(function, H)::hook, &CONCAT(fdmHooks, __LINE__)::CONCAT(function, H)::original ); \
		EnableHook(Func::cl::function); \
	} \
	inline returnType __fastcall CONCAT(fdmHooks, __LINE__)::CONCAT(function, H)::hook(cl* self, ##__VA_ARGS__)

/*
creates a hook for a member function (__thiscall) using Func namespace.
to call the original function, do `original(self, <all of the you have arguments>)`
`this` pointer is called `self`
*/
#define $hookByFunc(returnType, className, func, ...) \
	namespace CONCAT(fdmHooks, __LINE__) \
	{ \
		class H \
		{ \
		public: \
			inline static returnType(__thiscall* original)(className* self, ##__VA_ARGS__) = nullptr; \
			static returnType __fastcall hook(className* self, __VA_ARGS__); \
		}; \
	} \
	$exec \
	{ \
		Hook( (int)func, &CONCAT(fdmHooks, __LINE__)::H::hook, &CONCAT(fdmHooks, __LINE__)::H::original ); \
		EnableHook( (int)func ); \
	} \
	inline returnType __fastcall CONCAT(fdmHooks, __LINE__)::H::hook(className* self, ##__VA_ARGS__)

/*
creates a hook for a static function (__fastcall)
to call the original function, do `original(<all of the you have arguments>)`
*/
#define $hookStatic(returnType, cl, function, ...) \
	namespace CONCAT(fdmHooks, __LINE__) \
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
		Hook( Func::cl::function, &CONCAT(fdmHooks, __LINE__)::CONCAT(function, H)::hook, &CONCAT(fdmHooks, __LINE__)::CONCAT(function, H)::original ); \
		EnableHook(Func::cl::function); \
	} \
	inline returnType __fastcall CONCAT(fdmHooks, __LINE__)::CONCAT(function, H)::hook(__VA_ARGS__)

/*
creates a hook for a static function (__fastcall) using Func namespace.
to call the original function, do `original(<all of the you have arguments>)`
*/
#define $hookStaticByFunc(returnType, func, ...) \
	namespace CONCAT(fdmHooks, __LINE__) \
	{ \
		class H \
		{ \
		public: \
			inline static returnType(__fastcall* original)(__VA_ARGS__) = nullptr; \
			static returnType __fastcall hook(__VA_ARGS__); \
		}; \
	} \
	$exec \
	{ \
		Hook( (int)func, &CONCAT(fdmHooks, __LINE__)::H::hook, &CONCAT(fdmHooks, __LINE__)::H::original); \
		EnableHook( (int)func ); \
	} \
	inline returnType __fastcall CONCAT(fdmHooks, __LINE__)::H::hook(__VA_ARGS__)

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
