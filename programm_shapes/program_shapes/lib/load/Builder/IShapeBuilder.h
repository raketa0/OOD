#pragma once
#include <string>
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "../../tools/ShapesStruct.h"
#include "../../shapes/IShape.h"
#include "../../shapes/CÑompositionShapes.h"
#include "../../tools/Constants.h"

class IShapeBuilder
{
public:
    virtual ~IShapeBuilder() = default;
    virtual void SetType(std::string& type);
    virtual void SetPoints(std::vector<Point>& points);
    virtual void SetDimensions(int width, int height);
    virtual void SetRadius(int radius);
    virtual void SetColors(sf::Color& fill, sf::Color& outline);
    virtual void SetOutlineThickness(float thickness);
	virtual void AddShapeInComposition(std::shared_ptr<CÑompositionShapes> composition);
	virtual void AddShapeToGroup(int id, std::shared_ptr<IShape> shape);
    virtual std::shared_ptr<IShape> CreateShape() = 0;

};