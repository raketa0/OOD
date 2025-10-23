#pragma once
#include "IShape.h"
#include "../canvas/ICanvas.h"

#include <cmath>
#include "../tools/ShapesStruct.h"

class TriangleAdapter : public IShape
{
public:
	TriangleAdapter(Point firstPoint, Point secondPoint, Point thirdPoint, std::string type = TRIANGLE_TYPE);
	double Perimeter() override;
	double Area() override;
	void DrawShape(ICanvas& canvas) override;
	std::string GetType() override;

private:
	Point m_firstPoint;
	Point m_secondPoint;
	Point m_thirdPoint;
	std::string m_type;

	double Distation(const Point& firstPoint, const Point& secondPoint)
	{
		double dx = double(firstPoint.x - secondPoint.x);
		double dy = double(firstPoint.y - secondPoint.y);
		return std::sqrt(dx * dx + dy * dy);
	}
};
