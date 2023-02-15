#pragma once
#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H
#include "4dm.h"
namespace fdm
{
	class ResourceManager
	{
	public:
		// if you use modFolder assets then base path will be "mods/fdm::MOD_NAME/" instead of "assets/textures/"
		static const Tex2D* get(const std::string& filename, bool modFolder = false) 
		{
			if (!modFolder) 
			{
				return reinterpret_cast<const Tex2D * (__fastcall*)(const std::string&)>(
					base + idaOffsetFix(0x85D20)
					)(filename);
			}
			else 
			{
				const Tex2D* texture{};
				if (texture->load("mods/" + std::string(fdm::modName) + "/" + filename))
					return texture;
				else 
				{
					glDeleteTextures(1, &texture->ID);
					delete(texture);
				}
				return NULL;
			}
		}
		static bool loadArrayTexture(const std::string& filename, int cols, int rows)
		{
			return reinterpret_cast<bool(__fastcall*)(const std::string&, int, int)>(
				base + idaOffsetFix(0x85EB0)
				)(filename, cols, rows);
		}
	};
}
#endif