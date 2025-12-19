#include "ChangeFillColorCommand.h"
#include "../../memento/HistoryShapes.h"

ChangeFillColorCommand::ChangeFillColorCommand(std::shared_ptr<CÑompositionShapes> compositionShapes, 
	const sf::Color& newColor):
	m_compositionShapes(std::move(compositionShapes)), 
	m_newColor(newColor){}

void ChangeFillColorCommand::Execute()
{
	HistoryShapes::GetInstance().AddMemento(m_compositionShapes->CreateMement());
	m_compositionShapes->ChangeFillColor(m_newColor);
}
