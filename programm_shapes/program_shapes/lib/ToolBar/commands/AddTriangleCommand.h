#pragma once
#include "ICommand.h"
#include <memory>
#include "../../shapes/CÑompositionShapes.h"
#include "../../canvas/ICanvasSFML.h"

class AddTriangleCommand : public ICommand 
{
public:
AddTriangleCommand(std::shared_ptr<CÑompositionShapes> composition,
	std::shared_ptr<ICanvasSFML> canvas,
	Point firstPoint,
	Point secondPoint,
	Point thirdPoint);
void Execute() override;

private:
	std::shared_ptr<CÑompositionShapes> m_composition;
	std::shared_ptr<ICanvasSFML> m_canvas;
	Point m_firstPoint;
	Point m_secondPoint;
	Point m_thirdPoint;
};