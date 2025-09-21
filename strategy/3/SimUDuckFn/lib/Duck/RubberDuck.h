#ifndef RUBBERDUCK_H
#define RUBBERDUCK_H

#include "Duck.h"
#include "Fly/FlyBehavior.h"
#include "Quack/QuakBehavior.h"
#include "Dance/DanceBehavior.h"

#include <iostream>

class RubberDuck : public Duck
{
public:
	RubberDuck()
		: Duck(FlyNoWay, DanceNoWay, SqueakBehavior)
	{
	}

	void Display() const override
	{
		std::cout << "I'm rubber duck" << std::endl;
	}

};

#endif
