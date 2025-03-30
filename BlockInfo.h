#pragma once

#include "4dm.h"
#include "MeshRenderer.h"

// creates a cube out of tetrahedrons.
// the offsets are ordered such that each vertex corresponds to one normal component,
// which allows an index buffer to be used without needing a normal for each vertex.
#define _cube_tet_indices(offset)\
(offset)+0,(offset)+6,(offset)+5,(offset)+3,\
(offset)+0,(offset)+1,(offset)+5,(offset)+3,\
(offset)+0,(offset)+6,(offset)+2,(offset)+3,\
(offset)+0,(offset)+6,(offset)+5,(offset)+4,\
(offset)+7,(offset)+6,(offset)+5,(offset)+3

#define _cube_normal(x, y, z, w)\
{ (x), (y), (z), (w) },\
{ (w), (z), (y), (x) }

namespace fdm 
{
	class BlockInfo 
	{
	public:
		struct BlockData
		{
			glm::u8vec4* tuv_top;// 0x0
			glm::u8vec4* tuv_side;// 0x8
			glm::u8vec4* tuv_bottom;// 0x10
			glm::u8vec4* tuv_full_block;// 0x18
			glm::u8vec4* uv_top;// 0x20
			glm::u8vec4* uv_side;// 0x28
			glm::u8vec4* uv_bottom;// 0x30
			bool solid;// 0x38
			bool opaque;// 0x39
			bool plant;// 0x3A
			glm::u8vec3 glowColor;// 0x3B
			PAD(2);
		};
		struct VertLighting 
		{
			uint8_t ambient;
			uint8_t shadow;// 0x1
			glm::u8vec3 glow;// 0x2
		};
		struct ItemMesh 
		{
			MeshRenderer renderer;

			~ItemMesh() 
			{
				reinterpret_cast<void(__thiscall*)(BlockInfo::ItemMesh* self)>(getFuncAddr((int)Func::BlockInfo::ItemMesh::destr_ItemMesh))(this);
			}
		};

		enum TYPE : int
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

		inline static constexpr const int TET_VERT_COUNT = 4;
		inline static constexpr const int CUBE_TET_COUNT = 5;
		inline static constexpr const int CUBE_FULL_INDEX_COUNT = 20;
		inline static constexpr const int HYPERCUBE_FULL_INDEX_COUNT = 160;
		inline static constexpr const int PLANT_FULL_INDEX_COUNT = 240;
		inline static constexpr const int SQUARE_VERT_COUNT = 4;
		inline static constexpr const int CUBE_VERT_COUNT = 8;
		inline static constexpr const int HYPERCUBE_VERT_COUNT = 64;
		inline static constexpr const int PLANT_VERT_COUNT = 48;

