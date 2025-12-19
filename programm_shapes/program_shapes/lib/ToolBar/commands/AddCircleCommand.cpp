#include "AddCircleCommand.h"
#include "../../memento/HistoryShapes.h"

AddCircleCommand::AddCircleCommand(std::shared_ptr<CÑompositionShapes> composition, 
	std::shared_ptr<ICanvasSFML> canvas, 
	Point centerCircle, int radius)
	: m_composition(composition),
	m_canvas(canvas),
	m_centerCircle(centerCircle),
	m_radius(radius)
{
}

void AddCircleCommand::Execute()
{
	HistoryShapes::GetInstance().AddMemento(m_composition->CreateMement());

	auto circle = std::make_shared<CircleAdapter>(
		m_centerCircle,
		m_radius,
		CIRCLE_TYPE,
		m_canvas);

	m_composition->AddShape(circle);
}
