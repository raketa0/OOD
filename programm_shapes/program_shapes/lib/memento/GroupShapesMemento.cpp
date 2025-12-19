#include "GroupShapesMemento.h"

GroupShapesMemento::GroupShapesMemento(std::shared_ptr<CGroupShape> groupShape)
    : m_groupShape(std::move(groupShape)), m_selected(m_groupShape->IsSelected())
{
    auto shapes = m_groupShape->GetGroupedShapes();
    for (auto& [id, shape] : shapes)
    {
        FrameParameters frame = shape->CalckSelectionFrameParameters();
        ShapeParameters parameters{
            frame.topLeftCorner,
            shape->GetFillColor(),
            shape->GetOutlineColor(),
            shape->GetOutlineThickness(),
            shape->IsSelected()
        };
        m_shapesParameters[id] = parameters;
    }
}

void GroupShapesMemento::Restore()
{
    m_groupShape->SetSelected(m_selected);
    auto shapes = m_groupShape->GetGroupedShapes();
    for (auto& [id, shape] : shapes)
    {
        if (m_shapesParameters.find(id) != m_shapesParameters.end())
        {
            ShapeParameters& state = m_shapesParameters[id];
            shape->MoveShape(state.topLeft);
            shape->SetSelected(state.selected);
            shape->ChangeFillColor(state.fill);
            shape->ChangeOutlineColor(state.outline);
            shape->ChangeOutlineThickness(state.thickness);
        }
    }
}