		inline static const glm::u8vec4 hypercube_full_verts[HYPERCUBE_VERT_COUNT] =
		{
			// -x
			{ 0, 0, 0, 0 },
			{ 0, 0, 1, 0 },
			{ 0, 1, 0, 0 },
			{ 0, 1, 1, 0 },
			{ 0, 0, 0, 1 },
			{ 0, 0, 1, 1 },
			{ 0, 1, 0, 1 },
			{ 0, 1, 1, 1 },
			// +x
			{ 1, 0, 0, 0 },
			{ 1, 0, 1, 0 },
			{ 1, 1, 0, 0 },
			{ 1, 1, 1, 0 },
			{ 1, 0, 0, 1 },
			{ 1, 0, 1, 1 },
			{ 1, 1, 0, 1 },
			{ 1, 1, 1, 1 },
			// -y
			{ 0, 0, 0, 0 },
			{ 1, 0, 0, 0 },
			{ 0, 0, 1, 0 },
			{ 1, 0, 1, 0 },
			{ 0, 0, 0, 1 },
			{ 1, 0, 0, 1 },
			{ 0, 0, 1, 1 },
			{ 1, 0, 1, 1 },
			// +y
			{ 0, 1, 0, 0 },
			{ 1, 1, 0, 0 },
			{ 0, 1, 1, 0 },
			{ 1, 1, 1, 0 },
			{ 0, 1, 0, 1 },
			{ 1, 1, 0, 1 },
			{ 0, 1, 1, 1 },
			{ 1, 1, 1, 1 },
			// -z
			{ 0, 0, 0, 0 },
			{ 1, 0, 0, 0 },
			{ 0, 1, 0, 0 },
			{ 1, 1, 0, 0 },
			{ 0, 0, 0, 1 },
			{ 1, 0, 0, 1 },
			{ 0, 1, 0, 1 },
			{ 1, 1, 0, 1 },
			// +z
			{ 0, 0, 1, 0 },
			{ 1, 0, 1, 0 },
			{ 0, 1, 1, 0 },
			{ 1, 1, 1, 0 },
			{ 0, 0, 1, 1 },
			{ 1, 0, 1, 1 },
			{ 0, 1, 1, 1 },
			{ 1, 1, 1, 1 },
			// -w
			{ 0, 0, 0, 0 },
			{ 1, 0, 0, 0 },
			{ 0, 1, 0, 0 },
			{ 1, 1, 0, 0 },
			{ 0, 0, 1, 0 },
			{ 1, 0, 1, 0 },
			{ 0, 1, 1, 0 },
			{ 1, 1, 1, 0 },
			// +w
			{ 0, 0, 0, 1 },
			{ 1, 0, 0, 1 },
			{ 0, 1, 0, 1 },
			{ 1, 1, 0, 1 },
			{ 0, 0, 1, 1 },
			{ 1, 0, 1, 1 },
			{ 0, 1, 1, 1 },
			{ 1, 1, 1, 1 },
		};

		inline static const glm::u8vec3 hypercube_full_tuvs[HYPERCUBE_VERT_COUNT] =
		{
			// -x
			{ 0, 0, 0 },
			{ 1, 0, 0 },
			{ 0, 1, 0 },
			{ 1, 1, 0 },
			{ 0, 0, 1 },
			{ 1, 0, 1 },
			{ 0, 1, 1 },
			{ 1, 1, 1 },
			// +x
			{ 0, 0, 0 },
			{ 1, 0, 0 },
			{ 0, 1, 0 },
			{ 1, 1, 0 },
			{ 0, 0, 1 },
			{ 1, 0, 1 },
			{ 0, 1, 1 },
			{ 1, 1, 1 },
			// -y
			{ 0, 0, 0 },
			{ 1, 0, 0 },
			{ 0, 1, 0 },
			{ 1, 1, 0 },
			{ 0, 0, 1 },
			{ 1, 0, 1 },
			{ 0, 1, 1 },
			{ 1, 1, 1 },
			// +y
			{ 0, 0, 0 },
			{ 1, 0, 0 },
			{ 0, 1, 0 },
			{ 1, 1, 0 },
			{ 0, 0, 1 },
			{ 1, 0, 1 },
			{ 0, 1, 1 },
			{ 1, 1, 1 },
			// -z
			{ 0, 0, 0 },
			{ 1, 0, 0 },
			{ 0, 1, 0 },
			{ 1, 1, 0 },
			{ 0, 0, 1 },
			{ 1, 0, 1 },
			{ 0, 1, 1 },
			{ 1, 1, 1 },
			// +z
			{ 0, 0, 0 },
			{ 1, 0, 0 },
			{ 0, 1, 0 },
			{ 1, 1, 0 },
			{ 0, 0, 1 },
			{ 1, 0, 1 },
			{ 0, 1, 1 },
			{ 1, 1, 1 },
			// -w
			{ 0, 0, 0 },
			{ 1, 0, 0 },
			{ 0, 1, 0 },
			{ 1, 1, 0 },
			{ 0, 0, 1 },
			{ 1, 0, 1 },
			{ 0, 1, 1 },
			{ 1, 1, 1 },
			// +w
			{ 0, 0, 0 },
			{ 1, 0, 0 },
			{ 0, 1, 0 },
			{ 1, 1, 0 },
			{ 0, 0, 1 },
			{ 1, 0, 1 },
			{ 0, 1, 1 },
			{ 1, 1, 1 },
		};

