#pragma once
#include <SFML/Graphics.hpp>
#include "../app/Application.h"


class IState 
{
public:
    virtual bool HandleEvent(Application& app) = 0;

};