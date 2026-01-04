#include "IShapeBuilder.h"

void IShapeBuilder::SetType(std::string& type)
{
}

void IShapeBuilder::SetPoints(std::vector<Point>& points)
{
}

void IShapeBuilder::SetDimensions(int width, int height)
{
}

void IShapeBuilder::SetRadius(int radius)
{
}

void IShapeBuilder::SetColors(sf::Color& fill, sf::Color& outline)
{
}

void IShapeBuilder::SetOutlineThickness(float thickness)
{
}


void IShapeBuilder::AddShapeInComposition(std::shared_ptr<CÑompositionShapes> composition)
{
}

void IShapeBuilder::AddShapeToGroup(int id, std::shared_ptr<IShape> shape)
{
}


