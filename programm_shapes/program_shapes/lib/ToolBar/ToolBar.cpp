#include "ToolBar.h"
#include "commands/AddRectangleCommand.h"
#include "commands/AddTriangleCommand.h"
#include "commands/AddCircleCommand.h"
#include "commands/ChangeFillColorCommand.h"
#include "commands/ChangeOutlineColorCommand.h"
#include "commands/SetStateCommand.h"
#include "commands/ChangeOutlineThicknessCommand.h"

ToolBar::ToolBar(sf::RenderWindow& window)
    : m_window(window)
{
    InitPanelArea();
}


void ToolBar::AddButton(sf::Vector2f& size, sf::Vector2f& position,
    std::string& label, std::shared_ptr<ICommand> command)
{
    auto button = std::make_shared<Button>(size, position, label, command);
    m_buttons.push_back(button);
}

void ToolBar::InitPanelArea()
{
    m_area = sf::FloatRect({ X, Y }, { WIDTH, HEIGHT });

    m_background.setPosition({ X, Y });
    m_background.setSize({ WIDTH, HEIGHT });
    m_background.setFillColor(sf::Color(230, 230, 230));
    m_background.setOutlineColor(sf::Color::Black);
    m_background.setOutlineThickness(1.f);
}



void ToolBar::SetupDefaultButtons()
{
    m_buttons.clear();

    float startX = 10.f;
    float y = 10.f;
    float width = 100.f;
    float height = 34.f;
    float margin = 6.f;

    float x = startX;

    // Размер кнопки
    sf::Vector2f size(width, height);

    // Rectangle
    sf::Vector2f position(x, y);
    std::string label = "Rectangle";
    FrameParameters rectFrame = { {0, 0}, 50, 50 }; // примерные параметры прямоугольника
    AddButton(size, position, label,
        std::make_shared<AddRectangleCommand>(m_app.GetComposition(), m_app.GetCanvas(), rectFrame));
    x += width + margin;

    // Triangle
    position = sf::Vector2f(x, y);
    label = "Triangle";
    Point p1 = { 0,0 }, p2 = { 50,0 }, p3 = { 25,50 }; // примерные точки треугольника
    AddButton(size, position, label,
        std::make_shared<AddTriangleCommand>(m_app.GetComposition(), m_app.GetCanvas(), p1, p2, p3));
    x += width + margin;

    // Circle
    position = sf::Vector2f(x, y);
    label = "Circle";
    Point center = { 25,25 }; // центр круга
    int radius = 25;        // радиус круга
    AddButton(size, position, label,
        std::make_shared<AddCircleCommand>(m_app.GetComposition(), m_app.GetCanvas(), center, radius));
    x += width + margin;

    // Fill Color
    position = sf::Vector2f(x, y);
    label = "Fill Color";
    AddButton(size, position, label,
        std::make_shared<ChangeFillColorCommand>(m_app.GetComposition(), sf::Color::Green));
    x += width + margin;

    // Outline Color
    position = sf::Vector2f(x, y);
    label = "Outline Color";
    AddButton(size, position, label,
        std::make_shared<ChangeOutlineColorCommand>(m_app.GetComposition(), sf::Color::Red));
    x += width + margin;

    // Select
    position = sf::Vector2f(x, y);
    label = "Select";
	State state = SELECT;
    AddButton(size, position, label,
        std::make_shared<SetStateCommand>(m_app, state));
    x += width + margin;

    // Fill
    position = sf::Vector2f(x, y);
    label = "Fill";
	state = FILL;
    AddButton(size, position, label,
        std::make_shared<SetStateCommand>(m_app, state));
    x += width + margin;

    // Outline 1
    position = sf::Vector2f(x, y);
    label = "Outline 1";
    AddButton(size, position, label,
        std::make_shared<ChangeOutlineThicknessCommand>(m_app.GetComposition(), 1.f));
    x += width + margin;

    // Outline 3
    position = sf::Vector2f(x, y);
    label = "Outline 3";
    AddButton(size, position, label,
        std::make_shared<ChangeOutlineThicknessCommand>(m_app.GetComposition(), 3.f));
    x += width + margin;

    // Outline 5
    position = sf::Vector2f(x, y);
    label = "Outline 5";
    AddButton(size, position, label,
        std::make_shared<ChangeOutlineThicknessCommand>(m_app.GetComposition(), 5.f));
    x += width + margin;
}


void ToolBar::Draw()
{
    m_window.draw(m_background);
    for (auto& btn : m_buttons)
        btn->Draw(m_window);
}

bool ToolBar::HandleEvent(sf::Event& event)
{
    if (auto mouse = event.getIf<sf::Event::MouseButtonPressed>())
    {
        if (mouse->button == sf::Mouse::Button::Left)
        {
            sf::Vector2f clickPos = m_window.mapPixelToCoords(mouse->position);

            for (auto& btn : m_buttons)
            {
                if (btn->Contains(clickPos))
                {
                    for (auto& b : m_buttons)
                        b->SetActive(false);

                    btn->SetActive(true);
                    btn->Execute();
                    return true;
                }
            }
        }
    }

    return false;
}