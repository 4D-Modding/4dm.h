#pragma once
#ifndef TEX2D_H
#define TEX2D_H
#include "4dm.h"
namespace fdm
{
	class Tex2D
	{
	public:
		unsigned int ID;
		int width;
		int height;
		~Tex2D(void)
		{
			if (this->ID)
			{
				glDeleteTextures(1, &this->ID);
				this->ID = 0;
			}
		}
		bool load(const std::string& filename) 
		{
			return reinterpret_cast<bool(__thiscall*)(Tex2D*, const std::string&)>(
				base + idaOffsetFix(0x931D0)
				)(this, filename);
		}
		bool loadRawImageData(const unsigned char* data, int texWidth, int texHeight, int channels)
		{
			return reinterpret_cast<bool(__thiscall*)(Tex2D*, const unsigned char*, int, int, int)>(
				base + idaOffsetFix(0x932E0)
				)(this, data, texWidth, texHeight, channels);
		}
		bool loadArrayTexture(const unsigned char* data, int texWidth, int texHeight, int channels, int cols)
		{
			return reinterpret_cast<bool(__thiscall*)(Tex2D*, const unsigned char*, int, int, int, int)>(
				base + idaOffsetFix(0x93410)
				)(this, data, texWidth, texHeight, channels, cols);
		}
	};
}
#endif