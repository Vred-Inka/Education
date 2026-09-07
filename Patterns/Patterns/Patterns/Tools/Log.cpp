#include "Log.h"

#include <iostream>
#include <format>

void Log_old(const char* message)
{
    std::cout << message << "__func__" << __func__ << std::endl;
    std::cout << message << "__FUNCDNAME__" << __FUNCDNAME__ << std::endl;
    std::cout << message << "__FUNCTION__" << __FUNCTION__ << std::endl;
    std::cout << message << "__FUNCSIG__" << __FUNCSIG__ << std::endl;
    std::cout << message << "__FILE__" << __FILE__ << std::endl;
}

void Log(const char* message, std::source_location loc)
{
    std::cout << std::format("File: {}, Line: {}, Function: {} Message :  {} \n",
        loc.file_name(),
        loc.line(),
        loc.function_name(),
        message);
}