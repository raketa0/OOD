#include "CircleAdapter.h"
#include <string>


CircleAdapter::CircleAdapter(Point centerCircle, int radius, std::string type):
	m_centerCircle(centerCircle),
	m_radius(radius),
	m_type(type)
{}

double CircleAdapter::Perimeter()
{
	return 2 * PI * m_radius;
}

double CircleAdapter::Area()
{
	return PI * m_radius * m_radius;
}

void CircleAdapter::DrawShape(ICanvas& canvas)
{
	canvas.drawCircle(m_centerCircle, m_radius);
}

std::string CircleAdapter::GetType()
{
	return m_type;
}
