#pragma once
#include "IShape.h"
#include "../tools/Point.h"
#include "../canvas/ICanvas.h"
#include <memory>


const double PI = 3.14159265358979323846;


class CircleAdapter : public IShape
{
public:
	CircleAdapter(int cx, int cy, int r);
	double Perimeter() override;
	double Area() override;
	void DrawShape(ICanvas& canvas) override;

private:
	Point centerCircle;
	int radius;
};

