#pragma once

#include "IShape.h"
#include <map>
#include <memory>

class CGroupShape : public IShape
{
public:

	CGroupShape(std::map<int, std::shared_ptr<IShape>> groupedShapes, 
        std::shared_ptr<ICanvasSFML> canvas = nullptr);

    void Draw() override;
    std::string GetType() override;
    bool IsSelected() override;
    bool IsGroup() override;
    void SetSelected(bool value) override;
    bool IsClick(const sf::Vector2i& mousePos) override;
     FrameParameters CalckSelectionFrameParameters() override;
    std::map<int, std::shared_ptr<IShape>> GetGroupedShapes();
	void MoveShape(const Point& newPosition) override;

	void ChangeFillColor(const sf::Color& color) override;
	void ChangeOutlineColor(const sf::Color& color) override;
	void ChangeOutlineThickness(float thickness) override;

private:
    FrameParameters m_frameParameters = { {0, 0}, 0, 0 };

    bool m_selected = false;
    std::map<int, std::shared_ptr<IShape>> m_groupedShapes;
    std::shared_ptr<ICanvasSFML> m_canvas;



};