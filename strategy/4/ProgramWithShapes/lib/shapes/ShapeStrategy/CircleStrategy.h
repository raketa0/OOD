#pragma once

#include "IShapeStrategy.h"
namespace shapes
{
	class CircleStrategy : public shapes::IShapeStrategy
	{
	public:
		CircleStrategy(double cx, double cy, double r);
		void MoveShape(double dx, double dy) override;
		void DrawShape(gfx::ICanvas& canvas, gfx::Color& color) const override;
		std::string ToString() const override;

	private:
		double m_cx, m_cy, m_r;
	};
}


