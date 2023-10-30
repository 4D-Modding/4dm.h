#pragma once

#include "4dm.h"

namespace fdm 
{
	class ShaderManager 
	{
	public:
		inline static std::map<std::string,Shader *>* shaders = reinterpret_cast<std::map<std::string,Shader *>*>((base + 0x2C0728));

		inline static bool loadFromShaderList(const std::string& jsonListPath) 
		{
			return reinterpret_cast<bool (__fastcall*)(const std::string& jsonListPath)>(FUNC_SHADERMANAGER_LOADFROMSHADERLIST)(jsonListPath);
		}
	};
}
