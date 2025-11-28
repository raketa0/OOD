#include "CCanvasSFML.h"


CCanvasSFML::CCanvasSFML(sf::RenderWindow& window): m_window(window) {}

void CCanvasSFML::DrawCircle(Point centerCircle, int radius,
	sf::Color fillColor,
	sf::Color outlineColor,
	float outlineThickness
    )
{
    sf::CircleShape circle(radius);
    circle.setPosition(sf::Vector2f(centerCircle.x - radius, centerCircle.y - radius));
    circle.setFillColor(fillColor);
    circle.setOutlineThickness(outlineThickness);
    circle.setOutlineColor(outlineColor);
	m_window.draw(circle);
}

void CCanvasSFML::DrawRectangle(Point leftTopCorner, int width, int height,
	sf::Color fillColor,
	sf::Color outlineColor,
	float outlineThickness,
	bool useFill
    )
{
    sf::RectangleShape rectangle(sf::Vector2f(width, height));
    rectangle.setPosition(sf::Vector2f(leftTopCorner.x, leftTopCorner.y));
    if (useFill)
    {
        rectangle.setFillColor(fillColor);
    }
    else
    {
        rectangle.setFillColor(sf::Color::Transparent);
    }
    rectangle.setOutlineThickness(outlineThickness);
    rectangle.setOutlineColor(outlineColor);
	m_window.draw(rectangle);
}

void CCanvasSFML::DrawTriangle(Point firstPoint, Point secondPoint, Point thirdPoint,
    sf::Color fillColor,
    sf::Color outlineColor,
	float outlineThickness
)
{
    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(firstPoint.x, firstPoint.y));
    triangle.setPoint(1, sf::Vector2f(secondPoint.x, secondPoint.y));
    triangle.setPoint(2, sf::Vector2f(thirdPoint.x, thirdPoint.y));
    triangle.setFillColor(fillColor);
    triangle.setOutlineThickness(outlineThickness);
    triangle.setOutlineColor(outlineColor);
    m_window.draw(triangle);
}
