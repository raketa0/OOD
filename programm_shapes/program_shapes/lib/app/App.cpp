#include <SFML/Graphics.hpp>
#include <optional>
#include <memory>

#include "App.h"
#include "../shapes/C�ompositionShapes.h"
#include "../canvas/CCanvasSFML.h"
#include "../tools/Constants.h"

void run()
{
    setlocale(LC_ALL, LOCALE_RU);

    sf::RenderWindow window(sf::VideoMode({ WINDOW_WIDTH, WINDOW_HEIGHT }), WINDOW_TITLE);
    window.clear(sf::Color::White);

    auto canvas = std::make_shared<CCanvasSFML>(window);

    C�ompositionShapes picture(canvas);

    picture.LoadFromFile(INPUT_FILE);
    picture.OutCharacteristics();

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear(sf::Color::Black);

        picture.Draw();

        window.display();
    }

}
