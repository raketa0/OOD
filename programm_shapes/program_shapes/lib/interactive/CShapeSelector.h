#pragma once
#include <memory>
#include "../shapes/C�ompositionShapes.h"
#include <SFML/Graphics.hpp>

class CShapeSelector
{
public:
	CShapeSelector(std::shared_ptr<C�ompositionShapes> composition);
	void OnClick(const sf::Vector2i& mousePos);
	void DrawSelection(sf::RenderWindow& window);

private:
	std::shared_ptr<C�ompositionShapes> m_composition;
	std::shared_ptr<IShape> m_selectedShape;
	bool IsClickInsideShape(const sf::Vector2i& mousePos);
};


