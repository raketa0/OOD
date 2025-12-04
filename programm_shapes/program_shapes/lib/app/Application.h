#pragma once
#include <memory>
#include "../canvas/CCanvasSFML.h"
#include "../shapes/CÑompositionShapes.h"
#include "../interactive/CShapeSelector.h"
#include "../interactive/CShapeDraggerMove.h"


class Application
{
public:

	static Application& GetApp();

	void Init(const std::string& inputFile = INPUT_FILE);
	void Run();

private:
	Application();
	~Application();
	Application(const Application&) = delete;
	Application& operator=(const Application&) = delete;

	std::unique_ptr<sf::RenderWindow> m_window;
	std::shared_ptr<CCanvasSFML> m_canvas;
	std::shared_ptr<CÑompositionShapes> m_composition;
	std::unique_ptr<CShapeSelector> m_selector;
	std::unique_ptr<CShapeDraggerMove> m_dragger;

	std::string m_inputFile;

	void InitWindow();
	void InitCanvas();
	void InitComposition();
	void InitInteractive();
};