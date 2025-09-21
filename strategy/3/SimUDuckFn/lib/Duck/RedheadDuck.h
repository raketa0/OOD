#ifndef REDHEADDUCK_H
#define REDHEADDUCK_H

#include "Duck.h"
#include "Fly/FlyBehavior.h"
#include "Quack/QuakBehavior.h"
#include "Dance/DanceBehavior.h"
#include <memory>

class RedheadDuck : public Duck
{
public:
	RedheadDuck()
		: Duck(FlyWithWings, DanceAMinuet, QuackBehavior)
	{
	}

	void Display() const override
	{
		std::cout << "I'm redhead duck" << std::endl;
	}
};

#endif
