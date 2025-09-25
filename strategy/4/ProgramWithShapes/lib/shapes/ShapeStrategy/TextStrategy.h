#pragma once

#include "IShapeStrategy.h"

namespace shapes
{
    class TextStrategy : public shapes::IShapeStrategy
    {
    public:
        TextStrategy(double left, double top,
            double fontSize, const std::string& text);

        void MoveShape(double dx, double dy) override;
        void DrawShape(gfx::ICanvas& canvas, gfx::Color& color) const override;
        std::string ToString() const override;

    private:
        double m_left, m_top, m_fontSize;
        std::string m_text;
    };
}