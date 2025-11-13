#pragma once
#include "IShape.h"
#include "../canvas/ICanvasSFML.h"
#include "../tools/ShapesStruct.h"
#include <memory>
#include <string>

class RectangleAdapter : public IShape
{
public:
	RectangleAdapter(Point leftTopCorner, int width,
		int height, std::string type = RECTANGLE_TYPE,
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

private:
	Point m_leftTopCorner;
	int m_width;
	int m_height;
	std::string m_type;
	std::shared_ptr<ICanvasSFML> m_canvas;
	bool m_isSelected = false;
};
