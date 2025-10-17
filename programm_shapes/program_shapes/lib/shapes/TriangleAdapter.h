#pragma once
#include "IShape.h"
#include "../canvas/ICanvas.h"

#include <cmath>

class TriangleAdapter : public IShape
{
public:
	TriangleAdapter(Triangle triangle);
	double Perimeter() override;
	double Area() override;
	void DrawShape(ICanvas& canvas) override;
private:
	Triangle m_triangle;

	double Distation(Point& firstPoint, Point& secondPoint)
	{
		double dx = double(firstPoint.x - secondPoint.x);
		double dy = double(firstPoint.y - secondPoint.y);
		return std::sqrt(dx * dx + dy * dy);
	}
};
