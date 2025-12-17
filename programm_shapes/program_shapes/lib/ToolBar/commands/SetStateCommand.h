#pragma once
#include "../../app/Application.h"
#include "ICommand.h"
#include <functional>
#include <memory>
#include "../state/IState.h"


class SetStateCommand : public ICommand
{
public:
    SetStateCommand(Application& app, State state);

    void Execute() override;

private:
    Application& m_app;
	State m_state;
};
