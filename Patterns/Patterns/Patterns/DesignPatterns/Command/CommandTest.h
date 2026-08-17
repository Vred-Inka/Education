#pragma once

#include "Command.h"
#include "GameActor.h"
#include "InputHandler.h"

namespace CommandPattern
{  
    void Test()
    {
        // Command pattern
        GameActor actor;
        InputHandler inputHandler;
        inputHandler.SetSelectedActor(&actor);
            
        std::cout << " Press Any Key:" << std::endl;
        while(true) {
            if (Command* command = inputHandler.HandleInput())
            {
                command->Execute(actor);
            }
            Sleep(100);
        }
    }
    
} //namespace CommandPattern
