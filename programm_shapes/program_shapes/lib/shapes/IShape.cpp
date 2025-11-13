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

