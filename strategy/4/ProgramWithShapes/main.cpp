#include <SFML/Graphics.hpp>
#include "lib/gfx/CCanvas.h"
#include "lib/gfx/ICanvas.h"
#include "lib/gfx/Color.h"
#include "lib/controller/CommandParser.h"
#include <iostream>
#include <queue>
#include <mutex>


std::queue<std::string> g_commands;
std::mutex g_mutex;

// Поток для чтения команд
void inputThread() {
    std::string line;
    while (std::getline(std::cin, line)) {
        if (!line.empty()) {
            std::lock_guard<std::mutex> lock(g_mutex);
            g_commands.push(line);
        }
    }
}

int main()
{
    std::thread reader(inputThread);
    reader.detach(); // поток живет сам по себе

    sf::RenderWindow window(sf::VideoMode({ 600, 600 }), "SFML Shapes App");
    shapes::CPicture picture;
    gfx::CCanvas canvas(window, { 0, 0 }, sf::Color::Blue);

    parser::CommandParser parser(picture, canvas);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())

                window.close();
        }

        {
            std::lock_guard<std::mutex> lock(g_mutex);
            while (!g_commands.empty()) {
                std::string cmdLine = g_commands.front();
                g_commands.pop();

                if (cmdLine == "exit") {
                    window.close();
                    break;
                }

                try {
                    auto cmd = parser.Parse(cmdLine);
                    if (cmd) {
                        cmd->Execute();
                    }
                }
                catch (const std::exception& ex) {
                    std::cout << "Error: " << ex.what() << "\n";
                }
            }
        }
        window.clear(sf::Color::Black);

        // Важно: если по заданию эффект DrawShape/DrawPicture *накапливается*,
        // то реализация с очисткой экрана каждый кадр перерисовывает всё заново
        // и, строго говоря, не накапливает "растровые следы".
        // Обычно перерисовка всей сцены каждый кадр — нормальная практика.
        // Если требуется действительно "накопление" в растровом буфере,
        // нужно отрисовывать в RenderTexture и не очищать его между Draw calls.
        picture.DrawPicture(canvas);

        window.display();
    }




}