#pragma once
#ifndef TEXRENDERER_H
#define TEXRENDERER_H
#include "4dm.h"
namespace fdm 
{
	class Tex2D;
	class Shader;
	class TexRenderer
	{
	public:
		const Tex2D* texture;
		const Shader* shader;
		unsigned int VAO;
		unsigned int buffers[5];
	};
}
#endif