#pragma once
#ifndef MESH_H
#define MESH_H
#include "4dm.h"
namespace fdm
{
	struct Mesh 
	{
	public:
		virtual int buffCount() = NULL;
		virtual const void* buffData(int) = NULL;
		virtual int buffSize(int) = NULL;
		virtual int attrCount(int) = NULL;
		virtual unsigned int attrType(int, int) = NULL;
		virtual int attrSize(int, int) = NULL;
		virtual int attrStride(int, int) = NULL;
		virtual int vertCount() = NULL;
		virtual const void* indexBuffData() = NULL;
		virtual int indexBuffSize() = NULL;
	};
}
#endif