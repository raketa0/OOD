#pragma once

#include <string>

namespace shapes 
{


class IShapeStrategy
{
public:
	
	virtual ~IShapeStrategy(){};
	virtual void MoveShape(double dx, double dy) = 0;
	virtual void DrawShape() const = 0;
	virtual std::string ToString() const = 0;

};
}
