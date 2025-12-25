#include "FillColorVisitor.h"

FillColorVisitor::FillColorVisitor(sf::Color color)
	: m_color(color) {}

void FillColorVisitor::VisitCircle(CircleAdapter& circle)
{
    circle.ChangeFillColor(m_color);
}

void FillColorVisitor::VisitRectangle(RectangleAdapter& rectangle)
{
    rectangle.ChangeFillColor(m_color);
}

void FillColorVisitor::VisitTriangle(TriangleAdapter& triangle)
{
    triangle.ChangeFillColor(m_color);
}

void FillColorVisitor::VisitGroup(CGroupShape& group)
{
    for (const auto& [id, shape] : group.GetGroupedShapes())
    {
        shape->ChangeFillColor(m_color);
    }
}
