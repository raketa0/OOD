#include "SelectState.h"

SelectState::SelectState(std::unique_ptr<CShapeSelector>& selector, 
	std::unique_ptr<CShapeDraggerMove>& dragger,
	std::optional<sf::Event> event,
	sf::RenderWindow& window)
	: m_selector(selector), 
    m_dragger(dragger),
	m_event(event),
	m_window(window){}

bool SelectState::HandleEvent(Application& app)
{
    if (m_event->is<sf::Event::MouseButtonPressed>())
    {
        return HandleMousePressed();
    }
    if (m_event->is<sf::Event::MouseMoved>())
    {
        return HandleMouseMoved();
    }
    if (m_event->is<sf::Event::MouseButtonReleased>())
    {
        return HandleMouseReleased();
    }
    if (m_event->is<sf::Event::KeyPressed>())
    {
        return HandleKeyPressed();
    }

    return false;
}

bool SelectState::HandleMousePressed()
{
    if (const auto* mouseEvent = m_event->getIf<sf::Event::MouseButtonPressed>())
    {
        if (mouseEvent->button == sf::Mouse::Button::Left)
        {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(m_window);
            bool isShiftPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)
                || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::RShift);
            m_selector->OnClick(mousePosition, isShiftPressed);
            m_dragger->StartDrag(mousePosition);
            return true;
        }
    }
	return false;
}

bool SelectState::HandleMouseMoved()
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition(m_window);
    m_dragger->OnMouseMoved(mousePosition);
	return true;
}

bool SelectState::HandleMouseReleased()
{
    if (const auto* mouseEvent = m_event->getIf<sf::Event::MouseButtonReleased>())
    {
        if (mouseEvent->button == sf::Mouse::Button::Left)
        {
            m_dragger->EndDrag();
            return true;
        }
    }
	return false;
}

bool SelectState::HandleKeyPressed()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl) &&
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::G))
    {
        m_selector->GroupSelectedShapes();
		return true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl) &&
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::U))
    {
        m_selector->UngroupSelectedShape();
		return true;
    }
	return false;
}
