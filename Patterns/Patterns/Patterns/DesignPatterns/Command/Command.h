#pragma once

#include <windows.h>

#include "GameActor.h"
 
class Command
{
public:
    virtual ~Command() {}
    virtual void Execute() = 0;
    virtual void Undo() = 0;
};

class ActorCommand : public Command
{
private:
    GameActor* m_Actor {nullptr};

protected:
    void SetActor(GameActor* actor) { m_Actor = actor; }
    GameActor* GetActor() { return m_Actor; }
};

class EmptyCommand : public ActorCommand
{
public:
    void Execute() override
    {
        std::cout << "Empty command pressed" << std::endl;
    }

    void Undo() override
    {
        std::cout << "Empty command undo pressed" << std::endl;
	}
};

class JumpCommand : public ActorCommand
{    
public:
    void Execute() override
    { 
        if (GameActor* actor =  GetActor())
        {
            actor->Jump();
        }
    }

    void Undo() override
    {
        std::cout << "JumpCommand undo pressed" << std::endl;
    }
};

class FireCommand : public ActorCommand
{
public:
    void Execute() override
    {
        if (GameActor* actor =  GetActor())
        {
            actor->FireGun();
        }
    }

    void Undo() override
    {
        std::cout << "FireCommand undo pressed" << std::endl;
	}
};

class MoveActorCommand : public ActorCommand
{
public:
    MoveActorCommand(GameActor* actor, int x, int y)
        :  m_X(x), m_Y(y)
    {
        SetActor(actor);
    }

    void Execute() override
    {
        if (GameActor* actor =  GetActor())
        {
            m_BeforeX = actor->GetX();
            m_BeforeY = actor->GetY();
            actor->MoveTo(m_X, m_Y);
        }
        std::cout << "New Actor location is " << m_X << ", " << m_Y << std::endl;
    }

    void Undo() override
    {
        if (GameActor* actor =  GetActor())
        {
            actor->MoveTo(m_BeforeX, m_BeforeY);
        }
        std::cout << "New Actor location is " << m_X << ", " << m_Y << std::endl;
    }
    
private:
    int m_X {0};
    int m_Y {0};
    int m_BeforeX {0};
    int m_BeforeY {0};
};

