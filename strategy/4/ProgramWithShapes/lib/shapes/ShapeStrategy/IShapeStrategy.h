#pragma once

#include <string>
#include "../../gfx/ICanvas.h"

namespace shapes 
{
	class IShapeStrategy
	{
	public:
	
		virtual ~IShapeStrategy(){};
		virtual void MoveShape(double dx, double dy) = 0;
		virtual void DrawShape(gfx::ICanvas& canvas) const = 0;
		virtual std::string ToString() const = 0;

	};
}
