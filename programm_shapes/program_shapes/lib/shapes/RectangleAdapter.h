#pragma once
#include "IShape.h"
#include "../canvas/ICanvas.h"
#include "../tools/ShapesStruct.h"


class RectangleAdapter : public IShape
{
public:
	RectangleAdapter(Rectangle rectange);
	double Perimeter() override;
	double Area() override;
	void DrawShape(ICanvas& canvas) override;
	std::string GetType() override;

private:
	Rectangle m_rectange;
};
