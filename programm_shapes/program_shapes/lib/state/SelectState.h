#pragma once
#include <memory>
#include "../app/Application.h"
#include "../interactive/CShapeSelector.h"
#include "../interactive/CShapeDraggerMove.h"
#include "IState.h"

class SelectState : public IState 
{
 public:
    SelectState(std::unique_ptr<CShapeSelector>& selector,
        std::unique_ptr<CShapeDraggerMove>& dragger,
        std::optional<sf::Event> event,
        sf::RenderWindow& window);

    bool HandleEvent(Application& app) override;

private:
    std::unique_ptr<CShapeSelector>& m_selector;
    std::unique_ptr<CShapeDraggerMove>& m_dragger;
	std::optional<sf::Event> m_event;
	sf::RenderWindow& m_window;

    bool HandleMousePressed();
    bool HandleMouseMoved();
    bool HandleMouseReleased();
    bool HandleKeyPressed();
};
