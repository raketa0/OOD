#pragma once
#include "IShape.h"
#include "../canvas/ICanvasSFML.h"
#include "../tools/ShapesStruct.h"
#include "../tools/Constants.h"
#include <memory>
#include <string>

class CircleAdapter : public IShape
{
public:
	CircleAdapter(Point centerCircle, int radius, 
		std::string type = CIRCLE_TYPE,
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
	Point m_centerCircle;
	int m_radius;
	std::string m_type = CIRCLE_TYPE;
	std::shared_ptr<ICanvasSFML> m_canvas;
	bool m_isSelected = false;

};

