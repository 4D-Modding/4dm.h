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

		// yes im RE-ing 90% of functions there. even clear() function. lol
		~MeshBuilder() 
		{
			reinterpret_cast<void(__thiscall*)(MeshBuilder*)>(
				FUNC_MESHBUILDER_DMESHBUILDER
				)(this);
		}
		int buffCount() override
		{
			return buffers.size();
		}
		const void* buffData(int buffIndex) override
		{
			return buffers[buffIndex].bufferData;
		}
		int buffSize(int buffIndex) override
		{
			return buffers[buffIndex].bufferSize;
		}
		int attrCount(int buffIndex) override
		{
			return buffers[buffIndex].attributes.size();
		}
		int vertCount() override
		{
			return vertexCount;
		}
		const void* indexBuffData() override
		{
			return indexBufferData;
		}
		int indexBuffSize() override
		{
			return indexBufferSize;
		}
		unsigned int attrType(int buffIndex, int attrIndex) override
		{
			return buffers[buffIndex].attributes[attrIndex].type;
		}
		int attrSize(int buffIndex, int attrIndex) override
		{
			return buffers[buffIndex].attributes[attrIndex].size;
		}
		int attrStride(int buffIndex, int attrIndex) override
		{
			return buffers[buffIndex].attributes[attrIndex].stride;
		}
		void clear() 
		{
			vertexCount = 0;

			buffers.clear();

			indexBufferData = nullptr;
			indexBufferSize = 0;
		}
	};
}
#endif