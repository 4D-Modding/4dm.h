#pragma once

#include "4dm.h"

namespace fdm 
{
	class Tex2D 
	{
	public:
		uint32_t ID; 
		int width; // 0x4
		int height; // 0x8
		uint32_t target; // 0xC

		~Tex2D() 
		{
			return reinterpret_cast<void(__thiscall*)(Tex2D* self)>(FUNC_TEX2D_DESTR_TEX2D_A)(this);
		}
		bool loadRawImageData(const unsigned char* data, int texWidth, int texHeight, int channels) 
		{
			return reinterpret_cast<bool (__thiscall*)(Tex2D* self, const unsigned char* data, int texWidth, int texHeight, int channels)>(FUNC_TEX2D_LOADRAWIMAGEDATA_A)(this, data, texWidth, texHeight, channels);
		}
		bool initFromTexID(uint32_t texID) 
		{
			return reinterpret_cast<bool (__thiscall*)(Tex2D* self, uint32_t texID)>(FUNC_TEX2D_INITFROMTEXID_A)(this, texID);
		}
		bool loadArrayTexture(const unsigned char* data, GLint texWidth, int texHeight, int channels, int cols, int rows) 
		{
			return reinterpret_cast<bool (__thiscall*)(Tex2D* self, const unsigned char* data, GLint texWidth, int texHeight, int channels, int cols, int rows)>(FUNC_TEX2D_LOADARRAYTEXTURE_A)(this, data, texWidth, texHeight, channels, cols, rows);
		}
	};
}
