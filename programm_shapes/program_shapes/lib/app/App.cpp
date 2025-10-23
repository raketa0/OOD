#include <SFML/Graphics.hpp>
#include <optional>

#include "App.h"
#include "../shapes/CPicture.h"
#include "../canvas/CCanvas.h"
#include "../tools/Constants.h"

void run()
{
    setlocale(LC_ALL, LOCALE_RU);

    CPicture picture;
    picture.LoadFromFile(INPUT_FILE);

    sf::RenderWindow window(sf::VideoMode({ WINDOW_WIDTH, WINDOW_HEIGHT }), WINDOW_TITLE);
    window.clear(sf::Color::White);
    CCanvas canvas(window);
    picture.OutCharacteristics();

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear(sf::Color::Black);

        picture.DrawPicture(canvas);

        window.display();
    }

}