		inline static const glm::vec4 hypercube_full_normals[HYPERCUBE_VERT_COUNT / 4] =
		{
			// -x
			_cube_normal(-1, 0, 0, 0),
			// +x
			_cube_normal(1, 0, 0, 0),

			// -y
			_cube_normal(0, -1, 0, 0),
			// +y
			_cube_normal(0, 1, 0, 0),

			// -z
			_cube_normal(0, 0, -1, 0),
			// +z
			_cube_normal(0, 0, 1, 0),

			// -w
			_cube_normal(0, 0, 0, -1),
			// +w
			_cube_normal(0, 0, 0, 1),
		};

		// indices for the full hypercube mesh
		inline static const GLuint hypercube_full_indices[HYPERCUBE_FULL_INDEX_COUNT] =
		{
			_cube_tet_indices(CUBE_VERT_COUNT * 0),
			_cube_tet_indices(CUBE_VERT_COUNT * 1),
			_cube_tet_indices(CUBE_VERT_COUNT * 2),
			_cube_tet_indices(CUBE_VERT_COUNT * 3),
			_cube_tet_indices(CUBE_VERT_COUNT * 4),
			_cube_tet_indices(CUBE_VERT_COUNT * 5),
			_cube_tet_indices(CUBE_VERT_COUNT * 6),
			_cube_tet_indices(CUBE_VERT_COUNT * 7),
		};
		
		inline static glm::u8vec3 cube_verts[CUBE_VERT_COUNT] =
		{
			{ 0, 0, 0 },
			{ 1, 0, 0 },
			{ 0, 1, 0 },
			{ 1, 1, 0 },
			{ 0, 0, 1 },
			{ 1, 0, 1 },
			{ 0, 1, 1 },
			{ 1, 1, 1 }
		};
		inline static uint32_t cube_indices[CUBE_FULL_INDEX_COUNT] =
		{
			1, 2, 4, 7, 0, 1, 2, 4, 2, 4, 6, 7, 1, 2, 3, 7, 1, 4, 5, 7
		};

