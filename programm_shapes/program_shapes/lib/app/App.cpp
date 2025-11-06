#include <SFML/Graphics.hpp>
#include <optional>
#include <memory>

#include "App.h"
#include "../shapes/CÑompositionShapes.h"
#include "../canvas/CCanvasSFML.h"
#include "../tools/Constants.h"
#include "../interactive/CShapeSelector.h"

void run()
{
    setlocale(LC_ALL, LOCALE_RU);

    sf::RenderWindow window(sf::VideoMode({ WINDOW_WIDTH, WINDOW_HEIGHT }), WINDOW_TITLE);
    window.clear(sf::Color::White);

    auto canvas = std::make_shared<CCanvasSFML>(window);

    auto composition = std::make_shared<CÑompositionShapes>(canvas);

    composition->LoadFromFile(INPUT_FILE);
    composition->OutCharacteristics();

    CShapeSelector selector(composition, canvas);

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
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);  // Ïîëó÷àåì ïîçèöèþ êëèêà
                selector.OnClick(mousePosition);  // Ïðîâåðÿåì êëèê ïî ôèãóðàì, îáíîâëÿåì âûäåëåíèå
            }
        }

        window.clear(sf::Color::Black);

        composition->Draw();
        selector.DrawSelection();
        window.display();
    }

}
