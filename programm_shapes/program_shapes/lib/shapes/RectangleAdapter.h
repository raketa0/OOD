#pragma once
#include "IShape.h"
#include "../canvas/ICanvas.h"


class RectangleAdapter : public IShape
{
public:
	RectangleAdapter(Rectangle rectange);
	double Perimeter() override;
	double Area() override;
	void DrawShape(ICanvas& canvas) override;

private:
	Rectangle m_rectange;
};
