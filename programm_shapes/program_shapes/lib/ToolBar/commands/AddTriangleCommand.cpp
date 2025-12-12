#include "AddTriangleCommand.h"

AddTriangleCommand::AddTriangleCommand(std::shared_ptr<CÑompositionShapes> composition, 
	std::shared_ptr<ICanvasSFML> canvas, 
	Point firstPoint, 
	Point secondPoint, 
	Point thirdPoint)
	: m_composition(composition),
	m_canvas(canvas),
	m_firstPoint(firstPoint),
	m_secondPoint(secondPoint),
	m_thirdPoint(thirdPoint)
{
}

void AddTriangleCommand::Execute()
{
	auto triangle = std::make_shared<TriangleAdapter>(
		m_firstPoint,
		m_secondPoint,
		m_thirdPoint,
		TRIANGLE_TYPE,
		m_canvas);
	m_composition->AddShape(triangle);
}
