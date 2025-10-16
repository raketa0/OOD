#pragma once
#include "IShape.h"
#include "../tools/Point.h"
#include <algorithm>
#include "../canvas/ICanvas.h"


class RectangleAdapter : public IShape
{
public:
	RectangleAdapter(int x1, int y1, int x2, int y2);
	double Perimeter() override;
	double Area() override;
	void DrawShape(ICanvas& canvas) override;

private:
	Point leftTopCorner;
	int width;
	int	height;
};
