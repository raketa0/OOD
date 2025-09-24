#include "CircleStrategy.h"

CircleStrategy::CircleStrategy(double cx, double cy, double r):
	m_cx(cx-r), m_cy(cy-r), m_r(r){}

void CircleStrategy::MoveShape(double dx, double dy)
{
	m_cx = m_cx + dx;
	m_cy = m_cy + dy;
}

void CircleStrategy::DrawShape(gfx::ICanvas& canvas, gfx::Color& color) const
{
	canvas.SetColor(color);
	canvas.DrawEllipse(m_cx, m_cy, m_r, m_r);
}

std::string CircleStrategy::ToString() const
{
	return std::string();
}
