#pragma once
#include<vector>
#include <string>


class ISaveStrategy
{
public:
    virtual ~ISaveStrategy() = default;
    virtual void Save(std::string& filename) = 0;
};