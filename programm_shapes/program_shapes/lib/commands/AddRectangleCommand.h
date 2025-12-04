#pragma once
#include "ICommand.h"
#include <memory>
#include "../shapes/CÑompositionShapes.h"

class AddRectangleCommand : public ICommand 
{
public:
    AddRectangleCommand(std::shared_ptr<CÑompositionShapes> composition,
        std::shared_ptr<ICanvasSFML> canvas,
        FrameParameters parameters);
        
    void Execute() override;

private:
    std::shared_ptr<CÑompositionShapes> m_composition;
    std::shared_ptr<ICanvasSFML> m_canvas;
    FrameParameters m_parameters;
};