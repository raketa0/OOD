#ifndef LAB01_SIMUDUCK_IFLYBEHAVIOR_H
#define LAB01_SIMUDUCK_IFLYBEHAVIOR_H
#include <iostream>
#include <functional>

auto FlyNoWay = [](){};

auto FlyWithWings = []()
{
	int flyCount = 0;
	return [flyCount]() mutable 
	{
		flyCount++;
		std::cout << "I'm flying with wings!! Number of flights: " << flyCount << std::endl;
	};
};



#endif
