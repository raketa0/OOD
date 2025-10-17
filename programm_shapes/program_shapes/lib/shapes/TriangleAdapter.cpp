#include "TriangleAdapter.h"

TriangleAdapter::TriangleAdapter(Triangle triangle):
	m_triangle(triangle){}

double TriangleAdapter::Perimeter()
{
	return Distation(m_triangle.firstPoint, m_triangle.secondPoint) +
		   Distation(m_triangle.firstPoint, m_triangle.thirdPoint) +
		   Distation(m_triangle.secondPoint, m_triangle.thirdPoint);
}

double TriangleAdapter::Area()
{
    double halfPerimeter = Perimeter() / 2;
    return std::sqrt(
        halfPerimeter *
        (halfPerimeter - Distation(m_triangle.firstPoint, m_triangle.secondPoint)) *
        (halfPerimeter - Distation(m_triangle.firstPoint, m_triangle.thirdPoint)) *
        (halfPerimeter - Distation(m_triangle.secondPoint, m_triangle.thirdPoint))
    );
}

void TriangleAdapter::DrawShape(ICanvas& canvas)
{
    canvas.drawTriangle(m_triangle);
}

std::string TriangleAdapter::GetType()
{
    return m_triangle.type;
}
