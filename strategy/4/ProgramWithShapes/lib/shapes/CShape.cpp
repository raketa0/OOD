#include "CShape.h"
#include <stdexcept>
#include <iostream>

shapes::CShape::CShape(const std::string id,
	const gfx::Color& color,
	std::unique_ptr<IShapeStrategy>&& shapeStrategy) :
	m_id(id),
	//m_shapeStrategy(std::move(shapeStrategy)),
	m_color(color)
{
	ChangeShape(std::move(shapeStrategy));
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
	if (!m_shapeStrategy) {
		throw std::runtime_error("No strategy set for shape");
	}
	
	m_shapeStrategy->DrawShape(canvas, m_color);
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