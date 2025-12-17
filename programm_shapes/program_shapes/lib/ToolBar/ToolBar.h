#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "../app/Application.h"
#include "commands/ICommand.h"
#include "button/CButton.h"
#include "IToolBar.h"


class ToolBar : public IToolBar
{
public:
    ToolBar(sf::RenderWindow& window);

    void SetupDefaultButtons() override;
    void Draw() override;
    bool HandleEvent(sf::Event& event) override;
    void InitPanelArea() override;
    std::vector<std::shared_ptr<Button>> GetButtons() override { return m_buttons; } ;

private:
    const float X = 10.f;
    const float Y = 10.f;
    const float WIDTH = 400.f;
    const float HEIGHT = 120.f;
    const float BTN_HEIGHT = 34.f;
    const float BTN_MARGIN = 6.f;

	Application& m_app = Application::GetApp();
	sf::RenderWindow& m_window = Application::GetApp().GetWindow();
    sf::FloatRect m_area;
    sf::RectangleShape m_background;

    std::vector<std::shared_ptr<Button>> m_buttons;

    void AddButton(sf::Vector2f& size, sf::Vector2f& position,
        std::string label, std::shared_ptr<ICommand> command);
};
