#include <SFML/Graphics.hpp>
#include <optional>

#include "lib/shapes/CPicture.h"
#include "lib/canvas/CCanvas.h"
#include "lib/tools/Constants.h"


int main()
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

    return 0;
}
