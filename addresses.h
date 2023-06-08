#pragma once

#include "4dm.h"

// BlockItem

#define FUNC_BLOCKITEM_ADDITEMTYPE ( base + idaOffsetFix(0x15F30) )
#define FUNC_BLOCKITEM_BLOCKITEM ( base + idaOffsetFix(0x16150) )
#define FUNC_BLOCKITEM_GETNAME ( base + idaOffsetFix(0x16370) )
#define FUNC_BLOCKITEM_RENDER ( base + idaOffsetFix(0x16430) )
#define FUNC_BLOCKITEM_RENDERENTITY ( base + idaOffsetFix(0x164F0) )
#define FUNC_BLOCKITEM_ISDEADLY ( base + idaOffsetFix(0x168A0) )
#define FUNC_BLOCKITEM_ISCOMPATIBLE ( base + idaOffsetFix(0x168B0) )
#define FUNC_BLOCKITEM_ACTION ( base + idaOffsetFix(0x16940) )
#define FUNC_BLOCKITEM_CLONE ( base + idaOffsetFix(0x16AB0) )


// Chunk

#define FUNK_CHUNK_CHUNK ( base + idaOffsetFix(0x1C9E0) )
#define FUNK_CHUNK_SETBLOCK ( base + idaOffsetFix(0x1CD00) )
#define FUNK_CHUNK_GENERATEMESH ( base + idaOffsetFix(0x1CDE0) )
#define FUNK_CHUNK_UPDATEENTITIES ( base + idaOffsetFix(0x1CF40) )
#define FUNK_CHUNK_ADDENTITY ( base + idaOffsetFix(0x1D340) )
#define FUNK_CHUNK_GETBLOCKENTITY ( base + idaOffsetFix(0x1D510) )
#define FUNK_CHUNK_RENDER ( base + idaOffsetFix(0x1D650) )
#define FUNK_CHUNK_UPDATELIGHTINGHEIGHTMAP ( base + idaOffsetFix(0x1E020) )
#define FUNK_CHUNK_UPDATEMESH ( base + idaOffsetFix(0x1E100) )
#define FUNK_CHUNK_LOAD ( base + idaOffsetFix(0x1E2E0) )
#define FUNK_CHUNK_SAVE ( base + idaOffsetFix(0x1EE50) )
#define FUNK_CHUNK_UPDATECACHESECTION ( base + idaOffsetFix(0x1F660) )
#define FUNK_CHUNK_GENERATEMESHSECTION ( base + idaOffsetFix(0x26F40) )
#define FUNK_CHUNK_GETSMOOTHLIGHTING ( base + idaOffsetFix(0x28880) )
#define FUNK_CHUNK_GETLIGHTING ( base + idaOffsetFix(0x29DC0) )
#define FUNK_CHUNK_GETCHUNKPATH ( base + idaOffsetFix(0x2A1F0) )


// Chunk::ChunkMesh

#define FUNC_CHUNK_CHUNKMESH_DCHUNKMESH ( base + idaOffsetFix(0x1CC20) )
#define FUNC_CHUNK_CHUNKMESH_CHUNKMESH ( base + idaOffsetFix(0x2A3C0) )
#define FUNC_CHUNK_CHUNKMESH_BUFFSIZE ( base + idaOffsetFix(0x2A410) )
#define FUNC_CHUNK_CHUNKMESH_ATTRCOUNT ( base + idaOffsetFix(0x2A440) )
#define FUNC_CHUNK_CHUNKMESH_ATTRTYPE ( base + idaOffsetFix(0x2A450) )
#define FUNC_CHUNK_CHUNKMESH_ATTRSIZE ( base + idaOffsetFix(0x2A460) )
#define FUNC_CHUNK_CHUNKMESH_ATTRSTRIDE ( base + idaOffsetFix(0x2A480) )
#define FUNC_CHUNK_CHUNKMESH_INDEXBUFFDATA ( base + idaOffsetFix(0x2A4A0) )
#define FUNC_CHUNK_CHUNKMESH_OPERATOR_EQ ( base + idaOffsetFix(0x2A4C0) )
#define FUNC_CHUNK_CHUNKMESH_ADDMESHSIDE ( base + idaOffsetFix(0x2A5A0) )
#define FUNC_CHUNK_CHUNKMESH_ADDMESHPLANT ( base + idaOffsetFix(0x2A780) )


// CloudChunk

#define FUNC_CLOUDCHUNK_GENERATEMESH ( base + idaOffsetFix(0x2DFB0) )


// CloudChunk::CloudChunkMesh

#define FUNC_CLOUDCHUNK_CLOUDCHUNKMESH_VERTCOUNT ( base + idaOffsetFix(0x2A490) )
#define FUNC_CLOUDCHUNK_CLOUDCHUNKMESH_INDEXBUFFSIZE ( base + idaOffsetFix(0x2A4B0) )
#define FUNC_CLOUDCHUNK_CLOUDCHUNKMESH_BUFFSIZE ( base + idaOffsetFix(0x2DF90) )
#define FUNC_CLOUDCHUNK_CLOUDCHUNKMESH_ATTRSTRIDE ( base + idaOffsetFix(0x2DFA0) )


