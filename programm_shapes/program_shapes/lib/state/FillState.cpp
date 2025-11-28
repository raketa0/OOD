#include "FillState.h"

FillState::FillState(std::shared_ptr<CÑompositionShapes> composition,
	std::unique_ptr<CShapeSelector>& selector, 
	std::optional<sf::Event> event, 
	sf::Color color)
	: m_composition(composition), 
	m_selector(selector), 
	m_event(event), 
	m_fillColor(color)
{
}

bool FillState::HandleEvent(Application& app)
{
	if (m_event->is<sf::Event::MouseButtonPressed>())
	{
		return HandleMousePressed();
	}
	return false;
}

bool FillState::HandleMousePressed()
{
	if (const auto* mouseEvent = m_event->getIf<sf::Event::MouseButtonPressed>())
	{
		if (mouseEvent->button == sf::Mouse::Button::Left)
		{
			sf::Vector2i mousePosition = sf::Mouse::getPosition(app.GetApp().m_window->get());
			m_composition->FillShapesAtPoint(mousePosition, m_fillColor);
			return true;
		}
	}
	return false;
}
