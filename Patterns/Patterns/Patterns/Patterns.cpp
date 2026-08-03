#pragma once

#include <iostream>
#include <windows.h>

#include "Commands/GameActor.cpp"
#include "Commands/InputHandler.cpp"
#include "Tasks/AABB.h"
#include "Tasks/Inventory.h"
#include "Tasks/Test1.h"

using namespace std;

int main(int argc, char* argv[])
{
    TestInventory();
    Test1 t;
    t.RevertString();

    AABB a(2,1,6,5);
    AABB b(12,5,18,11);
    AABB c(5,4,9,8);
    bool areCollideAB = intersect(a, b);
    bool areCollideAC = intersect(a, c);
    bool areCollideCB = intersect(c, b);
    
    // Command pattern
    GameActor actor;
    InputHandler inputHandler;
    inputHandler.SetSelectedActor(&actor);

    cout << " Press Any Key:" << endl;
    while(true) {
        if (Command* command = inputHandler.HandleInput())
        {
            command->Execute(actor);
        }
        Sleep(100);
    }

    return 0;
}
 