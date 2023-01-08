#pragma once
#ifndef MESH_H
#define MESH_H
#include "4dm.h"
namespace fdm
{
	struct Mesh 
	{
	public:
		virtual int buffCount();
		virtual const void* buffData(int);
		virtual int buffSize(int);
		virtual int attrCount(int);
		virtual unsigned int attrType(int, int);
		virtual int attrSize(int, int);
		virtual int attrStride(int, int);
		virtual int vertCount();
		virtual const void* indexBuffData();
		virtual int indexBuffSize();
	};
}
#endif