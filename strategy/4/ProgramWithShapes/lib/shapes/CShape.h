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
		CShape(const std::string id,
			const gfx::Color& color,
			std::unique_ptr<IShapeStrategy>&& shapeStrategy):
			m_id (id),
			m_shapeStrategy(std::move(shapeStrategy)),
			m_color(color)
		{
			assert(m_shapeStrategy);
		}

		const std::string& GetId() const
		{
			return m_id;
		}
		const gfx::Color& GetColor() const
		{
			return m_color;
		}
	
		void SetColor(const gfx::Color& newColor)
		{
			m_color = newColor;
		}

		void MoveShape(double dx, double dy)
		{
			m_shapeStrategy->MoveShape(dx, dy);
		}

		void DrawShape(gfx::ICanvas& canvas)
		{
			m_shapeStrategy->DrawShape();
		}

		void ChangeShape(std::unique_ptr<IShapeStrategy>&& newShapeStrategy)
		{
			assert(newShapeStrategy);
			m_shapeStrategy = std::move(newShapeStrategy);
		}

		std::string ToString()
		{
			m_shapeStrategy->ToString();
		}

		virtual ~CShape() = default;

	private:
		std::string m_id;
		gfx::Color m_color;
		std::unique_ptr<IShapeStrategy>&& m_shapeStrategy;
	};

};