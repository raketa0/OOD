#pragma once
#include"ICommand.h"
#include <string>
#include "../shapes/CPicture.h"


namespace command
{
	class ChangeColorCommand : public ICommand
	{
	public:
		ChangeColorCommand(shapes::CPicture& picture,
			const std::string& id,
			const gfx::Color& color)
			: m_picture(picture), m_id(id), m_color(color) {}

		void Execute() override
		{
			auto shape = m_picture.GetShape(m_id);
			if (shape) 
			{
				shape->SetColor(m_color);
			}
		}

	private:
		shapes::CPicture& m_picture;
		std::string m_id;
		gfx::Color m_color;

	};
}


