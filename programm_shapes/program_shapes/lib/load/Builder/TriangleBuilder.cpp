#include "TriangleBuilder.h"

TriangleBuilder::TriangleBuilder(std::shared_ptr<ICanvasSFML> canvas)
    : m_canvas(canvas) {}


void TriangleBuilder::SetType(std::string& type) 
{
    m_type = type; 
}

void TriangleBuilder::SetPoints(std::vector<Point>& points)
{
    m_point_first = points[FIRST_INDEX];
    m_point_second = points[FIRST_Y_INDEX];
    m_point_third = points[SECOND_X_INDEX];
}

void TriangleBuilder::SetColors(sf::Color& fill, sf::Color& outline) 
{
    m_fill = fill;
    m_outline = outline;
}

void TriangleBuilder::SetOutlineThickness(float thickness) 
{
    m_outlineThickness = thickness;
}

void TriangleBuilder::AddShapeInComposition(std::shared_ptr<CÑompositionShapes> composition) 
{
    auto triangle = std::make_shared<TriangleAdapter>(
        m_point_first, m_point_second, m_point_third, m_type, m_canvas);
    triangle->ChangeFillColor(m_fill);
    triangle->ChangeOutlineColor(m_outline);
    triangle->ChangeOutlineThickness(m_outlineThickness);
    composition->AddShape(triangle);
}

std::shared_ptr<IShape> TriangleBuilder::CreateShape()
{
    auto triangle = std::make_shared<TriangleAdapter>(
        m_point_first, m_point_second, m_point_third, m_type, m_canvas);
    triangle->ChangeFillColor(m_fill);
    triangle->ChangeOutlineColor(m_outline);
    triangle->ChangeOutlineThickness(m_outlineThickness);
	return triangle;
}
