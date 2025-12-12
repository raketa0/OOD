#pragma once
#include "IState.h"
#include"../../app/Application.h"

class SelectState : public IState
{
public:
	void OnMouseButtonPressed(sf::Event& event) override;
	void OnMouseMoved(sf::Event& event) override;
	void OnKeyPressed(sf::Event& event) override;
	void OnMouseButtonReleased(sf::Event& event) override;
	void HandleEvent(sf::Event& event) override;
private:
	Application& m_aplication = Application::GetApp();
};