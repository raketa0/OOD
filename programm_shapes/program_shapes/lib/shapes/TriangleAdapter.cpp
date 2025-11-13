#include "TriangleAdapter.h"
#include <cassert>

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
    double halfPerimeter = Perimeter() / 2;
    return std::sqrt(
        halfPerimeter *
        (halfPerimeter - Distation(m_firstPoint, m_secondPoint)) *
        (halfPerimeter - Distation(m_firstPoint, m_thirdPoint)) *
        (halfPerimeter - Distation(m_secondPoint, m_thirdPoint))
    );
}

void TriangleAdapter::Draw()
{
	m_canvas->DrawTriangle(m_firstPoint, m_secondPoint, m_thirdPoint);
}

std::string TriangleAdapter::GetType()
{
    return m_type;
}

bool TriangleAdapter::IsClick(const sf::Vector2i& mousePosition)
{

    double fullTriangleArea = CalculateTriangleArea(m_firstPoint, m_secondPoint, m_thirdPoint);
    if (fullTriangleArea < FIRST)
    { 
        return false;
    }

    Point clickPoint{ mousePosition.x, mousePosition.y };

    double sumOfSubAreas = CalculateTriangleArea(clickPoint, m_secondPoint, m_thirdPoint)
        + CalculateTriangleArea(m_firstPoint, clickPoint, m_thirdPoint)
        + CalculateTriangleArea(m_firstPoint, m_secondPoint, clickPoint);

    
    double tolerance = FIRST;
    if (std::abs(sumOfSubAreas - fullTriangleArea) <= tolerance) 
    {
        return true;
    }

    return false;
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

double TriangleAdapter::Distation(const Point& firstPoint, const Point& secondPoint)
{
    double dx = double(firstPoint.x - secondPoint.x);
    double dy = double(firstPoint.y - secondPoint.y);
    return std::sqrt(dx * dx + dy * dy);
}


double TriangleAdapter::CalculateTriangleArea(const Point& firstPoint, const Point& secondPoint, const Point& thirdPoint)
{
    return 0.5 * std::abs((firstPoint.x) * (secondPoint.y - thirdPoint.y) +
        (secondPoint.x) * (thirdPoint.y - firstPoint.y) +
        (thirdPoint.x) * (firstPoint.y - secondPoint.y)
    );
}

