#pragma once
#include "Inventory.h"

#include <iostream>
#include <mutex>
#include <ostream>
#include <windows.h>

bool Inventory::AddItem(std::string name, int amount)
{
    if (Item* item = GetItem(name))
    {
        item->m_Amount += amount;
        return true;
    }

    m_Items.push_back(Item(name, amount));
    return true;    
}

bool Inventory::RemoveItem(std::string name, int amount)
{
    if (Item* item = GetItem(name))
    {
        if (item->m_Amount > amount)
        {
            item->m_Amount -= amount;
        }
        else if (item->m_Amount < amount)
        {
            std::cout<< "Not enough amount of " <<name<<std::endl;
        }
        else
        {
            auto it = std::find_if(m_Items.begin(), m_Items.end(),
                [&](const Item& i)
                {
                    return name == i.m_Name;
                });

            m_Items.erase(it);
            return true;
        }
        
        return true;
    }
    
    return false;
}

Item* Inventory::GetItem(std::string name)
{
    for (Item& item : m_Items)
    {
        if (item.m_Name == name)
            return &item;
    }

    return nullptr;        
}

void Inventory::ShowItems()
{
    std::cout<< "[---Inventory--- "<<std::endl;
    for (Item& item : m_Items)
    {
        std::cout<<item.m_Name<< " : " << item.m_Amount << std::endl;
    }
    std::cout<< " ------------- ] "<<std::endl;
}
