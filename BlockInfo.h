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
			glm::u8vec4* tuv_top; // 0x0
			glm::u8vec4* tuv_side; // 0x8
			glm::u8vec4* tuv_bottom; // 0x10
			glm::u8vec4* tuv_full_block; // 0x18
			glm::u8vec4* uv_top; // 0x20
			glm::u8vec4* uv_side; // 0x28
			glm::u8vec4* uv_bottom; // 0x30
			bool solid; // 0x38
			bool opaque; // 0x39
			bool plant; // 0x3A
			glm::u8vec3 glowColor; // 0x3B
			PAD(2);
		};
		inline static const BlockData* Blocks = reinterpret_cast<BlockData*>(base + 0x23F690);
		struct VertLighting 
		{
			uint8_t ambient; 
			uint8_t shadow; // 0x1
			glm::u8vec3 glow; // 0x2
		};
		struct ItemMesh 
		{
			MeshRenderer renderer; 

			~ItemMesh() 
			{
				reinterpret_cast<void(__thiscall*)(BlockInfo::ItemMesh* self)>(getFuncAddr((int)Func::BlockInfo_Nested::ItemMesh::destr_ItemMesh))(this);
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
		
		inline static const int BLOCK_COUNT = 34; 
		inline static const int VISIBLE_BLOCK_COUNT = 31;

		inline static glm::u8vec4* cube_verts_x = reinterpret_cast<glm::u8vec4*>((base + 0x3B570 + 0x200000));
		inline static glm::u8vec4* cube_verts_y = reinterpret_cast<glm::u8vec4*>((base + 0x3BD80 + 0x200000));
		inline static glm::u8vec4* cube_verts_z = reinterpret_cast<glm::u8vec4*>((base + 0x3A210 + 0x200000));
		inline static glm::u8vec4* cube_verts_w = reinterpret_cast<glm::u8vec4*>((base + 0x3AE98 + 0x200000));
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
		inline static glm::u8vec4* plant_full_verts = reinterpret_cast<glm::u8vec4*>((base + 0x3A790 + 0x200000));
		inline static glm::vec4* plant_full_normals = reinterpret_cast<glm::vec4*>((base + 0x53E50 + 0x270000));
		inline static uint32_t* plant_full_indices = reinterpret_cast<uint32_t*>((base + 0x3A260 + 0x200000));
		inline static glm::u8vec3* square_verts_x = reinterpret_cast<glm::u8vec3*>((base + 0x3AE88 + 0x200000));
		inline static glm::u8vec3* square_verts_y = reinterpret_cast<glm::u8vec3*>((base + 0x3B0C0 + 0x200000));
		inline static glm::u8vec3* square_verts_z = reinterpret_cast<glm::u8vec3*>((base + 0x3BC70 + 0x200000));
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
		inline static glm::u8vec3* cube_verts_triangles = reinterpret_cast<glm::u8vec3*>((base + 0x3B2E0 + 0x200000));
		inline static glm::u8vec3* cube_verts_lines = reinterpret_cast<glm::u8vec3*>((base + 0x3B1D0 + 0x200000));
		inline static std::unordered_map<std::string,uint8_t>* blockIDs = reinterpret_cast<std::unordered_map<std::string,uint8_t>*>((base + 0x53FD0 + 0x270000));
		inline static std::unordered_map<uint8_t,std::string>* blockNames = reinterpret_cast<std::unordered_map<uint8_t,std::string>*>((base + 0x54010 + 0x270000));
		inline static BlockInfo::ItemMesh* itemMeshes = reinterpret_cast<BlockInfo::ItemMesh*>((base + 0x4DB30 + 0x270000));

		inline static void renderItemMesh(uint8_t blockID) 
		{
			return reinterpret_cast<void (__fastcall*)(uint8_t blockID)>(getFuncAddr((int)Func::BlockInfo::renderItemMesh))(blockID);
		}
	};
}
