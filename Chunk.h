#pragma once
#ifndef CHUNK_H
#define CHUNK_H
#include "4dm.h"
namespace fdm
{
	class MeshRenderer;
	class Entity;
	
	class Chunk
	{
	public:
		class ChunkMesh
		{
			struct VertData
			{
				glm::u8vec4 vert;
				glm::u8vec4 tuv;
				glm::u8vec3 lighting;
			};
			PAD(2 * sizeof(long));
			std::vector<Chunk::ChunkMesh::VertData> verts;
			std::vector<unsigned int> indices;
			bool updateQueued;
		};
		static const unsigned char SIZE;
		static const unsigned char HEIGHT;
		static const unsigned char MESH_COUNT;
		static const unsigned char MESH_HEIGHT;

		unsigned char blocks[128][10][10][10];
		unsigned char lightingHeightMap[10][10][10];
		glm::i64vec3 pos;
		bool saved;

		PAD(7);

		ChunkMesh meshData[8];
		MeshRenderer meshRenderers[8];
		bool meshUpdatesQueued;

		PAD(7);

		std::mutex meshMutex;
		bool meshUpdated;
		std::atomic_bool meshReady;
		std::atomic_bool meshNew;
		std::atomic_bool inBounds;
		std::atomic_bool generatingMeshes;
		std::atomic_bool loaded;
		std::atomic_bool shouldUpdateCache;

		PAD(1);

		std::vector< std::unique_ptr<Entity> > entities;
		std::unordered_map<glm::u8vec4, std::unique_ptr<Entity>, std::hash<glm::u8vec4 >, std::equal_to<glm::u8vec4 >, std::allocator<std::pair<glm::u8vec4 const, std::unique_ptr<Entity> > > > blockEntities;

	};
}
#endif