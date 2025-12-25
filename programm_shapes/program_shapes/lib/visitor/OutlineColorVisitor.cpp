#include "OutlineColorVisitor.h"

OutlineColorVisitor::OutlineColorVisitor(sf::Color color)
	: m_color(color) {
}

void OutlineColorVisitor::VisitCircle(CircleAdapter& circle)
{
	circle.ChangeOutlineColor(m_color);
}

void OutlineColorVisitor::VisitRectangle(RectangleAdapter& rectangle)
{
	rectangle.ChangeOutlineColor(m_color);
}

void OutlineColorVisitor::VisitTriangle(TriangleAdapter& triangle)
{
	triangle.ChangeOutlineColor(m_color);
}

void OutlineColorVisitor::VisitGroup(CGroupShape& group)
{
	for (const auto& [id, shape] : group.GetGroupedShapes())
	{
		shape->ChangeOutlineColor(m_color);
	}
}
