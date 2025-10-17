#include "CircleAdapter.h"


CircleAdapter::CircleAdapter(Circle circle):
	m_circle(circle)
{}

double CircleAdapter::Perimeter()
{
	return 2 * PI * m_circle.radius;
}

double CircleAdapter::Area()
{
	return PI * m_circle.radius * m_circle.radius;
}

void CircleAdapter::DrawShape(ICanvas& canvas)
{
	canvas.drawCircle(m_circle);
}
