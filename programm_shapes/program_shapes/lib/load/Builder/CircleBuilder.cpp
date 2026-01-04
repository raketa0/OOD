#include "CircleBuilder.h"

CircleBuilder::CircleBuilder(std::shared_ptr<ICanvasSFML> canvas)
	: m_canvas(canvas) {}

void CircleBuilder::SetType(std::string& type)
{
	m_type = type;
}

void CircleBuilder::SetPoints(std::vector<Point>& points)
{
	m_center = points[FIRST_INDEX];
}

void CircleBuilder::SetRadius(int radius)
{
	m_radius = radius;
}

void CircleBuilder::SetColors(sf::Color& fill, sf::Color& outline)
{
	m_fill = fill;
	m_outline = outline;
}

void CircleBuilder::SetOutlineThickness(float thickness)
{
	m_outlineThickness = thickness;
}

void CircleBuilder::AddShapeInComposition(std::shared_ptr<CÑompositionShapes> composition)
{
	auto circle = std::make_shared<CircleAdapter>(m_center,
		m_radius, m_type, m_canvas);
	circle->ChangeFillColor(m_fill);
	circle->ChangeOutlineColor(m_outline);
	circle->ChangeOutlineThickness(m_outlineThickness);
	composition->AddShape(circle);
}

std::shared_ptr<IShape> CircleBuilder::CreateShape()
{
	auto circle = std::make_shared<CircleAdapter>(m_center,
		m_radius, m_type, m_canvas);
	circle->ChangeFillColor(m_fill);
	circle->ChangeOutlineColor(m_outline);
	circle->ChangeOutlineThickness(m_outlineThickness);
	return circle;
}
