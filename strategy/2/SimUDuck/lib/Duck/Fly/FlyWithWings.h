#ifndef FLYWITHWINGS_H
#define FLYWITHWINGS_H

#include "IFlyBehavior.h"
#include <iostream>

class FlyWithWings : public IFlyBehavior
{
public:
	void Fly() override
	{
		flyCount++;
		std::cout << "I'm flying with wings!! Number of flights: " << flyCount << std::endl;
	}

	bool CanFly() override
	{
		return true;
	}

	int GetCountFly() override
	{
		return flyCount;
	}

private:
	int flyCount = 0;
};

#endif
