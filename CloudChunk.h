#pragma once

#include "4dm.h"

namespace fdm 
{
	class CloudChunk 
	{
	public:
		class CloudChunkMesh : public Mesh 
		{
		public:
			inline static const int TRUNCATED_OCTAHEDRON_VERT_COUNT = 25; 
			inline static glm::vec4** truncated_octahedron_verts = reinterpret_cast<glm::vec4**>((base + 0x2ACCE0));
			inline static const int TRUNCATED_OCTAHEDRON_INDEX_COUNT = 176; 
			inline static uint32_t** truncated_octahedron_indices = reinterpret_cast<uint32_t**>((base + 0x2ACE70));
			std::vector<glm::vec4> verts; // 0x8
			std::vector<uint32_t> indices; // 0x20

			int indexBuffSize() const override
			{
				return reinterpret_cast<int (__thiscall*)(const CloudChunk::CloudChunkMesh* self)>(FUNC_CLOUDCHUNK_CLOUDCHUNKMESH_INDEXBUFFSIZE)(this);
			}
			int buffSize(int buffIndex) const override
			{
				return reinterpret_cast<int (__thiscall*)(const CloudChunk::CloudChunkMesh* self, int buffIndex)>(FUNC_CLOUDCHUNK_CLOUDCHUNKMESH_BUFFSIZE)(this, buffIndex);
			}
			int attrSize(int buffIndex, int attrIndex) const override
			{
				return reinterpret_cast<int (__thiscall*)(const CloudChunk::CloudChunkMesh* self, int buffIndex, int attrIndex)>(FUNC_CLOUDCHUNK_CLOUDCHUNKMESH_ATTRSIZE)(this, buffIndex, attrIndex);
			}
			int attrStride(int buffIndex, int attrIndex) const override
			{
				return reinterpret_cast<int (__thiscall*)(const CloudChunk::CloudChunkMesh* self, int buffIndex, int attrIndex)>(FUNC_CLOUDCHUNK_CLOUDCHUNKMESH_ATTRSTRIDE)(this, buffIndex, attrIndex);
			}
			void move(CloudChunk::CloudChunkMesh* other) 
			{
				return reinterpret_cast<void (__thiscall*)(CloudChunk::CloudChunkMesh* self, CloudChunk::CloudChunkMesh* other)>(FUNC_CLOUDCHUNK_CLOUDCHUNKMESH_MOVE)(this, other);
			}
			~CloudChunkMesh() 
			{
				reinterpret_cast<void(__thiscall*)(CloudChunk::CloudChunkMesh* self)>(FUNC_CLOUDCHUNK_CLOUDCHUNKMESH_DESTR_CLOUDCHUNKMESH)(this);
			}
		};
		inline static const uint32_t SIZE = 6; 
		inline static const uint32_t SCALE = 20; 
		unsigned char blocks[SIZE][SIZE][SIZE * 2];
		glm::i64vec3 pos; // 0x1B0
		std::mutex meshMutex; // 0x1C8
		CloudChunk::CloudChunkMesh activeMesh; // 0x218
		MeshRenderer meshRenderer; // 0x250
		bool meshUpdated; // 0x270
		std::atomic_bool meshReady; // 0x271
		std::atomic_bool meshNew; // 0x272
		std::atomic_bool inBounds; // 0x273

		void generateMesh() 
		{
			return reinterpret_cast<void (__thiscall*)(CloudChunk* self)>(FUNC_CLOUDCHUNK_GENERATEMESH)(this);
		}
	};
}
