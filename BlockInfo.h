#pragma once

#include "4dm.h"
#include "MeshRenderer.h"

namespace fdm 
{
	class BlockInfo 
	{
	public:
		struct VertLighting 
		{
			uint32_t ambient; 
			uint32_t shadow; // 0x1
			glm::u8vec3 glow; // 0x2

		};
		struct ItemMesh 
		{
			MeshRenderer renderer; 

			~ItemMesh() 
			{
				reinterpret_cast<void(__thiscall*)(BlockInfo::ItemMesh* self)>(FUNC_BLOCKINFO_ITEMMESH_DESTR_ITEMMESH)(this);
			}
		};

		enum TYPE
		{
			AIR = 0x0,
			VISIBLE_BLOCK_START = 0x1,
			GRASS = 0x1,
			DIRT = 0x2,
			STONE = 0x3,
			WOOD = 0x4,
			LEAF = 0x5,
			LAVA = 0x6,
			IRON_ORE = 0x7,
			DEADLY_ORE = 0x8,
			CHEST = 0x9,
			MIDNIGHT_GRASS = 0xA,
			MIDNIGHT_SOIL = 0xB,
			MIDNIGHT_STONE = 0xC,
			MIDNIGHT_WOOD = 0xD,
			MIDNIGHT_LEAF = 0xE,
			BUSH = 0xF,
			MIDNIGHT_BUSH = 0x10,
			RED_FLOWER = 0x11,
			WHITE_FLOWER = 0x12,
			BLUE_FLOWER = 0x13,
			TALL_GRASS = 0x14,
			SAND = 0x15,
			SANDSTONE = 0x16,
			CACTUS = 0x17,
			SNOW = 0x18,
			ICE = 0x19,
			SNOWY_BUSH = 0x1A,
			GLASS = 0x1B,
			SOLENOID_ORE = 0x1C,
			SNOWY_LEAF = 0x1D,
			PUMPKIN = 0x1E,
			JACK_O_LANTERN = 0x1F,
			VISIBLE_BLOCK_END = 0x20,
			SPECIAL_BLOCK_START = 0x20,
			BARRIER = 0x20,
			CHUNK_BORDER = 0x21,
			SPECIAL_BLOCK_END = 0x22,
			BLOCK_END = 0x22,
		};

