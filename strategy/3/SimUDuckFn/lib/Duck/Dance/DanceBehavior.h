#pragma once
#include <functional>
#include <iostream>


auto DanceAMinuet = []()
   
	{
		std::cout << "I dance the minuet!!" << std::endl;
	};

auto DanceTheWaltz = []()
{
	{
		std::cout << "I dance the waltz!!" << std::endl;
	};
};

auto DanceNoWay = [](){};
