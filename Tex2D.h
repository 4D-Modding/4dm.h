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
			reinterpret_cast<void(__thiscall*)(Tex2D* self)>(FUNC_TEX2D_DESTR_TEX2D_A)(this);
		}
		// decompiled from old version. since it got removed (probably optimized out) in newer versions
		bool load(const std::string& filename)
		{
			if(this->ID)
			{
				glDeleteTextures(1, &this->ID);
				this->ID = 0;
			}
			unsigned int OGL_texture = SOIL_load_OGL_texture(filename.c_str(), 0, 0, 0);
			this->ID = OGL_texture;
			if (!OGL_texture)
				return false;
			glBindTexture(GL_TEXTURE_2D, OGL_texture);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_BASE_LEVEL, 0);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, 0);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &this->width);
			glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &this->height);
			glBindTexture(GL_TEXTURE_2D, 0);
			return true;
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
