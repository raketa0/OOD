#pragma once
#include <memory>

class CircleAdapter;
class RectangleAdapter;
class TriangleAdapter;
class CGroupShape;


class IShapeVisitor
{
public:
    virtual ~IShapeVisitor() = default;

    virtual void VisitCircle(CircleAdapter& circle) = 0;
    virtual void VisitRectangle(RectangleAdapter& rectangle) = 0;
    virtual void VisitTriangle(TriangleAdapter& triangle) = 0;
    virtual void VisitGroup(CGroupShape& group) = 0;
};
