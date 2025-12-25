#include "ChangeOutlineColorCommand.h"
#include "../../memento/HistoryShapes.h"
#include "../../visitor/OutlineColorVisitor.h"

ChangeOutlineColorCommand::ChangeOutlineColorCommand(std::shared_ptr<CÑompositionShapes> compositionShapes, 
	const sf::Color& newColor)
	: m_compositionShapes(std::move(compositionShapes)),
	m_newColor(newColor){}

void ChangeOutlineColorCommand::Execute()
{
	HistoryShapes::GetInstance().AddMemento(m_compositionShapes->CreateMement());

	OutlineColorVisitor visitor(m_newColor);
	m_compositionShapes->ChangeOutlineColor(m_newColor);

}
