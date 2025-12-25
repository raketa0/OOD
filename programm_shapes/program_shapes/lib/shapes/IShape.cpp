#include "IShape.h"
#include <map>

double IShape::Perimeter() 
{ 
	return ZERO;
}
double IShape::Area()
{ 
	return ZERO;
}
std::string IShape::GetType()
{
	return ""; 
}

bool IShape::IsClick(const sf::Vector2i& mousePos)
{
	return false;
}

FrameParameters IShape::CalckSelectionFrameParameters()
{
	return {};
}

void IShape::SetSelected(bool value)
{
}

bool IShape::IsSelected()
{
	return false;
}

bool IShape::IsGroup()
{
	return false;
}

std::map<int, std::shared_ptr<IShape>> IShape::GetGroupedShapes()
{
	return {};
}

void IShape::MoveShape(const Point& newPosition)
{
}

sf::Color IShape::GetFillColor()
{
	return sf::Color();
}

sf::Color IShape::GetOutlineColor()
{
	return sf::Color();
}

float IShape::GetOutlineThickness()
{
	return 0.0f;
}

void IShape::ChangeFillColor(const sf::Color& color)
{
}

void IShape::ChangeOutlineColor(const sf::Color& color)
{
}

void IShape::ChangeOutlineThickness(float thickness)
{
}

std::shared_ptr<IShape> IShape::CreateMemento()
{
	return nullptr;
}

void IShape::Accept(IShapeVisitor& visitor)
{
}
