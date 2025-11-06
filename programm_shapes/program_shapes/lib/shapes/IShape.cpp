#include "IShape.h"

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
