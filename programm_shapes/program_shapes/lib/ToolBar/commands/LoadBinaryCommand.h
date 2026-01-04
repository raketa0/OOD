#pragma once
#include "ICommand.h"
#include <memory>
#include <string>
#include "../../shapes/CÑompositionShapes.h"

class LoadBinaryCommand : public ICommand
{
public:
    LoadBinaryCommand(std::shared_ptr<CÑompositionShapes> composition);

    void Execute() override;

private:
    std::shared_ptr<CÑompositionShapes> m_composition;
};