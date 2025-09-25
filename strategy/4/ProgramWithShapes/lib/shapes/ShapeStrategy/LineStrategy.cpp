#include "LineStrategy.h"

shapes::LineStrategy::LineStrategy(double x1, double x2, double y1, double y2):
	m_x1(x1), m_x2(x2), m_y1(y1), m_y2(y2){}

void shapes::LineStrategy::MoveShape(double dx, double dy)
{
	m_x1 = m_x1 + dx;
	m_x2 = m_x2 + dx;
	m_y1 = m_y1 + dy;
	m_y2 = m_y2 + dy;
}

void shapes::LineStrategy::DrawShape(gfx::ICanvas& canvas, gfx::Color& color) const
{
	canvas.SetColor(color);
	canvas.MoveTo(m_x1, m_y1);
	canvas.LineTo(m_x2, m_y2);
}

std::string shapes::LineStrategy::ToString() const
{
	return std::string();
}
