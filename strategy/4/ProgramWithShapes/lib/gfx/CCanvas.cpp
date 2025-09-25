#include"CCanvas.h"

gfx::CCanvas::CCanvas(sf::RenderWindow& window, 
    sf::Vector2f position, sf::Color color) :
    m_window(window), 
    m_currentPosition(position), 
    m_currentColor(color) {}

void gfx::CCanvas::MoveTo(double x, double y)
{
    m_currentPosition = sf::Vector2f(static_cast<float>(x), static_cast<float>(y));
}

void gfx::CCanvas::LineTo(double x, double y)
{
    sf::Vertex line[] = {
        sf::Vertex{{m_currentPosition}, m_currentColor},
        sf::Vertex{sf::Vector2f({static_cast<float>(x), static_cast<float>(y)}), {m_currentColor}}
    };
    m_window.draw(line, 2, sf::PrimitiveType::Lines);
    m_currentPosition = sf::Vector2f(static_cast<float>(x), static_cast<float>(y));
}

void gfx::CCanvas::SetColor(const gfx::Color& c)
{
    m_currentColor = sf::Color(c.r, c.g, c.b, 255);
}

void gfx::CCanvas::DrawEllipse(double cx, double cy, double rx, double ry)
{
    EllipseShape ellipse({ static_cast<float>(rx), static_cast<float>(ry) });
    ellipse.setPosition({ static_cast<float>(cx), static_cast<float>(cy) });
    ellipse.setFillColor(m_currentColor);
    m_window.draw(ellipse);
}

void gfx::CCanvas::DrawText(double left, double top, double fontSize, const std::string& text)
{
    const sf::Font font("arial.ttf");
    sf::Text sfText(font);
    sfText.setString(text);
    sfText.setCharacterSize(fontSize);
    sfText.setFillColor(m_currentColor);
    sfText.setPosition({ static_cast<float>(left), static_cast<float>(top) });
    m_window.draw(sfText);
}