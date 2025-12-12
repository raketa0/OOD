#pragma once
#include <SFML/Graphics.hpp>
#include <memory>


class IToolBar
{
public:
    virtual ~IToolBar() = default;

    virtual void InitPanelArea() = 0;
    virtual void SetupDefaultButtons() = 0;
    virtual void Draw() = 0;
    virtual bool HandleEvent(sf::Event& event) = 0;
};
