#pragma once

#include <iostream>
#include <windows.h>

#include "Command.cpp"
#include "GameActor.cpp"

enum Buttons
{
    BUTTON_X = VK_SPACE,
    BUTTON_Y = VK_MBUTTON,
    BUTTON_A = 0,
    BUTTON_B = 0,

    BUTTON_UP = VK_UP,
    BUTTON_DOWN = VK_DOWN
};

class InputHandler
{
public:
    InputHandler()
    {
        m_Button_X = new JumpCommand(); 
        m_Button_Y = new FireCommand();
        m_Button_A = new EmptyCommand();
        m_Button_B = new EmptyCommand();
    }

    ~InputHandler()
    {
        delete m_Button_X;
        delete m_Button_Y;
        delete m_Button_A;
        delete m_Button_B;
    } 

    Command* HandleInput()
    {     
        if (IsPressed(Buttons::BUTTON_X)) return m_Button_X;
        if (IsPressed(Buttons::BUTTON_Y)) return m_Button_Y;
        if (IsPressed(Buttons::BUTTON_A)) return m_Button_A;
        if (IsPressed(Buttons::BUTTON_B)) return m_Button_B;

        //move actions
        if (GameActor* actor = GetSelectedActor())
        {
            if (IsPressed(Buttons::BUTTON_UP))
            {
                int destY = actor->GetY() - 1;
                return new MoveActorCommand(actor, actor->GetX(), destY);
            }
            
            if (IsPressed(Buttons::BUTTON_DOWN))
            {
                int destY = actor->GetY() + 1;
                return new MoveActorCommand(actor, actor->GetX(), destY);
            }
        }
        

        return nullptr;
    }

private:
    Command* m_Button_X;
    Command* m_Button_Y;
    Command* m_Button_A;
    Command* m_Button_B;

    GameActor* m_SelectedActor;

public:
    void SetSelectedActor(GameActor* actor) { m_SelectedActor = actor; }
    GameActor* GetSelectedActor() const { return m_SelectedActor; }

private:
    bool IsPressed(Buttons button)
    {
        SHORT keyState = GetKeyState(button);
        if(keyState & 0x8000) 
        {
           // std::cout << button << " key is pressed." << std::endl;
            return true;
        }
        
        return false;
    } 
};