// CloudManager

#define FUNC_CLOUDMANAGER_RENDER ( base + idaOffsetFix(0x2E4E0) )
#define FUNC_CLOUDMANAGER_UPDATELOADEDCHUNKS ( base + idaOffsetFix(0x2E940) )
#define FUNC_CLOUDMANAGER_LOADCHUNKS ( base + idaOffsetFix(0x2F870) )
#define FUNC_CLOUDMANAGER_UPDATECHUNK ( base + idaOffsetFix(0x2FBE0) )
#define FUNC_CLOUDMANAGER_DCLOUDMANAGER ( base + idaOffsetFix(0x4E310) )


// CraftingMenu

#define FUNC_CRAFTINGMENU_LOADRECIPES ( base + idaOffsetFix(0x39870) )
#define FUNC_CRAFTINGMENU_RENDERINIT ( base + idaOffsetFix(0x39B80) )
#define FUNC_CRAFTINGMENU_RENDER ( base + idaOffsetFix(0x39D00) )
#define FUNC_CRAFTINGMENU_OFFSETX ( base + idaOffsetFix(0x3A1A0) )
#define FUNC_CRAFTINGMENU_OFFSETY ( base + idaOffsetFix(0x3A1B0) )
#define FUNC_CRAFTINGMENU_GETPOS ( base + idaOffsetFix(0x3A1C0) )
#define FUNC_CRAFTINGMENU_GETSIZE ( base + idaOffsetFix(0x3A2A0) )
#define FUNC_CRAFTINGMENU_MOUSEBUTTONINPUT ( base + idaOffsetFix(0x3A340) )
#define FUNC_CRAFTINGMENU_UPDATEAVAILABLERECIPES ( base + idaOffsetFix(0x3AE40) )


// CraftingMenu::CraftableRecipe

#define FUNC_CRAFTINGMENU_CRAFTABLERECIPE_DCRAFTABLERECIPE ( base + idaOffsetFix(0x3B9B0) )


// FontRenderer

#define FUNC_FONTRENDERER_FONTRENDERER ( base + idaOffsetFix(0x4D9A0) )
#define FUNC_FONTRENDERER_OPERATOR_EQ ( base + idaOffsetFix(0x4DB40) )
#define FUNC_FONTRENDERER_SETTEXT ( base + idaOffsetFix(0x4DC50) )
#define FUNC_FONTRENDERER_RENDER ( base + idaOffsetFix(0x4DCE0) )
#define FUNC_FONTRENDERER_UPDATEMODEL ( base + idaOffsetFix(0x4DE00) )


// Inventory

#define FUNC_INVENTORY_DINVENTORY ( base + idaOffsetFix(0x1B000) )
#define FUNC_INVENTORY_RENDERINIT ( base + idaOffsetFix(0x64A50) )
#define FUNC_INVENTORY_RENDER ( base + idaOffsetFix(0x64CD0) )
#define FUNC_INVENTORY_COMBINEITEM ( base + idaOffsetFix(0x65180) )
#define FUNC_INVENTORY_PLACEITEM ( base + idaOffsetFix(0x65230) )
#define FUNC_INVENTORY_MOUSEBUTTONEVENT ( base + idaOffsetFix(0x65280) )
#define FUNC_INVENTORY_LOAD ( base + idaOffsetFix(0x65470) )
#define FUNC_INVENTORY_SAVE ( base + idaOffsetFix(0x65650) )
#define FUNC_INVENTORY_CLEAR ( base + idaOffsetFix(0x657A0) )
#define FUNC_INVENTORY_END ( base + idaOffsetFix(0x65800) )
#define FUNC_INVENTORY_GETSLOTCOUNT ( base + idaOffsetFix(0x65820) )
#define FUNC_INVENTORY_GETSLOT ( base + idaOffsetFix(0x65830) )
#define FUNC_INVENTORY_ITEMACTION ( base + idaOffsetFix(0x65880) )


// InventoryGUI

#define FUNC_INVENTORYGUI_DINVENTORYGUI ( base + idaOffsetFix(0x4E420) )
#define FUNC_INVENTORYGUI_RENDERINIT ( base + idaOffsetFix(0x65A20) )
#define FUNC_INVENTORYGUI_WINDOWRESIZE ( base + idaOffsetFix(0x65DC0) )
#define FUNC_INVENTORYGUI_UPDATECRAFTINGMENUBOX ( base + idaOffsetFix(0x65E70) )
#define FUNC_INVENTORYGUI_VIEWPORTCALLBACK ( base + idaOffsetFix(0x65F20) )
#define FUNC_INVENTORYGUI_UPDATEPROJECTION ( base + idaOffsetFix(0x65F80) )


// Item

