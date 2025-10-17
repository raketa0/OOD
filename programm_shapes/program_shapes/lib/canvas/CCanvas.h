#pragma once
#include "ICanvas.h"
#include <SFML/Graphics.hpp>
#include "../tools/ShapesStruct.h"

class CCanvas : public ICanvas
{
public:
	CCanvas(sf::RenderWindow& window);
	void drawCircle(Circle circ) override;
	void drawRectangle(Rectangle rect) override;
	void drawTriangle(Triangle triang) override;
private:
	sf::RenderWindow& m_window;
};

