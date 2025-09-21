#pragma once
#include "../SimUDuck/lib/Duck/Fly/IFlyBehavior.h"

class MockFlyBehavior : public IFlyBehavior
{
public:
	void Fly() override
	{
		if (canFly)
		{
			flyCount++;
		}
	}

	bool CanFly() override
	{
		return canFly;
	}

	int GetCountFly() override
	{
		return flyCount;
	}

	void SetCanFly(bool isFlying)
	{
		canFly = isFlying;
	}

private:
	int flyCount = 0;
	bool canFly = false;
};



