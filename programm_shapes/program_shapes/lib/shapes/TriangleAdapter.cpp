#include "TriangleAdapter.h"

TriangleAdapter::TriangleAdapter(int x1, int y1, int x2, int y2, int x3, int y3):
	firstPoint{ x1, y1 }, secondPoint{ x2, y2 }, thirdPoint{ x3, y3 }{}

double TriangleAdapter::Perimeter()
{
	return Distation(firstPoint, secondPoint) + 
		   Distation(firstPoint, thirdPoint) +
		   Distation(secondPoint, thirdPoint);
}

double TriangleAdapter::Area()
{
    double halfPerimeter = Perimeter() / 2;
    return std::sqrt(
        halfPerimeter *
        (halfPerimeter - Distation(firstPoint, secondPoint)) *
        (halfPerimeter - Distation(firstPoint, thirdPoint)) *
        (halfPerimeter - Distation(secondPoint, thirdPoint))
    );
}

void TriangleAdapter::DrawShape(ICanvas& canvas)
{
}
