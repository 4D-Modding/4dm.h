#pragma once
#ifndef MESH_H
#define MESH_H
#include "4dm.h"
namespace fdm
{
	struct Mesh 
	{
	public:
		virtual int buffCount() {}
		virtual const void* buffData(int buffIndex) {}
		virtual int buffSize(int buffIndex) {}
		virtual int attrCount(int buffIndex) {}
		virtual unsigned int attrType(int buffIndex, int attrIndex) {}
		virtual int attrSize(int buffIndex, int attrIndex) {}
		virtual int attrStride(int buffIndex, int attrIndex) {}
		virtual int vertCount() {}
		virtual const void* indexBuffData() {}
		virtual int indexBuffSize() {}
	};
}
#endif