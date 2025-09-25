#pragma once

#include "IShapeStrategy.h"

namespace shapes
{
	class LineStrategy : public shapes::IShapeStrategy
	{
	public:
		LineStrategy(double x1, double x2, double y1, double y2);

		void MoveShape(double dx, double dy) override;
		void DrawShape(gfx::ICanvas& canvas, gfx::Color& color) const override;
		std::string ToString() const override;
	private:
		double m_x1, m_x2, m_y1, m_y2;
	};


}
