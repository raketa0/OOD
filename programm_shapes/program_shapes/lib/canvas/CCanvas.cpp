#include "CCanvas.h"


CCanvas::CCanvas(sf::RenderWindow& window): m_window(window) {}

void CCanvas::drawCircle(Point centerCircle, int radius)
{
	sf::CircleShape circle(radius);
	circle.setPosition(sf::Vector2f(centerCircle.x - radius, centerCircle.y - radius));
	circle.setOutlineThickness(4.f);
	circle.setOutlineColor(sf::Color::White);
	circle.setFillColor(sf::Color::Transparent);
	m_window.draw(circle);
}

void CCanvas::drawRectangle(Point leftTopCorner, int width, int height)
{
    sf::RectangleShape rectangle(sf::Vector2f(width, height));
    rectangle.setPosition(sf::Vector2f(leftTopCorner.x, leftTopCorner.y));
    rectangle.setOutlineThickness(4.f);
    rectangle.setOutlineColor(sf::Color::White);
    rectangle.setFillColor(sf::Color::Transparent);
    m_window.draw(rectangle);
}

void CCanvas::drawTriangle(Point firstPoint, Point secondPoint, Point thirdPoint)
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
