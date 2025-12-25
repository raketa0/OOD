#pragma once
#include "../canvas/ICanvasSFML.h"
#include <string>
#include "../tools/ShapesStruct.h"
#include <map>
#include "../memento/IMementoShapes.h"
#include "../visitor/IShapeVisitor.h"
class IShape
{
public:
	virtual void Draw() = 0;

	virtual double Perimeter();
	virtual double Area();
	virtual std::string GetType();

	virtual bool IsClick(const sf::Vector2i& mousePos);
	virtual FrameParameters CalckSelectionFrameParameters();
	virtual void SetSelected(bool value);
	virtual bool IsSelected();
	virtual bool IsGroup();
	virtual std::map<int, std::shared_ptr<IShape>> GetGroupedShapes();
	virtual void MoveShape(const Point& newPosition);
	virtual sf::Color GetFillColor();
	virtual sf::Color GetOutlineColor();
	virtual float GetOutlineThickness();
	virtual void ChangeFillColor(const sf::Color& color);
	virtual void ChangeOutlineColor(const sf::Color& color);
	virtual void ChangeOutlineThickness(float thickness);

	virtual std::shared_ptr<IShape> CreateMemento();

	virtual void Accept(IShapeVisitor& visitor);

};

