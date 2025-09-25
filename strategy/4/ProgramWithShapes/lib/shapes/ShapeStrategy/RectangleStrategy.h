#pragma once

#include "IShapeStrategy.h"

namespace shapes
{
	class RectangleStrategy : public shapes::IShapeStrategy
	{
	public:
		RectangleStrategy(double left, double top, 
			double width, double height);

		void MoveShape(double dx, double dy) override;
		void DrawShape(gfx::ICanvas& canvas, gfx::Color& color) const override;
		std::string ToString() const override;

	private:
		double m_left, m_top, m_width, m_height;
	};
}


