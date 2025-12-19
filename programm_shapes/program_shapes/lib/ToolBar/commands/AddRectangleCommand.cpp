#include "AddRectangleCommand.h"
#include "../../memento/HistoryShapes.h"

AddRectangleCommand::AddRectangleCommand(std::shared_ptr<CÑompositionShapes> composition,
	std::shared_ptr<ICanvasSFML> canvas, 
	FrameParameters parameters)
	: m_composition(composition),
	m_canvas(canvas),
	m_parameters(parameters)
{
}

void AddRectangleCommand::Execute()
{
	HistoryShapes::GetInstance().AddMemento(m_composition->CreateMement());

	auto rectange = std::make_shared<RectangleAdapter>(
		m_parameters.topLeftCorner,
		m_parameters.width,
		m_parameters.height,
		RECTANGLE_TYPE,
		m_canvas);
	m_composition->AddShape(rectange);
}
