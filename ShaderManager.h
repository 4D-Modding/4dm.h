#pragma once
#ifndef SHADERMANAGER_H
#define SHADERMANAGER_H
#include "4dm.h"
namespace fdm
{
	class ShaderManager 
	{
	public:
		static std::map<std::string, Shader*> shaders() 
		{
			return (*reinterpret_cast<std::map<std::string, Shader*>*>((base + idaOffsetFix(0x1401C0A28))));
		}
		static const Shader* get(const std::string& shaderName) 
		{
			return reinterpret_cast<const Shader*(__fastcall*)(const std::string&)>(
				base + idaOffsetFix(0x8A8E0)
				)(shaderName);
		}
		static bool loadFromShaderList(const std::string& jsonListPath)
		{
			return reinterpret_cast<const Shader * (__fastcall*)(const std::string&)>(
				base + idaOffsetFix(0x8A950)
				)(jsonListPath);
		}
	};
}
#endif