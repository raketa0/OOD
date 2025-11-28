#pragma once
#include "ICommand.h"
#include <memory>
#include "../shapes/CÑompositionShapes.h"
#include "../canvas/ICanvasSFML.h"

class AddCircleCommand : public ICommand 
{
public:
	AddCircleCommand(std::shared_ptr<CÑompositionShapes> composition,
		std::shared_ptr<ICanvasSFML> canvas,
		Point centerCircle,
		int radius);

	void Execute() override;
private:
	std::shared_ptr<CÑompositionShapes> m_composition;
	std::shared_ptr<ICanvasSFML> m_canvas;
	Point m_centerCircle;
	int m_radius;

};
