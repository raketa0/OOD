#ifndef MODELDUCK_H
#define MODELDUCK_H

#include "Duck.h"
#include "Fly/FlyBehavior.h"
#include "Quack/QuakBehavior.h"
#include "Dance/DanceBehavior.h"

class ModelDuck : public Duck
{
public:
	ModelDuck()
		: Duck(FlyNoWay, DanceNoWay, QuackBehavior)
	{
	}

	void Display() const override
	{
		std::cout << "I'm model duck" << std::endl;
	}
};

#endif
