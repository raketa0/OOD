#pragma once
#include "../tools/ShapesStruct.h"



class ICanvas
{
public:
    virtual void drawCircle(Circle circ) = 0;
    virtual void drawRectangle(Rectangle rect) = 0;
    virtual void drawTriangle(Triangle triang) = 0;
private:

};