#define FUNC_ITEM_LOADITEMINFO ( base + idaOffsetFix(0x663E0) )
#define FUNC_ITEM_RENDERINIT ( base + idaOffsetFix(0x66A70) )
#define FUNC_ITEM_RENDERITEM ( base + idaOffsetFix(0x66D90) )
#define FUNC_ITEM_RENDERITEMDESCRIPTION ( base + idaOffsetFix(0x66F20) )
#define FUNC_ITEM_CREATEFROMJSON ( base + idaOffsetFix(0x67460) )
#define FUNC_ITEM_CREATE ( base + idaOffsetFix(0x680F0) )
#define FUNC_ITEM_GIVEMAX ( base + idaOffsetFix(0x685B0) )
#define FUNC_ITEM_GIVEONE ( base + idaOffsetFix(0x68770) )
#define FUNC_ITEM_INSTANTIATEITEM ( base + idaOffsetFix(0x688E0) )
#define FUNC_ITEM_COMBINEITEMATTRIBUTES ( base + idaOffsetFix(0x68A30) )
#define FUNC_ITEM_SAVE ( base + idaOffsetFix(0x68CE0) )
#define FUNC_ITEM_TAKEHALF ( base + idaOffsetFix(0x68EE0) )


// m4

#define FUNC_M4_CROSS ( base + idaOffsetFix(0x744D0) )
#define FUNC_M4_WEDGE ( base + idaOffsetFix(0x74690) )
#define FUNC_M4_CREATECAMERA ( base + idaOffsetFix(0x755F0) )
#define FUNC_M4_ADJUSTTOMAXHORIZSPEED ( base + idaOffsetFix(0x75840) )


// m4::BiVector4

#define FUNC_M4_BIVECTOR4_NORMALIZE ( base + idaOffsetFix(0x743B0) )


// m4::Rotor

#define FUNC_M4_ROTOR_ROTOR ( base + idaOffsetFix(0x74760) )
#define FUNC_M4_ROTOR_OPERATOR_MULT_EQ ( base + idaOffsetFix(0x74820) )
#define FUNC_M4_ROTOR_ROTATE ( base + idaOffsetFix(0x74BB0) )
#define FUNC_M4_ROTOR_NORMALIZE ( base + idaOffsetFix(0x75040) )


// m4::Mat5

#define FUNC_M4_MAT5_MAT5 ( base + idaOffsetFix(0x751B0) )
#define FUNC_M4_MAT5_OPERATOR_MULT ( base + idaOffsetFix(0x751F0) )
#define FUNC_M4_MAT5_OPERATOR_MULT_EQ ( base + idaOffsetFix(0x752E0) )
#define FUNC_M4_MAT5_MULTIPLY ( base + idaOffsetFix(0x75380) )
#define FUNC_M4_MAT5_OPERATOR_MULT_VEC4 ( base + idaOffsetFix(0x75450) )
#define FUNC_M4_MAT5_OPERATOR_IND ( base + idaOffsetFix(0x75470) )
#define FUNC_M4_MAT5_TRANSLATE ( base + idaOffsetFix(0x75480) )
#define FUNC_M4_MAT5_SCALE ( base + idaOffsetFix(0x75580) )


// MeshBuilder

#define FUNC_MESHBUILDER_DMESHBUILDER ( base + idaOffsetFix(0x54360) )
#define FUNC_MESHBUILDER_BUFFCOUNT ( base + idaOffsetFix(0x54380) )
#define FUNC_MESHBUILDER_BUFFDATA ( base + idaOffsetFix(0x543B0) )
#define FUNC_MESHBUILDER_BUFFSIZE ( base + idaOffsetFix(0x543C0) )
#define FUNC_MESHBUILDER_ATTRCOUNT ( base + idaOffsetFix(0x543D0) )
#define FUNC_MESHBUILDER_VERTCOUNT ( base + idaOffsetFix(0x54400) )
#define FUNC_MESHBUILDER_INDEXBUFFDATA ( base + idaOffsetFix(0x54410) )
#define FUNC_MESHBUILDER_INDEXBUFFSIZE ( base + idaOffsetFix(0x54420) )
#define FUNC_MESHBUILDER_BUFFINFO_DBUFFINFO ( base + idaOffsetFix(0x54430) )
#define FUNC_MESHBUILDER_ATTRTYPE ( base + idaOffsetFix(0x54440) )
#define FUNC_MESHBUILDER_ATTRSIZE ( base + idaOffsetFix(0x54460) )
#define FUNC_MESHBUILDER_ATTRSTRIDE ( base + idaOffsetFix(0x54480) )
#define FUNC_MESHBUILDER_CLEAR ( base + idaOffsetFix(0x544A0) )


// MeshRenderer

