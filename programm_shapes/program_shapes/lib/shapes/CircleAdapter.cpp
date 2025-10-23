#include "CircleAdapter.h"
#include <string>
#include <cassert>

CircleAdapter::CircleAdapter(Point centerCircle, int radius,
	std::string type, std::shared_ptr<ICanvas> canvas) :
	m_centerCircle(centerCircle),
	m_radius(radius),
	m_type(type),
	m_canvas(std::move(canvas))
{
	assert(m_canvas);
}

double CircleAdapter::Perimeter()
{
	return 2 * PI * m_radius;
}

double CircleAdapter::Area()
{
	return PI * m_radius * m_radius;
}

void CircleAdapter::DrawShape()
{
	m_canvas->drawCircle(m_centerCircle, m_radius);
}

std::string CircleAdapter::GetType()
{
	return m_type;
}
