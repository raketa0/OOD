#include "ChangeOutlineColorCommand.h"
#include "../../memento/HistoryShapes.h"

ChangeOutlineColorCommand::ChangeOutlineColorCommand(std::shared_ptr<CÑompositionShapes> compositionShapes, 
	const sf::Color& newColor)
	: m_compositionShapes(std::move(compositionShapes)),
	m_newColor(newColor){}

void ChangeOutlineColorCommand::Execute()
{
	HistoryShapes::GetInstance().AddMemento(m_compositionShapes->CreateMement());

	m_compositionShapes->ChangeOutlineColor(m_newColor);
}
