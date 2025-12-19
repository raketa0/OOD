#include "ChangeOutlineThicknessCommand.h"
#include "../../memento/HistoryShapes.h"

ChangeOutlineThicknessCommand::ChangeOutlineThicknessCommand(std::shared_ptr<CÑompositionShapes> compositionShapes,
	float newThickness)
	: m_compositionShapes(std::move(compositionShapes)),
	m_newThickness(newThickness){}

void ChangeOutlineThicknessCommand::Execute()
{
	HistoryShapes::GetInstance().AddMemento(m_compositionShapes->CreateMement());

	m_compositionShapes->ChangeOutlineThickness(m_newThickness);
}
