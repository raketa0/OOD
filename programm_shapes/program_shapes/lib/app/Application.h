#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "../canvas/CCanvasSFML.h"
#include "../shapes/CÑompositionShapes.h"
#include "../interactive/CShapeSelector.h"
#include "../interactive/CShapeDraggerMove.h"
#include "../ToolBar/state/IState.h"
#include "../ToolBar/IToolBar.h"

enum State
{
    SELECT,
	FILL
};

class Application
{
public:
    static Application& GetApp();

    void Init(const std::string& inputFile = "");
    void Run();

    sf::RenderWindow& GetWindow();
    std::shared_ptr<CCanvasSFML> GetCanvas();
    std::shared_ptr<CÑompositionShapes> GetComposition();
    std::unique_ptr<CShapeSelector>& GetSelector();
    std::unique_ptr<CShapeDraggerMove>& GetDragger();

    void SetState(State newState);
    std::shared_ptr<IState> GetState();
    State& GetAppState() { return m_appState; }


    Application(const Application&) = delete;
    Application& operator=(const Application&) = delete;

private:
    Application();
    ~Application() = default;

    void InitWindow();
    void InitCanvas();
    void InitComposition();
    void InitInteractive();
    void InitToolBar();

    std::unique_ptr<sf::RenderWindow> m_window;
    std::shared_ptr<CCanvasSFML> m_canvas;
    std::shared_ptr<CÑompositionShapes> m_composition;
    std::unique_ptr<CShapeSelector> m_selector;
    std::unique_ptr<CShapeDraggerMove> m_dragger;
    std::unique_ptr<IToolBar> m_toolbar;
    std::shared_ptr<IState> m_currentState;
	State m_appState = State::SELECT;
    std::string m_inputFile = "input.txt";
};