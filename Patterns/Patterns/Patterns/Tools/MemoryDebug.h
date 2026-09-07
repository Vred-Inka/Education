#pragma once
#include <crtdbg.h>
#include "Log.h"

template<typename T>
class Array
{
public:
    Array()
    {
        _RPTF0(_CRT_WARN, "Array constructor called\n");
        /*
        Log("Array");
        std::cout << "__func__" << __func__ << std::endl;
        std::cout << "__FUNCDNAME__" << __FUNCDNAME__ << std::endl;
        std::cout << "__FUNCTION__" << __FUNCTION__ << std::endl;
        std::cout << "__FUNCSIG__" << __FUNCSIG__ << std::endl;
        */
    }

    Array(size_t size)
    {
        _RPTF1(_CRT_WARN, "Array constructor called with size:%lu\n", size);
        /*
        Log("Array");
        std::cout << "__func__" << __func__ << std::endl;
        std::cout << "__FUNCDNAME__" << __FUNCDNAME__ << std::endl;
        std::cout << "__FUNCTION__" << __FUNCTION__ << std::endl;
        std::cout << "__FUNCSIG__" << __FUNCSIG__ << std::endl;
        */
    }

    const T& operator[](size_t index) const;

private:    
    T* m_pBuffer{nullptr};
    size_t m_Length =0;
};

