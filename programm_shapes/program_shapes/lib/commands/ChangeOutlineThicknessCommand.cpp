#include "ChangeOutlineThicknessCommand.h"

ChangeOutlineThicknessCommand::ChangeOutlineThicknessCommand(std::shared_ptr<CÑompositionShapes> compositionShapes,
	float newThickness)
	: m_compositionShapes(std::move(compositionShapes)),
	m_newThickness(newThickness){}

void ChangeOutlineThicknessCommand::Execute()
{
	m_compositionShapes->ChangeOutlineThickness(m_newThickness);
}
