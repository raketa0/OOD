#pragma once
#include "../canvas/ICanvas.h"


class IShape
{
public:
	virtual double Perimeter() = 0;
	virtual double Area() = 0;
	virtual void DrawShape() = 0;
	virtual std::string GetType() = 0;    
};

