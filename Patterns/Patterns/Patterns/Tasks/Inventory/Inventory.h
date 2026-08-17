#pragma once

#include <string>
#include <vector>

struct Item
{
    Item(std::string name, int amount)
    : m_Name(name), m_Amount(amount)
    {
        
    }
    
    int m_ID{0};
    std::string m_Name;
    int m_Amount;
};

class Inventory
{
public:
    Inventory(){};

    void AddItem(std::string name, int amount);
    void RemoveItem(std::string name, int amount);
    Item* GetItem(std::string name);
    void ShowItems();

private:
    unsigned int id_generator = 0;

public:
    std::vector<Item> m_Items;
};
