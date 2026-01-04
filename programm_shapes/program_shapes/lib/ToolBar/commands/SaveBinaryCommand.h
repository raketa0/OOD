#pragma once
#include "ICommand.h"
#include <memory>
#include "../../shapes/CÑompositionShapes.h"

class SaveBinaryCommand : public ICommand
{
public:
    SaveBinaryCommand(std::shared_ptr<CÑompositionShapes> composition);

    void Execute() override;

private:
    std::shared_ptr<CÑompositionShapes> m_composition;
};