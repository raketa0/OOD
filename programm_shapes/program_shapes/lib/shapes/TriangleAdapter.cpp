#include "TriangleAdapter.h"
#include <cassert>
#include "../visitor/IShapeVisitor.h"
#include <cmath>
#include <algorithm>

const std::string TRIANGLE_TEXT_ = "Triangle: (First Point: (";
const std::string SECOND_POINT_TEXT_ = "Second Point: (";
const std::string THIRD_POINT_TEXT_ = "Third Point: (";
const std::string FILL_COLOR_TEXT_ = "Fill Color: ";
const std::string OUTLINE_COLOR_TEXT_ = "Outline Color: ";
const std::string OUTLINE_THICKNESS_TEXT_ = "Outline Thickness: ";
const std::string COMMA_SPACE_ = ", ";
const std::string CLOSE_PAREN_ = ")";
const double TOLERANCE_ = 1e-6;
const double HALF_ = 0.5;

TriangleAdapter::TriangleAdapter(Point firstPoint, Point secondPoint,
	Point thirdPoint, std::string type,
	std::shared_ptr<ICanvasSFML> canvas) :
	m_firstPoint(firstPoint),
	m_secondPoint(secondPoint),
	m_thirdPoint(thirdPoint),
	m_type(type),
	m_canvas(std::move(canvas))
{
	assert(m_canvas);
}

double TriangleAdapter::Perimeter()
{
	return Distation(m_firstPoint, m_secondPoint) +
		Distation(m_firstPoint, m_thirdPoint) +
		Distation(m_secondPoint, m_thirdPoint);
}

double TriangleAdapter::Area()
{
	double halfPerimeter = Perimeter() * HALF_;
	return std::sqrt(
		halfPerimeter *
		(halfPerimeter - Distation(m_firstPoint, m_secondPoint)) *
		(halfPerimeter - Distation(m_firstPoint, m_thirdPoint)) *
		(halfPerimeter - Distation(m_secondPoint, m_thirdPoint))
	);
}

void TriangleAdapter::Draw()
{
	m_canvas->DrawTriangle(m_firstPoint, m_secondPoint, m_thirdPoint,
		m_fillColor, m_outlineColor, m_outlineThickness);
}

std::string TriangleAdapter::GetType()
{
	return m_type;
}

bool TriangleAdapter::IsClick(const sf::Vector2i& mousePosition)
{
	double fullTriangleArea = CalculateTriangleArea(m_firstPoint, m_secondPoint, m_thirdPoint);
	if (fullTriangleArea < TOLERANCE_)
		return false;

	Point clickPoint{ mousePosition.x, mousePosition.y };
	double sumOfSubAreas = CalculateTriangleArea(clickPoint, m_secondPoint, m_thirdPoint)
		+ CalculateTriangleArea(m_firstPoint, clickPoint, m_thirdPoint)
		+ CalculateTriangleArea(m_firstPoint, m_secondPoint, clickPoint);

	return std::abs(sumOfSubAreas - fullTriangleArea) <= TOLERANCE_;
}

FrameParameters TriangleAdapter::CalckSelectionFrameParameters()
{
	int minX = std::min({ m_firstPoint.x, m_secondPoint.x, m_thirdPoint.x });
	int minY = std::min({ m_firstPoint.y, m_secondPoint.y, m_thirdPoint.y });
	int maxX = std::max({ m_firstPoint.x, m_secondPoint.x, m_thirdPoint.x });
	int maxY = std::max({ m_firstPoint.y, m_secondPoint.y, m_thirdPoint.y });

	FrameParameters frameParams;
	frameParams.topLeftCorner = { minX, minY };
	frameParams.width = maxX - minX;
	frameParams.height = maxY - minY;
	return frameParams;
}

void TriangleAdapter::SetSelected(bool value)
{
	m_isSelected = value;
}

bool TriangleAdapter::IsSelected()
{
	return m_isSelected;
}

void TriangleAdapter::MoveShape(const Point& newPosition)
{
	int deltaX = newPosition.x - CalckSelectionFrameParameters().topLeftCorner.x;
	int deltaY = newPosition.y - CalckSelectionFrameParameters().topLeftCorner.y;
	m_firstPoint.x += deltaX;
	m_firstPoint.y += deltaY;
	m_secondPoint.x += deltaX;
	m_secondPoint.y += deltaY;
	m_thirdPoint.x += deltaX;
	m_thirdPoint.y += deltaY;
}

void TriangleAdapter::ChangeFillColor(const sf::Color& color)
{
	m_fillColor = color;
}

void TriangleAdapter::ChangeOutlineColor(const sf::Color& color)
{
	m_outlineColor = color;
}

void TriangleAdapter::ChangeOutlineThickness(float thickness)
{
	m_outlineThickness = thickness;
}

sf::Color TriangleAdapter::GetFillColor()
{
	return m_fillColor;
}

sf::Color TriangleAdapter::GetOutlineColor()
{
	return m_outlineColor;
}

float TriangleAdapter::GetOutlineThickness()
{
	return m_outlineThickness;
}

std::string TriangleAdapter::GetCharacteristics()
{
	return TRIANGLE_TEXT_ + std::to_string(m_firstPoint.x) + COMMA_SPACE_ + std::to_string(m_firstPoint.y) + CLOSE_PAREN_ + ", " +
		SECOND_POINT_TEXT_ + std::to_string(m_secondPoint.x) + COMMA_SPACE_ + std::to_string(m_secondPoint.y) + CLOSE_PAREN_ + ", " +
		THIRD_POINT_TEXT_ + std::to_string(m_thirdPoint.x) + COMMA_SPACE_ + std::to_string(m_thirdPoint.y) + CLOSE_PAREN_ + ", " +
		FILL_COLOR_TEXT_ + std::to_string(m_fillColor.toInteger()) + COMMA_SPACE_ +
		OUTLINE_COLOR_TEXT_ + std::to_string(m_outlineColor.toInteger()) + COMMA_SPACE_ +
		OUTLINE_THICKNESS_TEXT_ + std::to_string(m_outlineThickness) + CLOSE_PAREN_;
}

std::shared_ptr<IShape> TriangleAdapter::CreateMemento()
{
	return std::make_shared<TriangleAdapter>(*this);
}

void TriangleAdapter::Accept(IShapeVisitor& visitor)
{
	visitor.VisitTriangle(*this);
}

double TriangleAdapter::Distation(const Point& firstPoint, const Point& secondPoint)
{
	double dx = double(firstPoint.x - secondPoint.x);
	double dy = double(firstPoint.y - secondPoint.y);
	return std::sqrt(dx * dx + dy * dy);
}

double TriangleAdapter::CalculateTriangleArea(const Point& firstPoint, const Point& secondPoint, const Point& thirdPoint)
{
	return HALF_ * std::abs((firstPoint.x) * (secondPoint.y - thirdPoint.y) +
		(secondPoint.x) * (thirdPoint.y - firstPoint.y) +
		(thirdPoint.x) * (firstPoint.y - secondPoint.y));
}
