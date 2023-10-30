#pragma once

#include "4dm.h"

namespace fdm
{
	class Mesh 
	{
	public:
		virtual int buffCount() const { return NULL; }
		virtual const void* buffData(int buffIndex) const { return NULL; }
		virtual int buffSize(int buffIndex) const { return NULL; }
		virtual int attrCount(int buffIndex) const { return NULL; }
		virtual unsigned int attrType(int buffIndex, int attrIndex) const { return NULL; }
		virtual int attrSize(int buffIndex, int attrIndex) const { return NULL; }
		virtual int attrStride(int buffIndex, int attrIndex) const { return NULL; }
		virtual int vertCount() const { return NULL; }
		virtual const void* indexBuffData() const { return NULL; }
		virtual int indexBuffSize() const { return NULL; }
	};
}