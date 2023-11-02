#pragma once

#include "4dm.h"

namespace fdm 
{
	class ChunkLoader 
	{
	public:
		struct BiomeInfo 
		{
			enum TreeType
			{
				TREE_NONE = 0x0,
				TREE_REDLEAF = 0x1,
				TREE_MIDNIGHT = 0x2,
				TREE_SNOWY = 0x3,
			};

			std::string name; 
			float weight; // 0x20
			float hMultiplier; // 0x24
			float vMultiplier; // 0x28
			float temperature; // 0x2C
			float moisture; // 0x30
			glm::vec2 mapPos; // 0x34
			PAD(0x4);
			std::vector<uint8_t> layers; // 0x40
			std::vector<ChunkLoader::BiomeInfo::TreeType> trees; // 0x58
			int treeAbundance; // 0x70
			PAD(0x4);
			std::vector<uint8_t> decorations; // 0x78
			int decorationAbundance; // 0x90

			~BiomeInfo() 
			{
				reinterpret_cast<void(__thiscall*)(ChunkLoader::BiomeInfo* self)>(FUNC_CHUNKLOADER_BIOMEINFO_DESTR_BIOMEINFO)(this);
			}
			BiomeInfo(const ChunkLoader::BiomeInfo& __that) noexcept 
			{
				reinterpret_cast<void(__thiscall*)(ChunkLoader::BiomeInfo* self, const ChunkLoader::BiomeInfo & __that)>(FUNC_CHUNKLOADER_BIOMEINFO_BIOMEINFO)(this, __that);
			}
		};
		struct BiomeMapPixel 
		{
			uint32_t biome; 
			PAD(0x3);
			float hMultiplier; // 0x4
			float vMultiplier; // 0x8
		};
		path worldPath; 
		path chunksPath; // 0x20
		uint32_t seed; // 0x40
		glm::vec3 terrainOffsets; // 0x44
		glm::vec3 biomeOffsets; // 0x50
		glm::vec3 caveOffsets; // 0x5C
		bool flatWorld; // 0x68
		bool generateCaves; // 0x69
		PAD(0x2);
		float caveSize; // 0x6C
		float biomeSize; // 0x70
		float amplification; // 0x74
		bool shouldSpawnEntities; // 0x78
		bool shouldSaveUnmodifiedChunks; // 0x79
		PAD(0x2);
		int difficulty; // 0x7C
		std::vector<ChunkLoader::BiomeInfo> biomes; // 0x80
		std::unique_ptr<ChunkLoader::BiomeMapPixel*> biomeMap; // 0x98

		bool init(const path& worldPath, const path& biomeInfoPath) 
		{
			return reinterpret_cast<bool (__thiscall*)(ChunkLoader* self, const path& worldPath, const path& biomeInfoPath)>(FUNC_CHUNKLOADER_INIT)(this, worldPath, biomeInfoPath);
		}
		void loadChunk(Chunk* c, World* world) 
		{
			return reinterpret_cast<void (__thiscall*)(ChunkLoader* self, Chunk* c, World* world)>(FUNC_CHUNKLOADER_LOADCHUNK)(this, c, world);
		}
		bool loadBiomes(const path& biomeInfoPath) 
		{
			return reinterpret_cast<bool (__thiscall*)(ChunkLoader* self, const path& biomeInfoPath)>(FUNC_CHUNKLOADER_LOADBIOMES)(this, biomeInfoPath);
		}
		bool loadInfo(const path& worldInfoPath) 
		{
			return reinterpret_cast<bool (__thiscall*)(ChunkLoader* self, const path& worldInfoPath)>(FUNC_CHUNKLOADER_LOADINFO)(this, worldInfoPath);
		}
		void generateChunk(Chunk* chunk) 
		{
			return reinterpret_cast<void (__thiscall*)(ChunkLoader* self, Chunk* chunk)>(FUNC_CHUNKLOADER_GENERATECHUNK)(this, chunk);
		}
		ChunkLoader::BiomeMapPixel getBiome(int x, int z, int w) 
		{
			return reinterpret_cast<ChunkLoader::BiomeMapPixel (__thiscall*)(ChunkLoader* self, int x, int z, int w)>(FUNC_CHUNKLOADER_GETBIOME)(this, x, z, w);
		}
		void generateTree(unsigned char* blocks, const glm::i64vec3& chunkPos, bool dark) 
		{
			return reinterpret_cast<void (__thiscall*)(ChunkLoader* self, unsigned char* blocks, const glm::i64vec3& chunkPos, bool dark)>(FUNC_CHUNKLOADER_GENERATETREE)(this, blocks, chunkPos, dark);
		}
		void generateTreeBranch(unsigned char* blocks, const glm::i64vec3& chunkPos, glm::ivec4& startPos, int limit, bool dark) 
		{
			return reinterpret_cast<void (__thiscall*)(ChunkLoader* self, unsigned char* blocks, const glm::i64vec3& chunkPos, glm::ivec4& startPos, int limit, bool dark)>(FUNC_CHUNKLOADER_GENERATETREEBRANCH)(this, blocks, chunkPos, startPos, limit, dark);
		}
		void generateTaigaTree(unsigned char* blocks, const glm::i64vec3& chunkPos) 
		{
			return reinterpret_cast<void (__thiscall*)(ChunkLoader* self, unsigned char* blocks, const glm::i64vec3& chunkPos)>(FUNC_CHUNKLOADER_GENERATETAIGATREE)(this, blocks, chunkPos);
		}
		void createFlatWorldChests(Chunk* chunk, World* world) 
		{
			return reinterpret_cast<void (__thiscall*)(ChunkLoader* self, Chunk* chunk, World* world)>(FUNC_CHUNKLOADER_CREATEFLATWORLDCHESTS)(this, chunk, world);
		}
	};
}
