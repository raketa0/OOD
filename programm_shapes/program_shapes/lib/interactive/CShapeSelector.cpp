#include "CShapeSelector.h"
#include "../tools/Parser.h"
#include "../tools/ShapesStruct.h"
#include "../shapes/CGroupShape.h"


CShapeSelector::CShapeSelector(std::shared_ptr<CÑompositionShapes> composition,
    std::shared_ptr<CCanvasSFML> canvas)
	: m_composition(composition), m_canvas(std::move(canvas)),
	m_selectionFrameParameters({ {ZERO,ZERO}, ZERO, ZERO })
{
    assert(m_canvas);
}

void CShapeSelector::OnClick(sf::Vector2i& mousePos, bool isShiftPressed)
{
    if (!isShiftPressed)
    {
        for (auto& [id, shape] : m_composition->GetÑompositionShapes())
        {
            shape->SetSelected(false);
        }
    }

    for (auto& [id, shape] : m_composition->GetÑompositionShapes())
    {
        if ((isShiftPressed) && (shape->IsClick(mousePos)))
        {
			shape->SetSelected(true);
        }
        else if (shape->IsClick(mousePos))
        {
            shape->SetSelected(true);
            break;
        }
    }
}

void CShapeSelector::DrawSelection()
{
    auto selectedShapes = m_composition->GetSelectedShapes();
    if (selectedShapes.empty())
    {
        return;
    }
    else
    {
        for (auto& [id, shape] : selectedShapes)
        {
            m_selectionFrameParameters = shape->CalckSelectionFrameParameters();

            Point topLeft(m_selectionFrameParameters.topLeftCorner.x,
                m_selectionFrameParameters.topLeftCorner.y);

            Point topRight(m_selectionFrameParameters.topLeftCorner.x + m_selectionFrameParameters.width,
                m_selectionFrameParameters.topLeftCorner.y);

            Point bottomLeft(m_selectionFrameParameters.topLeftCorner.x,
                m_selectionFrameParameters.topLeftCorner.y + m_selectionFrameParameters.height);

            Point bottomRight(m_selectionFrameParameters.topLeftCorner.x + m_selectionFrameParameters.width,
                m_selectionFrameParameters.topLeftCorner.y + m_selectionFrameParameters.height);
            
            m_canvas->DrawRectangle(m_selectionFrameParameters.topLeftCorner,
                m_selectionFrameParameters.width, m_selectionFrameParameters.height,
                OUTLINE_THINCENSS, sf::Color::Yellow, false);

            m_canvas->DrawRectangle(topLeft, SIDE_OF_THE_SQUARE, SIDE_OF_THE_SQUARE,
                OUTLINE_THINCENSS, sf::Color::Green, true);

            m_canvas->DrawRectangle(topRight, SIDE_OF_THE_SQUARE, SIDE_OF_THE_SQUARE,
                OUTLINE_THINCENSS, sf::Color::Green, true);

            m_canvas->DrawRectangle(bottomLeft, SIDE_OF_THE_SQUARE, SIDE_OF_THE_SQUARE,
                OUTLINE_THINCENSS, sf::Color::Green, true);

            m_canvas->DrawRectangle(bottomRight, SIDE_OF_THE_SQUARE, SIDE_OF_THE_SQUARE,
                OUTLINE_THINCENSS, sf::Color::Green, true);
        }
    }
}

void CShapeSelector::GroupSelectedShapes()
{
    auto selected = m_composition->GetSelectedShapes();
    if (selected.size() < SECOND)
        return;

    auto group = std::make_shared<CGroupShape>(selected, m_canvas);

    for (auto& [id, shape] : selected)
    {
        m_composition->RemoveShapeById(id);
    }

    m_composition->AddShape(group);
}

void CShapeSelector::UngroupSelectedShape()
{
    auto selected = m_composition->GetSelectedShapes();

    for (auto& [id, shape] : selected)
    {
        if (shape->IsGroup())
        {
            auto groupShapes = shape->GetGroupedShapes();
            for (auto& [innerId, innerShape] : groupShapes)
            {
                m_composition->AddShape(innerShape);
            }
            m_composition->RemoveShapeById(id);
        }
    }
}

