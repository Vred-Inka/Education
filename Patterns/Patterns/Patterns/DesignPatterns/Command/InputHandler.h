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
    std::unique_ptr<Command> HandleInput();

private:
    Command* m_Button_X{ nullptr };
    Command* m_Button_Y{ nullptr };
    Command* m_Button_A{ nullptr };
    Command* m_Button_B{ nullptr };

    GameActor* m_SelectedActor{ nullptr };

public:
    void SetSelectedActor(GameActor* actor) { m_SelectedActor = actor; }
    GameActor* GetSelectedActor() const { return m_SelectedActor; }

private:
    bool IsPressed(Buttons button);
};