		inline static const int TET_VERT_COUNT = 4; 
		inline static const int CUBE_TET_COUNT = 5; 
		inline static const int CUBE_FULL_INDEX_COUNT = 20; 
		inline static const int HYPERCUBE_FULL_INDEX_COUNT = 160; 
		inline static const int PLANT_FULL_INDEX_COUNT = 240; 
		inline static const int SQUARE_VERT_COUNT = 4; 
		inline static const int CUBE_VERT_COUNT = 8; 
		inline static const int HYPERCUBE_VERT_COUNT = 64; 
		inline static const int PLANT_VERT_COUNT = 48; 
		inline static glm::u8vec4** tuv_grass_top = reinterpret_cast<glm::u8vec4**>((base + 0x2AA740));
		inline static glm::u8vec4* *tuv_grass_side = reinterpret_cast<glm::u8vec4**>((base + 0x2AC730)); 
		inline static glm::u8vec4* *tuv_grass_full = reinterpret_cast<glm::u8vec4**>((base + 0x2A9E70)); 
		inline static glm::u8vec3* *uv_grass_top = reinterpret_cast<glm::u8vec3**>((base + 0x2AA230)); 
		inline static glm::u8vec3* *uv_grass_side = reinterpret_cast<glm::u8vec3**>((base + 0x2AB590)); 
		inline static glm::u8vec4* *tuv_dirt = reinterpret_cast<glm::u8vec4**>((base + 0x2AB0A0)); 
		inline static glm::u8vec4* *tuv_dirt_full = reinterpret_cast<glm::u8vec4**>((base + 0x2AC7B0)); 
		inline static glm::u8vec3* *uv_dirt = reinterpret_cast<glm::u8vec3**>((base + 0x2AB980)); 
		inline static glm::u8vec4* *tuv_stone = reinterpret_cast<glm::u8vec4**>((base + 0x2ABB70)); 
		inline static glm::u8vec4* *tuv_stone_full = reinterpret_cast<glm::u8vec4**>((base + 0x2AB9B0)); 
		inline static glm::u8vec3* *uv_stone = reinterpret_cast<glm::u8vec3**>((base + 0x2A9E00)); 
		inline static glm::u8vec4* *tuv_lava = reinterpret_cast<glm::u8vec4**>((base + 0x2AC180)); 
		inline static glm::u8vec4* *tuv_lava_full = reinterpret_cast<glm::u8vec4**>((base + 0x2AC610)); 
		inline static glm::u8vec3* *uv_lava = reinterpret_cast<glm::u8vec3**>((base + 0x2AA780)); 
		inline static glm::u8vec4* *tuv_wood_top = reinterpret_cast<glm::u8vec4**>((base + 0x2AB990)); 
		inline static glm::u8vec4* *tuv_wood_side = reinterpret_cast<glm::u8vec4**>((base + 0x2A9E50)); 
		inline static glm::u8vec4* *tuv_wood_full = reinterpret_cast<glm::u8vec4**>((base + 0x2AB370)); 
		inline static glm::u8vec4* *tuv_leaf = reinterpret_cast<glm::u8vec4**>((base + 0x2AA720)); 
		inline static glm::u8vec4* *tuv_leaf_full = reinterpret_cast<glm::u8vec4**>((base + 0x2AB880)); 
		inline static glm::u8vec4* *tuv_iron_ore = reinterpret_cast<glm::u8vec4**>((base + 0x2AC160)); 
		inline static glm::u8vec4* *tuv_iron_ore_full = reinterpret_cast<glm::u8vec4**>((base + 0x2ABFA0)); 
		inline static glm::u8vec4* *tuv_deadly_ore = reinterpret_cast<glm::u8vec4**>((base + 0x2AB820)); 
		inline static glm::u8vec4* *tuv_deadly_ore_full = reinterpret_cast<glm::u8vec4**>((base + 0x2AC3F0)); 
		inline static glm::u8vec4* *tuv_chest_top = reinterpret_cast<glm::u8vec4**>((base + 0x2AAA10)); 
		inline static glm::u8vec4* *tuv_chest_side = reinterpret_cast<glm::u8vec4**>((base + 0x2AA760)); 
		inline static glm::u8vec4* *tuv_chest_bottom = reinterpret_cast<glm::u8vec4**>((base + 0x2A9DA0)); 
		inline static glm::u8vec4* *tuv_chest_full = reinterpret_cast<glm::u8vec4**>((base + 0x2AC510)); 
		inline static glm::u8vec4* *tuv_midnight_grass_top = reinterpret_cast<glm::u8vec4**>((base + 0x2AA0D0)); 
		inline static glm::u8vec4* *tuv_midnight_grass_side = reinterpret_cast<glm::u8vec4**>((base + 0x2AB490)); 
		inline static glm::u8vec4* *tuv_midnight_grass_full = reinterpret_cast<glm::u8vec4**>((base + 0x2AC2D0)); 
		inline static glm::u8vec4* *tuv_midnight_soil = reinterpret_cast<glm::u8vec4**>((base + 0x2ABB90)); 
		inline static glm::u8vec4* *tuv_midnight_soil_full = reinterpret_cast<glm::u8vec4**>((base + 0x2AC970)); 
		inline static glm::u8vec4* *tuv_midnight_stone = reinterpret_cast<glm::u8vec4**>((base + 0x2AA090)); 
		inline static glm::u8vec4* *tuv_midnight_stone_full = reinterpret_cast<glm::u8vec4**>((base + 0x2AA620)); 
		inline static glm::u8vec4* *tuv_midnight_wood_top = reinterpret_cast<glm::u8vec4**>((base + 0x2AC2B0)); 
		inline static glm::u8vec4* *tuv_midnight_wood_side = reinterpret_cast<glm::u8vec4**>((base + 0x2AB840)); 
		inline static glm::u8vec4* *tuv_midnight_wood_full = reinterpret_cast<glm::u8vec4**>((base + 0x2AAEC0)); 
		inline static glm::u8vec4* *tuv_midnight_leaf = reinterpret_cast<glm::u8vec4**>((base + 0x2AC4F0)); 
		inline static glm::u8vec4* *tuv_midnight_leaf_full = reinterpret_cast<glm::u8vec4**>((base + 0x2AAA30)); 
		inline static glm::u8vec4* *tuv_bush = reinterpret_cast<glm::u8vec4**>((base + 0x2AA1F0)); 
		inline static glm::u8vec4* *tuv_bush_full = reinterpret_cast<glm::u8vec4**>((base + 0x2ABBB0)); 
		inline static glm::u8vec4* *tuv_midnight_bush = reinterpret_cast<glm::u8vec4**>((base + 0x2A9E10)); 
		inline static glm::u8vec4* *tuv_midnight_bush_full = reinterpret_cast<glm::u8vec4**>((base + 0x2AAFC0)); 
		inline static glm::u8vec4* *tuv_red_flower = reinterpret_cast<glm::u8vec4**>((base + 0x2A9DE0)); 
		inline static glm::u8vec4* *tuv_red_flower_full = reinterpret_cast<glm::u8vec4**>((base + 0x2ABC80)); 
		inline static glm::u8vec4* *tuv_white_flower = reinterpret_cast<glm::u8vec4**>((base + 0x2AC710)); 
		inline static glm::u8vec4* *tuv_white_flower_full = reinterpret_cast<glm::u8vec4**>((base + 0x2AB220)); 
		inline static glm::u8vec4* *tuv_blue_flower = reinterpret_cast<glm::u8vec4**>((base + 0x2ABD40)); 
		inline static glm::u8vec4* *tuv_blue_flower_full = reinterpret_cast<glm::u8vec4**>((base + 0x2AB4B0)); 
		inline static glm::u8vec4* *tuv_tall_grass = reinterpret_cast<glm::u8vec4**>((base + 0x2AAC50)); 
		inline static glm::u8vec4* *tuv_tall_grass_full = reinterpret_cast<glm::u8vec4**>((base + 0x2ABAB0)); 
		inline static glm::u8vec4* *tuv_sand = reinterpret_cast<glm::u8vec4**>((base + 0x2AB860)); 
		inline static glm::u8vec4* *tuv_sand_full = reinterpret_cast<glm::u8vec4**>((base + 0x2ACA70)); 
		inline static glm::u8vec4* *tuv_sandstone = reinterpret_cast<glm::u8vec4**>((base + 0x2AC790)); 
		inline static glm::u8vec4* *tuv_sandstone_full = reinterpret_cast<glm::u8vec4**>((base + 0x2ABDA0)); 
		inline static glm::u8vec4* *tuv_cactus = reinterpret_cast<glm::u8vec4**>((base + 0x2AA240)); 
		inline static glm::u8vec4* *tuv_cactus_full = reinterpret_cast<glm::u8vec4**>((base + 0x2AC0A0)); 
		inline static glm::u8vec4* *tuv_snow = reinterpret_cast<glm::u8vec4**>((base + 0x2A9E30)); 
		inline static glm::u8vec4* *tuv_snow_full = reinterpret_cast<glm::u8vec4**>((base + 0x2ACB70)); 
		inline static glm::u8vec4* *tuv_ice = reinterpret_cast<glm::u8vec4**>((base + 0x2AB080)); 
		inline static glm::u8vec4* *tuv_ice_full = reinterpret_cast<glm::u8vec4**>((base + 0x2A9F70)); 
		inline static glm::u8vec4* *tuv_snowy_bush = reinterpret_cast<glm::u8vec4**>((base + 0x2AAC30)); 
		inline static glm::u8vec4* *tuv_snowy_bush_full = reinterpret_cast<glm::u8vec4**>((base + 0x2AC1A0)); 
		inline static glm::u8vec4* *tuv_glass = reinterpret_cast<glm::u8vec4**>((base + 0x2AC770)); 
		inline static glm::u8vec4* *tuv_glass_full = reinterpret_cast<glm::u8vec4**>((base + 0x2AB0D0)); 
		inline static glm::u8vec4* *tuv_solenoid_ore = reinterpret_cast<glm::u8vec4**>((base + 0x2AC3D0)); 
		inline static glm::u8vec4* *tuv_solenoid_ore_full = reinterpret_cast<glm::u8vec4**>((base + 0x2ABEA0)); 
		inline static glm::u8vec4* *tuv_snowy_leaf_top = reinterpret_cast<glm::u8vec4**>((base + 0x2AB470)); 
		inline static glm::u8vec4* *tuv_snowy_leaf_side = reinterpret_cast<glm::u8vec4**>((base + 0x2AA0B0)); 
		inline static glm::u8vec4* *tuv_snowy_leaf_bottom = reinterpret_cast<glm::u8vec4**>((base + 0x2A9DC0)); 
		inline static glm::u8vec4* *tuv_snowy_leaf_full = reinterpret_cast<glm::u8vec4**>((base + 0x2AAB30)); 
		inline static glm::u8vec4* *tuv_pumpkin_top = reinterpret_cast<glm::u8vec4**>((base + 0x2AA070)); 
		inline static glm::u8vec4* *tuv_pumpkin_side = reinterpret_cast<glm::u8vec4**>((base + 0x2ABD60)); 
		inline static glm::u8vec4* *tuv_pumpkin_full = reinterpret_cast<glm::u8vec4**>((base + 0x2AA0F0)); 
		inline static glm::u8vec4* *tuv_jack_o_lantern_side = reinterpret_cast<glm::u8vec4**>((base + 0x2AC750)); 
		inline static glm::u8vec4* *tuv_jack_o_lantern_full = reinterpret_cast<glm::u8vec4**>((base + 0x2AAD70)); 
		inline static const int BLOCK_COUNT = 34; 
		inline static const int VISIBLE_BLOCK_COUNT = 31; 
		/*struct 
		{

		} Blocks;*/
		inline static glm::u8vec4* *cube_verts_x = reinterpret_cast<glm::u8vec4**>((base + 0x2AB570)); 
		inline static glm::u8vec4* *cube_verts_y = reinterpret_cast<glm::u8vec4**>((base + 0x2ABD80)); 
		inline static glm::u8vec4* *cube_verts_z = reinterpret_cast<glm::u8vec4**>((base + 0x2AA210)); 
		inline static glm::u8vec4* *cube_verts_w = reinterpret_cast<glm::u8vec4**>((base + 0x2AAE98)); 
		inline static glm::u8vec4* *hypercube_full_verts = reinterpret_cast<glm::u8vec4**>((base + 0x2AAC70)); 
		inline static glm::u8vec3* *hypercube_full_tuvs = reinterpret_cast<glm::u8vec3**>((base + 0x2AC8B0)); 
		inline static glm::vec4** hypercube_full_normals = reinterpret_cast<glm::vec4**>((base + 0x2AA910));
		inline static uint32_t** hypercube_full_indices = reinterpret_cast<uint32_t**>((base + 0x2AB5A0));
		inline static glm::u8vec4** plant_full_verts = reinterpret_cast<glm::u8vec4**>((base + 0x2AA790));
		inline static glm::vec4** plant_full_normals = reinterpret_cast<glm::vec4**>((base + 0x2C3E50));
		inline static uint32_t** plant_full_indices = reinterpret_cast<uint32_t**>((base + 0x2AA260));
		inline static glm::u8vec3* *square_verts_x = reinterpret_cast<glm::u8vec3**>((base + 0x2AAE88)); 
		inline static glm::u8vec3* *square_verts_y = reinterpret_cast<glm::u8vec3**>((base + 0x2AB0C0)); 
		inline static glm::u8vec3* *square_verts_z = reinterpret_cast<glm::u8vec3**>((base + 0x2ABC70)); 
		inline static glm::u8vec3* *cube_verts = reinterpret_cast<glm::u8vec3**>((base + 0x2AAE70)); 
		inline static uint32_t** cube_indices = reinterpret_cast<uint32_t**>((base + 0x2AC260));
		inline static glm::u8vec3* *cube_verts_triangles = reinterpret_cast<glm::u8vec3**>((base + 0x2AB2E0)); 
		inline static glm::u8vec3* *cube_verts_lines = reinterpret_cast<glm::u8vec3**>((base + 0x2AB1D0)); 
		inline static std::unordered_map<std::string,uint8_t>* blockIDs = reinterpret_cast<std::unordered_map<std::string,uint8_t>*>((base + 0x2C3FD0));
		inline static std::unordered_map<uint8_t,std::string>* blockNames = reinterpret_cast<std::unordered_map<uint8_t,std::string>*>((base + 0x2C4010));
		inline static BlockInfo::ItemMesh** itemMeshes = reinterpret_cast<BlockInfo::ItemMesh**>((base + 0x2BDB30));

		inline static void renderItemMesh(uint8_t blockID) 
		{
			return reinterpret_cast<void (__fastcall*)(uint8_t blockID)>(FUNC_BLOCKINFO_RENDERITEMMESH)(blockID);
		}
	};
}
