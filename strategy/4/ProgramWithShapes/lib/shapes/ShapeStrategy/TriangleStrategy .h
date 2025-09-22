#pragma once

#include "IShapeStrategy.h"

class TriangleStrategy : public shapes::IShapeStrategy
{
public:
	TriangleStrategy(double x1, double x2, double x3, 
		double y1, double y2, double y3);

	void MoveShape(double dx, double dy) override;
	void DrawShape() const override;
	std::string ToString() const override;
private:
	double m_x1, m_x2, m_x3, m_y1, m_y2, m_y3;
};

