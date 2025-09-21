#ifndef IQUAKBEHAVIOR_H
#define IQUAKBEHAVIOR_H

#include <iostream>
#include <functional>


auto MuteQuackBehavior = []() {};

auto QuackBehavior = []() {
		std::cout << "Quack Quack!!!" << std::endl;
};

auto SqueakBehavior = []() {
	std::cout << "Squeek!!!" << std::endl;
};


#endif
