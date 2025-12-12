#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include <functional>

class IState
{
public:
    virtual ~IState() = default;

	virtual void OnMouseButtonPressed(sf::Event& event) = 0;
	virtual void OnMouseMoved(sf::Event& event) = 0;
	virtual void OnKeyPressed(sf::Event& event) = 0;
	virtual void OnMouseButtonReleased(sf::Event& event) = 0;
	virtual void HandleEvent(sf::Event& event) = 0;
};

