#include "ToolBar.h"
#include "commands/AddRectangleCommand.h"
#include "commands/AddTriangleCommand.h"
#include "commands/AddCircleCommand.h"
#include "commands/ChangeFillColorCommand.h"
#include "commands/ChangeOutlineColorCommand.h"
#include "commands/SetStateCommand.h"
#include "commands/ChangeOutlineThicknessCommand.h"
#include "../tools/Constants.h"
#include "commands/SaveTextCommand.h"
#include "commands/SaveBinaryCommand.h"
#include "commands/LoadTextCommand.h"
#include "commands/LoadBinaryCommand.h"

std::string LABEL_RECTANGLE = "Rectangle";
std::string LABEL_TRIANGLE = "Triangle";
std::string LABEL_CIRCLE = "Circle";

std::string LABEL_FILL_RED = "Fill Red";
std::string LABEL_FILL_GREEN = "Fill Green";
std::string LABEL_FILL_BLUE = "Fill Blue";

std::string LABEL_OUTLINE_RED = "Outline Red";
std::string LABEL_OUTLINE_GREEN = "Outline Green";
std::string LABEL_OUTLINE_BLUE = "Outline Blue";

std::string LABEL_SELECT = "Select";
std::string LABEL_FILL = "Fill";

std::string LABEL_OUTLINE_1 = "Outline 1";
std::string LABEL_OUTLINE_3 = "Outline 3";
std::string LABEL_OUTLINE_5 = "Outline 5";

ToolBar::ToolBar(sf::RenderWindow& window)
    : m_window(window)
{
}

void ToolBar::AddButton(sf::Vector2f& size, sf::Vector2f& position,
    std::string label, std::shared_ptr<ICommand> command)
{
    auto button = std::make_shared<Button>(size, position, label, command);
    m_buttons.push_back(button);
}

void ToolBar::InitPanelArea()
{
    m_area = sf::FloatRect({ PANEL_X, PANEL_Y }, { PANEL_WIDTH, PANEL_HEIGHT });
    m_background.setPosition({ PANEL_X, PANEL_Y });
    m_background.setSize({ PANEL_WIDTH, PANEL_HEIGHT });
    m_background.setFillColor(sf::Color(230, 230, 230));
    m_background.setOutlineColor(sf::Color::Black);
    m_background.setOutlineThickness(1.f);
}

