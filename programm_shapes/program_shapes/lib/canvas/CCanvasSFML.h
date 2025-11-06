#pragma once
#include "ICanvasSFML.h"

class CCanvasSFML : public ICanvasSFML
{
public:
	CCanvasSFML(sf::RenderWindow& window);
	void drawCircle(Point centerCircle, int radius) override;
	void drawRectangle(Point leftTopCorner, int width, int height,
		float outlineThickness,
		sf::Color outlineColor,
		bool useFill) override;
	void drawTriangle(Point firstPoint, Point secondPoint, Point thirdPoint) override;
private:
	sf::RenderWindow& m_window;
};

