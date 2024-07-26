#pragma once

#include "4dm.h"

namespace fdm::stl
{
    class path
    {
    public:
        stl::wstring pathName;
        path()
        {
            pathName = L"";
        }
        path(const path& src)
        {
            pathName = src.pathName;
        }
        path(const stl::string& src)
        {
            pathName = stl::wstring(src.begin(), src.end());
        }
        path(const stl::wstring& src)
        {
            pathName = src;
        }
        stl::wstring wstring(void) const
        {
            return pathName;
        }
        stl::string string(void) const
        {
            return stl::string(pathName.begin(), pathName.end());
        }
        const char* c_str(void) const
        {
            return string().c_str();
        }
        const wchar_t* c_wstr(void) const
        {
            return pathName.c_str();
        }
    };
}
