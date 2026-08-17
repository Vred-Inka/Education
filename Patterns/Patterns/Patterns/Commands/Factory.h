#pragma once
#include <utility>

template<typename T, typename... Args>
T* Create(Args&&... args)
{
    return new T(std::forward<Args>(args)...);
}