#pragma once
#include"ICommand.h"
#include <string>
#include "../shapes/CPicture.h"


namespace command
{
	class DeleteShapeCommand : public ICommand
	{
	public:
		DeleteShapeCommand(shapes::CPicture& picture,
			const std::string& id):
			m_picture(picture),
			m_id(id){}

		void Execute() override
		{
			m_picture.DeleteShape(m_id);
		}
	private:
		shapes::CPicture& m_picture;
		std::string m_id;
	};

}

