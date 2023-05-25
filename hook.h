#pragma once
#ifndef HOOK_H
#define HOOK_H

#include <Windows.h>

// 4DModLoader-Core hooking stuff for multihooking yea

inline void Hook(LPVOID target, LPVOID detour, LPVOID* original)
{
	reinterpret_cast<void(__stdcall*)(LPVOID target, LPVOID detour, LPVOID * original)>(GetProcAddress(GetModuleHandleA("4DModLoader-Core.dll"), "Hook"))(target, detour, original);
}

// if target is NULL (0), enables every hook.
inline void EnableHook(LPVOID target)
{
	reinterpret_cast<void(__stdcall*)(LPVOID target)>(GetProcAddress(GetModuleHandleA("4DModLoader-Core.dll"), "EnableHook"))(target);
}

#endif // !HOOK_H