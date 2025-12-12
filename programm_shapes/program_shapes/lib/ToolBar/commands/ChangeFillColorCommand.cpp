#include "ChangeFillColorCommand.h"

ChangeFillColorCommand::ChangeFillColorCommand(std::shared_ptr<CÑompositionShapes> compositionShapes, 
	const sf::Color& newColor):
	m_compositionShapes(std::move(compositionShapes)), 
	m_newColor(newColor){}

void ChangeFillColorCommand::Execute()
{
	m_compositionShapes->ChangeFillColor(m_newColor);
}
