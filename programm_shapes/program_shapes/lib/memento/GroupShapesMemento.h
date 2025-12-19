#pragma once

#include "IMementoShapes.h"
#include "../shapes/CGroupShape.h"
#include <memory>
#include <map>
struct ShapeParameters
{
    Point topLeft;
    sf::Color fill;
    sf::Color outline;
    float thickness;
    bool selected;
};

class GroupShapesMemento : public IMementoShapes
{
public:
    GroupShapesMemento(std::shared_ptr<CGroupShape> groupShape);

    void Restore() override;

private:
    std::shared_ptr<CGroupShape> m_groupShape;
    bool m_selected;
    std::map<int, ShapeParameters> m_shapesParameters;
};