#pragma once
#include <iostream>
#include <ostream>

#include "../Tasks/Inventory/Inventory.h"

namespace  MemorySizeTest
{
    void Test()
    {
        int a = 0;
        int* b = new int(0);
        std::cout << "size of a " << sizeof(a) << std::endl;
        std::cout << "size of b " << sizeof(b) << std::endl;

        Inventory inventory;
        std::cout << "size of inventory " << sizeof(inventory) << std::endl;
        inventory.AddItem("Goold", 2000);
        std::cout << "size of inventory " << sizeof(inventory) << std::endl;
        std::cout << "size of inventory " << sizeof(inventory.m_Items) << std::endl;
        
    }
}
