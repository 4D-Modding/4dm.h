#pragma once

#include "4dm.h"

namespace fdm 
{
	class ResourceManager 
	{
	public:
		inline static std::unordered_map<std::string,Tex2D *>* textures = reinterpret_cast<std::unordered_map<std::string,Tex2D *>*>((base + 0x2C40F0));

		// if you use modFolder assets (custom assets from yur mod's folder) then base path will become "mods/MOD_NAME/" instead of "assets/textures/"
		inline static const Tex2D* get(const std::string& filename, bool modFolder = false)
		{
			if (!modFolder)
			{
				return reinterpret_cast<const Tex2D * (__fastcall*)(const std::string&)>(
					FUNC_RESOURCEMANAGER_GET
					)(filename);
			}
			else
			{
				Tex2D* texture = new Tex2D();
				if (texture->load("mods/" + std::string(MOD_NAME) + "/" + filename))
					return texture;
				else
				{
					glDeleteTextures(1, &texture->ID);
					delete(texture);
				}
				return NULL;
			}
		}
		inline static bool loadArrayTexture(const std::string& filename, int cols, int rows) 
		{
			return reinterpret_cast<bool (__fastcall*)(const std::string& filename, int cols, int rows)>(FUNC_RESOURCEMANAGER_LOADARRAYTEXTURE)(filename, cols, rows);
		}
	};
}
