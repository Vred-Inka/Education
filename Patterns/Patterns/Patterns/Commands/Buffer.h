#pragma once
#include <iterator>

class Buffer
{
public:
    Buffer(size_t n)
        :m_Size(n), m_Data(new int[n])
    {}

    ~Buffer()
    {
       delete[] m_Data; 
    }

    Buffer(const Buffer& other)
        : m_Size(other.m_Size), m_Data(new int[m_Size])
    {
        std::copy(other.m_Data, other.m_Data + m_Size, m_Data);
    }

    Buffer& operator=(const Buffer& other)
    {
        if (this != &other)
        {
            delete[] m_Data;
            m_Size = other.m_Size;
            m_Data = new int[m_Size];
            std::copy(other.m_Data, other.m_Data + m_Size, m_Data);
        }

        return *this;
    }

    Buffer(Buffer&& other) noexcept
    : m_Size(other.m_Size), m_Data(other.m_Data)
    {
        other.m_Data = nullptr;
        other.m_Size = 0;
    }

    Buffer& operator=(Buffer&& other) noexcept
    {
        if(this != &other)
        {
            delete[] m_Data;
            m_Size = other.m_Size;
            m_Data = other.m_Data;
            other.m_Data = nullptr;
            other.m_Size = 0;
        }
    }
    
private:
    size_t m_Size = 0;
    int* m_Data;
};
