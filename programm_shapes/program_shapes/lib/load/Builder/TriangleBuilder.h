#pragma once
#include "IShapeBuilder.h"
#include "../../canvas/ICanvasSFML.h"

const float DEF_OUTLINE_THICKNESS = 1.0f;
const std::string DEF_TYPE = "";
const Point DEF_POINT = { 0, 0 };
const Point DEF_POINT_SECOND = { 0, 0 };
const Point DEF_POINT_THIRD = { 0, 0 };


class TriangleBuilder : public IShapeBuilder
{
public:
    TriangleBuilder(std::shared_ptr<ICanvasSFML> canvas);

    void SetType(std::string& type) override;
    void SetPoints(std::vector<Point>& points) override;
    void SetColors(sf::Color& fill, sf::Color& outline) override;
    void SetOutlineThickness(float thickness) override;
    void AddShapeInComposition(std::shared_ptr<CÑompositionShapes> composition) override;
    std::shared_ptr<IShape> CreateShape() override;

private:
    Point m_point_first = DEF_POINT;
    Point m_point_second = DEF_POINT_SECOND;
    Point m_point_third = DEF_POINT_THIRD;
    std::string m_type = DEF_TYPE;
    sf::Color m_fill;
    sf::Color m_outline;
    float m_outlineThickness = DEF_OUTLINE_THICKNESS;
    std::shared_ptr<ICanvasSFML> m_canvas;
};
