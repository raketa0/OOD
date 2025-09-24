#pragma once
#include <SFML/Graphics.hpp>
#include "../gfx/ICanvas.h"
#include "EllipseShape.h"


class CCanvas : public gfx::ICanvas
{
public:
    CCanvas(sf::RenderWindow& window, sf::Vector2f position, sf::Color color) :
        m_window(window), m_currentPosition(position), m_currentColor(color) {
    };
    void MoveTo(double x, double y) override
    {
        m_currentPosition = sf::Vector2f(static_cast<float>(x), static_cast<float>(y));
    }

    void LineTo(double x, double y) override
    {
        sf::Vertex line[] = {
            sf::Vertex{{m_currentPosition}, m_currentColor},
            sf::Vertex{sf::Vector2f({static_cast<float>(x), static_cast<float>(y)}), {m_currentColor}}
        };
        m_window.draw(line, 2, sf::PrimitiveType::Lines);
        m_currentPosition = sf::Vector2f(static_cast<float>(x), static_cast<float>(y));
    }

    void SetColor(const gfx::Color& c) override
    {
        m_currentColor = sf::Color(c.r, c.g, c.b, 255);
    }

    void DrawEllipse(double cx, double cy, double rx, double ry) override
    {
        EllipseShape ellipse({ static_cast<float>(rx), static_cast<float>(ry) });
        ellipse.setPosition({ static_cast<float>(cx), static_cast<float>(cy) });
        ellipse.setFillColor(m_currentColor);
        m_window.draw(ellipse);
    }

    void DrawText(double left, double top, double fontSize, const std::string& text) override
    {
        const sf::Font font("arial.ttf");
        sf::Text sfText(font);
        sfText.setString(text);
        sfText.setCharacterSize(fontSize);
        sfText.setFillColor(m_currentColor);
        sfText.setPosition({ static_cast<float>(left), static_cast<float>(top) });
        m_window.draw(sfText);
    }

private:
    sf::RenderWindow& m_window;
    sf::Vector2f m_currentPosition;
    sf::Color m_currentColor;
};