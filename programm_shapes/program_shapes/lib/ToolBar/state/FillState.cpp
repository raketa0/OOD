#include "FillState.h"
#include "../../visitor/FillColorVisitor.h"
#include "../../visitor/OutlineColorVisitor.h"
#include "../../visitor/OutlineThicknessVisitor.h"

FillState::FillState(sf::Color fillColor, sf::Color outlineColor, float outlineThickness)
    : m_fillColor(fillColor), m_outlineColor(outlineColor), m_outlineThickness(outlineThickness) {}

void FillState::OnMouseButtonPressed(sf::Event& event)
{
    if (!event.is<sf::Event::MouseButtonPressed>()) return;

    const auto* mouseEvent = event.getIf<sf::Event::MouseButtonPressed>();
    if (!mouseEvent || mouseEvent->button != sf::Mouse::Button::Left) return;

    sf::Vector2i clickPos = mouseEvent->position;

    for (const auto& [id, shape] : m_composition->GetÑompositionShapes())
    {
        if (shape && shape->IsClick(clickPos))
        {
            sf::Color fillColor = m_app.GetComposition()->GetFillColor();
            sf::Color outlineColor = m_app.GetComposition()->GetOutlineColor();
            float outlineThinkess = m_app.GetComposition()->GetOutlineThickness();
            FillColorVisitor fillColorVisitor(fillColor);
            OutlineColorVisitor outlineColorVisitor(outlineColor);
            OutlineThicknessVisitor outlineThicknessVisitor(outlineThinkess);
            m_composition->ApplyVisitorToClickedShape(clickPos, outlineThicknessVisitor);
            m_composition->ApplyVisitorToClickedShape(clickPos, outlineColorVisitor);
            m_composition->ApplyVisitorToClickedShape(clickPos, fillColorVisitor);
            break;
        }
    }
}

void FillState::OnMouseMoved(sf::Event&) {}
void FillState::OnKeyPressed(sf::Event&) {}
void FillState::OnMouseButtonReleased(sf::Event&) {}

void FillState::HandleEvent(sf::Event& event)
{
    if (event.is<sf::Event::Closed>())
    {
        m_app.GetWindow().close();
    }
    else if (event.is<sf::Event::MouseButtonPressed>())
    {
        OnMouseButtonPressed(event);
    }
}