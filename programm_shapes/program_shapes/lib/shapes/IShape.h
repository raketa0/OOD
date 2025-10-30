#pragma once
#include "../canvas/ICanvasSFML.h"


class IShape
{
public:
	virtual double Perimeter() = 0;
	virtual double Area() = 0;
	virtual void Draw() = 0;
	virtual std::string GetType() = 0;    
};

