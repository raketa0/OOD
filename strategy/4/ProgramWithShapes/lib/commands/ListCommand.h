#pragma once


#include"ICommand.h"
#include <string>
#include "../shapes/CPicture.h"

namespace command
{
    class ListCommand : public ICommand
    {
    public:
        ListCommand(shapes::CPicture& picture)
            : m_picture(picture) {}

        void Execute() override
        {
            m_picture.List();
        }

    private:
        shapes::CPicture& m_picture;
    };
}