#pragma once
#ifndef CLOUDCHUNK_H
#define CLOUDCHUNK_H
#include "4dm.h"
namespace fdm
{
	class MeshRenderer;
	struct Mesh;
	class CloudChunk
	{
	public:
		class CloudChunkMesh : Mesh
		{
		public:
			std::vector<glm::u8vec4> verts;
			std::vector<unsigned int> indices;

			int vertCount() override 
			{
				return reinterpret_cast<int(__thiscall*)(CloudChunkMesh*)>(
					FUNC_CLOUDCHUNK_CLOUDCHUNKMESH_VERTCOUNT
					)(this);
			}
			int indexBuffSize() override
			{
				return reinterpret_cast<int(__thiscall*)(CloudChunkMesh*)>(
					FUNC_CLOUDCHUNK_CLOUDCHUNKMESH_INDEXBUFFSIZE
					)(this);
			}
			int buffSize(int buffIndex) override
			{
				return reinterpret_cast<int(__thiscall*)(CloudChunkMesh*, int)>(
					FUNC_CLOUDCHUNK_CLOUDCHUNKMESH_BUFFSIZE
					)(this, buffIndex);
			}
			int attrStride(int buffIndex, int attrIndex) override
			{
				return reinterpret_cast<int(__thiscall*)(CloudChunkMesh*, int, int)>(
					FUNC_CLOUDCHUNK_CLOUDCHUNKMESH_ATTRSTRIDE
					)(this, buffIndex, attrIndex);
			}
		};
		inline static const unsigned char SIZE = 6; // ig? not sure
		inline static const unsigned char SCALE = 1; // idk???

		unsigned char blocks[SIZE * SCALE][SIZE * SCALE][SIZE * SCALE];

		std::mutex meshMutex;
		CloudChunk::CloudChunkMesh activeMesh;
		MeshRenderer meshRenderer;
		bool meshUpdated;
		std::atomic_bool meshReady;
		std::atomic_bool meshNew;
		std::atomic_bool inBounds;

		void generateMesh() 
		{
			reinterpret_cast<void(__thiscall*)(CloudChunk*)>(
				FUNC_CLOUDCHUNK_GENERATEMESH
				)(this);
		}
	};
}
#endif