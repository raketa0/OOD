#include "RectangleMemento.h"

RectangleMemento::RectangleMemento(std::shared_ptr<RectangleAdapter> rect, Point topLeft,
	int width, int height, sf::Color fill, 
	sf::Color outline, float thickness, bool selected)
    : m_rect(rect),
    m_topLeft(topLeft),
    m_width(width),
    m_height(height),
    m_fillColor(fill),
    m_outlineColor(outline),
    m_outlineThickness(thickness),
    m_isSelected(selected)
{
    assert(m_rect);
}

void RectangleMemento::Restore()
{
    m_rect->MoveShape(m_topLeft);
    m_rect->SetSelected(m_isSelected);
    m_rect->ChangeFillColor(m_fillColor);
    m_rect->ChangeOutlineColor(m_outlineColor);
    m_rect->ChangeOutlineThickness(m_outlineThickness);
}
