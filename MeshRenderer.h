#pragma once
#ifndef MESHRENDERER_H
#define MESHRENDERER_H
#include "4dm.h"
namespace fdm
{
	class MeshRenderer
	{
	public:
		unsigned int VAO;
		PAD(1 * sizeof(long));
		unsigned int* VBOs;
		unsigned int indexVBO;
		int vertexCount;
		int bufferCount;
		unsigned int mode;
	};
}
#endif