void ToolBar::SetupDefaultButtons()
{
    m_buttons.clear();

    float x = BTN_START_X;
    float y = BTN_START_Y;
    sf::Vector2f size(BTN_WIDTH, BTN_HEIGHT);

    sf::Vector2f position(x, y);
    AddButton(size, position, LABEL_RECTANGLE,
        std::make_shared<AddRectangleCommand>(m_app.GetComposition(), m_app.GetCanvas(),
            FrameParameters{ {DEFAULT_RECT_X, DEFAULT_RECT_Y}, 50, 50 }));
    x += BTN_WIDTH + BTN_MARGIN;

    position = sf::Vector2f(x, y);
    AddButton(size, position, LABEL_TRIANGLE,
        std::make_shared<AddTriangleCommand>(m_app.GetComposition(), m_app.GetCanvas(),
            Point{ DEFAULT_TRIANGLE_P1X, DEFAULT_TRIANGLE_P1Y },
            Point{ DEFAULT_TRIANGLE_P2X, DEFAULT_TRIANGLE_P2Y },
            Point{ DEFAULT_TRIANGLE_P3X, DEFAULT_TRIANGLE_P3Y }));
    x += BTN_WIDTH + BTN_MARGIN;

    position = sf::Vector2f(x, y);
    AddButton(size, position, LABEL_CIRCLE,
        std::make_shared<AddCircleCommand>(m_app.GetComposition(), m_app.GetCanvas(),
            Point{ DEFAULT_CIRCLE_X, DEFAULT_CIRCLE_Y },
            DEFAULT_CIRCLE_RADIUS));
    x += BTN_WIDTH + BTN_MARGIN;

    position = sf::Vector2f(x, y);
    AddButton(size, position, LABEL_FILL_RED,
        std::make_shared<ChangeFillColorCommand>(m_app.GetComposition(), sf::Color::Red));
    x += BTN_WIDTH + BTN_MARGIN;

    position = sf::Vector2f(x, y);
    AddButton(size, position, LABEL_FILL_GREEN,
        std::make_shared<ChangeFillColorCommand>(m_app.GetComposition(), sf::Color::Green));
    x += BTN_WIDTH + BTN_MARGIN;

    position = sf::Vector2f(x, y);
    AddButton(size, position, LABEL_FILL_BLUE,
        std::make_shared<ChangeFillColorCommand>(m_app.GetComposition(), sf::Color::Blue));
    x += BTN_WIDTH + BTN_MARGIN;

    position = sf::Vector2f(x, y);
    AddButton(size, position, LABEL_OUTLINE_RED,
        std::make_shared<ChangeOutlineColorCommand>(m_app.GetComposition(), sf::Color::Red));
    x += BTN_WIDTH + BTN_MARGIN;

    position = sf::Vector2f(x, y);
    AddButton(size, position, LABEL_OUTLINE_GREEN,
        std::make_shared<ChangeOutlineColorCommand>(m_app.GetComposition(), sf::Color::Green));
    x += BTN_WIDTH + BTN_MARGIN;

    position = sf::Vector2f(x, y);
    AddButton(size, position, LABEL_OUTLINE_BLUE,
        std::make_shared<ChangeOutlineColorCommand>(m_app.GetComposition(), sf::Color::Blue));
    x += BTN_WIDTH + BTN_MARGIN;

    position = sf::Vector2f(x, y);
    AddButton(size, position, LABEL_SELECT,
        std::make_shared<SetStateCommand>(m_app, SELECT));
    x += BTN_WIDTH + BTN_MARGIN;

    position = sf::Vector2f(x, y);
    AddButton(size, position, LABEL_FILL,
        std::make_shared<SetStateCommand>(m_app, FILL));
    x += BTN_WIDTH + BTN_MARGIN;

    position = sf::Vector2f(x, y);
    AddButton(size, position, LABEL_OUTLINE_1,
        std::make_shared<ChangeOutlineThicknessCommand>(m_app.GetComposition(), THICKNESS_1));
    x += BTN_WIDTH + BTN_MARGIN;

    position = sf::Vector2f(x, y);
    AddButton(size, position, LABEL_OUTLINE_3,
        std::make_shared<ChangeOutlineThicknessCommand>(m_app.GetComposition(), THICKNESS_3));
    x += BTN_WIDTH + BTN_MARGIN;

    position = sf::Vector2f(x, y);
    AddButton(size, position, LABEL_OUTLINE_5,
        std::make_shared<ChangeOutlineThicknessCommand>(m_app.GetComposition(), THICKNESS_5));
    x += BTN_WIDTH + BTN_MARGIN;

    std::string LABEL_SAVE_TEXT = "Save TXT";
    std::string LABEL_SAVE_BINARY = "Save BIN";

    position = sf::Vector2f(x, y);
    AddButton(size, position, LABEL_SAVE_TEXT,
        std::make_shared<SaveTextCommand>(m_app.GetComposition()));
    x += BTN_WIDTH + BTN_MARGIN;

    position = sf::Vector2f(x, y);
    AddButton(size, position, LABEL_SAVE_BINARY,
        std::make_shared<SaveBinaryCommand>(m_app.GetComposition()));
    x += BTN_WIDTH + BTN_MARGIN;

    x = BTN_START_X;
    y += BTN_HEIGHT + BTN_MARGIN;

    position = sf::Vector2f(x, y);
    AddButton(size, position, "Load TXT",
        std::make_shared<LoadTextCommand>(m_app.GetComposition()));
    x += BTN_WIDTH + BTN_MARGIN;

    position = sf::Vector2f(x, y);
    AddButton(size, position, "Load BIN",
        std::make_shared<LoadBinaryCommand>(m_app.GetComposition()));
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
        if (mouse->button != sf::Mouse::Button::Left)
            return false;

        sf::Vector2f clickPos = m_window.mapPixelToCoords(mouse->position);

        for (auto& btn : m_buttons)
        {
            if (btn->Contains(clickPos))
            {
                if (btn->GetLabel() == LABEL_SELECT || btn->GetLabel() == LABEL_FILL)
                {
                    for (auto& b : m_buttons)
                    {
                        if (b->GetLabel() == LABEL_SELECT || b->GetLabel() == LABEL_FILL)
                            b->SetActive(false);
                    }
                    btn->SetActive(true);
                }

                btn->Execute();
                return true;
            }
        }
    }

    return false;
}
