#pragma once

#include "4dm.h"

namespace fdm
{
    class path
    {
    public:
        std::wstring pathName;
        path()
        {
            pathName = L"";
        }
        path(const path& src)
        {
            pathName = src.pathName;
        }
        path(const std::string& src)
        {
            pathName = std::wstring(src.begin(), src.end());
        }
        path(const std::wstring& src)
        {
            pathName = src;
        }
        const std::wstring wstring(void)
        {
            return pathName;
        }
        const std::string string(void)
        {
            return std::string(pathName.begin(), pathName.end());
        }
        const char* c_str(void)
        {
            return string().c_str();
        }
        const wchar_t* c_wstr(void)
        {
            return pathName.c_str();
        }
    };
}