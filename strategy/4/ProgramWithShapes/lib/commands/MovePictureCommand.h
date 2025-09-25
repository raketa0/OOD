#pragma once
#include"ICommand.h"
#include <string>
#include <memory>
#include "../shapes/CPicture.h"


namespace command
{
	class MovePictureCommand : public ICommand
	{
	public:
		MovePictureCommand(shapes::CPicture& picture, 
			double dx, double dy)
			: m_picture(picture), m_dx(dx), m_dy(dy) {}


		void Execute() override
		{
			m_picture.MovePicture(m_dx, m_dy);
		}
	private:
		shapes::CPicture& m_picture;
		double m_dx, m_dy;
	};
}
