#include "RectangleAdapter.h"
#include <cassert>
#include "../visitor/IShapeVisitor.h"

const std::string RECTANGLE_TEXT_ = "Rectangle: (Height: ";
const std::string WIDTH_TEXT_ = ", Width: ";
const std::string LEFT_TOP_TEXT_ = "Left Top Corner(";
const std::string COMMA_SPACE_ = ", ";
const std::string FILL_COLOR_TEXT_ = "Fill Color: ";
const std::string OUTLINE_COLOR_TEXT_ = "Outline Color: ";
const std::string OUTLINE_THICKNESS_TEXT_ = "Outline Thickness: ";
const std::string CLOSE_PAREN_ = ")";
const double TWO_ = 2.0;

RectangleAdapter::RectangleAdapter(Point leftTopCorner, int width,
	int height, std::string type,
	std::shared_ptr<ICanvasSFML> canvas) :
	m_leftTopCorner(leftTopCorner),
	m_width(width),
	m_height(height),
	m_type(type),
	m_canvas(std::move(canvas))
{
	assert(m_canvas);
}

double RectangleAdapter::Perimeter()
{
	return TWO_ * (m_width + m_height);
}

double RectangleAdapter::Area()
{
	return double(m_width) * double(m_height);
}

void RectangleAdapter::Draw()
{
	m_canvas->DrawRectangle(m_leftTopCorner, m_width, m_height,
		m_fillColor, m_outlineColor, m_outlineThickness, true);
}

std::string RectangleAdapter::GetType()
{
	return m_type;
}

bool RectangleAdapter::IsClick(const sf::Vector2i& mousePos)
{
	return (mousePos.x >= m_leftTopCorner.x &&
		mousePos.x <= m_leftTopCorner.x + m_width &&
		mousePos.y >= m_leftTopCorner.y &&
		mousePos.y <= m_leftTopCorner.y + m_height);
}

FrameParameters RectangleAdapter::CalckSelectionFrameParameters()
{
	FrameParameters frameParams{};
	frameParams.topLeftCorner = m_leftTopCorner;
	frameParams.width = m_width;
	frameParams.height = m_height;
	return frameParams;
}

void RectangleAdapter::SetSelected(bool value)
{
	m_isSelected = value;
}

bool RectangleAdapter::IsSelected()
{
	return m_isSelected;
}

void RectangleAdapter::MoveShape(const Point& newPosition)
{
	m_leftTopCorner = newPosition;
}

void RectangleAdapter::ChangeFillColor(const sf::Color& color)
{
	m_fillColor = color;
}

void RectangleAdapter::ChangeOutlineColor(const sf::Color& color)
{
	m_outlineColor = color;
}

void RectangleAdapter::ChangeOutlineThickness(float thickness)
{
	m_outlineThickness = thickness;
}

sf::Color RectangleAdapter::GetFillColor()
{
	return m_fillColor;
}

sf::Color RectangleAdapter::GetOutlineColor()
{
	return m_outlineColor;
}

float RectangleAdapter::GetOutlineThickness()
{
	return m_outlineThickness;
}

std::string RectangleAdapter::GetCharacteristics()
{
	return RECTANGLE_TEXT_ + std::to_string(m_height) +
		WIDTH_TEXT_ + std::to_string(m_width) +
		LEFT_TOP_TEXT_ + std::to_string(m_leftTopCorner.x) + COMMA_SPACE_ + std::to_string(m_leftTopCorner.y) +
		COMMA_SPACE_ + FILL_COLOR_TEXT_ + std::to_string(m_fillColor.toInteger()) +
		COMMA_SPACE_ + OUTLINE_COLOR_TEXT_ + std::to_string(m_outlineColor.toInteger()) +
		COMMA_SPACE_ + OUTLINE_THICKNESS_TEXT_ + std::to_string(m_outlineThickness) + CLOSE_PAREN_;
}

std::shared_ptr<IShape> RectangleAdapter::CreateMemento()
{
	return std::make_shared<RectangleAdapter>(*this);
}

void RectangleAdapter::Accept(IShapeVisitor& visitor)
{
	visitor.VisitRectangle(*this);
}
