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
		unsigned int target = GL_TEXTURE_2D; // 0xC

		~Tex2D() 
		{
			reinterpret_cast<void(__thiscall*)(Tex2D* self)>(getFuncAddr((int)Func::Tex2D::destr_Tex2D))(this);
		}
		bool initFromTexID(uint32_t texID)
		{
			return reinterpret_cast<bool(__thiscall*)(Tex2D * self, uint32_t texID)>(getFuncAddr((int)Func::Tex2D::initFromTexID))(this, texID);
		}
		bool load(const stl::string& filename)
		{
			uint32_t OGL_texture = SOIL_load_OGL_texture(filename.c_str(), 0, 0, 0);
			return initFromTexID(OGL_texture);
		}
		bool loadRawImageData(const uint8_t* data, int texWidth, int texHeight, int channels)
		{
			return reinterpret_cast<bool (__thiscall*)(Tex2D* self, const uint8_t * data, int texWidth, int texHeight, int channels)>(getFuncAddr((int)Func::Tex2D::loadRawImageData))(this, data, texWidth, texHeight, channels);
		}
		bool loadArrayTexture(const uint8_t* data, GLint texWidth, int texHeight, int channels, int cols, int rows)
		{
			return reinterpret_cast<bool (__thiscall*)(Tex2D* self, const uint8_t * data, GLint texWidth, int texHeight, int channels, int cols, int rows)>(getFuncAddr((int)Func::Tex2D::loadArrayTexture))(this, data, texWidth, texHeight, channels, cols, rows);
		}

		uint32_t id() const { return ID; }
		void use(uint32_t texNum = 0) const { glActiveTexture(texNum + GL_TEXTURE0); glBindTexture(target, ID); }
	};
}
