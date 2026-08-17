#pragma once

//#include "Algorithms/A_Search.cpp"

#include "Algorithms/AABB.h"

#include "DesignPatterns/Command/CommandTest.h"

#include "Tasks/Inventory/InventoryTest.h"
#include "Tasks/ReverseString.h"

#include "Tools/MemorySizeTest.h"


using namespace std;

int main(int argc, char* argv[])
{
    //Algorytms    
    //int i = aSearch::pathSearchAStar();
    AABB::Test();

    // Design Patterns
    //CommandPattern::Test();
    
    // Tasks
    InventoryTest::Test();
    ReverseString::Test();

    //Tools
    MemorySizeTest::Test();


   
    return 0;
}
 