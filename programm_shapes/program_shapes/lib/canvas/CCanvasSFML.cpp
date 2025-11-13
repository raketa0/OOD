#include "CCanvasSFML.h"


CCanvasSFML::CCanvasSFML(sf::RenderWindow& window): m_window(window) {}

void CCanvasSFML::DrawCircle(Point centerCircle, int radius)
{
	sf::CircleShape circle(radius);
	circle.setPosition(sf::Vector2f(centerCircle.x - radius, centerCircle.y - radius));
	circle.setOutlineThickness(4.f);
	circle.setOutlineColor(sf::Color::White);
	circle.setFillColor(sf::Color::Transparent);
	m_window.draw(circle);
}

void CCanvasSFML::DrawRectangle(Point leftTopCorner, int width, int height,
    float outlineThickness,
    sf::Color outlineColor,
    bool useFill)
{
    sf::RectangleShape rectangle(sf::Vector2f(width, height));
    rectangle.setPosition(sf::Vector2f(leftTopCorner.x, leftTopCorner.y));
    rectangle.setOutlineThickness(outlineThickness);
    rectangle.setOutlineColor(outlineColor);

    if (useFill) {
        rectangle.setFillColor(outlineColor);
    }
    else {
        rectangle.setFillColor(sf::Color::Transparent);
    }

    m_window.draw(rectangle);
}

void CCanvasSFML::DrawTriangle(Point firstPoint, Point secondPoint, Point thirdPoint)
{
    sf::ConvexShape triangle(3);
    triangle.setPoint(0, sf::Vector2f(firstPoint.x, firstPoint.y));
    triangle.setPoint(1, sf::Vector2f(secondPoint.x, secondPoint.y));
    triangle.setPoint(2, sf::Vector2f(thirdPoint.x, thirdPoint.y));
    triangle.setOutlineThickness(4.f);
    triangle.setOutlineColor(sf::Color::White);
    triangle.setFillColor(sf::Color::Transparent);
    m_window.draw(triangle);
}
