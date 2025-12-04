#pragma once
#include "ICanvasSFML.h"

class CCanvasSFML : public ICanvasSFML
{
public:
	CCanvasSFML(sf::RenderWindow& window);
	void DrawCircle(Point centerCircle, int radius,
		sf::Color fillColor,
		sf::Color outlineColor,
		float outlineThickness
	) override;
	void DrawRectangle(Point leftTopCorner, int width, int height,
		sf::Color fillColor,
		sf::Color outlineColor,
		float outlineThickness,
		bool useFill) override;

	void DrawTriangle(Point firstPoint, Point secondPoint, Point thirdPoint,
		sf::Color fillColor,
		sf::Color outlineColor,
		float outlineThickness) override;
private:
	sf::RenderWindow& m_window;
};

