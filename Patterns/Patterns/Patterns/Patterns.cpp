#pragma once

#include <iostream>
#include <windows.h>

#include "Commands/GameActor.cpp"
#include "Commands/InputHandler.cpp"

using namespace std;

int main(int argc, char* argv[])
{
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
 