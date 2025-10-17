#pragma once
#include "IShape.h"
#include "../canvas/ICanvas.h"

#include <cmath>
#include "../tools/ShapesStruct.h"


class TriangleAdapter : public IShape
{
public:
	TriangleAdapter(Triangle triangle);
	double Perimeter() override;
	double Area() override;
	void DrawShape(ICanvas& canvas) override;
	std::string GetType() override;

private:
	Triangle m_triangle;

	double Distation(Point& firstPoint, Point& secondPoint)
	{
		double dx = double(firstPoint.x - secondPoint.x);
		double dy = double(firstPoint.y - secondPoint.y);
		return std::sqrt(dx * dx + dy * dy);
	}
};
