#include "Application.h"

Application& Application::GetApp()
{
    static Application instance;
    return instance;
}

Application::Application()
    : m_window(nullptr), m_canvas(nullptr), m_composition(nullptr), m_inputFile(INPUT_FILE)
{
}

Application::~Application() = default;


void Application::Init(const std::string& inputFile)
{
    m_inputFile = inputFile;
    InitWindow();
    InitCanvas();
    InitComposition();
    InitInteractive();
}

void Application::InitWindow()
{
    setlocale(LC_ALL, LOCALE_RU);
    m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode({ WINDOW_WIDTH, WINDOW_HEIGHT }), WINDOW_TITLE);
    m_window->clear(sf::Color::White);
}

void Application::InitCanvas()
{
    m_canvas = std::make_shared<CCanvasSFML>(*m_window);
}

void Application::InitComposition()
{
    m_composition = std::make_shared<CÑompositionShapes>(m_canvas);
    m_composition->LoadFromFile(m_inputFile);
    m_composition->OutCharacteristics();
}

void Application::InitInteractive()
{
    m_selector = std::make_unique<CShapeSelector>(m_composition, m_canvas);
    m_dragger = std::make_unique<CShapeDraggerMove>(m_composition, *m_selector);
}

void Application::Run()
{
    if (!m_window) Init(m_inputFile);

    while (m_window->isOpen())
    {
        while (const auto event = m_window->pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                m_window->close();
            }
            else if (event->is<sf::Event::MouseButtonPressed>())
            {
                if (const auto* mouseEvent = event->getIf<sf::Event::MouseButtonPressed>())
                {
                    if (mouseEvent->button == sf::Mouse::Button::Left)
                    {
                        sf::Vector2i mousePosition = sf::Mouse::getPosition(*m_window);
                        bool isShiftPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)
                            || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::RShift);
                        m_selector->OnClick(mousePosition, isShiftPressed);
                        m_dragger->StartDrag(mousePosition);
                    }
                }
            }
            else if (event->is<sf::Event::MouseMoved>())
            {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(*m_window);
                m_dragger->OnMouseMoved(mousePosition);
            }
            else if (event->is<sf::Event::MouseButtonReleased>())
            {
                if (const auto* mouseEvent = event->getIf<sf::Event::MouseButtonReleased>())
                {
                    if (mouseEvent->button == sf::Mouse::Button::Left)
                    {
                        m_dragger->EndDrag();
                    }
                }
            }
            else if (event->is<sf::Event::KeyPressed>())
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl) &&
                    sf::Keyboard::isKeyPressed(sf::Keyboard::Key::G))
                {
                    m_selector->GroupSelectedShapes();
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl) &&
                    sf::Keyboard::isKeyPressed(sf::Keyboard::Key::U))
                {
                    m_selector->UngroupSelectedShape();
                }
            }
        }

        m_window->clear(sf::Color::Black);

        m_composition->Draw();
        m_selector->DrawSelection();
        m_window->display();
    }
}