#define FUNC_MESHRENDERER_MESHRENDERER ( base + idaOffsetFix(0x75A60) )
#define FUNC_MESHRENDERER_SETMESH ( base + idaOffsetFix(0x75A80) )
#define FUNC_MESHRENDERER_UPDATEMESH ( base + idaOffsetFix(0x75B10) )
#define FUNC_MESHRENDERER_DMESHRENDERER ( base + idaOffsetFix(0x75C10) )
#define FUNC_MESHRENDERER_OPERATOR_EQ ( base + idaOffsetFix(0x75C90) )
#define FUNC_MESHRENDERER_RENDER ( base + idaOffsetFix(0x75D60) )
#define FUNC_MESHRENDERER_INIT ( base + idaOffsetFix(0x75DD0) )
#define FUNC_MESHRENDERER_CLEANUP ( base + idaOffsetFix(0x75EE0) )
#define FUNC_MESHRENDERER_INITATTRS ( base + idaOffsetFix(0x75F50) )


// Player

#define FUNC_PLAYER_DPLAYER ( base + idaOffsetFix(0x4E3A0) )
#define FUNC_PLAYER_PLAYER ( base + idaOffsetFix(0x4E780) )
#define FUNC_PLAYER_UPDATEPOS ( base + idaOffsetFix(0x77070) )
#define FUNC_PLAYER_UPDATECURRENTBLOCK ( base + idaOffsetFix(0x77D70) )
#define FUNC_PLAYER_HANDLECOLLISION ( base + idaOffsetFix(0x77EF0) )
#define FUNC_PLAYER_UPDATECOMPONENTVECTORS ( base + idaOffsetFix(0x791A0) )
#define FUNC_PLAYER_REMOVEVELCOMP ( base + idaOffsetFix(0x79CE0) )
#define FUNC_PLAYER_UPDATETARGETBLOCK ( base + idaOffsetFix(0x7A230) )
#define FUNC_PLAYER_INIT ( base + idaOffsetFix(0x7ADF0) )
#define FUNC_PLAYER_RENDERHUD ( base + idaOffsetFix(0x7B090) )
#define FUNC_PLAYER_THROWITEM ( base + idaOffsetFix(0x7D3C0) )
#define FUNC_PLAYER_UPDATE ( base + idaOffsetFix(0x7D530) )
#define FUNC_PLAYER_UPDATECAMERAPOS ( base + idaOffsetFix(0x7F2A0) )
#define FUNC_PLAYER_RESETMOUSE ( base + idaOffsetFix(0x80100) )
#define FUNC_PLAYER_KEYINPUT ( base + idaOffsetFix(0x801E0) )
#define FUNC_PLAYER_MOUSEINPUT ( base + idaOffsetFix(0x809A0) )
#define FUNC_PLAYER_MOUSEBUTTONINPUT ( base + idaOffsetFix(0x80FC0) )
#define FUNC_PLAYER_ISHOLDINGGLASSES ( base + idaOffsetFix(0x81150) )
#define FUNC_PLAYER_ISHOLDINGCOMPASS ( base + idaOffsetFix(0x812D0) )
#define FUNC_PLAYER_LOAD ( base + idaOffsetFix(0x813C0) )
#define FUNC_PLAYER_SAVE ( base + idaOffsetFix(0x82860) )
#define FUNC_PLAYER_RENDERINIT ( base + idaOffsetFix(0x835C0) )


// PlayerInventoryManager

#define FUNC_PLAYERINVENTORYMANAGER_ADDITEM ( base + idaOffsetFix(0x65110) )
#define FUNC_PLAYERINVENTORYMANAGER_BEGIN ( base + idaOffsetFix(0x657F0) )
#define FUNC_PLAYERINVENTORYMANAGER_RENDER ( base + idaOffsetFix(0x83C60) )
#define FUNC_PLAYERINVENTORYMANAGER_COMBINEITEM ( base + idaOffsetFix(0x83C90) )
#define FUNC_PLAYERINVENTORYMANAGER_PLACEITEM ( base + idaOffsetFix(0x83D00) )
#define FUNC_PLAYERINVENTORYMANAGER_MOUSEBUTTONEVENT ( base + idaOffsetFix(0x83D70) )
#define FUNC_PLAYERINVENTORYMANAGER_END ( base + idaOffsetFix(0x83DF0) )
#define FUNC_PLAYERINVENTORYMANAGER_GETSLOTCOUNT ( base + idaOffsetFix(0x83E40) )
#define FUNC_PLAYERINVENTORYMANAGER_GETSLOT ( base + idaOffsetFix(0x83E70) )


// QuadRenderer

#define FUNC_QUADRENDERER_DQUADRENDERER ( base + idaOffsetFix(0x83EE0) )
#define FUNC_QUADRENDERER_INIT ( base + idaOffsetFix(0x83F20) )
#define FUNC_QUADRENDERER_SETCOLOR ( base + idaOffsetFix(0x84330) )
#define FUNC_QUADRENDERER_SETPOS ( base + idaOffsetFix(0x84410) )


// ResourceManager

#define FUNC_RESOURCEMANAGER_GET ( base + idaOffsetFix(0x84680) )


// Shader

#define FUNC_SHADER_LOAD ( base + idaOffsetFix(0x888A0) )
#define FUNC_SHADER_COMPILESHADER ( base + idaOffsetFix(0x889D0) )


// ShaderManager

