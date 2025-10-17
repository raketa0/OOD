#pragma once
#include "IShape.h"
#include "../canvas/ICanvas.h"
#include "../tools/ShapesStruct.h"


const double PI = 3.14159265358979323846;


class CircleAdapter : public IShape
{
public:
	CircleAdapter(Circle circle);
	double Perimeter() override;
	double Area() override;
	void DrawShape(ICanvas& canvas) override;

private:
	Circle m_circle;
};

