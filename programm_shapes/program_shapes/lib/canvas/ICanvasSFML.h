#pragma once
#include "../tools/ShapesStruct.h"
#include <SFML/Graphics.hpp>

class ICanvasSFML
{
public:
    virtual void DrawCircle(Point centerCircle, int radius,
		sf::Color fillColor, 
		sf::Color outlineColor, 
		float outlineThickness) = 0;

    virtual void DrawRectangle(Point leftTopCorner, int width, int height,
		sf::Color fillColor,
		sf::Color outlineColor,
		float outlineThickness,
		bool useFill) = 0;

    virtual void DrawTriangle(Point firstPoint, Point secondPoint, Point thirdPoint,
		sf::Color fillColor, 
		sf::Color outlineColor, 
		float outlineThickness) = 0;
};


