#pragma once

#include "4dm.h"

namespace fdm 
{
	class ResourceManager 
	{
	public:
		inline static constexpr std::unordered_map<std::string,Tex2D *,std::hash<std::string >,std::equal_to<std::string >,std::allocator<std::pair<std::string const ,Tex2D *> > > textures = *reinterpret_cast<std::unordered_map<std::string,Tex2D *,std::hash<std::string >,std::equal_to<std::string >,std::allocator<std::pair<std::string const ,Tex2D *> > >*>((base + 0x2C40F0)); 

		inline static bool loadArrayTexture(const std::string& filename, int cols, int rows) 
		{
			return reinterpret_cast<bool (__fastcall*)(const std::string& filename, int cols, int rows)>(FUNC_RESOURCEMANAGER_LOADARRAYTEXTURE)(filename, cols, rows);
		}
	};
}
