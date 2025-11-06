#pragma once
#include "../tools/ShapesStruct.h"
#include <SFML/Graphics.hpp>

class ICanvasSFML
{
public:
    virtual void drawCircle(Point centerCircle, int radius) = 0;
    virtual void drawRectangle(Point leftTopCorner, int width, int height,
		float outlineThickness = 4.0f,
		sf::Color outlineColor = sf::Color::White,
		bool useFill = false) = 0;
    virtual void drawTriangle(Point firstPoint, Point secondPoint, Point thirdPoint) = 0;
};


