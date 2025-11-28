#pragma once
#pragma once
#include "IState.h"
#include <memory>
#include "../shapes/CÑompositionShapes.h"
#include "../app/Application.h"

class FillState : public IState 
{
public:
    FillState(std::shared_ptr<CÑompositionShapes> composition,
        std::unique_ptr<CShapeSelector>& selector,
        std::optional<sf::Event> event,
        sf::Color color);

    bool HandleEvent(Application& app) override;

private:
    std::shared_ptr<CÑompositionShapes> m_composition;
    std::unique_ptr<CShapeSelector>& m_selector;
    sf::Color m_fillColor;
	std::optional<sf::Event> m_event;

    bool HandleMousePressed();
};

