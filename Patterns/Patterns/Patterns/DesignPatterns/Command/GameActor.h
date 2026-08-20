#pragma once

#include <iostream>

class GameActor
{
public:
    GameActor() {}
    ~GameActor() {}

    void Jump() { std::cout << "Jump pressed" << std::endl; }
    void FireGun() { std::cout << "FireGun pressed" << std::endl; }
    void MoveTo(int x, int y){m_X = x; m_Y = y;}

    int GetX(){return m_X;}
    int GetY(){return m_Y;}
    int SetX(int x){return m_X = x;}
    int SetY(int y){return m_Y = y;}

private:
    int m_X {0};
    int m_Y {0};
};