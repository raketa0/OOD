#pragma once
#include "IShapeBuilder.h"
#include "../../canvas/ICanvasSFML.h"
class CircleBuilder : public IShapeBuilder 
{
public:
	CircleBuilder(std::shared_ptr<ICanvasSFML> canvas);
	void SetType(std::string& type) override;
	void SetPoints(std::vector<Point>& points) override;
	void SetDimensions(int, int) override {}
	void SetRadius(int radius) override;
	void SetColors(sf::Color& fill, sf::Color& outline) override;
	void SetOutlineThickness(float thickness) override;
	void AddShapeInComposition(std::shared_ptr<CÑompositionShapes> composition) override;
	std::shared_ptr<IShape> CreateShape() override;

private:
	Point m_center;
	int m_radius = ZERO;
	std::string m_type;
	sf::Color m_fill;
	sf::Color m_outline;
	float m_outlineThickness = OUTLINE_THICKNESS;
	std::shared_ptr<ICanvasSFML> m_canvas;
};
