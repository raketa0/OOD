#include "TextStrategy.h"

TextStrategy::TextStrategy(double left, double top, double fontSize, const std::string& text):
	m_left(left), m_top(top), m_fontSize(fontSize), m_text(text){}

void TextStrategy::MoveShape(double dx, double dy)
{
	m_left += dx;
	m_top += dy;
}

void TextStrategy::DrawShape(gfx::ICanvas& canvas, gfx::Color& color) const
{
	canvas.SetColor(color);
	canvas.DrawText(m_left, m_top, m_fontSize, m_text);
}

std::string TextStrategy::ToString() const
{
	return std::string();
}
