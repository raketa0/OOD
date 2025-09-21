#pragma once
#include "IDanceBehavior.h"
#include <iostream>


class DanceAMinuet : public IDanceBehavior
{
public:
	void Dance() override
	{
		std::cout << "I dance the minuet!!" << std::endl;
	}
};
