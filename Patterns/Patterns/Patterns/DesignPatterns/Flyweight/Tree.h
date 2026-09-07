#pragma once
#include <vector>

class Texture {};
class Mesh {};
class Color {};

class ThreeModel
{
private:
    Mesh m_Mesh;
    Texture m_Bark;
    Texture m_Leaves;
};

class Tree
{
private:
	ThreeModel* m_Model;
    std::vector<int> m_Position;
    double m_Height;
    double m_Tickness;
    Color m_BarkTint;
    Color m_LeafTint;    
};


