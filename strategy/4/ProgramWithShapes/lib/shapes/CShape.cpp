#include "CShape.h"

shapes::CShape::CShape(const std::string id,
	const gfx::Color& color,
	std::unique_ptr<IShapeStrategy>&& shapeStrategy) :
	m_id(id),
	m_shapeStrategy(std::move(shapeStrategy)),
	m_color(color)
{
	assert(m_shapeStrategy);
}

const std::string& shapes::CShape::GetId() const
{
	return m_id;
}

const gfx::Color& shapes::CShape::GetColor() const
{
	return m_color;
}

void shapes::CShape::SetColor(const gfx::Color& newColor)
{
	m_color = newColor;
}

void shapes::CShape::MoveShape(double dx, double dy)
{
	m_shapeStrategy->MoveShape(dx, dy);
}

void shapes::CShape::DrawShape(gfx::ICanvas& canvas)
{
	m_shapeStrategy->DrawShape(canvas);
}

void shapes::CShape::ChangeShape(std::unique_ptr<IShapeStrategy>&& newShapeStrategy)
{
	assert(newShapeStrategy);
	m_shapeStrategy = std::move(newShapeStrategy);
}

std::string shapes::CShape::ToString()
{
	m_shapeStrategy->ToString();
	return"";
}