#define FUNC_SHADERMANAGER_GET ( base + idaOffsetFix(0x89000) )
#define FUNC_SHADERMANAGER_LOADFROMSHADERLIST ( base + idaOffsetFix(0x89070) )


// Tex2D

#define FUNC_TEX2D_DTEX2D ( base + idaOffsetFix(0x91970) )
#define FUNC_TEX2D_LOAD ( base + idaOffsetFix(0x919A0) )
#define FUNC_TEX2D_LOADRAWIMAGEDATA ( base + idaOffsetFix(0x91AB0) )
#define FUNC_TEX2D_INITFROMTEXID ( base + idaOffsetFix(0x91BE0) )


// TexRenderer

#define FUNC_TEXRENDERER_DTEXRENDERER ( base + idaOffsetFix(0x90F20) )
#define FUNC_TEXRENDERER_OPERATOR_EQ ( base + idaOffsetFix(0x90F60) )
#define FUNC_TEXRENDERER_INIT ( base + idaOffsetFix(0x91010) )
#define FUNC_TEXRENDERER_SETCLIP ( base + idaOffsetFix(0x914F0) )
#define FUNC_TEXRENDERER_SETCOLOR ( base + idaOffsetFix(0x91620) )
#define FUNC_TEXRENDERER_SETPOS ( base + idaOffsetFix(0x91700) )


// World

#define FUNC_WORLD_DWORLD ( base + idaOffsetFix(0x4E200) )
#define FUNC_WORLD_WORLD ( base + idaOffsetFix(0xA62B0) )
#define FUNC_WORLD_SETPATH ( base + idaOffsetFix(0xA6390) )
#define FUNC_WORLD_LOADSETTINGS ( base + idaOffsetFix(0xA65E0) )
#define FUNC_WORLD_GETBLOCK ( base + idaOffsetFix(0xA6E90) )
#define FUNC_WORLD_CASTRAY ( base + idaOffsetFix(0xA7040) )
#define FUNC_WORLD_SETBLOCKUPDATE ( base + idaOffsetFix(0xA8170) )
#define FUNC_WORLD_ADDENTITY ( base + idaOffsetFix(0xA89A0) )
#define FUNC_WORLD_RENDER ( base + idaOffsetFix(0xA8A70) )
#define FUNC_WORLD_UPDATERENDERFRUSTUM ( base + idaOffsetFix(0xA8F30) )
#define FUNC_WORLD_LOADCHUNKS ( base + idaOffsetFix(0xA9460) )
#define FUNC_WORLD_LOADCHUNK ( base + idaOffsetFix(0xA9D10) )
#define FUNC_WORLD_UPDATECHUNKCACHEANDMESH ( base + idaOffsetFix(0xAA050) )
#define FUNC_WORLD_UPDATECHUNKCACHE ( base + idaOffsetFix(0xAA0A0) )
#define FUNC_WORLD_REGENERATEALLCHUNKMESHES ( base + idaOffsetFix(0xAA730) )
#define FUNC_WORLD_SAVECHUNK ( base + idaOffsetFix(0xAAA50) )
#define FUNC_WORLD_UPDATECHUNK ( base + idaOffsetFix(0xAAB60) )
#define FUNC_WORLD_GENERATECHUNK ( base + idaOffsetFix(0xAAD20) )
#define FUNC_WORLD_GENERATETREE ( base + idaOffsetFix(0xABF40) )
#define FUNC_WORLD_GENERATETREEBRANCH ( base + idaOffsetFix(0xAC5F0) )
#define FUNC_WORLD_GETCHUNK ( base + idaOffsetFix(0xACF90) )
#define FUNC_WORLD_UPDATECHUNKS ( base + idaOffsetFix(0xAD060) )
#define FUNC_WORLD_UNLOADALLCHUNKS ( base + idaOffsetFix(0xAE1F0) )
#define FUNC_WORLD_GETENTITYINTERSECTION ( base + idaOffsetFix(0xAE360) )
#define FUNC_WORLD_LOADCUBE ( base + idaOffsetFix(0xAEBD0) )


// gui::Button

#define FUNC_GUI_BUTTON_DBUTTON ( base + idaOffsetFix(0x3CEC0) )
#define FUNC_GUI_BUTTON_RENDER ( base + idaOffsetFix(0x553E0) )
#define FUNC_GUI_BUTTON_MOUSEBUTTONINPUT ( base + idaOffsetFix(0x55AF0) )
#define FUNC_GUI_BUTTON_KEYINPUT ( base + idaOffsetFix(0x55B70) )
#define FUNC_GUI_BUTTON_OFFSETX ( base + idaOffsetFix(0x55BC0) )
#define FUNC_GUI_BUTTON_ENABLED ( base + idaOffsetFix(0x55BD0) )
#define FUNC_GUI_BUTTON_GETPOS ( base + idaOffsetFix(0x55C00) )
#define FUNC_GUI_BUTTON_GETSIZE ( base + idaOffsetFix(0x55CC0) )
#define FUNC_GUI_BUTTON_TOUCHINGMOUSE ( base + idaOffsetFix(0x55CD0) )


