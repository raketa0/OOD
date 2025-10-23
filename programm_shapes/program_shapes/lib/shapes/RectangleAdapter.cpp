#include "RectangleAdapter.h"

RectangleAdapter::RectangleAdapter(Point leftTopCorner, int width, int height, std::string type):
	m_leftTopCorner(leftTopCorner),
	m_width(width),
	m_height(height),
	m_type(type)
{}

double RectangleAdapter::Perimeter()
{
	return 2.0 * (m_width + m_height);
}

double RectangleAdapter::Area()
{
	return double(m_width) * double(m_height);
}

void RectangleAdapter::DrawShape(ICanvas& canvas)
{
	canvas.drawRectangle(m_leftTopCorner, m_width, m_height);
}

std::string RectangleAdapter::GetType()
{
	return m_type;
}

