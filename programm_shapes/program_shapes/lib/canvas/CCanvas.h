#pragma once
#include "ICanvas.h"
#include <SFML/Graphics.hpp>

class CCanvas : public ICanvas
{
public:
	CCanvas(sf::RenderWindow& window);
	void drawCircle(Point centerCircle, int radius) override;
	void drawRectangle(Point leftTopCorner, int width, int	height) override;
	void drawTriangle(Point firstPoint, Point secondPoint, Point thirdPoint) override;
private:
	sf::RenderWindow& m_window;
};

