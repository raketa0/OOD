#ifndef DUCK_H
#define DUCK_H

#include "Fly/FlyBehavior.h"
#include "Quack/QuakBehavior.h"
#include "Dance/DanceBehavior.h"
#include <cassert>
#include <iostream>
#include <memory>

using FlyFunction = std::function<void()>;
using DanceFunction = std::function<void()>;
using QuackFunction = std::function<void()>;

class Duck
{
public:
	Duck(FlyFunction flyBehavior,
		DanceFunction danceBehavior,
		QuackFunction quackBehavior)
		: m_quackBehavior(std::move(quackBehavior)),
		m_danceBehavior(std::move(danceBehavior)),
		m_flyBehavior(std::move(flyBehavior))
	{
		assert(m_quackBehavior);
		assert(m_danceBehavior);
		assert(m_flyBehavior);
	}

	void Quack() const
	{
		m_quackBehavior();
	}

	void Swim()
	{
		std::cout << "I'm swimming" << std::endl;
	}

	void Fly()
	{
		m_flyBehavior();
	}

	void Dance() const
	{
		m_danceBehavior();
	}

	void SetFlyBehavior(FlyFunction flyBehavior)
	{
		assert(flyBehavior);
		m_flyBehavior = std::move(flyBehavior);
	}

	void SetDanceBehavior(DanceFunction danceBehavior)
	{
		assert(danceBehavior);
		m_danceBehavior = std::move(danceBehavior);
	}

	virtual void Display() const = 0;
	virtual ~Duck() = default;

private:
	FlyFunction m_flyBehavior;
	QuackFunction m_quackBehavior;
	DanceFunction m_danceBehavior;


};

#endif
