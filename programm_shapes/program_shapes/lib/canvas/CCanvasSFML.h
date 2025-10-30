#pragma once
#include "ICanvasSFML.h"

class CCanvasSFML : public ICanvasSFML
{
public:
	CCanvasSFML(sf::RenderWindow& window);
	void DrawCircle(Point centerCircle, int radius) override;
	void DrawRectangle(Point leftTopCorner, int width, int height) override;
	void DrawTriangle(Point firstPoint, Point secondPoint, Point thirdPoint) override;
private:
	sf::RenderWindow& m_window;
};

