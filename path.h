#pragma once

#include "4dm.h"
namespace fdm
{
    class path
    {
    public:
        std::string pathName;
        path()
        {
            pathName = "";
        }
        path(const path& src)
        {
            pathName = src.pathName;
        }
        path(const char* src)
        {
            pathName = std::string(src);
        }
        const std::string string(void)
        {
            return pathName;
        }
        const char* c_str(void)
        {
            return pathName.c_str();
        }
    };
}