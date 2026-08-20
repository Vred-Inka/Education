#include "InputHandler.h"
#include "Command.h"
#include "GameActor.h"

InputHandler::InputHandler()
{
    m_Button_X = new JumpCommand(); 
    m_Button_Y = new FireCommand();
    m_Button_A = new EmptyCommand();
    m_Button_B = new EmptyCommand();
}

InputHandler::~InputHandler()
{
    delete m_Button_X;
    delete m_Button_Y;
    delete m_Button_A;
    delete m_Button_B;
} 

std::unique_ptr<Command> InputHandler::HandleInput()
{     
    if (IsPressed(Buttons::BUTTON_X)) return std::make_unique<JumpCommand>();
    if (IsPressed(Buttons::BUTTON_Y)) return std::make_unique<FireCommand>();
    if (IsPressed(Buttons::BUTTON_A)) return std::make_unique<EmptyCommand>();
    if (IsPressed(Buttons::BUTTON_B)) return std::make_unique<EmptyCommand>();

    //move actions
    if (GameActor* actor = GetSelectedActor())
    {
        if (IsPressed(Buttons::BUTTON_UP))
        {
            int destY = actor->GetY() - 1;
            return std::make_unique<MoveActorCommand>(actor, actor->GetX(), destY);
        }
        
        if (IsPressed(Buttons::BUTTON_DOWN))
        {
            int destY = actor->GetY() + 1;
            return std::make_unique<MoveActorCommand>(actor, actor->GetX(), destY);
        }
    }
    

    return nullptr;
}

bool InputHandler::IsPressed(Buttons button)
{
    SHORT keyState = GetKeyState(button);
    if(keyState & 0x8000) 
    {
       // std::cout << button << " key is pressed." << std::endl;
        return true;
    }
    
    return false;
} 
