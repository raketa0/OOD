#include <SFML/Graphics.hpp>
#include <optional>
#include <memory>

#include "App.h"
#include "../shapes/CÑompositionShapes.h"
#include "../canvas/CCanvasSFML.h"
#include "../tools/Constants.h"
#include "../interactive/CShapeSelector.h"
#include "../interactive/CShapeDraggerMove.h"

void Run()
{
    setlocale(LC_ALL, LOCALE_RU);

    sf::RenderWindow window(sf::VideoMode({ WINDOW_WIDTH, WINDOW_HEIGHT }), WINDOW_TITLE);
    window.clear(sf::Color::White);

    auto canvas = std::make_shared<CCanvasSFML>(window);

    auto composition = std::make_shared<CÑompositionShapes>(canvas);

    composition->LoadFromFile(INPUT_FILE);
    composition->OutCharacteristics();

    CShapeSelector selector(composition, canvas);
    CShapeDraggerMove dragger(composition, selector);
    while (window.isOpen())
    {
        while (const auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
                
            else if (event->is<sf::Event::MouseButtonPressed>())
            {
                if (const auto* mouseEvent = event->getIf<sf::Event::MouseButtonPressed>())
                {
                    if (mouseEvent->button == sf::Mouse::Button::Left)
                    {
                        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                        bool isShiftPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)
                            || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::RShift);
                        selector.OnClick(mousePosition, isShiftPressed);
                        dragger.StartDrag(mousePosition);
                    }
                }
            }
            else if (event->is<sf::Event::MouseMoved>())
            {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                dragger.OnMouseMoved(mousePosition);
            }
            else if (event->is<sf::Event::MouseButtonReleased>())
            {
                if (const auto* mouseEvent = event->getIf<sf::Event::MouseButtonReleased>())
                {
                    if (mouseEvent->button == sf::Mouse::Button::Left)
                    {
                        dragger.EndDrag();
					}
                }
            }
            else if (event->is<sf::Event::KeyPressed>())
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl) &&
                    sf::Keyboard::isKeyPressed(sf::Keyboard::Key::G))
                {
                    selector.GroupSelectedShapes();
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl) &&
                    sf::Keyboard::isKeyPressed(sf::Keyboard::Key::U))
                {
                    selector.UngroupSelectedShape();
                }
            }
        }

        window.clear(sf::Color::Black);

        composition->Draw();
        selector.DrawSelection();
        window.display();
    }

}
