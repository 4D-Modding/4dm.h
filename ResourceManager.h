#pragma once
#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H
#include "4dm.h"
namespace fdm
{
	class ResourceManager
	{
	public:
		inline static std::unordered_map<std::string, Tex2D*> getTextures() // textures
		{
			return *(reinterpret_cast<std::unordered_map<std::string, Tex2D*>*>((base + 0x1C2870)));
		}
		// if you use modFolder assets then base path will be "mods/MOD_NAME/" instead of "assets/textures/"
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
				const Tex2D* texture = new Tex2D();
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
	};
}
#endif
