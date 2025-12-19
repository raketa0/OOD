#include "Application.h"
#include "../ToolBar/state/FillState.h"
#include "../ToolBar/state/SelectState.h"
#include "../ToolBar/ToolBar.h"
Application& Application::GetApp()
{
    static Application app;
    return app;
}

Application::Application()
    : m_window(nullptr), m_canvas(nullptr), m_composition(nullptr)
{
}

void Application::Init(const std::string& inputFile)
{
    if (!inputFile.empty())
        m_inputFile = inputFile;

    InitWindow();
    InitCanvas();
    InitComposition();
    InitInteractive();
    InitToolBar();
    SetState(m_appState);
}

void Application::InitWindow()
{
    setlocale(LC_ALL, LOCALE_RU);
    m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode({ WINDOW_WIDTH, WINDOW_HEIGHT }), WINDOW_TITLE);
    m_window->clear(sf::Color::Blue);
}

void Application::InitCanvas()
{
    m_canvas = std::make_shared<CCanvasSFML>(*m_window);
}

void Application::InitComposition()
{
    m_composition = std::make_shared<CÑompositionShapes>(m_canvas);
    if (!m_inputFile.empty())
    {
        m_composition->LoadFromFile(m_inputFile);
    }
}

void Application::InitInteractive()
{
    m_selector = std::make_unique<CShapeSelector>(m_composition, m_canvas);
    m_dragger = std::make_unique<CShapeDraggerMove>(m_composition, *m_selector);
}

void Application::InitToolBar()
{
    m_toolbar = std::make_shared<ToolBar>(*m_window);
    m_toolbar->SetupDefaultButtons();
}

sf::RenderWindow& Application::GetWindow()
{
    return *m_window;
}

std::shared_ptr<CCanvasSFML> Application::GetCanvas()
{
    return m_canvas;
}

std::shared_ptr<CÑompositionShapes> Application::GetComposition()
{
    return m_composition;
}

std::unique_ptr<CShapeSelector>& Application::GetSelector()
{
    return m_selector;
}

std::unique_ptr<CShapeDraggerMove>& Application::GetDragger()
{
    return m_dragger;
}

std::shared_ptr<IToolBar> Application::GetToolbar()
{
    return m_toolbar;
}

void Application::SetState(State newState)
{
    if (newState == SELECT)
    {
        m_appState = SELECT;
        m_currentState = std::make_shared<SelectState>();
    }
    else if (newState == FILL)
    {
        m_appState = FILL;

        m_currentState = std::make_shared<FillState>(
            m_composition->GetFillColor(),
            m_composition->GetOutlineColor(),
            m_composition->GetOutlineThickness()
        );
    }
}

std::shared_ptr<IState> Application::GetState()
{
    return m_currentState;
}

State& Application::GetAppState()
{
    return m_appState;
}

void Application::Undo()
{
    HistoryShapes::GetInstance().Undo();
}

void Application::Redo()
{
    HistoryShapes::GetInstance().Redo();
}


void Application::Run()
{
    if (!m_window)
    {
        Init(m_inputFile);
    }


    while (m_window->isOpen())
    {
        while (auto eventOpt = m_window->pollEvent())
        {
            sf::Event& event = *eventOpt;

            bool handledByToolbar = m_toolbar->HandleEvent(event);

            if (!handledByToolbar && m_currentState)
            {
                m_currentState->HandleEvent(event);
            }
        }

        m_window->clear(sf::Color::Black);


        m_composition->Draw();
        m_toolbar->Draw();
        m_selector->DrawSelection();
        m_window->display();
    }
}