// gui::CheckBox

#define FUNC_GUI_CHECKBOX_RENDER ( base + idaOffsetFix(0x55D60) )
#define FUNC_GUI_CHECKBOX_MOUSEBUTTONINPUT ( base + idaOffsetFix(0x56500) )
#define FUNC_GUI_CHECKBOX_KEYINPUT ( base + idaOffsetFix(0x56590) )
#define FUNC_GUI_CHECKBOX_GETPOS ( base + idaOffsetFix(0x565E0) )
#define FUNC_GUI_CHECKBOX_GETSIZE ( base + idaOffsetFix(0x566C0) )
#define FUNC_GUI_CHECKBOX_TOUCHINGMOUSE ( base + idaOffsetFix(0x56710) )


// gui::ContentBox

#define FUNC_GUI_CONTENTBOX_DCONTENTBOX ( base + idaOffsetFix(0x4E520) )
#define FUNC_GUI_CONTENTBOX_OFFSETY ( base + idaOffsetFix(0x57C00) )
#define FUNC_GUI_CONTENTBOX_GETQUADRENDERER ( base + idaOffsetFix(0x58840) )
#define FUNC_GUI_CONTENTBOX_GETFONT ( base + idaOffsetFix(0x58850) )
#define FUNC_GUI_CONTENTBOX_GETGLFWWINDOW ( base + idaOffsetFix(0x58860) )
#define FUNC_GUI_CONTENTBOX_GETCURSORPOS ( base + idaOffsetFix(0x58870) )
#define FUNC_GUI_CONTENTBOX_GETSIZE ( base + idaOffsetFix(0x588E0) )
#define FUNC_GUI_CONTENTBOX_CHANGEVIEWPORT ( base + idaOffsetFix(0x588F0) )
#define FUNC_GUI_CONTENTBOX_GETPOS ( base + idaOffsetFix(0x58A30) )
#define FUNC_GUI_CONTENTBOX_GETSIZE ( base + idaOffsetFix(0x588E0) )
#define FUNC_GUI_CONTENTBOX_TOUCHINGMOUSE ( base + idaOffsetFix(0x58AF0) )
#define FUNC_GUI_CONTENTBOX_RESETVIEWPORT ( base + idaOffsetFix(0x58B90) )
#define FUNC_GUI_CONTENTBOX_RENDER ( base + idaOffsetFix(0x58C30) )
#define FUNC_GUI_CONTENTBOX_OFFSETX ( base + idaOffsetFix(0x59740) )
#define FUNC_GUI_CONTENTBOX_MOUSEINPUT ( base + idaOffsetFix(0x59750) )
#define FUNC_GUI_CONTENTBOX_SCROLLINPUT ( base + idaOffsetFix(0x599D0) )
#define FUNC_GUI_CONTENTBOX_MOUSEBUTTONINPUT ( base + idaOffsetFix(0x59B20) )
#define FUNC_GUI_CONTENTBOX_KEYINPUT ( base + idaOffsetFix(0x59E10) )
#define FUNC_GUI_CONTENTBOX_SELECT ( base + idaOffsetFix(0x59FD0) )
#define FUNC_GUI_CONTENTBOX_DESELECT ( base + idaOffsetFix(0x5A000) )
#define FUNC_GUI_CONTENTBOX_ADDELEMENT ( base + idaOffsetFix(0x5A040) )
#define FUNC_GUI_CONTENTBOX_REMOVEELEMENT ( base + idaOffsetFix(0x5A080) )
#define FUNC_GUI_CONTENTBOX_SELECTELEMENT ( base + idaOffsetFix(0x5A0F0) )
#define FUNC_GUI_CONTENTBOX_CLEAR ( base + idaOffsetFix(0x5A1B0) )
#define FUNC_GUI_CONTENTBOX_EMPTY ( base + idaOffsetFix(0x5A200) )


// gui::Image

#define FUNC_GUI_IMAGE_RENDER ( base + idaOffsetFix(0x5AEA0) )
#define FUNC_GUI_IMAGE_ALIGNX ( base + idaOffsetFix(0x5AF70) )
#define FUNC_GUI_IMAGE_ALIGNY ( base + idaOffsetFix(0x5AF80) )
#define FUNC_GUI_IMAGE_OFFSETX ( base + idaOffsetFix(0x5AF90) )
#define FUNC_GUI_IMAGE_OFFSETY ( base + idaOffsetFix(0x5AFA0) )
#define FUNC_GUI_IMAGE_GETPOS ( base + idaOffsetFix(0x5AFB0) )
#define FUNC_GUI_IMAGE_GETSIZE ( base + idaOffsetFix(0x5B090) )


// gui::Interface

