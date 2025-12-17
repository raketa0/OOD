#pragma once
#include "IState.h"
#include "../../app/Application.h"
#include "../../shapes/CÑompositionShapes.h"

class FillState : public IState
{
public:
    FillState(sf::Color fillColor, sf::Color outlineColor, float outlineThickness);

    void OnMouseButtonPressed(sf::Event& event) override;
    void OnMouseMoved(sf::Event& event) override;
    void OnKeyPressed(sf::Event& event) override;
    void OnMouseButtonReleased(sf::Event& event) override;
    void HandleEvent(sf::Event& event) override;

private:
    Application& m_app = Application::GetApp();
    std::shared_ptr<CÑompositionShapes> m_composition = m_app.GetComposition();
    sf::Color m_fillColor;
    sf::Color m_outlineColor;
    float m_outlineThickness;
};