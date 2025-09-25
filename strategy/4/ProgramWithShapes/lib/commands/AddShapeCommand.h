#pragma once
#include"ICommand.h"
#include <string>
#include <memory>
#include "../shapes/CPicture.h"

namespace command
{
	class AddShapeCommand : public ICommand
	{
	public:
		AddShapeCommand(shapes::CPicture& picture,
			const std::string id,
			gfx::Color& color,
			std::unique_ptr<shapes::IShapeStrategy>&& shapeStrategy)
			: m_picture(picture),
			m_id(id),
			m_color(color),
			m_shapeStrategy(std::move(shapeStrategy)) {
		}


		void Execute() override
		{
			auto shape = std::make_shared<shapes::CShape>(m_id,
				m_color,
				std::move(m_shapeStrategy));
			m_picture.AddShape(shape);
		}
	private:
		shapes::CPicture& m_picture;
		std::string m_id;
		gfx::Color m_color;
		std::unique_ptr<shapes::IShapeStrategy>&& m_shapeStrategy;
	};
}


