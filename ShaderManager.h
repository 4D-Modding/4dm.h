#pragma once

#include "4dm.h"
#include "Shader.h"

namespace fdm 
{
	class Shader;
	class ShaderManager 
	{
	public:
		inline static std::map<std::string,Shader *>* shaders = reinterpret_cast<std::map<std::string,Shader *>*>((base + 0x2C0728));

		inline static const Shader* get(const std::string& shaderName)
		{
			return reinterpret_cast<const Shader * (__fastcall*)(const std::string&)>(
				FUNC_SHADERMANAGER_GET
				)(shaderName);
		}

		inline static bool loadFromShaderList(const std::string& jsonListPath) 
		{
			return reinterpret_cast<bool (__fastcall*)(const std::string& jsonListPath)>(FUNC_SHADERMANAGER_LOADFROMSHADERLIST)(jsonListPath);
		}
	};
}
