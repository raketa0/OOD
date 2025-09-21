#ifndef MALLARDDUCK_H
#define MALLARDDUCK_H

#include "Duck.h"
#include "Fly/FlyBehavior.h"
#include "Quack/QuakBehavior.h"
#include "Dance/DanceBehavior.h"

class MallardDuck : public Duck
{
public:
	MallardDuck()
		: Duck(FlyWithWings, DanceTheWaltz, QuackBehavior)
	{
	}

	void Display() const override
	{
		std::cout << "I'm mallard duck" << std::endl;
	}
};

#endif
