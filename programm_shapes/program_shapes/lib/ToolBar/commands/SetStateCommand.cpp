#include "SetStateCommand.h"
#include "../../app/Application.h"
#include "../IToolBar.h"
SetStateCommand::SetStateCommand(Application& app, State state)
    : m_app(app),
    m_state(state)
{
}

void SetStateCommand::Execute()
{
    m_app.SetState(m_state);

    auto toolbar = m_app.GetToolbar();
    if (!toolbar) return;

    for (auto& btn : toolbar->GetButtons())
    {
        if (btn->GetLabel() == SELECT_)
            btn->SetActive(m_state == SELECT);
        else if (btn->GetLabel() == FILL_)
            btn->SetActive(m_state == FILL);
    }
}
