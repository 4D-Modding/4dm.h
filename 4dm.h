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
#pragma warning(disable: 4200)

#define SDL_MAIN_HANDLED

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
#include "glfw/glfw.h"
#include <mutex>
#include <set>
#include <unordered_set>

#include "soil/SOIL2.h"

#include "sdl/SDL.h"

#define __STR_CAT___(str1, str2) str1##str2
#define CONCAT(str1, str2) __STR_CAT___(str1, str2)

#ifndef PAD
#define PAD(size) char CONCAT(__, CONCAT(pad, __LINE__))[size] = {}
#endif

#ifndef MBO
// Member By Offset (type, object, offset)
#define MBO(t, c, off) *reinterpret_cast<t*>(reinterpret_cast<uintptr_t>(c) + off)
#endif

#include "hook.h"

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
			inline constexpr int attrCount = 942;
			inline constexpr int attrStride = 943;
			inline constexpr int attrType = 944;
			inline constexpr int buffCount = 945;
			inline constexpr int vertCount = 946;
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
				//inline constexpr int OutMessage = 19;
				inline constexpr int ReleaseHeapMessageData = 20;
				inline constexpr int destr_OutMessage = 956;
				inline constexpr int FreeSteamNetworkingMessagePayload = 957;
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
			inline constexpr int getType = 1075;
			inline constexpr int handleLightingOptionsUpdate = 1076;
			inline constexpr int localPlayerEvent = 1077;
			inline constexpr int localPlayerInit = 1078;
			inline constexpr int localPlayerRespawn = 1079;
		}
		namespace FontRenderer {
			inline constexpr int FontRenderer = 30;
			inline constexpr int FontRendererA = 31;
			inline constexpr int setText = 32;
			inline constexpr int render = 33;
			inline constexpr int updateModel = 34;
			inline constexpr int move = 35;
			inline constexpr int destr_FontRenderer = 1006;
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
			inline constexpr int attrCount = 991;
			inline constexpr int attrStride = 992;
			inline constexpr int attrType = 993;
			inline constexpr int vertCount = 994;
		}
		namespace Skybox {
			inline constexpr int buffData = 51;
			inline constexpr int buffSize = 52;
			inline constexpr int attrSize = 53;
			inline constexpr int vertCount = 54;
			inline constexpr int attrCount = 1052;
			inline constexpr int attrStride = 1053;
			inline constexpr int attrType = 1054;
			inline constexpr int buffCount = 1055;
		}
		namespace PentachoronHollow {
			inline constexpr int buffData = 55;
			inline constexpr int PentachoronHollow = 56;
			inline constexpr int buffSize = 57;
			inline constexpr int vertCount = 58;
			inline constexpr int addTetSide = 59;
			inline constexpr int attrCount = 921;
			inline constexpr int attrSize = 922;
			inline constexpr int attrStride = 923;
			inline constexpr int attrType = 924;
			inline constexpr int buffCount = 925;
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
			inline constexpr int attrSize = 916;
			inline constexpr int attrStride = 917;
			inline constexpr int buffData = 918;
			inline constexpr int buffSize = 919;
			inline constexpr int vertCount = 920;
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
				inline constexpr int buffCount = 926;
				inline constexpr int buffData = 927;
				inline constexpr int indexBuffData = 928;
				inline constexpr int indexBuffSize = 929;
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
			inline constexpr int mouseButtonInput = 971;
			inline constexpr int updateProjection = 972;
			inline constexpr int amplificationSliderCallback = 973;
			inline constexpr int biomeSizeSliderCallback = 974;
			inline constexpr int caveSizeSliderCallback = 975;
			inline constexpr int createWorldCancel = 976;
			inline constexpr int updateAmplificationSliderText = 977;
			inline constexpr int updateBiomeSizeSliderText = 978;
			inline constexpr int updatecaveSizeSliderText = 979;
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
			inline constexpr int charInput = 980;
			inline constexpr int keyInput = 981;
			inline constexpr int mouseInput = 982;
			inline constexpr int render = 983;
			inline constexpr int scrollInput = 984;
			inline constexpr int cancelCallback = 985;
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
			inline constexpr int quitButtonCallback = 986;
		}
		namespace StateErrorScreen {
			inline constexpr int okButtonCallback = 206;
			inline constexpr int init = 207;
			inline constexpr int close = 208;
			inline constexpr int update = 209;
			inline constexpr int render = 210;
			inline constexpr int mouseButtonInput = 211;
			inline constexpr int windowResize = 212;
			inline constexpr int keyInput = 987;
			inline constexpr int mouseInput = 988;
			inline constexpr int scrollInput = 989;
			inline constexpr int updateProjection = 990;
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
			inline constexpr int charInput = 1060;
			inline constexpr int close = 1061;
			inline constexpr int keyInput = 1062;
			inline constexpr int mouseButtonInput = 1063;
			inline constexpr int mouseInput = 1064;
			inline constexpr int scrollInput = 1065;
			inline constexpr int exitButtonCallback = 1066;
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
			inline constexpr int mouseButtonInput = 1009;
			inline constexpr int okButtonCallback = 1010;
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
			inline constexpr int update = 1007;
			inline constexpr int okButtonCallback = 1008;
		}
		namespace StatePause {
			inline constexpr int StatePause = 315;
			inline constexpr int updateProjection = 316;
			inline constexpr int update = 317;
			inline constexpr int render = 318;
			inline constexpr int pause = 319;
			inline constexpr int resume = 320;
			inline constexpr int windowResize = 321;
			inline constexpr int close = 1031;
			inline constexpr int init = 1032;
			inline constexpr int keyInput = 1033;
			inline constexpr int mouseButtonInput = 1034;
			inline constexpr int mouseInput = 1035;
			inline constexpr int scrollInput = 1036;
			inline constexpr int quitButtonCallback = 1037;
			inline constexpr int returnButtonCallback = 1038;
			inline constexpr int settingsButtonCallback = 1039;
		}
		namespace StateManager {
			inline constexpr int pushState = 322;
			inline constexpr int destr_StateManager = 1056;
		}
		namespace m4 {
			namespace Mat5 {
				inline constexpr int operatorInd = 323;
				inline constexpr int Mat5 = 324;
				inline constexpr int Mat5A = 325;
				inline constexpr int toJson = 326;
				inline constexpr int operatorMult = 327;
				inline constexpr int operatorMultEq = 328;
				inline constexpr int multiply = 329;
				inline constexpr int operatorMultA = 330;
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
			inline constexpr int wedge = 881;
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
			inline constexpr int postAction = 846;
			inline constexpr int postBreakBlock = 847;
			inline constexpr int postEntityAction = 848;
			inline constexpr int renderInit = 849;
		}
		namespace World {
			inline constexpr int World = 360;
			inline constexpr int getChunk = 361;
			inline constexpr int getChunkFromCoords = 362;
			inline constexpr int getEntityIntersection = 363;
			inline constexpr int castRay = 364;
			inline constexpr int addEntityToChunk = 365;
			inline constexpr int getBlock = 1073;
			inline constexpr int handlePlayerDeath = 1074;
			inline constexpr int getEntity = 1227; // server
		}
		namespace BlockInfo {
			namespace ItemMesh {
				inline constexpr int destr_ItemMesh = 366;
			}
		}
		namespace BlockInfo {
			inline constexpr int renderItemMesh = 367;
			inline constexpr int getBlockID = 842;
			inline constexpr int renderInit = 843;
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
			inline constexpr int breakBlock = 882;
			inline constexpr int entityAction = 883;
			inline constexpr int getName = 884;
			inline constexpr int getStackLimit = 885;
			inline constexpr int renderInit = 886;
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
			inline constexpr int getName = 1057;
			inline constexpr int saveAttributes = 1058;
			inline constexpr int renderInit = 1059;
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
			inline constexpr int breakBlock = 887;
			inline constexpr int entityAction = 888;
			inline constexpr int saveAttributes = 889;
			inline constexpr int initGlassesMesh = 890;
			inline constexpr int renderInit = 891;
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
				inline constexpr int buffCount = 912;
				inline constexpr int buffData = 913;
				inline constexpr int indexBuffSize = 914;
				inline constexpr int vertCount = 915;
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
			inline constexpr int updateEntities = 911;
			inline constexpr int saveToMessage = 1208; // server
			inline constexpr int updateEntitiesServer = 1209; // server
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
				inline constexpr int attrCount = 930;
				inline constexpr int attrType = 931;
				inline constexpr int buffCount = 932;
				inline constexpr int buffData = 933;
				inline constexpr int indexBuffData = 934;
				inline constexpr int vertCount = 935;
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
			inline constexpr int alignX = 958;
			inline constexpr int alignY = 959;
			inline constexpr int craftRecipe = 960;
			inline constexpr int mouseInput = 961;
			inline constexpr int renderInit = 962;
		}
		namespace Entity {
			inline constexpr int loadEntityInfo = 459;
			inline constexpr int createFromJson = 460;
			inline constexpr int createWithAttributes = 461;
			inline constexpr int save = 462;
			inline constexpr int instantiateEntity = 463;
			inline constexpr int combineEntityAttributes = 464;
			inline constexpr int destr_Entity = 465;
			inline constexpr int postAction = 1003;
			inline constexpr int audioInit = 1004;
			inline constexpr int renderInit = 1005;
			inline constexpr int getServerUpdate = 1219; // server
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
			inline constexpr int addItem = 903;
			inline constexpr int begin = 904;
			inline constexpr int renderInit = 905;
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
			inline constexpr int MeshBuilderA = 499;
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
			inline constexpr int buffData = 844;
			inline constexpr int indexBuffData = 845;
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
			inline constexpr int renderInit = 1011;
			inline constexpr int applyMovementUpdate = 1221; // server
			inline constexpr int getSelectedHotbarSlot = 1222; // server
			inline constexpr int leftClickTimerReady = 1223; // server
			inline constexpr int rightClickTimerReady = 1224; // server
			inline constexpr int saveInventory = 1225; // server
			inline constexpr int startBreakingBlock = 1226; // server
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
			inline constexpr int cleanupLocal = 1067;
			inline constexpr int sendChatMessage = 1068;
			inline constexpr int setDifficultyLocal = 1069;
			inline constexpr int setRenderDistanceLocal = 1070;
			inline constexpr int setSkinVisibility = 1071;
			inline constexpr int updateLocal = 1072;
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
			inline constexpr int getType = 1080;
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
			inline constexpr int getType = 1081;
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
				inline constexpr int alignX = 906;
				inline constexpr int alignY = 907;
				inline constexpr int deselect = 908;
				inline constexpr int offsetY = 909;
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
				inline constexpr int alignX = 1014;
				inline constexpr int alignY = 1015;
				inline constexpr int deselect = 1016;
				inline constexpr int enabled = 1017;
				inline constexpr int offsetX = 1018;
				inline constexpr int offsetY = 1019;
				inline constexpr int select = 1020;
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
				inline constexpr int charInput = 859;
				inline constexpr int deselect = 860;
				inline constexpr int keyInput = 861;
				inline constexpr int mouseButtonInput = 862;
				inline constexpr int mouseInput = 863;
				inline constexpr int scrollInput = 864;
				inline constexpr int select = 865;
			}
		}
		namespace gui {
			namespace Image {
				inline constexpr int offsetX = 644;
				inline constexpr int offsetY = 645;
				inline constexpr int render = 646;
				inline constexpr int getPos = 647;
				inline constexpr int getSize = 648;
				inline constexpr int alignX = 968;
				inline constexpr int alignY = 969;
				inline constexpr int enabled = 970;
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
				inline constexpr int enabled = 963;
				inline constexpr int select = 964;
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
				inline constexpr int alignX = 1021;
				inline constexpr int alignY = 1022;
				inline constexpr int enabled = 1023;
				inline constexpr int offsetY = 1024;
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
			inline constexpr int action = 892;
			inline constexpr int deathTimer = 893;
			inline constexpr int getPos = 894;
			inline constexpr int isBlockEntity = 895;
			inline constexpr int isClickable = 896;
			inline constexpr int isIntersectingRay = 897;
			inline constexpr int saveAttributes = 898;
			inline constexpr int setPos = 899;
			inline constexpr int shouldSave = 900;
			inline constexpr int renderInit = 901;
			inline constexpr int renderLens = 902;
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
			inline constexpr int applyServerUpdate = 850;
			inline constexpr int deathTimer = 851;
			inline constexpr int getServerUpdateAttributes = 852;
			inline constexpr int isBlockEntity = 853;
			inline constexpr int isClickable = 854;
			inline constexpr int isIntersectingRay = 855;
			inline constexpr int shouldSave = 856;
			inline constexpr int generateSpherePolygons = 857;
			inline constexpr int renderModel = 858;
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
			inline constexpr int action = 1025;
			inline constexpr int deathTimer = 1026;
			inline constexpr int getServerUpdateAttributes = 1027;
			inline constexpr int isBlockEntity = 1028;
			inline constexpr int isClickable = 1029;
			inline constexpr int takeDamage = 1030;
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
			inline constexpr int action = 1040;
			inline constexpr int getServerUpdateAttributes = 1041;
			inline constexpr int isBlockEntity = 1042;
			inline constexpr int isClickable = 1043;
			inline constexpr int shouldSave = 1044;
			inline constexpr int renderInit = 1045;
			inline constexpr int setPerformingAction = 1220; // server
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
			inline constexpr int action = 871;
			inline constexpr int deathTimer = 872;
			inline constexpr int isBlockEntity = 873;
			inline constexpr int isClickable = 874;
			inline constexpr int shouldSave = 875;
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
			inline constexpr int deathTimer = 866;
			inline constexpr int isBlockEntity = 867;
			inline constexpr int isIntersectingRay = 868;
			inline constexpr int shouldSave = 869;
			inline constexpr int takeDamage = 870;
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
			inline constexpr int action = 876;
			inline constexpr int isClickable = 877;
			inline constexpr int saveAttributes = 878;
			inline constexpr int shouldSave = 879;
			inline constexpr int takeDamage = 880;
		}
		namespace EntityManager {
			inline constexpr int extract = 789;
			inline constexpr int get = 790;
			inline constexpr int getBlockEntity = 791;
			inline constexpr int relocateBlockEntities = 910;
		}
		namespace Coil {
			inline constexpr int Coil = 792;
			inline constexpr int buffSize = 793;
			inline constexpr int attrSize = 794;
			inline constexpr int attrCount = 936;
			inline constexpr int attrStride = 937;
			inline constexpr int attrType = 938;
			inline constexpr int buffCount = 939;
			inline constexpr int buffData = 940;
			inline constexpr int vertCount = 941;
		}
		namespace CompassRenderer {
			inline constexpr int renderHand = 795;
			inline constexpr int renderItemDrop = 796;
			inline constexpr int generateItemMesh = 953;
			inline constexpr int renderInit = 954;
			inline constexpr int renderText = 955;
		}
		namespace DodecaplexWireframe {
			inline constexpr int generateMesh = 797;
			inline constexpr int addFaces = 798;
			inline constexpr int addCells = 799;
			inline constexpr int attrCount = 995;
			inline constexpr int attrSize = 996;
			inline constexpr int attrStride = 997;
			inline constexpr int attrType = 998;
			inline constexpr int buffCount = 999;
			inline constexpr int buffData = 1000;
			inline constexpr int buffSize = 1001;
			inline constexpr int vertCount = 1002;
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
			inline constexpr int attrCount = 1046;
			inline constexpr int attrType = 1047;
			inline constexpr int buffCount = 1048;
			inline constexpr int buffData = 1049;
			inline constexpr int buffSize = 1050;
			inline constexpr int vertCount = 1051;
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
			inline constexpr int mouseButtonInput = 965;
			inline constexpr int offsetX = 966;
			inline constexpr int offsetY = 967;
		}
		namespace Sphere {
			inline constexpr int vertCount = 821;
			inline constexpr int buffSize = 822;
			inline constexpr int Sphere = 823;
			inline constexpr int generateCirclePolygons = 824;
			inline constexpr int attrCount = 947;
			inline constexpr int attrSize = 948;
			inline constexpr int attrStride = 949;
			inline constexpr int attrType = 950;
			inline constexpr int buffCount = 951;
			inline constexpr int buffData = 952;
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
			inline constexpr int normalizeMat5 = 1177;
		}
		namespace SoLoud {
			namespace Wav {
				inline constexpr int Wav = 834;
				inline constexpr int destr_Wav = 835;
				inline constexpr int createInstance = 836;
				inline constexpr int load = 837;
				inline constexpr int loadflac = 838;
				inline constexpr int loadmp3 = 839;
				inline constexpr int loadwav = 840;
				inline constexpr int testAndLoadFile = 841;
			}
		}
		namespace MeshBuilder {
			namespace BuffInfo {
				inline constexpr int BuffInfo = 1012;
				inline constexpr int destr_BuffInfo = 1013;
			}
		}
		namespace SoLoud {
			namespace vec3 {
				inline constexpr int normalize = 1082;
			}
		}
		namespace SoLoud {
			namespace Soloud {
				inline constexpr int play3d = 1083;
				inline constexpr int set3dListenerAt = 1084;
				inline constexpr int set3dListenerUp = 1085;
				inline constexpr int set3dListenerVelocity = 1086;
				inline constexpr int set3dSourceAttenuation = 1087;
				inline constexpr int set3dSourceParameters = 1088;
				inline constexpr int update3dAudio = 1089;
				inline constexpr int update3dVoices_internal = 1090;
				inline constexpr int findFreeVoice_internal = 1091;
				inline constexpr int getHandleFromVoice_internal = 1092;
				inline constexpr int getVoiceFromHandle_internal = 1093;
				inline constexpr int isValidVoiceHandle = 1094;
				inline constexpr int play = 1095;
				inline constexpr int stop = 1096;
				inline constexpr int stopAll = 1097;
				inline constexpr int stopAudioSource = 1098;
				inline constexpr int addVoiceToGroup = 1099;
				inline constexpr int createVoiceGroup = 1100;
				inline constexpr int trimVoiceGroup_internal = 1101;
				inline constexpr int voiceGroupHandleToArray_internal = 1102;
				inline constexpr int Soloud = 1103;
				inline constexpr int destr_Soloud = 1104;
				inline constexpr int calcActiveVoices_internal = 1105;
				inline constexpr int clip_internal = 1106;
				inline constexpr int deinit = 1107;
				inline constexpr int init = 1108;
				inline constexpr int lockAudioMutex_internal = 1109;
				inline constexpr int mapResampleBuffers_internal = 1110;
				inline constexpr int mix = 1111;
				inline constexpr int mixBus_internal = 1112;
				inline constexpr int mix_internal = 1113;
				inline constexpr int postinit_internal = 1114;
				inline constexpr int unlockAudioMutex_internal = 1115;
				inline constexpr int setDelaySamples = 1116;
				inline constexpr int setGlobalVolume = 1117;
				inline constexpr int setPause = 1118;
				inline constexpr int setProtectVoice = 1119;
				inline constexpr int setVolume = 1120;
				inline constexpr int setVoicePan_internal = 1121;
				inline constexpr int setVoicePause_internal = 1122;
				inline constexpr int setVoiceRelativePlaySpeed_internal = 1123;
				inline constexpr int setVoiceVolume_internal = 1124;
				inline constexpr int stopVoice_internal = 1125;
				inline constexpr int updateVoiceRelativePlaySpeed_internal = 1126;
				inline constexpr int updateVoiceVolume_internal = 1127;
			}
		}
		namespace SoLoud {
			namespace AlignedFloatBuffer {
				inline constexpr int AlignedFloatBuffer = 1128;
				inline constexpr int destr_AlignedFloatBuffer = 1129;
			}
		}
		namespace SoLoud {
			inline constexpr int panAndExpand = 1130;
			inline constexpr int resample = 1131;
			inline constexpr int miniaudio_init = 1132;
			inline constexpr int soloud_miniaudio_audiomixer = 1133;
			inline constexpr int soloud_miniaudio_deinit = 1134;
		}
		namespace SoLoud {
			namespace WavInstance {
				inline constexpr int getAudio = 1135;
				inline constexpr int hasEnded = 1136;
				inline constexpr int rewind = 1137;
			}
		}
		namespace SoLoud {
			namespace AudioSource {
				inline constexpr int AudioSource = 1138;
				inline constexpr int destr_AudioSource = 1139;
				inline constexpr int setFilter = 1140;
				inline constexpr int stop = 1141;
			}
		}
		namespace SoLoud {
			namespace AudioSourceInstance3dData {
				inline constexpr int AudioSourceInstance3dData = 1142;
				inline constexpr int init = 1143;
			}
		}
		namespace SoLoud {
			namespace AudioSourceInstance {
				inline constexpr int AudioSourceInstance = 1144;
				inline constexpr int destr_AudioSourceInstance = 1145;
				inline constexpr int getInfo = 1146;
				inline constexpr int init = 1147;
				inline constexpr int rewind = 1148;
				inline constexpr int seek = 1149;
			}
		}
		namespace SoLoud {
			namespace Fader {
				inline constexpr int Fader = 1150;
				inline constexpr int get = 1151;
			}
		}
		namespace SoLoud {
			namespace Thread {
				inline constexpr int createMutex = 1152;
				inline constexpr int destroyMutex = 1153;
				inline constexpr int lockMutex = 1154;
				inline constexpr int unlockMutex = 1155;
			}
		}
		namespace SoLoud {
			namespace DiskFile {
				inline constexpr int DiskFile = 1156;
				inline constexpr int destr_DiskFile = 1157;
				inline constexpr int eof = 1158;
				inline constexpr int getFilePtr = 1159;
				inline constexpr int length = 1160;
				inline constexpr int open = 1161;
				inline constexpr int pos = 1162;
				inline constexpr int read = 1163;
				inline constexpr int seek = 1164;
			}
		}
		namespace SoLoud {
			namespace MemoryFile {
				inline constexpr int MemoryFile = 1165;
				inline constexpr int destr_MemoryFile = 1166;
				inline constexpr int eof = 1167;
				inline constexpr int getMemPtr = 1168;
				inline constexpr int length = 1169;
				inline constexpr int openFileToMem = 1170;
				inline constexpr int pos = 1171;
				inline constexpr int read = 1172;
				inline constexpr int seek = 1173;
			}
		}
		namespace SoLoud {
			namespace File {
				inline constexpr int getFilePtr = 1174;
				inline constexpr int getMemPtr = 1175;
				inline constexpr int read32 = 1176;
			}
		}
		namespace Core {
			namespace StateModMenu {
				inline constexpr int updateProjection = 1178;
				inline constexpr int viewportCallbackFunc = 1179;
				inline constexpr int closeBtnCallback = 1180;
				inline constexpr int modSelectionCallback = 1181;
				inline constexpr int init = 1182;
				inline constexpr int enableCheckboxCallback = 1183;
				inline constexpr int update = 1184;
				inline constexpr int render = 1185;
				inline constexpr int resume = 1186;
				inline constexpr int updateFunnyBoxes = 1187;
				inline constexpr int windowResize = 1188;
				inline constexpr int mouseInput = 1189;
				inline constexpr int scrollInput = 1190;
				inline constexpr int keyInput = 1191;
				inline constexpr int mouseButtonInput = 1192;
				inline constexpr int close = 1193;
			}
			namespace StateTitleScreenA {
				inline constexpr int modsBtnCallback = 1194;
			}
			namespace StateSettingsA {
				inline constexpr int autoUpdateCheckBoxCallback = 1195;
			}
			namespace BetterText {
				inline constexpr int render = 1196;
				inline constexpr int getSize = 1197;
				inline constexpr int updateTTF = 1205;
			}
			namespace Counter {
				inline constexpr int Counter = 1198;
				inline constexpr int setCount = 1199;
				inline constexpr int getCount = 1200;
				inline constexpr int render = 1201;
				inline constexpr int getPos = 1206;
				inline constexpr int getSize = 1207;
			}
			namespace ModElement {
				inline constexpr int ModElement = 1202;
				inline constexpr int render = 1203;
				inline constexpr int mouseButtonInput = 1204;
			}
		}
		namespace Connection {
			namespace Server {
				inline constexpr int destr_Server = 1212; // server
				inline constexpr int cleanup = 1213; // server
				inline constexpr int handleConnectionStatusChange = 1214; // server
				inline constexpr int kickClient = 1215; // server
				inline constexpr int sendMessage = 1216; // server
				inline constexpr int connectionStatusChangedCallback = 1217; // server
			}
		}
		namespace WorldServer {
			inline constexpr int WorldServer = 1228; // server
			inline constexpr int destr_WorldServer = 1229; // server
			inline constexpr int addEntityToChunk = 1230; // server
			inline constexpr int getType = 1231; // server
			inline constexpr int giveItem = 1232; // server
			inline constexpr int handleLightingOptionsUpdate = 1233; // server
			inline constexpr int handleMessage = 1234; // server
			inline constexpr int handlePlayerDeath = 1235; // server
			inline constexpr int handlePlayerLogin = 1236; // server
			inline constexpr int loadChunk = 1237; // server
			inline constexpr int loadChunks = 1238; // server
			inline constexpr int localPlayerEvent = 1239; // server
			inline constexpr int localPlayerInit = 1240; // server
			inline constexpr int localPlayerRespawn = 1241; // server
			inline constexpr int removePlayer = 1242; // server
			inline constexpr int removePlayerChunks = 1243; // server
			inline constexpr int savePlayerData = 1244; // server
			inline constexpr int saveWorldData = 1245; // server
			inline constexpr int sendEquippedItemUpdate = 1246; // server
			inline constexpr int sendEquippedItemUpdateA = 1262; // server
			inline constexpr int sendMessage = 1247; // server
			inline constexpr int sendMessageOtherPlayers = 1248; // server
			inline constexpr int sendMessagePlayer = 1249; // server
			inline constexpr int setBlockUpdate = 1250; // server
			inline constexpr int setDifficultyLocal = 1251; // server
			inline constexpr int setRenderDistanceLocal = 1252; // server
			inline constexpr int unloadChunk = 1253; // server
			inline constexpr int updateBackend = 1254; // server
			inline constexpr int updateChunk = 1255; // server
			inline constexpr int updateChunks = 1256; // server
			inline constexpr int updateLocal = 1257; // server
			inline constexpr int updateNewlyLoadedChunks = 1258; // server
			inline constexpr int disconnectCallback = 1259; // server
		}
		namespace WorldServer {
			namespace PlayerInfo {
				inline constexpr int PlayerInfo = 1260; // server
				inline constexpr int destr_PlayerInfo = 1261; // server
			}
		}
	}

	inline std::unordered_map<int, uint64_t> funcAddresses{};
	inline uint64_t getFuncAddr(int func)
	{
		if (funcAddresses.contains(func))
			return funcAddresses[func];
		return funcAddresses[func] = reinterpret_cast<uint64_t(__stdcall*)(int)>(GetProcAddress(GetModuleHandleA("4DModLoader-Core.dll"), "getFuncAddr"))(func);
	}

	namespace Data {
		namespace AudioManager {
			inline constexpr int soloud = 0;
			inline constexpr int voiceGroups = 1;
			inline constexpr int sounds = 2;
			inline constexpr int BGMList = 3;
			inline constexpr int BGMVolume = 4;
			inline constexpr int BGMNextIndex = 5;
			inline constexpr int currentBGM = 6;
			inline constexpr int hyperplaneView = 7;
		}
		namespace BlockInfo {
			inline constexpr int tuv_grass_top = 8;
			inline constexpr int tuv_grass_side = 9;
			inline constexpr int tuv_grass_full = 10;
			inline constexpr int uv_grass_top = 11;
			inline constexpr int uv_grass_side = 12;
			inline constexpr int tuv_dirt = 13;
			inline constexpr int tuv_dirt_full = 14;
			inline constexpr int uv_dirt = 15;
			inline constexpr int tuv_stone = 16;
			inline constexpr int tuv_stone_full = 17;
			inline constexpr int uv_stone = 18;
			inline constexpr int tuv_lava = 19;
			inline constexpr int tuv_lava_full = 20;
			inline constexpr int uv_lava = 21;
			inline constexpr int tuv_wood_top = 22;
			inline constexpr int tuv_wood_side = 23;
			inline constexpr int tuv_wood_full = 24;
			inline constexpr int tuv_leaf = 25;
			inline constexpr int tuv_leaf_full = 26;
			inline constexpr int tuv_iron_ore = 27;
			inline constexpr int tuv_iron_ore_full = 28;
			inline constexpr int tuv_deadly_ore = 29;
			inline constexpr int tuv_deadly_ore_full = 30;
			inline constexpr int tuv_chest_top = 31;
			inline constexpr int tuv_chest_side = 32;
			inline constexpr int tuv_chest_bottom = 33;
			inline constexpr int tuv_chest_full = 34;
			inline constexpr int tuv_midnight_grass_top = 35;
			inline constexpr int tuv_midnight_grass_side = 36;
			inline constexpr int tuv_midnight_grass_full = 37;
			inline constexpr int tuv_midnight_soil = 38;
			inline constexpr int tuv_midnight_soil_full = 39;
			inline constexpr int tuv_midnight_stone = 40;
			inline constexpr int tuv_midnight_stone_full = 41;
			inline constexpr int tuv_midnight_wood_top = 42;
			inline constexpr int tuv_midnight_wood_side = 43;
			inline constexpr int tuv_midnight_wood_full = 44;
			inline constexpr int tuv_midnight_leaf = 45;
			inline constexpr int tuv_midnight_leaf_full = 46;
			inline constexpr int tuv_bush = 47;
			inline constexpr int tuv_bush_full = 48;
			inline constexpr int tuv_midnight_bush = 49;
			inline constexpr int tuv_midnight_bush_full = 50;
			inline constexpr int tuv_red_flower = 51;
			inline constexpr int tuv_red_flower_full = 52;
			inline constexpr int tuv_white_flower = 53;
			inline constexpr int tuv_white_flower_full = 54;
			inline constexpr int tuv_blue_flower = 55;
			inline constexpr int tuv_blue_flower_full = 56;
			inline constexpr int tuv_tall_grass = 57;
			inline constexpr int tuv_tall_grass_full = 58;
			inline constexpr int tuv_sand = 59;
			inline constexpr int tuv_sand_full = 60;
			inline constexpr int tuv_sandstone = 61;
			inline constexpr int tuv_sandstone_full = 62;
			inline constexpr int tuv_cactus = 63;
			inline constexpr int tuv_cactus_full = 64;
			inline constexpr int tuv_snow = 65;
			inline constexpr int tuv_snow_full = 66;
			inline constexpr int tuv_ice = 67;
			inline constexpr int tuv_ice_full = 68;
			inline constexpr int tuv_snowy_bush = 69;
			inline constexpr int tuv_snowy_bush_full = 70;
			inline constexpr int tuv_glass = 71;
			inline constexpr int tuv_glass_full = 72;
			inline constexpr int tuv_solenoid_ore = 73;
			inline constexpr int tuv_solenoid_ore_full = 74;
			inline constexpr int tuv_snowy_leaf_top = 75;
			inline constexpr int tuv_snowy_leaf_side = 76;
			inline constexpr int tuv_snowy_leaf_bottom = 77;
			inline constexpr int tuv_snowy_leaf_full = 78;
			inline constexpr int tuv_pumpkin_top = 79;
			inline constexpr int tuv_pumpkin_side = 80;
			inline constexpr int tuv_pumpkin_full = 81;
			inline constexpr int tuv_jack_o_lantern_side = 82;
			inline constexpr int tuv_jack_o_lantern_full = 83;
			inline constexpr int cube_verts_x = 84;
			inline constexpr int cube_verts_y = 85;
			inline constexpr int cube_verts_z = 86;
			inline constexpr int cube_verts_w = 87;
			inline constexpr int hypercube_full_verts = 88;
			inline constexpr int hypercube_full_tuvs = 89;
			inline constexpr int hypercube_full_normals = 90;
			inline constexpr int hypercube_full_indices = 91;
			inline constexpr int plant_full_verts = 92;
			inline constexpr int plant_full_normals = 93;
			inline constexpr int plant_full_indices = 94;
			inline constexpr int square_verts_x = 95;
			inline constexpr int square_verts_y = 96;
			inline constexpr int square_verts_z = 97;
			inline constexpr int cube_verts = 98;
			inline constexpr int cube_indices = 99;
			inline constexpr int cube_verts_triangles = 100;
			inline constexpr int cube_verts_lines = 101;
			inline constexpr int blockIDs = 102;
			inline constexpr int blockNames = 103;
			inline constexpr int itemMeshes = 104;
			inline constexpr int Blocks = 237;
		}
		namespace Item {
			inline constexpr int fr = 105;
			inline constexpr int qr = 106;
			inline constexpr int blueprints = 107;
		}
		namespace EntityAlidade {
			inline constexpr int telescopeRenderer = 108;
			inline constexpr int baseRenderer = 109;
			inline constexpr int supportRenderer = 110;
			inline constexpr int semicircleRenderer = 111;
			inline constexpr int wireframeRenderer = 112;
		}
		namespace EntityChest {
			inline constexpr int wireframeRenderer = 113;
		}
		namespace EntitySpider {
			inline constexpr int spiderTypes = 114;
			inline constexpr int legPositions = 115;
			inline constexpr int legRenderer = 116;
			inline constexpr int wireframeRenderer = 117;
		}
		namespace ItemBlock {
			inline constexpr int tr = 118;
		}
		namespace ItemMaterial {
			inline constexpr int tr = 119;
			inline constexpr int barTUV = 120;
			inline constexpr int hypersilkRenderer = 121;
			inline constexpr int rockRenderer = 122;
			inline constexpr int barRenderer = 123;
			inline constexpr int kleinBottleRenderer = 124;
			inline constexpr int healthPotionRenderer = 125;
			inline constexpr int glassesFrameRenderer = 126;
			inline constexpr int glassesLensRenderer = 127;
		}
		namespace EntityButterfly {
			inline constexpr int wing_tuv = 128;
			inline constexpr int ButterflyTypes = 129;
			inline constexpr int wingRenderer = 130;
			inline constexpr int wireframeRenderer = 131;
		}
		namespace InventoryGrid {
			inline constexpr int tr = 132;
			inline constexpr int fr = 133;
		}
		namespace CloudChunk {
			namespace CloudChunkMesh {
				inline constexpr int truncated_octahedron_verts = 134;
				inline constexpr int truncated_octahedron_indices = 135;
			}
		}
		namespace CompassRenderer {
			inline constexpr int hypercubeTetMesh = 136;
			inline constexpr int hypercubeTetRenderer = 137;
			inline constexpr int hypercubeHollowRenderer = 138;
			inline constexpr int cubeTetMesh = 139;
			inline constexpr int cubeTetRenderer = 140;
			inline constexpr int cubeTriangleMesh = 141;
			inline constexpr int cubeTriangleRenderer = 142;
			inline constexpr int cubeWireframeMesh = 143;
			inline constexpr int cubeWireframeRenderer = 144;
			inline constexpr int line = 145;
			inline constexpr int lineMesh = 146;
			inline constexpr int lineRenderer = 147;
			inline constexpr int fr = 148;
			inline constexpr int pd = 149;
			inline constexpr int left = 150;
			inline constexpr int over = 151;
			inline constexpr int pos = 152;
			inline constexpr int rotation3D = 153;
			inline constexpr int wWidth = 154;
			inline constexpr int wHeight = 155;
		}
		namespace Connection {
			namespace Client {
				inline constexpr int instances = 156;
			}
		}
		namespace CraftingMenu {
			inline constexpr int recipes = 157;
			inline constexpr int tr = 158;
		}
		namespace PlayerSkin {
			inline constexpr int meshBounds = 159;
		}
		namespace PlayerSkinRenderer {
			inline constexpr int wireframeRenderer = 160;
		}
		namespace StateCreateWorld {
			inline constexpr int instanceObj = 161;
		}
		namespace StateSingleplayer {
			inline constexpr int instanceObj = 162;
		}
		namespace StateTitleScreen {
			inline constexpr int instanceObj = 163;
		}
		namespace StateCredits {
			inline constexpr int instanceObj = 164;
		}
		namespace StateDeathScreen {
			inline constexpr int instanceObj = 165;
		}
		namespace StateErrorScreen {
			inline constexpr int instanceObj = 166;
		}
		namespace Entity {
			inline constexpr int uuidGenerator = 167;
			inline constexpr int uuidParser = 168;
			inline constexpr int blueprints = 169;
		}
		namespace StateSettings {
			inline constexpr int instanceObj = 170;
		}
		namespace StateSkinChooser {
			inline constexpr int defaultSkinPath = 171;
			inline constexpr int instanceObj = 172;
		}
		namespace Player {
			inline constexpr int defaultSpawnPos = 173;
			inline constexpr int targetBlockRenderer = 174;
			inline constexpr int healthRenderer = 175;
			inline constexpr int fr = 176;
		}
		namespace InventoryManager {
			inline constexpr int font = 177;
		}
		namespace StateGame {
			inline constexpr int instanceObj = 178;
		}
		namespace StateIntro {
			inline constexpr int instanceObj = 179;
			inline constexpr int fileNames = 180;
		}
		namespace EntityItem {
			inline constexpr int wireframeRenderer = 181;
		}
		namespace StateMultiplayer {
			inline constexpr int instanceObj = 182;
		}
		namespace StatePause {
			inline constexpr int instanceObj = 183;
		}
		namespace EntityPlayer {
			inline constexpr int defualtSkin = 184;
			inline constexpr int projection3D = 185;
			inline constexpr int wWidth = 186;
			inline constexpr int wHeight = 187;
			inline constexpr int fr = 188;
		}
		namespace ResourceManager {
			inline constexpr int textures = 189;
		}
		namespace ShaderManager {
			inline constexpr int shaders = 190;
		}
		namespace Skybox {
			inline constexpr int instance = 191;
			inline constexpr int verts = 192;
			inline constexpr int uv = 193;
		}
		namespace ItemTool {
			inline constexpr int pickaxeVerts = 194;
			inline constexpr int pickaxeNormals = 195;
			inline constexpr int ironPickTUV = 196;
			inline constexpr int deadlyPickTUV = 197;
			inline constexpr int ultrahammerTUV = 198;
			inline constexpr int solenoidCollectorTUV = 199;
			inline constexpr int ironPickaxeRenderer = 200;
			inline constexpr int deadlyPickaxeRenderer = 201;
			inline constexpr int rockRenderer = 202;
			inline constexpr int ultrahammerRenderer = 203;
			inline constexpr int solenoidCollectorRenderer = 204;
			inline constexpr int coilMesh = 205;
			inline constexpr int coilRenderer = 206;
			inline constexpr int collectorBall = 207;
			inline constexpr int collectorBallRenderer = 208;
			inline constexpr int collectorAnimation = 209;
			inline constexpr int tr = 210;
		}
		namespace StateTutorialSlideshow {
			inline constexpr int instanceObj = 211;
		}
		namespace StateTutorial {
			inline constexpr int instanceObj = 212;
		}
		namespace StateWorldGen {
			inline constexpr int instanceObj = 213;
		}
		namespace SoLoud {
			inline constexpr int gDevice = 214;
		}
		namespace Console
		{
			inline constexpr int inputMutex = 238;
			inline constexpr int inStrings = 239;
		}
		namespace GlobalShapes {
			inline constexpr int pentachoron = 215;
			inline constexpr int pentachoronHollow = 216;
			inline constexpr int five_cell_normals = 217;
			inline constexpr int pentachoronOriginBase = 218;
			inline constexpr int spiderLeg = 219;
			inline constexpr int five_cell_tet_origin_base = 220;
			inline constexpr int hypercube = 221;
			inline constexpr int hypercubeHollow = 222;
			inline constexpr int hypercube_cubes = 223;
			inline constexpr int hypercube_cubes_normals = 224;
			inline constexpr int hypercube_cubes_colors_deadly = 225;
			inline constexpr int hypercube_tet = 226;
			inline constexpr int hypercube_tet_colors = 227;
			inline constexpr int hypercube_wireframe = 228;
			inline constexpr int dodecaplexHollow = 229;
			inline constexpr int dodecaplex = 230;
			inline constexpr int rock = 231;
			inline constexpr int dodecaplexWireframe = 232;
			inline constexpr int sphere = 233;
			inline constexpr int hypersphere = 234;
			inline constexpr int hypersphereHollow = 235;
			inline constexpr int kleinBottle = 236;
			inline constexpr int five_cell_colors = 240;
			inline constexpr int five_cell_tet = 241;
		}
		namespace Core {
			namespace StateModMenu {
				inline constexpr int instanceObj = 242;
				inline constexpr int newSelectedMods = 243;
			}
			namespace StateTitleScreenA {
				inline constexpr int modloaderText = 244;
				inline constexpr int modsBtn = 245;
				inline constexpr int counterCriticals = 246;
				inline constexpr int counterWarnings = 247;
			}
			namespace StateSettingsA {
				inline constexpr int modloaderOptionsText = 248;
				inline constexpr int autoUpdateCheckBox = 249;
			}
			namespace Counter {
				inline constexpr int numbers = 250;
			}
		}
		namespace Connection {
			namespace Server {
				inline constexpr int instances = 251; // server
			}
		}
	}

	inline std::unordered_map<int, uint64_t> dataAddresses{};
	inline uint64_t getDataAddr(int data)
	{
		if (dataAddresses.contains(data))
			return dataAddresses[data];
		return dataAddresses[data] = reinterpret_cast<uint64_t(__stdcall*)(int)>(GetProcAddress(GetModuleHandleA("4DModLoader-Core.dll"), "getDataAddr"))(data);
	}

	inline void startConsole()
	{
		return reinterpret_cast<void(__stdcall*)()>(GetProcAddress(GetModuleHandleA("4DModLoader-Core.dll"), "startConsole"))();
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
	inline std::vector<fdm::stl::string> getLaunchArguments()
	{
		return reinterpret_cast<std::vector<fdm::stl::string>(__stdcall*)()>(GetProcAddress(GetModuleHandleA("4DModLoader-Core.dll"), "getLaunchArguments"))();
	}
	// useful for creating library mod headers
	inline FARPROC getModFuncPointer(const fdm::stl::string& modId, const fdm::stl::string& funcName)
	{
		HMODULE modModule = getModHandle(modId);
		if (modModule == nullptr) return nullptr;
		return GetProcAddress(modModule, funcName.c_str());
	}

	/* 
	Compares two version strings using an operator string
	operators are "==" | ">=" | "<=" | "<" | ">" | "!="
	it is used by the modloader to check dependency versions
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
	inline bool isServer()
	{
		return reinterpret_cast<bool(__stdcall*)()>(GetProcAddress(GetModuleHandleA("4DModLoader-Core.dll"), "isServer"))();
	}

	namespace m4 { class Mat5; }
	namespace main_cpp
	{
		inline int main()
		{
			return reinterpret_cast<int(__fastcall*)()>(getFuncAddr((int)Func::main_cpp::main))();
		}
		inline void handleRawMouseInput(GLFWwindow* window, double xpos, double ypos)
		{
			return reinterpret_cast<void(__fastcall*)(GLFWwindow*, double, double)>(getFuncAddr((int)Func::main_cpp::handleRawMouseInput))(window, xpos, ypos);
		}
		inline void scrollCallback(GLFWwindow* window, double xoff, double yoff)
		{
			return reinterpret_cast<void(__fastcall*)(GLFWwindow*, double, double)>(getFuncAddr((int)Func::main_cpp::scrollCallback))(window, xoff, yoff);
		}
		inline void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
		{
			return reinterpret_cast<void(__fastcall*)(GLFWwindow*, int, int, int)>(getFuncAddr((int)Func::main_cpp::mouseButtonCallback))(window, button, action, mods);
		}
		inline void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			return reinterpret_cast<void(__fastcall*)(GLFWwindow*, int, int, int, int)>(getFuncAddr((int)Func::main_cpp::keyCallback))(window, key, scancode, action, mods);
		}
		inline void framebufferSizeCallback(GLFWwindow* window, int width, int height)
		{
			return reinterpret_cast<void(__fastcall*)(GLFWwindow*, int, int)>(getFuncAddr((int)Func::main_cpp::framebufferSizeCallback))(window, width, height);
		}
		inline void charCallback(GLFWwindow* window, uint32_t codepoint)
		{
			return reinterpret_cast<void(__fastcall*)(GLFWwindow*, uint32_t)>(getFuncAddr((int)Func::main_cpp::charCallback))(window, codepoint);
		}
		inline void fileDropCallback(GLFWwindow* window, int count, const char** paths)
		{
			return reinterpret_cast<void(__fastcall*)(GLFWwindow*, int, const char**)>(getFuncAddr((int)Func::main_cpp::fileDropCallback))(window, count, paths);
		}
		inline void normalizeMat5(m4::Mat5& m)
		{
			return reinterpret_cast<void(__fastcall*)(m4::Mat5&)>(getFuncAddr((int)Func::main_cpp::normalizeMat5))(m);
		}
	}


	template<auto F>
	inline static constexpr uint64_t getClassFuncAddr()
	{
		auto pFunc = F;
		void* pPtr = (void*&)pFunc;
		return reinterpret_cast<uint64_t>(pPtr);
	}

	inline std::vector<void(*)()> execFuncs;
}

#include "Console.h"

// used by the modloader
extern "C" inline __declspec(dllexport) void setModID(const fdm::stl::string& modID)
{
	fdm::modID = modID;

	for (auto& func : fdm::execFuncs)
		func();
}

// Connection namespace
#include "Connection/MessageData.h"
#include "Connection/InMessage.h"
#include "Connection/OutMessage.h"
#include "Connection/Server.h"
#include "Connection/Client.h"
#include "Packet.h" // thats not in the Connection namespace for some reason even tho it relates to networking but k

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

// so loud!11!!11!!!!!1
#include "SoLoud/SoLoud.h"
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

// 4dmodloader-core stuff
#include "Core/TTFRenderer.h"
#include "Core/Mod.h"
#include "Core/BetterText.h"
#include "Core/Counter.h"
#include "Core/ModElement.h"
#include "Core/StateModMenu.h"
#include "Core/StateSettingsA.h"
#include "Core/StateTitleScreenA.h"

// allows to execute any code at any location (at dll load)
#define $execAtLoad                                                                                  \
	template <class>                                                                              \
	void CONCAT(fdmEFunc, __LINE__)();                                             \
	namespace \
	{                                                                                   \
		struct CONCAT(fdmEFuncU, __LINE__) {};                                         \
	}                                                                                             \
	inline static auto CONCAT(fdmEFuncC, __LINE__) =                                             \
		(CONCAT(fdmEFunc, __LINE__) < CONCAT(fdmEFuncU, __LINE__) > (), \
		 0);                                                                                      \
	template <class>                                                                              \
	void CONCAT(fdmEFunc, __LINE__)()

// allows to execute any code at any location (at modID init)
#define $exec                                                                                 \
	template <class>                                                                              \
	void CONCAT(fdmEFunc, __LINE__)();                                             \
	namespace \
	{                                                                                   \
		struct CONCAT(fdmEFuncU, __LINE__) {};                                         \
	}                                                                                             \
	inline static auto CONCAT(fdmEFuncC, __LINE__) = []() {                                        \
		fdm::execFuncs.emplace_back(&CONCAT(fdmEFunc, __LINE__) < CONCAT(fdmEFuncU, __LINE__) >); \
		return true; \
	}();                                                                                      \
	template <class>                                                                              \
	void CONCAT(fdmEFunc, __LINE__)()

/*
creates a hook for a member function (__thiscall)
to call the original function, do `original(self, <all of the you have arguments>)`
`this` pointer is called `self`
*/
#define $hookID(id, returnType, cl, function, ...) \
	namespace id \
	{ \
		class CONCAT(function, H) \
		{ \
		public: \
			inline static returnType(__thiscall* original)(cl* self, ##__VA_ARGS__) = nullptr; \
			static returnType __fastcall hook(cl* self, ##__VA_ARGS__); \
		}; \
	} \
	$execAtLoad \
	{ \
		uint64_t hookAddr = getFuncAddr((int)(Func::cl::function)); \
		if(hookAddr) \
		{ \
			Hook(hookAddr, &id::CONCAT(function, H)::hook, &id::CONCAT(function, H)::original); \
			EnableHook(); \
		} \
	} \
	inline returnType __fastcall id::CONCAT(function, H)::hook(cl* self, ##__VA_ARGS__)

/*
creates a hook for a member function (__thiscall)
to call the original function, do `original(self, <all of the you have arguments>)`
`this` pointer is called `self`
*/
#define $hook(returnType, cl, function, ...) $hookID(CONCAT(fdmHooks, __LINE__), returnType, cl, function, __VA_ARGS__)

/*
creates a hook for a member function (__thiscall) using Func namespace.
to call the original function, do `original(self, <all of the you have arguments>)`
`this` pointer is called `self`
*/
#define $hookByFuncID(id, returnType, className, func, ...) \
	namespace id \
	{ \
		class H \
		{ \
		public: \
			inline static returnType(__thiscall* original)(className* self, ##__VA_ARGS__) = nullptr; \
			static returnType __fastcall hook(className* self, ##__VA_ARGS__); \
		}; \
	} \
	$execAtLoad \
	{ \
		uint64_t hookAddr = getFuncAddr((int)(func)); \
		if(hookAddr) \
		{ \
			Hook(hookAddr, &id::H::hook, &id::H::original); \
			EnableHook(); \
		} \
	} \
	inline returnType __fastcall id::H::hook(className* self, ##__VA_ARGS__)

/*
creates a hook for a member function (__thiscall) using Func namespace.
to call the original function, do `original(self, <all of the you have arguments>)`
`this` pointer is called `self`
*/
#define $hookByFunc(returnType, className, func, ...) $hookByFuncID(CONCAT(fdmHooks, __LINE__), returnType, className, func, __VA_ARGS__)

/*
creates a hook for a static function (__fastcall)
to call the original function, do `original(<all of the you have arguments>)`
*/
#define $hookStaticID(id, returnType, cl, function, ...) \
	namespace id \
	{ \
		class CONCAT(function, H)  \
		{ \
		public: \
			inline static returnType(__fastcall* original)(__VA_ARGS__) = nullptr;\
			static returnType __fastcall hook(__VA_ARGS__); \
		}; \
	} \
	$execAtLoad \
	{ \
		uint64_t hookAddr = getFuncAddr((int)(Func::cl::function)); \
		if(hookAddr) \
		{ \
			Hook(hookAddr, &id::CONCAT(function, H)::hook, &id::CONCAT(function, H)::original); \
			EnableHook(); \
		} \
	} \
	inline returnType __fastcall id::CONCAT(function, H)::hook(__VA_ARGS__)

/*
creates a hook for a static function (__fastcall)
to call the original function, do `original(<all of the you have arguments>)`
*/
#define $hookStatic(returnType, cl, function, ...) $hookStaticID(CONCAT(fdmHooks, __LINE__), returnType, cl, function, __VA_ARGS__)

/*
creates a hook for a static function (__fastcall) using Func namespace.
to call the original function, do `original(<all of the you have arguments>)`
*/
#define $hookStaticByFuncID(id, returnType, func, ...) \
	namespace id \
	{ \
		class H \
		{ \
		public: \
			inline static returnType(__fastcall* original)(__VA_ARGS__) = nullptr; \
			static returnType __fastcall hook(__VA_ARGS__); \
		}; \
	} \
	$execAtLoad \
	{ \
		uint64_t hookAddr = getFuncAddr((int)(func)); \
		if(hookAddr) \
		{ \
			Hook(hookAddr, &id::H::hook, &id::H::original); \
			EnableHook(); \
		} \
	} \
	inline returnType __fastcall id::H::hook(__VA_ARGS__)

/*
creates a hook for a static function (__fastcall) using Func namespace.
to call the original function, do `original(<all of the you have arguments>)`
*/
#define $hookStaticByFunc(returnType, func, ...) $hookStaticByFuncID(CONCAT(fdmHooks, __LINE__), returnType, func, __VA_ARGS__)

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
