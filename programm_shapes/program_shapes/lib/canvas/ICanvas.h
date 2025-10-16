#pragma once
#include "../tools/Point.h"


class ICanvas
{
public:
    virtual void drawCircle(Point centerCircle, int radius) = 0;
    virtual void drawRectangle(Point leftTopCorner, int width, int	height) = 0;
    virtual void drawTriangle(Point firstPoint, Point secondPoint, Point thirdPoint) = 0;
private:

};


