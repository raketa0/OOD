#include "TriangleAdapter.h"

TriangleAdapter::TriangleAdapter(Point firstPoint, Point secondPoint, Point thirdPoint, std::string type):
	m_firstPoint(firstPoint),
	m_secondPoint(secondPoint),
	m_thirdPoint(thirdPoint),
	m_type(type) {}

double TriangleAdapter::Perimeter()
{
	return Distation(m_firstPoint, m_secondPoint) +
		   Distation(m_firstPoint, m_thirdPoint) +
		   Distation(m_secondPoint, m_thirdPoint);
}

double TriangleAdapter::Area()
{
    double halfPerimeter = Perimeter() / 2;
    return std::sqrt(
        halfPerimeter *
        (halfPerimeter - Distation(m_firstPoint, m_secondPoint)) *
        (halfPerimeter - Distation(m_firstPoint, m_thirdPoint)) *
        (halfPerimeter - Distation(m_secondPoint, m_thirdPoint))
    );
}

void TriangleAdapter::DrawShape(ICanvas& canvas)
{
    canvas.drawTriangle(m_firstPoint, m_secondPoint, m_thirdPoint);
}

std::string TriangleAdapter::GetType()
{
    return m_type;
}
