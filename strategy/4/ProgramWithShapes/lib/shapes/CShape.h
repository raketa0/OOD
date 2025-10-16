#pragma once

#include <string>
#include <memory>
#include "ShapeStrategy/IShapeStrategy.h"
#include "../gfx/ICanvas.h"
#include <cassert>

namespace shapes
{
	class CShape
	{
	public:
		CShape(const std::string id, const gfx::Color& color,
			std::unique_ptr<IShapeStrategy>&& shapeStrategy);

		const std::string& GetId() const;
		const gfx::Color& GetColor() const;
		void SetColor(const gfx::Color& newColor);
		void MoveShape(double dx, double dy);
		void DrawShape(gfx::ICanvas& canvas);
		void ChangeShape(std::unique_ptr<IShapeStrategy>&& newShapeStrategy);
		std::string ToString();
		virtual ~CShape() = default;

	private:
		std::string m_id;
		gfx::Color m_color;
		std::unique_ptr<IShapeStrategy> m_shapeStrategy;
	};
};