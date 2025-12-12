#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "../commands/ICommand.h"
class Button
{
public:
    Button(sf::Vector2f& size,
        sf::Vector2f& position,
        std::string& label,
        std::shared_ptr<ICommand> command);

    void Draw(sf::RenderWindow& window);
    bool Contains(sf::Vector2f& point);

    void SetActive(bool active);
    bool IsActive();

    void Execute();

private:
    void SetupShape(sf::Vector2f& size, sf::Vector2f& position);
    sf::Text SetupText(std::string& label, sf::Vector2f& size, sf::Vector2f& position);
    sf::RectangleShape m_rect;
    std::shared_ptr<ICommand> m_command;
	sf::Vector2f m_size;
	sf::Vector2f m_position;
	std::string m_label;
    bool m_isActive = false;
    sf::Font m_font;
    sf::Text m_text = SetupText(m_label, m_size, m_position);

};
