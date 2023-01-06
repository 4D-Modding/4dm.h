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
		union 
		{
			const unsigned char SIZE;
			const unsigned char HEIGHT;
			struct 
			{
				unsigned char blocks[128][10][10][10];
				unsigned char lightingHeightMap[10][10][10];
				glm::i64vec3 pos;
				bool saved;
			};
			const unsigned char MESH_COUNT;
			const unsigned char MESH_HEIGHT;
		};

		PAD(7);

		Chunk::ChunkMesh meshData[8];
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
		std::map< glm::u8vec4, std::unique_ptr<Entity> > blockEntities;

	};
}
#endif