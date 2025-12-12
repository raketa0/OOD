#include "FillState.h"

FillState::FillState(sf::Color fillColor, sf::Color outlineColor, float outlineThickness)
    : m_fillColor(fillColor),
    m_outlineColor(outlineColor), 
    m_outlineThickness(outlineThickness)
{
}

void FillState::OnMouseButtonPressed(sf::Event& event)
{
    if (!event.is<sf::Event::MouseButtonPressed>())
        return;

    const auto* mouseEvent = event.getIf<sf::Event::MouseButtonPressed>();

    if (!mouseEvent || mouseEvent->button != sf::Mouse::Button::Left)
    {
		return;
    }

    sf::Vector2i clickPos = mouseEvent->position;

    for (const auto& [id, shape] : m_composition->GetÑompositionShapes())
    {
        if (shape && shape->IsClick(clickPos))
        {
            m_composition->ChangeFillColor(m_fillColor);
            m_composition->ChangeOutlineColor(m_outlineColor);
            m_composition->ChangeOutlineThickness(m_outlineThickness);
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