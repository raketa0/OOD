#pragma once

#include "IShapeStrategy.h"

class RectangleStrategy : public shapes::IShapeStrategy
{
public:
	RectangleStrategy(double lift, double top, 
		double width, double height);

	void MoveShape(double dx, double dy) override;
	void DrawShape(gfx::ICanvas& canvas) const override;
	std::string ToString() const override;

private:
	double m_left, m_top, m_width, m_height;
};

