#include "SelectState.h"
#include "../../app/Application.h"



void SelectState::OnMouseButtonPressed(sf::Event& event)
{
    if (event.is<sf::Event::MouseButtonPressed>())
    {
        const auto* mouse = event.getIf<sf::Event::MouseButtonPressed>();
        if (mouse && mouse->button == sf::Mouse::Button::Left)
        {
            sf::Vector2i pos = mouse->position;

            bool shiftPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift) ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Key::RShift);

            m_aplication.GetSelector()->OnClick(pos, shiftPressed);
            m_aplication.GetDragger()->StartDrag(pos);
        }
    }
}

void SelectState::OnMouseMoved(sf::Event& event)
{
    if (event.is<sf::Event::MouseMoved>())
    {
        const auto* move = event.getIf<sf::Event::MouseMoved>();
        if (move)
        {
            m_aplication.GetDragger()->OnMouseMoved(move->position);
        }
    }
}

void SelectState::OnMouseButtonReleased(sf::Event& event)
{
    if (event.is<sf::Event::MouseButtonReleased>())
    {
        const auto* mouse = event.getIf<sf::Event::MouseButtonReleased>();
        if (mouse && mouse->button == sf::Mouse::Button::Left)
        {
            m_aplication.GetDragger()->EndDrag();
        }
    }
}

void SelectState::OnKeyPressed(sf::Event& event)
{
    if (event.is<sf::Event::KeyPressed>())
    {
        bool ctrlPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Key::RControl);

        const auto* key = event.getIf<sf::Event::KeyPressed>();

        if (ctrlPressed && key && key->code == sf::Keyboard::Key::G)
        {
            m_aplication.GetSelector()->GroupSelectedShapes();
        }
        else if (ctrlPressed && key && key->code == sf::Keyboard::Key::U)
        {
            m_aplication.GetSelector()->UngroupSelectedShape();
        }
    }
}

void SelectState::HandleEvent(sf::Event& event)
{
    if (event.is<sf::Event::Closed>())
    {
        m_aplication.GetWindow().close();
    }
    else if (event.is<sf::Event::MouseButtonPressed>())
    {
        OnMouseButtonPressed(event);
    }
    else if (event.is<sf::Event::MouseMoved>())
    {
        OnMouseMoved(event);
    }
    else if (event.is<sf::Event::MouseButtonReleased>())
    {
        OnMouseButtonReleased(event);
    }
    else if (event.is<sf::Event::KeyPressed>())
    {
        OnKeyPressed(event);
    }
}