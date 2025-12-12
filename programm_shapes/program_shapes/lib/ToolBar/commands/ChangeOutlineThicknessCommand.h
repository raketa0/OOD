#pragma once
#include "ICommand.h"
#include "../../shapes/CÑompositionShapes.h"
#include <memory>
#include <SFML/Graphics/Color.hpp>

class ChangeOutlineThicknessCommand : public ICommand
{
public:
	ChangeOutlineThicknessCommand(std::shared_ptr<CÑompositionShapes> compositionShapes, float newThickness);

	void Execute() override;
private:
	std::shared_ptr<CÑompositionShapes> m_compositionShapes;
	float m_newThickness;
};
