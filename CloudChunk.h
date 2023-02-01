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
					base + idaOffsetFix(0x2C250)
					)(this);
			}
			int indexBuffSize() override
			{
				return reinterpret_cast<int(__thiscall*)(CloudChunkMesh*)>(
					base + idaOffsetFix(0x2C270)
					)(this);
			}
			int buffSize(int buffIndex) override
			{
				return reinterpret_cast<int(__thiscall*)(CloudChunkMesh*, int)>(
					base + idaOffsetFix(0x2FD40)
					)(this, buffIndex);
			}
			int attrStride(int buffIndex, int attrIndex) override
			{
				return reinterpret_cast<int(__thiscall*)(CloudChunkMesh*, int, int)>(
					base + idaOffsetFix(0x2FD50)
					)(this, buffIndex, attrIndex);
			}
		};
		static const unsigned char SIZE;
		static const unsigned char SCALE;

		unsigned char blocks[6][6][6];

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
				base + idaOffsetFix(0x2FD60)
				)(this);
		}
	};
}
#endif