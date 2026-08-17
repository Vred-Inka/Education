#pragma once

#include <windows.h>

#include "GameActor.h"

class Command;

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
    InputHandler();
    ~InputHandler();
    Command* HandleInput();

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
    bool IsPressed(Buttons button);
};