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
			std::vector<glm::u8vec4> verts;
			std::vector<unsigned int> indices;
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
	};
}
#endif