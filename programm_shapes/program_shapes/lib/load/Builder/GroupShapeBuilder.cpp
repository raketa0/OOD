#include "GroupShapeBuilder.h"

GroupShapeBuilder::GroupShapeBuilder(std::shared_ptr<ICanvasSFML> canvas)
	: m_canvas(canvas) {}

void GroupShapeBuilder::SetType(std::string& type)
{
	m_type = type;
}

void GroupShapeBuilder::AddShapeInComposition(std::shared_ptr<CÑompositionShapes> composition)
{
	auto groupShape = std::make_shared<CGroupShape>(m_groupedShapes, m_canvas);
	composition->AddShape(groupShape);
}

void GroupShapeBuilder::AddShapeToGroup(int id, std::shared_ptr<IShape> shape)
{
	m_groupedShapes[id] = shape;
}

std::shared_ptr<IShape> GroupShapeBuilder::CreateShape()
{
	auto groupShape = std::make_shared<CGroupShape>(m_groupedShapes, m_canvas);
	return groupShape;
}


