#pragma once
#include "ICommand.h"
#include "../shapes/CÑompositionShapes.h"
#include <memory>
#include <SFML/Graphics/Color.hpp>

class ChangeFillColorCommand : public ICommand
{
public:
	ChangeFillColorCommand(std::shared_ptr<CÑompositionShapes> compositionShapes, const sf::Color& newColor);
	void Execute() override;
private:
	std::shared_ptr<CÑompositionShapes> m_compositionShapes;
	sf::Color m_newColor;
};
	
