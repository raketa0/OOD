#pragma once
#include "ICommand.h"
#include "../../shapes/CÑompositionShapes.h"
#include <SFML/Graphics/Color.hpp>

class ChangeOutlineColorCommand : public ICommand
{
public:
	ChangeOutlineColorCommand(std::shared_ptr<CÑompositionShapes> compositionShapes, const sf::Color& newColor);
	void Execute() override;
private:
	std::shared_ptr<CÑompositionShapes> m_compositionShapes;
	sf::Color m_newColor;
};
	
