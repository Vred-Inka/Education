#pragma once
#include <iostream>
#include <ostream>

namespace AABB
{
    struct AABB
    {
        AABB(int minX, int minY, int maxX, int maxY)
            :m_MinX(minX), m_MinY(minY), m_MaxX(maxX), m_MaxY(maxY)
        {
        
        }
   
        int m_MinX = 0;
        int m_MinY = 0;
        int m_MaxX = 0;
        int m_MaxY = 0;
    };

    bool Intersect(const AABB& a, const AABB& b)
    {
        return !(a.m_MaxX < b.m_MinX
              || a.m_MinX > b.m_MaxX
              || a.m_MaxY < b.m_MinY
              || a.m_MinY > b.m_MaxY);
    }

    void Print(const AABB& a, const char* name)
    {
        std::cout << name << " :"  << a.m_MinX << " " << a.m_MinY << a.m_MaxX << " " << a.m_MaxY << std::endl;
    }

    void PrintintResult(const char* name_a, const char* name_b, bool sign)
    {
        const char* text = sign ? " intersect " : " not intersect ";
        std::cout << name_a << text << name_b  << std::endl;
    }

    void Test()
    {        
        AABB a(2,1,6,5);
        Print(a, "A");
        AABB b(12,5,18,11);
        Print(a, "B");
        AABB c(5,4,9,8);
        Print(a, "C");
        PrintintResult("A", "B", Intersect(a, b));
        PrintintResult("A", "C", Intersect(a, c));
        PrintintResult("C", "B", Intersect(c, b)); 
    }
}//namespace AABB
