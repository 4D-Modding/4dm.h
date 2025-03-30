#pragma once

#include "4dm.h"
#include "Shader.h"

namespace fdm 
{
	class Shader;
	class ShaderManager 
	{
	public:
		inline static std::map<stl::string, Shader*>& shaders = *reinterpret_cast<std::map<stl::string, Shader*>*>(getDataAddr((int)Data::ShaderManager::shaders));

		// will load relative to the mod's directory!! (will load a new shader only if the shaderName wasn't found in shaders tho so i recommend adding your mod's id as a prefix)
		inline static const Shader* load(const stl::string& shaderName, const stl::string& vertexPath, const stl::string& fragmentPath)
		{
			stl::string vertP = (std::filesystem::path(fdm::getModPath(fdm::modID)) / vertexPath).string();
			stl::string fragP = (std::filesystem::path(fdm::getModPath(fdm::modID)) / fragmentPath).string();
			if (shaders.contains(shaderName))
				return shaders.at(shaderName);

			Shader* shader = new Shader();
			if (!shader->load(vertP, fragP))
			{
				delete shader;
				shader = nullptr;
			}
			
			shaders[shaderName] = shader;
			return shader;
		}
		// will load relative to the mod's directory!! (will load a new shader only if the shaderName wasn't found in shaders tho so i recommend adding your mod's id as a prefix)
		inline static const Shader* load(const stl::string& shaderName, const stl::string& vertexPath, const stl::string& fragmentPath, const stl::string& geometryPath)
		{
			stl::string vertP = (std::filesystem::path(fdm::getModPath(fdm::modID)) / vertexPath).string();
			stl::string fragP = (std::filesystem::path(fdm::getModPath(fdm::modID)) / fragmentPath).string();
			stl::string geomP = (std::filesystem::path(fdm::getModPath(fdm::modID)) / geometryPath).string();
			if (shaders.contains(shaderName))
				return shaders.at(shaderName);

			Shader* shader = new Shader();
			if (!shader->load(vertP, geomP, fragP))
			{
				delete shader;
				shader = nullptr;
			}

			shaders[shaderName] = shader;
			return shader;
		}

		inline static const Shader* get(const stl::string& shaderName)
		{
			return reinterpret_cast<const Shader * (__fastcall*)(const stl::string&)>(
				getFuncAddr((int)Func::ShaderManager::get)
				)(shaderName);
		}

		inline static bool loadFromShaderList(const stl::string& jsonListPath) 
		{
			return reinterpret_cast<bool (__fastcall*)(const stl::string& jsonListPath)>(getFuncAddr((int)Func::ShaderManager::loadFromShaderList))(jsonListPath);
		}
	};
}
