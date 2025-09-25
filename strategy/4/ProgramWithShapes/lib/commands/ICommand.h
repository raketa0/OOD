#pragma once

namespace command
{
    class ICommand 
    {
    public:
        virtual ~ICommand() = default;
        virtual void Execute() = 0;
    };
}