		inline static std::array<const glm::u8vec4, 8>& tuv_grass_top = *reinterpret_cast<std::array<const glm::u8vec4, 8>*>(getDataAddr((int)Data::BlockInfo::tuv_grass_top));
		inline static std::array<const glm::u8vec4, 8>& tuv_grass_side = *reinterpret_cast<std::array<const glm::u8vec4, 8>*>(getDataAddr((int)Data::BlockInfo::tuv_grass_side));
		inline static std::array<const glm::u8vec4, 64>& tuv_grass_full = *reinterpret_cast<std::array<const glm::u8vec4, 64>*>(getDataAddr((int)Data::BlockInfo::tuv_grass_full));
		inline static std::array<const glm::u8vec3, 4>& uv_grass_top = *reinterpret_cast<std::array<const glm::u8vec3, 4>*>(getDataAddr((int)Data::BlockInfo::uv_grass_top));
		inline static std::array<const glm::u8vec3, 4>& uv_grass_side = *reinterpret_cast<std::array<const glm::u8vec3, 4>*>(getDataAddr((int)Data::BlockInfo::uv_grass_side));
		inline static std::array<const glm::u8vec4, 8>& tuv_dirt = *reinterpret_cast<std::array<const glm::u8vec4, 8>*>(getDataAddr((int)Data::BlockInfo::tuv_dirt));
		inline static std::array<const glm::u8vec4, 64>& tuv_dirt_full = *reinterpret_cast<std::array<const glm::u8vec4, 64>*>(getDataAddr((int)Data::BlockInfo::tuv_dirt_full));
		inline static std::array<const glm::u8vec3, 4>& uv_dirt = *reinterpret_cast<std::array<const glm::u8vec3, 4>*>(getDataAddr((int)Data::BlockInfo::uv_dirt));
		inline static std::array<const glm::u8vec4, 8>& tuv_stone = *reinterpret_cast<std::array<const glm::u8vec4, 8>*>(getDataAddr((int)Data::BlockInfo::tuv_stone));
		inline static std::array<const glm::u8vec4, 64>& tuv_stone_full = *reinterpret_cast<std::array<const glm::u8vec4, 64>*>(getDataAddr((int)Data::BlockInfo::tuv_stone_full));
		inline static std::array<const glm::u8vec3, 4>& uv_stone = *reinterpret_cast<std::array<const glm::u8vec3, 4>*>(getDataAddr((int)Data::BlockInfo::uv_stone));
		inline static std::array<const glm::u8vec4, 8>& tuv_lava = *reinterpret_cast<std::array<const glm::u8vec4, 8>*>(getDataAddr((int)Data::BlockInfo::tuv_lava));
		inline static std::array<const glm::u8vec4, 64>& tuv_lava_full = *reinterpret_cast<std::array<const glm::u8vec4, 64>*>(getDataAddr((int)Data::BlockInfo::tuv_lava_full));
		inline static std::array<const glm::u8vec3, 4>& uv_lava = *reinterpret_cast<std::array<const glm::u8vec3, 4>*>(getDataAddr((int)Data::BlockInfo::uv_lava));
		inline static std::array<const glm::u8vec4, 8>& tuv_wood_top = *reinterpret_cast<std::array<const glm::u8vec4, 8>*>(getDataAddr((int)Data::BlockInfo::tuv_wood_top));
		inline static std::array<const glm::u8vec4, 8>& tuv_wood_side = *reinterpret_cast<std::array<const glm::u8vec4, 8>*>(getDataAddr((int)Data::BlockInfo::tuv_wood_side));
		inline static std::array<const glm::u8vec4, 64>& tuv_wood_full = *reinterpret_cast<std::array<const glm::u8vec4, 64>*>(getDataAddr((int)Data::BlockInfo::tuv_wood_full));
		inline static std::array<const glm::u8vec4, 8>& tuv_leaf = *reinterpret_cast<std::array<const glm::u8vec4, 8>*>(getDataAddr((int)Data::BlockInfo::tuv_leaf));
		inline static std::array<const glm::u8vec4, 64>& tuv_leaf_full = *reinterpret_cast<std::array<const glm::u8vec4, 64>*>(getDataAddr((int)Data::BlockInfo::tuv_leaf_full));
		inline static std::array<const glm::u8vec4, 8>& tuv_iron_ore = *reinterpret_cast<std::array<const glm::u8vec4, 8>*>(getDataAddr((int)Data::BlockInfo::tuv_iron_ore));
		inline static std::array<const glm::u8vec4, 64>& tuv_iron_ore_full = *reinterpret_cast<std::array<const glm::u8vec4, 64>*>(getDataAddr((int)Data::BlockInfo::tuv_iron_ore_full));
		inline static std::array<const glm::u8vec4, 8>& tuv_deadly_ore = *reinterpret_cast<std::array<const glm::u8vec4, 8>*>(getDataAddr((int)Data::BlockInfo::tuv_deadly_ore));
		inline static std::array<const glm::u8vec4, 64>& tuv_deadly_ore_full = *reinterpret_cast<std::array<const glm::u8vec4, 64>*>(getDataAddr((int)Data::BlockInfo::tuv_deadly_ore_full));
		inline static std::array<const glm::u8vec4, 8>& tuv_chest_top = *reinterpret_cast<std::array<const glm::u8vec4, 8>*>(getDataAddr((int)Data::BlockInfo::tuv_chest_top));
		inline static std::array<const glm::u8vec4, 8>& tuv_chest_side = *reinterpret_cast<std::array<const glm::u8vec4, 8>*>(getDataAddr((int)Data::BlockInfo::tuv_chest_side));
		inline static std::array<const glm::u8vec4, 8>& tuv_chest_bottom = *reinterpret_cast<std::array<const glm::u8vec4, 8>*>(getDataAddr((int)Data::BlockInfo::tuv_chest_bottom));
		inline static std::array<const glm::u8vec4, 64>& tuv_chest_full = *reinterpret_cast<std::array<const glm::u8vec4, 64>*>(getDataAddr((int)Data::BlockInfo::tuv_chest_full));
		inline static std::array<const glm::u8vec4, 8>& tuv_midnight_grass_top = *reinterpret_cast<std::array<const glm::u8vec4, 8>*>(getDataAddr((int)Data::BlockInfo::tuv_midnight_grass_top));
		inline static std::array<const glm::u8vec4, 8>& tuv_midnight_grass_side = *reinterpret_cast<std::array<const glm::u8vec4, 8>*>(getDataAddr((int)Data::BlockInfo::tuv_midnight_grass_side));
		inline static std::array<const glm::u8vec4, 64>& tuv_midnight_grass_full = *reinterpret_cast<std::array<const glm::u8vec4, 64>*>(getDataAddr((int)Data::BlockInfo::tuv_midnight_grass_full));
		inline static std::array<const glm::u8vec4, 8>& tuv_midnight_soil = *reinterpret_cast<std::array<const glm::u8vec4, 8>*>(getDataAddr((int)Data::BlockInfo::tuv_midnight_soil));
		inline static std::array<const glm::u8vec4, 64>& tuv_midnight_soil_full = *reinterpret_cast<std::array<const glm::u8vec4, 64>*>(getDataAddr((int)Data::BlockInfo::tuv_midnight_soil_full));
		inline static std::array<const glm::u8vec4, 8>& tuv_midnight_stone = *reinterpret_cast<std::array<const glm::u8vec4, 8>*>(getDataAddr((int)Data::BlockInfo::tuv_midnight_stone));
		inline static std::array<const glm::u8vec4, 64>& tuv_midnight_stone_full = *reinterpret_cast<std::array<const glm::u8vec4, 64>*>(getDataAddr((int)Data::BlockInfo::tuv_midnight_stone_full));
		inline static std::array<const glm::u8vec4, 8>& tuv_midnight_wood_top = *reinterpret_cast<std::array<const glm::u8vec4, 8>*>(getDataAddr((int)Data::BlockInfo::tuv_midnight_wood_top));
		inline static std::array<const glm::u8vec4, 8>& tuv_midnight_wood_side = *reinterpret_cast<std::array<const glm::u8vec4, 8>*>(getDataAddr((int)Data::BlockInfo::tuv_midnight_wood_side));
		inline static std::array<const glm::u8vec4, 64>& tuv_midnight_wood_full = *reinterpret_cast<std::array<const glm::u8vec4, 64>*>(getDataAddr((int)Data::BlockInfo::tuv_midnight_wood_full));
		inline static std::array<const glm::u8vec4, 8>& tuv_midnight_leaf = *reinterpret_cast<std::array<const glm::u8vec4, 8>*>(getDataAddr((int)Data::BlockInfo::tuv_midnight_leaf));
		inline static std::array<const glm::u8vec4, 64>& tuv_midnight_leaf_full = *reinterpret_cast<std::array<const glm::u8vec4, 64>*>(getDataAddr((int)Data::BlockInfo::tuv_midnight_leaf_full));
		inline static std::array<const glm::u8vec4, 8>& tuv_bush = *reinterpret_cast<std::array<const glm::u8vec4, 8>*>(getDataAddr((int)Data::BlockInfo::tuv_bush));
		inline static std::array<const glm::u8vec4, 48>& tuv_bush_full = *reinterpret_cast<std::array<const glm::u8vec4, 48>*>(getDataAddr((int)Data::BlockInfo::tuv_bush_full));
		inline static std::array<const glm::u8vec4, 8>& tuv_midnight_bush = *reinterpret_cast<std::array<const glm::u8vec4, 8>*>(getDataAddr((int)Data::BlockInfo::tuv_midnight_bush));
		inline static std::array<const glm::u8vec4, 48>& tuv_midnight_bush_full = *reinterpret_cast<std::array<const glm::u8vec4, 48>*>(getDataAddr((int)Data::BlockInfo::tuv_midnight_bush_full));
		inline static std::array<const glm::u8vec4, 8>& tuv_red_flower = *reinterpret_cast<std::array<const glm::u8vec4, 8>*>(getDataAddr((int)Data::BlockInfo::tuv_red_flower));
		inline static std::array<const glm::u8vec4, 48>& tuv_red_flower_full = *reinterpret_cast<std::array<const glm::u8vec4, 48>*>(getDataAddr((int)Data::BlockInfo::tuv_red_flower_full));
		inline static std::array<const glm::u8vec4, 8>& tuv_white_flower = *reinterpret_cast<std::array<const glm::u8vec4, 8>*>(getDataAddr((int)Data::BlockInfo::tuv_white_flower));
		inline static std::array<const glm::u8vec4, 48>& tuv_white_flower_full = *reinterpret_cast<std::array<const glm::u8vec4, 48>*>(getDataAddr((int)Data::BlockInfo::tuv_white_flower_full));
		inline static std::array<const glm::u8vec4, 8>& tuv_blue_flower = *reinterpret_cast<std::array<const glm::u8vec4, 8>*>(getDataAddr((int)Data::BlockInfo::tuv_blue_flower));
		inline static std::array<const glm::u8vec4, 48>& tuv_blue_flower_full = *reinterpret_cast<std::array<const glm::u8vec4, 48>*>(getDataAddr((int)Data::BlockInfo::tuv_blue_flower_full));
		inline static std::array<const glm::u8vec4, 8>& tuv_tall_grass = *reinterpret_cast<std::array<const glm::u8vec4, 8>*>(getDataAddr((int)Data::BlockInfo::tuv_tall_grass));
		inline static std::array<const glm::u8vec4, 48>& tuv_tall_grass_full = *reinterpret_cast<std::array<const glm::u8vec4, 48>*>(getDataAddr((int)Data::BlockInfo::tuv_tall_grass_full));
		inline static std::array<const glm::u8vec4, 8>& tuv_sand = *reinterpret_cast<std::array<const glm::u8vec4, 8>*>(getDataAddr((int)Data::BlockInfo::tuv_sand));
		inline static std::array<const glm::u8vec4, 64>& tuv_sand_full = *reinterpret_cast<std::array<const glm::u8vec4, 64>*>(getDataAddr((int)Data::BlockInfo::tuv_sand_full));
		inline static std::array<const glm::u8vec4, 8>& tuv_sandstone = *reinterpret_cast<std::array<const glm::u8vec4, 8>*>(getDataAddr((int)Data::BlockInfo::tuv_sandstone));
		inline static std::array<const glm::u8vec4, 64>& tuv_sandstone_full = *reinterpret_cast<std::array<const glm::u8vec4, 64>*>(getDataAddr((int)Data::BlockInfo::tuv_sandstone_full));
		inline static std::array<const glm::u8vec4, 8>& tuv_cactus = *reinterpret_cast<std::array<const glm::u8vec4, 8>*>(getDataAddr((int)Data::BlockInfo::tuv_cactus));
		inline static std::array<const glm::u8vec4, 48>& tuv_cactus_full = *reinterpret_cast<std::array<const glm::u8vec4, 48>*>(getDataAddr((int)Data::BlockInfo::tuv_cactus_full));
		inline static std::array<const glm::u8vec4, 8>& tuv_snow = *reinterpret_cast<std::array<const glm::u8vec4, 8>*>(getDataAddr((int)Data::BlockInfo::tuv_snow));
		inline static std::array<const glm::u8vec4, 64>& tuv_snow_full = *reinterpret_cast<std::array<const glm::u8vec4, 64>*>(getDataAddr((int)Data::BlockInfo::tuv_snow_full));
		inline static std::array<const glm::u8vec4, 8>& tuv_ice = *reinterpret_cast<std::array<const glm::u8vec4, 8>*>(getDataAddr((int)Data::BlockInfo::tuv_ice));
		inline static std::array<const glm::u8vec4, 64>& tuv_ice_full = *reinterpret_cast<std::array<const glm::u8vec4, 64>*>(getDataAddr((int)Data::BlockInfo::tuv_ice_full));
		inline static std::array<const glm::u8vec4, 8>& tuv_snowy_bush = *reinterpret_cast<std::array<const glm::u8vec4, 8>*>(getDataAddr((int)Data::BlockInfo::tuv_snowy_bush));
		inline static std::array<const glm::u8vec4, 48>& tuv_snowy_bush_full = *reinterpret_cast<std::array<const glm::u8vec4, 48>*>(getDataAddr((int)Data::BlockInfo::tuv_snowy_bush_full));
		inline static std::array<const glm::u8vec4, 8>& tuv_glass = *reinterpret_cast<std::array<const glm::u8vec4, 8>*>(getDataAddr((int)Data::BlockInfo::tuv_glass));
		inline static std::array<const glm::u8vec4, 64>& tuv_glass_full = *reinterpret_cast<std::array<const glm::u8vec4, 64>*>(getDataAddr((int)Data::BlockInfo::tuv_glass_full));
		inline static std::array<const glm::u8vec4, 8>& tuv_solenoid_ore = *reinterpret_cast<std::array<const glm::u8vec4, 8>*>(getDataAddr((int)Data::BlockInfo::tuv_solenoid_ore));
		inline static std::array<const glm::u8vec4, 64>& tuv_solenoid_ore_full = *reinterpret_cast<std::array<const glm::u8vec4, 64>*>(getDataAddr((int)Data::BlockInfo::tuv_solenoid_ore_full));
		inline static std::array<const glm::u8vec4, 8>& tuv_snowy_leaf_top = *reinterpret_cast<std::array<const glm::u8vec4, 8>*>(getDataAddr((int)Data::BlockInfo::tuv_snowy_leaf_top));
		inline static std::array<const glm::u8vec4, 8>& tuv_snowy_leaf_side = *reinterpret_cast<std::array<const glm::u8vec4, 8>*>(getDataAddr((int)Data::BlockInfo::tuv_snowy_leaf_side));
		inline static std::array<const glm::u8vec4, 8>& tuv_snowy_leaf_bottom = *reinterpret_cast<std::array<const glm::u8vec4, 8>*>(getDataAddr((int)Data::BlockInfo::tuv_snowy_leaf_bottom));
		inline static std::array<const glm::u8vec4, 64>& tuv_snowy_leaf_full = *reinterpret_cast<std::array<const glm::u8vec4, 64>*>(getDataAddr((int)Data::BlockInfo::tuv_snowy_leaf_full));
		inline static std::array<const glm::u8vec4, 8>& tuv_pumpkin_top = *reinterpret_cast<std::array<const glm::u8vec4, 8>*>(getDataAddr((int)Data::BlockInfo::tuv_pumpkin_top));
		inline static std::array<const glm::u8vec4, 8>& tuv_pumpkin_side = *reinterpret_cast<std::array<const glm::u8vec4, 8>*>(getDataAddr((int)Data::BlockInfo::tuv_pumpkin_side));
		inline static std::array<const glm::u8vec4, 64>& tuv_pumpkin_full = *reinterpret_cast<std::array<const glm::u8vec4, 64>*>(getDataAddr((int)Data::BlockInfo::tuv_pumpkin_full));
		inline static std::array<const glm::u8vec4, 8>& tuv_jack_o_lantern_side = *reinterpret_cast<std::array<const glm::u8vec4, 8>*>(getDataAddr((int)Data::BlockInfo::tuv_jack_o_lantern_side));
		inline static std::array<const glm::u8vec4, 64>& tuv_jack_o_lantern_full = *reinterpret_cast<std::array<const glm::u8vec4, 64>*>(getDataAddr((int)Data::BlockInfo::tuv_jack_o_lantern_full));
		inline static constexpr const int BLOCK_COUNT = 34;
		inline static constexpr const int VISIBLE_BLOCK_COUNT = 31;
		inline static std::array<const BlockInfo::BlockData, BLOCK_COUNT>& Blocks = *reinterpret_cast<std::array<const BlockInfo::BlockData, BLOCK_COUNT>*>(getDataAddr((int)Data::BlockInfo::Blocks));
		inline static std::array<const glm::u8vec4, 8>& cube_verts_x = *reinterpret_cast<std::array<const glm::u8vec4, 8>*>(getDataAddr((int)Data::BlockInfo::cube_verts_x));
		inline static std::array<const glm::u8vec4, 8>& cube_verts_y = *reinterpret_cast<std::array<const glm::u8vec4, 8>*>(getDataAddr((int)Data::BlockInfo::cube_verts_y));
		inline static std::array<const glm::u8vec4, 8>& cube_verts_z = *reinterpret_cast<std::array<const glm::u8vec4, 8>*>(getDataAddr((int)Data::BlockInfo::cube_verts_z));
		inline static std::array<const glm::u8vec4, 8>& cube_verts_w = *reinterpret_cast<std::array<const glm::u8vec4, 8>*>(getDataAddr((int)Data::BlockInfo::cube_verts_w));
		inline static std::array<const glm::u8vec4, 96>& plant_full_verts = *reinterpret_cast<std::array<const glm::u8vec4, 96>*>(getDataAddr((int)Data::BlockInfo::plant_full_verts));
		inline static std::array<const glm::vec4, 24>& plant_full_normals = *reinterpret_cast<std::array<const glm::vec4, 24>*>(getDataAddr((int)Data::BlockInfo::plant_full_normals));
		inline static std::array<const uint32_t, 240>& plant_full_indices = *reinterpret_cast<std::array<const uint32_t, 240>*>(getDataAddr((int)Data::BlockInfo::plant_full_indices));
		inline static std::array<const glm::u8vec3, 4>& square_verts_x = *reinterpret_cast<std::array<const glm::u8vec3, 4>*>(getDataAddr((int)Data::BlockInfo::square_verts_x));
		inline static std::array<const glm::u8vec3, 4>& square_verts_y = *reinterpret_cast<std::array<const glm::u8vec3, 4>*>(getDataAddr((int)Data::BlockInfo::square_verts_y));
		inline static std::array<const glm::u8vec3, 4>& square_verts_z = *reinterpret_cast<std::array<const glm::u8vec3, 4>*>(getDataAddr((int)Data::BlockInfo::square_verts_z));
		inline static std::array<const glm::u8vec3, 48>& cube_verts_triangles = *reinterpret_cast<std::array<const glm::u8vec3, 48>*>(getDataAddr((int)Data::BlockInfo::cube_verts_triangles));
		inline static std::array<const glm::u8vec3, 24>& cube_verts_lines = *reinterpret_cast<std::array<const glm::u8vec3, 24>*>(getDataAddr((int)Data::BlockInfo::cube_verts_lines));
		inline static std::unordered_map<stl::string, unsigned char>& blockIDs = *reinterpret_cast<std::unordered_map<stl::string, unsigned char>*>(getDataAddr((int)Data::BlockInfo::blockIDs));
		inline static std::unordered_map<unsigned char, stl::string>& blockNames = *reinterpret_cast<std::unordered_map<unsigned char, stl::string>*>(getDataAddr((int)Data::BlockInfo::blockNames));
		inline static std::array<BlockInfo::ItemMesh, VISIBLE_BLOCK_COUNT>& itemMeshes = *reinterpret_cast<std::array<BlockInfo::ItemMesh, VISIBLE_BLOCK_COUNT>*>(getDataAddr((int)Data::BlockInfo::itemMeshes));
		
		inline static uint8_t getBlockID(const stl::string& name)
		{
			return reinterpret_cast<uint8_t(__fastcall*)(const stl::string&)>(getFuncAddr((int)Func::BlockInfo::getBlockID))(name);
		}
		inline static void renderInit()
		{
			return reinterpret_cast<void(__fastcall*)()>(getFuncAddr((int)Func::BlockInfo::renderInit))();
		}
		inline static void renderItemMesh(uint8_t blockID)
		{
			return reinterpret_cast<void(__fastcall*)(uint8_t)>(getFuncAddr((int)Func::BlockInfo::renderItemMesh))(blockID);
		}
	};
}
