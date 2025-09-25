#pragma once
#include <SFML/Graphics.hpp>
#include "../gfx/ICanvas.h"
#include "EllipseShape.h"

namespace gfx
{
    class CCanvas : public gfx::ICanvas
    {
    public:
        CCanvas(sf::RenderWindow& window, sf::Vector2f position, sf::Color color);

        void MoveTo(double x, double y) override;
        void LineTo(double x, double y) override;
        void SetColor(const gfx::Color& c) override;
        void DrawEllipse(double cx, double cy, double rx, double ry) override;
        void DrawText(double left, double top, double fontSize, const std::string& text) override;

    private:
        sf::RenderWindow& m_window;
        sf::Vector2f m_currentPosition;
        sf::Color m_currentColor;
    };
}
