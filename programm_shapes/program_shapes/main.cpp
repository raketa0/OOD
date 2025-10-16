#include <SFML/Graphics.hpp>
#include "lib/shapes/CircleAdapter.h"
#include "lib/canvas/CCanvas.h"

int main()
{
    CircleAdapter circ(350, 350, 50);

    sf::RenderWindow window(sf::VideoMode({ 600, 600 }), "SFML Shapes App");
    CCanvas canv(window);


    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())

                window.close();
        }

        window.clear(sf::Color::Black);
        circ.DrawShape(canv);


        window.display();
    }




}