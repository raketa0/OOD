#pragma once
#include "ICommand.h"
#include <memory>
#include "../../shapes/CÑompositionShapes.h"
#include "../../save/TextSaveStrategy.h"


class SaveTextCommand : public ICommand
{
public:
    SaveTextCommand(std::shared_ptr<CÑompositionShapes> composition);

    void Execute() override;

private:
    std::shared_ptr<CÑompositionShapes> m_composition;
};