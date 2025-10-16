#pragma once
#include "IShape.h"
#include "../tools/Point.h"
#include "../canvas/ICanvas.h"

#include <cmath>

class TriangleAdapter : public IShape
{
public:
	TriangleAdapter(int x1, int y1, int x2, int y2, int x3, int y3);
	double Perimeter() override;
	double Area() override;
	void DrawShape(ICanvas& canvas) override;
private:
	Point firstPoint;
	Point secondPoint;
	Point thirdPoint;

	double Distation(Point& firstPoint, Point& secondPoint)
	{
		double dx = double(firstPoint.x - secondPoint.x);
		double dy = double(firstPoint.y - secondPoint.y);
		return std::sqrt(dx * dx + dy * dy);
	}
};
