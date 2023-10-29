#pragma once

#include "4dm.h"

namespace fdm
{
	class Mesh 
	{
	public:
		virtual int buffCount() const = NULL;
		virtual const void* buffData(int buffIndex) const = NULL;
		virtual int buffSize(int buffIndex) const = NULL;
		virtual int attrCount(int buffIndex) const = NULL;
		virtual unsigned int attrType(int buffIndex, int attrIndex) const = NULL;
		virtual int attrSize(int buffIndex, int attrIndex) const = NULL;
		virtual int attrStride(int buffIndex, int attrIndex) const = NULL;
		virtual int vertCount() const = NULL;
		virtual const void* indexBuffData() const = NULL;
		virtual int indexBuffSize() const = NULL;
	};
}