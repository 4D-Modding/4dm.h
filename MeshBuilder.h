#pragma once
#ifndef MESHBUILDER_H
#define MESHBUILDER_H
#include "4dm.h"
namespace fdm
{
	struct Mesh;
	class MeshBuilder : Mesh
	{
	public:
		struct AttrInfo
		{
			unsigned int type;
			int size;
			int stride;
		};
		struct BuffInfo
		{
			const void* bufferData;
			int bufferSize;
			PAD(4);
			std::vector<AttrInfo> attributes;
		};
		int vertexCount;
		PAD(4);
		std::vector<BuffInfo> buffers;
		const void* indexBufferData;
		int indexBufferSize;
	};
}
#endif