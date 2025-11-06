#pragma once
#include "../canvas/ICanvasSFML.h"
#include <string>


class IShape
{
public:
	virtual void Draw() = 0;

	virtual double Perimeter();
	virtual double Area();
	virtual std::string GetType();
};

