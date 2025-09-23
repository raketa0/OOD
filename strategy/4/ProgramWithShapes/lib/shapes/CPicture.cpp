#include "CPicture.h"


void shapes::CPicture::AddShape(std::shared_ptr<CShape> shape)
{
	m_shapes.push_back(shape);
}

void shapes::CPicture::DeleteShape(std::string id)
{
	m_shapes.erase(
		std::remove_if(m_shapes.begin(), m_shapes.end(),
			[id](auto shape) { return shape->GetId() == id; }),
		m_shapes.end());
}

void shapes::CPicture::MovePicture(double dx, double dy)
{
	for (auto shape : m_shapes)
	{
		shape->MoveShape(dx, dy);
	}
}

void shapes::CPicture::DrawPicture(gfx::ICanvas& canvas)
{
	for (auto shape : m_shapes)
	{
		shape->DrawShape(canvas);
	}
}

std::shared_ptr<shapes::CShape> shapes::CPicture::GetShape(std::string id)
{
	for (auto shape : m_shapes)
	{
		if (shape->GetId() == id)
		{
			return shape;
		}
	}
	return nullptr;
}

void shapes::CPicture::List()
{
}
