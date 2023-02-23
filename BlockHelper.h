#pragma once
#ifndef BLOCKHELPER_H
#define BLOCKHELPER_H
#include "4dm.h"

namespace fdm
{
	class MeshRenderer;
	class Tex2D;
	class Shader;
	class ResourceManager;
	class ShaderManager;
	class BlockItem;
	// That class doesnt exist in 4D Miner. It was only created for 4DModding so its easier to add custom blocks
	class BlockHelper
	{
	private:
		static bool initialized;
	public:
		static const int lastBlockID = 28;

		// same struct as 4D Miner BlockInfo::ItemMesh.
		struct ItemMesh
		{
		public:
			MeshRenderer renderer;
		};

		struct BlockTUV 
		{
		public:
			glm::u8vec4* top;
			glm::u8vec4* side;
			glm::u8vec4* bottom;
			glm::u8vec4* full_block;
			/*
			something like:
			{
				{ // top
					{0,0,0,0},
					{1,1,0,0}
				},
				{ // side
					{0,0,0,0},
					{1,1,0,0}
				},
				{ // bottom
					{0,0,0,0},
					{1,1,0,0}
				},
				{ // full_block
					{0,0,0,0},
					{1,1,0,0}
				}
			}
			*/
			BlockTUV(glm::u8vec4 top[], glm::u8vec4 side[], glm::u8vec4 bottom[], glm::u8vec4 full_block[])
			{
				this->top = top;
				this->side = side;
				this->bottom = bottom;
				this->full_block = full_block;
			}
			/*
			something like:
			{
				{ // top
					{0,0,0,0},
					{1,1,0,0}
				},
				{ // side
					{0,0,0,0},
					{1,1,0,0}
				},
				{ // bottom
					{0,0,0,0},
					{1,1,0,0}
				},
				{ // full_block
					{0,0,0,0},
					{1,1,0,0}
				}
			}
			*/
			BlockTUV(std::vector<glm::u8vec4> top, std::vector<glm::u8vec4> side, std::vector<glm::u8vec4> bottom, std::vector<glm::u8vec4> full_block) : BlockTUV(top.data(), side.data(), bottom.data(), full_block.data()) {}

			static BlockTUV generateSingleColumn(unsigned int column) 
			{
				glm::u8vec4 side[8] =
				{
					{0, 1, 0, column},
					{1, 1, 0, column},
					{0, 0, 0, column},
					{1, 0, 0, column},
					{0, 1, 1, column},
					{1, 1, 1, column},
					{0, 0, 1, column},
					{1, 0, 1, column}
				};
				glm::u8vec4 full_block[8 * 8];
				for (size_t i = 0; i < 8; i++) std::copy(side, side + (8 * (i + 1)), full_block + i * 8);
				return
				{
					side,
					side,
					side,
					full_block
				};
			}
		};
		struct BlockProperty 
		{
		public:
			bool solid;
			bool opaque;
			glm::u8vec3 glowColor;
			bool plant;
			BlockProperty(bool solid = true, bool opaque = true, glm::u8vec3 glowColor = glm::u8vec3{0, 0, 0}, bool plant = false)
			{
				this->solid = solid;
				this->opaque = opaque;
				this->glowColor = glowColor;
				this->plant = plant;
			}
		};

		struct Block 
		{
		public:
			ItemMesh itemMesh;
			BlockProperty blockProperty;
			BlockTUV blockTUV;
		};

		static std::vector<Block> blocks;
		static const Tex2D* tilesTex;
		static const Shader* blockShader;

		// initializes render hooks for custom blocks to work properly
		static void init()
		{
			if (!initialized) 
			{
				// initializing hooks
				Hook(reinterpret_cast<void*>(base + idaOffsetFix(0x16690)), reinterpret_cast<void*>(&BlockItem_renderEntity_H), reinterpret_cast<void**>(&BlockItem_renderEntity_O));
				EnableHook(reinterpret_cast<void*>(base + idaOffsetFix(0x16690)));

				// loading stuff
				tilesTex = ResourceManager::get("tiles.png", true);
				blockShader = ShaderManager::get("blockShader");

				initialized = true;
			}
		}
		// blockID starts from 0!! This function will automatically add 29 so its not messing up other 4D Miner blocks!!
		static void addBlockItem(const std::string& blockName, unsigned char blockID = 0)
		{
			nlohmann::json attrs;
			if (blockID >= 255 - lastBlockID - 1)
				blockID = 255 - lastBlockID - 1;
			attrs["id"] = blockID + lastBlockID + 1;
			BlockItem::addItemType(blockName, attrs);
		}

	private:
		static void(__thiscall* BlockItem_renderEntity_O)(BlockItem* self, const m4::Mat5& MV, bool inHand);
		static void __fastcall BlockItem_renderEntity_H(BlockItem* self, const m4::Mat5& MV, bool inHand)
		{
			if (self->blockID <= lastBlockID) 
			{
				BlockItem_renderEntity_O(self, MV, inHand);
				return;
			}

			// custom block render
			glBindTexture(GL_TEXTURE_2D, tilesTex->ID);
			blockShader->use();
			glUniform1fv(glGetUniformLocation(blockShader->id(), "MV"), 5 * 5, &MV.value[0][0]);
			Block block = blocks[self->blockID - 1];
			
			glBindVertexArray(block.itemMesh.renderer.VAO); 
			if (block.itemMesh.renderer.indexVBO) 
			{
				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, block.itemMesh.renderer.indexVBO);
				glDrawElements(block.itemMesh.renderer.mode, block.itemMesh.renderer.vertexCount, GL_UNSIGNED_INT, NULL);
				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
			}
			else 
			{
				glDrawArrays(block.itemMesh.renderer.mode, 0, block.itemMesh.renderer.vertexCount);
			}
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindVertexArray(0);
		}
	};
	const Tex2D* BlockHelper::tilesTex{};
	const Shader* BlockHelper::blockShader{};
	bool BlockHelper::initialized = false;
	std::vector<BlockHelper::Block> BlockHelper::blocks{};
	void (__thiscall* BlockHelper::BlockItem_renderEntity_O)(BlockItem* self, const m4::Mat5& MV, bool inHand) = NULL;
}
#endif