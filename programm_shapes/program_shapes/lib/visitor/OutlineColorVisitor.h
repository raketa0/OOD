#pragma once
#include "IShapeVisitor.h"
#include "../shapes/CircleAdapter.h"
#include "../shapes/RectangleAdapter.h"
#include "../shapes/TriangleAdapter.h"
#include "../shapes/CGroupShape.h"

class OutlineColorVisitor : public IShapeVisitor
{
public:
    OutlineColorVisitor(sf::Color color);

    void VisitCircle(CircleAdapter& circle) override;
    void VisitRectangle(RectangleAdapter& rectangle) override;
    void VisitTriangle(TriangleAdapter& triangle) override;
    void VisitGroup(CGroupShape& group) override;

private:
    sf::Color m_color;
};