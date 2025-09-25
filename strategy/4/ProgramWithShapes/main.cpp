#include <SFML/Graphics.hpp>
#include "lib/shapes/ShapeStrategy/RectangleStrategy.h"
#include "lib/gfx/CCanvas.h"
#include "lib/gfx/ICanvas.h"
#include "lib/gfx/Color.h"
#include "lib/shapes/ShapeStrategy/CircleStrategy.h"
#include "lib/shapes/ShapeStrategy/TextStrategy.h"
#include "lib/shapes/ShapeStrategy/TriangleStrategy .h"




int main()
{
    sf::RenderWindow window(sf::VideoMode({ 600, 600 }), "SFML works!");
    RectangleStrategy rec(100, 100, 130, 150);
    gfx::CCanvas c(window,{0, 0}, sf::Color::Blue);
    CircleStrategy cir(165, 175, 50);
    TextStrategy tt(100, 100, 26, "Hellot");
    TriangleStrategy tri(165, 20, 100, 100, 230, 100);
    gfx::Color color;
    color.r = 75;
    color.g = 75;
    color.b = 175;
    gfx::Color color1;
    color1.r = 175;
    color1.g = 175;
    color1.b = 35;
    auto rec1 = rec;
    rec1.MoveShape(15, 45);
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())

                window.close();
        }

        window.clear();
        c.SetColor(color);

        rec.DrawShape(c, color);
        rec1.DrawShape(c, color1);

        cir.DrawShape(c, color);
        tt.DrawShape(c, color);
        tri.DrawShape(c, color);
        window.display();
    }
}