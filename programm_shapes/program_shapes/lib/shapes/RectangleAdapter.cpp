#include "RectangleAdapter.h"

RectangleAdapter::RectangleAdapter(int x1, int y1, int x2, int y2):
	leftTopCorner{ std::min(x1, x2), std::min(y1, y2) }, 
	width (std::abs(x2 - x1)), height (std::abs(y2 - y1)) {}

double RectangleAdapter::Perimeter()
{
	return 2.0 * (width + height);
}

double RectangleAdapter::Area()
{
	return width * height;
}

void RectangleAdapter::DrawShape(ICanvas& canvas)
{
}
