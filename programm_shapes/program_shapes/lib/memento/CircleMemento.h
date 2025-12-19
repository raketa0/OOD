#pragma once
#include "IMementoShapes.h"
#include "../shapes/CircleAdapter.h"
#include <memory>
class CircleMemento : public IMementoShapes
{
public:
	CircleMemento(std::shared_ptr<CircleAdapter> circle, Point center,
		int radius, sf::Color fill, sf::Color outline,
		float thickness, bool selected);
	void Restore() override;
private:
	std::shared_ptr<CircleAdapter> m_circle;
	Point m_center;
	int m_radius;
	sf::Color m_fillColor;
	sf::Color m_outlineColor;
	float m_outlineThickness;
	bool m_isSelected;
};