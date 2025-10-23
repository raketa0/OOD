#pragma once
#include "IShape.h"
#include "../canvas/ICanvas.h"
#include "../tools/ShapesStruct.h"

class RectangleAdapter : public IShape
{
public:
	RectangleAdapter(Point leftTopCorner, int width, int height, std::string type = RECTANGLE_TYPE);
	double Perimeter() override;
	double Area() override;
	void DrawShape(ICanvas& canvas) override;
	std::string GetType() override;

private:
	Point m_leftTopCorner;
	int m_width;
	int m_height;
	std::string m_type;
};
