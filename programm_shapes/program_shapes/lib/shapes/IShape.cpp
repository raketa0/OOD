#include "IShape.h"
#include <map>

double IShape::Perimeter() 
{ 
	return 0.0;
}
double IShape::Area()
{ 
	return 0.0; 
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

