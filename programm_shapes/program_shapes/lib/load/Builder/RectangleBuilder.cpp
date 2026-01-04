#include "RectangleBuilder.h"

RectangleBuilder::RectangleBuilder(std::shared_ptr<ICanvasSFML> canvas)
	: m_canvas(canvas) {}

void RectangleBuilder::SetType(std::string& type)
{
	m_type = type;
}

void RectangleBuilder::SetPoints(std::vector<Point>& points)
{
	m_leftTop = points[ZERO_INDEX];
}

void RectangleBuilder::SetDimensions(int width, int height)
{
	m_width = width; 
	m_height = height;
}

void RectangleBuilder::SetColors(sf::Color& fill, sf::Color& outline)
{
	m_fill = fill;
	m_outline = outline;
}

void RectangleBuilder::SetOutlineThickness(float thickness)
{
	m_outlineThickness = thickness;
}

void RectangleBuilder::AddShapeInComposition(std::shared_ptr<CÑompositionShapes> composition)
{
	auto rectangle = std::make_shared<RectangleAdapter>(m_leftTop,
		m_width, m_height, m_type, m_canvas);
	rectangle->ChangeFillColor(m_fill);
	rectangle->ChangeOutlineColor(m_outline);
	rectangle->ChangeOutlineThickness(m_outlineThickness);
	composition->AddShape(rectangle);
}

std::shared_ptr<IShape> RectangleBuilder::CreateShape()
{
	auto rectangle = std::make_shared<RectangleAdapter>(m_leftTop,
		m_width, m_height, m_type, m_canvas);
	rectangle->ChangeFillColor(m_fill);
	rectangle->ChangeOutlineColor(m_outline);
	rectangle->ChangeOutlineThickness(m_outlineThickness);
	return rectangle;
}



