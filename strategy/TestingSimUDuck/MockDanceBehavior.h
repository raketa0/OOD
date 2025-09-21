#pragma once
#include "../SimUDuck/lib/Duck/Dance/IDanceBehavior.h"

struct MockDanceBehavior : public IDanceBehavior
{
	virtual ~MockDanceBehavior() {};
	bool isCalled = false;
	void Dance() override
	{
		isCalled = true;
	};
};

