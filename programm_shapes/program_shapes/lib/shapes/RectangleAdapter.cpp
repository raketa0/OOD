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

void RectangleAdapter::Draw()
{
	m_canvas->DrawRectangle(m_leftTopCorner, m_width, m_height, 
		m_fillColor, m_outlineColor, m_outlineThickness, true);
}

std::string RectangleAdapter::GetType()
{
	return m_type;
}

bool RectangleAdapter::IsClick(const sf::Vector2i& mousePos)
{
	return (mousePos.x >= m_leftTopCorner.x &&
		mousePos.x <= m_leftTopCorner.x + m_width &&
		mousePos.y >= m_leftTopCorner.y &&
		mousePos.y <= m_leftTopCorner.y + m_height);
}

FrameParameters RectangleAdapter::CalckSelectionFrameParameters()
{
	FrameParameters frameParams{};
	frameParams.topLeftCorner = m_leftTopCorner;
	frameParams.width = m_width;
	frameParams.height = m_height;
	return frameParams;
}

void RectangleAdapter::SetSelected(bool value)
{
	m_isSelected = value;
}

bool RectangleAdapter::IsSelected()
{
	return m_isSelected;
}

void RectangleAdapter::MoveShape(const Point& newPosition)
{
	m_leftTopCorner = newPosition;
}

void RectangleAdapter::ChangeFillColor(const sf::Color& color)
{
	m_fillColor = color;
}

void RectangleAdapter::ChangeOutlineColor(const sf::Color& color)
{
	m_outlineColor = color;
}

void RectangleAdapter::ChangeOutlineThickness(float thickness)
{
	m_outlineThickness = thickness;
}


