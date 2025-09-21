#pragma once
#include <memory>
#include "../SimUDuck/lib/Duck/Fly/IFlyBehavior.h"
#include "../SimUDuck/lib/Duck/Quack/IQuakBehavior.h"


class MockDuck
{
public:
    MockDuck(std::unique_ptr<IFlyBehavior>&& flyBehavior,
        std::unique_ptr<IQuackBehavior>&& quackBehavior)
        : m_quackBehavior(std::move(quackBehavior)) 
    {
        SetFlyBehavior(std::move(flyBehavior));
    }

    void Quack() const 
    {
        m_quackBehavior->Quack();
    }

    void Fly() 
    {
        bool canFly = m_flyBehavior->CanFly();
        m_flyBehavior->Fly();

        int countFly = m_flyBehavior->GetCountFly();

        if (canFly && countFly % 2 == 0)
        {
            Quack();
        }
    }

    void SetFlyBehavior(std::unique_ptr<IFlyBehavior>&& flyBehavior) 
    {
        m_flyBehavior = std::move(flyBehavior);
    }

private:
    std::unique_ptr<IFlyBehavior> m_flyBehavior;
    std::unique_ptr<IQuackBehavior> m_quackBehavior;
};
