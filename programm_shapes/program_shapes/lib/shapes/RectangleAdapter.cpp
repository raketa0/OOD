#include "RectangleAdapter.h"
#include <cassert>

RectangleAdapter::RectangleAdapter(Point leftTopCorner, int width,
	int height, std::string type,
	std::shared_ptr<ICanvasSFML> canvas):
	m_leftTopCorner(leftTopCorner),
	m_width(width),
	m_height(height),
	m_type(type),
	m_canvas(std::move(canvas))
{
	assert(m_canvas);
}

double RectangleAdapter::Perimeter()
{
	return 2.0 * (m_width + m_height);
}

double RectangleAdapter::Area()
{
	return double(m_width) * double(m_height);
}

void RectangleAdapter::DrawShape()
{
	m_canvas->DrawRectangle(m_leftTopCorner, m_width, m_height);
}

std::string RectangleAdapter::GetType()
{
	return m_type;
}

