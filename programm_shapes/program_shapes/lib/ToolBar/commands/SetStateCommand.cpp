#include "SetStateCommand.h"
#include "../../app/Application.h"

SetStateCommand::SetStateCommand( Application& app, State& state):
    m_app(app),
	m_state(state){}

void SetStateCommand::Execute()
{
    m_app.SetState(m_state);
}
