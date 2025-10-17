#include "RectangleAdapter.h"
#include "../tools/ShapesStruct.h"

RectangleAdapter::RectangleAdapter(Rectangle rectange):
	m_rectange(rectange) {}

double RectangleAdapter::Perimeter()
{
	return 2.0 * (m_rectange.width + m_rectange.height);
}

double RectangleAdapter::Area()
{
	return m_rectange.width * m_rectange.height;
}

void RectangleAdapter::DrawShape(ICanvas& canvas)
{
	canvas.drawRectangle(m_rectange);
}
