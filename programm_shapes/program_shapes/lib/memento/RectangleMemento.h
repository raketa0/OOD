#pragma once

#include "IMementoShapes.h"
#include "../shapes/RectangleAdapter.h"

class RectangleMemento : public IMementoShapes
{
public:
    RectangleMemento(std::shared_ptr<RectangleAdapter> rect, Point topLeft,
        int width, int height, sf::Color fill, sf::Color outline,
        float thickness, bool selected);

    void Restore() override;

private:
    std::shared_ptr<RectangleAdapter> m_rect;
    Point m_topLeft;
    int m_width;
    int m_height;
    sf::Color m_fillColor;
    sf::Color m_outlineColor;
    float m_outlineThickness;
    bool m_isSelected;
};