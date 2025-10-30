#pragma once
#include <memory>
#include "../shapes/CÑompositionShapes.h"
#include <SFML/Graphics.hpp>

class CShapeSelector
{
public:
	CShapeSelector(std::shared_ptr<CÑompositionShapes> composition);
	void OnClick(const sf::Vector2i& mousePos);
	void DrawSelection(sf::RenderWindow& window);

private:
	std::shared_ptr<CÑompositionShapes> m_composition;
	std::shared_ptr<IShape> m_selectedShape;
	bool IsClickInsideShape(const sf::Vector2i& mousePos);
};


