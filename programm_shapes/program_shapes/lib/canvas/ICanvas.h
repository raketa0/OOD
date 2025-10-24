#pragma once
#include "../tools/ShapesStruct.h"
#include <SFML/Graphics.hpp>

class ICanvas
{
public:
    virtual void drawCircle(Point centerCircle, int radius) = 0; // с большой буквы
    virtual void drawRectangle(Point leftTopCorner, int width, int height) = 0; 
    virtual void drawTriangle(Point firstPoint, Point secondPoint, Point thirdPoint) = 0;
};


