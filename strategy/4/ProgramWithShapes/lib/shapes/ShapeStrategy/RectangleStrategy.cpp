#include "RectangleStrategy.h"

shapes::RectangleStrategy::RectangleStrategy(double left, double top, double width, double height):
	m_left(left), m_top(top), m_width(width), m_height(height){}

void shapes::RectangleStrategy::MoveShape(double dx, double dy)
{
	m_left = m_left + dx;
	m_top = m_top + dy;
}

void shapes::RectangleStrategy::DrawShape(gfx::ICanvas& canvas, gfx::Color& color) const
{
	canvas.SetColor(color);
	canvas.MoveTo(m_left, m_top);
	canvas.LineTo(m_left + m_width, m_top);
	canvas.LineTo(m_left + m_width, m_top + m_height);
	canvas.LineTo(m_left, m_top + m_height);
	canvas.LineTo(m_left, m_top);
}

std::string shapes::RectangleStrategy::ToString() const
{
	return std::string();
}
