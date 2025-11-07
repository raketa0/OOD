#pragma once
#include <memory>
#include "../shapes/CÑompositionShapes.h"
#include <SFML/Graphics.hpp>
#include "../canvas/CCanvasSFML.h"
#include <set>


class CShapeSelector
{
public:
	CShapeSelector(std::shared_ptr<CÑompositionShapes> composition,
		std::shared_ptr<CCanvasSFML> canvas = nullptr);

	void OnClick(sf::Vector2i& mousePos, bool isShiftPressed);
	void DrawSelection();
	void GroupSelectedShapes();

	void UngroupSelectedShape();
private:
	std::shared_ptr<CÑompositionShapes> m_composition;
	FrameParameters m_selectionFrameParameters;
	std::shared_ptr<ICanvasSFML> m_canvas;
};


