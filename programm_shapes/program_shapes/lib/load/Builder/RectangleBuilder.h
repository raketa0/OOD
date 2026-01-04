#pragma once
#include "IShapeBuilder.h"
#include "../../canvas/ICanvasSFML.h"
#include "../../shapes/RectangleAdapter.h"

const float DEFAULT_OUTLINE_THICKNESS = 1.0f;
const int DEFAULT_WIDTH = 0;
const int DEFAULT_HEIGHT = 0;
const std::string DEFAULT_TYPE = "";

class RectangleBuilder : public IShapeBuilder
{
public:
    RectangleBuilder(std::shared_ptr<ICanvasSFML> canvas);
    void SetType(std::string& type) override;
    void SetPoints(std::vector<Point>& points) override;
    void SetDimensions(int width, int height) override;
    void SetRadius(int) override {}
    void SetColors(sf::Color& fill, sf::Color& outline) override;
    void SetOutlineThickness(float thickness) override;
    void AddShapeInComposition(std::shared_ptr<CÑompositionShapes> composition) override;
    std::shared_ptr<IShape> CreateShape() override;

private:
    Point m_leftTop;
    int m_width = DEFAULT_WIDTH;
    int m_height = DEFAULT_HEIGHT;
    std::string m_type = DEFAULT_TYPE;
    sf::Color m_fill;
    sf::Color m_outline;
    float m_outlineThickness = DEFAULT_OUTLINE_THICKNESS;
    std::shared_ptr<ICanvasSFML> m_canvas;
};
