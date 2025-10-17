#pragma once
#include "IShape.h"
#include "../canvas/ICanvas.h"
#include "../tools/ShapesStruct.h"
#include "../tools/Constants.h"



class CircleAdapter : public IShape
{
public:
	CircleAdapter(Circle circle);
	double Perimeter() override;
	double Area() override;
	void DrawShape(ICanvas& canvas) override;
	std::string GetType() override;
private:
	Circle m_circle;

};

