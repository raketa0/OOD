#pragma once

#include "IShapeStrategy.h"

class LineStrategy : public shapes::IShapeStrategy
{
public:
	LineStrategy(double x1, double x2, double y1, double y2);

	void MoveShape(double dx, double dy) override;
	void DrawShape() const override;
	std::string ToString() const override;
private:
	double m_x1, m_x2, m_y1, m_y2;
};