#define FUNC_GUI_INTERFACE_DINTERFACE ( base + idaOffsetFix(0x3CE60) )
#define FUNC_GUI_INTERFACE_RENDER ( base + idaOffsetFix(0x54C60) )
#define FUNC_GUI_INTERFACE_MOUSEINPUT ( base + idaOffsetFix(0x54D50) )
#define FUNC_GUI_INTERFACE_SCROLLINPUT ( base + idaOffsetFix(0x54DE0) )
#define FUNC_GUI_INTERFACE_MOUSEBUTTONINPUT ( base + idaOffsetFix(0x54E80) )
#define FUNC_GUI_INTERFACE_KEYINPUT ( base + idaOffsetFix(0x54F80) )
#define FUNC_GUI_INTERFACE_GETQUADRENDERER ( base + idaOffsetFix(0x55130) )
#define FUNC_GUI_INTERFACE_GETFONT ( base + idaOffsetFix(0x55140) )
#define FUNC_GUI_INTERFACE_GETGLFWWINDOW ( base + idaOffsetFix(0x55150) )
#define FUNC_GUI_INTERFACE_GETCURSORPOS ( base + idaOffsetFix(0x55160) )
#define FUNC_GUI_INTERFACE_GETSIZE ( base + idaOffsetFix(0x551C0) )
#define FUNC_GUI_INTERFACE_CHANGEVIEWPORT ( base + idaOffsetFix(0x551D0) )
#define FUNC_GUI_INTERFACE_ADDELEMENT ( base + idaOffsetFix(0x551F0) )
#define FUNC_GUI_INTERFACE_REMOVEELEMENT ( base + idaOffsetFix(0x55230) )
#define FUNC_GUI_INTERFACE_SELECTELEMENT ( base + idaOffsetFix(0x552C0) )
#define FUNC_GUI_INTERFACE_CLEAR ( base + idaOffsetFix(0x55380) )
#define FUNC_GUI_INTERFACE_EMPTY ( base + idaOffsetFix(0x553D0) )


// gui::Slider

#define FUNC_GUI_SLIDER_OFFSETX ( base + idaOffsetFix(0x3A180) )
#define FUNC_GUI_SLIDER_OFFSETY ( base + idaOffsetFix(0x3A190) )
#define FUNC_GUI_SLIDER_DESELECT ( base + idaOffsetFix(0x55BF0) )
#define FUNC_GUI_SLIDER_RENDER ( base + idaOffsetFix(0x567A0) )
#define FUNC_GUI_SLIDER_MOUSEBUTTONINPUT ( base + idaOffsetFix(0x56DE0) )
#define FUNC_GUI_SLIDER_MOUSEINPUT ( base + idaOffsetFix(0x56EC0) )
#define FUNC_GUI_SLIDER_KEYINPUT ( base + idaOffsetFix(0x56F80) )
#define FUNC_GUI_SLIDER_ALIGNX ( base + idaOffsetFix(0x56FE0) )
#define FUNC_GUI_SLIDER_ALIGNY ( base + idaOffsetFix(0x56FF0) )
#define FUNC_GUI_SLIDER_GETPOS ( base + idaOffsetFix(0x57000) )
#define FUNC_GUI_SLIDER_GETSIZE ( base + idaOffsetFix(0x570B0) )


// gui::Text

#define FUNC_GUI_TEXT_RENDER ( base + idaOffsetFix(0x5A210) )
#define FUNC_GUI_TEXT_OFFSETX ( base + idaOffsetFix(0x5A620) )
#define FUNC_GUI_TEXT_GETPOS ( base + idaOffsetFix(0x5A630) )
#define FUNC_GUI_TEXT_GETSIZE ( base + idaOffsetFix(0x5A710) )
#define FUNC_GUI_TEXT_SETTEXT ( base + idaOffsetFix(0x5A980) )
#define FUNC_GUI_TEXT_RENDERTEXT ( base + idaOffsetFix(0x5AB20) )


// gui::TextInput

#define FUNC_GUI_TEXTINPUT_SELECT ( base + idaOffsetFix(0x55BE0) )
#define FUNC_GUI_TEXTINPUT_RENDER ( base + idaOffsetFix(0x570C0) )
#define FUNC_GUI_TEXTINPUT_ALIGNX ( base + idaOffsetFix(0x57BE0) )
#define FUNC_GUI_TEXTINPUT_ALIGNY ( base + idaOffsetFix(0x57BF0) )
#define FUNC_GUI_TEXTINPUT_OFFSETY ( base + idaOffsetFix(0x57C10) )
#define FUNC_GUI_TEXTINPUT_MOUSEBUTTONINPUT ( base + idaOffsetFix(0x57C20) )
#define FUNC_GUI_TEXTINPUT_MOUSEINPUT ( base + idaOffsetFix(0x57D80) )
#define FUNC_GUI_TEXTINPUT_KEYINPUT ( base + idaOffsetFix(0x57E40) )
#define FUNC_GUI_TEXTINPUT_CHARINPUT ( base + idaOffsetFix(0x58530) )
#define FUNC_GUI_TEXTINPUT_DESELECT ( base + idaOffsetFix(0x58630) )
#define FUNC_GUI_TEXTINPUT_UPDATESCROLLPOS ( base + idaOffsetFix(0x58640) )
#define FUNC_GUI_TEXTINPUT_GETPOS ( base + idaOffsetFix(0x586C0) )
#define FUNC_GUI_TEXTINPUT_GETSIZE ( base + idaOffsetFix(0x58780) )
#define FUNC_GUI_TEXTINPUT_REMOVEHIGHLIGHTEDTEXT ( base + idaOffsetFix(0x58790) )


