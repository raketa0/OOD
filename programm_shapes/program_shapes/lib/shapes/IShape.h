#pragma once
#include "../canvas/ICanvasSFML.h"
#include <string>
#include "../tools/ShapesStruct.h"

class IShape
{
public:
	virtual void Draw() = 0;

	virtual double Perimeter();
	virtual double Area();
	virtual std::string GetType();
	virtual bool IsClick(const sf::Vector2i& mousePos);
	virtual FrameParameters CalckSelectionFrameParameters();
	
};

