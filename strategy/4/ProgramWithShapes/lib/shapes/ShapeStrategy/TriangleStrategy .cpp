#include "TriangleStrategy .h"

TriangleStrategy::TriangleStrategy(double x1, double y1,
    double x2, double y2,
    double x3, double y3)
    : m_x1(x1), m_y1(y1), m_x2(x2), m_y2(y2), m_x3(x3), m_y3(y3) {
}

void TriangleStrategy::MoveShape(double dx, double dy)
{
    m_x1 += dx; 
    m_y1 += dy;
    m_x2 += dx;
    m_y2 += dy;
    m_x3 += dx; 
    m_y3 += dy;
}

void TriangleStrategy::DrawShape(gfx::ICanvas& canvas, gfx::Color& color) const
{
    canvas.SetColor(color);
    canvas.MoveTo(m_x1, m_y1);
    canvas.LineTo(m_x2, m_y2);
    canvas.LineTo(m_x3, m_y3);
    canvas.LineTo(m_x1, m_y1);
}

std::string TriangleStrategy::ToString() const
{
	return std::string();
}
