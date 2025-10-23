#pragma once
#include "IShape.h"
#include "../canvas/ICanvas.h"
#include "../tools/ShapesStruct.h"
#include "../tools/Constants.h"



class CircleAdapter : public IShape
{
public:
	CircleAdapter(Point centerCircle, int radius, std::string type = CIRCLE_TYPE);
	double Perimeter() override;
	double Area() override;
	void DrawShape(ICanvas& canvas) override;
	std::string GetType() override;
private:
	Point m_centerCircle;
	int m_radius;
	std::string m_type = CIRCLE_TYPE;

};

