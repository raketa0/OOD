#pragma once
#include "IMementoShapes.h"
#include "../shapes/TriangleAdapter.h"
#include <memory>

class TriangleMemento : public IMementoShapes
{
public:
    TriangleMemento(std::shared_ptr<TriangleAdapter> triangle,
        Point firstPoint,
        Point secondPoint,
        Point thirdPoint,
        sf::Color fill, sf::Color outline,
        float thickness, bool selected);

    void Restore() override;


private:
    std::shared_ptr<TriangleAdapter> m_triangle;
    Point m_firstPoint;
    Point m_secondPoint;
    Point m_thirdPoint;
    sf::Color m_fillColor;
    sf::Color m_outlineColor;
    float m_outlineThickness;
    bool m_isSelected;
};