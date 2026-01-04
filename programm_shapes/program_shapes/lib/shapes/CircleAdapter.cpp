#include "CircleAdapter.h"
#include <string>
#include <cassert>

const double PI_ = 3.14159265358979323846;
const int SECOND_NUM_ = 2;
const std::string CIRCLE_TEXT_ = "Circle: (Center(";
const std::string COMMA_SPACE_ = ", ";
const std::string CLOSE_PAREN_ = ")";
const std::string RADIUS_TEXT_ = "Radius: ";
const std::string FILL_COLOR_TEXT_ = "Fill Color: ";
const std::string OUTLINE_COLOR_TEXT_ = "Outline Color: ";
const std::string OUTLINE_THICKNESS_TEXT_ = "Outline Thickness: ";

CircleAdapter::CircleAdapter(Point centerCircle, int radius,
	std::string type, std::shared_ptr<ICanvasSFML> canvas) :
	m_centerCircle(centerCircle),
	m_radius(radius),
	m_type(type),
	m_canvas(std::move(canvas))
{
	assert(m_canvas);
}

double CircleAdapter::Perimeter()
{
	return 2 * PI_ * m_radius;
}

double CircleAdapter::Area()
{
	return PI_ * m_radius * m_radius;
}

void CircleAdapter::Draw()
{
	m_canvas->DrawCircle(m_centerCircle, m_radius,
		m_fillColor, m_outlineColor, m_outlineThickness);
}

std::string CircleAdapter::GetType()
{
	return m_type;
}

bool CircleAdapter::IsClick(const sf::Vector2i& mousePos)
{
	double dx = mousePos.x - m_centerCircle.x;
	double dy = mousePos.y - m_centerCircle.y;
	double distanceSquared = dx * dx + dy * dy;
	return distanceSquared <= m_radius * m_radius;
}

FrameParameters CircleAdapter::CalckSelectionFrameParameters()
{
	FrameParameters frameParams{};
	frameParams.topLeftCorner.x = m_centerCircle.x - m_radius;
	frameParams.topLeftCorner.y = m_centerCircle.y - m_radius;
	frameParams.width = SECOND_NUM_ * m_radius;
	frameParams.height = SECOND_NUM_ * m_radius;
	return frameParams;
}

void CircleAdapter::SetSelected(bool value)
{
	m_isSelected = value;
}

bool CircleAdapter::IsSelected()
{
	return m_isSelected;
}

void CircleAdapter::MoveShape(const Point& newPosition)
{
	m_centerCircle = Point{ newPosition.x + m_radius, newPosition.y + m_radius };
}

void CircleAdapter::ChangeFillColor(const sf::Color& color)
{
	m_fillColor = color;
}

void CircleAdapter::ChangeOutlineColor(const sf::Color& color)
{
	m_outlineColor = color;
}

void CircleAdapter::ChangeOutlineThickness(float thickness)
{
	m_outlineThickness = thickness;
}

sf::Color CircleAdapter::GetFillColor()
{
	return m_fillColor;
}

sf::Color CircleAdapter::GetOutlineColor()
{
	return m_outlineColor;
}

std::string CircleAdapter::GetCharacteristics()
{
	return CIRCLE_TEXT_ + std::to_string(m_centerCircle.x) + COMMA_SPACE_ + std::to_string(m_centerCircle.y) +
		CLOSE_PAREN_ + COMMA_SPACE_ + RADIUS_TEXT_ + std::to_string(m_radius) + COMMA_SPACE_ +
		FILL_COLOR_TEXT_ + std::to_string(m_fillColor.toInteger()) + COMMA_SPACE_ +
		OUTLINE_COLOR_TEXT_ + std::to_string(m_outlineColor.toInteger()) + COMMA_SPACE_ +
		OUTLINE_THICKNESS_TEXT_ + std::to_string(m_outlineThickness) + CLOSE_PAREN_;
}

float CircleAdapter::GetOutlineThickness()
{
	return m_outlineThickness;
}

std::shared_ptr<IShape> CircleAdapter::CreateMemento()
{
	return std::make_shared<CircleAdapter>(*this);
}

void CircleAdapter::Accept(IShapeVisitor& visitor)
{
	visitor.VisitCircle(*this);
}
