#include "CShapeSelector.h"
#include "../tools/Parser.h"
#include "../tools/ShapesStruct.h"


CShapeSelector::CShapeSelector(std::shared_ptr<CÑompositionShapes> composition,
    std::shared_ptr<CCanvasSFML> canvas)
	: m_composition(composition), m_canvas(std::move(canvas)),
	m_selectedShape(nullptr), m_selectionFrameParameters({ {0,0}, 0, 0 })
{
    assert(m_canvas);
}

void CShapeSelector::OnClick(sf::Vector2i& mousePos)
{
    IsClickInsideShape(mousePos);
}

void CShapeSelector::DrawSelection()
{
    if (m_selectedShape == nullptr)
    {
        return;
    }

    Point topLeft(m_selectionFrameParameters.topLeftCorner.x, 
        m_selectionFrameParameters.topLeftCorner.y);

    Point topRight(m_selectionFrameParameters.topLeftCorner.x + m_selectionFrameParameters.width,
        m_selectionFrameParameters.topLeftCorner.y);

    Point bottomLeft(m_selectionFrameParameters.topLeftCorner.x,
        m_selectionFrameParameters.topLeftCorner.y + m_selectionFrameParameters.height);

    Point bottomRight(m_selectionFrameParameters.topLeftCorner.x + m_selectionFrameParameters.width,
        m_selectionFrameParameters.topLeftCorner.y + m_selectionFrameParameters.height);

    m_canvas->drawRectangle(m_selectionFrameParameters.topLeftCorner, 
        m_selectionFrameParameters.width, m_selectionFrameParameters.height,
        1.0f, sf::Color::Yellow, false);

    m_canvas->drawRectangle(topLeft, 5.0f, 5.0f, 
        1.0f, sf::Color::Green, true);

    m_canvas->drawRectangle(topRight, 5.0f, 5.0f, 
        1.0f, sf::Color::Green, true);

    m_canvas->drawRectangle(bottomLeft, 5.0f, 5.0f, 
        1.0f, sf::Color::Green, true);

    m_canvas->drawRectangle(bottomRight, 5.0f, 5.0f, 
        1.0f, sf::Color::Green, true);
}

void CShapeSelector::IsClickInsideShape(sf::Vector2i& mousePos)
{
	Parser parser;
	for (auto& [id, shape] : m_composition->GetÑompositionShapes())
	{
		if (shape->IsClick(mousePos))
		{
			m_selectedShape = shape;
			m_selectionFrameParameters = shape->CalckSelectionFrameParameters();
		}
	}
}