// GameState

#define FUNC_GAMESTATE_GAMESTATE ( base + idaOffsetFix(0x4E580) )
#define FUNC_GAMESTATE_INIT ( base + idaOffsetFix(0x4ECE0) )
#define FUNC_GAMESTATE_CLOSE ( base + idaOffsetFix(0x4F8B0) )
#define FUNC_GAMESTATE_PAUSE ( base + idaOffsetFix(0x4FF20) )
#define FUNC_GAMESTATE_RESUME ( base + idaOffsetFix(0x4FF70) )
#define FUNC_GAMESTATE_UPDATE ( base + idaOffsetFix(0x50030) )
#define FUNC_GAMESTATE_RENDER ( base + idaOffsetFix(0x50360) )
#define FUNC_GAMESTATE_MOUSEINPUT ( base + idaOffsetFix(0x51FC0) )
#define FUNC_GAMESTATE_SCROLLINPUT ( base + idaOffsetFix(0x51FD0) )
#define FUNC_GAMESTATE_MOUSEBUTTONINPUT ( base + idaOffsetFix(0x520D0) )
#define FUNC_GAMESTATE_KEYINPUT ( base + idaOffsetFix(0x520E0) )
#define FUNC_GAMESTATE_WINDOWRESIZE ( base + idaOffsetFix(0x521A0) )
#define FUNC_GAMESTATE_UPDATEPROJECTION ( base + idaOffsetFix(0x521F0) )


// CreateWorldState

#define FUNC_CREATEWORLDSTATE_CREATEWORLDSTATE ( base + idaOffsetFix(0x3CED0) )
#define FUNC_CREATEWORLDSTATE_UPDATEPROJECTION ( base + idaOffsetFix(0x3D310) )
#define FUNC_CREATEWORLDSTATE_CREATEWORLDCANCEL ( base + idaOffsetFix(0x3D7C0) )
#define FUNC_CREATEWORLDSTATE_CREATENEWWORLD ( base + idaOffsetFix(0x3D810) )
#define FUNC_CREATEWORLDSTATE_VIEWPORTCALLBACK ( base + idaOffsetFix(0x3D9A0) )
#define FUNC_CREATEWORLDSTATE_INIT ( base + idaOffsetFix(0x3DA30) )
#define FUNC_CREATEWORLDSTATE_CLOSE ( base + idaOffsetFix(0x3E1D0) )
#define FUNC_CREATEWORLDSTATE_UPDATE ( base + idaOffsetFix(0x3E1E0) )
#define FUNC_CREATEWORLDSTATE_RESUME ( base + idaOffsetFix(0x3E440) )
#define FUNC_CREATEWORLDSTATE_WINDOWRESIZE ( base + idaOffsetFix(0x3E590) )
#define FUNC_CREATEWORLDSTATE_HANDLECREATEBUTTON ( base + idaOffsetFix(0x3E5F0) )


// TitleState

#define FUNC_TITLESTATE_TITLESTATE ( base + idaOffsetFix(0x91CD0) )
#define FUNC_TITLESTATE_UPDATEPROJECTION ( base + idaOffsetFix(0x92120) )
#define FUNC_TITLESTATE_SINGLEPLAYERBUTTONCALLBACK ( base + idaOffsetFix(0x925A0) )
#define FUNC_TITLESTATE_CREDITSBUTTONCALLBACK ( base + idaOffsetFix(0x92630) )
#define FUNC_TITLESTATE_TUTORIALBUTTONCALLBACK ( base + idaOffsetFix(0x926C0) )
#define FUNC_TITLESTATE_INIT ( base + idaOffsetFix(0x92750) )
#define FUNC_TITLESTATE_CLOSE ( base + idaOffsetFix(0x93040) )
#define FUNC_TITLESTATE_UPDATE ( base + idaOffsetFix(0x931B0) )
#define FUNC_TITLESTATE_RENDER ( base + idaOffsetFix(0x932A0) )
#define FUNC_TITLESTATE_KEYINPUT ( base + idaOffsetFix(0x93A80) )
#define FUNC_TITLESTATE_WINDOWRESIZE ( base + idaOffsetFix(0x93B10) )
#define FUNC_TITLESTATE_MOUSEINPUT ( base + idaOffsetFix(0x93B20) )
#define FUNC_TITLESTATE_MOUSEBUTTONINPUT ( base + idaOffsetFix(0x93B40) )
#define FUNC_TITLESTATE_RESUME ( base + idaOffsetFix(0x93B70) )
#define FUNC_TITLESTATE_RENDERBACKGROUND ( base + idaOffsetFix(0x93BD0) )


