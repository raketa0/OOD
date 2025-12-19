#pragma once
#include "IShape.h"
#include "../canvas/ICanvasSFML.h"
#include <cmath>
#include "../tools/ShapesStruct.h"
#include <memory>
#include <string>

class TriangleAdapter : public IShape
{
public:
	TriangleAdapter(Point firstPoint,
		Point secondPoint,
		Point thirdPoint,
		std::string type = TRIANGLE_TYPE,
		std::shared_ptr<ICanvasSFML> canvas = nullptr);

	double Perimeter() override;
	double Area() override;
	void Draw() override;
	std::string GetType() override;

	bool IsClick(const sf::Vector2i& mousePos) override;
	FrameParameters CalckSelectionFrameParameters() override;
	void SetSelected(bool value) override;
	bool IsSelected() override;
	void MoveShape(const Point& newPosition) override;

	void ChangeFillColor(const sf::Color& color) override;
	void ChangeOutlineColor(const sf::Color& color) override;
	void ChangeOutlineThickness(float thickness) override;
	sf::Color GetFillColor() override;
	sf::Color GetOutlineColor() override;
	float GetOutlineThickness() override;
	std::shared_ptr<IShape> CreateMemento() override;

private:
	Point m_firstPoint;
	Point m_secondPoint;
	Point m_thirdPoint;
	std::string m_type;
	std::shared_ptr<ICanvasSFML> m_canvas;
	bool m_isSelected = false;

	sf::Color m_fillColor = sf::Color::White;
	sf::Color m_outlineColor = sf::Color::White;
	float m_outlineThickness = DEFOLD_OUTLINE_THINCENSS;

	double Distation(const Point& firstPoint, const Point& secondPoint);
	double CalculateTriangleArea(const Point& firstPoint, const Point& secondPoint, const Point& thirdPoint);
	
};
