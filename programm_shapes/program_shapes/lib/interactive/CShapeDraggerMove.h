#pragma once

#include "../shapes/CÑompositionShapes.h"
#include "CShapeSelector.h"
#include <SFML/Graphics.hpp>
#include <memory>

class CShapeDraggerMove
{
public:
    CShapeDraggerMove(std::shared_ptr<CÑompositionShapes> composition, CShapeSelector& selector);

    void StartDrag(sf::Vector2i& mousePosition);
    void OnMouseMoved(sf::Vector2i& mousePosition);
    void EndDrag();

private:
    std::shared_ptr<CÑompositionShapes> m_composition;
    CShapeSelector& m_selector;
    bool m_isDragging = false;
    sf::Vector2i m_dragOffset;

    void MoveSelectedShapes(int deltaX, int deltaY);
};