#pragma once

#include "GameActor.cpp"

class Command
{
public:
    virtual ~Command() {}
    virtual void Execute(GameActor& actor) = 0;
};

class EmptyCommand : public Command
{
public:
    virtual void Execute(GameActor& actor)
    {
        std::cout << "Empty command pressed" << endl;
    }
};

class JumpCommand : public Command
{
public:
    virtual void Execute(GameActor& actor) override
    { 
        actor.Jump();
    }
};

class FireCommand : public Command
{
public:
    virtual void Execute(GameActor& actor) override
    { 
        actor.FireGun();
    }
};

class MoveActorCommand : public Command
{
public:
    MoveActorCommand(GameActor* actor, int x, int y)
        : m_Actor(actor), m_X(x), m_Y(y)
    {
    }

    virtual void Execute(GameActor& actor) override
    {
        m_Actor->SetX(m_X);
        m_Actor->SetY(m_Y);
        cout << "New Actor location is " << m_X << ", " << m_Y << endl;
    }
    
private:
    GameActor* m_Actor {nullptr};
    int m_X {0};
    int m_Y {0};
};