#pragma once

#include <windows.h>
#include <cstdint>

namespace fdm
{
	inline constexpr uint64_t INVALID_HOOK_ID = -1;
	inline constexpr uint64_t ALL_HOOKS = 0;
}

// May return fdm::INVALID_HOOK_ID if the modloader-core version doesn't have the new hook methods (i.e. <= v2.2)
inline uint64_t __stdcall Hook(LPVOID target, LPVOID detour, LPVOID* original)
{
	static auto _Hook = reinterpret_cast<void(__stdcall*)(LPVOID target, LPVOID detour, LPVOID* original)>(
		GetProcAddress(GetModuleHandleA("4DModLoader-Core.dll"), "Hook"));
	static auto _HookB = reinterpret_cast<uint64_t(__stdcall*)(LPVOID target, LPVOID detour, LPVOID* original)>(
		GetProcAddress(GetModuleHandleA("4DModLoader-Core.dll"), "HookB"));
	if (_HookB)
	{
		return _HookB(target, detour, original);
	}
	else if (_Hook)
	{
		_Hook(target, detour, original);
	}
	return fdm::INVALID_HOOK_ID;
}

// May return fdm::INVALID_HOOK_ID if the modloader-core version doesn't have the new hook methods (i.e. <= v2.2)
template<typename FuncPtr>
inline uint64_t Hook(uint64_t target, FuncPtr detour, FuncPtr* original)
{
	static_assert(
		std::is_function<typename std::remove_pointer<FuncPtr>::type>::value,
		"Hook must be called with a function and a pointer to a function of identical signature"
	);
	return Hook(reinterpret_cast<LPVOID>(target), reinterpret_cast<LPVOID>(detour), reinterpret_cast<LPVOID*>(original));
}

// If target is NULL/nullptr (0), enables every hook.
// If id is fdm::ALL_HOOKS/NULL (0), enables every hook of the target. (modloader-core <= v2.2 enables all hooks of the target)
// INVALID_HOOK_ID is treated as ALL_HOOKS
inline void __stdcall EnableHook(LPVOID target = nullptr, uint64_t id = fdm::ALL_HOOKS)
{
	static auto _EnableHook = reinterpret_cast<void(__stdcall*)(LPVOID target)>(
		GetProcAddress(GetModuleHandleA("4DModLoader-Core.dll"), "EnableHook"));
	static auto _EnableHookB = reinterpret_cast<void(__stdcall*)(LPVOID target, uint64_t id)>(
		GetProcAddress(GetModuleHandleA("4DModLoader-Core.dll"), "EnableHookB"));

	if (id == fdm::INVALID_HOOK_ID)
		id = fdm::ALL_HOOKS;

	if (_EnableHookB)
	{
		_EnableHookB(target, id);
	}
	else if (_EnableHook)
	{
		_EnableHook(target);
	}
}
// If target is NULL/nullptr (0), enables every hook.
// If id is fdm::ALL_HOOKS/NULL (0), enables every hook of the target. (modloader-core <= v2.2 enables all hooks of the target)
// INVALID_HOOK_ID is treated as ALL_HOOKS
inline void EnableHook(uint64_t target = NULL, uint64_t id = fdm::ALL_HOOKS)
{
	EnableHook(reinterpret_cast<LPVOID>(target), id);
}

// Method not supported on modloader-core <= v2.2
// If target is NULL/nullptr (0), disables every hook.
// If id is fdm::ALL_HOOKS/NULL (0), disables every hook of the target.
// INVALID_HOOK_ID is treated as ALL_HOOKS
inline void __stdcall DisableHook(LPVOID target = nullptr, uint64_t id = fdm::ALL_HOOKS)
{
	static auto _DisableHook = reinterpret_cast<void(__stdcall*)(LPVOID target)>(
		GetProcAddress(GetModuleHandleA("4DModLoader-Core.dll"), "DisableHook"));
	static auto _DisableHookB = reinterpret_cast<void(__stdcall*)(LPVOID target, uint64_t id)>(
		GetProcAddress(GetModuleHandleA("4DModLoader-Core.dll"), "DisableHookB"));

	if (id == fdm::INVALID_HOOK_ID)
		id = fdm::ALL_HOOKS;

	if (_DisableHookB)
	{
		_DisableHookB(target, id);
	}
	else if (_DisableHook)
	{
		_DisableHook(target);
	}
}

// Method not supported on modloader-core <= v2.2
// If target is NULL/nullptr (0), disables every hook.
// If id is fdm::ALL_HOOKS/NULL (0), disables every hook of the target.
// INVALID_HOOK_ID is treated as ALL_HOOKS
inline void DisableHook(uint64_t target = NULL, uint64_t id = fdm::ALL_HOOKS)
{
	DisableHook(reinterpret_cast<LPVOID>(target), id);
}
