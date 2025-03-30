#pragma once

#include "4dm.h"

namespace fdm 
{
	class ChunkLoader 
	{
	public:
		struct BiomeInfo 
		{
			enum TreeType : int
			{
				TREE_NONE = 0,
				TREE_REDLEAF = 1,
				TREE_MIDNIGHT = 2,
				TREE_SNOWY = 3,
			};

			stl::string name; 
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
				reinterpret_cast<void(__thiscall*)(ChunkLoader::BiomeInfo* self)>(getFuncAddr((int)Func::ChunkLoader::BiomeInfo::destr_BiomeInfo))(this);
			}
			BiomeInfo(ChunkLoader::BiomeInfo&& __that)
			{
				reinterpret_cast<void(__thiscall*)(ChunkLoader::BiomeInfo* self, ChunkLoader::BiomeInfo& __that)>(getFuncAddr((int)Func::ChunkLoader::BiomeInfo::BiomeInfo))(this, __that);
			}
		};
		struct BiomeMapPixel 
		{
			uint8_t biome;
			PAD(0x3);
			float hMultiplier; // 0x4
			float vMultiplier; // 0x8
		};
		stl::path worldPath;
		stl::path chunksPath; // 0x20
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

		bool init(const stl::path& worldPath, const stl::path& biomeInfoPath)
		{
			return reinterpret_cast<bool (__thiscall*)(ChunkLoader* self, const stl::path& worldPath, const stl::path& biomeInfoPath)>(getFuncAddr((int)Func::ChunkLoader::init))(this, worldPath, biomeInfoPath);
		}
		void loadChunk(Chunk* c, World* world) 
		{
			return reinterpret_cast<void (__thiscall*)(ChunkLoader* self, Chunk* c, World* world)>(getFuncAddr((int)Func::ChunkLoader::loadChunk))(this, c, world);
		}
		bool loadBiomes(const stl::path& biomeInfoPath)
		{
			return reinterpret_cast<bool (__thiscall*)(ChunkLoader* self, const stl::path& biomeInfoPath)>(getFuncAddr((int)Func::ChunkLoader::loadBiomes))(this, biomeInfoPath);
		}
		bool loadInfo(const stl::path& worldInfoPath)
		{
			return reinterpret_cast<bool (__thiscall*)(ChunkLoader* self, const stl::path& worldInfoPath)>(getFuncAddr((int)Func::ChunkLoader::loadInfo))(this, worldInfoPath);
		}
		void generateChunk(Chunk* chunk) 
		{
			return reinterpret_cast<void (__thiscall*)(ChunkLoader* self, Chunk* chunk)>(getFuncAddr((int)Func::ChunkLoader::generateChunk))(this, chunk);
		}
		ChunkLoader::BiomeMapPixel getBiome(int x, int z, int w) 
		{
			ChunkLoader::BiomeMapPixel result;
			return reinterpret_cast<ChunkLoader::BiomeMapPixel& (__thiscall*)(ChunkLoader* self, ChunkLoader::BiomeMapPixel*, int x, int z, int w)>(getFuncAddr((int)Func::ChunkLoader::getBiome))(this, &result, x, z, w);
		}
		void generateTree(uint8_t* blocks, const glm::i64vec3& chunkPos, bool dark) 
		{
			return reinterpret_cast<void (__thiscall*)(ChunkLoader* self, uint8_t* blocks, const glm::i64vec3& chunkPos, bool dark)>(getFuncAddr((int)Func::ChunkLoader::generateTree))(this, blocks, chunkPos, dark);
		}
		void generateTreeBranch(uint8_t* blocks, const glm::i64vec3& chunkPos, glm::ivec4& startPos, int limit, bool dark) 
		{
			return reinterpret_cast<void (__thiscall*)(ChunkLoader* self, uint8_t* blocks, const glm::i64vec3& chunkPos, glm::ivec4& startPos, int limit, bool dark)>(getFuncAddr((int)Func::ChunkLoader::generateTreeBranch))(this, blocks, chunkPos, startPos, limit, dark);
		}
		void generateTaigaTree(uint8_t* blocks, const glm::i64vec3& chunkPos) 
		{
			return reinterpret_cast<void (__thiscall*)(ChunkLoader* self, uint8_t* blocks, const glm::i64vec3& chunkPos)>(getFuncAddr((int)Func::ChunkLoader::generateTaigaTree))(this, blocks, chunkPos);
		}
		void createFlatWorldChests(Chunk* chunk, World* world) 
		{
			return reinterpret_cast<void (__thiscall*)(ChunkLoader* self, Chunk* chunk, World* world)>(getFuncAddr((int)Func::ChunkLoader::createFlatWorldChests))(this, chunk, world);
		}
	};
}
