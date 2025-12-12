#include "CButton.h"


Button::Button(sf::Vector2f& size,
    sf::Vector2f& position,
    std::string& label,
    std::shared_ptr<ICommand> command)
    : m_size(size),
	m_position(position),
	m_label(label),
    m_command(std::move(command))
{
    SetupShape(size, position);
    SetupText(label, size, position);
}

void Button::SetupShape(sf::Vector2f& size, sf::Vector2f& position)
{
    m_rect.setSize(size);
    m_rect.setPosition(position);
    m_rect.setFillColor(sf::Color(200, 200, 200));
    m_rect.setOutlineThickness(1.f);
    m_rect.setOutlineColor(sf::Color::Black);
}


sf::Text Button::SetupText(std::string& label, sf::Vector2f& size, sf::Vector2f& position)
{
    m_font.openFromFile("Arial.ttf");
    sf::Text text = sf::Text(m_font, label, 14);
    text.setFillColor(sf::Color::Black);

    sf::FloatRect bounds = text.getLocalBounds();
    float x = m_position.x + 8.f;
    float y = m_position.y + (m_size.y - bounds.size.y) / 2.0f - bounds.position.y;

    text.setPosition(sf::Vector2f(x, y)); 

    return text;
}

void Button::Draw(sf::RenderWindow& window)
{
    m_rect.setOutlineColor(m_isActive ? sf::Color::Red : sf::Color::Black);
    window.draw(m_rect);
    window.draw(m_text);
}

bool Button::Contains(sf::Vector2f& point)
{
    return m_rect.getGlobalBounds().contains(point);
}

void Button::SetActive(bool active)
{
    m_isActive = active;
}

bool Button::IsActive()
{
    return m_isActive;
}

void Button::Execute()
{
    if (m_command)
    {
        m_command->Execute();
    }
}
