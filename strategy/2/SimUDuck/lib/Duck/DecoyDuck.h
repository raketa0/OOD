#ifndef DECOYDUCK_H
#define DECOYDUCK_H

#include "Duck.h"
#include "Fly/FlyNoWay.h"
#include "Quack/MuteQuackBehavior.h"
#include "Dance/DanceNoWay.h"
#include <iostream>
#include <memory>

class DecoyDuck : public Duck
{
public:
	DecoyDuck()
		: Duck(std::make_unique<FlyNoWay>(), std::make_unique<DanceNoWay>(), std::make_unique<MuteQuackBehavior>())
	{
	}

	void Display() const override
	{
		std::cout << "I'm decoy duck" << std::endl;
	}
};

#endif
