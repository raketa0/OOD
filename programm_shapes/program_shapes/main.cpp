#include <SFML/Graphics.hpp>
#include <iostream>
#include <optional>

#include "lib/shapes/CPicture.h"
#include "lib/canvas/CCanvas.h"

int main()
{
    setlocale(LC_ALL, "ru");

    CPicture picture;

    picture.LoadFromFile("input.txt");

    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Shapes Visualization");
    window.clear(sf::Color::White);
    CCanvas canvas(window);

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

    picture.OutCharacteristics();

    return 0;
}
