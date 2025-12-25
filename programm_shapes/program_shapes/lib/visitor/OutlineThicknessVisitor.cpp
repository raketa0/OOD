#include "OutlineThicknessVisitor.h"

OutlineThicknessVisitor::OutlineThicknessVisitor(float thickness)
	: m_thickness(thickness) {}

void OutlineThicknessVisitor::VisitCircle(CircleAdapter& circle)
{
	circle.ChangeOutlineThickness(m_thickness);
}

void OutlineThicknessVisitor::VisitRectangle(RectangleAdapter& rectangle)
{
	rectangle.ChangeOutlineThickness(m_thickness);
}

void OutlineThicknessVisitor::VisitTriangle(TriangleAdapter& triangle)
{
	triangle.ChangeOutlineThickness(m_thickness);
}

void OutlineThicknessVisitor::VisitGroup(CGroupShape& group)
{
	for (const auto& [id, shape] : group.GetGroupedShapes())
	{
		shape->ChangeOutlineThickness(m_thickness);
	}
}
