#pragma once

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

bool intersect(const AABB& a, const AABB& b)
{
    return !(a.m_MaxX < b.m_MinX
          || a.m_MinX > b.m_MaxX
          || a.m_MaxY < b.m_MinY
          || a.m_MinY > b.m_MaxY);
}
