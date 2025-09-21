#pragma once
#include "IDanceBehavior.h"
#include <iostream>

class DanceTheWaltz : public IDanceBehavior
{
public:
	void Dance() override
	{
		std::cout << "I dance the waltz!!" << std::endl;
	}
};
