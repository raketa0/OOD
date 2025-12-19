#pragma once
#include "IMementoShapes.h"
#include "../shapes/CÑompositionShapes.h"

class CompositionShapesMemento : public IMementoShapes
{
public:
    explicit CompositionShapesMemento(CÑompositionShapes& composition);

    void Restore() override;

private:
    CÑompositionShapes& m_composition;
    std::map<int, std::shared_ptr<IShape>> m_shapes;
};
