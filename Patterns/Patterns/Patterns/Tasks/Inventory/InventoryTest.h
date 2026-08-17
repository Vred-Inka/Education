#pragma once

#include "Inventory.h"

namespace InventoryTest
{
    void Test()
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
};
