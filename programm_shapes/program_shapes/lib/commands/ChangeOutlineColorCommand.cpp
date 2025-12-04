#include "ChangeOutlineColorCommand.h"

ChangeOutlineColorCommand::ChangeOutlineColorCommand(std::shared_ptr<CÑompositionShapes> compositionShapes, 
	const sf::Color& newColor)
	: m_compositionShapes(std::move(compositionShapes)),
	m_newColor(newColor){}

void ChangeOutlineColorCommand::Execute()
{
	m_compositionShapes->ChangeOutlineColor(m_newColor);
}
