#pragma once
#ifndef HOOK_H
#define HOOK_H

#include <windows.h>

// 4DModLoader-Core hooking stuff for multihooking yea

inline void Hook(LPVOID target, LPVOID detour, LPVOID* original)
{
	reinterpret_cast<void(__stdcall*)(LPVOID target, LPVOID detour, LPVOID * original)>(GetProcAddress(GetModuleHandleA("4DModLoader-Core.dll"), "Hook"))(target, detour, original);
}
template<typename T> inline void Hook( unsigned long long target, T detour, T* original ) {
	static_assert( std::is_function<typename std::remove_pointer<T>::type>::value, "Hook must be called with a function and a pointer to a function of identical signature");
	Hook( reinterpret_cast<LPVOID>(target), reinterpret_cast<LPVOID>(detour), reinterpret_cast<LPVOID*>(original) );
}

// if target is NULL (0), enables every hook.
inline void EnableHook(LPVOID target)
{
	reinterpret_cast<void(__stdcall*)(LPVOID target)>(GetProcAddress(GetModuleHandleA("4DModLoader-Core.dll"), "EnableHook"))(target);
}

#endif // !HOOK_H
