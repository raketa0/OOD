#pragma once
#include "IShapeVisitor.h"
#include "../shapes/CircleAdapter.h"
#include "../shapes/RectangleAdapter.h"
#include "../shapes/TriangleAdapter.h"
#include "../shapes/CGroupShape.h"

class OutlineThicknessVisitor : public IShapeVisitor
{
public:
    OutlineThicknessVisitor(float thickness);

    void VisitCircle(CircleAdapter& circle) override;
    void VisitRectangle(RectangleAdapter& rectangle) override;
    void VisitTriangle(TriangleAdapter& triangle) override;
    void VisitGroup(CGroupShape& group) override;
private:
    float m_thickness;
};
