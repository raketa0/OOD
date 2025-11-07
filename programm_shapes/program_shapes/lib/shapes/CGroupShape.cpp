#include "CGroupShape.h"

CGroupShape::CGroupShape(std::map<int, std::shared_ptr<IShape>> groupedShapes,
	std::shared_ptr<ICanvasSFML> canvas):
	m_groupedShapes(std::move(groupedShapes)),
	m_canvas(std::move(canvas))
{
	assert(m_canvas);
	assert(!m_groupedShapes.empty());
}

void CGroupShape::Draw()
{
	for (auto& [id, shape] : m_groupedShapes)
	{
		shape->Draw();
	}
}

std::string CGroupShape::GetType()
{
	return GROUP_TYPE;
}

bool CGroupShape::IsSelected()
{
	return m_selected;
}

bool CGroupShape::IsGroup()
{
	return true;
}

void CGroupShape::SetSelected(bool value)
{
	m_selected = value;
}

bool CGroupShape::IsClick(const sf::Vector2i& mousePos)
{
	for (auto& [id, shape] : m_groupedShapes)
	{
		if (shape->IsClick(mousePos))
		{
			return true;
		}
	}
	return false;
}

FrameParameters CGroupShape::CalckSelectionFrameParameters()
{
	FrameParameters frameParams{ {ZERO, ZERO}, ZERO, ZERO };
	bool firstShape = true;
	for (auto& [id, shape] : m_groupedShapes)
	{
		FrameParameters shapeFrame = shape->CalckSelectionFrameParameters();
		if (firstShape)
		{
			frameParams = shapeFrame;
			firstShape = false;
			continue;
		}
		int leftX = std::min(frameParams.topLeftCorner.x, shapeFrame.topLeftCorner.x);
		int topY = std::min(frameParams.topLeftCorner.y, shapeFrame.topLeftCorner.y);
		int rightX = std::max(frameParams.topLeftCorner.x + frameParams.width,
			shapeFrame.topLeftCorner.x + shapeFrame.width);
		int bottomY = std::max(frameParams.topLeftCorner.y + frameParams.height,
			shapeFrame.topLeftCorner.y + shapeFrame.height);
		frameParams.topLeftCorner.x = leftX;
		frameParams.topLeftCorner.y = topY;
		frameParams.width = rightX - leftX;
		frameParams.height = bottomY - topY;
	}
	return frameParams;
}

std::map<int, std::shared_ptr<IShape>> CGroupShape::GetGroupedShapes()
{
	return m_groupedShapes;
}

void CGroupShape::MoveShape(const Point& newPosition)
{
	FrameParameters frameParams = CalckSelectionFrameParameters();
	int deltaX = newPosition.x - frameParams.topLeftCorner.x;
	int deltaY = newPosition.y - frameParams.topLeftCorner.y;
	for (auto& [id, shape] : m_groupedShapes)
	{
		FrameParameters shapeFrame = shape->CalckSelectionFrameParameters();
		Point shapeNewTopLeft(shapeFrame.topLeftCorner.x + deltaX,
			shapeFrame.topLeftCorner.y + deltaY);
		shape->MoveShape(shapeNewTopLeft);
	}
}
