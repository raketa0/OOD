#pragma once

#include "IShapeStrategy.h"

class CircleStrategy : public shapes::IShapeStrategy
{
public:
	CircleStrategy(double cx, double cy, double r);
	void MoveShape(double dx, double dy) override;
	void DrawShape() const override;
	std::string ToString() const override;

private:
	double m_cx, m_cy, m_r;
};

