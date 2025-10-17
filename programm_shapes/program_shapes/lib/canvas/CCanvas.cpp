#include "CCanvas.h"


CCanvas::CCanvas(sf::RenderWindow& window): m_window(window) {}


void CCanvas::drawCircle(Circle circ)
{
	sf::CircleShape circle(circ.radius);
        circle.setPosition(sf::Vector2f(circ.centerCircle.x - circ.radius, circ.centerCircle.y - circ.radius));
        circle.setOutlineThickness(4.f);
        circle.setOutlineColor(sf::Color::White);
        circle.setFillColor(sf::Color::Transparent);
        m_window.draw(circle);
}

void CCanvas::drawRectangle(Rectangle rect)
{
    sf::RectangleShape rectangle(sf::Vector2f(rect.width,
        rect.height));
    rectangle.setPosition(sf::Vector2f(rect.leftTopCorner.x, rect.leftTopCorner.y));
    rectangle.setOutlineThickness(4.f);
    rectangle.setOutlineColor(sf::Color::White);
    rectangle.setFillColor(sf::Color::Transparent);
    m_window.draw(rectangle);
}

void CCanvas::drawTriangle(Triangle triang)
{
    sf::ConvexShape triangle(3);
    triangle.setPoint(0, sf::Vector2f(triang.firstPoint.x, triang.firstPoint.y));
    triangle.setPoint(1, sf::Vector2f(triang.secondPoint.x, triang.secondPoint.y));
    triangle.setPoint(2, sf::Vector2f(triang.thirdPoint.x, triang.thirdPoint.y));
    triangle.setOutlineThickness(4.f);
    triangle.setOutlineColor(sf::Color::White);
    triangle.setFillColor(sf::Color::Transparent);
    m_window.draw(triangle);
}
