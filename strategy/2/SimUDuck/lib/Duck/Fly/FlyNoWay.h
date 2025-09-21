#ifndef FLYNOWAY_H
#define FLYNOWAY_H

#include "IFlyBehavior.h"

class FlyNoWay : public IFlyBehavior
{
public:
	void Fly() override {}

	bool CanFly() override
	{
		return false;
	}

	int GetCountFly() override
	{
		return 0;
	}
};

#endif
