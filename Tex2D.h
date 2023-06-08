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
			reinterpret_cast<void(__thiscall*)(Tex2D*)>(
				FUNC_TEX2D_DTEX2D
				)(this);
		}
		bool load(const std::string& filename) 
		{
			return reinterpret_cast<bool(__thiscall*)(Tex2D*, const std::string&)>(
				FUNC_TEX2D_LOAD
				)(this, filename);
		}
		bool loadRawImageData(const unsigned char* data, int texWidth, int texHeight, int channels)
		{
			return reinterpret_cast<bool(__thiscall*)(Tex2D*, const unsigned char*, int, int, int)>(
				FUNC_TEX2D_LOADRAWIMAGEDATA
				)(this, data, texWidth, texHeight, channels);
		}
		bool load(const std::string& filename) const
		{
			return reinterpret_cast<bool(__thiscall*)(const Tex2D*, const std::string&)>(
				FUNC_TEX2D_LOAD
				)(this, filename);
		}
		bool loadRawImageData(const unsigned char* data, int texWidth, int texHeight, int channels) const
		{
			return reinterpret_cast<bool(__thiscall*)(const Tex2D*, const unsigned char*, int, int, int)>(
				FUNC_TEX2D_LOADRAWIMAGEDATA
				)(this, data, texWidth, texHeight, channels);
		}
		bool initFromTexID(unsigned int texID)
		{
			return reinterpret_cast<bool(__thiscall*)(Tex2D*, unsigned int)>(
				FUNC_TEX2D_INITFROMTEXID
				)(this, texID);
		}
		bool initFromTexID(unsigned int texID) const
		{
			return reinterpret_cast<bool(__thiscall*)(const Tex2D*, unsigned int)>(
				FUNC_TEX2D_INITFROMTEXID
				)(this, texID);
		}
	};
}
#endif