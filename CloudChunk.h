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
			inline static constexpr const int TRUNCATED_OCTAHEDRON_VERT_COUNT = 25;
			inline static std::array<const glm::vec4, 25>& truncated_octahedron_verts = *reinterpret_cast<std::array<const glm::vec4, 25>*>(getDataAddr((int)Data::CloudChunk::CloudChunkMesh::truncated_octahedron_verts));
			inline static constexpr const int TRUNCATED_OCTAHEDRON_INDEX_COUNT = 176;
			inline static std::array<const uint32_t, 176>& truncated_octahedron_indices = *reinterpret_cast<std::array<const uint32_t, 176>*>(getDataAddr((int)Data::CloudChunk::CloudChunkMesh::truncated_octahedron_indices));

			std::vector<glm::vec4> verts; // 0x8
			std::vector<uint32_t> indices; // 0x20

			int attrCount(int buffIndex) const override
			{
				return reinterpret_cast<int(__thiscall*)(const CloudChunk::CloudChunkMesh * self, int)>(getFuncAddr((int)Func::CloudChunk::CloudChunkMesh::attrCount))(this, buffIndex);
			}
			int attrSize(int buffIndex, int attrIndex) const override
			{
				return reinterpret_cast<int(__thiscall*)(const CloudChunk::CloudChunkMesh * self, int, int)>(getFuncAddr((int)Func::CloudChunk::CloudChunkMesh::attrSize))(this, buffIndex, attrIndex);
			}
			int attrStride(int buffIndex, int attrIndex) const override
			{
				return reinterpret_cast<int(__thiscall*)(const CloudChunk::CloudChunkMesh * self, int, int)>(getFuncAddr((int)Func::CloudChunk::CloudChunkMesh::attrStride))(this, buffIndex, attrIndex);
			}
			uint32_t attrType(int buffIndex, int attrIndex) const override
			{
				return reinterpret_cast<uint32_t(__thiscall*)(const CloudChunk::CloudChunkMesh * self, int, int)>(getFuncAddr((int)Func::CloudChunk::CloudChunkMesh::attrType))(this, buffIndex, attrIndex);
			}
			int buffCount() const override
			{
				return reinterpret_cast<int(__thiscall*)(const CloudChunk::CloudChunkMesh * self)>(getFuncAddr((int)Func::CloudChunk::CloudChunkMesh::buffCount))(this);
			}
			const void* buffData(int buffIndex) const override
			{
				return reinterpret_cast<const void* (__thiscall*)(const CloudChunk::CloudChunkMesh * self, int)>(getFuncAddr((int)Func::CloudChunk::CloudChunkMesh::buffData))(this, buffIndex);
			}
			int buffSize(int buffIndex) const override
			{
				return reinterpret_cast<int(__thiscall*)(const CloudChunk::CloudChunkMesh * self, int)>(getFuncAddr((int)Func::CloudChunk::CloudChunkMesh::buffSize))(this, buffIndex);
			}
			const void* indexBuffData() const override
			{
				return reinterpret_cast<const void* (__thiscall*)(const CloudChunk::CloudChunkMesh * self)>(getFuncAddr((int)Func::CloudChunk::CloudChunkMesh::indexBuffData))(this);
			}
			int indexBuffSize() const override
			{
				return reinterpret_cast<int(__thiscall*)(const CloudChunk::CloudChunkMesh * self)>(getFuncAddr((int)Func::CloudChunk::CloudChunkMesh::indexBuffSize))(this);
			}
			void move(CloudChunk::CloudChunkMesh& other)
			{
				return reinterpret_cast<void(__thiscall*)(CloudChunk::CloudChunkMesh * self, CloudChunk::CloudChunkMesh&)>(getFuncAddr((int)Func::CloudChunk::CloudChunkMesh::move))(this, other);
			}
			int vertCount() const override
			{
				return reinterpret_cast<int(__thiscall*)(const CloudChunk::CloudChunkMesh * self)>(getFuncAddr((int)Func::CloudChunk::CloudChunkMesh::vertCount))(this);
			}
			~CloudChunkMesh() 
			{
				reinterpret_cast<void(__thiscall*)(CloudChunk::CloudChunkMesh* self)>(getFuncAddr((int)Func::CloudChunk::CloudChunkMesh::destr_CloudChunkMesh))(this);
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
		std::atomic<bool> meshReady; // 0x271
		std::atomic<bool> meshNew; // 0x272
		std::atomic<bool> inBounds; // 0x273

		void generateMesh() 
		{
			return reinterpret_cast<void (__thiscall*)(CloudChunk* self)>(getFuncAddr((int)Func::CloudChunk::generateMesh))(this);
		}
	};
}
