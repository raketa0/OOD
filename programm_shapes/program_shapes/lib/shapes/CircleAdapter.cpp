#include "CircleAdapter.h"
#include <math.h>
CircleAdapter::CircleAdapter(int cx, int cy, int r):
	centerCircle{ cx, cy }, radius(r) 
{}

double CircleAdapter::Perimeter()
{
	return 2 * PI * radius;
}

double CircleAdapter::Area()
{
	return PI * radius * radius;
}

void CircleAdapter::DrawShape(ICanvas& canvas)
{
	canvas.drawCircle(centerCircle, radius);
}
