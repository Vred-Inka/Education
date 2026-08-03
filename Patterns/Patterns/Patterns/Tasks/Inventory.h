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

    bool AddItem(std::string name, int amount);
    bool RemoveItem(std::string name, int amount);
    Item* GetItem(std::string name);
    void ShowItems();

private:
    unsigned int id_generator = 0;
    std::vector<Item> m_Items;
};

static void TestInventory()
{
    Inventory inventory;
    inventory.AddItem("Gold", 10);
    inventory.AddItem("Silver", 10);
    inventory.AddItem("FireGun", 1);
    inventory.ShowItems();
    inventory.RemoveItem("Gold", 5);
    inventory.RemoveItem("FireGun", 2);
    inventory.RemoveItem("Silver", 7);
   //inventory.RemoveItem("")
    inventory.ShowItems();
}
