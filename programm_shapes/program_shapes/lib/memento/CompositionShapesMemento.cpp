#include "CompositionShapesMemento.h"

CompositionShapesMemento::CompositionShapesMemento(CÑompositionShapes& composition)
    : m_composition(composition)
{
    for (auto& [id, shape] : composition.GetÑompositionShapes())
    {
        if (!shape)
        {
            continue;
        }
        m_shapes[id] = shape->CreateMemento();
    }
}

void CompositionShapesMemento::Restore()
{
    m_composition.SetCompositionShapes(m_shapes);
}
