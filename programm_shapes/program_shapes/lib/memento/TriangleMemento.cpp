#include "TriangleMemento.h"

TriangleMemento::TriangleMemento(std::shared_ptr<TriangleAdapter> triangle, 
	Point firstPoint, Point secondPoint, Point thirdPoint, 
	sf::Color fill, sf::Color outline, float thickness, bool selected)
	: m_triangle(std::move(triangle)),
	m_firstPoint(firstPoint),
	m_secondPoint(secondPoint),
	m_thirdPoint(thirdPoint),
	m_fillColor(fill),
	m_outlineColor(outline),
	m_outlineThickness(thickness),
	m_isSelected(selected)
{
	assert(m_triangle);
}

void TriangleMemento::Restore()
{
	Point delta{ m_firstPoint.x - m_triangle->CalckSelectionFrameParameters().topLeftCorner.x,
				m_firstPoint.y - m_triangle->CalckSelectionFrameParameters().topLeftCorner.y };
	m_triangle->MoveShape(Point{ delta.x, delta.y });
	m_triangle->SetSelected(m_isSelected);
	m_triangle->ChangeFillColor(m_fillColor);
	m_triangle->ChangeOutlineColor(m_outlineColor);
	m_triangle->ChangeOutlineThickness(m_outlineThickness);
}
