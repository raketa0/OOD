#pragma once
#include "../tools/ShapesStruct.h"
#include <SFML/Graphics.hpp>

class ICanvasSFML
{
public:
    virtual void DrawCircle(Point centerCircle, int radius) = 0;
    virtual void DrawRectangle(Point leftTopCorner, int width, int height,
		float outlineThickness = DEFOLD_OUTLINE_THINCENSS,
		sf::Color outlineColor = sf::Color::White,
		bool useFill = false) = 0;
    virtual void DrawTriangle(Point firstPoint, Point secondPoint, Point thirdPoint) = 0;
};


