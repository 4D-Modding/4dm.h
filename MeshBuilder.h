#pragma once

#include "4dm.h"

namespace fdm
{
	class Mesh;
	class MeshBuilder : public Mesh
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

		void addBuff(const void* buffData, GLsizei buffSize)
		{
			buffers.push_back({ buffData, buffSize, {} });
		}
		void addAttr(GLenum type, GLint attrib_size, GLint stride)
		{
			buffers.back().attributes.push_back({ type, attrib_size, stride });
		}
		void addAttr(GLenum type, GLint attrib_size, GLint stride, int buffIndex)
		{
			buffers[buffIndex].attributes.push_back({ type, attrib_size, stride });
		}

		void setIndexBuff(const void* indexBuffData, int indexBuffSize)
		{
			this->indexBufferData = indexBuffData;
			this->indexBufferSize = indexBuffSize;
		}

		MeshBuilder(GLsizei vertexCount = 0)
			: vertexCount(vertexCount), indexBufferData(nullptr), indexBufferSize(0)
		{
		}

		MeshBuilder(GLsizei vertexCount, std::initializer_list<BuffInfo> buffers, const void* indexBuffData, GLsizei indexBuffSize)
			: vertexCount(vertexCount), buffers(buffers), indexBufferData(indexBuffData), indexBufferSize(indexBuffSize)
		{
		}

		~MeshBuilder() 
		{
			// do not free anything; that is not our responsibility - Mashpoe
		}

		void move(MeshBuilder& other)
		{
			buffers = std::move(other.buffers);

			vertexCount = other.vertexCount;
			other.vertexCount = 0;

			indexBufferData = other.indexBufferData;
			other.indexBufferData = nullptr;

			indexBufferSize = other.indexBufferSize;
			other.indexBufferSize = 0;
		}

		MeshBuilder(MeshBuilder&& other) noexcept
		{
			move(other);
		}
		MeshBuilder& operator=(MeshBuilder&& other) noexcept
		{
			clear();

			move(other);

			return *this;
		}

		int buffCount() const override
		{
			return buffers.size();
		}
		const void* buffData(int buffIndex) const override
		{
			return buffers[buffIndex].bufferData;
		}
		int buffSize(int buffIndex) const override
		{
			return buffers[buffIndex].bufferSize;
		}
		int attrCount(int buffIndex) const override
		{
			return buffers[buffIndex].attributes.size();
		}
		int vertCount() const override
		{
			return vertexCount;
		}
		const void* indexBuffData() const override
		{
			return indexBufferData;
		}
		int indexBuffSize() const override
		{
			return indexBufferSize;
		}
		unsigned int attrType(int buffIndex, int attrIndex) const override
		{
			return buffers[buffIndex].attributes[attrIndex].type;
		}
		int attrSize(int buffIndex, int attrIndex) const override
		{
			return buffers[buffIndex].attributes[attrIndex].size;
		}
		int attrStride(int buffIndex, int attrIndex) const override
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
