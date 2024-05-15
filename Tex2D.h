#pragma once

#include "4dm.h"

namespace fdm 
{
	class Tex2D 
	{
	public:
		unsigned int ID = 0;
		int width = 0; // 0x4
		int height = 0; // 0x8
		unsigned int target = 0; // 0xC

		~Tex2D() 
		{
			reinterpret_cast<void(__thiscall*)(Tex2D* self)>(getFuncAddr((int)Func::Tex2D::destr_Tex2D))(this);
		}
		// decompiled from old version. since it got removed (probably optimized out) in newer versions
		bool load(const stl::string& filename)
		{
			if (this->ID)
			{
				glDeleteTextures(1, &this->ID);
				this->ID = 0;
			}
			unsigned int OGL_texture = SOIL_load_OGL_texture(filename.c_str(), 0, 0, 0);
			this->ID = OGL_texture;
			if (!OGL_texture)
				return false;
			glBindTexture(target, OGL_texture);
			glTexParameteri(target, GL_TEXTURE_BASE_LEVEL, 0);
			glTexParameteri(target, GL_TEXTURE_MAX_LEVEL, 0);
			glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(target, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			glGetTexLevelParameteriv(target, 0, GL_TEXTURE_WIDTH, &this->width);
			glGetTexLevelParameteriv(target, 0, GL_TEXTURE_HEIGHT, &this->height);
			glBindTexture(target, 0);
			return true;
		}
		bool loadRawImageData(const unsigned char* data, int texWidth, int texHeight, int channels) 
		{
			return reinterpret_cast<bool (__thiscall*)(Tex2D* self, const unsigned char* data, int texWidth, int texHeight, int channels)>(getFuncAddr((int)Func::Tex2D::loadRawImageData))(this, data, texWidth, texHeight, channels);
		}
		bool initFromTexID(uint32_t texID) 
		{
			return reinterpret_cast<bool (__thiscall*)(Tex2D* self, uint32_t texID)>(getFuncAddr((int)Func::Tex2D::initFromTexID))(this, texID);
		}
		bool loadArrayTexture(const unsigned char* data, GLint texWidth, int texHeight, int channels, int cols, int rows) 
		{
			return reinterpret_cast<bool (__thiscall*)(Tex2D* self, const unsigned char* data, GLint texWidth, int texHeight, int channels, int cols, int rows)>(getFuncAddr((int)Func::Tex2D::loadArrayTexture))(this, data, texWidth, texHeight, channels, cols, rows);
		}
	};
}
