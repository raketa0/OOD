#include "CircleAdapter.h"
#include <string>
#include <cassert>

CircleAdapter::CircleAdapter(Point centerCircle, int radius,
	std::string type, std::shared_ptr<ICanvasSFML> canvas) :
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

void CircleAdapter::Draw()
{
	m_canvas->drawCircle(m_centerCircle, m_radius);
}

std::string CircleAdapter::GetType()
{
	return m_type;
}

bool CircleAdapter::IsClick(const sf::Vector2i& mousePos)
{
	double dx = mousePos.x - m_centerCircle.x;
	double dy = mousePos.y - m_centerCircle.y;
	double distanceSquared = dx * dx + dy * dy;
	
	return distanceSquared <= m_radius * m_radius;
}

FrameParameters CircleAdapter::CalckSelectionFrameParameters()
{
	FrameParameters frameParams{};
	frameParams.topLeftCorner.x = m_centerCircle.x - m_radius;
	frameParams.topLeftCorner.y = m_centerCircle.y - m_radius;
	frameParams.width = 2 * m_radius;
	frameParams.height = 2 * m_radius;
	return frameParams;
}

void CircleAdapter::SetSelected(bool value)
{
	m_isSelected = value;
}

bool CircleAdapter::IsSelected()
{
	return m_isSelected;
}

void CircleAdapter::MoveShape(const Point& newPosition)
{
	m_centerCircle = Point{ newPosition.x + m_radius, newPosition.y + m_radius };
}

