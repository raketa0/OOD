#include "CShapeDraggerMove.h"

CShapeDraggerMove::CShapeDraggerMove(std::shared_ptr<CÑompositionShapes> composition,
	CShapeSelector& selector):
	m_composition(std::move(composition)),
	m_selector(selector)
{
	assert(m_composition);
	assert(&m_selector);
}

void CShapeDraggerMove::StartDrag(sf::Vector2i& mousePosition)
{
	if (m_composition->GetSelectedShapes().empty())
	{
		return;
	}

	m_isDragging = true;
	m_dragOffset = mousePosition; 
}

void CShapeDraggerMove::OnMouseMoved(sf::Vector2i& mousePosition)
{
	if (!m_isDragging)
	{
		return;
	}
	int deltaX = mousePosition.x - m_dragOffset.x;
	int deltaY = mousePosition.y - m_dragOffset.y;
	MoveSelectedShapes(deltaX, deltaY);
	m_dragOffset = mousePosition;
}

void CShapeDraggerMove::EndDrag()
{
	m_isDragging = false;
}

void CShapeDraggerMove::MoveSelectedShapes(int deltaX, int deltaY)
{
	auto selectedShapes = m_composition->GetSelectedShapes();
	for (auto& [id, shape] : selectedShapes)
	{
		FrameParameters frameParams = shape->CalckSelectionFrameParameters();
		Point newTopLeft(frameParams.topLeftCorner.x + deltaX,
		frameParams.topLeftCorner.y + deltaY);
		shape->MoveShape(newTopLeft);

	}
}
