#pragma once
#include <memory>
#include "../shapes/CÑompositionShapes.h"
#include <SFML/Graphics.hpp>
#include "../canvas/CCanvasSFML.h"


class CShapeSelector
{
public:
	CShapeSelector(std::shared_ptr<CÑompositionShapes> composition,
		std::shared_ptr<CCanvasSFML> canvas = nullptr);
	void OnClick(sf::Vector2i& mousePos);
	void DrawSelection();

private:
	std::shared_ptr<CÑompositionShapes> m_composition;
	std::shared_ptr<IShape> m_selectedShape;
	FrameParameters m_selectionFrameParameters;
	std::shared_ptr<ICanvasSFML> m_canvas;

	void IsClickInsideShape(sf::Vector2i& mousePos);
};


