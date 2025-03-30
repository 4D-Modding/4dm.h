#pragma once

#include <windows.h>
#include <string>
#include <vector>
#include "../stl/string.hpp"

enum class DLLType
{
	Mod,
	ExternalDLL,
};

struct DLL
{
	fdm::stl::string path;
	DLLType type;
};

enum class LoadOrder
{
	DontCare,
	Before,
	After
};

enum class DependencyType
{
	Hard,
	Optional,
	Incompatible
};

typedef fdm::stl::string ModID;
typedef fdm::stl::string ModVersion;

struct VersionReq
{
	fdm::stl::string op;
	ModVersion requiredVer;
};

struct ModDependency
{
	ModID id;
	LoadOrder order;
	DependencyType type;
	VersionReq versionReq;
};

struct Mod
{
	HMODULE module = nullptr; // set when the dll is loaded. by default set to nullptr
	ModID id = "";
	fdm::stl::string path = "";
	fdm::stl::string name = "";
	fdm::stl::string author = "Unknown";
	fdm::stl::string description = "";
	ModVersion version = "";
	fdm::stl::string gameVersion = "";
	fdm::stl::string modDLL = "";
	std::vector<fdm::stl::string> externalDLLs;
	std::vector<ModDependency> dependencies;
	bool completed = false;
};
