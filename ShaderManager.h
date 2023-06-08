#pragma once
#ifndef SHADERMANAGER_H
#define SHADERMANAGER_H
#include "4dm.h"
namespace fdm
{
	class ShaderManager 
	{
	public:
		inline static std::map<std::string, Shader*> getShaders() // shaders
		{
			return (*reinterpret_cast<std::map<std::string, Shader*>*>((base + 0x1BFA80)));
		}
		inline static const Shader* get(const std::string& shaderName) 
		{
			return reinterpret_cast<const Shader*(__fastcall*)(const std::string&)>(
				FUNC_SHADERMANAGER_GET
				)(shaderName);
		}
		inline static bool loadFromShaderList(const std::string& jsonListPath)
		{
			return reinterpret_cast<const Shader * (__fastcall*)(const std::string&)>(
				FUNC_SHADERMANAGER_LOADFROMSHADERLIST
				)(jsonListPath);
		}
	};
}
#endif